/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_MBSTRING_S
#وصف_ڪريو _INC_MBSTRING_S

#ضمن <mbstring.h>

#إذا defined(MINGW_HAS_SECURE_API)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _MBSTRING_S_DEFINED
#وصف_ڪريو _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,ثابت بنانشان حرف *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,ثابت بنانشان حرف *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,ثابت بنانشان حرف *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,ثابت بنانشان حرف *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(بنانشان حرف *_Str,سائيز_t سائيز_اندريون_بائيٽون);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(بنانشان حرف *_Str,سائيز_t سائيز_اندريون_بائيٽون,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,ثابت بنانشان حرف *_Src,سائيز_t Max_ڳڻپ);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,ثابت بنانشان حرف *_Src,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,ثابت بنانشان حرف *_Src,سائيز_t Max_ڳڻپ);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,ثابت بنانشان حرف *_Src,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,بنانشان صحيح _Ch,سائيز_t Max_ڳڻپ);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,بنانشان صحيح _Ch,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,ثابت بنانشان حرف *_Src,سائيز_t Max_ڳڻپ);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,ثابت بنانشان حرف *_Src,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,ثابت بنانشان حرف *_Src,سائيز_t Max_ڳڻپ);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,ثابت بنانشان حرف *_Src,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,بنانشان صحيح _Val,سائيز_t Max_ڳڻپ);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,بنانشان صحيح _Val,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,بنانشان صحيح _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,بنانشان صحيح _Val,_locale_t _Locale);
  _CRTIMP بنانشان حرف *__cdecl _mbstok_s(بنانشان حرف *_Str,ثابت بنانشان حرف *_Delim,بنانشان حرف **_Context);
  _CRTIMP بنانشان حرف *__cdecl _mbstok_s_l(بنانشان حرف *_Str,ثابت بنانشان حرف *_Delim,بنانشان حرف **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(بنانشان حرف *_Str,سائيز_t سائيز_اندريون_بائيٽون);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(بنانشان حرف *_Str,سائيز_t سائيز_اندريون_بائيٽون,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,صحيح *_PCopied,ثابت بنانشان حرف *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(بنانشان حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,صحيح *_PCopied,ثابت بنانشان حرف *_Src,_locale_t _Locale);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#جيڪڏهن_پورو
#جيڪڏهن_پورو
