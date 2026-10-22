/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __ASSERT_H_
#define __ASSERT_H_

#ضمن <_mingw.h>
#ifdef __cplusplus
#ضمن <stdlib.h>
#endif

#ifdef NDEBUG
#ifndef أكد
#define أكد(_Expression) ((فراغ)0)
#endif
#אחרת

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  فراغ __cdecl __MINGW_NOTHROW exit(صحيح _Code) __MINGW_ATTRIB_NORETURN;
 _CRTIMP فراغ __cdecl __MINGW_NOTHROW _exit(صحيح _Code) __MINGW_ATTRIB_NORETURN;
#אם !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
/* C99 function name */
فراغ __cdecl _Exit(صحيح) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN فراغ __cdecl _Exit(صحيح status)
{  _exit(status); }
#endif

#pragma push_macro("abort")
#undef abort
  فراغ __cdecl __declspec(noreturn) abort(فراغ);
#pragma pop_macro("abort")

#endif

#ifdef __cplusplus
خارجي "C" {
#endif


خارجي فراغ __cdecl _wassert(ثابت wchar_t *_Message,ثابت wchar_t *_File,unsigned _Line);
خارجي فراغ __cdecl _assert(ثابت حرف *, ثابت حرف *, unsigned);

#ifdef __cplusplus
}
#endif

#ifndef أكد
//#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))
#define أكد(e) ((e) ? (فراغ)0 : _assert(#e, __FILE__, __LINE__))
#endif

#endif

#אם (__STDC_VERSION__ >= 201112L) && !defined(static_assert)
/* C11, section 7.2: The macro static_assert expands to _Static_assert. */
#define static_assert(exp, str) _Static_assert(exp, str) 
#endif

#endif
