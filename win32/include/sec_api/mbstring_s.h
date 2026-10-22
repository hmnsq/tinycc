/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_MBSTRING_S
#define _INC_MBSTRING_S

#ضمن <mbstring.h>

#ܐܢ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
خارجي "C" {
#endif

#ifndef _MBSTRING_S_DEFINED
#define _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(unsigned حرف *_Dst,size_t _DstSizeInBytes,ثابت unsigned حرف *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(unsigned حرف *_Dst,size_t _DstSizeInBytes,ثابت unsigned حرف *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(unsigned حرف *_Dst,size_t _DstSizeInBytes,ثابت unsigned حرف *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(unsigned حرف *_Dst,size_t _DstSizeInBytes,ثابت unsigned حرف *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(unsigned حرف *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(unsigned حرف *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(unsigned حرف *_Dst,size_t _DstSizeInBytes,ثابت unsigned حرف *_Src,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(unsigned حرف *_Dst,size_t _DstSizeInBytes,ثابت unsigned حرف *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(unsigned حرف *_Dst,size_t _DstSizeInBytes,ثابت unsigned حرف *_Src,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(unsigned حرف *_Dst,size_t _DstSizeInBytes,ثابت unsigned حرف *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(unsigned حرف *_Dst,size_t _DstSizeInBytes,unsigned صحيح _Ch,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(unsigned حرف *_Dst,size_t _DstSizeInBytes,unsigned صحيح _Ch,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(unsigned حرف *_Dst,size_t _DstSizeInBytes,ثابت unsigned حرف *_Src,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(unsigned حرف *_Dst,size_t _DstSizeInBytes,ثابت unsigned حرف *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(unsigned حرف *_Dst,size_t _DstSizeInBytes,ثابت unsigned حرف *_Src,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(unsigned حرف *_Dst,size_t _DstSizeInBytes,ثابت unsigned حرف *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(unsigned حرف *_Dst,size_t _DstSizeInBytes,unsigned صحيح _Val,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(unsigned حرف *_Dst,size_t _DstSizeInBytes,unsigned صحيح _Val,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(unsigned حرف *_Dst,size_t _DstSizeInBytes,unsigned صحيح _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(unsigned حرف *_Dst,size_t _DstSizeInBytes,unsigned صحيح _Val,_locale_t _Locale);
  _CRTIMP unsigned حرف *__cdecl _mbstok_s(unsigned حرف *_Str,ثابت unsigned حرف *_Delim,unsigned حرف **_Context);
  _CRTIMP unsigned حرف *__cdecl _mbstok_s_l(unsigned حرف *_Str,ثابت unsigned حرف *_Delim,unsigned حرف **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(unsigned حرف *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(unsigned حرف *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(unsigned حرف *_Dst,size_t _DstSizeInBytes,صحيح *_PCopied,ثابت unsigned حرف *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(unsigned حرف *_Dst,size_t _DstSizeInBytes,صحيح *_PCopied,ثابت unsigned حرف *_Src,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
