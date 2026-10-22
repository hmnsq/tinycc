/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_LOCALE
#تعریف_کړه _INC_LOCALE

#ضمن <_mingw.h>

#لارښوونه pack(ټېل,_CRT_PACKING)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی عدم
#که_تعریف_شوی __cplusplus
#تعریف_کړه عدم 0
#وإلا
#تعریف_کړه عدم ((فراغ *)0)
#د_که_پای
#د_که_پای

#تعریف_کړه LC_ALL 0
#تعریف_کړه LC_COLLATE 1
#تعریف_کړه LC_CTYPE 2
#تعریف_کړه LC_MONETARY 3
#تعریف_کړه LC_NUMERIC 4
#تعریف_کړه LC_وخت 5

#تعریف_کړه LC_MIN LC_ALL
#تعریف_کړه LC_MAX LC_وخت

#که_نه_تعریف_شوی _LCONV_DEFINED
#تعریف_کړه _LCONV_DEFINED
  بنية lconv {
    حرف *decimal_ټکی;
    حرف *thousands_sep;
    حرف *grouping;
    حرف *int_curr_نښه;
    حرف *currency_نښه;
    حرف *mon_decimal_ټکی;
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
#د_که_پای

#که_نه_تعریف_شوی _CONFIG_LOCALE_SWT
#تعریف_کړه _CONFIG_LOCALE_SWT

#تعریف_کړه ENABLE_فی_THREAD_LOCALE 0x1
#تعریف_کړه DISABLE_فی_THREAD_LOCALE 0x2
#تعریف_کړه ENABLE_فی_THREAD_LOCALE_GLOBAL 0x10
#تعریف_کړه DISABLE_فی_THREAD_LOCALE_GLOBAL 0x20
#تعریف_کړه ENABLE_فی_THREAD_LOCALE_NEW 0x100
#تعریف_کړه DISABLE_فی_THREAD_LOCALE_NEW 0x200

#د_که_پای

  صحيح __cdecl _configthreadlocale(صحيح _Flag);
  حرف *__cdecl setlocale(صحيح _Category,ثابت حرف *_Locale);
  _CRTIMP بنية lconv *__cdecl localeconv(فراغ);
  _locale_t __cdecl _get_current_locale(فراغ);
  _locale_t __cdecl _create_locale(صحيح _Category,ثابت حرف *_Locale);
  فراغ __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(فراغ);
  _locale_t __cdecl __create_locale(صحيح _Category,ثابت حرف *_Locale);
  فراغ __cdecl __free_locale(_locale_t _Locale);

#که_نه_تعریف_شوی _WLOCALE_DEFINED
#تعریف_کړه _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(صحيح _Category,ثابت wchar_t *_Locale);
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#لارښوونه pack(راوباسه)
#د_که_پای
