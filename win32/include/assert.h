/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __ASSERT_H_
#define __ASSERT_H_

#അന്തര്ഭാവ <_mingw.h>
#ifdef __cplusplus
#അന്തര്ഭാവ <stdlib.h>
#endif

#ifdef NDEBUG
#ifndef പ്രതിജ്ഞാ
#define പ്രതിജ്ഞാ(_Expression) ((ശൂന്യം)0)
#endif
#അല്ലെങ്കിൽ

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  ശൂന്യം __cdecl __MINGW_NOTHROW exit(പൂർണ്ണസംഖ്യ _Code) __MINGW_ATTRIB_NORETURN;
 _CRTIMP ശൂന്യം __cdecl __MINGW_NOTHROW _exit(പൂർണ്ണസംഖ്യ _Code) __MINGW_ATTRIB_NORETURN;
#എങ്കിൽ !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
/* C99 function name */
ശൂന്യം __cdecl _Exit(പൂർണ്ണസംഖ്യ) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN ശൂന്യം __cdecl _Exit(പൂർണ്ണസംഖ്യ status)
{  _exit(status); }
#endif

#pragma തള്ളുക_macro("abort")
#undef abort
  ശൂന്യം __cdecl __declspec(noreturn) abort(ശൂന്യം);
#pragma എടുക്കുക_macro("abort")

#endif

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif


ബാഹ്യ ശൂന്യം __cdecl _wassert(സ്ഥിരം wchar_t *_Message,സ്ഥിരം wchar_t *_File,unsigned വരി_2);
ബാഹ്യ ശൂന്യം __cdecl _assert(സ്ഥിരം അക്ഷരം *, സ്ഥിരം അക്ഷരം *, unsigned);

#ifdef __cplusplus
}
#endif

#ifndef പ്രതിജ്ഞാ
//#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))
#define പ്രതിജ്ഞാ(e) ((e) ? (ശൂന്യം)0 : _assert(#e, __FILE__, __LINE__))
#endif

#endif

#എങ്കിൽ (__STDC_VERSION__ >= 201112L) && !defined(static_assert)
/* C11, section 7.2: The macro static_assert expands to _Static_assert. */
#define static_assert(exp, str) _Static_assert(exp, str) 
#endif

#endif
