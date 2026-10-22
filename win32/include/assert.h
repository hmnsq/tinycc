/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده __ASSERT_H_
#تعریف_کن __ASSERT_H_

#ضمن <_mingw.h>
#اگر_تعریف_شده __cplusplus
#ضمن <stdlib.h>
#پایان_اگر

#اگر_تعریف_شده NDEBUG
#اگر_تعریف_نشده أكد
#تعریف_کن أكد(عبارت_2) ((فراغ)0)
#پایان_اگر
#وإلا

#اگر_تعریف_نشده _CRT_TERMINATE_DEFINED
#تعریف_کن _CRT_TERMINATE_DEFINED
  فراغ __cdecl __MINGW_NOTHROW خروج(صحيح کد_3) __MINGW_ATTRIB_NORETURN;
 _CRTIMP فراغ __cdecl __MINGW_NOTHROW _exit(صحيح کد_3) __MINGW_ATTRIB_NORETURN;
#إذا !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
/* C99 function name */
فراغ __cdecl _Exit(صحيح) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN فراغ __cdecl _Exit(صحيح وضعیت)
{  _exit(وضعیت); }
#پایان_اگر

#رهنمود افزودن_macro("abort")
#لغو_تعریف abort
  فراغ __cdecl __declspec(noreturn) abort(فراغ);
#رهنمود برداشت_macro("abort")

#پایان_اگر

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر


خارجي فراغ __cdecl _wassert(ثابت wchar_t *پیام_4,ثابت wchar_t *_File,بیعلامت سطر_2);
خارجي فراغ __cdecl _assert(ثابت حرف *, ثابت حرف *, بیعلامت);

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#اگر_تعریف_نشده أكد
//#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))
#تعریف_کن أكد(e) ((e) ? (فراغ)0 : _assert(#e, __FILE__, __LINE__))
#پایان_اگر

#پایان_اگر

#إذا (__STDC_VERSION__ >= 201112L) && !defined(static_assert)
/* C11, section 7.2: The macro static_assert expands to _Static_assert. */
#تعریف_کن static_assert(نمایی_تابع, str) _Static_assert(نمایی_تابع, str) 
#پایان_اگر

#پایان_اگر
