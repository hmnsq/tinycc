/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _MATH_H_
#تعریف_کرو _MATH_H_

#إذا __GNUC__ >= 3
#ہدایت GCC system_سرخی
#جے_انت

#ضمن <_mingw.h>

بنية exception;

#ہدایت pack(ڈالو,_CRT_PACKING)

#تعریف_کرو _DOMAIN 1
#تعریف_کرو _SING 2
#تعریف_کرو حد_توں_ودھ 3
#تعریف_کرو _UNDERFLOW 4
#تعریف_کرو _TLOSS 5
#تعریف_کرو _PLOSS 6

#جے_بنا_تعریف __STRICT_ANSI__
#جے_بنا_تعریف	NO_OLDNAMES
#تعریف_کرو DOMAIN _DOMAIN
#تعریف_کرو SING _SING
#تعریف_کرو حد_توں_ودھ_2 حد_توں_ودھ
#تعریف_کرو UNDERFLOW _UNDERFLOW
#تعریف_کرو TLOSS _TLOSS
#تعریف_کرو PLOSS _PLOSS
#جے_انت
#جے_انت

#جے_بنا_تعریف __STRICT_ANSI__
#تعریف_کرو M_E 2.71828182845904523536
#تعریف_کرو M_LOG2E 1.44269504088896340736
#تعریف_کرو M_LOG10E 0.434294481903251827651
#تعریف_کرو M_LN2 0.693147180559945309417
#تعریف_کرو M_LN10 2.30258509299404568402
#تعریف_کرو M_PI 3.14159265358979323846
#تعریف_کرو M_PI_2 1.57079632679489661923
#تعریف_کرو M_PI_4 0.785398163397448309616
#تعریف_کرو M_1_PI 0.318309886183790671538
#تعریف_کرو M_2_PI 0.636619772367581343076
#تعریف_کرو M_2_SQRTPI 1.12837916709551257390
#تعریف_کرو M_SQRT2 1.41421356237309504880
#تعریف_کرو M_SQRT1_2 0.707106781186547524401
#جے_انت

#جے_بنا_تعریف __STRICT_ANSI__
/* See also float.h  */
#جے_بنا_تعریف __MINGW_FPCLASS_DEFINED
#تعریف_کرو __MINGW_FPCLASS_DEFINED 1
#تعریف_کرو	_FPCLASS_SNAN	0x0001	/* Signaling "Not a Number" */
#تعریف_کرو	_FPCLASS_QNAN	0x0002	/* Quiet "Not a Number" */
#تعریف_کرو	_FPCLASS_NINF	0x0004	/* Negative Infinity */
#تعریف_کرو	_FPCLASS_NN	0x0008	/* Negative Normal */
#تعریف_کرو	_FPCLASS_ND	0x0010	/* Negative Denormal */
#تعریف_کرو	_FPCLASS_NZ	0x0020	/* Negative Zero */
#تعریف_کرو	_FPCLASS_PZ	0x0040	/* Positive Zero */
#تعریف_کرو	_FPCLASS_PD	0x0080	/* Positive Denormal */
#تعریف_کرو	_FPCLASS_PN	0x0100	/* Positive Normal */
#تعریف_کرو	_FPCLASS_PINF	0x0200	/* Positive Infinity */
#جے_انت
#جے_انت

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف _EXCEPTION_DEFINED
#تعریف_کرو _EXCEPTION_DEFINED
  بنية _exception {
    صحيح type;
    حرف *name;
    مزدوج arg1;
    مزدوج arg2;
    مزدوج retval;
  };
#جے_انت

#جے_بنا_تعریف _COMPLEX_DEFINED
#تعریف_کرو _COMPLEX_DEFINED
  بنية _complex {
    مزدوج x,y;
  };
#جے_انت

#تعریف_کرو EDOM 33
#تعریف_کرو ERANGE 34

#جے_بنا_تعریف _HUGE
#جے_تعریف_شدہ _MSVCRT_
  خارجي مزدوج *_HUGE;
#وإلا
  خارجي مزدوج *_imp___HUGE;
