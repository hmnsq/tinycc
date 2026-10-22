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
বাহ্যিক "C" {
#endif

#ifndef ফাঁকা
#ifdef __cplusplus
#define ফাঁকা 0
#অন্যথা
#define ফাঁকা ((শূন্য *)0)
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
  কাঠামো lconv {
    অক্ষর *decimal_point;
    অক্ষর *thousands_sep;
    অক্ষর *grouping;
    অক্ষর *int_curr_প্রতীক;
    অক্ষর *currency_প্রতীক;
    অক্ষর *mon_decimal_point;
    অক্ষর *mon_thousands_sep;
    অক্ষর *mon_grouping;
    অক্ষর *positive_sign;
    অক্ষর *negative_sign;
    অক্ষর int_frac_digits;
    অক্ষর frac_digits;
    অক্ষর p_cs_precedes;
    অক্ষর p_sep_by_space;
    অক্ষর n_cs_precedes;
    অক্ষর n_sep_by_space;
    অক্ষর p_sign_posn;
    অক্ষর n_sign_posn;
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

  পূর্ণসংখ্যা __cdecl _configthreadlocale(পূর্ণসংখ্যা _Flag);
  অক্ষর *__cdecl setlocale(পূর্ণসংখ্যা _Category,ধ্রুবক অক্ষর *_Locale);
  _CRTIMP কাঠামো lconv *__cdecl localeconv(শূন্য);
  _locale_t __cdecl _get_current_locale(শূন্য);
  _locale_t __cdecl _create_locale(পূর্ণসংখ্যা _Category,ধ্রুবক অক্ষর *_Locale);
  শূন্য __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(শূন্য);
  _locale_t __cdecl __create_locale(পূর্ণসংখ্যা _Category,ধ্রুবক অক্ষর *_Locale);
  শূন্য __cdecl __free_locale(_locale_t _Locale);

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(পূর্ণসংখ্যা _Category,ধ্রুবক wchar_t *_Locale);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(বের_করো)
#endif
