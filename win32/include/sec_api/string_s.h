/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_STRING_S
#وصف_ڪريو _INC_STRING_S

#ضمن <string.h>

#إذا defined(MINGW_HAS_SECURE_API)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

  _CRTIMP errno_t __cdecl _strset_s(حرف *_Dst,سائيز_t Dst_سائيز,صحيح قدر_2);
  _CRTIMP errno_t __cdecl _strerror_s(حرف *_Buf,سائيز_t سائيز_اندريون_بائيٽون,ثابت حرف *Err_نياپو);
  _CRTIMP errno_t __cdecl _strlwr_s(حرف *_Str,سائيز_t سائيز_4);
  _CRTIMP errno_t __cdecl _strlwr_s_l(حرف *_Str,سائيز_t سائيز_4,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(حرف *_Str,سائيز_t سائيز_4,صحيح _Val,سائيز_t Max_ڳڻپ);
  _CRTIMP errno_t __cdecl _strupr_s(حرف *_Str,سائيز_t سائيز_4);
  _CRTIMP errno_t __cdecl _strupr_s_l(حرف *_Str,سائيز_t سائيز_4,_locale_t _Locale);
#جيڪڏهن_وصف_نه_ٿيل _WSTRING_S_DEFINED
#وصف_ڪريو _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,ثابت wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,سائيز_t سائيز_اندريون_لفظ,صحيح Err_انگ);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *بفر_2,سائيز_t سائيز_اندريون_لفظ,ثابت wchar_t *Err_نياپو);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,سائيز_t Dst_سائيز_اندريون_لفظ,wchar_t _Val,سائيز_t Max_ڳڻپ);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,سائيز_t سائيز_اندريون_لفظ,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,سائيز_t سائيز_اندريون_لفظ);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,سائيز_t سائيز_اندريون_لفظ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,سائيز_t سائيز_4);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,سائيز_t سائيز_4,_locale_t _Locale);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو
