/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _MATH_H_
#నిర్వచించు _MATH_H_

#ఒకవేళ __GNUC__ >= 3
#సూచన GCC system_శీర్షిక
#అయితే_ముగింపు

#అన్తర్భావ <_mingw.h>

నిర్మాణం exception;

#సూచన pack(నెట్టు,_CRT_PACKING)

#నిర్వచించు _DOMAIN 1
#నిర్వచించు _SING 2
#నిర్వచించు అధికప్రవాహం 3
#నిర్వచించు _UNDERFLOW 4
#నిర్వచించు _TLOSS 5
#నిర్వచించు _PLOSS 6

#నిర్వచితం_కాకపోతే __STRICT_ANSI__
#నిర్వచితం_కాకపోతే	NO_OLDNAMES
#నిర్వచించు DOMAIN _DOMAIN
#నిర్వచించు SING _SING
#నిర్వచించు అధికప్రవాహం_2 అధికప్రవాహం
#నిర్వచించు UNDERFLOW _UNDERFLOW
#నిర్వచించు TLOSS _TLOSS
#నిర్వచించు PLOSS _PLOSS
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే __STRICT_ANSI__
#నిర్వచించు M_E 2.71828182845904523536
#నిర్వచించు M_LOG2E 1.44269504088896340736
#నిర్వచించు M_LOG10E 0.434294481903251827651
#నిర్వచించు M_LN2 0.693147180559945309417
#నిర్వచించు M_LN10 2.30258509299404568402
#నిర్వచించు M_PI 3.14159265358979323846
#నిర్వచించు M_PI_2 1.57079632679489661923
#నిర్వచించు M_PI_4 0.785398163397448309616
#నిర్వచించు M_1_PI 0.318309886183790671538
#నిర్వచించు M_2_PI 0.636619772367581343076
#నిర్వచించు M_2_SQRTPI 1.12837916709551257390
#నిర్వచించు M_SQRT2 1.41421356237309504880
#నిర్వచించు M_SQRT1_2 0.707106781186547524401
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే __STRICT_ANSI__
/* See also float.h  */
#నిర్వచితం_కాకపోతే __MINGW_FPCLASS_DEFINED
#నిర్వచించు __MINGW_FPCLASS_DEFINED 1
#నిర్వచించు	_FPCLASS_SNAN	0x0001	/* Signaling "Not a Number" */
#నిర్వచించు	_FPCLASS_QNAN	0x0002	/* Quiet "Not a Number" */
#నిర్వచించు	_FPCLASS_NINF	0x0004	/* Negative Infinity */
#నిర్వచించు	_FPCLASS_NN	0x0008	/* Negative Normal */
#నిర్వచించు	_FPCLASS_ND	0x0010	/* Negative Denormal */
#నిర్వచించు	_FPCLASS_NZ	0x0020	/* Negative Zero */
#నిర్వచించు	_FPCLASS_PZ	0x0040	/* Positive Zero */
#నిర్వచించు	_FPCLASS_PD	0x0080	/* Positive Denormal */
#నిర్వచించు	_FPCLASS_PN	0x0100	/* Positive Normal */
#నిర్వచించు	_FPCLASS_PINF	0x0200	/* Positive Infinity */
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _EXCEPTION_DEFINED
#నిర్వచించు _EXCEPTION_DEFINED
  నిర్మాణం _exception {
    పూర్ణాంకం type;
    అక్షరం *name;
    ద్విగుణ arg1;
    ద్విగుణ arg2;
    ద్విగుణ retval;
  };
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _COMPLEX_DEFINED
#నిర్వచించు _COMPLEX_DEFINED
  నిర్మాణం _complex {
    ద్విగుణ x,y;
  };
#అయితే_ముగింపు

#నిర్వచించు EDOM 33
#నిర్వచించు ERANGE 34

#నిర్వచితం_కాకపోతే _HUGE
#నిర్వచితమైతే _MSVCRT_
  బాహ్య ద్విగుణ *_HUGE;
#లేకపోతే
  బాహ్య ద్విగుణ *_imp___HUGE;
