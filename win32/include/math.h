/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _MATH_H_
#define _MATH_H_

#जर __GNUC__ >= 3
#pragma GCC system_header
#endif

#अन्तर्भाव <_mingw.h>

संरचना exception;

#pragma pack(ढकला,_CRT_PACKING)

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
बाह्य "C" {
#endif

#ifndef _EXCEPTION_DEFINED
#define _EXCEPTION_DEFINED
  संरचना _exception {
    पूर्णांक type;
    अक्षर *name;
    द्विगुण arg1;
    द्विगुण arg2;
    द्विगुण retval;
  };
#endif

#ifndef _COMPLEX_DEFINED
#define _COMPLEX_DEFINED
  संरचना _complex {
    द्विगुण x,y;
  };
#endif

#define गलत_तर्क 33
#define दुस्फल 34

#ifndef _HUGE
#ifdef _MSVCRT_
  बाह्य द्विगुण *_HUGE;
#अन्यथा
  बाह्य द्विगुण *_imp___HUGE;
#define _HUGE	(*_imp___HUGE)
#endif
#endif

#define विशाल_मान _HUGE

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  पूर्णांक __cdecl असल(पूर्णांक _X);
  दीर्घ __cdecl द_असल(दीर्घ _X);
#endif
  द्विगुण __cdecl acos(द्विगुण _X);
  द्विगुण __cdecl asin(द्विगुण _X);
  द्विगुण __cdecl atan(द्विगुण _X);
  द्विगुण __cdecl atan2(द्विगुण _Y,द्विगुण _X);
#ifndef _SIGN_DEFINED
#define _SIGN_DEFINED
  _CRTIMP द्विगुण __cdecl _copysign (द्विगुण संख्या,द्विगुण _Sign);
  _CRTIMP द्विगुण __cdecl _chgsign (द्विगुण _X);
#endif
  द्विगुण __cdecl cos(द्विगुण _X);
  द्विगुण __cdecl cosh(द्विगुण _X);
  द्विगुण __cdecl exp(द्विगुण _X);
  द्विगुण __cdecl expm1(द्विगुण _X);
  द्विगुण __cdecl भ_असल(द्विगुण _X);
  द्विगुण __cdecl भ_शेष(द्विगुण _X,द्विगुण _Y);
  द्विगुण __cdecl log(द्विगुण _X);
  द्विगुण __cdecl log10(द्विगुण _X);
  द्विगुण __cdecl घात(द्विगुण _X,द्विगुण _Y);
  द्विगुण __cdecl sin(द्विगुण _X);
  द्विगुण __cdecl sinh(द्विगुण _X);
  द्विगुण __cdecl tan(द्विगुण _X);
  द्विगुण __cdecl tanh(द्विगुण _X);
  द्विगुण __cdecl वर्ग_मूल(द्विगुण _X);
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  द्विगुण __cdecl म_से_भ(स्थिरांक अक्षर *_String);
  द्विगुण __cdecl _atof_l(स्थिरांक अक्षर *_String,_locale_t _Locale);
#endif

  _CRTIMP द्विगुण __cdecl _cabs(संरचना _complex _ComplexA);
  द्विगुण __cdecl उच्चमान(द्विगुण _X);
  द्विगुण __cdecl न्यूनमान(द्विगुण _X);
  द्विगुण __cdecl frexp(द्विगुण _X,पूर्णांक *_Y);
  द्विगुण __cdecl _hypot(द्विगुण _X,द्विगुण _Y);
  _CRTIMP द्विगुण __cdecl _j0(द्विगुण _X);
  _CRTIMP द्विगुण __cdecl _j1(द्विगुण _X);
  _CRTIMP द्विगुण __cdecl _jn(पूर्णांक _X,द्विगुण _Y);
  द्विगुण __cdecl ldexp(द्विगुण _X,पूर्णांक _Y);
#ifndef _CRT_MATHERR_DEFINED
#define _CRT_MATHERR_DEFINED
  पूर्णांक __cdecl _matherr(संरचना _exception *_Except);
#endif
  द्विगुण __cdecl modf(द्विगुण _X,द्विगुण *_Y);
  _CRTIMP द्विगुण __cdecl _y0(द्विगुण _X);
  _CRTIMP द्विगुण __cdecl _y1(द्विगुण _X);
  _CRTIMP द्विगुण __cdecl _yn(पूर्णांक _X,द्विगुण _Y);

#जर(defined(_X86_) && !defined(__x86_64))
  _CRTIMP पूर्णांक __cdecl _set_SSE2_enable(पूर्णांक _Flag);
  /* from libmingwex */
  दशांश __cdecl _hypotf(दशांश _X,दशांश _Y);
#endif

  दशांश frexpf(दशांश _X,पूर्णांक *_Y);
  दशांश __cdecl ldexpf(दशांश _X,पूर्णांक _Y);
  दीर्घ द्विगुण __cdecl ldexpl(दीर्घ द्विगुण _X,पूर्णांक _Y);
  दशांश __cdecl acosf(दशांश _X);
  दशांश __cdecl asinf(दशांश _X);
   दशांश __cdecl atanf(दशांश _X);
   दशांश __cdecl atan2f(दशांश _X,दशांश _Y);
   दशांश __cdecl cosf(दशांश _X);
   दशांश __cdecl sinf(दशांश _X);
   दशांश __cdecl tanf(दशांश _X);
   दशांश __cdecl coshf(दशांश _X);
   दशांश __cdecl sinhf(दशांश _X);
   दशांश __cdecl tanhf(दशांश _X);
   दशांश __cdecl expf(दशांश _X);
   दशांश __cdecl expm1f(दशांश _X);
   दशांश __cdecl logf(दशांश _X);
   दशांश __cdecl log10f(दशांश _X);
   दशांश __cdecl modff(दशांश _X,दशांश *_Y);
   दशांश __cdecl powf(दशांश _X,दशांश _Y);
   दशांश __cdecl sqrtf(दशांश _X);
   दशांश __cdecl ceilf(दशांश _X);
   दशांश __cdecl floorf(दशांश _X);
  दशांश __cdecl fmodf(दशांश _X,दशांश _Y);
   दशांश __cdecl _hypotf(दशांश _X,दशांश _Y);
  दशांश __cdecl fabsf(दशांश _X);
#जर !defined(__ia64__)
   /* from libmingwex */
   दशांश __cdecl _copysignf (दशांश संख्या,दशांश _Sign);
   दशांश __cdecl _chgsignf (दशांश _X);
   दशांश __cdecl _logbf(दशांश _X);
   दशांश __cdecl _nextafterf(दशांश _X,दशांश _Y);
   पूर्णांक __cdecl _finitef(दशांश _X);
   पूर्णांक __cdecl _isnanf(दशांश _X);
   पूर्णांक __cdecl _fpclassf(दशांश _X);
#endif

#ifndef	NO_OLDNAMES
#define matherr _matherr

#define HUGE	_HUGE
  /*	double __cdecl cabs(struct _complex _X); */
  द्विगुण __cdecl hypot(द्विगुण _X,द्विगुण _Y);
  _CRTIMP द्विगुण __cdecl j0(द्विगुण _X);
  _CRTIMP द्विगुण __cdecl j1(द्विगुण _X);
  _CRTIMP द्विगुण __cdecl jn(पूर्णांक _X,द्विगुण _Y);
  _CRTIMP द्विगुण __cdecl y0(द्विगुण _X);
  _CRTIMP द्विगुण __cdecl y1(द्विगुण _X);
  _CRTIMP द्विगुण __cdecl yn(पूर्णांक _X,द्विगुण _Y);
#endif

#ifndef __NO_ISOCEXT
#जर (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
  || !defined __STRICT_ANSI__ || defined __GLIBCPP__

#define न_अंक (0.0F/0.0F)
#define HUGE_VALF (1.0F/0.0F)
#define HUGE_VALL (1.0L/0.0L)
#define अनन्त (1.0F/0.0F)


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

  बाह्य पूर्णांक __cdecl __fpclassifyf (दशांश);
  बाह्य पूर्णांक __cdecl __fpclassify (द्विगुण);
  बाह्य पूर्णांक __cdecl __fpclassifyl (दीर्घ द्विगुण);

/* Implemented at tcc/tcc_libm.h
#define fpclassify(x) (sizeof (x) == sizeof (float) ? __fpclassifyf (x)	  \
  : sizeof (x) == sizeof (double) ? __fpclassify (x) \
  : __fpclassifyl (x))
*/
#define fpclassify(x) \
  _Generic(x, दशांश: __fpclassifyf, द्विगुण: __fpclassify, दीर्घ द्विगुण: __fpclassifyl)(x)

  /* 7.12.3.2 */
#define है_सीमित(x) ((fpclassify(x) & FP_NAN) == 0)

  /* 7.12.3.3 */
#define isinf(x) (fpclassify(x) == FP_INFINITE)

  /* 7.12.3.4 */
  /* We don't need to worry about truncation here:
  A NaN stays a NaN. */
#define isnan(x) (fpclassify(x) == FP_NAN)

  /* 7.12.3.5 */
#define isnormal(x) (fpclassify(x) == FP_NORMAL)

  /* 7.12.3.6 The signbit macro */

  बाह्य पूर्णांक __cdecl __signbitf (दशांश);
  बाह्य पूर्णांक __cdecl __signbit (द्विगुण);
  बाह्य पूर्णांक __cdecl __signbitl (दीर्घ द्विगुण);

/* Implemented at tcc/tcc_libm.h
#define signbit(x) (sizeof (x) == sizeof (float) ? __signbitf (x)	\
  : sizeof (x) == sizeof (double) ? __signbit (x)	\
  : __signbitl (x))
*/
#define signbit(x) \
  _Generic(x, दशांश: __signbitf, द्विगुण: __signbit, दीर्घ द्विगुण: __signbitl)(x)

  बाह्य द्विगुण __cdecl exp2(द्विगुण);
  बाह्य दशांश __cdecl exp2f(दशांश);
  बाह्य दीर्घ द्विगुण __cdecl exp2l(दीर्घ द्विगुण);

#define FP_ILOGB0 ((पूर्णांक)0x80000000)
#define FP_ILOGBNAN ((पूर्णांक)0x80000000)
  बाह्य पूर्णांक __cdecl ilogb (द्विगुण);
  बाह्य पूर्णांक __cdecl ilogbf (दशांश);
  बाह्य पूर्णांक __cdecl ilogbl (दीर्घ द्विगुण);

  बाह्य द्विगुण __cdecl log1p(द्विगुण);
  बाह्य दशांश __cdecl log1pf(दशांश);
  बाह्य दीर्घ द्विगुण __cdecl log1pl(दीर्घ द्विगुण);

  बाह्य द्विगुण __cdecl log2 (द्विगुण);
  बाह्य दशांश __cdecl log2f (दशांश);
  बाह्य दीर्घ द्विगुण __cdecl log2l (दीर्घ द्विगुण);

  बाह्य द्विगुण __cdecl logb (द्विगुण);
  बाह्य दशांश __cdecl logbf (दशांश);
  बाह्य दीर्घ द्विगुण __cdecl logbl (दीर्घ द्विगुण);

  बाह्य दीर्घ द्विगुण __cdecl modfl (दीर्घ द्विगुण, दीर्घ द्विगुण*);

  /* 7.12.6.13 */
  बाह्य द्विगुण __cdecl scalbn (द्विगुण, पूर्णांक);
  बाह्य दशांश __cdecl scalbnf (दशांश, पूर्णांक);
  बाह्य दीर्घ द्विगुण __cdecl scalbnl (दीर्घ द्विगुण, पूर्णांक);

  बाह्य द्विगुण __cdecl scalbln (द्विगुण, दीर्घ);
  बाह्य दशांश __cdecl scalblnf (दशांश, दीर्घ);
  बाह्य दीर्घ द्विगुण __cdecl scalblnl (दीर्घ द्विगुण, दीर्घ);

  /* 7.12.7.1 */
  /* Implementations adapted from Cephes versions */ 
  बाह्य द्विगुण __cdecl cbrt (द्विगुण);
  बाह्य दशांश __cdecl cbrtf (दशांश);
  बाह्य दीर्घ द्विगुण __cdecl cbrtl (दीर्घ द्विगुण);

  बाह्य द्विगुण __cdecl hypot (द्विगुण, द्विगुण);
  बाह्य दशांश __cdecl hypotf (दशांश, दशांश);
  बाह्य दीर्घ द्विगुण __cdecl hypotl (दीर्घ द्विगुण, दीर्घ द्विगुण);

  बाह्य दीर्घ द्विगुण __cdecl powl (दीर्घ द्विगुण, दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl expl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl expm1l(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl coshl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl fabsl (दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl acosl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl asinl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl atanl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl atan2l(दीर्घ द्विगुण,दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl sinhl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl tanhl(दीर्घ द्विगुण);

  /* 7.12.8.1 The erf functions  */
  बाह्य द्विगुण __cdecl erf (द्विगुण);
  बाह्य दशांश __cdecl erff (दशांश);
  /* TODO
  extern long double __cdecl erfl (long double);
  */ 

  /* 7.12.8.2 The erfc functions  */
  बाह्य द्विगुण __cdecl erfc (द्विगुण);
  बाह्य दशांश __cdecl erfcf (दशांश);
  /* TODO
  extern long double __cdecl erfcl (long double);
  */ 

  /* 7.12.8.3 The lgamma functions */
  बाह्य द्विगुण __cdecl lgamma (द्विगुण);
  बाह्य दशांश __cdecl lgammaf (दशांश);
  बाह्य दीर्घ द्विगुण __cdecl lgammal (दीर्घ द्विगुण);

  /* 7.12.8.4 The tgamma functions */
  बाह्य द्विगुण __cdecl tgamma (द्विगुण);
  बाह्य दशांश __cdecl tgammaf (दशांश);
  बाह्य दीर्घ द्विगुण __cdecl tgammal (दीर्घ द्विगुण);

  बाह्य दीर्घ द्विगुण __cdecl ceill (दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl floorl (दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl frexpl(दीर्घ द्विगुण,पूर्णांक *);
  बाह्य दीर्घ द्विगुण __cdecl log10l(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl logl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl cosl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl sinl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl tanl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण sqrtl(दीर्घ द्विगुण);

  /* 7.12.9.3 */
  बाह्य द्विगुण __cdecl nearbyint ( द्विगुण);
  बाह्य दशांश __cdecl nearbyintf (दशांश);
  बाह्य दीर्घ द्विगुण __cdecl nearbyintl (दीर्घ द्विगुण);

  /* 7.12.9.4 */
  /* round, using fpu control word settings */
  बाह्य द्विगुण __cdecl rint (द्विगुण);
  बाह्य दशांश __cdecl rintf (दशांश);
  बाह्य दीर्घ द्विगुण __cdecl rintl (दीर्घ द्विगुण);

  बाह्य दीर्घ __cdecl lrint (द्विगुण);
  बाह्य दीर्घ __cdecl lrintf (दशांश);
  बाह्य दीर्घ __cdecl lrintl (दीर्घ द्विगुण);

  बाह्य दीर्घ दीर्घ __cdecl llrint (द्विगुण);
  बाह्य दीर्घ दीर्घ __cdecl llrintf (दशांश);
  बाह्य दीर्घ दीर्घ __cdecl llrintl (दीर्घ द्विगुण);

  #define FE_TONEAREST	0x0000
  #define FE_DOWNWARD	0x0400
  #define FE_UPWARD	0x0800
  #define FE_TOWARDZERO	0x0c00

  /* 7.12.9.6 */
  /* round away from zero, regardless of fpu control word settings */
  बाह्य द्विगुण __cdecl round (द्विगुण);
  बाह्य दशांश __cdecl roundf (दशांश);
  बाह्य दीर्घ द्विगुण __cdecl roundl (दीर्घ द्विगुण);

  /* 7.12.9.7  */
  बाह्य दीर्घ __cdecl lround (द्विगुण);
  बाह्य दीर्घ __cdecl lroundf (दशांश);
  बाह्य दीर्घ __cdecl lroundl (दीर्घ द्विगुण);

  बाह्य दीर्घ दीर्घ __cdecl llround (द्विगुण);
  बाह्य दीर्घ दीर्घ __cdecl llroundf (दशांश);
  बाह्य दीर्घ दीर्घ __cdecl llroundl (दीर्घ द्विगुण);

  /* 7.12.9.8 */
  /* round towards zero, regardless of fpu control word settings */
  बाह्य द्विगुण __cdecl trunc (द्विगुण);
  बाह्य दशांश __cdecl truncf (दशांश);
  बाह्य दीर्घ द्विगुण __cdecl truncl (दीर्घ द्विगुण);

  बाह्य दीर्घ द्विगुण __cdecl fmodl (दीर्घ द्विगुण, दीर्घ द्विगुण);

  /* 7.12.10.2 */ 
  बाह्य द्विगुण __cdecl remainder (द्विगुण, द्विगुण);
  बाह्य दशांश __cdecl remainderf (दशांश, दशांश);
  बाह्य दीर्घ द्विगुण __cdecl remainderl (दीर्घ द्विगुण, दीर्घ द्विगुण);

  /* 7.12.10.3 */
  बाह्य द्विगुण __cdecl remquo(द्विगुण, द्विगुण, पूर्णांक *);
  बाह्य दशांश __cdecl remquof(दशांश, दशांश, पूर्णांक *);
  बाह्य दीर्घ द्विगुण __cdecl remquol(दीर्घ द्विगुण, दीर्घ द्विगुण, पूर्णांक *);

  /* 7.12.11.1 */
  बाह्य द्विगुण __cdecl copysign (द्विगुण, द्विगुण); /* in libmoldname.a */
  बाह्य दशांश __cdecl copysignf (दशांश, दशांश);
  बाह्य दीर्घ द्विगुण __cdecl copysignl (दीर्घ द्विगुण, दीर्घ द्विगुण);

  /* 7.12.11.2 Return a NaN */
  बाह्य द्विगुण __cdecl nan(स्थिरांक अक्षर *tagp);
  बाह्य दशांश __cdecl nanf(स्थिरांक अक्षर *tagp);
  बाह्य दीर्घ द्विगुण __cdecl nanl(स्थिरांक अक्षर *tagp);

#ifndef __STRICT_ANSI__
#define _nan() nan("")
#define _nanf() nanf("")
#define _nanl() nanl("")
#endif

  /* 7.12.11.3 */
  बाह्य द्विगुण __cdecl nextafter (द्विगुण, द्विगुण); /* in libmoldname.a */
  बाह्य दशांश __cdecl nextafterf (दशांश, दशांश);
  बाह्य दीर्घ द्विगुण __cdecl nextafterl (दीर्घ द्विगुण, दीर्घ द्विगुण);

  /* 7.12.11.4 The nexttoward functions: TODO */

  /* 7.12.12.1 */
  /*  x > y ? (x - y) : 0.0  */
  बाह्य द्विगुण __cdecl fdim (द्विगुण x, द्विगुण y);
  बाह्य दशांश __cdecl fdimf (दशांश x, दशांश y);
  बाह्य दीर्घ द्विगुण __cdecl fdiml (दीर्घ द्विगुण x, दीर्घ द्विगुण y);

  /* fmax and fmin.
  NaN arguments are treated as missing data: if one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

  /* 7.12.12.2 */
  बाह्य द्विगुण __cdecl fmax  (द्विगुण, द्विगुण);
  बाह्य दशांश __cdecl fmaxf (दशांश, दशांश);
  बाह्य दीर्घ द्विगुण __cdecl fmaxl (दीर्घ द्विगुण, दीर्घ द्विगुण);

  /* 7.12.12.3 */
  बाह्य द्विगुण __cdecl fmin (द्विगुण, द्विगुण);
  बाह्य दशांश __cdecl fminf (दशांश, दशांश);
  बाह्य दीर्घ द्विगुण __cdecl fminl (दीर्घ द्विगुण, दीर्घ द्विगुण);

  /* 7.12.13.1 */
  /* return x * y + z as a ternary op */ 
  बाह्य द्विगुण __cdecl fma (द्विगुण, द्विगुण, द्विगुण);
  बाह्य दशांश __cdecl fmaf (दशांश, दशांश, दशांश);
  बाह्य दीर्घ द्विगुण __cdecl fmal (दीर्घ द्विगुण, दीर्घ द्विगुण, दीर्घ द्विगुण);


#endif /* __STDC_VERSION__ >= 199901L */
#endif /* __NO_ISOCEXT */

#ifdef __cplusplus
}
#endif
#pragma pack(काढा)

/* 7.12.14 */
/* 
 *  With these functions, comparisons involving quiet NaNs set the FP
 *  condition code to "unordered".  The IEEE floating-point spec
 *  dictates that the result of floating-point comparisons should be
 *  false whenever a NaN is involved, with the exception of the != op, 
 *  which always returns true: yes, (NaN != NaN) is true).
 */

/* Mini libm (inline __fpclassify*, __signbit* and variants) */
#अन्तर्भाव "tcc/tcc_libm.h"

#endif /* End _MATH_H_ */

