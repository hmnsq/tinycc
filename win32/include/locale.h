/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_LOCALE
#घोषणा _INC_LOCALE

#समावेश <_mingw.h>

#आशय pack(धकेलो,_CRT_PACKING)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित शून्य
#अगर_घोषित __cplusplus
#घोषणा शून्य 0
#अन्यथा
#घोषणा शून्य ((व्योम *)0)
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा LC_ALL 0
#घोषणा LC_COLLATE 1
#घोषणा LC_CTYPE 2
#घोषणा LC_MONETARY 3
#घोषणा LC_NUMERIC 4
#घोषणा LC_TIME 5

#घोषणा LC_MIN LC_ALL
#घोषणा LC_MAX LC_TIME

#अगर_अघोषित _LCONV_DEFINED
#घोषणा _LCONV_DEFINED
  काष्ठा स्था_बदल {
    अक्षर *decimal_point;
    अक्षर *thousands_sep;
    अक्षर *grouping;
    अक्षर *int_curr_प्रतीक;
    अक्षर *currency_प्रतीक;
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
#पूर्ण_अगर

#अगर_अघोषित _CONFIG_LOCALE_SWT
#घोषणा _CONFIG_LOCALE_SWT

#घोषणा _ENABLE_PER_THREAD_LOCALE 0x1
#घोषणा _DISABLE_PER_THREAD_LOCALE 0x2
#घोषणा _ENABLE_PER_THREAD_LOCALE_GLOBAL 0x10
#घोषणा _DISABLE_PER_THREAD_LOCALE_GLOBAL 0x20
#घोषणा _ENABLE_PER_THREAD_LOCALE_NEW 0x100
#घोषणा _DISABLE_PER_THREAD_LOCALE_NEW 0x200

#पूर्ण_अगर

  पूर्णांक __cdecl _configthreadlocale(पूर्णांक _Flag);
  अक्षर *__cdecl रखो_क्षेत्र(पूर्णांक _Category,स्थिर अक्षर *_Locale);
  _CRTIMP काष्ठा स्था_बदल *__cdecl क्षेत्र_बदलो(व्योम);
  _locale_t __cdecl _get_current_locale(व्योम);
  _locale_t __cdecl _create_locale(पूर्णांक _Category,स्थिर अक्षर *_Locale);
  व्योम __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(व्योम);
  _locale_t __cdecl __create_locale(पूर्णांक _Category,स्थिर अक्षर *_Locale);
  व्योम __cdecl __free_locale(_locale_t _Locale);

#अगर_अघोषित _WLOCALE_DEFINED
#घोषणा _WLOCALE_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wsetlocale(पूर्णांक _Category,स्थिर ब_अक्षर_प्रकार *_Locale);
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#आशय pack(निकालो)
#पूर्ण_अगर
