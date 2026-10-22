/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_STRING_S
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_STRING_S

#ಅನ್ತರ್ಭಾವ <string.h>

#ಆದರೆ defined(MINGW_HAS_SECURE_API)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP errno_t __cdecl _strset_s(ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ,ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ_2);
  _CRTIMP errno_t __cdecl _strerror_s(ಅಕ್ಷರ *_Buf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *Err_ಸಂದೇಶ);
  _CRTIMP errno_t __cdecl _strlwr_s(ಅಕ್ಷರ *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_5);
  _CRTIMP errno_t __cdecl _strlwr_s_l(ಅಕ್ಷರ *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_5,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(ಅಕ್ಷರ *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_5,ಪೂರ್ಣಾಂಕ _Val,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  _CRTIMP errno_t __cdecl _strupr_s(ಅಕ್ಷರ *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_5);
  _CRTIMP errno_t __cdecl _strupr_s_l(ಅಕ್ಷರ *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_5,_locale_t _Locale);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WSTRING_S_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,ಸ್ಥಿರಾಂಕ wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಪೂರ್ಣಾಂಕ Err_ಅಂಕೆ);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *ಬಫರ್_2,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ wchar_t *Err_ಸಂದೇಶ);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಪದಗಳು,wchar_t _Val,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_5);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_5,_locale_t _Locale);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
