/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#جيڪڏهن_وصف_نه_ٿيل _TIMEB_H_S
#وصف_ڪريو _TIMEB_H_S

#ضمن <sys/timeb.h>

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#إذا defined(MINGW_HAS_SECURE_API)

#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
#وصف_ڪريو _ftime_s _ftime32_s
#وإلا
#وصف_ڪريو _ftime_s _ftime64_s
#جيڪڏهن_پورو

  _CRTIMP errno_t __cdecl _ftime32_s(بنية __timeb32 *وقت_2);
#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP errno_t __cdecl _ftime64_s(بنية __timeb64 *وقت_2);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#جيڪڏهن_پورو
