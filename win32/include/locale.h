/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_LOCALE
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_LOCALE

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ಸೂಚನೆ pack(ತಳ್ಳು,_CRT_PACKING)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ಖಾಲಿ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು ಖಾಲಿ 0
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಖಾಲಿ ((ಶೂನ್ಯ *)0)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು LC_ALL 0
#ವ್ಯಾಖ್ಯಾನಿಸು LC_COLLATE 1
#ವ್ಯಾಖ್ಯಾನಿಸು LC_CTYPE 2
#ವ್ಯಾಖ್ಯಾನಿಸು LC_MONETARY 3
#ವ್ಯಾಖ್ಯಾನಿಸು LC_NUMERIC 4
#ವ್ಯಾಖ್ಯಾನಿಸು LC_ಸಮಯ 5

#ವ್ಯಾಖ್ಯಾನಿಸು LC_MIN LC_ALL
#ವ್ಯಾಖ್ಯಾನಿಸು LC_MAX LC_ಸಮಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _LCONV_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _LCONV_DEFINED
  ರಚನೆ lconv {
    ಅಕ್ಷರ *decimal_ಬಿಂದು;
    ಅಕ್ಷರ *thousands_sep;
    ಅಕ್ಷರ *grouping;
    ಅಕ್ಷರ *int_curr_ಚಿಹ್ನೆ;
    ಅಕ್ಷರ *currency_ಚಿಹ್ನೆ;
    ಅಕ್ಷರ *mon_decimal_ಬಿಂದು;
    ಅಕ್ಷರ *mon_thousands_sep;
    ಅಕ್ಷರ *mon_grouping;
    ಅಕ್ಷರ *ಧನಾತ್ಮಕ_sign;
    ಅಕ್ಷರ *negative_sign;
    ಅಕ್ಷರ int_frac_digits;
    ಅಕ್ಷರ frac_digits;
    ಅಕ್ಷರ p_cs_precedes;
    ಅಕ್ಷರ p_sep_by_space;
    ಅಕ್ಷರ n_cs_precedes;
    ಅಕ್ಷರ n_sep_by_space;
    ಅಕ್ಷರ p_sign_posn;
    ಅಕ್ಷರ n_sign_posn;
  };
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CONFIG_LOCALE_SWT
#ವ್ಯಾಖ್ಯಾನಿಸು _CONFIG_LOCALE_SWT

#ವ್ಯಾಖ್ಯಾನಿಸು ENABLE_ಪ್ರತಿ_THREAD_LOCALE 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು DISABLE_ಪ್ರತಿ_THREAD_LOCALE 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು ENABLE_ಪ್ರತಿ_THREAD_LOCALE_GLOBAL 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು DISABLE_ಪ್ರತಿ_THREAD_LOCALE_GLOBAL 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು ENABLE_ಪ್ರತಿ_THREAD_LOCALE_NEW 0x100
#ವ್ಯಾಖ್ಯಾನಿಸು DISABLE_ಪ್ರತಿ_THREAD_LOCALE_NEW 0x200

#ಆದರೆ_ಅಂತ್ಯ

  ಪೂರ್ಣಾಂಕ __cdecl _configthreadlocale(ಪೂರ್ಣಾಂಕ _Flag);
  ಅಕ್ಷರ *__cdecl setlocale(ಪೂರ್ಣಾಂಕ _Category,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Locale);
  _CRTIMP ರಚನೆ lconv *__cdecl localeconv(ಶೂನ್ಯ);
  _locale_t __cdecl _get_current_locale(ಶೂನ್ಯ);
  _locale_t __cdecl _create_locale(ಪೂರ್ಣಾಂಕ _Category,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Locale);
  ಶೂನ್ಯ __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(ಶೂನ್ಯ);
  _locale_t __cdecl __create_locale(ಪೂರ್ಣಾಂಕ _Category,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Locale);
  ಶೂನ್ಯ __cdecl __free_locale(_locale_t _Locale);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WLOCALE_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(ಪೂರ್ಣಾಂಕ _Category,ಸ್ಥಿರಾಂಕ wchar_t *_Locale);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ pack(ತೆಗೆ)
#ಆದರೆ_ಅಂತ್ಯ
