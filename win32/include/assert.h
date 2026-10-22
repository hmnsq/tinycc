/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __ASSERT_H_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ASSERT_H_

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ NDEBUG
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ਪ੍ਰਤਿਜ੍ਞਾ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪ੍ਰਤਿਜ੍ਞਾ(ਵਿਅੰਜਕ_2) ((ਖਾਲੀ)0)
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_TERMINATE_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_TERMINATE_DEFINED
  ਖਾਲੀ __cdecl __MINGW_NOTHROW ਬਾਹਰ_ਨਿਕਲੋ(ਪੂਰਨ ਕੋਡ_3) __MINGW_ATTRIB_NORETURN;
 _CRTIMP ਖਾਲੀ __cdecl __MINGW_NOTHROW _exit(ਪੂਰਨ ਕੋਡ_3) __MINGW_ATTRIB_NORETURN;
#ਜੇ !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
/* C99 function name */
ਖਾਲੀ __cdecl _Exit(ਪੂਰਨ) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN ਖਾਲੀ __cdecl _Exit(ਪੂਰਨ ਸਥਿਤੀ)
{  _exit(ਸਥਿਤੀ); }
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ ਧੱਕੋ_macro("abort")
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ abort
  ਖਾਲੀ __cdecl __declspec(noreturn) abort(ਖਾਲੀ);
#ਹਦਾਇਤ ਕੱਢੋ_macro("abort")

#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ


ਬਾਹਰੀ ਖਾਲੀ __cdecl _wassert(ਅਚਲ wchar_t *ਸੁਨੇਹਾ_4,ਅਚਲ wchar_t *_File,ਬਿਨਾਨਿਸ਼ਾਨੀ ਸਤਰ_2);
ਬਾਹਰੀ ਖਾਲੀ __cdecl _assert(ਅਚਲ ਅੱਖਰ *, ਅਚਲ ਅੱਖਰ *, ਬਿਨਾਨਿਸ਼ਾਨੀ);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ਪ੍ਰਤਿਜ੍ਞਾ
//#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪ੍ਰਤਿਜ੍ਞਾ(e) ((e) ? (ਖਾਲੀ)0 : _assert(#e, __FILE__, __LINE__))
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ

#ਜੇ (__STDC_VERSION__ >= 201112L) && !defined(static_assert)
/* C11, section 7.2: The macro static_assert expands to _Static_assert. */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ static_assert(ਘਾਤਾਂਕ, str) _Static_assert(ਘਾਤਾਂਕ, str) 
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ
