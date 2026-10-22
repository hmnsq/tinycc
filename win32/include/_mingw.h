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

#اگر_تعریف_نشده __MINGW_H
#تعریف_کن __MINGW_H

/* some winapi files define these before including _mingw.h --> */
#لغو_تعریف __cdecl
#لغو_تعریف _X86_
#لغو_تعریف WIN32
/* <-- */

#ضمن <stddef.h>
#ضمن <stdarg.h>

#تعریف_کن __int8 حرف
#تعریف_کن __int16 کوتاه
#تعریف_کن __int32 صحيح
#تعریف_کن __int64 دراز دراز
#تعریف_کن _HAVE_INT64

#تعریف_کن __cdecl
#تعریف_کن __declspec(x) __attribute__((x))
#تعریف_کن __unaligned __attribute__((packed))
#تعریف_کن __fastcall __attribute__((fastcall))

#تعریف_کن __MSVCRT__ 1
#لغو_تعریف _MSVCRT_
#تعریف_کن __MINGW_IMPORT خارجي __declspec(dllimport)
#تعریف_کن __MINGW_ATTRIB_NORETURN __declspec(noreturn)
#تعریف_کن __MINGW_ATTRIB_CONST
#تعریف_کن __MINGW_ATTRIB_DEPRECATED
#تعریف_کن __MINGW_ATTRIB_MALLOC
#تعریف_کن __MINGW_ATTRIB_PURE
#تعریف_کن __MINGW_ATTRIB_NONNULL(arg)
#تعریف_کن __MINGW_NOTHROW
#تعریف_کن __GNUC_VA_LIST

#تعریف_کن _CRTIMP خارجي
#تعریف_کن __CRT_INLINE ساكن __inline__

#تعریف_کن _CRT_ALIGN(x) __attribute__((aligned(x)))
#تعریف_کن DECLSPEC_ALIGN(x) __attribute__((aligned(x)))
#تعریف_کن _CRT_PACKING 8
#تعریف_کن __CRT_UNALIGNED
#تعریف_کن _CONST_RETURN

#اگر_تعریف_نشده _TRUNCATE
#تعریف_کن _TRUNCATE ((اندازه_t)-1)
#پایان_اگر

#تعریف_کن __CRT_STRINGIZE(مقدار_2) #_Value
#تعریف_کن _CRT_STRINGIZE(مقدار_2) __CRT_STRINGIZE(مقدار_2)
#تعریف_کن __CRT_WIDE(_String) L ## _String
#تعریف_کن _CRT_WIDE(_String) __CRT_WIDE(_String)

#اگر_تعریف_شده _WIN64
#تعریف_کن __stdcall
#إذا defined(__aarch64__)
#تعریف_کن _M_ARM64 1
#تعریف_کن _ARM64_ 1
#وإلا
#تعریف_کن _AMD64_ 1
#تعریف_کن __x86_64 1
#تعریف_کن _M_X64 100 /* Visual Studio */
#تعریف_کن _M_AMD64 100 /* Visual Studio */
#پایان_اگر
#وإلا
#تعریف_کن __stdcall __attribute__((__stdcall__))
#تعریف_کن _X86_ 1
#تعریف_کن _M_IX86 300 /* Visual Studio */
#اگر_تعریف_نشده __MINGW_USE_VC2005_COMPAT /* time became 64, but not timeval.tv_sec */
# ifndef USE_32_بیت_زمان_T
#  define USE_32_بیت_زمان_T
# endif
#پایان_اگر
#پایان_اگر

/* in stddef.h */
#تعریف_کن _SIZE_T_DEFINED
#تعریف_کن _SSIZE_T_DEFINED
#تعریف_کن _PTRDIFF_T_DEFINED
#تعریف_کن _WCHAR_T_DEFINED
#تعریف_کن _UINTPTR_T_DEFINED
#تعریف_کن _INTPTR_T_DEFINED
#تعریف_کن INTEGRAL_MAX_بیتها 64

#اگر_تعریف_نشده _TIME32_T_DEFINED
#تعریف_کن _TIME32_T_DEFINED
تعريفنوع دراز __time32_t;
#پایان_اگر

#اگر_تعریف_نشده _TIME64_T_DEFINED
#تعریف_کن _TIME64_T_DEFINED
تعريفنوع دراز دراز __time64_t;
#پایان_اگر

#اگر_تعریف_نشده زمان_T_DEFINED
#تعریف_کن زمان_T_DEFINED
#اگر_تعریف_شده USE_32_بیت_زمان_T
تعريفنوع __time32_t time_t;
#وإلا
تعريفنوع __time64_t time_t;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _WCTYPE_T_DEFINED
#تعریف_کن _WCTYPE_T_DEFINED
تعريفنوع wchar_t wctype_t;
#پایان_اگر

#اگر_تعریف_نشده _WINT_T
#تعریف_کن _WINT_T
تعريفنوع __WINT_TYPE__ wint_t;
#پایان_اگر

تعريفنوع صحيح errno_t;
#تعریف_کن _ERRCODE_DEFINED

تعريفنوع بنية threadlocaleinfostruct *pthreadlocinfo;
تعريفنوع بنية threadmbcinfostruct *pthreadmbcinfo;
تعريفنوع بنية localeinfo_struct _locale_tstruct,*_locale_t;

/* for winapi */
#تعریف_کن _ANONYMOUS_UNION
#تعریف_کن _ANONYMOUS_STRUCT
#تعریف_کن DECLSPEC_NORETURN __declspec(noreturn)
#تعریف_کن DECLARE_STDCALL_P(type) __stdcall type
#تعریف_کن NOSERVICE 1
#تعریف_کن NOMCX 1
#تعریف_کن NOIME 1
#تعریف_کن __INTRIN_H_
#اگر_تعریف_نشده DUMMYUNIONNAME
#  define DUMMYUNIONNAME
#  define DUMMYUNIONNAME1
#  define DUMMYUNIONNAME2
#  define DUMMYUNIONNAME3
#  define DUMMYUNIONNAME4
#  define DUMMYUNIONNAME5
#پایان_اگر
#اگر_تعریف_نشده DUMMYSTRUCTNAME
#  define DUMMYSTRUCTNAME
#پایان_اگر
#اگر_تعریف_نشده WINVER
# define WINVER 0x0502
#پایان_اگر
#اگر_تعریف_نشده _WIN32_WINNT
# define _WIN32_WINNT 0x502
#پایان_اگر

#تعریف_کن __C89_NAMELESS
#تعریف_کن __MINGW_EXTENSION
#تعریف_کن WINAPI_FAMILY_افراز(X) 1
#تعریف_کن MINGW_HAS_SECURE_API
#تعریف_کن WIN32 1

#پایان_اگر /* __MINGW_H */
