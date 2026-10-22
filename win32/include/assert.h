/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __ASSERT_H_
#define __ASSERT_H_

#অন্তর্ভাব <_mingw.h>
#ifdef __cplusplus
#অন্তর্ভাব <stdlib.h>
#endif

#ifdef NDEBUG
#ifndef প্রতিজ্ঞা
#define প্রতিজ্ঞা(_Expression) ((শূন্য)0)
#endif
#অন্যথা

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  শূন্য __cdecl __MINGW_NOTHROW exit(পূর্ণাঙ্ক _Code) __MINGW_ATTRIB_NORETURN;
 _CRTIMP শূন্য __cdecl __MINGW_NOTHROW _exit(পূর্ণাঙ্ক _Code) __MINGW_ATTRIB_NORETURN;
#যদি !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
/* C99 function name */
শূন্য __cdecl _Exit(পূর্ণাঙ্ক) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN শূন্য __cdecl _Exit(পূর্ণাঙ্ক status)
{  _exit(status); }
#endif

#pragma ঠেলো_macro("abort")
#undef abort
  শূন্য __cdecl __declspec(noreturn) abort(শূন্য);
#pragma বের_করো_macro("abort")

#endif

#ifdef __cplusplus
বাহ্য "C" {
#endif


বাহ্য শূন্য __cdecl _wassert(ধ্রুব wchar_t *_Message,ধ্রুব wchar_t *_File,unsigned সারি_2);
বাহ্য শূন্য __cdecl _assert(ধ্রুব বর্ণ *, ধ্রুব বর্ণ *, unsigned);

#ifdef __cplusplus
}
#endif

#ifndef প্রতিজ্ঞা
//#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))
#define প্রতিজ্ঞা(e) ((e) ? (শূন্য)0 : _assert(#e, __FILE__, __LINE__))
#endif

#endif

#যদি (__STDC_VERSION__ >= 201112L) && !defined(static_assert)
/* C11, section 7.2: The macro static_assert expands to _Static_assert. */
#define static_assert(exp, str) _Static_assert(exp, str) 
#endif

#endif
