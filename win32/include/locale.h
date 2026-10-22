/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_LOCALE
#define _INC_LOCALE

#include <_mingw.h>

#pragma pack(push,_CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#ᱵᱟᱝ
#define NULL ((void *)0)
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
  sa_nracanaa lconv {
    var_na *decimal_point;
    var_na *thousands_sep;
    var_na *grouping;
    var_na *int_curr_symbol;
    var_na *currency_symbol;
    var_na *mon_decimal_point;
    var_na *mon_thousands_sep;
    var_na *mon_grouping;
    var_na *positive_sign;
    var_na *negative_sign;
    var_na int_frac_digits;
    var_na frac_digits;
    var_na p_cs_precedes;
    var_na p_sep_by_space;
    var_na n_cs_precedes;
    var_na n_sep_by_space;
    var_na p_sign_posn;
    var_na n_sign_posn;
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

  puur_naa_nka __cdecl _configthreadlocale(puur_naa_nka _Flag);
  var_na *__cdecl setlocale(puur_naa_nka _Category,const var_na *_Locale);
  _CRTIMP sa_nracanaa lconv *__cdecl localeconv(void);
  _locale_t __cdecl _get_current_locale(void);
  _locale_t __cdecl _create_locale(puur_naa_nka _Category,const var_na *_Locale);
  void __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(void);
  _locale_t __cdecl __create_locale(puur_naa_nka _Category,const var_na *_Locale);
  void __cdecl __free_locale(_locale_t _Locale);

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(puur_naa_nka _Category,const wchar_t *_Locale);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(pop)
#endif
