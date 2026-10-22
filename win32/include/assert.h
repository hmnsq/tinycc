/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل __ASSERT_H_
#وصف_ڪريو __ASSERT_H_

#ضمن <_mingw.h>
#جيڪڏهن_وصف_ٿيل __cplusplus
#ضمن <stdlib.h>
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل NDEBUG
#جيڪڏهن_وصف_نه_ٿيل أكد
#وصف_ڪريو أكد(اظهار_2) ((فراغ)0)
#جيڪڏهن_پورو
#وإلا

#جيڪڏهن_وصف_نه_ٿيل _CRT_TERMINATE_DEFINED
#وصف_ڪريو _CRT_TERMINATE_DEFINED
  فراغ __cdecl __MINGW_NOTHROW ٻاهر_نڪرو(صحيح ڪوڊ_3) __MINGW_ATTRIB_NORETURN;
 _CRTIMP فراغ __cdecl __MINGW_NOTHROW _exit(صحيح ڪوڊ_3) __MINGW_ATTRIB_NORETURN;
#إذا !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
/* C99 function name */
فراغ __cdecl _Exit(صحيح) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN فراغ __cdecl _Exit(صحيح حالت)
{  _exit(حالت); }
#جيڪڏهن_پورو

#هدايت ڌڪو_macro("abort")
#وصف_رد abort
  فراغ __cdecl __declspec(noreturn) abort(فراغ);
#هدايت ڪڍو_macro("abort")

#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو


خارجي فراغ __cdecl _wassert(ثابت wchar_t *پيغام_2,ثابت wchar_t *_File,بنانشان سٽ_2);
خارجي فراغ __cdecl _assert(ثابت حرف *, ثابت حرف *, بنانشان);

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل أكد
//#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))
#وصف_ڪريو أكد(e) ((e) ? (فراغ)0 : _assert(#e, __FILE__, __LINE__))
#جيڪڏهن_پورو

#جيڪڏهن_پورو

#إذا (__STDC_VERSION__ >= 201112L) && !defined(static_assert)
/* C11, section 7.2: The macro static_assert expands to _Static_assert. */
#وصف_ڪريو static_assert(قوت_نما, str) _Static_assert(قوت_نما, str) 
#جيڪڏهن_پورو

#جيڪڏهن_پورو
