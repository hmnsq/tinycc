/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_MBSTRING_S
#define _INC_MBSTRING_S

#شامل <mbstring.h>

#اگر defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
بیرونی "C" {
#endif

#ifndef _MBSTRING_S_DEFINED
#define _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(unsigned نویسه *_Dst,size_t _DstSizeInBytes,ثابت unsigned نویسه *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(unsigned نویسه *_Dst,size_t _DstSizeInBytes,ثابت unsigned نویسه *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(unsigned نویسه *_Dst,size_t _DstSizeInBytes,ثابت unsigned نویسه *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(unsigned نویسه *_Dst,size_t _DstSizeInBytes,ثابت unsigned نویسه *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(unsigned نویسه *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(unsigned نویسه *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(unsigned نویسه *_Dst,size_t _DstSizeInBytes,ثابت unsigned نویسه *_Src,size_t Max_شمار);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(unsigned نویسه *_Dst,size_t _DstSizeInBytes,ثابت unsigned نویسه *_Src,size_t Max_شمار,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(unsigned نویسه *_Dst,size_t _DstSizeInBytes,ثابت unsigned نویسه *_Src,size_t Max_شمار);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(unsigned نویسه *_Dst,size_t _DstSizeInBytes,ثابت unsigned نویسه *_Src,size_t Max_شمار,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(unsigned نویسه *_Dst,size_t _DstSizeInBytes,unsigned صحیح _Ch,size_t Max_شمار);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(unsigned نویسه *_Dst,size_t _DstSizeInBytes,unsigned صحیح _Ch,size_t Max_شمار,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(unsigned نویسه *_Dst,size_t _DstSizeInBytes,ثابت unsigned نویسه *_Src,size_t Max_شمار);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(unsigned نویسه *_Dst,size_t _DstSizeInBytes,ثابت unsigned نویسه *_Src,size_t Max_شمار,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(unsigned نویسه *_Dst,size_t _DstSizeInBytes,ثابت unsigned نویسه *_Src,size_t Max_شمار);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(unsigned نویسه *_Dst,size_t _DstSizeInBytes,ثابت unsigned نویسه *_Src,size_t Max_شمار,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(unsigned نویسه *_Dst,size_t _DstSizeInBytes,unsigned صحیح _Val,size_t Max_شمار);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(unsigned نویسه *_Dst,size_t _DstSizeInBytes,unsigned صحیح _Val,size_t Max_شمار,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(unsigned نویسه *_Dst,size_t _DstSizeInBytes,unsigned صحیح _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(unsigned نویسه *_Dst,size_t _DstSizeInBytes,unsigned صحیح _Val,_locale_t _Locale);
  _CRTIMP unsigned نویسه *__cdecl _mbstok_s(unsigned نویسه *_Str,ثابت unsigned نویسه *_Delim,unsigned نویسه **_Context);
  _CRTIMP unsigned نویسه *__cdecl _mbstok_s_l(unsigned نویسه *_Str,ثابت unsigned نویسه *_Delim,unsigned نویسه **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(unsigned نویسه *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(unsigned نویسه *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(unsigned نویسه *_Dst,size_t _DstSizeInBytes,صحیح *_PCopied,ثابت unsigned نویسه *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(unsigned نویسه *_Dst,size_t _DstSizeInBytes,صحیح *_PCopied,ثابت unsigned نویسه *_Src,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
