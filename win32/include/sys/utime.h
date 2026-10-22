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

#অন্তর্ভাব <_mingw.h>

#pragma pack(ঠেলো,_CRT_PACKING)

#ifdef __cplusplus
বাহ্যিক "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
  প্রকারলেখ unsigned short wchar_t;
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
  প্রকারলেখ long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#যদি _INTEGRAL_MAX_BITS >= 64
  প্রকারলেখ __int64 __time64_t;
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  প্রকারলেখ __time32_t time_t;
#অন্যথা
  প্রকারলেখ __time64_t time_t;
#endif
#endif

#ifndef _UTIMBUF_DEFINED
#define _UTIMBUF_DEFINED

  কাঠামো _utimbuf {
    time_t actime;
    time_t modtime;
  };

  কাঠামো __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#যদি _INTEGRAL_MAX_BITS >= 64
  কাঠামো __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#endif

#ifndef	NO_OLDNAMES
  কাঠামো utimbuf {
    time_t actime;
    time_t modtime;
  };

  কাঠামো utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#endif
#endif

  _CRTIMP পূর্ণসংখ্যা __cdecl _utime32(ধ্রুবক অক্ষর *_Filename,কাঠামো __utimbuf32 *_Time);
  _CRTIMP পূর্ণসংখ্যা __cdecl _futime32(পূর্ণসংখ্যা _FileDes,কাঠামো __utimbuf32 *_Time);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wutime32(ধ্রুবক wchar_t *_Filename,কাঠামো __utimbuf32 *_Time);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP পূর্ণসংখ্যা __cdecl _utime64(ধ্রুবক অক্ষর *_Filename,কাঠামো __utimbuf64 *_Time);
  _CRTIMP পূর্ণসংখ্যা __cdecl _futime64(পূর্ণসংখ্যা _FileDes,কাঠামো __utimbuf64 *_Time);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wutime64(ধ্রুবক wchar_t *_Filename,কাঠামো __utimbuf64 *_Time);
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE পূর্ণসংখ্যা __cdecl _utime(ধ্রুবক অক্ষর *_Filename,কাঠামো _utimbuf *_Utimbuf) {
  ফেরত _utime32(_Filename,(কাঠামো __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE পূর্ণসংখ্যা __cdecl _futime(পূর্ণসংখ্যা _Desc,কাঠামো _utimbuf *_Utimbuf) {
  ফেরত _futime32(_Desc,(কাঠামো __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE পূর্ণসংখ্যা __cdecl _wutime(ধ্রুবক wchar_t *_Filename,কাঠামো _utimbuf *_Utimbuf) {
  ফেরত _wutime32(_Filename,(কাঠামো __utimbuf32 *)_Utimbuf);
}
#অন্যথা
__CRT_INLINE পূর্ণসংখ্যা __cdecl _utime(ধ্রুবক অক্ষর *_Filename,কাঠামো _utimbuf *_Utimbuf) {
  ফেরত _utime64(_Filename,(কাঠামো __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE পূর্ণসংখ্যা __cdecl _futime(পূর্ণসংখ্যা _Desc,কাঠামো _utimbuf *_Utimbuf) {
  ফেরত _futime64(_Desc,(কাঠামো __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE পূর্ণসংখ্যা __cdecl _wutime(ধ্রুবক wchar_t *_Filename,কাঠামো _utimbuf *_Utimbuf) {
  ফেরত _wutime64(_Filename,(কাঠামো __utimbuf64 *)_Utimbuf);
}
#endif

#ifndef	NO_OLDNAMES
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE পূর্ণসংখ্যা __cdecl utime(ধ্রুবক অক্ষর *_Filename,কাঠামো utimbuf *_Utimbuf) {
  ফেরত _utime32(_Filename,(কাঠামো __utimbuf32 *)_Utimbuf);
}
#অন্যথা
__CRT_INLINE পূর্ণসংখ্যা __cdecl utime(ধ্রুবক অক্ষর *_Filename,কাঠামো utimbuf *_Utimbuf) {
  ফেরত _utime64(_Filename,(কাঠামো __utimbuf64 *)_Utimbuf);
}
#endif
#endif
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(বের_করো)
#endif