#تعریف_کرو _HUGE	(*_imp___HUGE)
#جے_انت
#جے_انت

#تعریف_کرو HUGE_VAL _HUGE

#جے_بنا_تعریف _CRT_ABS_DEFINED
#تعریف_کرو _CRT_ABS_DEFINED
  صحيح __cdecl مطلق_قدر(صحيح _X);
  لما __cdecl labs(لما _X);
#جے_انت
  مزدوج __cdecl acos(مزدوج _X);
  مزدوج __cdecl asin(مزدوج _X);
  مزدوج __cdecl atan(مزدوج _X);
  مزدوج __cdecl atan2(مزدوج _Y,مزدوج _X);
#جے_بنا_تعریف _SIGN_DEFINED
#تعریف_کرو _SIGN_DEFINED
  _CRTIMP مزدوج __cdecl _copysign (مزدوج نمبر,مزدوج _Sign);
  _CRTIMP مزدوج __cdecl _chgsign (مزدوج _X);
#جے_انت
  مزدوج __cdecl جیب_تمام(مزدوج _X);
  مزدوج __cdecl cosh(مزدوج _X);
  مزدوج __cdecl قوت_نما(مزدوج _X);
  مزدوج __cdecl expm1(مزدوج _X);
  مزدوج __cdecl fabs(مزدوج _X);
  مزدوج __cdecl fmod(مزدوج _X,مزدوج _Y);
  مزدوج __cdecl لوگارتھم(مزدوج _X);
  مزدوج __cdecl log10(مزدوج _X);
  مزدوج __cdecl قوت(مزدوج _X,مزدوج _Y);
  مزدوج __cdecl جیب(مزدوج _X);
  مزدوج __cdecl sinh(مزدوج _X);
  مزدوج __cdecl tan(مزدوج _X);
  مزدوج __cdecl tanh(مزدوج _X);
  مزدوج __cdecl جذر(مزدوج _X);
#جے_بنا_تعریف _CRT_ATOF_DEFINED
#تعریف_کرو _CRT_ATOF_DEFINED
  مزدوج __cdecl atof(ثابت حرف *_String);
  مزدوج __cdecl _atof_l(ثابت حرف *_String,_locale_t _Locale);
#جے_انت

  _CRTIMP مزدوج __cdecl _cabs(بنية _complex _ComplexA);
  مزدوج __cdecl ceil(مزدوج _X);
  مزدوج __cdecl floor(مزدوج _X);
  مزدوج __cdecl frexp(مزدوج _X,صحيح *_Y);
  مزدوج __cdecl _hypot(مزدوج _X,مزدوج _Y);
  _CRTIMP مزدوج __cdecl _j0(مزدوج _X);
  _CRTIMP مزدوج __cdecl _j1(مزدوج _X);
  _CRTIMP مزدوج __cdecl _jn(صحيح _X,مزدوج _Y);
  مزدوج __cdecl ldexp(مزدوج _X,صحيح _Y);
#جے_بنا_تعریف _CRT_MATHERR_DEFINED
#تعریف_کرو _CRT_MATHERR_DEFINED
  صحيح __cdecl _matherr(بنية _exception *_Except);
#جے_انت
  مزدوج __cdecl modf(مزدوج _X,مزدوج *_Y);
  _CRTIMP مزدوج __cdecl _y0(مزدوج _X);
  _CRTIMP مزدوج __cdecl _y1(مزدوج _X);
  _CRTIMP مزدوج __cdecl _yn(صحيح _X,مزدوج _Y);

#إذا(defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحيح __cdecl سیٹ_SSE2_enable(صحيح _Flag);
  /* from libmingwex */
  عائم __cdecl _hypotf(عائم _X,عائم _Y);
