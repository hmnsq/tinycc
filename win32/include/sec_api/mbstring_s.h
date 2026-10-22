/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_MBSTRING_S
#define _INC_MBSTRING_S

#include <mbstring.h>

#ถ้า defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _MBSTRING_S_DEFINED
#define _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(unsigned var_na *_Dst,size_t _DstSizeInBytes,const unsigned var_na *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(unsigned var_na *_Dst,size_t _DstSizeInBytes,const unsigned var_na *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(unsigned var_na *_Dst,size_t _DstSizeInBytes,const unsigned var_na *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(unsigned var_na *_Dst,size_t _DstSizeInBytes,const unsigned var_na *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(unsigned var_na *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(unsigned var_na *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(unsigned var_na *_Dst,size_t _DstSizeInBytes,const unsigned var_na *_Src,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(unsigned var_na *_Dst,size_t _DstSizeInBytes,const unsigned var_na *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(unsigned var_na *_Dst,size_t _DstSizeInBytes,const unsigned var_na *_Src,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(unsigned var_na *_Dst,size_t _DstSizeInBytes,const unsigned var_na *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(unsigned var_na *_Dst,size_t _DstSizeInBytes,unsigned จำนวนเต็ม _Ch,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(unsigned var_na *_Dst,size_t _DstSizeInBytes,unsigned จำนวนเต็ม _Ch,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(unsigned var_na *_Dst,size_t _DstSizeInBytes,const unsigned var_na *_Src,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(unsigned var_na *_Dst,size_t _DstSizeInBytes,const unsigned var_na *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(unsigned var_na *_Dst,size_t _DstSizeInBytes,const unsigned var_na *_Src,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(unsigned var_na *_Dst,size_t _DstSizeInBytes,const unsigned var_na *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(unsigned var_na *_Dst,size_t _DstSizeInBytes,unsigned จำนวนเต็ม _Val,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(unsigned var_na *_Dst,size_t _DstSizeInBytes,unsigned จำนวนเต็ม _Val,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(unsigned var_na *_Dst,size_t _DstSizeInBytes,unsigned จำนวนเต็ม _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(unsigned var_na *_Dst,size_t _DstSizeInBytes,unsigned จำนวนเต็ม _Val,_locale_t _Locale);
  _CRTIMP unsigned var_na *__cdecl _mbstok_s(unsigned var_na *_Str,const unsigned var_na *_Delim,unsigned var_na **_Context);
  _CRTIMP unsigned var_na *__cdecl _mbstok_s_l(unsigned var_na *_Str,const unsigned var_na *_Delim,unsigned var_na **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(unsigned var_na *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(unsigned var_na *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(unsigned var_na *_Dst,size_t _DstSizeInBytes,จำนวนเต็ม *_PCopied,const unsigned var_na *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(unsigned var_na *_Dst,size_t _DstSizeInBytes,จำนวนเต็ม *_PCopied,const unsigned var_na *_Src,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
