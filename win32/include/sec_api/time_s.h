/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIME_H__S
#define _TIME_H__S

#അന്തര്ഭാവ <time.h>

#എങ്കിൽ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

  _CRTIMP errno_t __cdecl _ctime32_s(അക്ഷരം *_Buf,size_t _SizeInBytes,സ്ഥിരം __time32_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime32_s(ഘടന tm *_Tm,സ്ഥിരം __time32_t *_Time);
  _CRTIMP errno_t __cdecl _localtime32_s(ഘടന tm *_Tm,സ്ഥിരം __time32_t *_Time);
  _CRTIMP errno_t __cdecl _strdate_s(അക്ഷരം *_Buf,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _strtime_s(അക്ഷരം *_Buf ,size_t _SizeInBytes);
#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(അക്ഷരം *_Buf,size_t _SizeInBytes,സ്ഥിരം __time64_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime64_s(ഘടന tm *_Tm,സ്ഥിരം __time64_t *_Time);
  _CRTIMP errno_t __cdecl _localtime64_s(ഘടന tm *_Tm,സ്ഥിരം __time64_t *_Time);
#endif

#ifndef _WTIME_S_DEFINED
#define _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,size_t Size_In_വാക്കുകൾ,സ്ഥിരം ഘടന tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,size_t Size_In_വാക്കുകൾ,സ്ഥിരം __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,size_t Size_In_വാക്കുകൾ);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,size_t Size_In_വാക്കുകൾ);
#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,size_t Size_In_വാക്കുകൾ,സ്ഥിരം __time64_t *_Time);
#endif

#എങ്കിൽ !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#define _INC_WTIME_S_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t Size_In_വാക്കുകൾ,സ്ഥിരം time_t *_Time) { തിരികെ _wctime32_s(_Buffer,Size_In_വാക്കുകൾ,_Time); }
#അല്ലെങ്കിൽ
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t Size_In_വാക്കുകൾ,സ്ഥിരം time_t *_Time) { തിരികെ _wctime64_s(_Buffer,Size_In_വാക്കുകൾ,_Time); }
#endif
#endif
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl localtime_s(ഘടന tm *_Tm,സ്ഥിരം time_t *_Time) { തിരികെ _localtime32_s(_Tm,_Time); }
#അല്ലെങ്കിൽ
__CRT_INLINE errno_t __cdecl localtime_s(ഘടന tm *_Tm,സ്ഥിരം time_t *_Time) { തിരികെ _localtime64_s(_Tm,_Time); }
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
