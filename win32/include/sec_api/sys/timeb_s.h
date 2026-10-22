/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#جے_بنا_تعریف _TIMEB_H_S
#تعریف_کرو _TIMEB_H_S

#ضمن <sys/timeb.h>

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#إذا defined(MINGW_HAS_SECURE_API)

#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
#تعریف_کرو _ftime_s _ftime32_s
#وإلا
#تعریف_کرو _ftime_s _ftime64_s
#جے_انت

  _CRTIMP errno_t __cdecl _ftime32_s(بنية __timeb32 *ویلا_2);
#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP errno_t __cdecl _ftime64_s(بنية __timeb64 *ویلا_2);
#جے_انت
#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#جے_انت
