/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _MATH_H_
#define _MATH_H_

#எனில் __GNUC__ >= 3
#pragma GCC system_header
#endif

#அந்தர்பாவ <_mingw.h>

கட்டமைப்பு exception;

#pragma pack(தள்ளு,_CRT_PACKING)

#define _DOMAIN 1
#define _SING 2
#define _OVERFLOW 3
#define _UNDERFLOW 4
#define _TLOSS 5
#define _PLOSS 6

#ifndef __STRICT_ANSI__
#ifndef	NO_OLDNAMES
#define DOMAIN _DOMAIN
#define SING _SING
#define OVERFLOW _OVERFLOW
#define UNDERFLOW _UNDERFLOW
#define TLOSS _TLOSS
#define PLOSS _PLOSS
#endif
#endif

#ifndef __STRICT_ANSI__
#define M_E 2.71828182845904523536
#define M_LOG2E 1.44269504088896340736
#define M_LOG10E 0.434294481903251827651
#define M_LN2 0.693147180559945309417
#define M_LN10 2.30258509299404568402
#define M_PI 3.14159265358979323846
#define M_PI_2 1.57079632679489661923
#define M_PI_4 0.785398163397448309616
#define M_1_PI 0.318309886183790671538
#define M_2_PI 0.636619772367581343076
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2 1.41421356237309504880
#define M_SQRT1_2 0.707106781186547524401
#endif

#ifndef __STRICT_ANSI__
/* See also float.h  */
#ifndef __MINGW_FPCLASS_DEFINED
#define __MINGW_FPCLASS_DEFINED 1
#define	_FPCLASS_SNAN	0x0001	/* Signaling "Not a Number" */
#define	_FPCLASS_QNAN	0x0002	/* Quiet "Not a Number" */
#define	_FPCLASS_NINF	0x0004	/* Negative Infinity */
#define	_FPCLASS_NN	0x0008	/* Negative Normal */
#define	_FPCLASS_ND	0x0010	/* Negative Denormal */
#define	_FPCLASS_NZ	0x0020	/* Negative Zero */
#define	_FPCLASS_PZ	0x0040	/* Positive Zero */
#define	_FPCLASS_PD	0x0080	/* Positive Denormal */
#define	_FPCLASS_PN	0x0100	/* Positive Normal */
#define	_FPCLASS_PINF	0x0200	/* Positive Infinity */
#endif
#endif

