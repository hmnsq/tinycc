/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_LOCALE
#define _INC_LOCALE

#അന്തര്ഭാവ <_mingw.h>

#pragma pack(തള്ളുക,_CRT_PACKING)

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

#ifndef ശൂന്യ
#ifdef __cplusplus
#define ശൂന്യ 0
#അല്ലെങ്കിൽ
#define ശൂന്യ ((ശൂന്യം *)0)
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
  ഘടന lconv {
    അക്ഷരം *decimal_point;
    അക്ഷരം *thousands_sep;
    അക്ഷരം *grouping;
    അക്ഷരം *int_curr_ചിഹ്നം;
    അക്ഷരം *currency_ചിഹ്നം;
    അക്ഷരം *mon_decimal_point;
    അക്ഷരം *mon_thousands_sep;
    അക്ഷരം *mon_grouping;
    അക്ഷരം *positive_sign;
    അക്ഷരം *negative_sign;
    അക്ഷരം int_frac_digits;
    അക്ഷരം frac_digits;
    അക്ഷരം p_cs_precedes;
    അക്ഷരം p_sep_by_space;
    അക്ഷരം n_cs_precedes;
    അക്ഷരം n_sep_by_space;
    അക്ഷരം p_sign_posn;
    അക്ഷരം n_sign_posn;
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

  പൂർണ്ണസംഖ്യ __cdecl _configthreadlocale(പൂർണ്ണസംഖ്യ _Flag);
  അക്ഷരം *__cdecl setlocale(പൂർണ്ണസംഖ്യ _Category,സ്ഥിരം അക്ഷരം *_Locale);
  _CRTIMP ഘടന lconv *__cdecl localeconv(ശൂന്യം);
  _locale_t __cdecl _get_current_locale(ശൂന്യം);
  _locale_t __cdecl _create_locale(പൂർണ്ണസംഖ്യ _Category,സ്ഥിരം അക്ഷരം *_Locale);
  ശൂന്യം __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(ശൂന്യം);
  _locale_t __cdecl __create_locale(പൂർണ്ണസംഖ്യ _Category,സ്ഥിരം അക്ഷരം *_Locale);
  ശൂന്യം __cdecl __free_locale(_locale_t _Locale);

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(പൂർണ്ണസംഖ്യ _Category,സ്ഥിരം wchar_t *_Locale);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(എടുക്കുക)
#endif
