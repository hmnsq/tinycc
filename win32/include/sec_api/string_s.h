/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_STRING_S
#تعریف_کړه _INC_STRING_S

#ضمن <string.h>

#إذا defined(MINGW_HAS_SECURE_API)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

  _CRTIMP errno_t __cdecl _strset_s(حرف *_Dst,اندازه_t Dst_اندازه,صحيح ارزښت_2);
  _CRTIMP errno_t __cdecl _strerror_s(حرف *_Buf,اندازه_t اندازه_دننه_بایټونه,ثابت حرف *Err_پیغام);
  _CRTIMP errno_t __cdecl _strlwr_s(حرف *_Str,اندازه_t اندازه_4);
  _CRTIMP errno_t __cdecl _strlwr_s_l(حرف *_Str,اندازه_t اندازه_4,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(حرف *_Str,اندازه_t اندازه_4,صحيح _Val,اندازه_t Max_شمېر);
  _CRTIMP errno_t __cdecl _strupr_s(حرف *_Str,اندازه_t اندازه_4);
  _CRTIMP errno_t __cdecl _strupr_s_l(حرف *_Str,اندازه_t اندازه_4,_locale_t _Locale);
#که_نه_تعریف_شوی _WSTRING_S_DEFINED
#تعریف_کړه _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,ثابت wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,اندازه_t اندازه_دننه_ټکي,صحيح Err_عدد);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *بفر_2,اندازه_t اندازه_دننه_ټکي,ثابت wchar_t *Err_پیغام);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,اندازه_t Dst_اندازه_دننه_ټکي,wchar_t _Val,اندازه_t Max_شمېر);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,اندازه_t اندازه_دننه_ټکي,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,اندازه_t اندازه_دننه_ټکي);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,اندازه_t اندازه_دننه_ټکي,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,اندازه_t اندازه_4);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,اندازه_t اندازه_4,_locale_t _Locale);
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای
#د_که_پای
#د_که_پای
