/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_LOCALE
#وصف_ڪريو _INC_LOCALE

#ضمن <_mingw.h>

#هدايت pack(ڌڪو,_CRT_PACKING)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل عدم
#جيڪڏهن_وصف_ٿيل __cplusplus
#وصف_ڪريو عدم 0
#وإلا
#وصف_ڪريو عدم ((فراغ *)0)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو LC_ALL 0
#وصف_ڪريو LC_COLLATE 1
#وصف_ڪريو LC_CTYPE 2
#وصف_ڪريو LC_MONETARY 3
#وصف_ڪريو LC_NUMERIC 4
#وصف_ڪريو LC_وقت 5

#وصف_ڪريو LC_MIN LC_ALL
#وصف_ڪريو LC_MAX LC_وقت

#جيڪڏهن_وصف_نه_ٿيل _LCONV_DEFINED
#وصف_ڪريو _LCONV_DEFINED
  بنية lconv {
    حرف *decimal_نقطو;
    حرف *thousands_sep;
    حرف *grouping;
    حرف *int_curr_نشان;
    حرف *currency_نشان;
    حرف *mon_decimal_نقطو;
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
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _CONFIG_LOCALE_SWT
#وصف_ڪريو _CONFIG_LOCALE_SWT

#وصف_ڪريو ENABLE_في_THREAD_LOCALE 0x1
#وصف_ڪريو DISABLE_في_THREAD_LOCALE 0x2
#وصف_ڪريو ENABLE_في_THREAD_LOCALE_GLOBAL 0x10
#وصف_ڪريو DISABLE_في_THREAD_LOCALE_GLOBAL 0x20
#وصف_ڪريو ENABLE_في_THREAD_LOCALE_NEW 0x100
#وصف_ڪريو DISABLE_في_THREAD_LOCALE_NEW 0x200

#جيڪڏهن_پورو

  صحيح __cdecl _configthreadlocale(صحيح _Flag);
  حرف *__cdecl setlocale(صحيح _Category,ثابت حرف *_Locale);
  _CRTIMP بنية lconv *__cdecl localeconv(فراغ);
  _locale_t __cdecl _get_current_locale(فراغ);
  _locale_t __cdecl _create_locale(صحيح _Category,ثابت حرف *_Locale);
  فراغ __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(فراغ);
  _locale_t __cdecl __create_locale(صحيح _Category,ثابت حرف *_Locale);
  فراغ __cdecl __free_locale(_locale_t _Locale);

#جيڪڏهن_وصف_نه_ٿيل _WLOCALE_DEFINED
#وصف_ڪريو _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(صحيح _Category,ثابت wchar_t *_Locale);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#هدايت pack(ڪڍو)
#جيڪڏهن_پورو
