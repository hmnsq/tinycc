/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIME_H__S
#define _TIME_H__S

#شامل <time.h>

#اگر defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
بیرونی "C" {
#endif

  _CRTIMP errno_t __cdecl _ctime32_s(نویسه *_Buf,size_t _SizeInBytes,ثابت __time32_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime32_s(ساختار tm *_Tm,ثابت __time32_t *_Time);
  _CRTIMP errno_t __cdecl _localtime32_s(ساختار tm *_Tm,ثابت __time32_t *_Time);
  _CRTIMP errno_t __cdecl _strdate_s(نویسه *_Buf,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _strtime_s(نویسه *_Buf ,size_t _SizeInBytes);
#اگر _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(نویسه *_Buf,size_t _SizeInBytes,ثابت __time64_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime64_s(ساختار tm *_Tm,ثابت __time64_t *_Time);
  _CRTIMP errno_t __cdecl _localtime64_s(ساختار tm *_Tm,ثابت __time64_t *_Time);
#endif

#ifndef _WTIME_S_DEFINED
#define _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,size_t Size_In_واژگان,ثابت ساختار tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,size_t Size_In_واژگان,ثابت __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,size_t Size_In_واژگان);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,size_t Size_In_واژگان);
#اگر _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,size_t Size_In_واژگان,ثابت __time64_t *_Time);
#endif

#اگر !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#define _INC_WTIME_S_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t Size_In_واژگان,ثابت time_t *_Time) { بازگشت _wctime32_s(_Buffer,Size_In_واژگان,_Time); }
#وگرنه
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t Size_In_واژگان,ثابت time_t *_Time) { بازگشت _wctime64_s(_Buffer,Size_In_واژگان,_Time); }
#endif
#endif
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl localtime_s(ساختار tm *_Tm,ثابت time_t *_Time) { بازگشت _localtime32_s(_Tm,_Time); }
#وگرنه
__CRT_INLINE errno_t __cdecl localtime_s(ساختار tm *_Tm,ثابت time_t *_Time) { بازگشت _localtime64_s(_Tm,_Time); }
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
