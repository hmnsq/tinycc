/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#که_نه_تعریف_شوی _TIMEB_H_S
#تعریف_کړه _TIMEB_H_S

#ضمن <sys/timeb.h>

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#إذا defined(MINGW_HAS_SECURE_API)

#که_تعریف_شوی USE_32_بټ_وخت_T
#تعریف_کړه _ftime_s _ftime32_s
#وإلا
#تعریف_کړه _ftime_s _ftime64_s
#د_که_پای

  _CRTIMP errno_t __cdecl _ftime32_s(بنية __timeb32 *وخت_2);
#إذا INTEGRAL_MAX_بټونه >= 64
  _CRTIMP errno_t __cdecl _ftime64_s(بنية __timeb64 *وخت_2);
#د_که_پای
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#د_که_پای
