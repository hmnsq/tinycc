/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __ASSERT_H_
#define __ASSERT_H_

#ଅନ୍ତର୍ଭାଵ <_mingw.h>
#ifdef __cplusplus
#ଅନ୍ତର୍ଭାଵ <stdlib.h>
#endif

#ifdef NDEBUG
#ifndef ପ୍ରତିଜ୍ଞା
#define ପ୍ରତିଜ୍ଞା(_Expression) ((ଶୂନ୍ୟ)0)
#endif
#ଅନ୍ୟଥା

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  ଶୂନ୍ୟ __cdecl __MINGW_NOTHROW exit(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Code) __MINGW_ATTRIB_NORETURN;
 _CRTIMP ଶୂନ୍ୟ __cdecl __MINGW_NOTHROW _exit(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Code) __MINGW_ATTRIB_NORETURN;
#ଯଦି !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
/* C99 function name */
ଶୂନ୍ୟ __cdecl _Exit(ପୂର୍ଣ୍ଣସଂଖ୍ୟା) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN ଶୂନ୍ୟ __cdecl _Exit(ପୂର୍ଣ୍ଣସଂଖ୍ୟା status)
{  _exit(status); }
#endif

#pragma ଠେଲ_macro("abort")
#undef abort
  ଶୂନ୍ୟ __cdecl __declspec(noreturn) abort(ଶୂନ୍ୟ);
#pragma କାଢ଼_macro("abort")

#endif

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif


ବାହ୍ୟ ଶୂନ୍ୟ __cdecl _wassert(ଅଚଳ wchar_t *_Message,ଅଚଳ wchar_t *_File,unsigned ଧାଡ଼ି_2);
ବାହ୍ୟ ଶୂନ୍ୟ __cdecl _assert(ଅଚଳ ଅକ୍ଷର *, ଅଚଳ ଅକ୍ଷର *, unsigned);

#ifdef __cplusplus
}
#endif

#ifndef ପ୍ରତିଜ୍ଞା
//#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))
#define ପ୍ରତିଜ୍ଞା(e) ((e) ? (ଶୂନ୍ୟ)0 : _assert(#e, __FILE__, __LINE__))
#endif

#endif

#ଯଦି (__STDC_VERSION__ >= 201112L) && !defined(static_assert)
/* C11, section 7.2: The macro static_assert expands to _Static_assert. */
#define static_assert(exp, str) _Static_assert(exp, str) 
#endif

#endif
