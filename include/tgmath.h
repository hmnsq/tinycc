/*
 * ISO C Standard:  7.22  Type-generic math <tgmath.h>
 */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TGMATH_H
#ವ್ಯಾಖ್ಯಾನಿಸು _TGMATH_H

#ಅನ್ತರ್ಭಾವ <math.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು __tgmath_real(x, F) \
  _Generic ((x), ದಶಮಾಂಶ: F##f, ದೀರ್ಘ ದ್ವಿಗುಣ: F##l, ಪೂರ್ವನಿಯೋಜಿತ: F)(x)
#ವ್ಯಾಖ್ಯಾನಿಸು __tgmath_real_2_1(x, y, F) \
  _Generic ((x), ದಶಮಾಂಶ: F##f, ದೀರ್ಘ ದ್ವಿಗುಣ: F##l, ಪೂರ್ವನಿಯೋಜಿತ: F)(x, y)
#ವ್ಯಾಖ್ಯಾನಿಸು __tgmath_real_2(x, y, F) \
  _Generic ((x)+(y), ದಶಮಾಂಶ: F##f, ದೀರ್ಘ ದ್ವಿಗುಣ: F##l, ಪೂರ್ವನಿಯೋಜಿತ: F)(x, y)
#ವ್ಯಾಖ್ಯಾನಿಸು __tgmath_real_3_2(x, y, z, F) \
  _Generic ((x)+(y), ದಶಮಾಂಶ: F##f, ದೀರ್ಘ ದ್ವಿಗುಣ: F##l, ಪೂರ್ವನಿಯೋಜಿತ: F)(x, y, z)
#ವ್ಯಾಖ್ಯಾನಿಸು __tgmath_real_3(x, y, z, F) \
  _Generic ((x)+(y)+(z), ದಶಮಾಂಶ: F##f, ದೀರ್ಘ ದ್ವಿಗುಣ: F##l, ಪೂರ್ವನಿಯೋಜಿತ: F)(x, y, z)

/* Functions defined in both <math.h> and <complex.h> (7.22p4) */
#ವ್ಯಾಖ್ಯಾನಿಸು acos(z)          __tgmath_real(z, acos)
#ವ್ಯಾಖ್ಯಾನಿಸು asin(z)          __tgmath_real(z, asin)
#ವ್ಯಾಖ್ಯಾನಿಸು atan(z)          __tgmath_real(z, atan)
#ವ್ಯಾಖ್ಯಾನಿಸು acosh(z)         __tgmath_real(z, acosh)
#ವ್ಯಾಖ್ಯಾನಿಸು asinh(z)         __tgmath_real(z, asinh)
#ವ್ಯಾಖ್ಯಾನಿಸು atanh(z)         __tgmath_real(z, atanh)
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೋಜ್ಯಾ(z)           __tgmath_real(z, ಕೋಜ್ಯಾ)
#ವ್ಯಾಖ್ಯಾನಿಸು ಜ್ಯಾ(z)           __tgmath_real(z, ಜ್ಯಾ)
#ವ್ಯಾಖ್ಯಾನಿಸು tan(z)           __tgmath_real(z, tan)
#ವ್ಯಾಖ್ಯಾನಿಸು cosh(z)          __tgmath_real(z, cosh)
#ವ್ಯಾಖ್ಯಾನಿಸು sinh(z)          __tgmath_real(z, sinh)
#ವ್ಯಾಖ್ಯಾನಿಸು tanh(z)          __tgmath_real(z, tanh)
#ವ್ಯಾಖ್ಯಾನಿಸು ಘಾತಾಂಕ(z)           __tgmath_real(z, ಘಾತಾಂಕ)
#ವ್ಯಾಖ್ಯಾನಿಸು ಲಘುಗಣಕ(z)           __tgmath_real(z, ಲಘುಗಣಕ)
#ವ್ಯಾಖ್ಯಾನಿಸು ಘಾತ(z1,z2)       __tgmath_real_2(z1, z2, ಘಾತ)
#ವ್ಯಾಖ್ಯಾನಿಸು ವರ್ಗಮೂಲ(z)          __tgmath_real(z, ವರ್ಗಮೂಲ)
#ವ್ಯಾಖ್ಯಾನಿಸು fabs(z)          __tgmath_real(z, fabs)

/* Functions defined in <math.h> only (7.22p5) */
#ವ್ಯಾಖ್ಯಾನಿಸು atan2(x,y)       __tgmath_real_2(x, y, atan2)
#ವ್ಯಾಖ್ಯಾನಿಸು cbrt(x)          __tgmath_real(x, cbrt)
#ವ್ಯಾಖ್ಯಾನಿಸು ceil(x)          __tgmath_real(x, ceil)
#ವ್ಯಾಖ್ಯಾನಿಸು copysign(x,y)    __tgmath_real_2(x, y, copysign)
#ವ್ಯಾಖ್ಯಾನಿಸು erf(x)           __tgmath_real(x, erf)
#ವ್ಯಾಖ್ಯಾನಿಸು erfc(x)          __tgmath_real(x, erfc)
#ವ್ಯಾಖ್ಯಾನಿಸು exp2(x)          __tgmath_real(x, exp2)
#ವ್ಯಾಖ್ಯಾನಿಸು expm1(x)         __tgmath_real(x, expm1)
#ವ್ಯಾಖ್ಯಾನಿಸು fdim(x,y)        __tgmath_real_2(x, y, fdim)
#ವ್ಯಾಖ್ಯಾನಿಸು floor(x)         __tgmath_real(x, floor)
#ವ್ಯಾಖ್ಯಾನಿಸು fma(x,y,z)       __tgmath_real_3(x, y, z, fma)
#ವ್ಯಾಖ್ಯಾನಿಸು fmax(x,y)        __tgmath_real_2(x, y, fmax)
#ವ್ಯಾಖ್ಯಾನಿಸು fmin(x,y)        __tgmath_real_2(x, y, fmin)
#ವ್ಯಾಖ್ಯಾನಿಸು fmod(x,y)        __tgmath_real_2(x, y, fmod)
#ವ್ಯಾಖ್ಯಾನಿಸು frexp(x,y)       __tgmath_real_2_1(x, y, frexp)
#ವ್ಯಾಖ್ಯಾನಿಸು hypot(x,y)       __tgmath_real_2(x, y, hypot)
#ವ್ಯಾಖ್ಯಾನಿಸು ilogb(x)         __tgmath_real(x, ilogb)
#ವ್ಯಾಖ್ಯಾನಿಸು ldexp(x,y)       __tgmath_real_2_1(x, y, ldexp)
#ವ್ಯಾಖ್ಯಾನಿಸು lgamma(x)        __tgmath_real(x, lgamma)
#ವ್ಯಾಖ್ಯಾನಿಸು llrint(x)        __tgmath_real(x, llrint)
#ವ್ಯಾಖ್ಯಾನಿಸು llround(x)       __tgmath_real(x, llround)
#ವ್ಯಾಖ್ಯಾನಿಸು log10(x)         __tgmath_real(x, log10)
#ವ್ಯಾಖ್ಯಾನಿಸು log1p(x)         __tgmath_real(x, log1p)
#ವ್ಯಾಖ್ಯಾನಿಸು log2(x)          __tgmath_real(x, log2)
#ವ್ಯಾಖ್ಯಾನಿಸು logb(x)          __tgmath_real(x, logb)
#ವ್ಯಾಖ್ಯಾನಿಸು lrint(x)         __tgmath_real(x, lrint)
#ವ್ಯಾಖ್ಯಾನಿಸು lround(x)        __tgmath_real(x, lround)
#ವ್ಯಾಖ್ಯಾನಿಸು nearbyint(x)     __tgmath_real(x, nearbyint)
#ವ್ಯಾಖ್ಯಾನಿಸು nextafter(x,y)   __tgmath_real_2(x, y, nextafter)
#ವ್ಯಾಖ್ಯಾನಿಸು nexttoward(x,y)  __tgmath_real_2(x, y, nexttoward)
#ವ್ಯಾಖ್ಯಾನಿಸು remainder(x,y)   __tgmath_real_2(x, y, remainder)
#ವ್ಯಾಖ್ಯಾನಿಸು remquo(x,y,z)    __tgmath_real_3_2(x, y, z, remquo)
#ವ್ಯಾಖ್ಯಾನಿಸು rint(x)          __tgmath_real(x, rint)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸುತ್ತು(x)         __tgmath_real(x, ಸುತ್ತು)
#ವ್ಯಾಖ್ಯಾನಿಸು scalbln(x,y)     __tgmath_real_2_1(x, y, scalbln)
#ವ್ಯಾಖ್ಯಾನಿಸು scalbn(x,y)      __tgmath_real_2_1(x, y, scalbn)
#ವ್ಯಾಖ್ಯಾನಿಸು tgamma(x)        __tgmath_real(x, tgamma)
#ವ್ಯಾಖ್ಯಾನಿಸು trunc(x)         __tgmath_real(x, trunc)

/* Functions defined in <complex.h> only (7.22p6)
#define carg(z)          __tgmath_cplx_only(z, carg)
#define cimag(z)         __tgmath_cplx_only(z, cimag)
#define conj(z)          __tgmath_cplx_only(z, conj)
#define cproj(z)         __tgmath_cplx_only(z, cproj)
#define creal(z)         __tgmath_cplx_only(z, creal)
*/
#ಆದರೆ_ಅಂತ್ಯ /* __cplusplus */
#ಆದರೆ_ಅಂತ್ಯ /* _TGMATH_H */
