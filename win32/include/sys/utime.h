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

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#pragma pack(ತಳ್ಳು,_CRT_PACKING)

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#ಅನ್ಯಥಾ
#ಯದಿ _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  ಪ್ರಕಾರನಿರ್ದೇಶ long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  ಪ್ರಕಾರನಿರ್ದೇಶ __int64 __time64_t;
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  ಪ್ರಕಾರನಿರ್ದೇಶ __time32_t time_t;
#ಅನ್ಯಥಾ
  ಪ್ರಕಾರನಿರ್ದೇಶ __time64_t time_t;
#endif
#endif

#ifndef _UTIMBUF_DEFINED
#define _UTIMBUF_DEFINED

  ಸಂರಚನಾ _utimbuf {
    time_t actime;
    time_t modtime;
  };

  ಸಂರಚನಾ __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  ಸಂರಚನಾ __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#endif

#ifndef	NO_OLDNAMES
  ಸಂರಚನಾ utimbuf {
    time_t actime;
    time_t modtime;
  };

  ಸಂರಚನಾ utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#endif
#endif

  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _utime32(ಧ್ರುವ ವರ್ಣ *_Filename,ಸಂರಚನಾ __utimbuf32 *_Time);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _futime32(ಪೂರ್ಣಾಙ್ಕ _FileDes,ಸಂರಚನಾ __utimbuf32 *_Time);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wutime32(ಧ್ರುವ wchar_t *_Filename,ಸಂರಚನಾ __utimbuf32 *_Time);
#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _utime64(ಧ್ರುವ ವರ್ಣ *_Filename,ಸಂರಚನಾ __utimbuf64 *_Time);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _futime64(ಪೂರ್ಣಾಙ್ಕ _FileDes,ಸಂರಚನಾ __utimbuf64 *_Time);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wutime64(ಧ್ರುವ wchar_t *_Filename,ಸಂರಚನಾ __utimbuf64 *_Time);
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl _utime(ಧ್ರುವ ವರ್ಣ *_Filename,ಸಂರಚನಾ _utimbuf *_Utimbuf) {
  ಪ್ರತ್ಯಾಗಮ _utime32(_Filename,(ಸಂರಚನಾ __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl _futime(ಪೂರ್ಣಾಙ್ಕ _Desc,ಸಂರಚನಾ _utimbuf *_Utimbuf) {
  ಪ್ರತ್ಯಾಗಮ _futime32(_Desc,(ಸಂರಚನಾ __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl _wutime(ಧ್ರುವ wchar_t *_Filename,ಸಂರಚನಾ _utimbuf *_Utimbuf) {
  ಪ್ರತ್ಯಾಗಮ _wutime32(_Filename,(ಸಂರಚನಾ __utimbuf32 *)_Utimbuf);
}
#ಅನ್ಯಥಾ
__CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl _utime(ಧ್ರುವ ವರ್ಣ *_Filename,ಸಂರಚನಾ _utimbuf *_Utimbuf) {
  ಪ್ರತ್ಯಾಗಮ _utime64(_Filename,(ಸಂರಚನಾ __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl _futime(ಪೂರ್ಣಾಙ್ಕ _Desc,ಸಂರಚನಾ _utimbuf *_Utimbuf) {
  ಪ್ರತ್ಯಾಗಮ _futime64(_Desc,(ಸಂರಚನಾ __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl _wutime(ಧ್ರುವ wchar_t *_Filename,ಸಂರಚನಾ _utimbuf *_Utimbuf) {
  ಪ್ರತ್ಯಾಗಮ _wutime64(_Filename,(ಸಂರಚನಾ __utimbuf64 *)_Utimbuf);
}
#endif

#ifndef	NO_OLDNAMES
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl utime(ಧ್ರುವ ವರ್ಣ *_Filename,ಸಂರಚನಾ utimbuf *_Utimbuf) {
  ಪ್ರತ್ಯಾಗಮ _utime32(_Filename,(ಸಂರಚನಾ __utimbuf32 *)_Utimbuf);
}
#ಅನ್ಯಥಾ
__CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl utime(ಧ್ರುವ ವರ್ಣ *_Filename,ಸಂರಚನಾ utimbuf *_Utimbuf) {
  ಪ್ರತ್ಯಾಗಮ _utime64(_Filename,(ಸಂರಚನಾ __utimbuf64 *)_Utimbuf);
}
#endif
#endif
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(ತೆಗೆ)
#endif
