/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _INC_STRING_S
#تعریف_کرو _INC_STRING_S

#ضمن <string.h>

#إذا defined(MINGW_HAS_SECURE_API)

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

  _CRTIMP errno_t __cdecl _strset_s(حرف *_Dst,ناپ_t Dst_ناپ,صحيح قدر_2);
  _CRTIMP errno_t __cdecl _strerror_s(حرف *_Buf,ناپ_t ناپ_وچ_بائٹاں,ثابت حرف *Err_پیغام);
  _CRTIMP errno_t __cdecl _strlwr_s(حرف *_Str,ناپ_t ناپ_4);
  _CRTIMP errno_t __cdecl _strlwr_s_l(حرف *_Str,ناپ_t ناپ_4,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(حرف *_Str,ناپ_t ناپ_4,صحيح _Val,ناپ_t Max_گنتی);
  _CRTIMP errno_t __cdecl _strupr_s(حرف *_Str,ناپ_t ناپ_4);
  _CRTIMP errno_t __cdecl _strupr_s_l(حرف *_Str,ناپ_t ناپ_4,_locale_t _Locale);
#جے_بنا_تعریف _WSTRING_S_DEFINED
#تعریف_کرو _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,ثابت wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,ناپ_t ناپ_وچ_الفاظ,صحيح Err_عدد);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *بفر_2,ناپ_t ناپ_وچ_الفاظ,ثابت wchar_t *Err_پیغام);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,ناپ_t Dst_ناپ_وچ_الفاظ,wchar_t _Val,ناپ_t Max_گنتی);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,ناپ_t ناپ_وچ_الفاظ,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,ناپ_t ناپ_وچ_الفاظ);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,ناپ_t ناپ_وچ_الفاظ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,ناپ_t ناپ_4);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,ناپ_t ناپ_4,_locale_t _Locale);
#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت
#جے_انت
#جے_انت
