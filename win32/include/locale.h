/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_LOCALE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_LOCALE

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

#ਹਦਾਇਤ pack(ਧੱਕੋ,_CRT_PACKING)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ਨਿਰਾ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਿਰਾ 0
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਿਰਾ ((ਖਾਲੀ *)0)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_ALL 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_COLLATE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_CTYPE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_MONETARY 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_NUMERIC 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_ਸਮਾਂ 5

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_MIN LC_ALL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_MAX LC_ਸਮਾਂ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _LCONV_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _LCONV_DEFINED
  ਬਣਤਰ lconv {
    ਅੱਖਰ *decimal_ਬਿੰਦੂ;
    ਅੱਖਰ *thousands_sep;
    ਅੱਖਰ *grouping;
    ਅੱਖਰ *int_curr_ਚਿੰਨ੍ਹ;
    ਅੱਖਰ *currency_ਚਿੰਨ੍ਹ;
    ਅੱਖਰ *mon_decimal_ਬਿੰਦੂ;
    ਅੱਖਰ *mon_thousands_sep;
    ਅੱਖਰ *mon_grouping;
    ਅੱਖਰ *ਸਕਾਰਾਤਮਕ_sign;
    ਅੱਖਰ *negative_sign;
    ਅੱਖਰ int_frac_digits;
    ਅੱਖਰ frac_digits;
    ਅੱਖਰ p_cs_precedes;
    ਅੱਖਰ p_sep_by_space;
    ਅੱਖਰ n_cs_precedes;
    ਅੱਖਰ n_sep_by_space;
    ਅੱਖਰ p_sign_posn;
    ਅੱਖਰ n_sign_posn;
  };
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CONFIG_LOCALE_SWT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CONFIG_LOCALE_SWT

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLE_ਪ੍ਰਤੀ_THREAD_LOCALE 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISABLE_ਪ੍ਰਤੀ_THREAD_LOCALE 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLE_ਪ੍ਰਤੀ_THREAD_LOCALE_GLOBAL 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISABLE_ਪ੍ਰਤੀ_THREAD_LOCALE_GLOBAL 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLE_ਪ੍ਰਤੀ_THREAD_LOCALE_NEW 0x100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISABLE_ਪ੍ਰਤੀ_THREAD_LOCALE_NEW 0x200

#ਜੇ_ਅੰਤ

  ਪੂਰਨ __cdecl _configthreadlocale(ਪੂਰਨ _Flag);
  ਅੱਖਰ *__cdecl setlocale(ਪੂਰਨ _Category,ਅਚਲ ਅੱਖਰ *_Locale);
  _CRTIMP ਬਣਤਰ lconv *__cdecl localeconv(ਖਾਲੀ);
  _locale_t __cdecl _get_current_locale(ਖਾਲੀ);
  _locale_t __cdecl _create_locale(ਪੂਰਨ _Category,ਅਚਲ ਅੱਖਰ *_Locale);
  ਖਾਲੀ __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(ਖਾਲੀ);
  _locale_t __cdecl __create_locale(ਪੂਰਨ _Category,ਅਚਲ ਅੱਖਰ *_Locale);
  ਖਾਲੀ __cdecl __free_locale(_locale_t _Locale);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WLOCALE_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(ਪੂਰਨ _Category,ਅਚਲ wchar_t *_Locale);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ pack(ਕੱਢੋ)
#ਜੇ_ਅੰਤ
