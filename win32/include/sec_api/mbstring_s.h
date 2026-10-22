/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_MBSTRING_S
#define _INC_MBSTRING_S

#ಅನ್ತರ್ಭಾವ <mbstring.h>

#ಯದಿ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

#ifndef _MBSTRING_S_DEFINED
#define _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,ಧ್ರುವ unsigned ವರ್ಣ *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,ಧ್ರುವ unsigned ವರ್ಣ *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,ಧ್ರುವ unsigned ವರ್ಣ *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,ಧ್ರುವ unsigned ವರ್ಣ *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(unsigned ವರ್ಣ *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(unsigned ವರ್ಣ *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,ಧ್ರುವ unsigned ವರ್ಣ *_Src,size_t Max_ಎಣಿಕೆ);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,ಧ್ರುವ unsigned ವರ್ಣ *_Src,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,ಧ್ರುವ unsigned ವರ್ಣ *_Src,size_t Max_ಎಣಿಕೆ);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,ಧ್ರುವ unsigned ವರ್ಣ *_Src,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,unsigned ಪೂರ್ಣಾಙ್ಕ _Ch,size_t Max_ಎಣಿಕೆ);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,unsigned ಪೂರ್ಣಾಙ್ಕ _Ch,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,ಧ್ರುವ unsigned ವರ್ಣ *_Src,size_t Max_ಎಣಿಕೆ);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,ಧ್ರುವ unsigned ವರ್ಣ *_Src,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,ಧ್ರುವ unsigned ವರ್ಣ *_Src,size_t Max_ಎಣಿಕೆ);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,ಧ್ರುವ unsigned ವರ್ಣ *_Src,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,unsigned ಪೂರ್ಣಾಙ್ಕ _Val,size_t Max_ಎಣಿಕೆ);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,unsigned ಪೂರ್ಣಾಙ್ಕ _Val,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,unsigned ಪೂರ್ಣಾಙ್ಕ _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,unsigned ಪೂರ್ಣಾಙ್ಕ _Val,_locale_t _Locale);
  _CRTIMP unsigned ವರ್ಣ *__cdecl _mbstok_s(unsigned ವರ್ಣ *_Str,ಧ್ರುವ unsigned ವರ್ಣ *_Delim,unsigned ವರ್ಣ **_Context);
  _CRTIMP unsigned ವರ್ಣ *__cdecl _mbstok_s_l(unsigned ವರ್ಣ *_Str,ಧ್ರುವ unsigned ವರ್ಣ *_Delim,unsigned ವರ್ಣ **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(unsigned ವರ್ಣ *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(unsigned ವರ್ಣ *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,ಪೂರ್ಣಾಙ್ಕ *_PCopied,ಧ್ರುವ unsigned ವರ್ಣ *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(unsigned ವರ್ಣ *_Dst,size_t _DstSizeInBytes,ಪೂರ್ಣಾಙ್ಕ *_PCopied,ಧ್ರುವ unsigned ವರ್ಣ *_Src,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
