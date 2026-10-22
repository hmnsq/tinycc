/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_LOCALE
#تعریف_کرو _INC_LOCALE

#شامل <_mingw.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ تہی
#اگر_تعریف_شدہ __cplusplus
#تعریف_کرو تہی 0
#ورنہ
#تعریف_کرو تہی ((خالی *)0)
#اگر_ختم
#اگر_ختم

#تعریف_کرو LC_ALL 0
#تعریف_کرو LC_COLLATE 1
#تعریف_کرو LC_CTYPE 2
#تعریف_کرو LC_MONETARY 3
#تعریف_کرو LC_NUMERIC 4
#تعریف_کرو LC_وقت 5

#تعریف_کرو LC_MIN LC_ALL
#تعریف_کرو LC_MAX LC_وقت

#اگر_غیر_تعریف_شدہ _LCONV_DEFINED
#تعریف_کرو _LCONV_DEFINED
  ساخت lconv {
    حرف *decimal_نقطہ;
    حرف *thousands_sep;
    حرف *grouping;
    حرف *int_curr_علامت;
    حرف *currency_علامت;
    حرف *mon_decimal_نقطہ;
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
#اگر_ختم

#اگر_غیر_تعریف_شدہ _CONFIG_LOCALE_SWT
#تعریف_کرو _CONFIG_LOCALE_SWT

#تعریف_کرو ENABLE_فی_THREAD_LOCALE 0x1
#تعریف_کرو DISABLE_فی_THREAD_LOCALE 0x2
#تعریف_کرو ENABLE_فی_THREAD_LOCALE_GLOBAL 0x10
#تعریف_کرو DISABLE_فی_THREAD_LOCALE_GLOBAL 0x20
#تعریف_کرو ENABLE_فی_THREAD_LOCALE_NEW 0x100
#تعریف_کرو DISABLE_فی_THREAD_LOCALE_NEW 0x200

#اگر_ختم

  صحیح __cdecl _configthreadlocale(صحیح _Flag);
  حرف *__cdecl setlocale(صحیح _Category,ثابت حرف *_Locale);
  _CRTIMP ساخت lconv *__cdecl localeconv(خالی);
  _locale_t __cdecl _get_current_locale(خالی);
  _locale_t __cdecl _create_locale(صحیح _Category,ثابت حرف *_Locale);
  خالی __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(خالی);
  _locale_t __cdecl __create_locale(صحیح _Category,ثابت حرف *_Locale);
  خالی __cdecl __free_locale(_locale_t _Locale);

#اگر_غیر_تعریف_شدہ _WLOCALE_DEFINED
#تعریف_کرو _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(صحیح _Category,ثابت wchar_t *_Locale);
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#ہدایت pack(نکالو)
#اگر_ختم
