/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _MATH_H_
#ವ್ಯಾಖ್ಯಾನಿಸು _MATH_H_

#ಆದರೆ __GNUC__ >= 3
#ಸೂಚನೆ GCC system_ಶೀರ್ಷಿಕೆ
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ <_mingw.h>

ರಚನೆ exception;

#ಸೂಚನೆ pack(ತಳ್ಳು,_CRT_PACKING)

#ವ್ಯಾಖ್ಯಾನಿಸು _DOMAIN 1
#ವ್ಯಾಖ್ಯಾನಿಸು _SING 2
#ವ್ಯಾಖ್ಯಾನಿಸು ಅತಿಪ್ರವಾಹ 3
#ವ್ಯಾಖ್ಯಾನಿಸು _UNDERFLOW 4
#ವ್ಯಾಖ್ಯಾನಿಸು _TLOSS 5
#ವ್ಯಾಖ್ಯಾನಿಸು _PLOSS 6

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __STRICT_ANSI__
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN _DOMAIN
#ವ್ಯಾಖ್ಯಾನಿಸು SING _SING
#ವ್ಯಾಖ್ಯಾನಿಸು ಅತಿಪ್ರವಾಹ_2 ಅತಿಪ್ರವಾಹ
#ವ್ಯಾಖ್ಯಾನಿಸು UNDERFLOW _UNDERFLOW
#ವ್ಯಾಖ್ಯಾನಿಸು TLOSS _TLOSS
#ವ್ಯಾಖ್ಯಾನಿಸು PLOSS _PLOSS
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __STRICT_ANSI__
#ವ್ಯಾಖ್ಯಾನಿಸು M_E 2.71828182845904523536
#ವ್ಯಾಖ್ಯಾನಿಸು M_LOG2E 1.44269504088896340736
#ವ್ಯಾಖ್ಯಾನಿಸು M_LOG10E 0.434294481903251827651
#ವ್ಯಾಖ್ಯಾನಿಸು M_LN2 0.693147180559945309417
#ವ್ಯಾಖ್ಯಾನಿಸು M_LN10 2.30258509299404568402
#ವ್ಯಾಖ್ಯಾನಿಸು M_PI 3.14159265358979323846
#ವ್ಯಾಖ್ಯಾನಿಸು M_PI_2 1.57079632679489661923
#ವ್ಯಾಖ್ಯಾನಿಸು M_PI_4 0.785398163397448309616
#ವ್ಯಾಖ್ಯಾನಿಸು M_1_PI 0.318309886183790671538
#ವ್ಯಾಖ್ಯಾನಿಸು M_2_PI 0.636619772367581343076
#ವ್ಯಾಖ್ಯಾನಿಸು M_2_SQRTPI 1.12837916709551257390
#ವ್ಯಾಖ್ಯಾನಿಸು M_SQRT2 1.41421356237309504880
#ವ್ಯಾಖ್ಯಾನಿಸು M_SQRT1_2 0.707106781186547524401
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __STRICT_ANSI__
/* See also float.h  */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __MINGW_FPCLASS_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು __MINGW_FPCLASS_DEFINED 1
#ವ್ಯಾಖ್ಯಾನಿಸು	_FPCLASS_SNAN	0x0001	/* Signaling "Not a Number" */
#ವ್ಯಾಖ್ಯಾನಿಸು	_FPCLASS_QNAN	0x0002	/* Quiet "Not a Number" */
#ವ್ಯಾಖ್ಯಾನಿಸು	_FPCLASS_NINF	0x0004	/* Negative Infinity */
#ವ್ಯಾಖ್ಯಾನಿಸು	_FPCLASS_NN	0x0008	/* Negative Normal */
#ವ್ಯಾಖ್ಯಾನಿಸು	_FPCLASS_ND	0x0010	/* Negative Denormal */
#ವ್ಯಾಖ್ಯಾನಿಸು	_FPCLASS_NZ	0x0020	/* Negative Zero */
#ವ್ಯಾಖ್ಯಾನಿಸು	_FPCLASS_PZ	0x0040	/* Positive Zero */
#ವ್ಯಾಖ್ಯಾನಿಸು	_FPCLASS_PD	0x0080	/* Positive Denormal */
#ವ್ಯಾಖ್ಯಾನಿಸು	_FPCLASS_PN	0x0100	/* Positive Normal */
#ವ್ಯಾಖ್ಯಾನಿಸು	_FPCLASS_PINF	0x0200	/* Positive Infinity */
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _EXCEPTION_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _EXCEPTION_DEFINED
  ರಚನೆ _exception {
    ಪೂರ್ಣಾಂಕ type;
    ಅಕ್ಷರ *name;
    ದ್ವಿಗುಣ arg1;
    ದ್ವಿಗುಣ arg2;
    ದ್ವಿಗುಣ retval;
  };
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _COMPLEX_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _COMPLEX_DEFINED
  ರಚನೆ _complex {
    ದ್ವಿಗುಣ x,y;
  };
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು EDOM 33
#ವ್ಯಾಖ್ಯಾನಿಸು ERANGE 34

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _HUGE
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ದ್ವಿಗುಣ *_HUGE;
#ಇಲ್ಲದಿದ್ದರೆ
  ಬಾಹ್ಯ ದ್ವಿಗುಣ *_imp___HUGE;
