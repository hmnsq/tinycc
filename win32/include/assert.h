/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __ASSERT_H_
#define __ASSERT_H_

#شامل <_mingw.h>
#ifdef __cplusplus
#شامل <stdlib.h>
#endif

#ifdef NDEBUG
#ifndef أكد
#define أكد(_Expression) ((تهی)0)
#endif
#وگرنه

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  تهی __cdecl __MINGW_NOTHROW exit(صحیح _Code) __MINGW_ATTRIB_NORETURN;
 _CRTIMP تهی __cdecl __MINGW_NOTHROW _exit(صحیح _Code) __MINGW_ATTRIB_NORETURN;
#اگر !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
/* C99 function name */
تهی __cdecl _Exit(صحیح) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN تهی __cdecl _Exit(صحیح status)
{  _exit(status); }
#endif

#pragma افزودن_macro("abort")
#undef abort
  تهی __cdecl __declspec(noreturn) abort(تهی);
#pragma برداشت_macro("abort")

#endif

#ifdef __cplusplus
بیرونی "C" {
#endif


بیرونی تهی __cdecl _wassert(ثابت wchar_t *_Message,ثابت wchar_t *_File,unsigned سطر_2);
بیرونی تهی __cdecl _assert(ثابت نویسه *, ثابت نویسه *, unsigned);

#ifdef __cplusplus
}
#endif

#ifndef أكد
//#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))
#define أكد(e) ((e) ? (تهی)0 : _assert(#e, __FILE__, __LINE__))
#endif

#endif

#اگر (__STDC_VERSION__ >= 201112L) && !defined(static_assert)
/* C11, section 7.2: The macro static_assert expands to _Static_assert. */
#define static_assert(exp, str) _Static_assert(exp, str) 
#endif

#endif
