/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING_S
#define _INC_STRING_S

#ಅನ್ತರ್ಭಾವ <string.h>

#ಯದಿ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

  _CRTIMP errno_t __cdecl _strset_s(ವರ್ಣ *_Dst,size_t _DstSize,ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ_2);
  _CRTIMP errno_t __cdecl _strerror_s(ವರ್ಣ *_Buf,size_t _SizeInBytes,ಧ್ರುವ ವರ್ಣ *Err_ಸಂದೇಶ);
  _CRTIMP errno_t __cdecl _strlwr_s(ವರ್ಣ *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _strlwr_s_l(ವರ್ಣ *_Str,size_t _Size,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(ವರ್ಣ *_Str,size_t _Size,ಪೂರ್ಣಾಙ್ಕ _Val,size_t Max_ಎಣಿಕೆ);
  _CRTIMP errno_t __cdecl _strupr_s(ವರ್ಣ *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _strupr_s_l(ವರ್ಣ *_Str,size_t _Size,_locale_t _Locale);
#ifndef _WSTRING_S_DEFINED
#define _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,ಧ್ರುವ wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,size_t Size_In_ಪದಗಳು,ಪೂರ್ಣಾಙ್ಕ Err_ಅಂಕೆ);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *_Buffer,size_t Size_In_ಪದಗಳು,ಧ್ರುವ wchar_t *Err_ಸಂದೇಶ);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,size_t Dst_Size_In_ಪದಗಳು,wchar_t _Val,size_t Max_ಎಣಿಕೆ);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,size_t Size_In_ಪದಗಳು,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,size_t Size_In_ಪದಗಳು);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,size_t Size_In_ಪದಗಳು,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,size_t _Size,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
