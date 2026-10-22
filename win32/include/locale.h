/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_LOCALE
#define _INC_LOCALE

#অন্তর্ভাব <_mingw.h>

#pragma pack(ঠেলো,_CRT_PACKING)

#ifdef __cplusplus
বাহ্য "C" {
#endif

#ifndef রিক্ত
#ifdef __cplusplus
#define রিক্ত 0
#অন্যথা
#define রিক্ত ((শূন্য *)0)
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
  সংরচনা lconv {
    বর্ণ *decimal_point;
    বর্ণ *thousands_sep;
    বর্ণ *grouping;
    বর্ণ *int_curr_প্রতীক;
    বর্ণ *currency_প্রতীক;
    বর্ণ *mon_decimal_point;
    বর্ণ *mon_thousands_sep;
    বর্ণ *mon_grouping;
    বর্ণ *positive_sign;
    বর্ণ *negative_sign;
    বর্ণ int_frac_digits;
    বর্ণ frac_digits;
    বর্ণ p_cs_precedes;
    বর্ণ p_sep_by_space;
    বর্ণ n_cs_precedes;
    বর্ণ n_sep_by_space;
    বর্ণ p_sign_posn;
    বর্ণ n_sign_posn;
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

  পূর্ণাঙ্ক __cdecl _configthreadlocale(পূর্ণাঙ্ক _Flag);
  বর্ণ *__cdecl setlocale(পূর্ণাঙ্ক _Category,ধ্রুব বর্ণ *_Locale);
  _CRTIMP সংরচনা lconv *__cdecl localeconv(শূন্য);
  _locale_t __cdecl _get_current_locale(শূন্য);
  _locale_t __cdecl _create_locale(পূর্ণাঙ্ক _Category,ধ্রুব বর্ণ *_Locale);
  শূন্য __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(শূন্য);
  _locale_t __cdecl __create_locale(পূর্ণাঙ্ক _Category,ধ্রুব বর্ণ *_Locale);
  শূন্য __cdecl __free_locale(_locale_t _Locale);

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(পূর্ণাঙ্ক _Category,ধ্রুব wchar_t *_Locale);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(বের_করো)
#endif
