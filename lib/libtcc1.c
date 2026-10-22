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

#परिभाषय W_TYPE_आकार   32
#परिभाषय द्वयङ्काः_प्रत्येकम्_UNIT 8

प्रकारनिर्देश पूर्णाङ्क Wtype;
प्रकारनिर्देश अचिह्नित पूर्णाङ्क UWtype;
प्रकारनिर्देश अचिह्नित पूर्णाङ्क USItype;
प्रकारनिर्देश दीर्घ दीर्घ DWtype;
प्रकारनिर्देश अचिह्नित दीर्घ दीर्घ UDWtype;

संरचना DWstruct {
    Wtype नीचः, उच्चः;
};

प्रकारनिर्देश सङ्घ
{
  संरचना DWstruct s;
  DWtype ll;
} DWunion;

प्रकारनिर्देश दीर्घ द्विगुण XFtype;
#परिभाषय WORD_आकार (परिमाण (Wtype) * द्वयङ्काः_प्रत्येकम्_UNIT)
#परिभाषय उच्चः_WORD_COEFF (((UDWtype) 1) << WORD_आकार)

/* the following deal with IEEE single-precision numbers */
#परिभाषय EXCESS		126
#परिभाषय SIGNBIT		0x80000000
#परिभाषय HIDDEN		(1 << 23)
#परिभाषय SIGN(fp)	((fp) & SIGNBIT)
#परिभाषय EXP(fp)		(((fp) >> 23) & 0xFF)
#परिभाषय MANT(fp)	(((fp) & 0x7FFFFF) | HIDDEN)
#परिभाषय PACK(s,e,m)	((s) | ((e) << 23) | (m))

/* the following deal with IEEE double-precision numbers */
#परिभाषय EXCESSD		1022
#परिभाषय HIDDEND		(1 << 20)
#परिभाषय EXPD(fp)	(((fp.l.ऊर्ध्वस्थम्) >> 20) & 0x7FF)
#परिभाषय SIGND(fp)	((fp.l.ऊर्ध्वस्थम्) & SIGNBIT)
#परिभाषय MANTD(fp)	(((((fp.l.ऊर्ध्वस्थम्) & 0xFFFFF) | HIDDEND) << 10) | \
				(fp.l.अधस्तनम् >> 22))
#परिभाषय HIDDEND_LL	((दीर्घ दीर्घ)1 << 52)
#परिभाषय MANTD_LL(fp)	((fp.ll & (HIDDEND_LL-1)) | HIDDEND_LL)
#परिभाषय PACKD_LL(s,e,m)	(((दीर्घ दीर्घ)((s)+((e)<<20))<<32)|(m))

/* the following deal with x86 long double-precision numbers */
#परिभाषय EXCESSLD	16382
#परिभाषय EXPLD(fp)	(fp.l.ऊर्ध्वस्थम् & 0x7fff)
#परिभाषय SIGNLD(fp)	((fp.l.ऊर्ध्वस्थम्) & 0x8000)

/* only for x86 */
सङ्घ ldouble_long {
    दीर्घ द्विगुण ld;
    संरचना {
        अचिह्नित दीर्घ दीर्घ अधस्तनम्;
        अचिह्नित ह्रस्व ऊर्ध्वस्थम्;
    } l;
};

सङ्घ double_long {
    द्विगुण d;
#यदि 1
    संरचना {
        अचिह्नित पूर्णाङ्क अधस्तनम्;
        पूर्णाङ्क ऊर्ध्वस्थम्;
    } l;
#अन्यथा
    संरचना {
        पूर्णाङ्क ऊर्ध्वस्थम्;
        अचिह्नित पूर्णाङ्क अधस्तनम्;
    } l;
#यदि_अन्तः
    दीर्घ दीर्घ ll;
};

सङ्घ float_long {
    भिन्न f;
    अचिह्नित पूर्णाङ्क l;
};

