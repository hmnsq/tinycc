/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_LOCALE
#define _INC_LOCALE

#ضمن <_mingw.h>

#pragma pack(push,_CRT_PACKING)

#ifdef __cplusplus
خارجي "C" {
#endif

#ifndef عدم
#ifdef __cplusplus
#define عدم 0
#ܐܚܪܢܐ
#define عدم ((فراغ *)0)
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
  بنية lconv {
    حرف *decimal_point;
    حرف *thousands_sep;
    حرف *grouping;
    حرف *int_curr_symbol;
    حرف *currency_symbol;
    حرف *mon_decimal_point;
    حرف *mon_thousands_sep;
    حرف *mon_grouping;
    حرف *positive_sign;
    حرف *negative_sign;
    حرف int_frac_digits;
    حرف frac_digits;
    حرف p_cs_precedes;
    حرف p_sep_by_space;
    حرف n_cs_precedes;
    حرف n_sep_by_space;
    حرف p_sign_posn;
    حرف n_sign_posn;
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

  صحيح __cdecl _configthreadlocale(صحيح _Flag);
  حرف *__cdecl setlocale(صحيح _Category,ثابت حرف *_Locale);
  _CRTIMP بنية lconv *__cdecl localeconv(فراغ);
  _locale_t __cdecl _get_current_locale(فراغ);
  _locale_t __cdecl _create_locale(صحيح _Category,ثابت حرف *_Locale);
  فراغ __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(فراغ);
  _locale_t __cdecl __create_locale(صحيح _Category,ثابت حرف *_Locale);
  فراغ __cdecl __free_locale(_locale_t _Locale);

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(صحيح _Category,ثابت wchar_t *_Locale);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(pop)
#endif
