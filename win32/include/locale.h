/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_LOCALE
#నిర్వచించు _INC_LOCALE

#అన్తర్భావ <_mingw.h>

#సూచన pack(నెట్టు,_CRT_PACKING)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే ఖాళీ
#నిర్వచితమైతే __cplusplus
#నిర్వచించు ఖాళీ 0
#లేకపోతే
#నిర్వచించు ఖాళీ ((శూన్య *)0)
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు LC_ALL 0
#నిర్వచించు LC_COLLATE 1
#నిర్వచించు LC_CTYPE 2
#నిర్వచించు LC_MONETARY 3
#నిర్వచించు LC_NUMERIC 4
#నిర్వచించు LC_సమయం 5

#నిర్వచించు LC_MIN LC_ALL
#నిర్వచించు LC_MAX LC_సమయం

#నిర్వచితం_కాకపోతే _LCONV_DEFINED
#నిర్వచించు _LCONV_DEFINED
  నిర్మాణం lconv {
    అక్షరం *decimal_బిందువు;
    అక్షరం *thousands_sep;
    అక్షరం *grouping;
    అక్షరం *int_curr_చిహ్నం;
    అక్షరం *currency_చిహ్నం;
    అక్షరం *mon_decimal_బిందువు;
    అక్షరం *mon_thousands_sep;
    అక్షరం *mon_grouping;
    అక్షరం *ధనాత్మక_sign;
    అక్షరం *negative_sign;
    అక్షరం int_frac_digits;
    అక్షరం frac_digits;
    అక్షరం p_cs_precedes;
    అక్షరం p_sep_by_space;
    అక్షరం n_cs_precedes;
    అక్షరం n_sep_by_space;
    అక్షరం p_sign_posn;
    అక్షరం n_sign_posn;
  };
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _CONFIG_LOCALE_SWT
#నిర్వచించు _CONFIG_LOCALE_SWT

#నిర్వచించు ENABLE_చొప్పున_THREAD_LOCALE 0x1
#నిర్వచించు DISABLE_చొప్పున_THREAD_LOCALE 0x2
#నిర్వచించు ENABLE_చొప్పున_THREAD_LOCALE_GLOBAL 0x10
#నిర్వచించు DISABLE_చొప్పున_THREAD_LOCALE_GLOBAL 0x20
#నిర్వచించు ENABLE_చొప్పున_THREAD_LOCALE_NEW 0x100
#నిర్వచించు DISABLE_చొప్పున_THREAD_LOCALE_NEW 0x200

#అయితే_ముగింపు

  పూర్ణాంకం __cdecl _configthreadlocale(పూర్ణాంకం _Flag);
  అక్షరం *__cdecl setlocale(పూర్ణాంకం _Category,స్థిరరాశి అక్షరం *_Locale);
  _CRTIMP నిర్మాణం lconv *__cdecl localeconv(శూన్య);
  _locale_t __cdecl _get_current_locale(శూన్య);
  _locale_t __cdecl _create_locale(పూర్ణాంకం _Category,స్థిరరాశి అక్షరం *_Locale);
  శూన్య __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(శూన్య);
  _locale_t __cdecl __create_locale(పూర్ణాంకం _Category,స్థిరరాశి అక్షరం *_Locale);
  శూన్య __cdecl __free_locale(_locale_t _Locale);

#నిర్వచితం_కాకపోతే _WLOCALE_DEFINED
#నిర్వచించు _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(పూర్ణాంకం _Category,స్థిరరాశి wchar_t *_Locale);
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#సూచన pack(తీయి)
#అయితే_ముగింపు
