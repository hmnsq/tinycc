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

#تعریف_کرو W_TYPE_سائز   32
#تعریف_کرو بٹ_فی_UNIT 8

قسمتعریف صحیح Wtype;
قسمتعریف غیرعلامتی صحیح UWtype;
قسمتعریف غیرعلامتی صحیح USItype;
قسمتعریف طویل طویل DWtype;
قسمتعریف غیرعلامتی طویل طویل UDWtype;

ساخت DWstruct {
    Wtype کم, بلند;
};

قسمتعریف اتحاد
{
  ساخت DWstruct s;
  DWtype ll;
} DWunion;

قسمتعریف طویل دوہرا XFtype;
#تعریف_کرو لفظ_سائز (حجم (Wtype) * بٹ_فی_UNIT)
#تعریف_کرو بلند_لفظ_COEFF (((UDWtype) 1) << لفظ_سائز)

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
#تعریف_کرو EXPD(fp)	(((fp.l.بالائی) >> 20) & 0x7FF)
#تعریف_کرو SIGND(fp)	((fp.l.بالائی) & SIGNBIT)
#تعریف_کرو MANTD(fp)	(((((fp.l.بالائی) & 0xFFFFF) | HIDDEND) << 10) | \
				(fp.l.زیریں >> 22))
#تعریف_کرو HIDDEND_LL	((طویل طویل)1 << 52)
#تعریف_کرو MANTD_LL(fp)	((fp.ll & (HIDDEND_LL-1)) | HIDDEND_LL)
#تعریف_کرو PACKD_LL(s,e,m)	(((طویل طویل)((s)+((e)<<20))<<32)|(m))

/* the following deal with x86 long double-precision numbers */
#تعریف_کرو EXCESSLD	16382
#تعریف_کرو EXPLD(fp)	(fp.l.بالائی & 0x7fff)
#تعریف_کرو SIGNLD(fp)	((fp.l.بالائی) & 0x8000)

/* only for x86 */
اتحاد ldouble_long {
    طویل دوہرا ld;
    ساخت {
        غیرعلامتی طویل طویل زیریں;
        غیرعلامتی مختصر بالائی;
    } l;
};

اتحاد double_long {
    دوہرا d;
#اگر 1
    ساخت {
        غیرعلامتی صحیح زیریں;
        صحیح بالائی;
    } l;
#ورنہ
    ساخت {
        صحیح بالائی;
        غیرعلامتی صحیح زیریں;
    } l;
#اگر_ختم
    طویل طویل ll;
};

اتحاد float_long {
    اعشاری f;
    غیرعلامتی صحیح l;
};

/* XXX: we don't support several builtin supports for now */
#اگر defined __i386__

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
  کرو {									\
    USItype __cbtmp;							\
    __asm__ ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (گنتی_2) = __cbtmp ^ 31;						\
  } جب (0)

/* most of this code is taken from libgcc2.c from gcc */

ساکن UDWtype __udivmoddi4 (UDWtype n, UDWtype d, UDWtype *rp)
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

