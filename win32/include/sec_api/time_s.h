/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIME_H__S
#define _TIME_H__S

#ଅନ୍ତର୍ଭାଵ <time.h>

#ଯଦି defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

  _CRTIMP errno_t __cdecl _ctime32_s(ଅକ୍ଷର *_Buf,size_t _SizeInBytes,ଅଚଳ __time32_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime32_s(ସଂରଚନା tm *_Tm,ଅଚଳ __time32_t *_Time);
  _CRTIMP errno_t __cdecl _localtime32_s(ସଂରଚନା tm *_Tm,ଅଚଳ __time32_t *_Time);
  _CRTIMP errno_t __cdecl _strdate_s(ଅକ୍ଷର *_Buf,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _strtime_s(ଅକ୍ଷର *_Buf ,size_t _SizeInBytes);
#ଯଦି _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(ଅକ୍ଷର *_Buf,size_t _SizeInBytes,ଅଚଳ __time64_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime64_s(ସଂରଚନା tm *_Tm,ଅଚଳ __time64_t *_Time);
  _CRTIMP errno_t __cdecl _localtime64_s(ସଂରଚନା tm *_Tm,ଅଚଳ __time64_t *_Time);
#endif

#ifndef _WTIME_S_DEFINED
#define _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ ସଂରଚନା tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ);
#ଯଦି _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ __time64_t *_Time);
#endif

#ଯଦି !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#define _INC_WTIME_S_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ time_t *_Time) { ଫେରନ୍ତୁ _wctime32_s(_Buffer,Size_In_ଶବ୍ଦଗୁଡ଼ିକ,_Time); }
#ଅନ୍ୟଥା
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ time_t *_Time) { ଫେରନ୍ତୁ _wctime64_s(_Buffer,Size_In_ଶବ୍ଦଗୁଡ଼ିକ,_Time); }
#endif
#endif
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl localtime_s(ସଂରଚନା tm *_Tm,ଅଚଳ time_t *_Time) { ଫେରନ୍ତୁ _localtime32_s(_Tm,_Time); }
#ଅନ୍ୟଥା
__CRT_INLINE errno_t __cdecl localtime_s(ସଂରଚନା tm *_Tm,ଅଚଳ time_t *_Time) { ଫେରନ୍ତୁ _localtime64_s(_Tm,_Time); }
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
