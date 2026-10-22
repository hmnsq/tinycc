/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#अगर_अघोषित _INC_CONIO_S
#घोषणा _INC_CONIO_S

#समावेश <conio.h>

#अगर defined(MINGW_HAS_SECURE_API)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

  _CRTIMP errno_t __cdecl _cgets_s(अक्षर *बफर_2,माप_प्रकार आकार_4,माप_प्रकार *आकार_Read);
  _CRTIMP पूर्णांक __cdecl _cprintf_s(स्थिर अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _cscanf_s(स्थिर अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _cscanf_s_l(स्थिर अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vcprintf_s(स्थिर अक्षर *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _cprintf_s_l(स्थिर अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vcprintf_s_l(स्थिर अक्षर *_Format,_locale_t _Locale,बहु_सूची _ArgList);

#अगर_अघोषित _WCONIO_DEFINED_S
#घोषणा _WCONIO_DEFINED_S
  _CRTIMP errno_t __cdecl _cgetws_s(ब_अक्षर_प्रकार *बफर_2,माप_प्रकार आकार_In_शब्दगण,माप_प्रकार *आकार_Read);
  _CRTIMP पूर्णांक __cdecl _cwprintf_s(स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _cwscanf_s(स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _cwscanf_s_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vcwprintf_s(स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _cwprintf_s_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vcwprintf_s_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#पूर्ण_अगर
#पूर्ण_अगर