#నిర్వచించు _HUGE	(*_imp___HUGE)
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు HUGE_VAL _HUGE

#నిర్వచితం_కాకపోతే _CRT_ABS_DEFINED
#నిర్వచించు _CRT_ABS_DEFINED
  పూర్ణాంకం __cdecl నిరపేక్ష(పూర్ణాంకం _X);
  దీర్ఘ __cdecl labs(దీర్ఘ _X);
#అయితే_ముగింపు
  ద్విగుణ __cdecl acos(ద్విగుణ _X);
  ద్విగుణ __cdecl asin(ద్విగుణ _X);
  ద్విగుణ __cdecl atan(ద్విగుణ _X);
  ద్విగుణ __cdecl atan2(ద్విగుణ _Y,ద్విగుణ _X);
#నిర్వచితం_కాకపోతే _SIGN_DEFINED
#నిర్వచించు _SIGN_DEFINED
  _CRTIMP ద్విగుణ __cdecl _copysign (ద్విగుణ సంఖ్య,ద్విగుణ _Sign);
  _CRTIMP ద్విగుణ __cdecl _chgsign (ద్విగుణ _X);
#అయితే_ముగింపు
  ద్విగుణ __cdecl కోజ్యా(ద్విగుణ _X);
  ద్విగుణ __cdecl cosh(ద్విగుణ _X);
  ద్విగుణ __cdecl ఘాతాంకం(ద్విగుణ _X);
  ద్విగుణ __cdecl expm1(ద్విగుణ _X);
  ద్విగుణ __cdecl fabs(ద్విగుణ _X);
  ద్విగుణ __cdecl fmod(ద్విగుణ _X,ద్విగుణ _Y);
  ద్విగుణ __cdecl సంవర్గమానం(ద్విగుణ _X);
  ద్విగుణ __cdecl log10(ద్విగుణ _X);
  ద్విగుణ __cdecl ఘాతం(ద్విగుణ _X,ద్విగుణ _Y);
  ద్విగుణ __cdecl జ్యా(ద్విగుణ _X);
  ద్విగుణ __cdecl sinh(ద్విగుణ _X);
  ద్విగుణ __cdecl tan(ద్విగుణ _X);
  ద్విగుణ __cdecl tanh(ద్విగుణ _X);
  ద్విగుణ __cdecl వర్గమూలం(ద్విగుణ _X);
#నిర్వచితం_కాకపోతే _CRT_ATOF_DEFINED
#నిర్వచించు _CRT_ATOF_DEFINED
  ద్విగుణ __cdecl atof(స్థిరరాశి అక్షరం *_String);
  ద్విగుణ __cdecl _atof_l(స్థిరరాశి అక్షరం *_String,_locale_t _Locale);
#అయితే_ముగింపు

  _CRTIMP ద్విగుణ __cdecl _cabs(నిర్మాణం _complex _ComplexA);
  ద్విగుణ __cdecl ceil(ద్విగుణ _X);
  ద్విగుణ __cdecl floor(ద్విగుణ _X);
  ద్విగుణ __cdecl frexp(ద్విగుణ _X,పూర్ణాంకం *_Y);
  ద్విగుణ __cdecl _hypot(ద్విగుణ _X,ద్విగుణ _Y);
  _CRTIMP ద్విగుణ __cdecl _j0(ద్విగుణ _X);
  _CRTIMP ద్విగుణ __cdecl _j1(ద్విగుణ _X);
  _CRTIMP ద్విగుణ __cdecl _jn(పూర్ణాంకం _X,ద్విగుణ _Y);
  ద్విగుణ __cdecl ldexp(ద్విగుణ _X,పూర్ణాంకం _Y);
#నిర్వచితం_కాకపోతే _CRT_MATHERR_DEFINED
#నిర్వచించు _CRT_MATHERR_DEFINED
  పూర్ణాంకం __cdecl _matherr(నిర్మాణం _exception *_Except);
