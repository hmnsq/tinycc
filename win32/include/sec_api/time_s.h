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
বাহ্যিক "C" {
#endif

  _CRTIMP errno_t __cdecl _ctime32_s(অক্ষর *_Buf,আকার_t আকার_In_Bytes,ধ্রুবক __time32_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime32_s(কাঠামো tm *_Tm,ধ্রুবক __time32_t *_Time);
  _CRTIMP errno_t __cdecl _localtime32_s(কাঠামো tm *_Tm,ধ্রুবক __time32_t *_Time);
  _CRTIMP errno_t __cdecl _strdate_s(অক্ষর *_Buf,আকার_t আকার_In_Bytes);
  _CRTIMP errno_t __cdecl _strtime_s(অক্ষর *_Buf ,আকার_t আকার_In_Bytes);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(অক্ষর *_Buf,আকার_t আকার_In_Bytes,ধ্রুবক __time64_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime64_s(কাঠামো tm *_Tm,ধ্রুবক __time64_t *_Time);
  _CRTIMP errno_t __cdecl _localtime64_s(কাঠামো tm *_Tm,ধ্রুবক __time64_t *_Time);
#endif

#ifndef _WTIME_S_DEFINED
#define _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,আকার_t আকার_In_শব্দগুলি,ধ্রুবক কাঠামো tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,আকার_t আকার_In_শব্দগুলি,ধ্রুবক __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,আকার_t আকার_In_শব্দগুলি);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,আকার_t আকার_In_শব্দগুলি);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,আকার_t আকার_In_শব্দগুলি,ধ্রুবক __time64_t *_Time);
#endif

#যদি !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#define _INC_WTIME_S_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *বাফার_2,আকার_t আকার_In_শব্দগুলি,ধ্রুবক time_t *_Time) { ফেরত _wctime32_s(বাফার_2,আকার_In_শব্দগুলি,_Time); }
#অন্যথা
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *বাফার_2,আকার_t আকার_In_শব্দগুলি,ধ্রুবক time_t *_Time) { ফেরত _wctime64_s(বাফার_2,আকার_In_শব্দগুলি,_Time); }
#endif
#endif
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl localtime_s(কাঠামো tm *_Tm,ধ্রুবক time_t *_Time) { ফেরত _localtime32_s(_Tm,_Time); }
#অন্যথা
__CRT_INLINE errno_t __cdecl localtime_s(কাঠামো tm *_Tm,ধ্রুবক time_t *_Time) { ফেরত _localtime64_s(_Tm,_Time); }
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