/* XXX: we don't support several builtin supports for now */
#यदि defined __i386__

/* XXX: use gcc/tcc intrinsic ? */
#परिभाषय sub_ddmmss(sh, sl, ah, al, bh, bl) \
  __asm__ ("subl %5,%1\n\tsbbl %3,%0"					\
	   : "=r" ((USItype) (sh)),					\
	     "=&r" ((USItype) (sl))					\
	   : "0" ((USItype) (ah)),					\
	     "g" ((USItype) (bh)),					\
	     "1" ((USItype) (al)),					\
	     "g" ((USItype) (bl)))
#परिभाषय umul_ppmm(w1, w0, u, v) \
  __asm__ ("mull %3"							\
	   : "=a" ((USItype) (w0)),					\
	     "=d" ((USItype) (w1))					\
	   : "%0" ((USItype) (u)),					\
	     "rm" ((USItype) (v)))
#परिभाषय udiv_qrnnd(q, r, n1, n0, dv) \
  __asm__ ("divl %4"							\
	   : "=a" ((USItype) (q)),					\
	     "=d" ((USItype) (r))					\
	   : "0" ((USItype) (n0)),					\
	     "1" ((USItype) (n1)),					\
	     "rm" ((USItype) (dv)))
#परिभाषय गणनम्_leading_zeros(गणनम्_2, x) \
  कुरु {									\
    USItype __cbtmp;							\
    __asm__ ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (गणनम्_2) = __cbtmp ^ 31;						\
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

  d0 = dd.s.नीचः;
  d1 = dd.s.उच्चः;
  n0 = nn.s.नीचः;
  n1 = nn.s.उच्चः;

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
	  rr.s.नीचः = n0;
	  rr.s.उच्चः = 0;
	  *rp = rr.ll;
	}
    }

#अन्यथा /* UDIV_NEEDS_NORMALIZATION */

  यदि (d1 == 0)
    {
      यदि (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  गणनम्_leading_zeros (bm, d0);

	  यदि (bm != 0)
	    {
	      /* Normalize, i.e. make the most significant bit of the
		 denominator set.  */

	      d0 = d0 << bm;
	      n1 = (n1 << bm) | (n0 >> (W_TYPE_आकार - bm));
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

	  गणनम्_leading_zeros (bm, d0);

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

	      b = W_TYPE_आकार - bm;

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
	  rr.s.नीचः = n0 >> bm;
	  rr.s.उच्चः = 0;
	  *rp = rr.ll;
	}
    }
#यदि_अन्तः /* UDIV_NEEDS_NORMALIZATION */

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
	      rr.s.नीचः = n0;
	      rr.s.उच्चः = n1;
	      *rp = rr.ll;
	    }
	}
      अन्यथा
	{
	  /* 0q = NN / dd */

	  गणनम्_leading_zeros (bm, d1);
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
		  rr.s.नीचः = n0;
		  rr.s.उच्चः = n1;
		  *rp = rr.ll;
		}
	    }
	  अन्यथा
	    {
	      UWtype m1, m0;
	      /* Normalize.  */

	      b = W_TYPE_आकार - bm;

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
		  rr.s.नीचः = (n1 << b) | (n0 >> bm);
		  rr.s.उच्चः = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }

  ww.s.नीचः = q0;
  ww.s.उच्चः = q1;
  प्रत्यागम ww.ll;
}

#परिभाषय __negdi2(a) (-(a))