#అయితే_ముగింపు
  ద్విగుణ __cdecl modf(ద్విగుణ _X,ద్విగుణ *_Y);
  _CRTIMP ద్విగుణ __cdecl _y0(ద్విగుణ _X);
  _CRTIMP ద్విగుణ __cdecl _y1(ద్విగుణ _X);
  _CRTIMP ద్విగుణ __cdecl _yn(పూర్ణాంకం _X,ద్విగుణ _Y);

#ఒకవేళ(defined(_X86_) && !defined(__x86_64))
  _CRTIMP పూర్ణాంకం __cdecl సమితి_SSE2_enable(పూర్ణాంకం _Flag);
  /* from libmingwex */
  దశాంశం __cdecl _hypotf(దశాంశం _X,దశాంశం _Y);
#అయితే_ముగింపు

  దశాంశం frexpf(దశాంశం _X,పూర్ణాంకం *_Y);
  దశాంశం __cdecl ldexpf(దశాంశం _X,పూర్ణాంకం _Y);
  దీర్ఘ ద్విగుణ __cdecl ldexpl(దీర్ఘ ద్విగుణ _X,పూర్ణాంకం _Y);
  దశాంశం __cdecl acosf(దశాంశం _X);
  దశాంశం __cdecl asinf(దశాంశం _X);
   దశాంశం __cdecl atanf(దశాంశం _X);
   దశాంశం __cdecl atan2f(దశాంశం _X,దశాంశం _Y);
   దశాంశం __cdecl cosf(దశాంశం _X);
   దశాంశం __cdecl sinf(దశాంశం _X);
   దశాంశం __cdecl tanf(దశాంశం _X);
   దశాంశం __cdecl coshf(దశాంశం _X);
   దశాంశం __cdecl sinhf(దశాంశం _X);
   దశాంశం __cdecl tanhf(దశాంశం _X);
   దశాంశం __cdecl expf(దశాంశం _X);
   దశాంశం __cdecl expm1f(దశాంశం _X);
   దశాంశం __cdecl logf(దశాంశం _X);
   దశాంశం __cdecl log10f(దశాంశం _X);
   దశాంశం __cdecl modff(దశాంశం _X,దశాంశం *_Y);
   దశాంశం __cdecl powf(దశాంశం _X,దశాంశం _Y);
   దశాంశం __cdecl sqrtf(దశాంశం _X);
   దశాంశం __cdecl ceilf(దశాంశం _X);
   దశాంశం __cdecl floorf(దశాంశం _X);
  దశాంశం __cdecl fmodf(దశాంశం _X,దశాంశం _Y);
   దశాంశం __cdecl _hypotf(దశాంశం _X,దశాంశం _Y);
  దశాంశం __cdecl fabsf(దశాంశం _X);
#ఒకవేళ !defined(__ia64__)
   /* from libmingwex */
   దశాంశం __cdecl _copysignf (దశాంశం సంఖ్య,దశాంశం _Sign);
   దశాంశం __cdecl _chgsignf (దశాంశం _X);
   దశాంశం __cdecl _logbf(దశాంశం _X);
   దశాంశం __cdecl _nextafterf(దశాంశం _X,దశాంశం _Y);
   పూర్ణాంకం __cdecl _finitef(దశాంశం _X);
   పూర్ణాంకం __cdecl _isnanf(దశాంశం _X);
   పూర్ణాంకం __cdecl _fpclassf(దశాంశం _X);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే	NO_OLDNAMES
#నిర్వచించు matherr _matherr

#నిర్వచించు HUGE	_HUGE
  /*	double __cdecl cabs(struct _complex _X); */
  ద్విగుణ __cdecl hypot(ద్విగుణ _X,ద్విగుణ _Y);
  _CRTIMP ద్విగుణ __cdecl j0(ద్విగుణ _X);
  _CRTIMP ద్విగుణ __cdecl j1(ద్విగుణ _X);
  _CRTIMP ద్విగుణ __cdecl jn(పూర్ణాంకం _X,ద్విగుణ _Y);
  _CRTIMP ద్విగుణ __cdecl y0(ద్విగుణ _X);
  _CRTIMP ద్విగుణ __cdecl y1(ద్విగుణ _X);
  _CRTIMP ద్విగుణ __cdecl yn(పూర్ణాంకం _X,ద్విగుణ _Y);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే __NO_ISOCEXT
