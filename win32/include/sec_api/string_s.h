/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING_S
#define _INC_STRING_S

#અન્તર્ભાવ <string.h>

#જો defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
બાહ્ય "C" {
#endif

  _CRTIMP errno_t __cdecl _strset_s(અક્ષર *_Dst,size_t _DstSize,પૂર્ણાંક કિંમત_2);
  _CRTIMP errno_t __cdecl _strerror_s(અક્ષર *_Buf,size_t _SizeInBytes,અચલ અક્ષર *Err_સંદેશ);
  _CRTIMP errno_t __cdecl _strlwr_s(અક્ષર *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _strlwr_s_l(અક્ષર *_Str,size_t _Size,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(અક્ષર *_Str,size_t _Size,પૂર્ણાંક _Val,size_t Max_ગણતરી);
  _CRTIMP errno_t __cdecl _strupr_s(અક્ષર *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _strupr_s_l(અક્ષર *_Str,size_t _Size,_locale_t _Locale);
#ifndef _WSTRING_S_DEFINED
#define _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,અચલ wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,size_t Size_In_શબ્દો,પૂર્ણાંક Err_અંક);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *_Buffer,size_t Size_In_શબ્દો,અચલ wchar_t *Err_સંદેશ);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,size_t Dst_Size_In_શબ્દો,wchar_t _Val,size_t Max_ગણતરી);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,size_t Size_In_શબ્દો,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,size_t Size_In_શબ્દો);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,size_t Size_In_શબ્દો,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,size_t _Size,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
