/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_MBSTRING_S
#تعریف_کړه _INC_MBSTRING_S

#ضمن <mbstring.h>

#إذا defined(MINGW_HAS_SECURE_API)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی _MBSTRING_S_DEFINED
#تعریف_کړه _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,ثابت بینښه حرف *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,ثابت بینښه حرف *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,ثابت بینښه حرف *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,ثابت بینښه حرف *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(بینښه حرف *_Str,اندازه_t اندازه_دننه_بایټونه);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(بینښه حرف *_Str,اندازه_t اندازه_دننه_بایټونه,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,ثابت بینښه حرف *_Src,اندازه_t Max_شمېر);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,ثابت بینښه حرف *_Src,اندازه_t Max_شمېر,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,ثابت بینښه حرف *_Src,اندازه_t Max_شمېر);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,ثابت بینښه حرف *_Src,اندازه_t Max_شمېر,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,بینښه صحيح _Ch,اندازه_t Max_شمېر);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,بینښه صحيح _Ch,اندازه_t Max_شمېر,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,ثابت بینښه حرف *_Src,اندازه_t Max_شمېر);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,ثابت بینښه حرف *_Src,اندازه_t Max_شمېر,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,ثابت بینښه حرف *_Src,اندازه_t Max_شمېر);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,ثابت بینښه حرف *_Src,اندازه_t Max_شمېر,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,بینښه صحيح _Val,اندازه_t Max_شمېر);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,بینښه صحيح _Val,اندازه_t Max_شمېر,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,بینښه صحيح _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,بینښه صحيح _Val,_locale_t _Locale);
  _CRTIMP بینښه حرف *__cdecl _mbstok_s(بینښه حرف *_Str,ثابت بینښه حرف *_Delim,بینښه حرف **_Context);
  _CRTIMP بینښه حرف *__cdecl _mbstok_s_l(بینښه حرف *_Str,ثابت بینښه حرف *_Delim,بینښه حرف **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(بینښه حرف *_Str,اندازه_t اندازه_دننه_بایټونه);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(بینښه حرف *_Str,اندازه_t اندازه_دننه_بایټونه,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,صحيح *_PCopied,ثابت بینښه حرف *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(بینښه حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,صحيح *_PCopied,ثابت بینښه حرف *_Src,_locale_t _Locale);
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#د_که_پای
#د_که_پای
