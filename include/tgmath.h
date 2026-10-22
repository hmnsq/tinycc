/*
 * ISO C Standard:  7.22  Type-generic math <tgmath.h>
 */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TGMATH_H
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TGMATH_H

#ਅਨ੍ਤਰ੍ਭਾਵ <math.h>

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __tgmath_real(x, F) \
  _Generic ((x), ਦਸ਼ਮਲਵ: F##f, ਲੰਮਾ ਦੁੱਗਣਾ: F##l, ਮੂਲ: F)(x)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __tgmath_real_2_1(x, y, F) \
  _Generic ((x), ਦਸ਼ਮਲਵ: F##f, ਲੰਮਾ ਦੁੱਗਣਾ: F##l, ਮੂਲ: F)(x, y)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __tgmath_real_2(x, y, F) \
  _Generic ((x)+(y), ਦਸ਼ਮਲਵ: F##f, ਲੰਮਾ ਦੁੱਗਣਾ: F##l, ਮੂਲ: F)(x, y)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __tgmath_real_3_2(x, y, z, F) \
  _Generic ((x)+(y), ਦਸ਼ਮਲਵ: F##f, ਲੰਮਾ ਦੁੱਗਣਾ: F##l, ਮੂਲ: F)(x, y, z)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __tgmath_real_3(x, y, z, F) \
  _Generic ((x)+(y)+(z), ਦਸ਼ਮਲਵ: F##f, ਲੰਮਾ ਦੁੱਗਣਾ: F##l, ਮੂਲ: F)(x, y, z)

/* Functions defined in both <math.h> and <complex.h> (7.22p4) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ acos(z)          __tgmath_real(z, acos)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ asin(z)          __tgmath_real(z, asin)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atan(z)          __tgmath_real(z, atan)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ acosh(z)         __tgmath_real(z, acosh)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ asinh(z)         __tgmath_real(z, asinh)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atanh(z)         __tgmath_real(z, atanh)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੋਜੀਵਾ(z)           __tgmath_real(z, ਕੋਜੀਵਾ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਜੀਵਾ(z)           __tgmath_real(z, ਜੀਵਾ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tan(z)           __tgmath_real(z, tan)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ cosh(z)          __tgmath_real(z, cosh)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ sinh(z)          __tgmath_real(z, sinh)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tanh(z)          __tgmath_real(z, tanh)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਘਾਤਾਂਕ(z)           __tgmath_real(z, ਘਾਤਾਂਕ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲਘੂਗਣਕ(z)           __tgmath_real(z, ਲਘੂਗਣਕ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਘਾਤ(z1,z2)       __tgmath_real_2(z1, z2, ਘਾਤ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਰਗਮੂਲ(z)          __tgmath_real(z, ਵਰਗਮੂਲ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ fabs(z)          __tgmath_real(z, fabs)

/* Functions defined in <math.h> only (7.22p5) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atan2(x,y)       __tgmath_real_2(x, y, atan2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ cbrt(x)          __tgmath_real(x, cbrt)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ceil(x)          __tgmath_real(x, ceil)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ copysign(x,y)    __tgmath_real_2(x, y, copysign)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ erf(x)           __tgmath_real(x, erf)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ erfc(x)          __tgmath_real(x, erfc)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ exp2(x)          __tgmath_real(x, exp2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ expm1(x)         __tgmath_real(x, expm1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ fdim(x,y)        __tgmath_real_2(x, y, fdim)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ floor(x)         __tgmath_real(x, floor)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ fma(x,y,z)       __tgmath_real_3(x, y, z, fma)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ fmax(x,y)        __tgmath_real_2(x, y, fmax)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ fmin(x,y)        __tgmath_real_2(x, y, fmin)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ fmod(x,y)        __tgmath_real_2(x, y, fmod)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ frexp(x,y)       __tgmath_real_2_1(x, y, frexp)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ hypot(x,y)       __tgmath_real_2(x, y, hypot)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ilogb(x)         __tgmath_real(x, ilogb)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ldexp(x,y)       __tgmath_real_2_1(x, y, ldexp)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ lgamma(x)        __tgmath_real(x, lgamma)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ llrint(x)        __tgmath_real(x, llrint)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ llround(x)       __tgmath_real(x, llround)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ log10(x)         __tgmath_real(x, log10)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ log1p(x)         __tgmath_real(x, log1p)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ log2(x)          __tgmath_real(x, log2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ logb(x)          __tgmath_real(x, logb)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ lrint(x)         __tgmath_real(x, lrint)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ lround(x)        __tgmath_real(x, lround)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ nearbyint(x)     __tgmath_real(x, nearbyint)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ nextafter(x,y)   __tgmath_real_2(x, y, nextafter)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ nexttoward(x,y)  __tgmath_real_2(x, y, nexttoward)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ remainder(x,y)   __tgmath_real_2(x, y, remainder)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ remquo(x,y,z)    __tgmath_real_3_2(x, y, z, remquo)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ rint(x)          __tgmath_real(x, rint)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੇੜਾ(x)         __tgmath_real(x, ਗੇੜਾ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ scalbln(x,y)     __tgmath_real_2_1(x, y, scalbln)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ scalbn(x,y)      __tgmath_real_2_1(x, y, scalbn)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tgamma(x)        __tgmath_real(x, tgamma)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ trunc(x)         __tgmath_real(x, trunc)

/* Functions defined in <complex.h> only (7.22p6)
#define carg(z)          __tgmath_cplx_only(z, carg)
#define cimag(z)         __tgmath_cplx_only(z, cimag)
#define conj(z)          __tgmath_cplx_only(z, conj)
#define cproj(z)         __tgmath_cplx_only(z, cproj)
#define creal(z)         __tgmath_cplx_only(z, creal)
*/
#ਜੇ_ਅੰਤ /* __cplusplus */
#ਜੇ_ਅੰਤ /* _TGMATH_H */
