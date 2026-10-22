/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_MBSTRING_S
#define _INC_MBSTRING_S

#অন্তর্ভাৱ <mbstring.h>

#যদি defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
বাহ্য "C" {
#endif

#ifndef _MBSTRING_S_DEFINED
#define _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,ধ্রুৱ unsigned ৱর্ণ *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,ধ্রুৱ unsigned ৱর্ণ *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,ধ্রুৱ unsigned ৱর্ণ *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,ধ্রুৱ unsigned ৱর্ণ *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(unsigned ৱর্ণ *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(unsigned ৱর্ণ *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,ধ্রুৱ unsigned ৱর্ণ *_Src,size_t Max_গুনতি);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,ধ্রুৱ unsigned ৱর্ণ *_Src,size_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,ধ্রুৱ unsigned ৱর্ণ *_Src,size_t Max_গুনতি);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,ধ্রুৱ unsigned ৱর্ণ *_Src,size_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,unsigned পূর্ণাঙ্ক _Ch,size_t Max_গুনতি);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,unsigned পূর্ণাঙ্ক _Ch,size_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,ধ্রুৱ unsigned ৱর্ণ *_Src,size_t Max_গুনতি);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,ধ্রুৱ unsigned ৱর্ণ *_Src,size_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,ধ্রুৱ unsigned ৱর্ণ *_Src,size_t Max_গুনতি);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,ধ্রুৱ unsigned ৱর্ণ *_Src,size_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,unsigned পূর্ণাঙ্ক _Val,size_t Max_গুনতি);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,unsigned পূর্ণাঙ্ক _Val,size_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,unsigned পূর্ণাঙ্ক _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,unsigned পূর্ণাঙ্ক _Val,_locale_t _Locale);
  _CRTIMP unsigned ৱর্ণ *__cdecl _mbstok_s(unsigned ৱর্ণ *_Str,ধ্রুৱ unsigned ৱর্ণ *_Delim,unsigned ৱর্ণ **_Context);
  _CRTIMP unsigned ৱর্ণ *__cdecl _mbstok_s_l(unsigned ৱর্ণ *_Str,ধ্রুৱ unsigned ৱর্ণ *_Delim,unsigned ৱর্ণ **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(unsigned ৱর্ণ *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(unsigned ৱর্ণ *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,পূর্ণাঙ্ক *_PCopied,ধ্রুৱ unsigned ৱর্ণ *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(unsigned ৱর্ণ *_Dst,size_t _DstSizeInBytes,পূর্ণাঙ্ক *_PCopied,ধ্রুৱ unsigned ৱর্ণ *_Src,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
