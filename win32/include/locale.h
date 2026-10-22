/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_LOCALE
#define _INC_LOCALE

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#pragma pack(ತಳ್ಳು,_CRT_PACKING)

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

#ifndef ರಿಕ್ತ
#ifdef __cplusplus
#define ರಿಕ್ತ 0
#ಅನ್ಯಥಾ
#define ರಿಕ್ತ ((ಶೂನ್ಯ *)0)
#endif
#endif

#define LC_ALL 0
#define LC_COLLATE 1
#define LC_CTYPE 2
#define LC_MONETARY 3
#define LC_NUMERIC 4
#define LC_TIME 5

#define LC_MIN LC_ALL
#define LC_MAX LC_TIME

#ifndef _LCONV_DEFINED
#define _LCONV_DEFINED
  ಸಂರಚನಾ lconv {
    ವರ್ಣ *decimal_point;
    ವರ್ಣ *thousands_sep;
    ವರ್ಣ *grouping;
    ವರ್ಣ *int_curr_ಚಿಹ್ನೆ;
    ವರ್ಣ *currency_ಚಿಹ್ನೆ;
    ವರ್ಣ *mon_decimal_point;
    ವರ್ಣ *mon_thousands_sep;
    ವರ್ಣ *mon_grouping;
    ವರ್ಣ *positive_sign;
    ವರ್ಣ *negative_sign;
    ವರ್ಣ int_frac_digits;
    ವರ್ಣ frac_digits;
    ವರ್ಣ p_cs_precedes;
    ವರ್ಣ p_sep_by_space;
    ವರ್ಣ n_cs_precedes;
    ವರ್ಣ n_sep_by_space;
    ವರ್ಣ p_sign_posn;
    ವರ್ಣ n_sign_posn;
  };
#endif

#ifndef _CONFIG_LOCALE_SWT
#define _CONFIG_LOCALE_SWT

#define _ENABLE_PER_THREAD_LOCALE 0x1
#define _DISABLE_PER_THREAD_LOCALE 0x2
#define _ENABLE_PER_THREAD_LOCALE_GLOBAL 0x10
#define _DISABLE_PER_THREAD_LOCALE_GLOBAL 0x20
#define _ENABLE_PER_THREAD_LOCALE_NEW 0x100
#define _DISABLE_PER_THREAD_LOCALE_NEW 0x200

#endif

  ಪೂರ್ಣಾಙ್ಕ __cdecl _configthreadlocale(ಪೂರ್ಣಾಙ್ಕ _Flag);
  ವರ್ಣ *__cdecl setlocale(ಪೂರ್ಣಾಙ್ಕ _Category,ಧ್ರುವ ವರ್ಣ *_Locale);
  _CRTIMP ಸಂರಚನಾ lconv *__cdecl localeconv(ಶೂನ್ಯ);
  _locale_t __cdecl _get_current_locale(ಶೂನ್ಯ);
  _locale_t __cdecl _create_locale(ಪೂರ್ಣಾಙ್ಕ _Category,ಧ್ರುವ ವರ್ಣ *_Locale);
  ಶೂನ್ಯ __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(ಶೂನ್ಯ);
  _locale_t __cdecl __create_locale(ಪೂರ್ಣಾಙ್ಕ _Category,ಧ್ರುವ ವರ್ಣ *_Locale);
  ಶೂನ್ಯ __cdecl __free_locale(_locale_t _Locale);

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(ಪೂರ್ಣಾಙ್ಕ _Category,ಧ್ರುವ wchar_t *_Locale);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(ತೆಗೆ)
#endif
