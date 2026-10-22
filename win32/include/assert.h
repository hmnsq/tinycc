/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __ASSERT_H_
#define __ASSERT_H_

#ಅನ್ತರ್ಭಾವ <_mingw.h>
#ifdef __cplusplus
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#endif

#ifdef NDEBUG
#ifndef ಪ್ರತಿಜ್ಞಾ
#define ಪ್ರತಿಜ್ಞಾ(_Expression) ((ಶೂನ್ಯ)0)
#endif
#ಅನ್ಯಥಾ

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  ಶೂನ್ಯ __cdecl __MINGW_NOTHROW exit(ಪೂರ್ಣಾಙ್ಕ _Code) __MINGW_ATTRIB_NORETURN;
 _CRTIMP ಶೂನ್ಯ __cdecl __MINGW_NOTHROW _exit(ಪೂರ್ಣಾಙ್ಕ _Code) __MINGW_ATTRIB_NORETURN;
#ಯದಿ !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
/* C99 function name */
ಶೂನ್ಯ __cdecl _Exit(ಪೂರ್ಣಾಙ್ಕ) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN ಶೂನ್ಯ __cdecl _Exit(ಪೂರ್ಣಾಙ್ಕ status)
{  _exit(status); }
#endif

#pragma ತಳ್ಳು_macro("abort")
#undef abort
  ಶೂನ್ಯ __cdecl __declspec(noreturn) abort(ಶೂನ್ಯ);
#pragma ತೆಗೆ_macro("abort")

#endif

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif


ಬಾಹ್ಯ ಶೂನ್ಯ __cdecl _wassert(ಧ್ರುವ wchar_t *_Message,ಧ್ರುವ wchar_t *_File,unsigned ಸಾಲು_2);
ಬಾಹ್ಯ ಶೂನ್ಯ __cdecl _assert(ಧ್ರುವ ವರ್ಣ *, ಧ್ರುವ ವರ್ಣ *, unsigned);

#ifdef __cplusplus
}
#endif

#ifndef ಪ್ರತಿಜ್ಞಾ
//#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))
#define ಪ್ರತಿಜ್ಞಾ(e) ((e) ? (ಶೂನ್ಯ)0 : _assert(#e, __FILE__, __LINE__))
#endif

#endif

#ಯದಿ (__STDC_VERSION__ >= 201112L) && !defined(static_assert)
/* C11, section 7.2: The macro static_assert expands to _Static_assert. */
#define static_assert(exp, str) _Static_assert(exp, str) 
#endif

#endif
