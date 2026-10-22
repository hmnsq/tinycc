/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_LOCALE
#परिभाषय _INC_LOCALE

#अन्तर्भाव <_mingw.h>

#निर्देशः pack(प्रक्षिप,_CRT_PACKING)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् रिक्त
#यदि_परिभाषितम् __cplusplus
#परिभाषय रिक्त 0
#अन्यथा
#परिभाषय रिक्त ((शून्य *)0)
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय LC_ALL 0
#परिभाषय LC_COLLATE 1
#परिभाषय LC_CTYPE 2
#परिभाषय LC_MONETARY 3
#परिभाषय LC_NUMERIC 4
#परिभाषय LC_TIME 5

#परिभाषय LC_MIN LC_ALL
#परिभाषय LC_MAX LC_TIME

#यदि_अपरिभाषितम् _LCONV_DEFINED
#परिभाषय _LCONV_DEFINED
  संरचना lconv {
    वर्ण *decimal_point;
    वर्ण *thousands_sep;
    वर्ण *grouping;
    वर्ण *int_curr_चिह्नम्;
    वर्ण *currency_चिह्नम्;
    वर्ण *mon_decimal_point;
    वर्ण *mon_thousands_sep;
    वर्ण *mon_grouping;
    वर्ण *धनात्मकम्_sign;
    वर्ण *negative_sign;
    वर्ण int_frac_digits;
    वर्ण frac_digits;
    वर्ण p_cs_precedes;
    वर्ण p_sep_by_space;
    वर्ण n_cs_precedes;
    वर्ण n_sep_by_space;
    वर्ण p_sign_posn;
    वर्ण n_sign_posn;
  };
#यदि_अन्तः

#यदि_अपरिभाषितम् _CONFIG_LOCALE_SWT
#परिभाषय _CONFIG_LOCALE_SWT

#परिभाषय ENABLE_प्रत्येकम्_THREAD_LOCALE 0x1
#परिभाषय DISABLE_प्रत्येकम्_THREAD_LOCALE 0x2
#परिभाषय ENABLE_प्रत्येकम्_THREAD_LOCALE_GLOBAL 0x10
#परिभाषय DISABLE_प्रत्येकम्_THREAD_LOCALE_GLOBAL 0x20
#परिभाषय ENABLE_प्रत्येकम्_THREAD_LOCALE_NEW 0x100
#परिभाषय DISABLE_प्रत्येकम्_THREAD_LOCALE_NEW 0x200

#यदि_अन्तः

  पूर्णाङ्क __cdecl _configthreadlocale(पूर्णाङ्क _Flag);
  वर्ण *__cdecl setlocale(पूर्णाङ्क _Category,ध्रुव वर्ण *_Locale);
  _CRTIMP संरचना lconv *__cdecl localeconv(शून्य);
  _locale_t __cdecl _get_current_locale(शून्य);
  _locale_t __cdecl _create_locale(पूर्णाङ्क _Category,ध्रुव वर्ण *_Locale);
  शून्य __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(शून्य);
  _locale_t __cdecl __create_locale(पूर्णाङ्क _Category,ध्रुव वर्ण *_Locale);
  शून्य __cdecl __free_locale(_locale_t _Locale);

#यदि_अपरिभाषितम् _WLOCALE_DEFINED
#परिभाषय _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(पूर्णाङ्क _Category,ध्रुव wchar_t *_Locale);
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#निर्देशः pack(निष्कासय)
#यदि_अन्तः
