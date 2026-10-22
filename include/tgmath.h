/*
 * ISO C Standard:  7.22  Type-generic math <tgmath.h>
 */

#अगर_अघोषित _TGMATH_H
#घोषणा _TGMATH_H

#समावेश <math.h>

#अगर_अघोषित __cplusplus
#घोषणा __tgmath_real(x, F) \
  _Generic ((x), भग्न: F##f, दीर्घ द्विगुन: F##l, शेष: F)(x)
#घोषणा __tgmath_real_2_1(x, y, F) \
  _Generic ((x), भग्न: F##f, दीर्घ द्विगुन: F##l, शेष: F)(x, y)
#घोषणा __tgmath_real_2(x, y, F) \
  _Generic ((x)+(y), भग्न: F##f, दीर्घ द्विगुन: F##l, शेष: F)(x, y)
#घोषणा __tgmath_real_3_2(x, y, z, F) \
  _Generic ((x)+(y), भग्न: F##f, दीर्घ द्विगुन: F##l, शेष: F)(x, y, z)
#घोषणा __tgmath_real_3(x, y, z, F) \
  _Generic ((x)+(y)+(z), भग्न: F##f, दीर्घ द्विगुन: F##l, शेष: F)(x, y, z)

/* Functions defined in both <math.h> and <complex.h> (7.22p4) */
#घोषणा acos(z)          __tgmath_real(z, acos)
#घोषणा asin(z)          __tgmath_real(z, asin)
#घोषणा atan(z)          __tgmath_real(z, atan)
#घोषणा acosh(z)         __tgmath_real(z, acosh)
#घोषणा asinh(z)         __tgmath_real(z, asinh)
#घोषणा atanh(z)         __tgmath_real(z, atanh)
#घोषणा cos(z)           __tgmath_real(z, cos)
#घोषणा sin(z)           __tgmath_real(z, sin)
#घोषणा tan(z)           __tgmath_real(z, tan)
#घोषणा cosh(z)          __tgmath_real(z, cosh)
#घोषणा sinh(z)          __tgmath_real(z, sinh)
#घोषणा tanh(z)          __tgmath_real(z, tanh)
#घोषणा exp(z)           __tgmath_real(z, exp)
#घोषणा log(z)           __tgmath_real(z, log)
#घोषणा घात(z1,z2)       __tgmath_real_2(z1, z2, घात)
#घोषणा वर्ग_मूल(z)          __tgmath_real(z, वर्ग_मूल)
#घोषणा भ_असल(z)          __tgmath_real(z, भ_असल)

/* Functions defined in <math.h> only (7.22p5) */
#घोषणा atan2(x,y)       __tgmath_real_2(x, y, atan2)
#घोषणा cbrt(x)          __tgmath_real(x, cbrt)
#घोषणा उच्चमान(x)          __tgmath_real(x, उच्चमान)
#घोषणा copysign(x,y)    __tgmath_real_2(x, y, copysign)
#घोषणा erf(x)           __tgmath_real(x, erf)
#घोषणा erfc(x)          __tgmath_real(x, erfc)
#घोषणा exp2(x)          __tgmath_real(x, exp2)
#घोषणा expm1(x)         __tgmath_real(x, expm1)
#घोषणा fdim(x,y)        __tgmath_real_2(x, y, fdim)
#घोषणा न्यूनमान(x)         __tgmath_real(x, न्यूनमान)
#घोषणा fma(x,y,z)       __tgmath_real_3(x, y, z, fma)
#घोषणा fmax(x,y)        __tgmath_real_2(x, y, fmax)
#घोषणा fmin(x,y)        __tgmath_real_2(x, y, fmin)
#घोषणा भ_शेष(x,y)        __tgmath_real_2(x, y, भ_शेष)
#घोषणा frexp(x,y)       __tgmath_real_2_1(x, y, frexp)
#घोषणा hypot(x,y)       __tgmath_real_2(x, y, hypot)
#घोषणा ilogb(x)         __tgmath_real(x, ilogb)
#घोषणा ldexp(x,y)       __tgmath_real_2_1(x, y, ldexp)
#घोषणा lgamma(x)        __tgmath_real(x, lgamma)
#घोषणा llrint(x)        __tgmath_real(x, llrint)
#घोषणा llround(x)       __tgmath_real(x, llround)
#घोषणा log10(x)         __tgmath_real(x, log10)
#घोषणा log1p(x)         __tgmath_real(x, log1p)
#घोषणा log2(x)          __tgmath_real(x, log2)
#घोषणा logb(x)          __tgmath_real(x, logb)
#घोषणा lrint(x)         __tgmath_real(x, lrint)
#घोषणा lround(x)        __tgmath_real(x, lround)
#घोषणा nearbyint(x)     __tgmath_real(x, nearbyint)
#घोषणा nextafter(x,y)   __tgmath_real_2(x, y, nextafter)
#घोषणा nexttoward(x,y)  __tgmath_real_2(x, y, nexttoward)
#घोषणा remainder(x,y)   __tgmath_real_2(x, y, remainder)
#घोषणा remquo(x,y,z)    __tgmath_real_3_2(x, y, z, remquo)
#घोषणा rint(x)          __tgmath_real(x, rint)
#घोषणा round(x)         __tgmath_real(x, round)
#घोषणा scalbln(x,y)     __tgmath_real_2_1(x, y, scalbln)
#घोषणा scalbn(x,y)      __tgmath_real_2_1(x, y, scalbn)
#घोषणा tgamma(x)        __tgmath_real(x, tgamma)
#घोषणा trunc(x)         __tgmath_real(x, trunc)

/* Functions defined in <complex.h> only (7.22p6)
#define carg(z)          __tgmath_cplx_only(z, carg)
#define cimag(z)         __tgmath_cplx_only(z, cimag)
#define conj(z)          __tgmath_cplx_only(z, conj)
#define cproj(z)         __tgmath_cplx_only(z, cproj)
#define creal(z)         __tgmath_cplx_only(z, creal)
*/
#पूर्ण_अगर /* __cplusplus */
#पूर्ण_अगर /* _TGMATH_H */
