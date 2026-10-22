/*
 * _mingw.h
 *
 *  This file is for TinyCC and not part of the Mingw32 package.
 *
 *  THIS SOFTWARE IS NOT COPYRIGHTED
 *
 *  This source code is offered for use in the public domain. You may
 *  use, modify or distribute it freely.
 *
 *  This code is distributed in the hope that it will be useful but
 *  WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 *  DISCLAIMED. This includes but is not limited to warranties of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __MINGW_H
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __MINGW_H

/* some winapi files define these before including _mingw.h --> */
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ __cdecl
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ _X86_
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ WIN32
/* <-- */

#ਅਨ੍ਤਰ੍ਭਾਵ <stddef.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdarg.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __int8 ਅੱਖਰ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __int16 ਛੋਟਾ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __int32 ਪੂਰਨ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __int64 ਲੰਮਾ ਲੰਮਾ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _HAVE_INT64

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __cdecl
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __declspec(x) __attribute__((x))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __unaligned __attribute__((packed))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __fastcall __attribute__((fastcall))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __MSVCRT__ 1
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ _MSVCRT_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __MINGW_IMPORT ਬਾਹਰੀ __declspec(dllimport)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __MINGW_ATTRIB_NORETURN __declspec(noreturn)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __MINGW_ATTRIB_CONST
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __MINGW_ATTRIB_DEPRECATED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __MINGW_ATTRIB_MALLOC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __MINGW_ATTRIB_PURE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __MINGW_ATTRIB_NONNULL(arg)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __MINGW_NOTHROW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __GNUC_VA_LIST

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRTIMP ਬਾਹਰੀ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __CRT_INLINE ਸਥਿਰ __inline__

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_ALIGN(x) __attribute__((aligned(x)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLSPEC_ALIGN(x) __attribute__((aligned(x)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_PACKING 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __CRT_UNALIGNED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CONST_RETURN

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TRUNCATE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TRUNCATE ((ਮਾਪ_t)-1)
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __CRT_STRINGIZE(ਮੁੱਲ_2) #_Value
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_STRINGIZE(ਮੁੱਲ_2) __CRT_STRINGIZE(ਮੁੱਲ_2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __CRT_WIDE(_String) L ## _String
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_WIDE(_String) __CRT_WIDE(_String)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __stdcall
#ਜੇ defined(__aarch64__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _M_ARM64 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _ARM64_ 1
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _AMD64_ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __x86_64 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _M_X64 100 /* Visual Studio */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _M_AMD64 100 /* Visual Studio */
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __stdcall __attribute__((__stdcall__))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _X86_ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _M_IX86 300 /* Visual Studio */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __MINGW_USE_VC2005_COMPAT /* time became 64, but not timeval.tv_sec */
# ifndef USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#  define USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
# endif
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

/* in stddef.h */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SIZE_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SSIZE_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _PTRDIFF_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WCHAR_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _UINTPTR_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INTPTR_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INTEGRAL_MAX_ਬਿੱਟ 64

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIME32_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIME32_T_DEFINED
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ __time32_t;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIME64_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIME64_T_DEFINED
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ ਲੰਮਾ __time64_t;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ਸਮਾਂ_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮਾਂ_T_DEFINED
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
ਕਿਸਮਪਰਿਭਾਸ਼ਾ __time32_t time_t;
#ਨਹੀਂਤਾਂ
ਕਿਸਮਪਰਿਭਾਸ਼ਾ __time64_t time_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WCTYPE_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WCTYPE_T_DEFINED
ਕਿਸਮਪਰਿਭਾਸ਼ਾ wchar_t wctype_t;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WINT_T
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WINT_T
ਕਿਸਮਪਰਿਭਾਸ਼ਾ __WINT_TYPE__ wint_t;
#ਜੇ_ਅੰਤ

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ errno_t;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _ERRCODE_DEFINED

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ threadlocaleinfostruct *pthreadlocinfo;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ threadmbcinfostruct *pthreadmbcinfo;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ localeinfo_struct _locale_tstruct,*_locale_t;

/* for winapi */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _ANONYMOUS_UNION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _ANONYMOUS_STRUCT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLSPEC_NORETURN __declspec(noreturn)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLARE_STDCALL_P(type) __stdcall type
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOSERVICE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOMCX 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOIME 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __INTRIN_H_
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ DUMMYUNIONNAME
#  define DUMMYUNIONNAME
#  define DUMMYUNIONNAME1
#  define DUMMYUNIONNAME2
#  define DUMMYUNIONNAME3
#  define DUMMYUNIONNAME4
#  define DUMMYUNIONNAME5
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ DUMMYSTRUCTNAME
#  define DUMMYSTRUCTNAME
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WINVER
# define WINVER 0x0502
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32_WINNT
# define _WIN32_WINNT 0x502
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __C89_NAMELESS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __MINGW_EXTENSION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINAPI_FAMILY_ਹਿੱਸੇ_ਕਰੋ(X) 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MINGW_HAS_SECURE_API
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WIN32 1

#ਜੇ_ਅੰਤ /* __MINGW_H */