#اگر !defined(UDIV_NEEDS_NORMALIZATION)
  اگر (d1 == 0)
    {
      اگر (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0.  */
	}
      ورنہ
	{
	  /* qq = NN / 0d */

	  اگر (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  udiv_qrnnd (q1, n1, 0, n1, d0);
	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0.  */
	}

      اگر (rp != 0)
	{
	  rr.s.کم = n0;
	  rr.s.بلند = 0;
	  *rp = rr.ll;
	}
    }

#ورنہ /* UDIV_NEEDS_NORMALIZATION */

  اگر (d1 == 0)
    {
      اگر (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  گنتی_leading_zeros (bm, d0);

	  اگر (bm != 0)
	    {
	      /* Normalize, i.e. make the most significant bit of the
		 denominator set.  */

	      d0 = d0 << bm;
	      n1 = (n1 << bm) | (n0 >> (W_TYPE_سائز - bm));
	      n0 = n0 << bm;
	    }

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0 >> bm.  */
	}
      ورنہ
	{
	  /* qq = NN / 0d */

	  اگر (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  گنتی_leading_zeros (bm, d0);

	  اگر (bm == 0)
	    {
	      /* From (n1 >= d0) /\ (the most significant bit of d0 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 leading quotient digit q1 = 1).

		 This special case is necessary, not an optimization.
		 (Shifts counts of W_TYPE_SIZE are undefined.)  */

	      n1 -= d0;
	      q1 = 1;
	    }
	  ورنہ
	    {
	      /* Normalize.  */

	      b = W_TYPE_سائز - bm;

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

      اگر (rp != 0)
	{
	  rr.s.کم = n0 >> bm;
	  rr.s.بلند = 0;
	  *rp = rr.ll;
	}
    }
#اگر_ختم /* UDIV_NEEDS_NORMALIZATION */

  ورنہ
    {
      اگر (d1 > n1)
	{
	  /* 00 = nn / DD */

	  q0 = 0;
	  q1 = 0;

	  /* Remainder in n1n0.  */
	  اگر (rp != 0)
	    {
	      rr.s.کم = n0;
	      rr.s.بلند = n1;
	      *rp = rr.ll;
	    }
	}
      ورنہ
	{
	  /* 0q = NN / dd */

	  گنتی_leading_zeros (bm, d1);
	  اگر (bm == 0)
	    {
	      /* From (n1 >= d1) /\ (the most significant bit of d1 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 quotient digit q0 = 0 or 1).

		 This special case is necessary, not an optimization.  */

	      /* The condition on the next line takes advantage of that
		 n1 >= d1 (true due to program flow).  */
	      اگر (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);
		}
	      ورنہ
		q0 = 0;

	      q1 = 0;

	      اگر (rp != 0)
		{
		  rr.s.کم = n0;
		  rr.s.بلند = n1;
		  *rp = rr.ll;
		}
	    }
	  ورنہ
	    {
	      UWtype m1, m0;
	      /* Normalize.  */

	      b = W_TYPE_سائز - bm;

	      d1 = (d1 << bm) | (d0 >> b);
	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;

	      udiv_qrnnd (q0, n1, n2, n1, d1);
	      umul_ppmm (m1, m0, q0, d0);

	      اگر (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);
		}

	      q1 = 0;

	      /* Remainder in (n1n0 - m1m0) >> bm.  */
	      اگر (rp != 0)
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
  واپس ww.ll;
}

#تعریف_کرو __negdi2(a) (-(a))

طویل طویل __divdi3(طویل طویل u, طویل طویل v)
{
    صحیح c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    اگر (uu.s.بلند < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    اگر (vv.s.بلند < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    اگر (c)
        w = __negdi2 (w);
    واپس w;
}

طویل طویل __moddi3(طویل طویل u, طویل طویل v)
{
    صحیح c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    اگر (uu.s.بلند < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    اگر (vv.s.بلند < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    اگر (c)
        w = __negdi2 (w);
    واپس w;
}

غیرعلامتی طویل طویل __udivdi3(غیرعلامتی طویل طویل u, غیرعلامتی طویل طویل v)
{
    واپس __udivmoddi4 (u, v, (UDWtype *) 0);
}

غیرعلامتی طویل طویل __umoddi3(غیرعلامتی طویل طویل u, غیرعلامتی طویل طویل v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    واپس w;
}

/* XXX: fix tcc's code generator to do this instead */
طویل طویل __ashrdi3(طویل طویل a, صحیح b)
{
#اگر_تعریف_شدہ __TINYC__
    DWunion u;
    u.ll = a;
    اگر (b >= 32) {
        u.s.کم = u.s.بلند >> (b - 32);
        u.s.بلند = u.s.بلند >> 31;
    } ورنہ اگر (b != 0) {
        u.s.کم = ((غیرعلامتی)u.s.کم >> b) | (u.s.بلند << (32 - b));
        u.s.بلند = u.s.بلند >> b;
    }
    واپس u.ll;
#ورنہ
    واپس a >> b;
#اگر_ختم
}

/* XXX: fix tcc's code generator to do this instead */
غیرعلامتی طویل طویل __lshrdi3(غیرعلامتی طویل طویل a, صحیح b)
{
#اگر_تعریف_شدہ __TINYC__
    DWunion u;
    u.ll = a;
    اگر (b >= 32) {
        u.s.کم = (غیرعلامتی)u.s.بلند >> (b - 32);
        u.s.بلند = 0;
    } ورنہ اگر (b != 0) {
        u.s.کم = ((غیرعلامتی)u.s.کم >> b) | (u.s.بلند << (32 - b));
        u.s.بلند = (غیرعلامتی)u.s.بلند >> b;
    }
    واپس u.ll;
#ورنہ
    واپس a >> b;
#اگر_ختم
}

/* XXX: fix tcc's code generator to do this instead */
طویل طویل __ashldi3(طویل طویل a, صحیح b)
{
#اگر_تعریف_شدہ __TINYC__
    DWunion u;
    u.ll = a;
    اگر (b >= 32) {
        u.s.بلند = (غیرعلامتی)u.s.کم << (b - 32);
        u.s.کم = 0;
    } ورنہ اگر (b != 0) {
        u.s.بلند = ((غیرعلامتی)u.s.بلند << b) | ((غیرعلامتی)u.s.کم >> (32 - b));
        u.s.کم = (غیرعلامتی)u.s.کم << b;
    }
    واپس u.ll;
#ورنہ
    واپس a << b;
#اگر_ختم
}

#اگر_ختم /* __i386__ */

/* XXX: fix tcc's code generator to do this instead */
اعشاری __floatundisf(غیرعلامتی طویل طویل a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    اگر (uu.s.بلند >= 0) {
        واپس (اعشاری)uu.ll;
    } ورنہ {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        واپس (اعشاری)r;
    }
}

دوہرا __floatundidf(غیرعلامتی طویل طویل a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    اگر (uu.s.بلند >= 0) {
        واپس (دوہرا)uu.ll;
    } ورنہ {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        واپس (دوہرا)r;
    }
}

طویل دوہرا __floatundixf(غیرعلامتی طویل طویل a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    اگر (uu.s.بلند >= 0) {
        واپس (طویل دوہرا)uu.ll;
    } ورنہ {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        واپس (طویل دوہرا)r;
    }
}

غیرعلامتی طویل طویل __fixunssfdi (اعشاری a1)
{
    اندراج اتحاد float_long fl1;
    اندراج صحیح قوت_نما;
    اندراج غیرعلامتی طویل طویل l;

    fl1.f = a1;

    اگر (fl1.l == 0)
	واپس (0);

    قوت_نما = EXP (fl1.l) - EXCESS - 24;
    l = MANT(fl1.l);

    اگر (قوت_نما >= 41)
        واپس 1ULL << 63;
    ورنہ اگر (قوت_نما >= 0)
        l <<= قوت_نما;
    ورنہ اگر (قوت_نما >= -23)
        l >>= -قوت_نما;
    ورنہ
	واپس 0;
    اگر (SIGN(fl1.l))
        l = (غیرعلامتی طویل طویل)-l;
    واپس l;
}

طویل طویل __fixsfdi (اعشاری a1)
{
    طویل طویل ret; صحیح s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    واپس s ? ret : -ret;
}

غیرعلامتی طویل طویل __fixunsdfdi (دوہرا a1)
{
    اندراج اتحاد double_long dl1;
    اندراج صحیح قوت_نما;
    اندراج غیرعلامتی طویل طویل l;

    dl1.d = a1;

    اگر (dl1.ll == 0)
	واپس (0);

    قوت_نما = EXPD (dl1) - EXCESSD - 53;
    l = MANTD_LL(dl1);

    اگر (قوت_نما >= 12)
        واپس 1ULL << 63; /* overflow result (like gcc, somewhat) */
    ورنہ اگر (قوت_نما >= 0)
        l <<= قوت_نما;
    ورنہ اگر (قوت_نما >= -52)
        l >>= -قوت_نما;
    ورنہ
        واپس 0;
    اگر (SIGND(dl1))
        l = (غیرعلامتی طویل طویل)-l;
    واپس l;
}

طویل طویل __fixdfdi (دوہرا a1)
{
    طویل طویل ret; صحیح s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    واپس s ? ret : -ret;
}

#اگر_غیر_تعریف_شدہ __arm__
غیرعلامتی طویل طویل __fixunsxfdi (طویل دوہرا a1)
{
    اندراج اتحاد ldouble_long dl1;
    اندراج صحیح قوت_نما;
    اندراج غیرعلامتی طویل طویل l;

    dl1.ld = a1;

    اگر (dl1.l.زیریں == 0 && dl1.l.بالائی == 0)
	واپس (0);

    قوت_نما = EXPLD (dl1) - EXCESSLD - 64;
    l = dl1.l.زیریں;
    اگر (قوت_نما > 0)
	واپس 1ULL << 63;
    اگر (قوت_نما < -63)
        واپس 0;
    l >>= -قوت_نما;
    اگر (SIGNLD(dl1))
        l = (غیرعلامتی طویل طویل)-l;
    واپس l;
}

طویل طویل __fixxfdi (طویل دوہرا a1)
{
    طویل طویل ret; صحیح s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    واپس s ? ret : -ret;
}
#اگر_ختم /* !ARM */
