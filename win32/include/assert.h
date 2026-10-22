/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __ASSERT_H_
#define __ASSERT_H_

#અન્તર્ભાવ <_mingw.h>
#ifdef __cplusplus
#અન્તર્ભાવ <stdlib.h>
#endif

#ifdef NDEBUG
#ifndef પ્રતિજ્ઞા
#define પ્રતિજ્ઞા(_Expression) ((શૂન્ય)0)
#endif
#નહીંતર

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  શૂન્ય __cdecl __MINGW_NOTHROW exit(પૂર્ણાંક _Code) __MINGW_ATTRIB_NORETURN;
 _CRTIMP શૂન્ય __cdecl __MINGW_NOTHROW _exit(પૂર્ણાંક _Code) __MINGW_ATTRIB_NORETURN;
#જો !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
/* C99 function name */
શૂન્ય __cdecl _Exit(પૂર્ણાંક) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN શૂન્ય __cdecl _Exit(પૂર્ણાંક status)
{  _exit(status); }
#endif

#pragma ધકેલો_macro("abort")
#undef abort
  શૂન્ય __cdecl __declspec(noreturn) abort(શૂન્ય);
#pragma કાઢો_macro("abort")

#endif

#ifdef __cplusplus
બાહ્ય "C" {
#endif


બાહ્ય શૂન્ય __cdecl _wassert(અચલ wchar_t *_Message,અચલ wchar_t *_File,unsigned લીટી_2);
બાહ્ય શૂન્ય __cdecl _assert(અચલ અક્ષર *, અચલ અક્ષર *, unsigned);

#ifdef __cplusplus
}
#endif

#ifndef પ્રતિજ્ઞા
//#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))
#define પ્રતિજ્ઞા(e) ((e) ? (શૂન્ય)0 : _assert(#e, __FILE__, __LINE__))
#endif

#endif

#જો (__STDC_VERSION__ >= 201112L) && !defined(static_assert)
/* C11, section 7.2: The macro static_assert expands to _Static_assert. */
#define static_assert(exp, str) _Static_assert(exp, str) 
#endif

#endif
