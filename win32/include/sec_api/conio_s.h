/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_CONIO_S
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_CONIO_S

#ಅನ್ತರ್ಭಾವ <conio.h>

#ಆದರೆ defined(MINGW_HAS_SECURE_API)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP errno_t __cdecl _cgets_s(ಅಕ್ಷರ *ಬಫರ್_2,ಗಾತ್ರ_t ಗಾತ್ರ_5,ಗಾತ್ರ_t *ಗಾತ್ರ_Read);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cprintf_s(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cscanf_s(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cscanf_s_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vcprintf_s(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cprintf_s_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vcprintf_s_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,va_list _ArgList);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WCONIO_DEFINED_S
#ವ್ಯಾಖ್ಯಾನಿಸು _WCONIO_DEFINED_S
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *ಬಫರ್_2,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಗಾತ್ರ_t *ಗಾತ್ರ_Read);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwprintf_s(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwscanf_s(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwscanf_s_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vcwprintf_s(ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwprintf_s_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vcwprintf_s_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
