/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_LOCALE
#define _INC_LOCALE

#અન્તર્ભાવ <_mingw.h>

#pragma pack(ધકેલો,_CRT_PACKING)

#ifdef __cplusplus
બાહ્ય "C" {
#endif

#ifndef ખાલી
#ifdef __cplusplus
#define ખાલી 0
#નહીંતર
#define ખાલી ((શૂન્ય *)0)
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
  સંરચના lconv {
    અક્ષર *decimal_point;
    અક્ષર *thousands_sep;
    અક્ષર *grouping;
    અક્ષર *int_curr_પ્રતીક;
    અક્ષર *currency_પ્રતીક;
    અક્ષર *mon_decimal_point;
    અક્ષર *mon_thousands_sep;
    અક્ષર *mon_grouping;
    અક્ષર *positive_sign;
    અક્ષર *negative_sign;
    અક્ષર int_frac_digits;
    અક્ષર frac_digits;
    અક્ષર p_cs_precedes;
    અક્ષર p_sep_by_space;
    અક્ષર n_cs_precedes;
    અક્ષર n_sep_by_space;
    અક્ષર p_sign_posn;
    અક્ષર n_sign_posn;
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

  પૂર્ણાંક __cdecl _configthreadlocale(પૂર્ણાંક _Flag);
  અક્ષર *__cdecl setlocale(પૂર્ણાંક _Category,અચલ અક્ષર *_Locale);
  _CRTIMP સંરચના lconv *__cdecl localeconv(શૂન્ય);
  _locale_t __cdecl _get_current_locale(શૂન્ય);
  _locale_t __cdecl _create_locale(પૂર્ણાંક _Category,અચલ અક્ષર *_Locale);
  શૂન્ય __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(શૂન્ય);
  _locale_t __cdecl __create_locale(પૂર્ણાંક _Category,અચલ અક્ષર *_Locale);
  શૂન્ય __cdecl __free_locale(_locale_t _Locale);

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(પૂર્ણાંક _Category,અચલ wchar_t *_Locale);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(કાઢો)
#endif
