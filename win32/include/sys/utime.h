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

#ضمن <_mingw.h>

#pragma pack(push,_CRT_PACKING)

#ifdef __cplusplus
خارجي "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
  تعريفنوع unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#ܐܚܪܢܐ
#ܐܢ _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  تعريفنوع long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#ܐܢ _INTEGRAL_MAX_BITS >= 64
  تعريفنوع __int64 __time64_t;
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  تعريفنوع __time32_t time_t;
#ܐܚܪܢܐ
  تعريفنوع __time64_t time_t;
#endif
#endif

#ifndef _UTIMBUF_DEFINED
#define _UTIMBUF_DEFINED

  بنية _utimbuf {
    time_t actime;
    time_t modtime;
  };

  بنية __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#ܐܢ _INTEGRAL_MAX_BITS >= 64
  بنية __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#endif

#ifndef	NO_OLDNAMES
  بنية utimbuf {
    time_t actime;
    time_t modtime;
  };

  بنية utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#endif
#endif

  _CRTIMP صحيح __cdecl _utime32(ثابت حرف *_Filename,بنية __utimbuf32 *_Time);
  _CRTIMP صحيح __cdecl _futime32(صحيح _FileDes,بنية __utimbuf32 *_Time);
  _CRTIMP صحيح __cdecl _wutime32(ثابت wchar_t *_Filename,بنية __utimbuf32 *_Time);
#ܐܢ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP صحيح __cdecl _utime64(ثابت حرف *_Filename,بنية __utimbuf64 *_Time);
  _CRTIMP صحيح __cdecl _futime64(صحيح _FileDes,بنية __utimbuf64 *_Time);
  _CRTIMP صحيح __cdecl _wutime64(ثابت wchar_t *_Filename,بنية __utimbuf64 *_Time);
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE صحيح __cdecl _utime(ثابت حرف *_Filename,بنية _utimbuf *_Utimbuf) {
  ܦܢܐ _utime32(_Filename,(بنية __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE صحيح __cdecl _futime(صحيح _Desc,بنية _utimbuf *_Utimbuf) {
  ܦܢܐ _futime32(_Desc,(بنية __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE صحيح __cdecl _wutime(ثابت wchar_t *_Filename,بنية _utimbuf *_Utimbuf) {
  ܦܢܐ _wutime32(_Filename,(بنية __utimbuf32 *)_Utimbuf);
}
#ܐܚܪܢܐ
__CRT_INLINE صحيح __cdecl _utime(ثابت حرف *_Filename,بنية _utimbuf *_Utimbuf) {
  ܦܢܐ _utime64(_Filename,(بنية __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE صحيح __cdecl _futime(صحيح _Desc,بنية _utimbuf *_Utimbuf) {
  ܦܢܐ _futime64(_Desc,(بنية __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE صحيح __cdecl _wutime(ثابت wchar_t *_Filename,بنية _utimbuf *_Utimbuf) {
  ܦܢܐ _wutime64(_Filename,(بنية __utimbuf64 *)_Utimbuf);
}
#endif

#ifndef	NO_OLDNAMES
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE صحيح __cdecl utime(ثابت حرف *_Filename,بنية utimbuf *_Utimbuf) {
  ܦܢܐ _utime32(_Filename,(بنية __utimbuf32 *)_Utimbuf);
}
#ܐܚܪܢܐ
__CRT_INLINE صحيح __cdecl utime(ثابت حرف *_Filename,بنية utimbuf *_Utimbuf) {
  ܦܢܐ _utime64(_Filename,(بنية __utimbuf64 *)_Utimbuf);
}
#endif
#endif
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(pop)
#endif
