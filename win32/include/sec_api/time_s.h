/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIME_H__S
#define _TIME_H__S

#অন্তর্ভাব <time.h>

#যদি defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
বাহ্য "C" {
#endif

  _CRTIMP errno_t __cdecl _ctime32_s(বর্ণ *_Buf,size_t _SizeInBytes,ধ্রুব __time32_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime32_s(সংরচনা tm *_Tm,ধ্রুব __time32_t *_Time);
  _CRTIMP errno_t __cdecl _localtime32_s(সংরচনা tm *_Tm,ধ্রুব __time32_t *_Time);
  _CRTIMP errno_t __cdecl _strdate_s(বর্ণ *_Buf,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _strtime_s(বর্ণ *_Buf ,size_t _SizeInBytes);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(বর্ণ *_Buf,size_t _SizeInBytes,ধ্রুব __time64_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime64_s(সংরচনা tm *_Tm,ধ্রুব __time64_t *_Time);
  _CRTIMP errno_t __cdecl _localtime64_s(সংরচনা tm *_Tm,ধ্রুব __time64_t *_Time);
#endif

#ifndef _WTIME_S_DEFINED
#define _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,size_t Size_In_শব্দগুলি,ধ্রুব সংরচনা tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,size_t Size_In_শব্দগুলি,ধ্রুব __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,size_t Size_In_শব্দগুলি);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,size_t Size_In_শব্দগুলি);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,size_t Size_In_শব্দগুলি,ধ্রুব __time64_t *_Time);
#endif

#যদি !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#define _INC_WTIME_S_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t Size_In_শব্দগুলি,ধ্রুব time_t *_Time) { প্রত্যাগম _wctime32_s(_Buffer,Size_In_শব্দগুলি,_Time); }
#অন্যথা
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t Size_In_শব্দগুলি,ধ্রুব time_t *_Time) { প্রত্যাগম _wctime64_s(_Buffer,Size_In_শব্দগুলি,_Time); }
#endif
#endif
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl localtime_s(সংরচনা tm *_Tm,ধ্রুব time_t *_Time) { প্রত্যাগম _localtime32_s(_Tm,_Time); }
#অন্যথা
__CRT_INLINE errno_t __cdecl localtime_s(সংরচনা tm *_Tm,ধ্রুব time_t *_Time) { প্রত্যাগম _localtime64_s(_Tm,_Time); }
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
