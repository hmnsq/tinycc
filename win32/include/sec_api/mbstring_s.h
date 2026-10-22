/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_MBSTRING_S
#define _INC_MBSTRING_S

#அந்தர்பாவ <mbstring.h>

#எனில் defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
வெளி "C" {
#endif

#ifndef _MBSTRING_S_DEFINED
#define _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,மாறிலி unsigned எழுத்து *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,மாறிலி unsigned எழுத்து *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,மாறிலி unsigned எழுத்து *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,மாறிலி unsigned எழுத்து *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(unsigned எழுத்து *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(unsigned எழுத்து *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,மாறிலி unsigned எழுத்து *_Src,size_t Max_மொத்தம்);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,மாறிலி unsigned எழுத்து *_Src,size_t Max_மொத்தம்,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,மாறிலி unsigned எழுத்து *_Src,size_t Max_மொத்தம்);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,மாறிலி unsigned எழுத்து *_Src,size_t Max_மொத்தம்,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,unsigned முழு _Ch,size_t Max_மொத்தம்);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,unsigned முழு _Ch,size_t Max_மொத்தம்,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,மாறிலி unsigned எழுத்து *_Src,size_t Max_மொத்தம்);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,மாறிலி unsigned எழுத்து *_Src,size_t Max_மொத்தம்,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,மாறிலி unsigned எழுத்து *_Src,size_t Max_மொத்தம்);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,மாறிலி unsigned எழுத்து *_Src,size_t Max_மொத்தம்,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,unsigned முழு _Val,size_t Max_மொத்தம்);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,unsigned முழு _Val,size_t Max_மொத்தம்,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,unsigned முழு _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,unsigned முழு _Val,_locale_t _Locale);
  _CRTIMP unsigned எழுத்து *__cdecl _mbstok_s(unsigned எழுத்து *_Str,மாறிலி unsigned எழுத்து *_Delim,unsigned எழுத்து **_Context);
  _CRTIMP unsigned எழுத்து *__cdecl _mbstok_s_l(unsigned எழுத்து *_Str,மாறிலி unsigned எழுத்து *_Delim,unsigned எழுத்து **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(unsigned எழுத்து *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(unsigned எழுத்து *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,முழு *_PCopied,மாறிலி unsigned எழுத்து *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(unsigned எழுத்து *_Dst,size_t _DstSizeInBytes,முழு *_PCopied,மாறிலி unsigned எழுத்து *_Src,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
