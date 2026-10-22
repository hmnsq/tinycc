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

#که_نه_تعریف_شوی __MINGW_H
#تعریف_کړه __MINGW_H

/* some winapi files define these before including _mingw.h --> */
#تعریف_لغوه __cdecl
#تعریف_لغوه _X86_
#تعریف_لغوه WIN32
/* <-- */

#ضمن <stddef.h>
#ضمن <stdarg.h>

#تعریف_کړه __int8 حرف
#تعریف_کړه __int16 لنډ
#تعریف_کړه __int32 صحيح
#تعریف_کړه __int64 اوږد اوږد
#تعریف_کړه _HAVE_INT64

#تعریف_کړه __cdecl
#تعریف_کړه __declspec(x) __attribute__((x))
#تعریف_کړه __unaligned __attribute__((packed))
#تعریف_کړه __fastcall __attribute__((fastcall))

#تعریف_کړه __MSVCRT__ 1
#تعریف_لغوه _MSVCRT_
#تعریف_کړه __MINGW_IMPORT خارجي __declspec(dllimport)
#تعریف_کړه __MINGW_ATTRIB_NORETURN __declspec(noreturn)
#تعریف_کړه __MINGW_ATTRIB_CONST
#تعریف_کړه __MINGW_ATTRIB_DEPRECATED
#تعریف_کړه __MINGW_ATTRIB_MALLOC
#تعریف_کړه __MINGW_ATTRIB_PURE
#تعریف_کړه __MINGW_ATTRIB_NONNULL(arg)
#تعریف_کړه __MINGW_NOTHROW
#تعریف_کړه __GNUC_VA_LIST

#تعریف_کړه _CRTIMP خارجي
#تعریف_کړه __CRT_INLINE ساكن __inline__

#تعریف_کړه _CRT_ALIGN(x) __attribute__((aligned(x)))
#تعریف_کړه DECLSPEC_ALIGN(x) __attribute__((aligned(x)))
#تعریف_کړه _CRT_PACKING 8
#تعریف_کړه __CRT_UNALIGNED
#تعریف_کړه _CONST_RETURN

#که_نه_تعریف_شوی _TRUNCATE
#تعریف_کړه _TRUNCATE ((اندازه_t)-1)
#د_که_پای

#تعریف_کړه __CRT_STRINGIZE(ارزښت_2) #_Value
#تعریف_کړه _CRT_STRINGIZE(ارزښت_2) __CRT_STRINGIZE(ارزښت_2)
#تعریف_کړه __CRT_WIDE(_String) L ## _String
#تعریف_کړه _CRT_WIDE(_String) __CRT_WIDE(_String)

#که_تعریف_شوی _WIN64
#تعریف_کړه __stdcall
#إذا defined(__aarch64__)
#تعریف_کړه _M_ARM64 1
#تعریف_کړه _ARM64_ 1
#وإلا
#تعریف_کړه _AMD64_ 1
#تعریف_کړه __x86_64 1
#تعریف_کړه _M_X64 100 /* Visual Studio */
#تعریف_کړه _M_AMD64 100 /* Visual Studio */
#د_که_پای
#وإلا
#تعریف_کړه __stdcall __attribute__((__stdcall__))
#تعریف_کړه _X86_ 1
#تعریف_کړه _M_IX86 300 /* Visual Studio */
#که_نه_تعریف_شوی __MINGW_USE_VC2005_COMPAT /* time became 64, but not timeval.tv_sec */
# ifndef USE_32_بټ_وخت_T
#  define USE_32_بټ_وخت_T
# endif
#د_که_پای
#د_که_پای

/* in stddef.h */
#تعریف_کړه _SIZE_T_DEFINED
#تعریف_کړه _SSIZE_T_DEFINED
#تعریف_کړه _PTRDIFF_T_DEFINED
#تعریف_کړه _WCHAR_T_DEFINED
#تعریف_کړه _UINTPTR_T_DEFINED
#تعریف_کړه _INTPTR_T_DEFINED
#تعریف_کړه INTEGRAL_MAX_بټونه 64

#که_نه_تعریف_شوی _TIME32_T_DEFINED
#تعریف_کړه _TIME32_T_DEFINED
تعريفنوع اوږد __time32_t;
#د_که_پای

#که_نه_تعریف_شوی _TIME64_T_DEFINED
#تعریف_کړه _TIME64_T_DEFINED
تعريفنوع اوږد اوږد __time64_t;
#د_که_پای

#که_نه_تعریف_شوی وخت_T_DEFINED
#تعریف_کړه وخت_T_DEFINED
#که_تعریف_شوی USE_32_بټ_وخت_T
تعريفنوع __time32_t time_t;
#وإلا
تعريفنوع __time64_t time_t;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _WCTYPE_T_DEFINED
#تعریف_کړه _WCTYPE_T_DEFINED
تعريفنوع wchar_t wctype_t;
#د_که_پای

#که_نه_تعریف_شوی _WINT_T
#تعریف_کړه _WINT_T
تعريفنوع __WINT_TYPE__ wint_t;
#د_که_پای

تعريفنوع صحيح errno_t;
#تعریف_کړه _ERRCODE_DEFINED

تعريفنوع بنية threadlocaleinfostruct *pthreadlocinfo;
تعريفنوع بنية threadmbcinfostruct *pthreadmbcinfo;
تعريفنوع بنية localeinfo_struct _locale_tstruct,*_locale_t;

/* for winapi */
#تعریف_کړه _ANONYMOUS_UNION
#تعریف_کړه _ANONYMOUS_STRUCT
#تعریف_کړه DECLSPEC_NORETURN __declspec(noreturn)
#تعریف_کړه DECLARE_STDCALL_P(type) __stdcall type
#تعریف_کړه NOSERVICE 1
#تعریف_کړه NOMCX 1
#تعریف_کړه NOIME 1
#تعریف_کړه __INTRIN_H_
#که_نه_تعریف_شوی DUMMYUNIONNAME
#  define DUMMYUNIONNAME
#  define DUMMYUNIONNAME1
#  define DUMMYUNIONNAME2
#  define DUMMYUNIONNAME3
#  define DUMMYUNIONNAME4
#  define DUMMYUNIONNAME5
#د_که_پای
#که_نه_تعریف_شوی DUMMYSTRUCTNAME
#  define DUMMYSTRUCTNAME
#د_که_پای
#که_نه_تعریف_شوی WINVER
# define WINVER 0x0502
#د_که_پای
#که_نه_تعریف_شوی _WIN32_WINNT
# define _WIN32_WINNT 0x502
#د_که_پای

#تعریف_کړه __C89_NAMELESS
#تعریف_کړه __MINGW_EXTENSION
#تعریف_کړه WINAPI_FAMILY_برخه_کول(X) 1
#تعریف_کړه MINGW_HAS_SECURE_API
#تعریف_کړه WIN32 1

#د_که_پای /* __MINGW_H */
