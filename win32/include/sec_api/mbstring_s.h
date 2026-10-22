/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _INC_MBSTRING_S
#تعریف_کرو _INC_MBSTRING_S

#ضمن <mbstring.h>

#إذا defined(MINGW_HAS_SECURE_API)

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف _MBSTRING_S_DEFINED
#تعریف_کرو _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,ثابت بنانشانی حرف *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,ثابت بنانشانی حرف *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,ثابت بنانشانی حرف *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,ثابت بنانشانی حرف *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(بنانشانی حرف *_Str,ناپ_t ناپ_وچ_بائٹاں);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(بنانشانی حرف *_Str,ناپ_t ناپ_وچ_بائٹاں,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,ثابت بنانشانی حرف *_Src,ناپ_t Max_گنتی);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,ثابت بنانشانی حرف *_Src,ناپ_t Max_گنتی,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,ثابت بنانشانی حرف *_Src,ناپ_t Max_گنتی);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,ثابت بنانشانی حرف *_Src,ناپ_t Max_گنتی,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,بنانشانی صحيح _Ch,ناپ_t Max_گنتی);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,بنانشانی صحيح _Ch,ناپ_t Max_گنتی,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,ثابت بنانشانی حرف *_Src,ناپ_t Max_گنتی);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,ثابت بنانشانی حرف *_Src,ناپ_t Max_گنتی,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,ثابت بنانشانی حرف *_Src,ناپ_t Max_گنتی);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,ثابت بنانشانی حرف *_Src,ناپ_t Max_گنتی,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,بنانشانی صحيح _Val,ناپ_t Max_گنتی);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,بنانشانی صحيح _Val,ناپ_t Max_گنتی,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,بنانشانی صحيح _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,بنانشانی صحيح _Val,_locale_t _Locale);
  _CRTIMP بنانشانی حرف *__cdecl _mbstok_s(بنانشانی حرف *_Str,ثابت بنانشانی حرف *_Delim,بنانشانی حرف **_Context);
  _CRTIMP بنانشانی حرف *__cdecl _mbstok_s_l(بنانشانی حرف *_Str,ثابت بنانشانی حرف *_Delim,بنانشانی حرف **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(بنانشانی حرف *_Str,ناپ_t ناپ_وچ_بائٹاں);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(بنانشانی حرف *_Str,ناپ_t ناپ_وچ_بائٹاں,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,صحيح *_PCopied,ثابت بنانشانی حرف *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(بنانشانی حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,صحيح *_PCopied,ثابت بنانشانی حرف *_Src,_locale_t _Locale);
#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#جے_انت
#جے_انت
