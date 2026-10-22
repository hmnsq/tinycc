/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_MBSTRING_S
#define _INC_MBSTRING_S

#অন্তর্ভাব <mbstring.h>

#যদি defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
বাহ্যিক "C" {
#endif

#ifndef _MBSTRING_S_DEFINED
#define _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,ধ্রুবক unsigned অক্ষর *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,ধ্রুবক unsigned অক্ষর *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,ধ্রুবক unsigned অক্ষর *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,ধ্রুবক unsigned অক্ষর *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(unsigned অক্ষর *_Str,আকার_t আকার_In_Bytes);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(unsigned অক্ষর *_Str,আকার_t আকার_In_Bytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,ধ্রুবক unsigned অক্ষর *_Src,আকার_t Max_গুনতি);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,ধ্রুবক unsigned অক্ষর *_Src,আকার_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,ধ্রুবক unsigned অক্ষর *_Src,আকার_t Max_গুনতি);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,ধ্রুবক unsigned অক্ষর *_Src,আকার_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,unsigned পূর্ণসংখ্যা _Ch,আকার_t Max_গুনতি);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,unsigned পূর্ণসংখ্যা _Ch,আকার_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,ধ্রুবক unsigned অক্ষর *_Src,আকার_t Max_গুনতি);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,ধ্রুবক unsigned অক্ষর *_Src,আকার_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,ধ্রুবক unsigned অক্ষর *_Src,আকার_t Max_গুনতি);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,ধ্রুবক unsigned অক্ষর *_Src,আকার_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,unsigned পূর্ণসংখ্যা _Val,আকার_t Max_গুনতি);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,unsigned পূর্ণসংখ্যা _Val,আকার_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,unsigned পূর্ণসংখ্যা _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,unsigned পূর্ণসংখ্যা _Val,_locale_t _Locale);
  _CRTIMP unsigned অক্ষর *__cdecl _mbstok_s(unsigned অক্ষর *_Str,ধ্রুবক unsigned অক্ষর *_Delim,unsigned অক্ষর **_Context);
  _CRTIMP unsigned অক্ষর *__cdecl _mbstok_s_l(unsigned অক্ষর *_Str,ধ্রুবক unsigned অক্ষর *_Delim,unsigned অক্ষর **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(unsigned অক্ষর *_Str,আকার_t আকার_In_Bytes);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(unsigned অক্ষর *_Str,আকার_t আকার_In_Bytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,পূর্ণসংখ্যা *_PCopied,ধ্রুবক unsigned অক্ষর *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(unsigned অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,পূর্ণসংখ্যা *_PCopied,ধ্রুবক unsigned অক্ষর *_Src,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
