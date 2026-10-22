/*
 * ISO C Standard:  7.22  Type-generic math <tgmath.h>
 */

#که_نه_تعریف_شوی _TGMATH_H
#تعریف_کړه _TGMATH_H

#ضمن <math.h>

#که_نه_تعریف_شوی __cplusplus
#تعریف_کړه __tgmath_real(x, F) \
  _Generic ((x), عائم: F##f, اوږد مزدوج: F##l, افتراضي: F)(x)
#تعریف_کړه __tgmath_real_2_1(x, y, F) \
  _Generic ((x), عائم: F##f, اوږد مزدوج: F##l, افتراضي: F)(x, y)
#تعریف_کړه __tgmath_real_2(x, y, F) \
  _Generic ((x)+(y), عائم: F##f, اوږد مزدوج: F##l, افتراضي: F)(x, y)
#تعریف_کړه __tgmath_real_3_2(x, y, z, F) \
  _Generic ((x)+(y), عائم: F##f, اوږد مزدوج: F##l, افتراضي: F)(x, y, z)
#تعریف_کړه __tgmath_real_3(x, y, z, F) \
  _Generic ((x)+(y)+(z), عائم: F##f, اوږد مزدوج: F##l, افتراضي: F)(x, y, z)

/* Functions defined in both <math.h> and <complex.h> (7.22p4) */
#تعریف_کړه acos(z)          __tgmath_real(z, acos)
#تعریف_کړه asin(z)          __tgmath_real(z, asin)
#تعریف_کړه atan(z)          __tgmath_real(z, atan)
#تعریف_کړه acosh(z)         __tgmath_real(z, acosh)
#تعریف_کړه asinh(z)         __tgmath_real(z, asinh)
#تعریف_کړه atanh(z)         __tgmath_real(z, atanh)
#تعریف_کړه کوساین(z)           __tgmath_real(z, کوساین)
#تعریف_کړه ساین(z)           __tgmath_real(z, ساین)
#تعریف_کړه tan(z)           __tgmath_real(z, tan)
#تعریف_کړه cosh(z)          __tgmath_real(z, cosh)
#تعریف_کړه sinh(z)          __tgmath_real(z, sinh)
#تعریف_کړه tanh(z)          __tgmath_real(z, tanh)
#تعریف_کړه توانیز_تابع(z)           __tgmath_real(z, توانیز_تابع)
#تعریف_کړه لوګاریتم(z)           __tgmath_real(z, لوګاریتم)
#تعریف_کړه توان(z1,z2)       __tgmath_real_2(z1, z2, توان)
#تعریف_کړه جذر(z)          __tgmath_real(z, جذر)
#تعریف_کړه fabs(z)          __tgmath_real(z, fabs)

/* Functions defined in <math.h> only (7.22p5) */
#تعریف_کړه atan2(x,y)       __tgmath_real_2(x, y, atan2)
#تعریف_کړه cbrt(x)          __tgmath_real(x, cbrt)
#تعریف_کړه ceil(x)          __tgmath_real(x, ceil)
#تعریف_کړه copysign(x,y)    __tgmath_real_2(x, y, copysign)
#تعریف_کړه erf(x)           __tgmath_real(x, erf)
#تعریف_کړه erfc(x)          __tgmath_real(x, erfc)
#تعریف_کړه exp2(x)          __tgmath_real(x, exp2)
#تعریف_کړه expm1(x)         __tgmath_real(x, expm1)
#تعریف_کړه fdim(x,y)        __tgmath_real_2(x, y, fdim)
#تعریف_کړه floor(x)         __tgmath_real(x, floor)
#تعریف_کړه fma(x,y,z)       __tgmath_real_3(x, y, z, fma)
#تعریف_کړه fmax(x,y)        __tgmath_real_2(x, y, fmax)
#تعریف_کړه fmin(x,y)        __tgmath_real_2(x, y, fmin)
#تعریف_کړه fmod(x,y)        __tgmath_real_2(x, y, fmod)
#تعریف_کړه frexp(x,y)       __tgmath_real_2_1(x, y, frexp)
#تعریف_کړه hypot(x,y)       __tgmath_real_2(x, y, hypot)
#تعریف_کړه ilogb(x)         __tgmath_real(x, ilogb)
#تعریف_کړه ldexp(x,y)       __tgmath_real_2_1(x, y, ldexp)
#تعریف_کړه lgamma(x)        __tgmath_real(x, lgamma)
#تعریف_کړه llrint(x)        __tgmath_real(x, llrint)
#تعریف_کړه llround(x)       __tgmath_real(x, llround)
#تعریف_کړه log10(x)         __tgmath_real(x, log10)
#تعریف_کړه log1p(x)         __tgmath_real(x, log1p)
#تعریف_کړه log2(x)          __tgmath_real(x, log2)
#تعریف_کړه logb(x)          __tgmath_real(x, logb)
#تعریف_کړه lrint(x)         __tgmath_real(x, lrint)
#تعریف_کړه lround(x)        __tgmath_real(x, lround)
#تعریف_کړه nearbyint(x)     __tgmath_real(x, nearbyint)
#تعریف_کړه nextafter(x,y)   __tgmath_real_2(x, y, nextafter)
#تعریف_کړه nexttoward(x,y)  __tgmath_real_2(x, y, nexttoward)
#تعریف_کړه remainder(x,y)   __tgmath_real_2(x, y, remainder)
#تعریف_کړه remquo(x,y,z)    __tgmath_real_3_2(x, y, z, remquo)
#تعریف_کړه rint(x)          __tgmath_real(x, rint)
#تعریف_کړه پړاو(x)         __tgmath_real(x, پړاو)
#تعریف_کړه scalbln(x,y)     __tgmath_real_2_1(x, y, scalbln)
#تعریف_کړه scalbn(x,y)      __tgmath_real_2_1(x, y, scalbn)
#تعریف_کړه tgamma(x)        __tgmath_real(x, tgamma)
#تعریف_کړه trunc(x)         __tgmath_real(x, trunc)

/* Functions defined in <complex.h> only (7.22p6)
#define carg(z)          __tgmath_cplx_only(z, carg)
#define cimag(z)         __tgmath_cplx_only(z, cimag)
#define conj(z)          __tgmath_cplx_only(z, conj)
#define cproj(z)         __tgmath_cplx_only(z, cproj)
#define creal(z)         __tgmath_cplx_only(z, creal)
*/
#د_که_پای /* __cplusplus */
#د_که_پای /* _TGMATH_H */
