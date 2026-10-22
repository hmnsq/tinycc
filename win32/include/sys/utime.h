/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_UTIME
#define _INC_UTIME

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#شامل <_mingw.h>

#pragma pack(افزودن,_CRT_PACKING)

#ifdef __cplusplus
بیرونی "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
  تعریفنوع unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#وگرنه
#اگر _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  تعریفنوع long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#اگر _INTEGRAL_MAX_BITS >= 64
  تعریفنوع __int64 __time64_t;
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  تعریفنوع __time32_t time_t;
#وگرنه
  تعریفنوع __time64_t time_t;
#endif
#endif

#ifndef _UTIMBUF_DEFINED
#define _UTIMBUF_DEFINED

  ساختار _utimbuf {
    time_t actime;
    time_t modtime;
  };

  ساختار __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#اگر _INTEGRAL_MAX_BITS >= 64
  ساختار __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#endif

#ifndef	NO_OLDNAMES
  ساختار utimbuf {
    time_t actime;
    time_t modtime;
  };

  ساختار utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#endif
#endif

  _CRTIMP صحیح __cdecl _utime32(ثابت نویسه *_Filename,ساختار __utimbuf32 *_Time);
  _CRTIMP صحیح __cdecl _futime32(صحیح _FileDes,ساختار __utimbuf32 *_Time);
  _CRTIMP صحیح __cdecl _wutime32(ثابت wchar_t *_Filename,ساختار __utimbuf32 *_Time);
#اگر _INTEGRAL_MAX_BITS >= 64
  _CRTIMP صحیح __cdecl _utime64(ثابت نویسه *_Filename,ساختار __utimbuf64 *_Time);
  _CRTIMP صحیح __cdecl _futime64(صحیح _FileDes,ساختار __utimbuf64 *_Time);
  _CRTIMP صحیح __cdecl _wutime64(ثابت wchar_t *_Filename,ساختار __utimbuf64 *_Time);
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE صحیح __cdecl _utime(ثابت نویسه *_Filename,ساختار _utimbuf *_Utimbuf) {
  بازگشت _utime32(_Filename,(ساختار __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE صحیح __cdecl _futime(صحیح _Desc,ساختار _utimbuf *_Utimbuf) {
  بازگشت _futime32(_Desc,(ساختار __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE صحیح __cdecl _wutime(ثابت wchar_t *_Filename,ساختار _utimbuf *_Utimbuf) {
  بازگشت _wutime32(_Filename,(ساختار __utimbuf32 *)_Utimbuf);
}
#وگرنه
__CRT_INLINE صحیح __cdecl _utime(ثابت نویسه *_Filename,ساختار _utimbuf *_Utimbuf) {
  بازگشت _utime64(_Filename,(ساختار __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE صحیح __cdecl _futime(صحیح _Desc,ساختار _utimbuf *_Utimbuf) {
  بازگشت _futime64(_Desc,(ساختار __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE صحیح __cdecl _wutime(ثابت wchar_t *_Filename,ساختار _utimbuf *_Utimbuf) {
  بازگشت _wutime64(_Filename,(ساختار __utimbuf64 *)_Utimbuf);
}
#endif

#ifndef	NO_OLDNAMES
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE صحیح __cdecl utime(ثابت نویسه *_Filename,ساختار utimbuf *_Utimbuf) {
  بازگشت _utime32(_Filename,(ساختار __utimbuf32 *)_Utimbuf);
}
#وگرنه
__CRT_INLINE صحیح __cdecl utime(ثابت نویسه *_Filename,ساختار utimbuf *_Utimbuf) {
  بازگشت _utime64(_Filename,(ساختار __utimbuf64 *)_Utimbuf);
}
#endif
#endif
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(برداشت)
#endif
