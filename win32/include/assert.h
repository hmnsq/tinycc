/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف __ASSERT_H_
#تعریف_کرو __ASSERT_H_

#ضمن <_mingw.h>
#جے_تعریف_شدہ __cplusplus
#ضمن <stdlib.h>
#جے_انت

#جے_تعریف_شدہ NDEBUG
#جے_بنا_تعریف أكد
#تعریف_کرو أكد(عبارت) ((فراغ)0)
#جے_انت
#وإلا

#جے_بنا_تعریف _CRT_TERMINATE_DEFINED
#تعریف_کرو _CRT_TERMINATE_DEFINED
  فراغ __cdecl __MINGW_NOTHROW باہر_نکلو(صحيح کوڈ_3) __MINGW_ATTRIB_NORETURN;
 _CRTIMP فراغ __cdecl __MINGW_NOTHROW _exit(صحيح کوڈ_3) __MINGW_ATTRIB_NORETURN;
#إذا !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
/* C99 function name */
فراغ __cdecl _Exit(صحيح) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN فراغ __cdecl _Exit(صحيح حالت)
{  _exit(حالت); }
#جے_انت

#ہدایت ڈالو_macro("abort")
#تعریف_رد abort
  فراغ __cdecl __declspec(noreturn) abort(فراغ);
#ہدایت نکالو_macro("abort")

#جے_انت

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت


خارجي فراغ __cdecl _wassert(ثابت wchar_t *سنیہا_2,ثابت wchar_t *_File,بنانشانی سطر_2);
خارجي فراغ __cdecl _assert(ثابت حرف *, ثابت حرف *, بنانشانی);

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#جے_بنا_تعریف أكد
//#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))
#تعریف_کرو أكد(e) ((e) ? (فراغ)0 : _assert(#e, __FILE__, __LINE__))
#جے_انت

#جے_انت

#إذا (__STDC_VERSION__ >= 201112L) && !defined(static_assert)
/* C11, section 7.2: The macro static_assert expands to _Static_assert. */
#تعریف_کرو static_assert(قوت_نما, str) _Static_assert(قوت_نما, str) 
#جے_انت

#جے_انت
