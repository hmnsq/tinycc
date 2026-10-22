/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef _INC_CONIO_S
#define _INC_CONIO_S

#அந்தர்பாவ <conio.h>

#எனில் defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
வெளி "C" {
#endif

  _CRTIMP errno_t __cdecl _cgets_s(எழுத்து *_Buffer,size_t _Size,size_t *_SizeRead);
  _CRTIMP முழு __cdecl _cprintf_s(மாறிலி எழுத்து *_Format,...);
  _CRTIMP முழு __cdecl _cscanf_s(மாறிலி எழுத்து *_Format,...);
  _CRTIMP முழு __cdecl _cscanf_s_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vcprintf_s(மாறிலி எழுத்து *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _cprintf_s_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vcprintf_s_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,va_list _ArgList);

#ifndef _WCONIO_DEFINED_S
#define _WCONIO_DEFINED_S
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *_Buffer,size_t Size_In_சொற்கள்,size_t *_SizeRead);
  _CRTIMP முழு __cdecl _cwprintf_s(மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _cwscanf_s(மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _cwscanf_s_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vcwprintf_s(மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _cwprintf_s_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vcwprintf_s_l(மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
