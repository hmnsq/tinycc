/*
 * ISO C Standard:  7.22  Type-generic math <tgmath.h>
 */

#اگر_غیر_تعریف_شدہ _TGMATH_H
#تعریف_کرو _TGMATH_H

#شامل <math.h>

#اگر_غیر_تعریف_شدہ __cplusplus
#تعریف_کرو __tgmath_real(x, F) \
  _Generic ((x), اعشاری: F##f, طویل دوہرا: F##l, طےشدہ: F)(x)
#تعریف_کرو __tgmath_real_2_1(x, y, F) \
  _Generic ((x), اعشاری: F##f, طویل دوہرا: F##l, طےشدہ: F)(x, y)
#تعریف_کرو __tgmath_real_2(x, y, F) \
  _Generic ((x)+(y), اعشاری: F##f, طویل دوہرا: F##l, طےشدہ: F)(x, y)
#تعریف_کرو __tgmath_real_3_2(x, y, z, F) \
  _Generic ((x)+(y), اعشاری: F##f, طویل دوہرا: F##l, طےشدہ: F)(x, y, z)
#تعریف_کرو __tgmath_real_3(x, y, z, F) \
  _Generic ((x)+(y)+(z), اعشاری: F##f, طویل دوہرا: F##l, طےشدہ: F)(x, y, z)

/* Functions defined in both <math.h> and <complex.h> (7.22p4) */
#تعریف_کرو acos(z)          __tgmath_real(z, acos)
#تعریف_کرو asin(z)          __tgmath_real(z, asin)
#تعریف_کرو atan(z)          __tgmath_real(z, atan)
#تعریف_کرو acosh(z)         __tgmath_real(z, acosh)
#تعریف_کرو asinh(z)         __tgmath_real(z, asinh)
#تعریف_کرو atanh(z)         __tgmath_real(z, atanh)
#تعریف_کرو جیب_تمام(z)           __tgmath_real(z, جیب_تمام)
#تعریف_کرو جیب(z)           __tgmath_real(z, جیب)
#تعریف_کرو tan(z)           __tgmath_real(z, tan)
#تعریف_کرو cosh(z)          __tgmath_real(z, cosh)
#تعریف_کرو sinh(z)          __tgmath_real(z, sinh)
#تعریف_کرو tanh(z)          __tgmath_real(z, tanh)
#تعریف_کرو قوت_نما(z)           __tgmath_real(z, قوت_نما)
#تعریف_کرو لوگارتھم(z)           __tgmath_real(z, لوگارتھم)
#تعریف_کرو قوت(z1,z2)       __tgmath_real_2(z1, z2, قوت)
#تعریف_کرو جذر(z)          __tgmath_real(z, جذر)
#تعریف_کرو fabs(z)          __tgmath_real(z, fabs)

/* Functions defined in <math.h> only (7.22p5) */
#تعریف_کرو atan2(x,y)       __tgmath_real_2(x, y, atan2)
#تعریف_کرو cbrt(x)          __tgmath_real(x, cbrt)
#تعریف_کرو ceil(x)          __tgmath_real(x, ceil)
#تعریف_کرو copysign(x,y)    __tgmath_real_2(x, y, copysign)
#تعریف_کرو erf(x)           __tgmath_real(x, erf)
#تعریف_کرو erfc(x)          __tgmath_real(x, erfc)
#تعریف_کرو exp2(x)          __tgmath_real(x, exp2)
#تعریف_کرو expm1(x)         __tgmath_real(x, expm1)
#تعریف_کرو fdim(x,y)        __tgmath_real_2(x, y, fdim)
#تعریف_کرو floor(x)         __tgmath_real(x, floor)
#تعریف_کرو fma(x,y,z)       __tgmath_real_3(x, y, z, fma)
#تعریف_کرو fmax(x,y)        __tgmath_real_2(x, y, fmax)
#تعریف_کرو fmin(x,y)        __tgmath_real_2(x, y, fmin)
#تعریف_کرو fmod(x,y)        __tgmath_real_2(x, y, fmod)
#تعریف_کرو frexp(x,y)       __tgmath_real_2_1(x, y, frexp)
#تعریف_کرو hypot(x,y)       __tgmath_real_2(x, y, hypot)
#تعریف_کرو ilogb(x)         __tgmath_real(x, ilogb)
#تعریف_کرو ldexp(x,y)       __tgmath_real_2_1(x, y, ldexp)
#تعریف_کرو lgamma(x)        __tgmath_real(x, lgamma)
#تعریف_کرو llrint(x)        __tgmath_real(x, llrint)
#تعریف_کرو llround(x)       __tgmath_real(x, llround)
#تعریف_کرو log10(x)         __tgmath_real(x, log10)
#تعریف_کرو log1p(x)         __tgmath_real(x, log1p)
#تعریف_کرو log2(x)          __tgmath_real(x, log2)
#تعریف_کرو logb(x)          __tgmath_real(x, logb)
#تعریف_کرو lrint(x)         __tgmath_real(x, lrint)
#تعریف_کرو lround(x)        __tgmath_real(x, lround)
#تعریف_کرو nearbyint(x)     __tgmath_real(x, nearbyint)
#تعریف_کرو nextafter(x,y)   __tgmath_real_2(x, y, nextafter)
#تعریف_کرو nexttoward(x,y)  __tgmath_real_2(x, y, nexttoward)
#تعریف_کرو remainder(x,y)   __tgmath_real_2(x, y, remainder)
#تعریف_کرو remquo(x,y,z)    __tgmath_real_3_2(x, y, z, remquo)
#تعریف_کرو rint(x)          __tgmath_real(x, rint)
#تعریف_کرو باری(x)         __tgmath_real(x, باری)
#تعریف_کرو scalbln(x,y)     __tgmath_real_2_1(x, y, scalbln)
#تعریف_کرو scalbn(x,y)      __tgmath_real_2_1(x, y, scalbn)
#تعریف_کرو tgamma(x)        __tgmath_real(x, tgamma)
#تعریف_کرو trunc(x)         __tgmath_real(x, trunc)

/* Functions defined in <complex.h> only (7.22p6)
#define carg(z)          __tgmath_cplx_only(z, carg)
#define cimag(z)         __tgmath_cplx_only(z, cimag)
#define conj(z)          __tgmath_cplx_only(z, conj)
#define cproj(z)         __tgmath_cplx_only(z, cproj)
#define creal(z)         __tgmath_cplx_only(z, creal)
*/
#اگر_ختم /* __cplusplus */
#اگر_ختم /* _TGMATH_H */
