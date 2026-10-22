/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef _INC_CONIO_S
#define _INC_CONIO_S

#अन्तर्भाव <conio.h>

#यदि defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
बाह्य "C" {
#endif

  _CRTIMP errno_t __cdecl _cgets_s(वर्ण *_Buffer,माप_प्रकार _Size,माप_प्रकार *_SizeRead);
  _CRTIMP पूर्णाङ्क __cdecl _cprintf_s(ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cscanf_s(ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cscanf_s_l(ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcprintf_s(ध्रुव वर्ण *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cprintf_s_l(ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcprintf_s_l(ध्रुव वर्ण *_Format,_locale_t _Locale,बहु_सूची _ArgList);

#ifndef _WCONIO_DEFINED_S
#define _WCONIO_DEFINED_S
  _CRTIMP errno_t __cdecl _cgetws_s(ब_अक्षर_प्रकार *_Buffer,माप_प्रकार Size_In_शब्दगण,माप_प्रकार *_SizeRead);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_s(ध्रुव ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cwscanf_s(ध्रुव ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cwscanf_s_l(ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_s(ध्रुव ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_s_l(ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_s_l(ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
