/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef _INC_CONIO_S
#define _INC_CONIO_S

#अन्तर्भाव <conio.h>

#जर defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
बाह्य "C" {
#endif

  _CRTIMP errno_t __cdecl _cgets_s(अक्षर *_Buffer,माप_प्रकार _Size,माप_प्रकार *_SizeRead);
  _CRTIMP पूर्णांक __cdecl _cprintf_s(स्थिरांक अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _cscanf_s(स्थिरांक अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _cscanf_s_l(स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vcprintf_s(स्थिरांक अक्षर *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _cprintf_s_l(स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vcprintf_s_l(स्थिरांक अक्षर *_Format,_locale_t _Locale,बहु_सूची _ArgList);

#ifndef _WCONIO_DEFINED_S
#define _WCONIO_DEFINED_S
  _CRTIMP errno_t __cdecl _cgetws_s(ब_अक्षर_प्रकार *_Buffer,माप_प्रकार Size_In_शब्द,माप_प्रकार *_SizeRead);
  _CRTIMP पूर्णांक __cdecl _cwprintf_s(स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _cwscanf_s(स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _cwscanf_s_l(स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vcwprintf_s(स्थिरांक ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _cwprintf_s_l(स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vcwprintf_s_l(स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
