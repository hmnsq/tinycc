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
  संरचना स्था_बदल {
    अक्षर *decimal_point;
    अक्षर *thousands_sep;
    अक्षर *grouping;
    अक्षर *int_curr_चिन्ह;
    अक्षर *currency_चिन्ह;
    अक्षर *mon_decimal_point;
    अक्षर *mon_thousands_sep;
    अक्षर *mon_grouping;
    अक्षर *positive_sign;
    अक्षर *negative_sign;
    अक्षर int_frac_digits;
    अक्षर frac_digits;
    अक्षर p_cs_precedes;
    अक्षर p_sep_by_space;
    अक्षर n_cs_precedes;
    अक्षर n_sep_by_space;
    अक्षर p_sign_posn;
    अक्षर n_sign_posn;
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

  पूर्णांक __cdecl _configthreadlocale(पूर्णांक _Flag);
  अक्षर *__cdecl रखो_क्षेत्र(पूर्णांक _Category,स्थिरांक अक्षर *_Locale);
  _CRTIMP संरचना स्था_बदल *__cdecl क्षेत्र_बदलो(शून्य);
  _locale_t __cdecl _get_current_locale(शून्य);
  _locale_t __cdecl _create_locale(पूर्णांक _Category,स्थिरांक अक्षर *_Locale);
  शून्य __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(शून्य);
  _locale_t __cdecl __create_locale(पूर्णांक _Category,स्थिरांक अक्षर *_Locale);
  शून्य __cdecl __free_locale(_locale_t _Locale);

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wsetlocale(पूर्णांक _Category,स्थिरांक ब_अक्षर_प्रकार *_Locale);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(काढा)
#endif