#ఒకవేళ (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
  || !defined __STRICT_ANSI__ || defined __GLIBCPP__

#నిర్వచించు NAN (0.0F/0.0F)
#నిర్వచించు HUGE_VALF (1.0F/0.0F)
#నిర్వచించు HUGE_VALL (1.0L/0.0L)
#నిర్వచించు INFINITY (1.0F/0.0F)


#నిర్వచించు FP_NAN		0x0100
#నిర్వచించు FP_NORMAL	0x0400
#నిర్వచించు FP_INFINITE	(FP_NAN | FP_NORMAL)
#నిర్వచించు FP_ZERO		0x4000
#నిర్వచించు FP_SUBNORMAL	(FP_NORMAL | FP_ZERO)
  /* 0x0200 is signbit mask */


  /*
  We can't __CRT_INLINE float or double, because we want to ensure truncation
  to semantic type before classification. 
  (A normal long double value might become subnormal when 
  converted to double, and zero when converted to float.)
  */

  బాహ్య పూర్ణాంకం __cdecl __fpclassifyf (దశాంశం);
  బాహ్య పూర్ణాంకం __cdecl __fpclassify (ద్విగుణ);
  బాహ్య పూర్ణాంకం __cdecl __fpclassifyl (దీర్ఘ ద్విగుణ);

/* Implemented at tcc/tcc_libm.h
#define fpclassify(x) (sizeof (x) == sizeof (float) ? __fpclassifyf (x)	  \
  : sizeof (x) == sizeof (double) ? __fpclassify (x) \
  : __fpclassifyl (x))
*/
#నిర్వచించు fpclassify(x) \
  _Generic(x, దశాంశం: __fpclassifyf, ద్విగుణ: __fpclassify, దీర్ఘ ద్విగుణ: __fpclassifyl)(x)

  /* 7.12.3.2 */
#నిర్వచించు isfinite(x) ((fpclassify(x) & FP_NAN) == 0)

  /* 7.12.3.3 */
#నిర్వచించు isinf(x) (fpclassify(x) == FP_INFINITE)

  /* 7.12.3.4 */
  /* We don't need to worry about truncation here:
  A NaN stays a NaN. */
#నిర్వచించు isnan(x) (fpclassify(x) == FP_NAN)

  /* 7.12.3.5 */
#నిర్వచించు isnormal(x) (fpclassify(x) == FP_NORMAL)

  /* 7.12.3.6 The signbit macro */

  బాహ్య పూర్ణాంకం __cdecl __signbitf (దశాంశం);
  బాహ్య పూర్ణాంకం __cdecl __signbit (ద్విగుణ);
  బాహ్య పూర్ణాంకం __cdecl __signbitl (దీర్ఘ ద్విగుణ);

/* Implemented at tcc/tcc_libm.h
#define signbit(x) (sizeof (x) == sizeof (float) ? __signbitf (x)	\
  : sizeof (x) == sizeof (double) ? __signbit (x)	\
  : __signbitl (x))
*/
#నిర్వచించు signbit(x) \
  _Generic(x, దశాంశం: __signbitf, ద్విగుణ: __signbit, దీర్ఘ ద్విగుణ: __signbitl)(x)

  బాహ్య ద్విగుణ __cdecl exp2(ద్విగుణ);
  బాహ్య దశాంశం __cdecl exp2f(దశాంశం);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl exp2l(దీర్ఘ ద్విగుణ);

