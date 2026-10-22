/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIME_H__S
#define _TIME_H__S

#અન્તર્ભાવ <time.h>

#જો defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
બાહ્ય "C" {
#endif

  _CRTIMP errno_t __cdecl _ctime32_s(અક્ષર *_Buf,size_t _SizeInBytes,અચલ __time32_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime32_s(સંરચના tm *_Tm,અચલ __time32_t *_Time);
  _CRTIMP errno_t __cdecl _localtime32_s(સંરચના tm *_Tm,અચલ __time32_t *_Time);
  _CRTIMP errno_t __cdecl _strdate_s(અક્ષર *_Buf,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _strtime_s(અક્ષર *_Buf ,size_t _SizeInBytes);
#જો _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(અક્ષર *_Buf,size_t _SizeInBytes,અચલ __time64_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime64_s(સંરચના tm *_Tm,અચલ __time64_t *_Time);
  _CRTIMP errno_t __cdecl _localtime64_s(સંરચના tm *_Tm,અચલ __time64_t *_Time);
#endif

#ifndef _WTIME_S_DEFINED
#define _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,size_t Size_In_શબ્દો,અચલ સંરચના tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,size_t Size_In_શબ્દો,અચલ __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,size_t Size_In_શબ્દો);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,size_t Size_In_શબ્દો);
#જો _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,size_t Size_In_શબ્દો,અચલ __time64_t *_Time);
#endif

#જો !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#define _INC_WTIME_S_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t Size_In_શબ્દો,અચલ time_t *_Time) { પાછા _wctime32_s(_Buffer,Size_In_શબ્દો,_Time); }
#નહીંતર
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t Size_In_શબ્દો,અચલ time_t *_Time) { પાછા _wctime64_s(_Buffer,Size_In_શબ્દો,_Time); }
#endif
#endif
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl localtime_s(સંરચના tm *_Tm,અચલ time_t *_Time) { પાછા _localtime32_s(_Tm,_Time); }
#નહીંતર
__CRT_INLINE errno_t __cdecl localtime_s(સંરચના tm *_Tm,અચલ time_t *_Time) { પાછા _localtime64_s(_Tm,_Time); }
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
