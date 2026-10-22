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

#నిర్వచితం_కాకపోతే __MINGW_H
#నిర్వచించు __MINGW_H

/* some winapi files define these before including _mingw.h --> */
#నిర్వచనం_రద్దు __cdecl
#నిర్వచనం_రద్దు _X86_
#నిర్వచనం_రద్దు WIN32
/* <-- */

#అన్తర్భావ <stddef.h>
#అన్తర్భావ <stdarg.h>

#నిర్వచించు __int8 అక్షరం
#నిర్వచించు __int16 పొట్టి
#నిర్వచించు __int32 పూర్ణాంకం
#నిర్వచించు __int64 దీర్ఘ దీర్ఘ
#నిర్వచించు _HAVE_INT64

#నిర్వచించు __cdecl
#నిర్వచించు __declspec(x) __attribute__((x))
#నిర్వచించు __unaligned __attribute__((packed))
#నిర్వచించు __fastcall __attribute__((fastcall))

#నిర్వచించు __MSVCRT__ 1
#నిర్వచనం_రద్దు _MSVCRT_
#నిర్వచించు __MINGW_IMPORT బాహ్య __declspec(dllimport)
#నిర్వచించు __MINGW_ATTRIB_NORETURN __declspec(noreturn)
#నిర్వచించు __MINGW_ATTRIB_CONST
#నిర్వచించు __MINGW_ATTRIB_DEPRECATED
#నిర్వచించు __MINGW_ATTRIB_MALLOC
#నిర్వచించు __MINGW_ATTRIB_PURE
#నిర్వచించు __MINGW_ATTRIB_NONNULL(arg)
#నిర్వచించు __MINGW_NOTHROW
#నిర్వచించు __GNUC_VA_LIST

#నిర్వచించు _CRTIMP బాహ్య
#నిర్వచించు __CRT_INLINE స్థిర __inline__

#నిర్వచించు _CRT_ALIGN(x) __attribute__((aligned(x)))
#నిర్వచించు DECLSPEC_ALIGN(x) __attribute__((aligned(x)))
#నిర్వచించు _CRT_PACKING 8
#నిర్వచించు __CRT_UNALIGNED
#నిర్వచించు _CONST_RETURN

#నిర్వచితం_కాకపోతే _TRUNCATE
#నిర్వచించు _TRUNCATE ((కొలత_t)-1)
#అయితే_ముగింపు

#నిర్వచించు __CRT_STRINGIZE(విలువ_2) #_Value
#నిర్వచించు _CRT_STRINGIZE(విలువ_2) __CRT_STRINGIZE(విలువ_2)
#నిర్వచించు __CRT_WIDE(_String) L ## _String
#నిర్వచించు _CRT_WIDE(_String) __CRT_WIDE(_String)

#నిర్వచితమైతే _WIN64
#నిర్వచించు __stdcall
#ఒకవేళ defined(__aarch64__)
#నిర్వచించు _M_ARM64 1
#నిర్వచించు _ARM64_ 1
#లేకపోతే
#నిర్వచించు _AMD64_ 1
#నిర్వచించు __x86_64 1
#నిర్వచించు _M_X64 100 /* Visual Studio */
#నిర్వచించు _M_AMD64 100 /* Visual Studio */
#అయితే_ముగింపు
#లేకపోతే
#నిర్వచించు __stdcall __attribute__((__stdcall__))
#నిర్వచించు _X86_ 1
#నిర్వచించు _M_IX86 300 /* Visual Studio */
#నిర్వచితం_కాకపోతే __MINGW_USE_VC2005_COMPAT /* time became 64, but not timeval.tv_sec */
# ifndef USE_32_బిట్టు_సమయం_T
#  define USE_32_బిట్టు_సమయం_T
# endif
#అయితే_ముగింపు
#అయితే_ముగింపు

/* in stddef.h */
#నిర్వచించు _SIZE_T_DEFINED
#నిర్వచించు _SSIZE_T_DEFINED
#నిర్వచించు _PTRDIFF_T_DEFINED
#నిర్వచించు _WCHAR_T_DEFINED
#నిర్వచించు _UINTPTR_T_DEFINED
#నిర్వచించు _INTPTR_T_DEFINED
#నిర్వచించు INTEGRAL_MAX_బిట్లు 64

#నిర్వచితం_కాకపోతే _TIME32_T_DEFINED
#నిర్వచించు _TIME32_T_DEFINED
రకనిర్వచనం దీర్ఘ __time32_t;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TIME64_T_DEFINED
#నిర్వచించు _TIME64_T_DEFINED
రకనిర్వచనం దీర్ఘ దీర్ఘ __time64_t;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే సమయం_T_DEFINED
#నిర్వచించు సమయం_T_DEFINED
#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
రకనిర్వచనం __time32_t time_t;
#లేకపోతే
రకనిర్వచనం __time64_t time_t;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WCTYPE_T_DEFINED
#నిర్వచించు _WCTYPE_T_DEFINED
రకనిర్వచనం wchar_t wctype_t;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WINT_T
#నిర్వచించు _WINT_T
రకనిర్వచనం __WINT_TYPE__ wint_t;
#అయితే_ముగింపు

రకనిర్వచనం పూర్ణాంకం errno_t;
#నిర్వచించు _ERRCODE_DEFINED

రకనిర్వచనం నిర్మాణం threadlocaleinfostruct *pthreadlocinfo;
రకనిర్వచనం నిర్మాణం threadmbcinfostruct *pthreadmbcinfo;
రకనిర్వచనం నిర్మాణం localeinfo_struct _locale_tstruct,*_locale_t;

/* for winapi */
#నిర్వచించు _ANONYMOUS_UNION
#నిర్వచించు _ANONYMOUS_STRUCT
#నిర్వచించు DECLSPEC_NORETURN __declspec(noreturn)
#నిర్వచించు DECLARE_STDCALL_P(type) __stdcall type
#నిర్వచించు NOSERVICE 1
#నిర్వచించు NOMCX 1
#నిర్వచించు NOIME 1
#నిర్వచించు __INTRIN_H_
#నిర్వచితం_కాకపోతే DUMMYUNIONNAME
#  define DUMMYUNIONNAME
#  define DUMMYUNIONNAME1
#  define DUMMYUNIONNAME2
#  define DUMMYUNIONNAME3
#  define DUMMYUNIONNAME4
#  define DUMMYUNIONNAME5
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే DUMMYSTRUCTNAME
#  define DUMMYSTRUCTNAME
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WINVER
# define WINVER 0x0502
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే _WIN32_WINNT
# define _WIN32_WINNT 0x502
#అయితే_ముగింపు

#నిర్వచించు __C89_NAMELESS
#నిర్వచించు __MINGW_EXTENSION
#నిర్వచించు WINAPI_FAMILY_విభజన(X) 1
#నిర్వచించు MINGW_HAS_SECURE_API
#నిర్వచించు WIN32 1

#అయితే_ముగింపు /* __MINGW_H */