#నిర్వచించు FP_ILOGB0 ((పూర్ణాంకం)0x80000000)
#నిర్వచించు FP_ILOGBNAN ((పూర్ణాంకం)0x80000000)
  బాహ్య పూర్ణాంకం __cdecl ilogb (ద్విగుణ);
  బాహ్య పూర్ణాంకం __cdecl ilogbf (దశాంశం);
  బాహ్య పూర్ణాంకం __cdecl ilogbl (దీర్ఘ ద్విగుణ);

  బాహ్య ద్విగుణ __cdecl log1p(ద్విగుణ);
  బాహ్య దశాంశం __cdecl log1pf(దశాంశం);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl log1pl(దీర్ఘ ద్విగుణ);

  బాహ్య ద్విగుణ __cdecl log2 (ద్విగుణ);
  బాహ్య దశాంశం __cdecl log2f (దశాంశం);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl log2l (దీర్ఘ ద్విగుణ);

  బాహ్య ద్విగుణ __cdecl logb (ద్విగుణ);
  బాహ్య దశాంశం __cdecl logbf (దశాంశం);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl logbl (దీర్ఘ ద్విగుణ);

  బాహ్య దీర్ఘ ద్విగుణ __cdecl modfl (దీర్ఘ ద్విగుణ, దీర్ఘ ద్విగుణ*);

  /* 7.12.6.13 */
  బాహ్య ద్విగుణ __cdecl scalbn (ద్విగుణ, పూర్ణాంకం);
  బాహ్య దశాంశం __cdecl scalbnf (దశాంశం, పూర్ణాంకం);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl scalbnl (దీర్ఘ ద్విగుణ, పూర్ణాంకం);

  బాహ్య ద్విగుణ __cdecl scalbln (ద్విగుణ, దీర్ఘ);
  బాహ్య దశాంశం __cdecl scalblnf (దశాంశం, దీర్ఘ);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl scalblnl (దీర్ఘ ద్విగుణ, దీర్ఘ);

  /* 7.12.7.1 */
  /* Implementations adapted from Cephes versions */ 
  బాహ్య ద్విగుణ __cdecl cbrt (ద్విగుణ);
  బాహ్య దశాంశం __cdecl cbrtf (దశాంశం);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl cbrtl (దీర్ఘ ద్విగుణ);

  బాహ్య ద్విగుణ __cdecl hypot (ద్విగుణ, ద్విగుణ);
  బాహ్య దశాంశం __cdecl hypotf (దశాంశం, దశాంశం);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl hypotl (దీర్ఘ ద్విగుణ, దీర్ఘ ద్విగుణ);

  బాహ్య దీర్ఘ ద్విగుణ __cdecl powl (దీర్ఘ ద్విగుణ, దీర్ఘ ద్విగుణ);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl expl(దీర్ఘ ద్విగుణ);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl expm1l(దీర్ఘ ద్విగుణ);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl coshl(దీర్ఘ ద్విగుణ);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl fabsl (దీర్ఘ ద్విగుణ);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl acosl(దీర్ఘ ద్విగుణ);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl asinl(దీర్ఘ ద్విగుణ);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl atanl(దీర్ఘ ద్విగుణ);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl atan2l(దీర్ఘ ద్విగుణ,దీర్ఘ ద్విగుణ);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl sinhl(దీర్ఘ ద్విగుణ);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl tanhl(దీర్ఘ ద్విగుణ);

  /* 7.12.8.1 The erf functions  */
  బాహ్య ద్విగుణ __cdecl erf (ద్విగుణ);
  బాహ్య దశాంశం __cdecl erff (దశాంశం);
  /* TODO
  extern long double __cdecl erfl (long double);
  */ 

  /* 7.12.8.2 The erfc functions  */
  బాహ్య ద్విగుణ __cdecl erfc (ద్విగుణ);
  బాహ్య దశాంశం __cdecl erfcf (దశాంశం);
  /* TODO
  extern long double __cdecl erfcl (long double);
  */ 

  /* 7.12.8.3 The lgamma functions */
  బాహ్య ద్విగుణ __cdecl lgamma (ద్విగుణ);
  బాహ్య దశాంశం __cdecl lgammaf (దశాంశం);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl lgammal (దీర్ఘ ద్విగుణ);

  /* 7.12.8.4 The tgamma functions */
  బాహ్య ద్విగుణ __cdecl tgamma (ద్విగుణ);
  బాహ్య దశాంశం __cdecl tgammaf (దశాంశం);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl tgammal (దీర్ఘ ద్విగుణ);

  బాహ్య దీర్ఘ ద్విగుణ __cdecl ceill (దీర్ఘ ద్విగుణ);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl floorl (దీర్ఘ ద్విగుణ);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl frexpl(దీర్ఘ ద్విగుణ,పూర్ణాంకం *);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl log10l(దీర్ఘ ద్విగుణ);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl logl(దీర్ఘ ద్విగుణ);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl cosl(దీర్ఘ ద్విగుణ);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl sinl(దీర్ఘ ద్విగుణ);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl tanl(దీర్ఘ ద్విగుణ);
  బాహ్య దీర్ఘ ద్విగుణ sqrtl(దీర్ఘ ద్విగుణ);

  /* 7.12.9.3 */
  బాహ్య ద్విగుణ __cdecl nearbyint ( ద్విగుణ);
  బాహ్య దశాంశం __cdecl nearbyintf (దశాంశం);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl nearbyintl (దీర్ఘ ద్విగుణ);

  /* 7.12.9.4 */
  /* round, using fpu control word settings */
  బాహ్య ద్విగుణ __cdecl rint (ద్విగుణ);
  బాహ్య దశాంశం __cdecl rintf (దశాంశం);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl rintl (దీర్ఘ ద్విగుణ);

  బాహ్య దీర్ఘ __cdecl lrint (ద్విగుణ);
  బాహ్య దీర్ఘ __cdecl lrintf (దశాంశం);
  బాహ్య దీర్ఘ __cdecl lrintl (దీర్ఘ ద్విగుణ);

  బాహ్య దీర్ఘ దీర్ఘ __cdecl llrint (ద్విగుణ);
  బాహ్య దీర్ఘ దీర్ఘ __cdecl llrintf (దశాంశం);
  బాహ్య దీర్ఘ దీర్ఘ __cdecl llrintl (దీర్ఘ ద్విగుణ);

  #నిర్వచించు FE_TONEAREST	0x0000
  #నిర్వచించు FE_DOWNWARD	0x0400
  #నిర్వచించు FE_UPWARD	0x0800
  #నిర్వచించు FE_TOWARDZERO	0x0c00

  /* 7.12.9.6 */
  /* round away from zero, regardless of fpu control word settings */
  బాహ్య ద్విగుణ __cdecl విడత (ద్విగుణ);
  బాహ్య దశాంశం __cdecl roundf (దశాంశం);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl roundl (దీర్ఘ ద్విగుణ);

  /* 7.12.9.7  */
  బాహ్య దీర్ఘ __cdecl lround (ద్విగుణ);
  బాహ్య దీర్ఘ __cdecl lroundf (దశాంశం);
  బాహ్య దీర్ఘ __cdecl lroundl (దీర్ఘ ద్విగుణ);

  బాహ్య దీర్ఘ దీర్ఘ __cdecl llround (ద్విగుణ);
  బాహ్య దీర్ఘ దీర్ఘ __cdecl llroundf (దశాంశం);
  బాహ్య దీర్ఘ దీర్ఘ __cdecl llroundl (దీర్ఘ ద్విగుణ);

  /* 7.12.9.8 */
  /* round towards zero, regardless of fpu control word settings */
  బాహ్య ద్విగుణ __cdecl trunc (ద్విగుణ);
  బాహ్య దశాంశం __cdecl truncf (దశాంశం);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl truncl (దీర్ఘ ద్విగుణ);

  బాహ్య దీర్ఘ ద్విగుణ __cdecl fmodl (దీర్ఘ ద్విగుణ, దీర్ఘ ద్విగుణ);

  /* 7.12.10.2 */ 
  బాహ్య ద్విగుణ __cdecl remainder (ద్విగుణ, ద్విగుణ);
  బాహ్య దశాంశం __cdecl remainderf (దశాంశం, దశాంశం);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl remainderl (దీర్ఘ ద్విగుణ, దీర్ఘ ద్విగుణ);

  /* 7.12.10.3 */
  బాహ్య ద్విగుణ __cdecl remquo(ద్విగుణ, ద్విగుణ, పూర్ణాంకం *);
  బాహ్య దశాంశం __cdecl remquof(దశాంశం, దశాంశం, పూర్ణాంకం *);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl remquol(దీర్ఘ ద్విగుణ, దీర్ఘ ద్విగుణ, పూర్ణాంకం *);

  /* 7.12.11.1 */
  బాహ్య ద్విగుణ __cdecl copysign (ద్విగుణ, ద్విగుణ); /* in libmoldname.a */
  బాహ్య దశాంశం __cdecl copysignf (దశాంశం, దశాంశం);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl copysignl (దీర్ఘ ద్విగుణ, దీర్ఘ ద్విగుణ);

  /* 7.12.11.2 Return a NaN */
  బాహ్య ద్విగుణ __cdecl nan(స్థిరరాశి అక్షరం *tagp);
  బాహ్య దశాంశం __cdecl nanf(స్థిరరాశి అక్షరం *tagp);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl nanl(స్థిరరాశి అక్షరం *tagp);

