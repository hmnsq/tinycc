/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __ASSERT_H_
#define __ASSERT_H_

#அந்தர்பாவ <_mingw.h>
#ifdef __cplusplus
#அந்தர்பாவ <stdlib.h>
#endif

#ifdef NDEBUG
#ifndef ப்ரதிஜ்ஞா
#define ப்ரதிஜ்ஞா(_Expression) ((வெறுமை)0)
#endif
#இல்லையெனில்

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  வெறுமை __cdecl __MINGW_NOTHROW exit(முழு _Code) __MINGW_ATTRIB_NORETURN;
 _CRTIMP வெறுமை __cdecl __MINGW_NOTHROW _exit(முழு _Code) __MINGW_ATTRIB_NORETURN;
#எனில் !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
/* C99 function name */
வெறுமை __cdecl _Exit(முழு) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN வெறுமை __cdecl _Exit(முழு status)
{  _exit(status); }
#endif

#pragma தள்ளு_macro("abort")
#undef abort
  வெறுமை __cdecl __declspec(noreturn) abort(வெறுமை);
#pragma எடு_macro("abort")

#endif

#ifdef __cplusplus
வெளி "C" {
#endif


வெளி வெறுமை __cdecl _wassert(மாறிலி wchar_t *_Message,மாறிலி wchar_t *_File,unsigned வரி_2);
வெளி வெறுமை __cdecl _assert(மாறிலி எழுத்து *, மாறிலி எழுத்து *, unsigned);

#ifdef __cplusplus
}
#endif

#ifndef ப்ரதிஜ்ஞா
//#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))
#define ப்ரதிஜ்ஞா(e) ((e) ? (வெறுமை)0 : _assert(#e, __FILE__, __LINE__))
#endif

#endif

#எனில் (__STDC_VERSION__ >= 201112L) && !defined(static_assert)
/* C11, section 7.2: The macro static_assert expands to _Static_assert. */
#define static_assert(exp, str) _Static_assert(exp, str) 
#endif

#endif
