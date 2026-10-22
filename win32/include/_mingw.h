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

#جيڪڏهن_وصف_نه_ٿيل __MINGW_H
#وصف_ڪريو __MINGW_H

/* some winapi files define these before including _mingw.h --> */
#وصف_رد __cdecl
#وصف_رد _X86_
#وصف_رد WIN32
/* <-- */

#ضمن <stddef.h>
#ضمن <stdarg.h>

#وصف_ڪريو __int8 حرف
#وصف_ڪريو __int16 ننڍو
#وصف_ڪريو __int32 صحيح
#وصف_ڪريو __int64 ڊگهو ڊگهو
#وصف_ڪريو _HAVE_INT64

#وصف_ڪريو __cdecl
#وصف_ڪريو __declspec(x) __attribute__((x))
#وصف_ڪريو __unaligned __attribute__((packed))
#وصف_ڪريو __fastcall __attribute__((fastcall))

#وصف_ڪريو __MSVCRT__ 1
#وصف_رد _MSVCRT_
#وصف_ڪريو __MINGW_IMPORT خارجي __declspec(dllimport)
#وصف_ڪريو __MINGW_ATTRIB_NORETURN __declspec(noreturn)
#وصف_ڪريو __MINGW_ATTRIB_CONST
#وصف_ڪريو __MINGW_ATTRIB_DEPRECATED
#وصف_ڪريو __MINGW_ATTRIB_MALLOC
#وصف_ڪريو __MINGW_ATTRIB_PURE
#وصف_ڪريو __MINGW_ATTRIB_NONNULL(arg)
#وصف_ڪريو __MINGW_NOTHROW
#وصف_ڪريو __GNUC_VA_LIST

#وصف_ڪريو _CRTIMP خارجي
#وصف_ڪريو __CRT_INLINE ساكن __inline__

#وصف_ڪريو _CRT_ALIGN(x) __attribute__((aligned(x)))
#وصف_ڪريو DECLSPEC_ALIGN(x) __attribute__((aligned(x)))
#وصف_ڪريو _CRT_PACKING 8
#وصف_ڪريو __CRT_UNALIGNED
#وصف_ڪريو _CONST_RETURN

#جيڪڏهن_وصف_نه_ٿيل _TRUNCATE
#وصف_ڪريو _TRUNCATE ((سائيز_t)-1)
#جيڪڏهن_پورو

#وصف_ڪريو __CRT_STRINGIZE(قدر_2) #_Value
#وصف_ڪريو _CRT_STRINGIZE(قدر_2) __CRT_STRINGIZE(قدر_2)
#وصف_ڪريو __CRT_WIDE(_String) L ## _String
#وصف_ڪريو _CRT_WIDE(_String) __CRT_WIDE(_String)

#جيڪڏهن_وصف_ٿيل _WIN64
#وصف_ڪريو __stdcall
#إذا defined(__aarch64__)
#وصف_ڪريو _M_ARM64 1
#وصف_ڪريو _ARM64_ 1
#وإلا
#وصف_ڪريو _AMD64_ 1
#وصف_ڪريو __x86_64 1
#وصف_ڪريو _M_X64 100 /* Visual Studio */
#وصف_ڪريو _M_AMD64 100 /* Visual Studio */
#جيڪڏهن_پورو
#وإلا
#وصف_ڪريو __stdcall __attribute__((__stdcall__))
#وصف_ڪريو _X86_ 1
#وصف_ڪريو _M_IX86 300 /* Visual Studio */
#جيڪڏهن_وصف_نه_ٿيل __MINGW_USE_VC2005_COMPAT /* time became 64, but not timeval.tv_sec */
# ifndef USE_32_ٻٽو_انگ_وقت_T
#  define USE_32_ٻٽو_انگ_وقت_T
# endif
#جيڪڏهن_پورو
#جيڪڏهن_پورو

/* in stddef.h */
#وصف_ڪريو _SIZE_T_DEFINED
#وصف_ڪريو _SSIZE_T_DEFINED
#وصف_ڪريو _PTRDIFF_T_DEFINED
#وصف_ڪريو _WCHAR_T_DEFINED
#وصف_ڪريو _UINTPTR_T_DEFINED
#وصف_ڪريو _INTPTR_T_DEFINED
#وصف_ڪريو INTEGRAL_MAX_بٽ 64

#جيڪڏهن_وصف_نه_ٿيل _TIME32_T_DEFINED
#وصف_ڪريو _TIME32_T_DEFINED
تعريفنوع ڊگهو __time32_t;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TIME64_T_DEFINED
#وصف_ڪريو _TIME64_T_DEFINED
تعريفنوع ڊگهو ڊگهو __time64_t;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل وقت_T_DEFINED
#وصف_ڪريو وقت_T_DEFINED
#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
تعريفنوع __time32_t time_t;
#وإلا
تعريفنوع __time64_t time_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WCTYPE_T_DEFINED
#وصف_ڪريو _WCTYPE_T_DEFINED
تعريفنوع wchar_t wctype_t;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WINT_T
#وصف_ڪريو _WINT_T
تعريفنوع __WINT_TYPE__ wint_t;
#جيڪڏهن_پورو

تعريفنوع صحيح errno_t;
#وصف_ڪريو _ERRCODE_DEFINED

تعريفنوع بنية threadlocaleinfostruct *pthreadlocinfo;
تعريفنوع بنية threadmbcinfostruct *pthreadmbcinfo;
تعريفنوع بنية localeinfo_struct _locale_tstruct,*_locale_t;

/* for winapi */
#وصف_ڪريو _ANONYMOUS_UNION
#وصف_ڪريو _ANONYMOUS_STRUCT
#وصف_ڪريو DECLSPEC_NORETURN __declspec(noreturn)
#وصف_ڪريو DECLARE_STDCALL_P(type) __stdcall type
#وصف_ڪريو NOSERVICE 1
#وصف_ڪريو NOMCX 1
#وصف_ڪريو NOIME 1
#وصف_ڪريو __INTRIN_H_
#جيڪڏهن_وصف_نه_ٿيل DUMMYUNIONNAME
#  define DUMMYUNIONNAME
#  define DUMMYUNIONNAME1
#  define DUMMYUNIONNAME2
#  define DUMMYUNIONNAME3
#  define DUMMYUNIONNAME4
#  define DUMMYUNIONNAME5
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل DUMMYSTRUCTNAME
#  define DUMMYSTRUCTNAME
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WINVER
# define WINVER 0x0502
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل _WIN32_WINNT
# define _WIN32_WINNT 0x502
#جيڪڏهن_پورو

#وصف_ڪريو __C89_NAMELESS
#وصف_ڪريو __MINGW_EXTENSION
#وصف_ڪريو WINAPI_FAMILY_حصا_ڪريو(X) 1
#وصف_ڪريو MINGW_HAS_SECURE_API
#وصف_ڪريو WIN32 1

#جيڪڏهن_پورو /* __MINGW_H */