#నిర్వచితం_కాకపోతే __STRICT_ANSI__
#నిర్వచించు _nan() nan("")
#నిర్వచించు _nanf() nanf("")
#నిర్వచించు _nanl() nanl("")
#అయితే_ముగింపు

  /* 7.12.11.3 */
  బాహ్య ద్విగుణ __cdecl nextafter (ద్విగుణ, ద్విగుణ); /* in libmoldname.a */
  బాహ్య దశాంశం __cdecl nextafterf (దశాంశం, దశాంశం);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl nextafterl (దీర్ఘ ద్విగుణ, దీర్ఘ ద్విగుణ);

  /* 7.12.11.4 The nexttoward functions: TODO */

  /* 7.12.12.1 */
  /*  x > y ? (x - y) : 0.0  */
  బాహ్య ద్విగుణ __cdecl fdim (ద్విగుణ x, ద్విగుణ y);
  బాహ్య దశాంశం __cdecl fdimf (దశాంశం x, దశాంశం y);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl fdiml (దీర్ఘ ద్విగుణ x, దీర్ఘ ద్విగుణ y);

  /* fmax and fmin.
  NaN arguments are treated as missing data: if one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

  /* 7.12.12.2 */
  బాహ్య ద్విగుణ __cdecl fmax  (ద్విగుణ, ద్విగుణ);
  బాహ్య దశాంశం __cdecl fmaxf (దశాంశం, దశాంశం);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl fmaxl (దీర్ఘ ద్విగుణ, దీర్ఘ ద్విగుణ);

  /* 7.12.12.3 */
  బాహ్య ద్విగుణ __cdecl fmin (ద్విగుణ, ద్విగుణ);
  బాహ్య దశాంశం __cdecl fminf (దశాంశం, దశాంశం);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl fminl (దీర్ఘ ద్విగుణ, దీర్ఘ ద్విగుణ);

  /* 7.12.13.1 */
  /* return x * y + z as a ternary op */ 
  బాహ్య ద్విగుణ __cdecl fma (ద్విగుణ, ద్విగుణ, ద్విగుణ);
  బాహ్య దశాంశం __cdecl fmaf (దశాంశం, దశాంశం, దశాంశం);
  బాహ్య దీర్ఘ ద్విగుణ __cdecl fmal (దీర్ఘ ద్విగుణ, దీర్ఘ ద్విగుణ, దీర్ఘ ద్విగుణ);


#అయితే_ముగింపు /* __STDC_VERSION__ >= 199901L */
#అయితే_ముగింపు /* __NO_ISOCEXT */

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#సూచన pack(తీయి)

/* 7.12.14 */
/* 
 *  With these functions, comparisons involving quiet NaNs set the FP
 *  condition code to "unordered".  The IEEE floating-point spec
 *  dictates that the result of floating-point comparisons should be
 *  false whenever a NaN is involved, with the exception of the != op, 
 *  which always returns true: yes, (NaN != NaN) is true).
 */

/* Mini libm (inline __fpclassify*, __signbit* and variants) */
#అన్తర్భావ "tcc/tcc_libm.h"

#అయితే_ముగింపు /* End _MATH_H_ */

