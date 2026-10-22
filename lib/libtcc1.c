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

#घोषणा W_TYPE_आकार   32
#घोषणा BITS_PER_UNIT 8

प्रकार पूर्णांक Wtype;
प्रकार अचिन्हित पूर्णांक UWtype;
प्रकार अचिन्हित पूर्णांक USItype;
प्रकार दीर्घ दीर्घ DWtype;
प्रकार अचिन्हित दीर्घ दीर्घ UDWtype;

काष्ठा DWstruct {
    Wtype निचला, ऊपरी;
};

प्रकार जोड़
{
  काष्ठा DWstruct s;
  DWtype ll;
} DWunion;

प्रकार दीर्घ द्विगुन XFtype;
#घोषणा WORD_आकार (माप (Wtype) * BITS_PER_UNIT)
#घोषणा ऊपरी_WORD_COEFF (((UDWtype) 1) << WORD_आकार)

/* the following deal with IEEE single-precision numbers */
#घोषणा EXCESS		126
#घोषणा SIGNBIT		0x80000000
#घोषणा HIDDEN		(1 << 23)
#घोषणा SIGN(fp)	((fp) & SIGNBIT)
#घोषणा EXP(fp)		(((fp) >> 23) & 0xFF)
#घोषणा MANT(fp)	(((fp) & 0x7FFFFF) | HIDDEN)
#घोषणा PACK(s,e,m)	((s) | ((e) << 23) | (m))

/* the following deal with IEEE double-precision numbers */
#घोषणा EXCESSD		1022
#घोषणा HIDDEND		(1 << 20)
#घोषणा EXPD(fp)	(((fp.l.upper) >> 20) & 0x7FF)
#घोषणा SIGND(fp)	((fp.l.upper) & SIGNBIT)
#घोषणा MANTD(fp)	(((((fp.l.upper) & 0xFFFFF) | HIDDEND) << 10) | \
				(fp.l.lower >> 22))
#घोषणा HIDDEND_LL	((दीर्घ दीर्घ)1 << 52)
#घोषणा MANTD_LL(fp)	((fp.ll & (HIDDEND_LL-1)) | HIDDEND_LL)
#घोषणा PACKD_LL(s,e,m)	(((दीर्घ दीर्घ)((s)+((e)<<20))<<32)|(m))

/* the following deal with x86 long double-precision numbers */
#घोषणा EXCESSLD	16382
#घोषणा EXPLD(fp)	(fp.l.upper & 0x7fff)
#घोषणा SIGNLD(fp)	((fp.l.upper) & 0x8000)

/* only for x86 */
जोड़ ldouble_long {
    दीर्घ द्विगुन ld;
    काष्ठा {
        अचिन्हित दीर्घ दीर्घ lower;
        अचिन्हित लघु upper;
    } l;
};

जोड़ double_long {
    द्विगुन d;
#अगर 1
    काष्ठा {
        अचिन्हित पूर्णांक lower;
        पूर्णांक upper;
    } l;
#अन्यथा
    काष्ठा {
        पूर्णांक upper;
        अचिन्हित पूर्णांक lower;
    } l;
#पूर्ण_अगर
    दीर्घ दीर्घ ll;
};

जोड़ float_long {
    भग्न f;
    अचिन्हित पूर्णांक l;
};

/* XXX: we don't support several builtin supports for now */
#अगर defined __i386__

/* XXX: use gcc/tcc intrinsic ? */
#घोषणा sub_ddmmss(sh, sl, ah, al, bh, bl) \
  __asm__ ("subl %5,%1\n\tsbbl %3,%0"					\
	   : "=r" ((USItype) (sh)),					\
	     "=&r" ((USItype) (sl))					\
	   : "0" ((USItype) (ah)),					\
	     "g" ((USItype) (bh)),					\
	     "1" ((USItype) (al)),					\
	     "g" ((USItype) (bl)))
