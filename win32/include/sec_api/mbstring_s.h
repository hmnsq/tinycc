/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_MBSTRING_S
#تعریف_کن _INC_MBSTRING_S

#ضمن <mbstring.h>

#إذا defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده _MBSTRING_S_DEFINED
#تعریف_کن _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,ثابت بیعلامت حرف *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,ثابت بیعلامت حرف *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,ثابت بیعلامت حرف *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,ثابت بیعلامت حرف *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(بیعلامت حرف *_Str,اندازه_t اندازه_درون_بایتها);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(بیعلامت حرف *_Str,اندازه_t اندازه_درون_بایتها,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,ثابت بیعلامت حرف *_Src,اندازه_t Max_شمار);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,ثابت بیعلامت حرف *_Src,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,ثابت بیعلامت حرف *_Src,اندازه_t Max_شمار);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,ثابت بیعلامت حرف *_Src,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,بیعلامت صحيح _Ch,اندازه_t Max_شمار);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,بیعلامت صحيح _Ch,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,ثابت بیعلامت حرف *_Src,اندازه_t Max_شمار);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,ثابت بیعلامت حرف *_Src,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,ثابت بیعلامت حرف *_Src,اندازه_t Max_شمار);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,ثابت بیعلامت حرف *_Src,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,بیعلامت صحيح _Val,اندازه_t Max_شمار);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,بیعلامت صحيح _Val,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,بیعلامت صحيح _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,بیعلامت صحيح _Val,_locale_t _Locale);
  _CRTIMP بیعلامت حرف *__cdecl _mbstok_s(بیعلامت حرف *_Str,ثابت بیعلامت حرف *_Delim,بیعلامت حرف **_Context);
  _CRTIMP بیعلامت حرف *__cdecl _mbstok_s_l(بیعلامت حرف *_Str,ثابت بیعلامت حرف *_Delim,بیعلامت حرف **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(بیعلامت حرف *_Str,اندازه_t اندازه_درون_بایتها);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(بیعلامت حرف *_Str,اندازه_t اندازه_درون_بایتها,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,صحيح *_PCopied,ثابت بیعلامت حرف *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(بیعلامت حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,صحيح *_PCopied,ثابت بیعلامت حرف *_Src,_locale_t _Locale);
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#پایان_اگر
#پایان_اگر