#ವ್ಯಾಖ್ಯಾನಿಸು _HUGE	(*_imp___HUGE)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು HUGE_VAL _HUGE

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_ABS_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_ABS_DEFINED
  ಪೂರ್ಣಾಂಕ __cdecl ನಿರಪೇಕ್ಷ(ಪೂರ್ಣಾಂಕ _X);
  ದೀರ್ಘ __cdecl labs(ದೀರ್ಘ _X);
#ಆದರೆ_ಅಂತ್ಯ
  ದ್ವಿಗುಣ __cdecl acos(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl asin(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl atan(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl atan2(ದ್ವಿಗುಣ _Y,ದ್ವಿಗುಣ _X);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _SIGN_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _SIGN_DEFINED
  _CRTIMP ದ್ವಿಗುಣ __cdecl _copysign (ದ್ವಿಗುಣ ಸಂಖ್ಯೆ,ದ್ವಿಗುಣ _Sign);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _chgsign (ದ್ವಿಗುಣ _X);
#ಆದರೆ_ಅಂತ್ಯ
  ದ್ವಿಗುಣ __cdecl ಕೋಜ್ಯಾ(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl cosh(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl ಘಾತಾಂಕ(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl expm1(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl fabs(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl fmod(ದ್ವಿಗುಣ _X,ದ್ವಿಗುಣ _Y);
  ದ್ವಿಗುಣ __cdecl ಲಘುಗಣಕ(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl log10(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl ಘಾತ(ದ್ವಿಗುಣ _X,ದ್ವಿಗುಣ _Y);
  ದ್ವಿಗುಣ __cdecl ಜ್ಯಾ(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl sinh(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl tan(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl tanh(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl ವರ್ಗಮೂಲ(ದ್ವಿಗುಣ _X);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_ATOF_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_ATOF_DEFINED
  ದ್ವಿಗುಣ __cdecl atof(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_String);
  ದ್ವಿಗುಣ __cdecl _atof_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_String,_locale_t _Locale);
#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP ದ್ವಿಗುಣ __cdecl _cabs(ರಚನೆ _complex _ComplexA);
  ದ್ವಿಗುಣ __cdecl ceil(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl floor(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl frexp(ದ್ವಿಗುಣ _X,ಪೂರ್ಣಾಂಕ *_Y);
  ದ್ವಿಗುಣ __cdecl _hypot(ದ್ವಿಗುಣ _X,ದ್ವಿಗುಣ _Y);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _j0(ದ್ವಿಗುಣ _X);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _j1(ದ್ವಿಗುಣ _X);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _jn(ಪೂರ್ಣಾಂಕ _X,ದ್ವಿಗುಣ _Y);
  ದ್ವಿಗುಣ __cdecl ldexp(ದ್ವಿಗುಣ _X,ಪೂರ್ಣಾಂಕ _Y);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_MATHERR_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_MATHERR_DEFINED
  ಪೂರ್ಣಾಂಕ __cdecl _matherr(ರಚನೆ _exception *_Except);
#ಆದರೆ_ಅಂತ್ಯ
  ದ್ವಿಗುಣ __cdecl modf(ದ್ವಿಗುಣ _X,ದ್ವಿಗುಣ *_Y);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _y0(ದ್ವಿಗುಣ _X);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _y1(ದ್ವಿಗುಣ _X);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _yn(ಪೂರ್ಣಾಂಕ _X,ದ್ವಿಗುಣ _Y);

#ಆದರೆ(defined(_X86_) && !defined(__x86_64))
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl ಗಣ_SSE2_enable(ಪೂರ್ಣಾಂಕ _Flag);
  /* from libmingwex */
  ದಶಮಾಂಶ __cdecl _hypotf(ದಶಮಾಂಶ _X,ದಶಮಾಂಶ _Y);
#ಆದರೆ_ಅಂತ್ಯ

  ದಶಮಾಂಶ frexpf(ದಶಮಾಂಶ _X,ಪೂರ್ಣಾಂಕ *_Y);
  ದಶಮಾಂಶ __cdecl ldexpf(ದಶಮಾಂಶ _X,ಪೂರ್ಣಾಂಕ _Y);
  ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl ldexpl(ದೀರ್ಘ ದ್ವಿಗುಣ _X,ಪೂರ್ಣಾಂಕ _Y);
  ದಶಮಾಂಶ __cdecl acosf(ದಶಮಾಂಶ _X);
  ದಶಮಾಂಶ __cdecl asinf(ದಶಮಾಂಶ _X);
   ದಶಮಾಂಶ __cdecl atanf(ದಶಮಾಂಶ _X);
   ದಶಮಾಂಶ __cdecl atan2f(ದಶಮಾಂಶ _X,ದಶಮಾಂಶ _Y);
   ದಶಮಾಂಶ __cdecl cosf(ದಶಮಾಂಶ _X);
   ದಶಮಾಂಶ __cdecl sinf(ದಶಮಾಂಶ _X);
   ದಶಮಾಂಶ __cdecl tanf(ದಶಮಾಂಶ _X);
   ದಶಮಾಂಶ __cdecl coshf(ದಶಮಾಂಶ _X);
   ದಶಮಾಂಶ __cdecl sinhf(ದಶಮಾಂಶ _X);
   ದಶಮಾಂಶ __cdecl tanhf(ದಶಮಾಂಶ _X);
   ದಶಮಾಂಶ __cdecl expf(ದಶಮಾಂಶ _X);
   ದಶಮಾಂಶ __cdecl expm1f(ದಶಮಾಂಶ _X);
   ದಶಮಾಂಶ __cdecl logf(ದಶಮಾಂಶ _X);
   ದಶಮಾಂಶ __cdecl log10f(ದಶಮಾಂಶ _X);
   ದಶಮಾಂಶ __cdecl modff(ದಶಮಾಂಶ _X,ದಶಮಾಂಶ *_Y);
   ದಶಮಾಂಶ __cdecl powf(ದಶಮಾಂಶ _X,ದಶಮಾಂಶ _Y);
   ದಶಮಾಂಶ __cdecl sqrtf(ದಶಮಾಂಶ _X);
   ದಶಮಾಂಶ __cdecl ceilf(ದಶಮಾಂಶ _X);
   ದಶಮಾಂಶ __cdecl floorf(ದಶಮಾಂಶ _X);
  ದಶಮಾಂಶ __cdecl fmodf(ದಶಮಾಂಶ _X,ದಶಮಾಂಶ _Y);
   ದಶಮಾಂಶ __cdecl _hypotf(ದಶಮಾಂಶ _X,ದಶಮಾಂಶ _Y);
  ದಶಮಾಂಶ __cdecl fabsf(ದಶಮಾಂಶ _X);
#ಆದರೆ !defined(__ia64__)
   /* from libmingwex */
   ದಶಮಾಂಶ __cdecl _copysignf (ದಶಮಾಂಶ ಸಂಖ್ಯೆ,ದಶಮಾಂಶ _Sign);
   ದಶಮಾಂಶ __cdecl _chgsignf (ದಶಮಾಂಶ _X);
   ದಶಮಾಂಶ __cdecl _logbf(ದಶಮಾಂಶ _X);
   ದಶಮಾಂಶ __cdecl _nextafterf(ದಶಮಾಂಶ _X,ದಶಮಾಂಶ _Y);
   ಪೂರ್ಣಾಂಕ __cdecl _finitef(ದಶಮಾಂಶ _X);
   ಪೂರ್ಣಾಂಕ __cdecl _isnanf(ದಶಮಾಂಶ _X);
   ಪೂರ್ಣಾಂಕ __cdecl _fpclassf(ದಶಮಾಂಶ _X);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
#ವ್ಯಾಖ್ಯಾನಿಸು matherr _matherr

#ವ್ಯಾಖ್ಯಾನಿಸು HUGE	_HUGE
  /*	double __cdecl cabs(struct _complex _X); */
  ದ್ವಿಗುಣ __cdecl hypot(ದ್ವಿಗುಣ _X,ದ್ವಿಗುಣ _Y);
  _CRTIMP ದ್ವಿಗುಣ __cdecl j0(ದ್ವಿಗುಣ _X);
  _CRTIMP ದ್ವಿಗುಣ __cdecl j1(ದ್ವಿಗುಣ _X);
  _CRTIMP ದ್ವಿಗುಣ __cdecl jn(ಪೂರ್ಣಾಂಕ _X,ದ್ವಿಗುಣ _Y);
  _CRTIMP ದ್ವಿಗುಣ __cdecl y0(ದ್ವಿಗುಣ _X);
  _CRTIMP ದ್ವಿಗುಣ __cdecl y1(ದ್ವಿಗುಣ _X);
  _CRTIMP ದ್ವಿಗುಣ __cdecl yn(ಪೂರ್ಣಾಂಕ _X,ದ್ವಿಗುಣ _Y);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __NO_ISOCEXT
#ಆದರೆ (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
  || !defined __STRICT_ANSI__ || defined __GLIBCPP__

#ವ್ಯಾಖ್ಯಾನಿಸು NAN (0.0F/0.0F)
#ವ್ಯಾಖ್ಯಾನಿಸು HUGE_VALF (1.0F/0.0F)
#ವ್ಯಾಖ್ಯಾನಿಸು HUGE_VALL (1.0L/0.0L)
#ವ್ಯಾಖ್ಯಾನಿಸು INFINITY (1.0F/0.0F)


#ವ್ಯಾಖ್ಯಾನಿಸು FP_NAN		0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು FP_NORMAL	0x0400
#ವ್ಯಾಖ್ಯಾನಿಸು FP_INFINITE	(FP_NAN | FP_NORMAL)
#ವ್ಯಾಖ್ಯಾನಿಸು FP_ZERO		0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು FP_SUBNORMAL	(FP_NORMAL | FP_ZERO)
  /* 0x0200 is signbit mask */


  /*
  We can't __CRT_INLINE float or double, because we want to ensure truncation
  to semantic type before classification. 
  (A normal long double value might become subnormal when 
  converted to double, and zero when converted to float.)
  */

  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl __fpclassifyf (ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl __fpclassify (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl __fpclassifyl (ದೀರ್ಘ ದ್ವಿಗುಣ);

/* Implemented at tcc/tcc_libm.h
#define fpclassify(x) (sizeof (x) == sizeof (float) ? __fpclassifyf (x)	  \
  : sizeof (x) == sizeof (double) ? __fpclassify (x) \
  : __fpclassifyl (x))
*/
#ವ್ಯಾಖ್ಯಾನಿಸು fpclassify(x) \
  _Generic(x, ದಶಮಾಂಶ: __fpclassifyf, ದ್ವಿಗುಣ: __fpclassify, ದೀರ್ಘ ದ್ವಿಗುಣ: __fpclassifyl)(x)

  /* 7.12.3.2 */
#ವ್ಯಾಖ್ಯಾನಿಸು isfinite(x) ((fpclassify(x) & FP_NAN) == 0)

  /* 7.12.3.3 */
#ವ್ಯಾಖ್ಯಾನಿಸು isinf(x) (fpclassify(x) == FP_INFINITE)

  /* 7.12.3.4 */
  /* We don't need to worry about truncation here:
  A NaN stays a NaN. */
#ವ್ಯಾಖ್ಯಾನಿಸು isnan(x) (fpclassify(x) == FP_NAN)

  /* 7.12.3.5 */
#ವ್ಯಾಖ್ಯಾನಿಸು isnormal(x) (fpclassify(x) == FP_NORMAL)

  /* 7.12.3.6 The signbit macro */

  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl __signbitf (ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl __signbit (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl __signbitl (ದೀರ್ಘ ದ್ವಿಗುಣ);

/* Implemented at tcc/tcc_libm.h
#define signbit(x) (sizeof (x) == sizeof (float) ? __signbitf (x)	\
  : sizeof (x) == sizeof (double) ? __signbit (x)	\
  : __signbitl (x))
*/
#ವ್ಯಾಖ್ಯಾನಿಸು signbit(x) \
  _Generic(x, ದಶಮಾಂಶ: __signbitf, ದ್ವಿಗುಣ: __signbit, ದೀರ್ಘ ದ್ವಿಗುಣ: __signbitl)(x)

  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl exp2(ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl exp2f(ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl exp2l(ದೀರ್ಘ ದ್ವಿಗುಣ);

#ವ್ಯಾಖ್ಯಾನಿಸು FP_ILOGB0 ((ಪೂರ್ಣಾಂಕ)0x80000000)
#ವ್ಯಾಖ್ಯಾನಿಸು FP_ILOGBNAN ((ಪೂರ್ಣಾಂಕ)0x80000000)
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl ilogb (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl ilogbf (ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl ilogbl (ದೀರ್ಘ ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl log1p(ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl log1pf(ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl log1pl(ದೀರ್ಘ ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl log2 (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl log2f (ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl log2l (ದೀರ್ಘ ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl logb (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl logbf (ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl logbl (ದೀರ್ಘ ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl modfl (ದೀರ್ಘ ದ್ವಿಗುಣ, ದೀರ್ಘ ದ್ವಿಗುಣ*);

  /* 7.12.6.13 */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl scalbn (ದ್ವಿಗುಣ, ಪೂರ್ಣಾಂಕ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl scalbnf (ದಶಮಾಂಶ, ಪೂರ್ಣಾಂಕ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl scalbnl (ದೀರ್ಘ ದ್ವಿಗುಣ, ಪೂರ್ಣಾಂಕ);

  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl scalbln (ದ್ವಿಗುಣ, ದೀರ್ಘ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl scalblnf (ದಶಮಾಂಶ, ದೀರ್ಘ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl scalblnl (ದೀರ್ಘ ದ್ವಿಗುಣ, ದೀರ್ಘ);

  /* 7.12.7.1 */
  /* Implementations adapted from Cephes versions */ 
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl cbrt (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl cbrtf (ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl cbrtl (ದೀರ್ಘ ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl hypot (ದ್ವಿಗುಣ, ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl hypotf (ದಶಮಾಂಶ, ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl hypotl (ದೀರ್ಘ ದ್ವಿಗುಣ, ದೀರ್ಘ ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl powl (ದೀರ್ಘ ದ್ವಿಗುಣ, ದೀರ್ಘ ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl expl(ದೀರ್ಘ ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl expm1l(ದೀರ್ಘ ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl coshl(ದೀರ್ಘ ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl fabsl (ದೀರ್ಘ ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl acosl(ದೀರ್ಘ ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl asinl(ದೀರ್ಘ ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl atanl(ದೀರ್ಘ ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl atan2l(ದೀರ್ಘ ದ್ವಿಗುಣ,ದೀರ್ಘ ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl sinhl(ದೀರ್ಘ ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl tanhl(ದೀರ್ಘ ದ್ವಿಗುಣ);

  /* 7.12.8.1 The erf functions  */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl erf (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl erff (ದಶಮಾಂಶ);
  /* TODO
  extern long double __cdecl erfl (long double);
  */ 

  /* 7.12.8.2 The erfc functions  */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl erfc (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl erfcf (ದಶಮಾಂಶ);
  /* TODO
  extern long double __cdecl erfcl (long double);
  */ 

  /* 7.12.8.3 The lgamma functions */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl lgamma (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl lgammaf (ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl lgammal (ದೀರ್ಘ ದ್ವಿಗುಣ);

  /* 7.12.8.4 The tgamma functions */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl tgamma (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl tgammaf (ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl tgammal (ದೀರ್ಘ ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl ceill (ದೀರ್ಘ ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl floorl (ದೀರ್ಘ ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl frexpl(ದೀರ್ಘ ದ್ವಿಗುಣ,ಪೂರ್ಣಾಂಕ *);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl log10l(ದೀರ್ಘ ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl logl(ದೀರ್ಘ ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl cosl(ದೀರ್ಘ ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl sinl(ದೀರ್ಘ ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl tanl(ದೀರ್ಘ ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ sqrtl(ದೀರ್ಘ ದ್ವಿಗುಣ);

  /* 7.12.9.3 */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl nearbyint ( ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl nearbyintf (ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl nearbyintl (ದೀರ್ಘ ದ್ವಿಗುಣ);

  /* 7.12.9.4 */
  /* round, using fpu control word settings */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl rint (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl rintf (ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl rintl (ದೀರ್ಘ ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ ದೀರ್ಘ __cdecl lrint (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ __cdecl lrintf (ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ __cdecl lrintl (ದೀರ್ಘ ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ ದೀರ್ಘ ದೀರ್ಘ __cdecl llrint (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದೀರ್ಘ __cdecl llrintf (ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದೀರ್ಘ __cdecl llrintl (ದೀರ್ಘ ದ್ವಿಗುಣ);

  #ವ್ಯಾಖ್ಯಾನಿಸು FE_TONEAREST	0x0000
  #ವ್ಯಾಖ್ಯಾನಿಸು FE_DOWNWARD	0x0400
  #ವ್ಯಾಖ್ಯಾನಿಸು FE_UPWARD	0x0800
  #ವ್ಯಾಖ್ಯಾನಿಸು FE_TOWARDZERO	0x0c00

  /* 7.12.9.6 */
  /* round away from zero, regardless of fpu control word settings */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl ಸುತ್ತು (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl roundf (ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl roundl (ದೀರ್ಘ ದ್ವಿಗುಣ);

  /* 7.12.9.7  */
  ಬಾಹ್ಯ ದೀರ್ಘ __cdecl lround (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ __cdecl lroundf (ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ __cdecl lroundl (ದೀರ್ಘ ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ ದೀರ್ಘ ದೀರ್ಘ __cdecl llround (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದೀರ್ಘ __cdecl llroundf (ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದೀರ್ಘ __cdecl llroundl (ದೀರ್ಘ ದ್ವಿಗುಣ);

  /* 7.12.9.8 */
  /* round towards zero, regardless of fpu control word settings */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl trunc (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl truncf (ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl truncl (ದೀರ್ಘ ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl fmodl (ದೀರ್ಘ ದ್ವಿಗುಣ, ದೀರ್ಘ ದ್ವಿಗುಣ);

  /* 7.12.10.2 */ 
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl remainder (ದ್ವಿಗುಣ, ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl remainderf (ದಶಮಾಂಶ, ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl remainderl (ದೀರ್ಘ ದ್ವಿಗುಣ, ದೀರ್ಘ ದ್ವಿಗುಣ);

  /* 7.12.10.3 */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl remquo(ದ್ವಿಗುಣ, ದ್ವಿಗುಣ, ಪೂರ್ಣಾಂಕ *);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl remquof(ದಶಮಾಂಶ, ದಶಮಾಂಶ, ಪೂರ್ಣಾಂಕ *);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl remquol(ದೀರ್ಘ ದ್ವಿಗುಣ, ದೀರ್ಘ ದ್ವಿಗುಣ, ಪೂರ್ಣಾಂಕ *);

  /* 7.12.11.1 */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl copysign (ದ್ವಿಗುಣ, ದ್ವಿಗುಣ); /* in libmoldname.a */
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl copysignf (ದಶಮಾಂಶ, ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl copysignl (ದೀರ್ಘ ದ್ವಿಗುಣ, ದೀರ್ಘ ದ್ವಿಗುಣ);

  /* 7.12.11.2 Return a NaN */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl nan(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *tagp);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl nanf(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *tagp);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl nanl(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *tagp);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __STRICT_ANSI__
#ವ್ಯಾಖ್ಯಾನಿಸು _nan() nan("")
#ವ್ಯಾಖ್ಯಾನಿಸು _nanf() nanf("")
#ವ್ಯಾಖ್ಯಾನಿಸು _nanl() nanl("")
#ಆದರೆ_ಅಂತ್ಯ

  /* 7.12.11.3 */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl nextafter (ದ್ವಿಗುಣ, ದ್ವಿಗುಣ); /* in libmoldname.a */
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl nextafterf (ದಶಮಾಂಶ, ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl nextafterl (ದೀರ್ಘ ದ್ವಿಗುಣ, ದೀರ್ಘ ದ್ವಿಗುಣ);

  /* 7.12.11.4 The nexttoward functions: TODO */

  /* 7.12.12.1 */
  /*  x > y ? (x - y) : 0.0  */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl fdim (ದ್ವಿಗುಣ x, ದ್ವಿಗುಣ y);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl fdimf (ದಶಮಾಂಶ x, ದಶಮಾಂಶ y);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl fdiml (ದೀರ್ಘ ದ್ವಿಗುಣ x, ದೀರ್ಘ ದ್ವಿಗುಣ y);

  /* fmax and fmin.
  NaN arguments are treated as missing data: if one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

  /* 7.12.12.2 */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl fmax  (ದ್ವಿಗುಣ, ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl fmaxf (ದಶಮಾಂಶ, ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl fmaxl (ದೀರ್ಘ ದ್ವಿಗುಣ, ದೀರ್ಘ ದ್ವಿಗುಣ);

  /* 7.12.12.3 */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl fmin (ದ್ವಿಗುಣ, ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl fminf (ದಶಮಾಂಶ, ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl fminl (ದೀರ್ಘ ದ್ವಿಗುಣ, ದೀರ್ಘ ದ್ವಿಗುಣ);

  /* 7.12.13.1 */
  /* return x * y + z as a ternary op */ 
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl fma (ದ್ವಿಗುಣ, ದ್ವಿಗುಣ, ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ದಶಮಾಂಶ __cdecl fmaf (ದಶಮಾಂಶ, ದಶಮಾಂಶ, ದಶಮಾಂಶ);
  ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl fmal (ದೀರ್ಘ ದ್ವಿಗುಣ, ದೀರ್ಘ ದ್ವಿಗುಣ, ದೀರ್ಘ ದ್ವಿಗುಣ);


#ಆದರೆ_ಅಂತ್ಯ /* __STDC_VERSION__ >= 199901L */
#ಆದರೆ_ಅಂತ್ಯ /* __NO_ISOCEXT */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ
#ಸೂಚನೆ pack(ತೆಗೆ)

/* 7.12.14 */
/* 
 *  With these functions, comparisons involving quiet NaNs set the FP
 *  condition code to "unordered".  The IEEE floating-point spec
 *  dictates that the result of floating-point comparisons should be
 *  false whenever a NaN is involved, with the exception of the != op, 
 *  which always returns true: yes, (NaN != NaN) is true).
 */

/* Mini libm (inline __fpclassify*, __signbit* and variants) */
#ಅನ್ತರ್ಭಾವ "tcc/tcc_libm.h"

#ಆದರೆ_ಅಂತ್ಯ /* End _MATH_H_ */