#घोषणा umul_ppmm(w1, w0, u, v) \
  __asm__ ("mull %3"							\
	   : "=a" ((USItype) (w0)),					\
	     "=d" ((USItype) (w1))					\
	   : "%0" ((USItype) (u)),					\
	     "rm" ((USItype) (v)))
#घोषणा udiv_qrnnd(q, r, n1, n0, dv) \
  __asm__ ("divl %4"							\
	   : "=a" ((USItype) (q)),					\
	     "=d" ((USItype) (r))					\
	   : "0" ((USItype) (n0)),					\
	     "1" ((USItype) (n1)),					\
	     "rm" ((USItype) (dv)))
#घोषणा गिनती_leading_zeros(गिनती_2, x) \
  करो {									\
    USItype __cbtmp;							\
    __asm__ ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (गिनती_2) = __cbtmp ^ 31;						\
  } जबतक (0)

/* most of this code is taken from libgcc2.c from gcc */

अटल UDWtype __udivmoddi4 (UDWtype n, UDWtype d, UDWtype *rp)
{
  DWunion ww;
  DWunion nn, dd;
  DWunion rr;
  UWtype d0, d1, n0, n1, n2;
  UWtype q0, q1;
  UWtype b, bm;

  nn.ll = n;
  dd.ll = d;

  d0 = dd.s.निचला;
  d1 = dd.s.ऊपरी;
  n0 = nn.s.निचला;
  n1 = nn.s.ऊपरी;

#अगर !defined(UDIV_NEEDS_NORMALIZATION)
  अगर (d1 == 0)
    {
      अगर (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0.  */
	}
      अन्यथा
	{
	  /* qq = NN / 0d */

	  अगर (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  udiv_qrnnd (q1, n1, 0, n1, d0);
	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0.  */
	}

      अगर (rp != 0)
	{
	  rr.s.निचला = n0;
	  rr.s.ऊपरी = 0;
	  *rp = rr.ll;
	}
    }

#अन्यथा /* UDIV_NEEDS_NORMALIZATION */

  अगर (d1 == 0)
    {
      अगर (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  गिनती_leading_zeros (bm, d0);

	  अगर (bm != 0)
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

	  अगर (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  गिनती_leading_zeros (bm, d0);

	  अगर (bm == 0)
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

      अगर (rp != 0)
	{
	  rr.s.निचला = n0 >> bm;
	  rr.s.ऊपरी = 0;
	  *rp = rr.ll;
	}
    }
#पूर्ण_अगर /* UDIV_NEEDS_NORMALIZATION */

  अन्यथा
    {
      अगर (d1 > n1)
	{
	  /* 00 = nn / DD */

	  q0 = 0;
	  q1 = 0;

	  /* Remainder in n1n0.  */
	  अगर (rp != 0)
	    {
	      rr.s.निचला = n0;
	      rr.s.ऊपरी = n1;
	      *rp = rr.ll;
	    }
	}
      अन्यथा
	{
	  /* 0q = NN / dd */

	  गिनती_leading_zeros (bm, d1);
	  अगर (bm == 0)
	    {
	      /* From (n1 >= d1) /\ (the most significant bit of d1 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 quotient digit q0 = 0 or 1).

		 This special case is necessary, not an optimization.  */

	      /* The condition on the next line takes advantage of that
		 n1 >= d1 (true due to program flow).  */
	      अगर (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);
		}
	      अन्यथा
		q0 = 0;

	      q1 = 0;

	      अगर (rp != 0)
		{
		  rr.s.निचला = n0;
		  rr.s.ऊपरी = n1;
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

	      अगर (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);
		}

	      q1 = 0;

	      /* Remainder in (n1n0 - m1m0) >> bm.  */
	      अगर (rp != 0)
		{
		  sub_ddmmss (n1, n0, n1, n0, m1, m0);
		  rr.s.निचला = (n1 << b) | (n0 >> bm);
		  rr.s.ऊपरी = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }

  ww.s.निचला = q0;
  ww.s.ऊपरी = q1;
  वापस ww.ll;
}

#घोषणा __negdi2(a) (-(a))

दीर्घ दीर्घ __divdi3(दीर्घ दीर्घ u, दीर्घ दीर्घ v)
{
    पूर्णांक c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    अगर (uu.s.ऊपरी < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    अगर (vv.s.ऊपरी < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    अगर (c)
        w = __negdi2 (w);
    वापस w;
}

दीर्घ दीर्घ __moddi3(दीर्घ दीर्घ u, दीर्घ दीर्घ v)
{
    पूर्णांक c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    अगर (uu.s.ऊपरी < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    अगर (vv.s.ऊपरी < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    अगर (c)
        w = __negdi2 (w);
    वापस w;
}

अचिन्हित दीर्घ दीर्घ __udivdi3(अचिन्हित दीर्घ दीर्घ u, अचिन्हित दीर्घ दीर्घ v)
{
    वापस __udivmoddi4 (u, v, (UDWtype *) 0);
}

अचिन्हित दीर्घ दीर्घ __umoddi3(अचिन्हित दीर्घ दीर्घ u, अचिन्हित दीर्घ दीर्घ v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    वापस w;
}

/* XXX: fix tcc's code generator to do this instead */
दीर्घ दीर्घ __ashrdi3(दीर्घ दीर्घ a, पूर्णांक b)
{
#अगर_घोषित __TINYC__
    DWunion u;
    u.ll = a;
    अगर (b >= 32) {
        u.s.निचला = u.s.ऊपरी >> (b - 32);
        u.s.ऊपरी = u.s.ऊपरी >> 31;
    } अन्यथा अगर (b != 0) {
        u.s.निचला = ((अचिन्हित)u.s.निचला >> b) | (u.s.ऊपरी << (32 - b));
        u.s.ऊपरी = u.s.ऊपरी >> b;
    }
    वापस u.ll;
#अन्यथा
    वापस a >> b;
#पूर्ण_अगर
}

/* XXX: fix tcc's code generator to do this instead */
अचिन्हित दीर्घ दीर्घ __lshrdi3(अचिन्हित दीर्घ दीर्घ a, पूर्णांक b)
{
#अगर_घोषित __TINYC__
    DWunion u;
    u.ll = a;
    अगर (b >= 32) {
        u.s.निचला = (अचिन्हित)u.s.ऊपरी >> (b - 32);
        u.s.ऊपरी = 0;
    } अन्यथा अगर (b != 0) {
        u.s.निचला = ((अचिन्हित)u.s.निचला >> b) | (u.s.ऊपरी << (32 - b));
        u.s.ऊपरी = (अचिन्हित)u.s.ऊपरी >> b;
    }
    वापस u.ll;
#अन्यथा
    वापस a >> b;
#पूर्ण_अगर
}

/* XXX: fix tcc's code generator to do this instead */
दीर्घ दीर्घ __ashldi3(दीर्घ दीर्घ a, पूर्णांक b)
{
#अगर_घोषित __TINYC__
    DWunion u;
    u.ll = a;
    अगर (b >= 32) {
        u.s.ऊपरी = (अचिन्हित)u.s.निचला << (b - 32);
        u.s.निचला = 0;
    } अन्यथा अगर (b != 0) {
        u.s.ऊपरी = ((अचिन्हित)u.s.ऊपरी << b) | ((अचिन्हित)u.s.निचला >> (32 - b));
        u.s.निचला = (अचिन्हित)u.s.निचला << b;
    }
    वापस u.ll;
#अन्यथा
    वापस a << b;
#पूर्ण_अगर
}

#पूर्ण_अगर /* __i386__ */

/* XXX: fix tcc's code generator to do this instead */
भग्न __floatundisf(अचिन्हित दीर्घ दीर्घ a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    अगर (uu.s.ऊपरी >= 0) {
        वापस (भग्न)uu.ll;
    } अन्यथा {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        वापस (भग्न)r;
    }
}

द्विगुन __floatundidf(अचिन्हित दीर्घ दीर्घ a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    अगर (uu.s.ऊपरी >= 0) {
        वापस (द्विगुन)uu.ll;
    } अन्यथा {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        वापस (द्विगुन)r;
    }
}

दीर्घ द्विगुन __floatundixf(अचिन्हित दीर्घ दीर्घ a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    अगर (uu.s.ऊपरी >= 0) {
        वापस (दीर्घ द्विगुन)uu.ll;
    } अन्यथा {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        वापस (दीर्घ द्विगुन)r;
    }
}

अचिन्हित दीर्घ दीर्घ __fixunssfdi (भग्न a1)
{
    रेजिस्टर जोड़ float_long fl1;
    रेजिस्टर पूर्णांक exp;
    रेजिस्टर अचिन्हित दीर्घ दीर्घ l;

    fl1.f = a1;

    अगर (fl1.l == 0)
	वापस (0);

    exp = EXP (fl1.l) - EXCESS - 24;
    l = MANT(fl1.l);

    अगर (exp >= 41)
        वापस 1ULL << 63;
    अन्यथा अगर (exp >= 0)
        l <<= exp;
    अन्यथा अगर (exp >= -23)
        l >>= -exp;
    अन्यथा
	वापस 0;
    अगर (SIGN(fl1.l))
        l = (अचिन्हित दीर्घ दीर्घ)-l;
    वापस l;
}

दीर्घ दीर्घ __fixsfdi (भग्न a1)
{
    दीर्घ दीर्घ ret; पूर्णांक s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    वापस s ? ret : -ret;
}

अचिन्हित दीर्घ दीर्घ __fixunsdfdi (द्विगुन a1)
{
    रेजिस्टर जोड़ double_long dl1;
    रेजिस्टर पूर्णांक exp;
    रेजिस्टर अचिन्हित दीर्घ दीर्घ l;

    dl1.d = a1;

    अगर (dl1.ll == 0)
	वापस (0);

    exp = EXPD (dl1) - EXCESSD - 53;
    l = MANTD_LL(dl1);

    अगर (exp >= 12)
        वापस 1ULL << 63; /* overflow result (like gcc, somewhat) */
    अन्यथा अगर (exp >= 0)
        l <<= exp;
    अन्यथा अगर (exp >= -52)
        l >>= -exp;
    अन्यथा
        वापस 0;
    अगर (SIGND(dl1))
        l = (अचिन्हित दीर्घ दीर्घ)-l;
    वापस l;
}

दीर्घ दीर्घ __fixdfdi (द्विगुन a1)
{
    दीर्घ दीर्घ ret; पूर्णांक s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    वापस s ? ret : -ret;
}

#अगर_अघोषित __arm__
अचिन्हित दीर्घ दीर्घ __fixunsxfdi (दीर्घ द्विगुन a1)
{
    रेजिस्टर जोड़ ldouble_long dl1;
    रेजिस्टर पूर्णांक exp;
    रेजिस्टर अचिन्हित दीर्घ दीर्घ l;

    dl1.ld = a1;

    अगर (dl1.l.lower == 0 && dl1.l.upper == 0)
	वापस (0);

    exp = EXPLD (dl1) - EXCESSLD - 64;
    l = dl1.l.lower;
    अगर (exp > 0)
	वापस 1ULL << 63;
    अगर (exp < -63)
        वापस 0;
    l >>= -exp;
    अगर (SIGNLD(dl1))
        l = (अचिन्हित दीर्घ दीर्घ)-l;
    वापस l;
}

दीर्घ दीर्घ __fixxfdi (दीर्घ द्विगुन a1)
{
    दीर्घ दीर्घ ret; पूर्णांक s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    वापस s ? ret : -ret;
}
#पूर्ण_अगर /* !ARM */
