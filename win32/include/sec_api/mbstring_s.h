/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_MBSTRING_S
#define _INC_MBSTRING_S

#અન્તર્ભાવ <mbstring.h>

#જો defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
બાહ્ય "C" {
#endif

#ifndef _MBSTRING_S_DEFINED
#define _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,અચલ unsigned અક્ષર *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,અચલ unsigned અક્ષર *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,અચલ unsigned અક્ષર *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,અચલ unsigned અક્ષર *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(unsigned અક્ષર *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(unsigned અક્ષર *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,અચલ unsigned અક્ષર *_Src,size_t Max_ગણતરી);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,અચલ unsigned અક્ષર *_Src,size_t Max_ગણતરી,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,અચલ unsigned અક્ષર *_Src,size_t Max_ગણતરી);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,અચલ unsigned અક્ષર *_Src,size_t Max_ગણતરી,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,unsigned પૂર્ણાંક _Ch,size_t Max_ગણતરી);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,unsigned પૂર્ણાંક _Ch,size_t Max_ગણતરી,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,અચલ unsigned અક્ષર *_Src,size_t Max_ગણતરી);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,અચલ unsigned અક્ષર *_Src,size_t Max_ગણતરી,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,અચલ unsigned અક્ષર *_Src,size_t Max_ગણતરી);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,અચલ unsigned અક્ષર *_Src,size_t Max_ગણતરી,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,unsigned પૂર્ણાંક _Val,size_t Max_ગણતરી);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,unsigned પૂર્ણાંક _Val,size_t Max_ગણતરી,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,unsigned પૂર્ણાંક _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,unsigned પૂર્ણાંક _Val,_locale_t _Locale);
  _CRTIMP unsigned અક્ષર *__cdecl _mbstok_s(unsigned અક્ષર *_Str,અચલ unsigned અક્ષર *_Delim,unsigned અક્ષર **_Context);
  _CRTIMP unsigned અક્ષર *__cdecl _mbstok_s_l(unsigned અક્ષર *_Str,અચલ unsigned અક્ષર *_Delim,unsigned અક્ષર **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(unsigned અક્ષર *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(unsigned અક્ષર *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,પૂર્ણાંક *_PCopied,અચલ unsigned અક્ષર *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(unsigned અક્ષર *_Dst,size_t _DstSizeInBytes,પૂર્ણાંક *_PCopied,અચલ unsigned અક્ષર *_Src,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
