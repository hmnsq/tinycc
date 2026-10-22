/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_STRING_S
#تعریف_کن _INC_STRING_S

#ضمن <string.h>

#إذا defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

  _CRTIMP errno_t __cdecl _strset_s(حرف *_Dst,اندازه_t Dst_اندازه,صحيح مقدار_2);
  _CRTIMP errno_t __cdecl _strerror_s(حرف *_Buf,اندازه_t اندازه_درون_بایتها,ثابت حرف *Err_پیام);
  _CRTIMP errno_t __cdecl _strlwr_s(حرف *_Str,اندازه_t اندازه_4);
  _CRTIMP errno_t __cdecl _strlwr_s_l(حرف *_Str,اندازه_t اندازه_4,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(حرف *_Str,اندازه_t اندازه_4,صحيح _Val,اندازه_t Max_شمار);
  _CRTIMP errno_t __cdecl _strupr_s(حرف *_Str,اندازه_t اندازه_4);
  _CRTIMP errno_t __cdecl _strupr_s_l(حرف *_Str,اندازه_t اندازه_4,_locale_t _Locale);
#اگر_تعریف_نشده _WSTRING_S_DEFINED
#تعریف_کن _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,ثابت wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,اندازه_t اندازه_درون_واژگان,صحيح Err_رقم);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *میانگیر_2,اندازه_t اندازه_درون_واژگان,ثابت wchar_t *Err_پیام);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,اندازه_t Dst_اندازه_درون_واژگان,wchar_t _Val,اندازه_t Max_شمار);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,اندازه_t اندازه_درون_واژگان,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,اندازه_t اندازه_درون_واژگان);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,اندازه_t اندازه_درون_واژگان,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,اندازه_t اندازه_4);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,اندازه_t اندازه_4,_locale_t _Locale);
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر
#پایان_اگر
#پایان_اگر