#جے_انت

  عائم frexpf(عائم _X,صحيح *_Y);
  عائم __cdecl ldexpf(عائم _X,صحيح _Y);
  لما مزدوج __cdecl ldexpl(لما مزدوج _X,صحيح _Y);
  عائم __cdecl acosf(عائم _X);
  عائم __cdecl asinf(عائم _X);
   عائم __cdecl atanf(عائم _X);
   عائم __cdecl atan2f(عائم _X,عائم _Y);
   عائم __cdecl cosf(عائم _X);
   عائم __cdecl sinf(عائم _X);
   عائم __cdecl tanf(عائم _X);
   عائم __cdecl coshf(عائم _X);
   عائم __cdecl sinhf(عائم _X);
   عائم __cdecl tanhf(عائم _X);
   عائم __cdecl expf(عائم _X);
   عائم __cdecl expm1f(عائم _X);
   عائم __cdecl logf(عائم _X);
   عائم __cdecl log10f(عائم _X);
   عائم __cdecl modff(عائم _X,عائم *_Y);
   عائم __cdecl powf(عائم _X,عائم _Y);
   عائم __cdecl sqrtf(عائم _X);
   عائم __cdecl ceilf(عائم _X);
   عائم __cdecl floorf(عائم _X);
  عائم __cdecl fmodf(عائم _X,عائم _Y);
   عائم __cdecl _hypotf(عائم _X,عائم _Y);
  عائم __cdecl fabsf(عائم _X);
#إذا !defined(__ia64__)
   /* from libmingwex */
   عائم __cdecl _copysignf (عائم نمبر,عائم _Sign);
   عائم __cdecl _chgsignf (عائم _X);
   عائم __cdecl _logbf(عائم _X);
   عائم __cdecl _nextafterf(عائم _X,عائم _Y);
   صحيح __cdecl _finitef(عائم _X);
   صحيح __cdecl _isnanf(عائم _X);
   صحيح __cdecl _fpclassf(عائم _X);
#جے_انت

#جے_بنا_تعریف	NO_OLDNAMES
#تعریف_کرو matherr _matherr

#تعریف_کرو HUGE	_HUGE
  /*	double __cdecl cabs(struct _complex _X); */
  مزدوج __cdecl hypot(مزدوج _X,مزدوج _Y);
  _CRTIMP مزدوج __cdecl j0(مزدوج _X);
  _CRTIMP مزدوج __cdecl j1(مزدوج _X);
  _CRTIMP مزدوج __cdecl jn(صحيح _X,مزدوج _Y);
  _CRTIMP مزدوج __cdecl y0(مزدوج _X);
  _CRTIMP مزدوج __cdecl y1(مزدوج _X);
  _CRTIMP مزدوج __cdecl yn(صحيح _X,مزدوج _Y);
#جے_انت

#جے_بنا_تعریف __NO_ISOCEXT
#إذا (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
  || !defined __STRICT_ANSI__ || defined __GLIBCPP__

#تعریف_کرو NAN (0.0F/0.0F)
#تعریف_کرو HUGE_VALF (1.0F/0.0F)
#تعریف_کرو HUGE_VALL (1.0L/0.0L)
#تعریف_کرو INFINITY (1.0F/0.0F)


#تعریف_کرو FP_NAN		0x0100
#تعریف_کرو FP_NORMAL	0x0400
#تعریف_کرو FP_INFINITE	(FP_NAN | FP_NORMAL)
#تعریف_کرو FP_ZERO		0x4000
#تعریف_کرو FP_SUBNORMAL	(FP_NORMAL | FP_ZERO)
  /* 0x0200 is signbit mask */


  /*
  We can't __CRT_INLINE float or double, because we want to ensure truncation
  to semantic type before classification. 
  (A normal long double value might become subnormal when 
  converted to double, and zero when converted to float.)
  */

  خارجي صحيح __cdecl __fpclassifyf (عائم);
  خارجي صحيح __cdecl __fpclassify (مزدوج);
  خارجي صحيح __cdecl __fpclassifyl (لما مزدوج);

/* Implemented at tcc/tcc_libm.h
#define fpclassify(x) (sizeof (x) == sizeof (float) ? __fpclassifyf (x)	  \
  : sizeof (x) == sizeof (double) ? __fpclassify (x) \
  : __fpclassifyl (x))
*/
#تعریف_کرو fpclassify(x) \
  _Generic(x, عائم: __fpclassifyf, مزدوج: __fpclassify, لما مزدوج: __fpclassifyl)(x)

  /* 7.12.3.2 */
