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

#অন্তর্ভাৱ <_mingw.h>

#pragma pack(ঠেলো,_CRT_PACKING)

#ifdef __cplusplus
বাহ্য "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
  প্রকারনির্দেশ unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#অন্যথা
#যদি _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  প্রকারনির্দেশ long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#যদি _INTEGRAL_MAX_BITS >= 64
  প্রকারনির্দেশ __int64 __time64_t;
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  প্রকারনির্দেশ __time32_t time_t;
#অন্যথা
  প্রকারনির্দেশ __time64_t time_t;
#endif
#endif

#ifndef _UTIMBUF_DEFINED
#define _UTIMBUF_DEFINED

  সংরচনা _utimbuf {
    time_t actime;
    time_t modtime;
  };

  সংরচনা __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#যদি _INTEGRAL_MAX_BITS >= 64
  সংরচনা __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#endif

#ifndef	NO_OLDNAMES
  সংরচনা utimbuf {
    time_t actime;
    time_t modtime;
  };

  সংরচনা utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#endif
#endif

  _CRTIMP পূর্ণাঙ্ক __cdecl _utime32(ধ্রুৱ ৱর্ণ *_Filename,সংরচনা __utimbuf32 *_Time);
  _CRTIMP পূর্ণাঙ্ক __cdecl _futime32(পূর্ণাঙ্ক _FileDes,সংরচনা __utimbuf32 *_Time);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wutime32(ধ্রুৱ wchar_t *_Filename,সংরচনা __utimbuf32 *_Time);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP পূর্ণাঙ্ক __cdecl _utime64(ধ্রুৱ ৱর্ণ *_Filename,সংরচনা __utimbuf64 *_Time);
  _CRTIMP পূর্ণাঙ্ক __cdecl _futime64(পূর্ণাঙ্ক _FileDes,সংরচনা __utimbuf64 *_Time);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wutime64(ধ্রুৱ wchar_t *_Filename,সংরচনা __utimbuf64 *_Time);
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE পূর্ণাঙ্ক __cdecl _utime(ধ্রুৱ ৱর্ণ *_Filename,সংরচনা _utimbuf *_Utimbuf) {
  ঘূৰাই _utime32(_Filename,(সংরচনা __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE পূর্ণাঙ্ক __cdecl _futime(পূর্ণাঙ্ক _Desc,সংরচনা _utimbuf *_Utimbuf) {
  ঘূৰাই _futime32(_Desc,(সংরচনা __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE পূর্ণাঙ্ক __cdecl _wutime(ধ্রুৱ wchar_t *_Filename,সংরচনা _utimbuf *_Utimbuf) {
  ঘূৰাই _wutime32(_Filename,(সংরচনা __utimbuf32 *)_Utimbuf);
}
#অন্যথা
__CRT_INLINE পূর্ণাঙ্ক __cdecl _utime(ধ্রুৱ ৱর্ণ *_Filename,সংরচনা _utimbuf *_Utimbuf) {
  ঘূৰাই _utime64(_Filename,(সংরচনা __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE পূর্ণাঙ্ক __cdecl _futime(পূর্ণাঙ্ক _Desc,সংরচনা _utimbuf *_Utimbuf) {
  ঘূৰাই _futime64(_Desc,(সংরচনা __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE পূর্ণাঙ্ক __cdecl _wutime(ধ্রুৱ wchar_t *_Filename,সংরচনা _utimbuf *_Utimbuf) {
  ঘূৰাই _wutime64(_Filename,(সংরচনা __utimbuf64 *)_Utimbuf);
}
#endif

#ifndef	NO_OLDNAMES
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE পূর্ণাঙ্ক __cdecl utime(ধ্রুৱ ৱর্ণ *_Filename,সংরচনা utimbuf *_Utimbuf) {
  ঘূৰাই _utime32(_Filename,(সংরচনা __utimbuf32 *)_Utimbuf);
}
#অন্যথা
__CRT_INLINE পূর্ণাঙ্ক __cdecl utime(ধ্রুৱ ৱর্ণ *_Filename,সংরচনা utimbuf *_Utimbuf) {
  ঘূৰাই _utime64(_Filename,(সংরচনা __utimbuf64 *)_Utimbuf);
}
#endif
#endif
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(বেৰ_কৰো)
#endif
