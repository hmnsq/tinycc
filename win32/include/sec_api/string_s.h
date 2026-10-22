/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING_S
#define _INC_STRING_S

#অন্তর্ভাৱ <string.h>

#যদি defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
বাহ্য "C" {
#endif

  _CRTIMP errno_t __cdecl _strset_s(ৱর্ণ *_Dst,size_t _DstSize,পূর্ণাঙ্ক মান_2);
  _CRTIMP errno_t __cdecl _strerror_s(ৱর্ণ *_Buf,size_t _SizeInBytes,ধ্রুৱ ৱর্ণ *Err_বাৰ্তা);
  _CRTIMP errno_t __cdecl _strlwr_s(ৱর্ণ *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _strlwr_s_l(ৱর্ণ *_Str,size_t _Size,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(ৱর্ণ *_Str,size_t _Size,পূর্ণাঙ্ক _Val,size_t Max_গুনতি);
  _CRTIMP errno_t __cdecl _strupr_s(ৱর্ণ *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _strupr_s_l(ৱর্ণ *_Str,size_t _Size,_locale_t _Locale);
#ifndef _WSTRING_S_DEFINED
#define _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,ধ্রুৱ wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,size_t Size_In_শব্দগুলি,পূর্ণাঙ্ক Err_অঙ্ক);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *_Buffer,size_t Size_In_শব্দগুলি,ধ্রুৱ wchar_t *Err_বাৰ্তা);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,size_t Dst_Size_In_শব্দগুলি,wchar_t _Val,size_t Max_গুনতি);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,size_t Size_In_শব্দগুলি,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,size_t Size_In_শব্দগুলি);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,size_t Size_In_শব্দগুলি,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,size_t _Size,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
