/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef _INC_CONIO_S
#define _INC_CONIO_S

#അന്തര്ഭാവ <conio.h>

#എങ്കിൽ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

  _CRTIMP errno_t __cdecl _cgets_s(അക്ഷരം *_Buffer,size_t _Size,size_t *_SizeRead);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cprintf_s(സ്ഥിരം അക്ഷരം *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cscanf_s(സ്ഥിരം അക്ഷരം *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cscanf_s_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vcprintf_s(സ്ഥിരം അക്ഷരം *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cprintf_s_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vcprintf_s_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,va_list _ArgList);

#ifndef _WCONIO_DEFINED_S
#define _WCONIO_DEFINED_S
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *_Buffer,size_t Size_In_വാക്കുകൾ,size_t *_SizeRead);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwprintf_s(സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwscanf_s(സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwscanf_s_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vcwprintf_s(സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwprintf_s_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vcwprintf_s_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