#تعریف_کرو isfinite(x) ((fpclassify(x) & FP_NAN) == 0)

  /* 7.12.3.3 */
#تعریف_کرو isinf(x) (fpclassify(x) == FP_INFINITE)

  /* 7.12.3.4 */
  /* We don't need to worry about truncation here:
  A NaN stays a NaN. */
#تعریف_کرو isnan(x) (fpclassify(x) == FP_NAN)

  /* 7.12.3.5 */
#تعریف_کرو isnormal(x) (fpclassify(x) == FP_NORMAL)

  /* 7.12.3.6 The signbit macro */

  خارجي صحيح __cdecl __signbitf (عائم);
  خارجي صحيح __cdecl __signbit (مزدوج);
  خارجي صحيح __cdecl __signbitl (لما مزدوج);

/* Implemented at tcc/tcc_libm.h
#define signbit(x) (sizeof (x) == sizeof (float) ? __signbitf (x)	\
  : sizeof (x) == sizeof (double) ? __signbit (x)	\
  : __signbitl (x))
*/
#تعریف_کرو signbit(x) \
  _Generic(x, عائم: __signbitf, مزدوج: __signbit, لما مزدوج: __signbitl)(x)

  خارجي مزدوج __cdecl exp2(مزدوج);
  خارجي عائم __cdecl exp2f(عائم);
  خارجي لما مزدوج __cdecl exp2l(لما مزدوج);

