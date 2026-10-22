/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_LOCALE
#تعریف_کن _INC_LOCALE

#ضمن <_mingw.h>

#رهنمود pack(افزودن,_CRT_PACKING)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده عدم
#اگر_تعریف_شده __cplusplus
#تعریف_کن عدم 0
#وإلا
#تعریف_کن عدم ((فراغ *)0)
#پایان_اگر
#پایان_اگر

#تعریف_کن LC_ALL 0
#تعریف_کن LC_COLLATE 1
#تعریف_کن LC_CTYPE 2
#تعریف_کن LC_MONETARY 3
#تعریف_کن LC_NUMERIC 4
#تعریف_کن LC_زمان 5

#تعریف_کن LC_MIN LC_ALL
#تعریف_کن LC_MAX LC_زمان

#اگر_تعریف_نشده _LCONV_DEFINED
#تعریف_کن _LCONV_DEFINED
  بنية lconv {
    حرف *decimal_نقطه;
    حرف *thousands_sep;
    حرف *grouping;
    حرف *int_curr_نماد;
    حرف *currency_نماد;
    حرف *mon_decimal_نقطه;
    حرف *mon_thousands_sep;
    حرف *mon_grouping;
    حرف *مثبت_sign;
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
#پایان_اگر

#اگر_تعریف_نشده _CONFIG_LOCALE_SWT
#تعریف_کن _CONFIG_LOCALE_SWT

#تعریف_کن ENABLE_در_هر_THREAD_LOCALE 0x1
#تعریف_کن DISABLE_در_هر_THREAD_LOCALE 0x2
#تعریف_کن ENABLE_در_هر_THREAD_LOCALE_GLOBAL 0x10
#تعریف_کن DISABLE_در_هر_THREAD_LOCALE_GLOBAL 0x20
#تعریف_کن ENABLE_در_هر_THREAD_LOCALE_NEW 0x100
#تعریف_کن DISABLE_در_هر_THREAD_LOCALE_NEW 0x200

#پایان_اگر

  صحيح __cdecl _configthreadlocale(صحيح _Flag);
  حرف *__cdecl setlocale(صحيح _Category,ثابت حرف *_Locale);
  _CRTIMP بنية lconv *__cdecl localeconv(فراغ);
  _locale_t __cdecl _get_current_locale(فراغ);
  _locale_t __cdecl _create_locale(صحيح _Category,ثابت حرف *_Locale);
  فراغ __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(فراغ);
  _locale_t __cdecl __create_locale(صحيح _Category,ثابت حرف *_Locale);
  فراغ __cdecl __free_locale(_locale_t _Locale);

#اگر_تعریف_نشده _WLOCALE_DEFINED
#تعریف_کن _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(صحيح _Category,ثابت wchar_t *_Locale);
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#رهنمود pack(برداشت)
#پایان_اگر
