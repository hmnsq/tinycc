/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIME_H__S
#define _TIME_H__S

#ಅನ್ತರ್ಭಾವ <time.h>

#ಯದಿ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

  _CRTIMP errno_t __cdecl _ctime32_s(ವರ್ಣ *_Buf,size_t _SizeInBytes,ಧ್ರುವ __time32_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime32_s(ಸಂರಚನಾ tm *_Tm,ಧ್ರುವ __time32_t *_Time);
  _CRTIMP errno_t __cdecl _localtime32_s(ಸಂರಚನಾ tm *_Tm,ಧ್ರುವ __time32_t *_Time);
  _CRTIMP errno_t __cdecl _strdate_s(ವರ್ಣ *_Buf,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _strtime_s(ವರ್ಣ *_Buf ,size_t _SizeInBytes);
#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(ವರ್ಣ *_Buf,size_t _SizeInBytes,ಧ್ರುವ __time64_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime64_s(ಸಂರಚನಾ tm *_Tm,ಧ್ರುವ __time64_t *_Time);
  _CRTIMP errno_t __cdecl _localtime64_s(ಸಂರಚನಾ tm *_Tm,ಧ್ರುವ __time64_t *_Time);
#endif

#ifndef _WTIME_S_DEFINED
#define _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,size_t Size_In_ಪದಗಳು,ಧ್ರುವ ಸಂರಚನಾ tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,size_t Size_In_ಪದಗಳು,ಧ್ರುವ __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,size_t Size_In_ಪದಗಳು);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,size_t Size_In_ಪದಗಳು);
#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,size_t Size_In_ಪದಗಳು,ಧ್ರುವ __time64_t *_Time);
#endif

#ಯದಿ !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#define _INC_WTIME_S_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t Size_In_ಪದಗಳು,ಧ್ರುವ time_t *_Time) { ಪ್ರತ್ಯಾಗಮ _wctime32_s(_Buffer,Size_In_ಪದಗಳು,_Time); }
#ಅನ್ಯಥಾ
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t Size_In_ಪದಗಳು,ಧ್ರುವ time_t *_Time) { ಪ್ರತ್ಯಾಗಮ _wctime64_s(_Buffer,Size_In_ಪದಗಳು,_Time); }
#endif
#endif
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl localtime_s(ಸಂರಚನಾ tm *_Tm,ಧ್ರುವ time_t *_Time) { ಪ್ರತ್ಯಾಗಮ _localtime32_s(_Tm,_Time); }
#ಅನ್ಯಥಾ
__CRT_INLINE errno_t __cdecl localtime_s(ಸಂರಚನಾ tm *_Tm,ಧ್ರುವ time_t *_Time) { ಪ್ರತ್ಯಾಗಮ _localtime64_s(_Tm,_Time); }
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