#ifdef __cplusplus
வெளி "C" {
#endif

#ifndef _EXCEPTION_DEFINED
#define _EXCEPTION_DEFINED
  கட்டமைப்பு _exception {
    முழு type;
    எழுத்து *name;
    இரட்டை arg1;
    இரட்டை arg2;
    இரட்டை retval;
  };
#endif

#ifndef _COMPLEX_DEFINED
#define _COMPLEX_DEFINED
  கட்டமைப்பு _complex {
    இரட்டை x,y;
  };
#endif

#define EDOM 33
#define ERANGE 34

#ifndef _HUGE
#ifdef _MSVCRT_
  வெளி இரட்டை *_HUGE;
#இல்லையெனில்
  வெளி இரட்டை *_imp___HUGE;
#define _HUGE	(*_imp___HUGE)
#endif
#endif

#define HUGE_VAL _HUGE

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  முழு __cdecl abs(முழு _X);
  long __cdecl labs(long _X);
#endif
  இரட்டை __cdecl acos(இரட்டை _X);
  இரட்டை __cdecl asin(இரட்டை _X);
  இரட்டை __cdecl atan(இரட்டை _X);
  இரட்டை __cdecl atan2(இரட்டை _Y,இரட்டை _X);
#ifndef _SIGN_DEFINED
#define _SIGN_DEFINED
  _CRTIMP இரட்டை __cdecl _copysign (இரட்டை எண்,இரட்டை _Sign);
  _CRTIMP இரட்டை __cdecl _chgsign (இரட்டை _X);
#endif
  இரட்டை __cdecl cos(இரட்டை _X);
  இரட்டை __cdecl cosh(இரட்டை _X);
  இரட்டை __cdecl exp(இரட்டை _X);
  இரட்டை __cdecl expm1(இரட்டை _X);
  இரட்டை __cdecl fabs(இரட்டை _X);
  இரட்டை __cdecl fmod(இரட்டை _X,இரட்டை _Y);
  இரட்டை __cdecl log(இரட்டை _X);
  இரட்டை __cdecl log10(இரட்டை _X);
  இரட்டை __cdecl pow(இரட்டை _X,இரட்டை _Y);
  இரட்டை __cdecl sin(இரட்டை _X);
  இரட்டை __cdecl sinh(இரட்டை _X);
  இரட்டை __cdecl tan(இரட்டை _X);
  இரட்டை __cdecl tanh(இரட்டை _X);
  இரட்டை __cdecl sqrt(இரட்டை _X);
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  இரட்டை __cdecl atof(மாறிலி எழுத்து *_String);
  இரட்டை __cdecl _atof_l(மாறிலி எழுத்து *_String,_locale_t _Locale);
#endif

  _CRTIMP இரட்டை __cdecl _cabs(கட்டமைப்பு _complex _ComplexA);
  இரட்டை __cdecl ceil(இரட்டை _X);
  இரட்டை __cdecl floor(இரட்டை _X);
  இரட்டை __cdecl frexp(இரட்டை _X,முழு *_Y);
  இரட்டை __cdecl _hypot(இரட்டை _X,இரட்டை _Y);
  _CRTIMP இரட்டை __cdecl _j0(இரட்டை _X);
  _CRTIMP இரட்டை __cdecl _j1(இரட்டை _X);
  _CRTIMP இரட்டை __cdecl _jn(முழு _X,இரட்டை _Y);
  இரட்டை __cdecl ldexp(இரட்டை _X,முழு _Y);
#ifndef _CRT_MATHERR_DEFINED
#define _CRT_MATHERR_DEFINED
  முழு __cdecl _matherr(கட்டமைப்பு _exception *_Except);
#endif
  இரட்டை __cdecl modf(இரட்டை _X,இரட்டை *_Y);
  _CRTIMP இரட்டை __cdecl _y0(இரட்டை _X);
  _CRTIMP இரட்டை __cdecl _y1(இரட்டை _X);
  _CRTIMP இரட்டை __cdecl _yn(முழு _X,இரட்டை _Y);

#எனில்(defined(_X86_) && !defined(__x86_64))
  _CRTIMP முழு __cdecl _set_SSE2_enable(முழு _Flag);
  /* from libmingwex */
  தசம __cdecl _hypotf(தசம _X,தசம _Y);
#endif

  தசம frexpf(தசம _X,முழு *_Y);
  தசம __cdecl ldexpf(தசம _X,முழு _Y);
  long இரட்டை __cdecl ldexpl(long இரட்டை _X,முழு _Y);
  தசம __cdecl acosf(தசம _X);
  தசம __cdecl asinf(தசம _X);
   தசம __cdecl atanf(தசம _X);
   தசம __cdecl atan2f(தசம _X,தசம _Y);
   தசம __cdecl cosf(தசம _X);
   தசம __cdecl sinf(தசம _X);
   தசம __cdecl tanf(தசம _X);
   தசம __cdecl coshf(தசம _X);
   தசம __cdecl sinhf(தசம _X);
   தசம __cdecl tanhf(தசம _X);
   தசம __cdecl expf(தசம _X);
   தசம __cdecl expm1f(தசம _X);
   தசம __cdecl logf(தசம _X);
   தசம __cdecl log10f(தசம _X);
   தசம __cdecl modff(தசம _X,தசம *_Y);
   தசம __cdecl powf(தசம _X,தசம _Y);
   தசம __cdecl sqrtf(தசம _X);
   தசம __cdecl ceilf(தசம _X);
   தசம __cdecl floorf(தசம _X);
  தசம __cdecl fmodf(தசம _X,தசம _Y);
   தசம __cdecl _hypotf(தசம _X,தசம _Y);
  தசம __cdecl fabsf(தசம _X);
#எனில் !defined(__ia64__)
   /* from libmingwex */
   தசம __cdecl _copysignf (தசம எண்,தசம _Sign);
   தசம __cdecl _chgsignf (தசம _X);
   தசம __cdecl _logbf(தசம _X);
   தசம __cdecl _nextafterf(தசம _X,தசம _Y);
   முழு __cdecl _finitef(தசம _X);
   முழு __cdecl _isnanf(தசம _X);
   முழு __cdecl _fpclassf(தசம _X);
#endif

#ifndef	NO_OLDNAMES
#define matherr _matherr

#define HUGE	_HUGE
  /*	double __cdecl cabs(struct _complex _X); */
  இரட்டை __cdecl hypot(இரட்டை _X,இரட்டை _Y);
  _CRTIMP இரட்டை __cdecl j0(இரட்டை _X);
  _CRTIMP இரட்டை __cdecl j1(இரட்டை _X);
  _CRTIMP இரட்டை __cdecl jn(முழு _X,இரட்டை _Y);
  _CRTIMP இரட்டை __cdecl y0(இரட்டை _X);
  _CRTIMP இரட்டை __cdecl y1(இரட்டை _X);
  _CRTIMP இரட்டை __cdecl yn(முழு _X,இரட்டை _Y);
#endif

#ifndef __NO_ISOCEXT
#எனில் (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
  || !defined __STRICT_ANSI__ || defined __GLIBCPP__

#define NAN (0.0F/0.0F)
#define HUGE_VALF (1.0F/0.0F)
#define HUGE_VALL (1.0L/0.0L)
#define INFINITY (1.0F/0.0F)


#define FP_NAN		0x0100
#define FP_NORMAL	0x0400
#define FP_INFINITE	(FP_NAN | FP_NORMAL)
#define FP_ZERO		0x4000
#define FP_SUBNORMAL	(FP_NORMAL | FP_ZERO)
  /* 0x0200 is signbit mask */


  /*
  We can't __CRT_INLINE float or double, because we want to ensure truncation
  to semantic type before classification. 
  (A normal long double value might become subnormal when 
  converted to double, and zero when converted to float.)
  */

  வெளி முழு __cdecl __fpclassifyf (தசம);
  வெளி முழு __cdecl __fpclassify (இரட்டை);
  வெளி முழு __cdecl __fpclassifyl (long இரட்டை);

/* Implemented at tcc/tcc_libm.h
#define fpclassify(x) (sizeof (x) == sizeof (float) ? __fpclassifyf (x)	  \
  : sizeof (x) == sizeof (double) ? __fpclassify (x) \
  : __fpclassifyl (x))
*/
#define fpclassify(x) \
  _Generic(x, தசம: __fpclassifyf, இரட்டை: __fpclassify, long இரட்டை: __fpclassifyl)(x)

  /* 7.12.3.2 */
#define isfinite(x) ((fpclassify(x) & FP_NAN) == 0)

  /* 7.12.3.3 */
#define isinf(x) (fpclassify(x) == FP_INFINITE)

  /* 7.12.3.4 */
  /* We don't need to worry about truncation here:
  A NaN stays a NaN. */
#define isnan(x) (fpclassify(x) == FP_NAN)

  /* 7.12.3.5 */
#define isnormal(x) (fpclassify(x) == FP_NORMAL)

  /* 7.12.3.6 The signbit macro */

  வெளி முழு __cdecl __signbitf (தசம);
  வெளி முழு __cdecl __signbit (இரட்டை);
  வெளி முழு __cdecl __signbitl (long இரட்டை);

/* Implemented at tcc/tcc_libm.h
#define signbit(x) (sizeof (x) == sizeof (float) ? __signbitf (x)	\
  : sizeof (x) == sizeof (double) ? __signbit (x)	\
  : __signbitl (x))
*/
#define signbit(x) \
  _Generic(x, தசம: __signbitf, இரட்டை: __signbit, long இரட்டை: __signbitl)(x)

  வெளி இரட்டை __cdecl exp2(இரட்டை);
  வெளி தசம __cdecl exp2f(தசம);
  வெளி long இரட்டை __cdecl exp2l(long இரட்டை);

#define FP_ILOGB0 ((முழு)0x80000000)
#define FP_ILOGBNAN ((முழு)0x80000000)
  வெளி முழு __cdecl ilogb (இரட்டை);
  வெளி முழு __cdecl ilogbf (தசம);
  வெளி முழு __cdecl ilogbl (long இரட்டை);

  வெளி இரட்டை __cdecl log1p(இரட்டை);
  வெளி தசம __cdecl log1pf(தசம);
  வெளி long இரட்டை __cdecl log1pl(long இரட்டை);

  வெளி இரட்டை __cdecl log2 (இரட்டை);
  வெளி தசம __cdecl log2f (தசம);
  வெளி long இரட்டை __cdecl log2l (long இரட்டை);

  வெளி இரட்டை __cdecl logb (இரட்டை);
  வெளி தசம __cdecl logbf (தசம);
  வெளி long இரட்டை __cdecl logbl (long இரட்டை);

  வெளி long இரட்டை __cdecl modfl (long இரட்டை, long இரட்டை*);

  /* 7.12.6.13 */
  வெளி இரட்டை __cdecl scalbn (இரட்டை, முழு);
  வெளி தசம __cdecl scalbnf (தசம, முழு);
  வெளி long இரட்டை __cdecl scalbnl (long இரட்டை, முழு);

  வெளி இரட்டை __cdecl scalbln (இரட்டை, long);
  வெளி தசம __cdecl scalblnf (தசம, long);
  வெளி long இரட்டை __cdecl scalblnl (long இரட்டை, long);

  /* 7.12.7.1 */
  /* Implementations adapted from Cephes versions */ 
  வெளி இரட்டை __cdecl cbrt (இரட்டை);
  வெளி தசம __cdecl cbrtf (தசம);
  வெளி long இரட்டை __cdecl cbrtl (long இரட்டை);

  வெளி இரட்டை __cdecl hypot (இரட்டை, இரட்டை);
  வெளி தசம __cdecl hypotf (தசம, தசம);
  வெளி long இரட்டை __cdecl hypotl (long இரட்டை, long இரட்டை);

  வெளி long இரட்டை __cdecl powl (long இரட்டை, long இரட்டை);
  வெளி long இரட்டை __cdecl expl(long இரட்டை);
  வெளி long இரட்டை __cdecl expm1l(long இரட்டை);
  வெளி long இரட்டை __cdecl coshl(long இரட்டை);
  வெளி long இரட்டை __cdecl fabsl (long இரட்டை);
  வெளி long இரட்டை __cdecl acosl(long இரட்டை);
  வெளி long இரட்டை __cdecl asinl(long இரட்டை);
  வெளி long இரட்டை __cdecl atanl(long இரட்டை);
  வெளி long இரட்டை __cdecl atan2l(long இரட்டை,long இரட்டை);
  வெளி long இரட்டை __cdecl sinhl(long இரட்டை);
  வெளி long இரட்டை __cdecl tanhl(long இரட்டை);

  /* 7.12.8.1 The erf functions  */
  வெளி இரட்டை __cdecl erf (இரட்டை);
  வெளி தசம __cdecl erff (தசம);
  /* TODO
  extern long double __cdecl erfl (long double);
  */ 

  /* 7.12.8.2 The erfc functions  */
  வெளி இரட்டை __cdecl erfc (இரட்டை);
  வெளி தசம __cdecl erfcf (தசம);
  /* TODO
  extern long double __cdecl erfcl (long double);
  */ 

  /* 7.12.8.3 The lgamma functions */
  வெளி இரட்டை __cdecl lgamma (இரட்டை);
  வெளி தசம __cdecl lgammaf (தசம);
  வெளி long இரட்டை __cdecl lgammal (long இரட்டை);

  /* 7.12.8.4 The tgamma functions */
  வெளி இரட்டை __cdecl tgamma (இரட்டை);
  வெளி தசம __cdecl tgammaf (தசம);
  வெளி long இரட்டை __cdecl tgammal (long இரட்டை);

  வெளி long இரட்டை __cdecl ceill (long இரட்டை);
  வெளி long இரட்டை __cdecl floorl (long இரட்டை);
  வெளி long இரட்டை __cdecl frexpl(long இரட்டை,முழு *);
  வெளி long இரட்டை __cdecl log10l(long இரட்டை);
  வெளி long இரட்டை __cdecl logl(long இரட்டை);
  வெளி long இரட்டை __cdecl cosl(long இரட்டை);
  வெளி long இரட்டை __cdecl sinl(long இரட்டை);
  வெளி long இரட்டை __cdecl tanl(long இரட்டை);
  வெளி long இரட்டை sqrtl(long இரட்டை);

  /* 7.12.9.3 */
  வெளி இரட்டை __cdecl nearbyint ( இரட்டை);
  வெளி தசம __cdecl nearbyintf (தசம);
  வெளி long இரட்டை __cdecl nearbyintl (long இரட்டை);

  /* 7.12.9.4 */
  /* round, using fpu control word settings */
  வெளி இரட்டை __cdecl rint (இரட்டை);
  வெளி தசம __cdecl rintf (தசம);
  வெளி long இரட்டை __cdecl rintl (long இரட்டை);

  வெளி long __cdecl lrint (இரட்டை);
  வெளி long __cdecl lrintf (தசம);
  வெளி long __cdecl lrintl (long இரட்டை);

  வெளி long long __cdecl llrint (இரட்டை);
  வெளி long long __cdecl llrintf (தசம);
  வெளி long long __cdecl llrintl (long இரட்டை);

  #define FE_TONEAREST	0x0000
  #define FE_DOWNWARD	0x0400
  #define FE_UPWARD	0x0800
  #define FE_TOWARDZERO	0x0c00

  /* 7.12.9.6 */
  /* round away from zero, regardless of fpu control word settings */
  வெளி இரட்டை __cdecl round (இரட்டை);
  வெளி தசம __cdecl roundf (தசம);
  வெளி long இரட்டை __cdecl roundl (long இரட்டை);

  /* 7.12.9.7  */
  வெளி long __cdecl lround (இரட்டை);
  வெளி long __cdecl lroundf (தசம);
  வெளி long __cdecl lroundl (long இரட்டை);

  வெளி long long __cdecl llround (இரட்டை);
  வெளி long long __cdecl llroundf (தசம);
  வெளி long long __cdecl llroundl (long இரட்டை);

  /* 7.12.9.8 */
  /* round towards zero, regardless of fpu control word settings */
  வெளி இரட்டை __cdecl trunc (இரட்டை);
  வெளி தசம __cdecl truncf (தசம);
  வெளி long இரட்டை __cdecl truncl (long இரட்டை);

  வெளி long இரட்டை __cdecl fmodl (long இரட்டை, long இரட்டை);

  /* 7.12.10.2 */ 
  வெளி இரட்டை __cdecl remainder (இரட்டை, இரட்டை);
  வெளி தசம __cdecl remainderf (தசம, தசம);
  வெளி long இரட்டை __cdecl remainderl (long இரட்டை, long இரட்டை);

  /* 7.12.10.3 */
  வெளி இரட்டை __cdecl remquo(இரட்டை, இரட்டை, முழு *);
  வெளி தசம __cdecl remquof(தசம, தசம, முழு *);
  வெளி long இரட்டை __cdecl remquol(long இரட்டை, long இரட்டை, முழு *);

  /* 7.12.11.1 */
  வெளி இரட்டை __cdecl copysign (இரட்டை, இரட்டை); /* in libmoldname.a */
  வெளி தசம __cdecl copysignf (தசம, தசம);
  வெளி long இரட்டை __cdecl copysignl (long இரட்டை, long இரட்டை);

  /* 7.12.11.2 Return a NaN */
  வெளி இரட்டை __cdecl nan(மாறிலி எழுத்து *tagp);
  வெளி தசம __cdecl nanf(மாறிலி எழுத்து *tagp);
  வெளி long இரட்டை __cdecl nanl(மாறிலி எழுத்து *tagp);

#ifndef __STRICT_ANSI__
#define _nan() nan("")
#define _nanf() nanf("")
#define _nanl() nanl("")
#endif

  /* 7.12.11.3 */
  வெளி இரட்டை __cdecl nextafter (இரட்டை, இரட்டை); /* in libmoldname.a */
  வெளி தசம __cdecl nextafterf (தசம, தசம);
  வெளி long இரட்டை __cdecl nextafterl (long இரட்டை, long இரட்டை);

  /* 7.12.11.4 The nexttoward functions: TODO */

  /* 7.12.12.1 */
  /*  x > y ? (x - y) : 0.0  */
  வெளி இரட்டை __cdecl fdim (இரட்டை x, இரட்டை y);
  வெளி தசம __cdecl fdimf (தசம x, தசம y);
  வெளி long இரட்டை __cdecl fdiml (long இரட்டை x, long இரட்டை y);

  /* fmax and fmin.
  NaN arguments are treated as missing data: if one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

  /* 7.12.12.2 */
  வெளி இரட்டை __cdecl fmax  (இரட்டை, இரட்டை);
  வெளி தசம __cdecl fmaxf (தசம, தசம);
  வெளி long இரட்டை __cdecl fmaxl (long இரட்டை, long இரட்டை);

  /* 7.12.12.3 */
  வெளி இரட்டை __cdecl fmin (இரட்டை, இரட்டை);
  வெளி தசம __cdecl fminf (தசம, தசம);
  வெளி long இரட்டை __cdecl fminl (long இரட்டை, long இரட்டை);

  /* 7.12.13.1 */
  /* return x * y + z as a ternary op */ 
  வெளி இரட்டை __cdecl fma (இரட்டை, இரட்டை, இரட்டை);
  வெளி தசம __cdecl fmaf (தசம, தசம, தசம);
  வெளி long இரட்டை __cdecl fmal (long இரட்டை, long இரட்டை, long இரட்டை);


#endif /* __STDC_VERSION__ >= 199901L */
#endif /* __NO_ISOCEXT */

#ifdef __cplusplus
}
#endif
#pragma pack(எடு)

/* 7.12.14 */
/* 
 *  With these functions, comparisons involving quiet NaNs set the FP
 *  condition code to "unordered".  The IEEE floating-point spec
 *  dictates that the result of floating-point comparisons should be
 *  false whenever a NaN is involved, with the exception of the != op, 
 *  which always returns true: yes, (NaN != NaN) is true).
 */

/* Mini libm (inline __fpclassify*, __signbit* and variants) */
#அந்தர்பாவ "tcc/tcc_libm.h"

#endif /* End _MATH_H_ */

