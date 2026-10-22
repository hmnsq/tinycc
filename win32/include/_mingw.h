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

#اگر_غیر_تعریف_شدہ __MINGW_H
#تعریف_کرو __MINGW_H

/* some winapi files define these before including _mingw.h --> */
#تعریف_منسوخ __cdecl
#تعریف_منسوخ _X86_
#تعریف_منسوخ WIN32
/* <-- */

#شامل <stddef.h>
#شامل <stdarg.h>

#تعریف_کرو __int8 حرف
#تعریف_کرو __int16 مختصر
#تعریف_کرو __int32 صحیح
#تعریف_کرو __int64 طویل طویل
#تعریف_کرو _HAVE_INT64

#تعریف_کرو __cdecl
#تعریف_کرو __declspec(x) __attribute__((x))
#تعریف_کرو __unaligned __attribute__((packed))
#تعریف_کرو __fastcall __attribute__((fastcall))

#تعریف_کرو __MSVCRT__ 1
#تعریف_منسوخ _MSVCRT_
#تعریف_کرو __MINGW_IMPORT خارجی __declspec(dllimport)
#تعریف_کرو __MINGW_ATTRIB_NORETURN __declspec(noreturn)
#تعریف_کرو __MINGW_ATTRIB_CONST
#تعریف_کرو __MINGW_ATTRIB_DEPRECATED
#تعریف_کرو __MINGW_ATTRIB_MALLOC
#تعریف_کرو __MINGW_ATTRIB_PURE
#تعریف_کرو __MINGW_ATTRIB_NONNULL(arg)
#تعریف_کرو __MINGW_NOTHROW
#تعریف_کرو __GNUC_VA_LIST

#تعریف_کرو _CRTIMP خارجی
#تعریف_کرو __CRT_INLINE ساکن __inline__

#تعریف_کرو _CRT_ALIGN(x) __attribute__((aligned(x)))
#تعریف_کرو DECLSPEC_ALIGN(x) __attribute__((aligned(x)))
#تعریف_کرو _CRT_PACKING 8
#تعریف_کرو __CRT_UNALIGNED
#تعریف_کرو _CONST_RETURN

#اگر_غیر_تعریف_شدہ _TRUNCATE
#تعریف_کرو _TRUNCATE ((سائز_t)-1)
#اگر_ختم

#تعریف_کرو __CRT_STRINGIZE(قدر_2) #_Value
#تعریف_کرو _CRT_STRINGIZE(قدر_2) __CRT_STRINGIZE(قدر_2)
#تعریف_کرو __CRT_WIDE(_String) L ## _String
#تعریف_کرو _CRT_WIDE(_String) __CRT_WIDE(_String)

#اگر_تعریف_شدہ _WIN64
#تعریف_کرو __stdcall
#اگر defined(__aarch64__)
#تعریف_کرو _M_ARM64 1
#تعریف_کرو _ARM64_ 1
#ورنہ
#تعریف_کرو _AMD64_ 1
#تعریف_کرو __x86_64 1
#تعریف_کرو _M_X64 100 /* Visual Studio */
#تعریف_کرو _M_AMD64 100 /* Visual Studio */
#اگر_ختم
#ورنہ
#تعریف_کرو __stdcall __attribute__((__stdcall__))
#تعریف_کرو _X86_ 1
#تعریف_کرو _M_IX86 300 /* Visual Studio */
#اگر_غیر_تعریف_شدہ __MINGW_USE_VC2005_COMPAT /* time became 64, but not timeval.tv_sec */
# ifndef USE_32_ثنائی_ہندسہ_وقت_T
#  define USE_32_ثنائی_ہندسہ_وقت_T
# endif
#اگر_ختم
#اگر_ختم

/* in stddef.h */
#تعریف_کرو _SIZE_T_DEFINED
#تعریف_کرو _SSIZE_T_DEFINED
#تعریف_کرو _PTRDIFF_T_DEFINED
#تعریف_کرو _WCHAR_T_DEFINED
#تعریف_کرو _UINTPTR_T_DEFINED
#تعریف_کرو _INTPTR_T_DEFINED
#تعریف_کرو INTEGRAL_MAX_بٹ 64

#اگر_غیر_تعریف_شدہ _TIME32_T_DEFINED
#تعریف_کرو _TIME32_T_DEFINED
قسمتعریف طویل __time32_t;
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TIME64_T_DEFINED
#تعریف_کرو _TIME64_T_DEFINED
قسمتعریف طویل طویل __time64_t;
#اگر_ختم

#اگر_غیر_تعریف_شدہ وقت_T_DEFINED
#تعریف_کرو وقت_T_DEFINED
#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
قسمتعریف __time32_t time_t;
#ورنہ
قسمتعریف __time64_t time_t;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WCTYPE_T_DEFINED
#تعریف_کرو _WCTYPE_T_DEFINED
قسمتعریف wchar_t wctype_t;
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WINT_T
#تعریف_کرو _WINT_T
قسمتعریف __WINT_TYPE__ wint_t;
#اگر_ختم

قسمتعریف صحیح errno_t;
#تعریف_کرو _ERRCODE_DEFINED

قسمتعریف ساخت threadlocaleinfostruct *pthreadlocinfo;
قسمتعریف ساخت threadmbcinfostruct *pthreadmbcinfo;
قسمتعریف ساخت localeinfo_struct _locale_tstruct,*_locale_t;

/* for winapi */
#تعریف_کرو _ANONYMOUS_UNION
#تعریف_کرو _ANONYMOUS_STRUCT
#تعریف_کرو DECLSPEC_NORETURN __declspec(noreturn)
#تعریف_کرو DECLARE_STDCALL_P(type) __stdcall type
#تعریف_کرو NOSERVICE 1
#تعریف_کرو NOMCX 1
#تعریف_کرو NOIME 1
#تعریف_کرو __INTRIN_H_
#اگر_غیر_تعریف_شدہ DUMMYUNIONNAME
#  define DUMMYUNIONNAME
#  define DUMMYUNIONNAME1
#  define DUMMYUNIONNAME2
#  define DUMMYUNIONNAME3
#  define DUMMYUNIONNAME4
#  define DUMMYUNIONNAME5
#اگر_ختم
#اگر_غیر_تعریف_شدہ DUMMYSTRUCTNAME
#  define DUMMYSTRUCTNAME
#اگر_ختم
#اگر_غیر_تعریف_شدہ WINVER
# define WINVER 0x0502
#اگر_ختم
#اگر_غیر_تعریف_شدہ _WIN32_WINNT
# define _WIN32_WINNT 0x502
#اگر_ختم

#تعریف_کرو __C89_NAMELESS
#تعریف_کرو __MINGW_EXTENSION
#تعریف_کرو WINAPI_FAMILY_تقسیم(X) 1
#تعریف_کرو MINGW_HAS_SECURE_API
#تعریف_کرو WIN32 1

#اگر_ختم /* __MINGW_H */
