/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING_S
#define _INC_STRING_S

#অন্তর্ভাব <string.h>

#যদি defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
বাহ্যিক "C" {
#endif

  _CRTIMP errno_t __cdecl _strset_s(অক্ষর *_Dst,আকার_t Dst_আকার,পূর্ণসংখ্যা মান_2);
  _CRTIMP errno_t __cdecl _strerror_s(অক্ষর *_Buf,আকার_t আকার_In_Bytes,ধ্রুবক অক্ষর *Err_বার্তা);
  _CRTIMP errno_t __cdecl _strlwr_s(অক্ষর *_Str,আকার_t আকার_5);
  _CRTIMP errno_t __cdecl _strlwr_s_l(অক্ষর *_Str,আকার_t আকার_5,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(অক্ষর *_Str,আকার_t আকার_5,পূর্ণসংখ্যা _Val,আকার_t Max_গুনতি);
  _CRTIMP errno_t __cdecl _strupr_s(অক্ষর *_Str,আকার_t আকার_5);
  _CRTIMP errno_t __cdecl _strupr_s_l(অক্ষর *_Str,আকার_t আকার_5,_locale_t _Locale);
#ifndef _WSTRING_S_DEFINED
#define _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,ধ্রুবক wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,আকার_t আকার_In_শব্দগুলি,পূর্ণসংখ্যা Err_অঙ্ক);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *বাফার_2,আকার_t আকার_In_শব্দগুলি,ধ্রুবক wchar_t *Err_বার্তা);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,আকার_t Dst_আকার_In_শব্দগুলি,wchar_t _Val,আকার_t Max_গুনতি);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,আকার_t আকার_In_শব্দগুলি,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,আকার_t আকার_In_শব্দগুলি);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,আকার_t আকার_In_শব্দগুলি,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,আকার_t আকার_5);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,আকার_t আকার_5,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
