/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING_S
#define _INC_STRING_S

#அந்தர்பாவ <string.h>

#எனில் defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
வெளி "C" {
#endif

  _CRTIMP errno_t __cdecl _strset_s(எழுத்து *_Dst,size_t _DstSize,முழு மதிப்பு_2);
  _CRTIMP errno_t __cdecl _strerror_s(எழுத்து *_Buf,size_t _SizeInBytes,மாறிலி எழுத்து *Err_செய்தி);
  _CRTIMP errno_t __cdecl _strlwr_s(எழுத்து *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _strlwr_s_l(எழுத்து *_Str,size_t _Size,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(எழுத்து *_Str,size_t _Size,முழு _Val,size_t Max_மொத்தம்);
  _CRTIMP errno_t __cdecl _strupr_s(எழுத்து *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _strupr_s_l(எழுத்து *_Str,size_t _Size,_locale_t _Locale);
#ifndef _WSTRING_S_DEFINED
#define _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,மாறிலி wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,size_t Size_In_சொற்கள்,முழு Err_இலக்கம்);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *_Buffer,size_t Size_In_சொற்கள்,மாறிலி wchar_t *Err_செய்தி);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,size_t Dst_Size_In_சொற்கள்,wchar_t _Val,size_t Max_மொத்தம்);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,size_t Size_In_சொற்கள்,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,size_t Size_In_சொற்கள்);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,size_t Size_In_சொற்கள்,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,size_t _Size,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
