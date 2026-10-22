/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_LOCALE
#define _INC_LOCALE

#अन्तर्भाव <_mingw.h>

#pragma pack(ढकला,_CRT_PACKING)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef रिक्त
#ifdef __cplusplus
#define रिक्त 0
#अन्यथा
#define रिक्त ((शून्य *)0)
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
  संरचना lconv {
    वर्ण *decimal_point;
    वर्ण *thousands_sep;
    वर्ण *grouping;
    वर्ण *int_curr_चिन्ह;
    वर्ण *currency_चिन्ह;
    वर्ण *mon_decimal_point;
    वर्ण *mon_thousands_sep;
    वर्ण *mon_grouping;
    वर्ण *positive_sign;
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

  पूर्णाङ्क __cdecl _configthreadlocale(पूर्णाङ्क _Flag);
  वर्ण *__cdecl setlocale(पूर्णाङ्क _Category,ध्रुव वर्ण *_Locale);
  _CRTIMP संरचना lconv *__cdecl localeconv(शून्य);
  _locale_t __cdecl _get_current_locale(शून्य);
  _locale_t __cdecl _create_locale(पूर्णाङ्क _Category,ध्रुव वर्ण *_Locale);
  शून्य __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(शून्य);
  _locale_t __cdecl __create_locale(पूर्णाङ्क _Category,ध्रुव वर्ण *_Locale);
  शून्य __cdecl __free_locale(_locale_t _Locale);

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(पूर्णाङ्क _Category,ध्रुव wchar_t *_Locale);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(काढा)
#endif
