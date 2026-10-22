/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ __ASSERT_H_
#تعریف_کرو __ASSERT_H_

#شامل <_mingw.h>
#اگر_تعریف_شدہ __cplusplus
#شامل <stdlib.h>
#اگر_ختم

#اگر_تعریف_شدہ NDEBUG
#اگر_غیر_تعریف_شدہ أكد
#تعریف_کرو أكد(عبارت) ((خالی)0)
#اگر_ختم
#ورنہ

#اگر_غیر_تعریف_شدہ _CRT_TERMINATE_DEFINED
#تعریف_کرو _CRT_TERMINATE_DEFINED
  خالی __cdecl __MINGW_NOTHROW باہر_نکلو(صحیح رمز_3) __MINGW_ATTRIB_NORETURN;
 _CRTIMP خالی __cdecl __MINGW_NOTHROW _exit(صحیح رمز_3) __MINGW_ATTRIB_NORETURN;
#اگر !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
/* C99 function name */
خالی __cdecl _Exit(صحیح) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN خالی __cdecl _Exit(صحیح حالت_2)
{  _exit(حالت_2); }
#اگر_ختم

#ہدایت ڈالو_macro("abort")
#تعریف_منسوخ abort
  خالی __cdecl __declspec(noreturn) abort(خالی);
#ہدایت نکالو_macro("abort")

#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم


خارجی خالی __cdecl _wassert(ثابت wchar_t *پیغام_4,ثابت wchar_t *_File,غیرعلامتی سطر_2);
خارجی خالی __cdecl _assert(ثابت حرف *, ثابت حرف *, غیرعلامتی);

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#اگر_غیر_تعریف_شدہ أكد
//#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))
#تعریف_کرو أكد(e) ((e) ? (خالی)0 : _assert(#e, __FILE__, __LINE__))
#اگر_ختم

#اگر_ختم

#اگر (__STDC_VERSION__ >= 201112L) && !defined(static_assert)
/* C11, section 7.2: The macro static_assert expands to _Static_assert. */
#تعریف_کرو static_assert(قوت_نما, str) _Static_assert(قوت_نما, str) 
#اگر_ختم

#اگر_ختم
