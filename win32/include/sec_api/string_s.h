/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING_S
#define _INC_STRING_S

#അന്തര്ഭാവ <string.h>

#എങ്കിൽ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

  _CRTIMP errno_t __cdecl _strset_s(അക്ഷരം *_Dst,size_t _DstSize,പൂർണ്ണസംഖ്യ മൂല്യം_2);
  _CRTIMP errno_t __cdecl _strerror_s(അക്ഷരം *_Buf,size_t _SizeInBytes,സ്ഥിരം അക്ഷരം *Err_സന്ദേശം);
  _CRTIMP errno_t __cdecl _strlwr_s(അക്ഷരം *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _strlwr_s_l(അക്ഷരം *_Str,size_t _Size,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(അക്ഷരം *_Str,size_t _Size,പൂർണ്ണസംഖ്യ _Val,size_t Max_എണ്ണം);
  _CRTIMP errno_t __cdecl _strupr_s(അക്ഷരം *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _strupr_s_l(അക്ഷരം *_Str,size_t _Size,_locale_t _Locale);
#ifndef _WSTRING_S_DEFINED
#define _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,സ്ഥിരം wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,size_t Size_In_വാക്കുകൾ,പൂർണ്ണസംഖ്യ Err_അക്കം);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *_Buffer,size_t Size_In_വാക്കുകൾ,സ്ഥിരം wchar_t *Err_സന്ദേശം);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,size_t Dst_Size_In_വാക്കുകൾ,wchar_t _Val,size_t Max_എണ്ണം);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,size_t Size_In_വാക്കുകൾ,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,size_t Size_In_വാക്കുകൾ);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,size_t Size_In_വാക്കുകൾ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,size_t _Size,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