दीर्घ दीर्घ __divdi3(दीर्घ दीर्घ u, दीर्घ दीर्घ v)
{
    पूर्णाङ्क c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    यदि (uu.s.उच्चः < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    यदि (vv.s.उच्चः < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    यदि (c)
        w = __negdi2 (w);
    प्रत्यागम w;
}

दीर्घ दीर्घ __moddi3(दीर्घ दीर्घ u, दीर्घ दीर्घ v)
{
    पूर्णाङ्क c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    यदि (uu.s.उच्चः < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    यदि (vv.s.उच्चः < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    यदि (c)
        w = __negdi2 (w);
    प्रत्यागम w;
}

अचिह्नित दीर्घ दीर्घ __udivdi3(अचिह्नित दीर्घ दीर्घ u, अचिह्नित दीर्घ दीर्घ v)
{
    प्रत्यागम __udivmoddi4 (u, v, (UDWtype *) 0);
}

अचिह्नित दीर्घ दीर्घ __umoddi3(अचिह्नित दीर्घ दीर्घ u, अचिह्नित दीर्घ दीर्घ v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    प्रत्यागम w;
}

/* XXX: fix tcc's code generator to do this instead */
दीर्घ दीर्घ __ashrdi3(दीर्घ दीर्घ a, पूर्णाङ्क b)
{
#यदि_परिभाषितम् __TINYC__
    DWunion u;
    u.ll = a;
    यदि (b >= 32) {
        u.s.नीचः = u.s.उच्चः >> (b - 32);
        u.s.उच्चः = u.s.उच्चः >> 31;
    } अन्यथा यदि (b != 0) {
        u.s.नीचः = ((अचिह्नित)u.s.नीचः >> b) | (u.s.उच्चः << (32 - b));
        u.s.उच्चः = u.s.उच्चः >> b;
    }
    प्रत्यागम u.ll;
#अन्यथा
    प्रत्यागम a >> b;
#यदि_अन्तः
}

/* XXX: fix tcc's code generator to do this instead */
अचिह्नित दीर्घ दीर्घ __lshrdi3(अचिह्नित दीर्घ दीर्घ a, पूर्णाङ्क b)
{
#यदि_परिभाषितम् __TINYC__
    DWunion u;
    u.ll = a;
    यदि (b >= 32) {
        u.s.नीचः = (अचिह्नित)u.s.उच्चः >> (b - 32);
        u.s.उच्चः = 0;
    } अन्यथा यदि (b != 0) {
        u.s.नीचः = ((अचिह्नित)u.s.नीचः >> b) | (u.s.उच्चः << (32 - b));
        u.s.उच्चः = (अचिह्नित)u.s.उच्चः >> b;
    }
    प्रत्यागम u.ll;
#अन्यथा
    प्रत्यागम a >> b;
#यदि_अन्तः
}

/* XXX: fix tcc's code generator to do this instead */
दीर्घ दीर्घ __ashldi3(दीर्घ दीर्घ a, पूर्णाङ्क b)
{
#यदि_परिभाषितम् __TINYC__
    DWunion u;
    u.ll = a;
    यदि (b >= 32) {
        u.s.उच्चः = (अचिह्नित)u.s.नीचः << (b - 32);
        u.s.नीचः = 0;
    } अन्यथा यदि (b != 0) {
        u.s.उच्चः = ((अचिह्नित)u.s.उच्चः << b) | ((अचिह्नित)u.s.नीचः >> (32 - b));
        u.s.नीचः = (अचिह्नित)u.s.नीचः << b;
    }
    प्रत्यागम u.ll;
#अन्यथा
    प्रत्यागम a << b;
#यदि_अन्तः
}

#यदि_अन्तः /* __i386__ */

/* XXX: fix tcc's code generator to do this instead */
भिन्न __floatundisf(अचिह्नित दीर्घ दीर्घ a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    यदि (uu.s.उच्चः >= 0) {
        प्रत्यागम (भिन्न)uu.ll;
    } अन्यथा {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        प्रत्यागम (भिन्न)r;
    }
}

द्विगुण __floatundidf(अचिह्नित दीर्घ दीर्घ a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    यदि (uu.s.उच्चः >= 0) {
        प्रत्यागम (द्विगुण)uu.ll;
    } अन्यथा {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        प्रत्यागम (द्विगुण)r;
    }
}

दीर्घ द्विगुण __floatundixf(अचिह्नित दीर्घ दीर्घ a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    यदि (uu.s.उच्चः >= 0) {
        प्रत्यागम (दीर्घ द्विगुण)uu.ll;
    } अन्यथा {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        प्रत्यागम (दीर्घ द्विगुण)r;
    }
}

अचिह्नित दीर्घ दीर्घ __fixunssfdi (भिन्न a1)
{
    पञ्जिका सङ्घ float_long fl1;
    पञ्जिका पूर्णाङ्क घातांकः;
    पञ्जिका अचिह्नित दीर्घ दीर्घ l;

    fl1.f = a1;

    यदि (fl1.l == 0)
	प्रत्यागम (0);

    घातांकः = EXP (fl1.l) - EXCESS - 24;
    l = MANT(fl1.l);

    यदि (घातांकः >= 41)
        प्रत्यागम 1ULL << 63;
    अन्यथा यदि (घातांकः >= 0)
        l <<= घातांकः;
    अन्यथा यदि (घातांकः >= -23)
        l >>= -घातांकः;
    अन्यथा
	प्रत्यागम 0;
    यदि (SIGN(fl1.l))
        l = (अचिह्नित दीर्घ दीर्घ)-l;
    प्रत्यागम l;
}

दीर्घ दीर्घ __fixsfdi (भिन्न a1)
{
    दीर्घ दीर्घ ret; पूर्णाङ्क s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    प्रत्यागम s ? ret : -ret;
}

अचिह्नित दीर्घ दीर्घ __fixunsdfdi (द्विगुण a1)
{
    पञ्जिका सङ्घ double_long dl1;
    पञ्जिका पूर्णाङ्क घातांकः;
    पञ्जिका अचिह्नित दीर्घ दीर्घ l;

    dl1.d = a1;

    यदि (dl1.ll == 0)
	प्रत्यागम (0);

    घातांकः = EXPD (dl1) - EXCESSD - 53;
    l = MANTD_LL(dl1);

    यदि (घातांकः >= 12)
        प्रत्यागम 1ULL << 63; /* overflow result (like gcc, somewhat) */
    अन्यथा यदि (घातांकः >= 0)
        l <<= घातांकः;
    अन्यथा यदि (घातांकः >= -52)
        l >>= -घातांकः;
    अन्यथा
        प्रत्यागम 0;
    यदि (SIGND(dl1))
        l = (अचिह्नित दीर्घ दीर्घ)-l;
    प्रत्यागम l;
}

दीर्घ दीर्घ __fixdfdi (द्विगुण a1)
{
    दीर्घ दीर्घ ret; पूर्णाङ्क s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    प्रत्यागम s ? ret : -ret;
}

#यदि_अपरिभाषितम् __arm__
अचिह्नित दीर्घ दीर्घ __fixunsxfdi (दीर्घ द्विगुण a1)
{
    पञ्जिका सङ्घ ldouble_long dl1;
    पञ्जिका पूर्णाङ्क घातांकः;
    पञ्जिका अचिह्नित दीर्घ दीर्घ l;

    dl1.ld = a1;

    यदि (dl1.l.अधस्तनम् == 0 && dl1.l.ऊर्ध्वस्थम् == 0)
	प्रत्यागम (0);

    घातांकः = EXPLD (dl1) - EXCESSLD - 64;
    l = dl1.l.अधस्तनम्;
    यदि (घातांकः > 0)
	प्रत्यागम 1ULL << 63;
    यदि (घातांकः < -63)
        प्रत्यागम 0;
    l >>= -घातांकः;
    यदि (SIGNLD(dl1))
        l = (अचिह्नित दीर्घ दीर्घ)-l;
    प्रत्यागम l;
}

दीर्घ दीर्घ __fixxfdi (दीर्घ द्विगुण a1)
{
    दीर्घ दीर्घ ret; पूर्णाङ्क s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    प्रत्यागम s ? ret : -ret;
}
#यदि_अन्तः /* !ARM */
