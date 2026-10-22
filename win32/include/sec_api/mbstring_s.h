/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_MBSTRING_S
#define _INC_MBSTRING_S

#ଅନ୍ତର୍ଭାଵ <mbstring.h>

#ଯଦି defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

#ifndef _MBSTRING_S_DEFINED
#define _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,ଅଚଳ unsigned ଅକ୍ଷର *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,ଅଚଳ unsigned ଅକ୍ଷର *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,ଅଚଳ unsigned ଅକ୍ଷର *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,ଅଚଳ unsigned ଅକ୍ଷର *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(unsigned ଅକ୍ଷର *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(unsigned ଅକ୍ଷର *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,ଅଚଳ unsigned ଅକ୍ଷର *_Src,size_t Max_ଗଣନା);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,ଅଚଳ unsigned ଅକ୍ଷର *_Src,size_t Max_ଗଣନା,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,ଅଚଳ unsigned ଅକ୍ଷର *_Src,size_t Max_ଗଣନା);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,ଅଚଳ unsigned ଅକ୍ଷର *_Src,size_t Max_ଗଣନା,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Ch,size_t Max_ଗଣନା);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Ch,size_t Max_ଗଣନା,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,ଅଚଳ unsigned ଅକ୍ଷର *_Src,size_t Max_ଗଣନା);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,ଅଚଳ unsigned ଅକ୍ଷର *_Src,size_t Max_ଗଣନା,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,ଅଚଳ unsigned ଅକ୍ଷର *_Src,size_t Max_ଗଣନା);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,ଅଚଳ unsigned ଅକ୍ଷର *_Src,size_t Max_ଗଣନା,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Val,size_t Max_ଗଣନା);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Val,size_t Max_ଗଣନା,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Val,_locale_t _Locale);
  _CRTIMP unsigned ଅକ୍ଷର *__cdecl _mbstok_s(unsigned ଅକ୍ଷର *_Str,ଅଚଳ unsigned ଅକ୍ଷର *_Delim,unsigned ଅକ୍ଷର **_Context);
  _CRTIMP unsigned ଅକ୍ଷର *__cdecl _mbstok_s_l(unsigned ଅକ୍ଷର *_Str,ଅଚଳ unsigned ଅକ୍ଷର *_Delim,unsigned ଅକ୍ଷର **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(unsigned ଅକ୍ଷର *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(unsigned ଅକ୍ଷର *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_PCopied,ଅଚଳ unsigned ଅକ୍ଷର *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(unsigned ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_PCopied,ଅଚଳ unsigned ଅକ୍ଷର *_Src,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