#تعریف_کرو FP_ILOGB0 ((صحيح)0x80000000)
#تعریف_کرو FP_ILOGBNAN ((صحيح)0x80000000)
  خارجي صحيح __cdecl ilogb (مزدوج);
  خارجي صحيح __cdecl ilogbf (عائم);
  خارجي صحيح __cdecl ilogbl (لما مزدوج);

  خارجي مزدوج __cdecl log1p(مزدوج);
  خارجي عائم __cdecl log1pf(عائم);
  خارجي لما مزدوج __cdecl log1pl(لما مزدوج);

  خارجي مزدوج __cdecl log2 (مزدوج);
  خارجي عائم __cdecl log2f (عائم);
  خارجي لما مزدوج __cdecl log2l (لما مزدوج);

  خارجي مزدوج __cdecl logb (مزدوج);
  خارجي عائم __cdecl logbf (عائم);
  خارجي لما مزدوج __cdecl logbl (لما مزدوج);

  خارجي لما مزدوج __cdecl modfl (لما مزدوج, لما مزدوج*);

  /* 7.12.6.13 */
  خارجي مزدوج __cdecl scalbn (مزدوج, صحيح);
  خارجي عائم __cdecl scalbnf (عائم, صحيح);
  خارجي لما مزدوج __cdecl scalbnl (لما مزدوج, صحيح);

  خارجي مزدوج __cdecl scalbln (مزدوج, لما);
  خارجي عائم __cdecl scalblnf (عائم, لما);
  خارجي لما مزدوج __cdecl scalblnl (لما مزدوج, لما);

  /* 7.12.7.1 */
  /* Implementations adapted from Cephes versions */ 
  خارجي مزدوج __cdecl cbrt (مزدوج);
  خارجي عائم __cdecl cbrtf (عائم);
  خارجي لما مزدوج __cdecl cbrtl (لما مزدوج);

  خارجي مزدوج __cdecl hypot (مزدوج, مزدوج);
  خارجي عائم __cdecl hypotf (عائم, عائم);
  خارجي لما مزدوج __cdecl hypotl (لما مزدوج, لما مزدوج);

  خارجي لما مزدوج __cdecl powl (لما مزدوج, لما مزدوج);
  خارجي لما مزدوج __cdecl expl(لما مزدوج);
  خارجي لما مزدوج __cdecl expm1l(لما مزدوج);
  خارجي لما مزدوج __cdecl coshl(لما مزدوج);
  خارجي لما مزدوج __cdecl fabsl (لما مزدوج);
  خارجي لما مزدوج __cdecl acosl(لما مزدوج);
  خارجي لما مزدوج __cdecl asinl(لما مزدوج);
  خارجي لما مزدوج __cdecl atanl(لما مزدوج);
  خارجي لما مزدوج __cdecl atan2l(لما مزدوج,لما مزدوج);
  خارجي لما مزدوج __cdecl sinhl(لما مزدوج);
  خارجي لما مزدوج __cdecl tanhl(لما مزدوج);

  /* 7.12.8.1 The erf functions  */
  خارجي مزدوج __cdecl erf (مزدوج);
  خارجي عائم __cdecl erff (عائم);
  /* TODO
  extern long double __cdecl erfl (long double);
  */ 

  /* 7.12.8.2 The erfc functions  */
  خارجي مزدوج __cdecl erfc (مزدوج);
  خارجي عائم __cdecl erfcf (عائم);
  /* TODO
  extern long double __cdecl erfcl (long double);
  */ 

  /* 7.12.8.3 The lgamma functions */
  خارجي مزدوج __cdecl lgamma (مزدوج);
  خارجي عائم __cdecl lgammaf (عائم);
  خارجي لما مزدوج __cdecl lgammal (لما مزدوج);

  /* 7.12.8.4 The tgamma functions */
  خارجي مزدوج __cdecl tgamma (مزدوج);
  خارجي عائم __cdecl tgammaf (عائم);
  خارجي لما مزدوج __cdecl tgammal (لما مزدوج);

  خارجي لما مزدوج __cdecl ceill (لما مزدوج);
  خارجي لما مزدوج __cdecl floorl (لما مزدوج);
  خارجي لما مزدوج __cdecl frexpl(لما مزدوج,صحيح *);
  خارجي لما مزدوج __cdecl log10l(لما مزدوج);
  خارجي لما مزدوج __cdecl logl(لما مزدوج);
  خارجي لما مزدوج __cdecl cosl(لما مزدوج);
  خارجي لما مزدوج __cdecl sinl(لما مزدوج);
  خارجي لما مزدوج __cdecl tanl(لما مزدوج);
  خارجي لما مزدوج sqrtl(لما مزدوج);

  /* 7.12.9.3 */
  خارجي مزدوج __cdecl nearbyint ( مزدوج);
  خارجي عائم __cdecl nearbyintf (عائم);
  خارجي لما مزدوج __cdecl nearbyintl (لما مزدوج);

  /* 7.12.9.4 */
  /* round, using fpu control word settings */
  خارجي مزدوج __cdecl rint (مزدوج);
  خارجي عائم __cdecl rintf (عائم);
  خارجي لما مزدوج __cdecl rintl (لما مزدوج);

  خارجي لما __cdecl lrint (مزدوج);
  خارجي لما __cdecl lrintf (عائم);
  خارجي لما __cdecl lrintl (لما مزدوج);

  خارجي لما لما __cdecl llrint (مزدوج);
  خارجي لما لما __cdecl llrintf (عائم);
  خارجي لما لما __cdecl llrintl (لما مزدوج);

  #تعریف_کرو FE_TONEAREST	0x0000
  #تعریف_کرو FE_DOWNWARD	0x0400
  #تعریف_کرو FE_UPWARD	0x0800
  #تعریف_کرو FE_TOWARDZERO	0x0c00

  /* 7.12.9.6 */
  /* round away from zero, regardless of fpu control word settings */
  خارجي مزدوج __cdecl گیڑا (مزدوج);
  خارجي عائم __cdecl roundf (عائم);
  خارجي لما مزدوج __cdecl roundl (لما مزدوج);

  /* 7.12.9.7  */
  خارجي لما __cdecl lround (مزدوج);
  خارجي لما __cdecl lroundf (عائم);
  خارجي لما __cdecl lroundl (لما مزدوج);

  خارجي لما لما __cdecl llround (مزدوج);
  خارجي لما لما __cdecl llroundf (عائم);
  خارجي لما لما __cdecl llroundl (لما مزدوج);

  /* 7.12.9.8 */
  /* round towards zero, regardless of fpu control word settings */
  خارجي مزدوج __cdecl trunc (مزدوج);
  خارجي عائم __cdecl truncf (عائم);
  خارجي لما مزدوج __cdecl truncl (لما مزدوج);

  خارجي لما مزدوج __cdecl fmodl (لما مزدوج, لما مزدوج);

  /* 7.12.10.2 */ 
  خارجي مزدوج __cdecl remainder (مزدوج, مزدوج);
  خارجي عائم __cdecl remainderf (عائم, عائم);
  خارجي لما مزدوج __cdecl remainderl (لما مزدوج, لما مزدوج);

  /* 7.12.10.3 */
  خارجي مزدوج __cdecl remquo(مزدوج, مزدوج, صحيح *);
  خارجي عائم __cdecl remquof(عائم, عائم, صحيح *);
  خارجي لما مزدوج __cdecl remquol(لما مزدوج, لما مزدوج, صحيح *);

  /* 7.12.11.1 */
  خارجي مزدوج __cdecl copysign (مزدوج, مزدوج); /* in libmoldname.a */
  خارجي عائم __cdecl copysignf (عائم, عائم);
  خارجي لما مزدوج __cdecl copysignl (لما مزدوج, لما مزدوج);

  /* 7.12.11.2 Return a NaN */
  خارجي مزدوج __cdecl nan(ثابت حرف *tagp);
  خارجي عائم __cdecl nanf(ثابت حرف *tagp);
  خارجي لما مزدوج __cdecl nanl(ثابت حرف *tagp);

