/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_LOCALE
#define _INC_LOCALE

#شامل <_mingw.h>

#pragma pack(افزودن,_CRT_PACKING)

#ifdef __cplusplus
بیرونی "C" {
#endif

#ifndef پوچ
#ifdef __cplusplus
#define پوچ 0
#وگرنه
#define پوچ ((تهی *)0)
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
  ساختار lconv {
    نویسه *decimal_point;
    نویسه *thousands_sep;
    نویسه *grouping;
    نویسه *int_curr_نماد;
    نویسه *currency_نماد;
    نویسه *mon_decimal_point;
    نویسه *mon_thousands_sep;
    نویسه *mon_grouping;
    نویسه *positive_sign;
    نویسه *negative_sign;
    نویسه int_frac_digits;
    نویسه frac_digits;
    نویسه p_cs_precedes;
    نویسه p_sep_by_space;
    نویسه n_cs_precedes;
    نویسه n_sep_by_space;
    نویسه p_sign_posn;
    نویسه n_sign_posn;
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

  صحیح __cdecl _configthreadlocale(صحیح _Flag);
  نویسه *__cdecl setlocale(صحیح _Category,ثابت نویسه *_Locale);
  _CRTIMP ساختار lconv *__cdecl localeconv(تهی);
  _locale_t __cdecl _get_current_locale(تهی);
  _locale_t __cdecl _create_locale(صحیح _Category,ثابت نویسه *_Locale);
  تهی __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(تهی);
  _locale_t __cdecl __create_locale(صحیح _Category,ثابت نویسه *_Locale);
  تهی __cdecl __free_locale(_locale_t _Locale);

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(صحیح _Category,ثابت wchar_t *_Locale);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(برداشت)
#endif
