/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING_S
#define _INC_STRING_S

#ଅନ୍ତର୍ଭାଵ <string.h>

#ଯଦି defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

  _CRTIMP errno_t __cdecl _strset_s(ଅକ୍ଷର *_Dst,size_t _DstSize,ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ_2);
  _CRTIMP errno_t __cdecl _strerror_s(ଅକ୍ଷର *_Buf,size_t _SizeInBytes,ଅଚଳ ଅକ୍ଷର *Err_ସନ୍ଦେଶ);
  _CRTIMP errno_t __cdecl _strlwr_s(ଅକ୍ଷର *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _strlwr_s_l(ଅକ୍ଷର *_Str,size_t _Size,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(ଅକ୍ଷର *_Str,size_t _Size,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Val,size_t Max_ଗଣନା);
  _CRTIMP errno_t __cdecl _strupr_s(ଅକ୍ଷର *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _strupr_s_l(ଅକ୍ଷର *_Str,size_t _Size,_locale_t _Locale);
#ifndef _WSTRING_S_DEFINED
#define _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,ଅଚଳ wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ପୂର୍ଣ୍ଣସଂଖ୍ୟା Err_ଅଙ୍କ);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *_Buffer,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ wchar_t *Err_ସନ୍ଦେଶ);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,size_t Dst_Size_In_ଶବ୍ଦଗୁଡ଼ିକ,wchar_t _Val,size_t Max_ଗଣନା);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,size_t _Size,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