#جے_بنا_تعریف __STRICT_ANSI__
#تعریف_کرو _nan() nan("")
#تعریف_کرو _nanf() nanf("")
#تعریف_کرو _nanl() nanl("")
#جے_انت

  /* 7.12.11.3 */
  خارجي مزدوج __cdecl nextafter (مزدوج, مزدوج); /* in libmoldname.a */
  خارجي عائم __cdecl nextafterf (عائم, عائم);
  خارجي لما مزدوج __cdecl nextafterl (لما مزدوج, لما مزدوج);

  /* 7.12.11.4 The nexttoward functions: TODO */

  /* 7.12.12.1 */
  /*  x > y ? (x - y) : 0.0  */
  خارجي مزدوج __cdecl fdim (مزدوج x, مزدوج y);
  خارجي عائم __cdecl fdimf (عائم x, عائم y);
  خارجي لما مزدوج __cdecl fdiml (لما مزدوج x, لما مزدوج y);

  /* fmax and fmin.
  NaN arguments are treated as missing data: if one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

  /* 7.12.12.2 */
  خارجي مزدوج __cdecl fmax  (مزدوج, مزدوج);
  خارجي عائم __cdecl fmaxf (عائم, عائم);
  خارجي لما مزدوج __cdecl fmaxl (لما مزدوج, لما مزدوج);

  /* 7.12.12.3 */
  خارجي مزدوج __cdecl fmin (مزدوج, مزدوج);
  خارجي عائم __cdecl fminf (عائم, عائم);
  خارجي لما مزدوج __cdecl fminl (لما مزدوج, لما مزدوج);

  /* 7.12.13.1 */
  /* return x * y + z as a ternary op */ 
  خارجي مزدوج __cdecl fma (مزدوج, مزدوج, مزدوج);
  خارجي عائم __cdecl fmaf (عائم, عائم, عائم);
  خارجي لما مزدوج __cdecl fmal (لما مزدوج, لما مزدوج, لما مزدوج);


#جے_انت /* __STDC_VERSION__ >= 199901L */
#جے_انت /* __NO_ISOCEXT */

#جے_تعریف_شدہ __cplusplus
}
#جے_انت
#ہدایت pack(نکالو)

/* 7.12.14 */
/* 
 *  With these functions, comparisons involving quiet NaNs set the FP
 *  condition code to "unordered".  The IEEE floating-point spec
 *  dictates that the result of floating-point comparisons should be
 *  false whenever a NaN is involved, with the exception of the != op, 
 *  which always returns true: yes, (NaN != NaN) is true).
 */

/* Mini libm (inline __fpclassify*, __signbit* and variants) */
#ضمن "tcc/tcc_libm.h"

#جے_انت /* End _MATH_H_ */

