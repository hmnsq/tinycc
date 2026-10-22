/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_STRING_S
#تعریف_کرو _INC_STRING_S

#شامل <string.h>

#اگر defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

  _CRTIMP errno_t __cdecl _strset_s(حرف *_Dst,سائز_t Dst_سائز,صحیح قدر_2);
  _CRTIMP errno_t __cdecl _strerror_s(حرف *_Buf,سائز_t سائز_اندر_بائٹیں,ثابت حرف *Err_پیغام);
  _CRTIMP errno_t __cdecl _strlwr_s(حرف *_Str,سائز_t سائز_4);
  _CRTIMP errno_t __cdecl _strlwr_s_l(حرف *_Str,سائز_t سائز_4,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(حرف *_Str,سائز_t سائز_4,صحیح _Val,سائز_t Max_گنتی);
  _CRTIMP errno_t __cdecl _strupr_s(حرف *_Str,سائز_t سائز_4);
  _CRTIMP errno_t __cdecl _strupr_s_l(حرف *_Str,سائز_t سائز_4,_locale_t _Locale);
#اگر_غیر_تعریف_شدہ _WSTRING_S_DEFINED
#تعریف_کرو _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,ثابت wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,سائز_t سائز_اندر_الفاظ,صحیح Err_عدد);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *بفر_2,سائز_t سائز_اندر_الفاظ,ثابت wchar_t *Err_پیغام);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,سائز_t Dst_سائز_اندر_الفاظ,wchar_t _Val,سائز_t Max_گنتی);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,سائز_t سائز_اندر_الفاظ,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,سائز_t سائز_اندر_الفاظ);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,سائز_t سائز_اندر_الفاظ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,سائز_t سائز_4);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,سائز_t سائز_4,_locale_t _Locale);
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم
#اگر_ختم
#اگر_ختم
