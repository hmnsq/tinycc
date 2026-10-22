/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی __ASSERT_H_
#تعریف_کړه __ASSERT_H_

#ضمن <_mingw.h>
#که_تعریف_شوی __cplusplus
#ضمن <stdlib.h>
#د_که_پای

#که_تعریف_شوی NDEBUG
#که_نه_تعریف_شوی أكد
#تعریف_کړه أكد(افاده) ((فراغ)0)
#د_که_پای
#وإلا

#که_نه_تعریف_شوی _CRT_TERMINATE_DEFINED
#تعریف_کړه _CRT_TERMINATE_DEFINED
  فراغ __cdecl __MINGW_NOTHROW وتل(صحيح کوډ_3) __MINGW_ATTRIB_NORETURN;
 _CRTIMP فراغ __cdecl __MINGW_NOTHROW _exit(صحيح کوډ_3) __MINGW_ATTRIB_NORETURN;
#إذا !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
/* C99 function name */
فراغ __cdecl _Exit(صحيح) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN فراغ __cdecl _Exit(صحيح حالت)
{  _exit(حالت); }
#د_که_پای

#لارښوونه ټېل_macro("abort")
#تعریف_لغوه abort
  فراغ __cdecl __declspec(noreturn) abort(فراغ);
#لارښوونه راوباسه_macro("abort")

#د_که_پای

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای


خارجي فراغ __cdecl _wassert(ثابت wchar_t *پیغام_4,ثابت wchar_t *_File,بینښه کرښه_2);
خارجي فراغ __cdecl _assert(ثابت حرف *, ثابت حرف *, بینښه);

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#که_نه_تعریف_شوی أكد
//#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))
#تعریف_کړه أكد(e) ((e) ? (فراغ)0 : _assert(#e, __FILE__, __LINE__))
#د_که_پای

#د_که_پای

#إذا (__STDC_VERSION__ >= 201112L) && !defined(static_assert)
/* C11, section 7.2: The macro static_assert expands to _Static_assert. */
#تعریف_کړه static_assert(توانیز_تابع, str) _Static_assert(توانیز_تابع, str) 
#د_که_پای

#د_که_پای
