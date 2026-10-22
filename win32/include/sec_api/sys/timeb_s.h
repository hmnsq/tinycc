/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#اگر_غیر_تعریف_شدہ _TIMEB_H_S
#تعریف_کرو _TIMEB_H_S

#شامل <sys/timeb.h>

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
#تعریف_کرو _ftime_s _ftime32_s
#ورنہ
#تعریف_کرو _ftime_s _ftime64_s
#اگر_ختم

  _CRTIMP errno_t __cdecl _ftime32_s(ساخت __timeb32 *وقت_2);
#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP errno_t __cdecl _ftime64_s(ساخت __timeb64 *وقت_2);
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#اگر_ختم
