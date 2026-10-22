/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#यदि_अपरिभाषितम् _INC_CONIO_S
#परिभाषय _INC_CONIO_S

#अन्तर्भाव <conio.h>

#यदि defined(MINGW_HAS_SECURE_API)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

  _CRTIMP errno_t __cdecl _cgets_s(वर्ण *बफर_2,आकार_t आकार_4,आकार_t *आकार_Read);
  _CRTIMP पूर्णाङ्क __cdecl _cprintf_s(ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cscanf_s(ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cscanf_s_l(ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcprintf_s(ध्रुव वर्ण *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cprintf_s_l(ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcprintf_s_l(ध्रुव वर्ण *_Format,_locale_t _Locale,va_list _ArgList);

#यदि_अपरिभाषितम् _WCONIO_DEFINED_S
#परिभाषय _WCONIO_DEFINED_S
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *बफर_2,आकार_t आकार_अन्तर्_शब्दाः,आकार_t *आकार_Read);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_s(ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cwscanf_s(ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cwscanf_s_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_s(ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_s_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_s_l(ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#यदि_अन्तः
#यदि_अन्तः
