/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_LOCALE
#define _INC_LOCALE

#ଅନ୍ତର୍ଭାଵ <_mingw.h>

#pragma pack(ଠେଲ,_CRT_PACKING)

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

#ifndef ଖାଲି
#ifdef __cplusplus
#define ଖାଲି 0
#ଅନ୍ୟଥା
#define ଖାଲି ((ଶୂନ୍ୟ *)0)
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
  ସଂରଚନା lconv {
    ଅକ୍ଷର *decimal_point;
    ଅକ୍ଷର *thousands_sep;
    ଅକ୍ଷର *grouping;
    ଅକ୍ଷର *int_curr_ପ୍ରତୀକ;
    ଅକ୍ଷର *currency_ପ୍ରତୀକ;
    ଅକ୍ଷର *mon_decimal_point;
    ଅକ୍ଷର *mon_thousands_sep;
    ଅକ୍ଷର *mon_grouping;
    ଅକ୍ଷର *positive_sign;
    ଅକ୍ଷର *negative_sign;
    ଅକ୍ଷର int_frac_digits;
    ଅକ୍ଷର frac_digits;
    ଅକ୍ଷର p_cs_precedes;
    ଅକ୍ଷର p_sep_by_space;
    ଅକ୍ଷର n_cs_precedes;
    ଅକ୍ଷର n_sep_by_space;
    ଅକ୍ଷର p_sign_posn;
    ଅକ୍ଷର n_sign_posn;
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

  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _configthreadlocale(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Flag);
  ଅକ୍ଷର *__cdecl setlocale(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Category,ଅଚଳ ଅକ୍ଷର *_Locale);
  _CRTIMP ସଂରଚନା lconv *__cdecl localeconv(ଶୂନ୍ୟ);
  _locale_t __cdecl _get_current_locale(ଶୂନ୍ୟ);
  _locale_t __cdecl _create_locale(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Category,ଅଚଳ ଅକ୍ଷର *_Locale);
  ଶୂନ୍ୟ __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(ଶୂନ୍ୟ);
  _locale_t __cdecl __create_locale(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Category,ଅଚଳ ଅକ୍ଷର *_Locale);
  ଶୂନ୍ୟ __cdecl __free_locale(_locale_t _Locale);

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Category,ଅଚଳ wchar_t *_Locale);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(କାଢ଼)
#endif
