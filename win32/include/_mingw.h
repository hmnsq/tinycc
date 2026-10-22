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

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __MINGW_H
#ವ್ಯಾಖ್ಯಾನಿಸು __MINGW_H

/* some winapi files define these before including _mingw.h --> */
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು __cdecl
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು _X86_
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು WIN32
/* <-- */

#ಅನ್ತರ್ಭಾವ <stddef.h>
#ಅನ್ತರ್ಭಾವ <stdarg.h>

#ವ್ಯಾಖ್ಯಾನಿಸು __int8 ಅಕ್ಷರ
#ವ್ಯಾಖ್ಯಾನಿಸು __int16 ಗಿಡ್ಡ
#ವ್ಯಾಖ್ಯಾನಿಸು __int32 ಪೂರ್ಣಾಂಕ
#ವ್ಯಾಖ್ಯಾನಿಸು __int64 ದೀರ್ಘ ದೀರ್ಘ
#ವ್ಯಾಖ್ಯಾನಿಸು _HAVE_INT64

#ವ್ಯಾಖ್ಯಾನಿಸು __cdecl
#ವ್ಯಾಖ್ಯಾನಿಸು __declspec(x) __attribute__((x))
#ವ್ಯಾಖ್ಯಾನಿಸು __unaligned __attribute__((packed))
#ವ್ಯಾಖ್ಯಾನಿಸು __fastcall __attribute__((fastcall))

#ವ್ಯಾಖ್ಯಾನಿಸು __MSVCRT__ 1
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು _MSVCRT_
#ವ್ಯಾಖ್ಯಾನಿಸು __MINGW_IMPORT ಬಾಹ್ಯ __declspec(dllimport)
#ವ್ಯಾಖ್ಯಾನಿಸು __MINGW_ATTRIB_NORETURN __declspec(noreturn)
#ವ್ಯಾಖ್ಯಾನಿಸು __MINGW_ATTRIB_CONST
#ವ್ಯಾಖ್ಯಾನಿಸು __MINGW_ATTRIB_DEPRECATED
#ವ್ಯಾಖ್ಯಾನಿಸು __MINGW_ATTRIB_MALLOC
#ವ್ಯಾಖ್ಯಾನಿಸು __MINGW_ATTRIB_PURE
#ವ್ಯಾಖ್ಯಾನಿಸು __MINGW_ATTRIB_NONNULL(arg)
#ವ್ಯಾಖ್ಯಾನಿಸು __MINGW_NOTHROW
#ವ್ಯಾಖ್ಯಾನಿಸು __GNUC_VA_LIST

#ವ್ಯಾಖ್ಯಾನಿಸು _CRTIMP ಬಾಹ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು __CRT_INLINE ಸ್ಥಿರ __inline__

#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_ALIGN(x) __attribute__((aligned(x)))
#ವ್ಯಾಖ್ಯಾನಿಸು DECLSPEC_ALIGN(x) __attribute__((aligned(x)))
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_PACKING 8
#ವ್ಯಾಖ್ಯಾನಿಸು __CRT_UNALIGNED
#ವ್ಯಾಖ್ಯಾನಿಸು _CONST_RETURN

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TRUNCATE
#ವ್ಯಾಖ್ಯಾನಿಸು _TRUNCATE ((ಗಾತ್ರ_t)-1)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು __CRT_STRINGIZE(ಮೌಲ್ಯ_2) #_Value
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_STRINGIZE(ಮೌಲ್ಯ_2) __CRT_STRINGIZE(ಮೌಲ್ಯ_2)
#ವ್ಯಾಖ್ಯಾನಿಸು __CRT_WIDE(_String) L ## _String
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_WIDE(_String) __CRT_WIDE(_String)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನಿಸು __stdcall
#ಆದರೆ defined(__aarch64__)
#ವ್ಯಾಖ್ಯಾನಿಸು _M_ARM64 1
#ವ್ಯಾಖ್ಯಾನಿಸು _ARM64_ 1
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _AMD64_ 1
#ವ್ಯಾಖ್ಯಾನಿಸು __x86_64 1
#ವ್ಯಾಖ್ಯಾನಿಸು _M_X64 100 /* Visual Studio */
#ವ್ಯಾಖ್ಯಾನಿಸು _M_AMD64 100 /* Visual Studio */
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು __stdcall __attribute__((__stdcall__))
#ವ್ಯಾಖ್ಯಾನಿಸು _X86_ 1
#ವ್ಯಾಖ್ಯಾನಿಸು _M_IX86 300 /* Visual Studio */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __MINGW_USE_VC2005_COMPAT /* time became 64, but not timeval.tv_sec */
# ifndef USE_32_ಬಿಟ್_ಸಮಯ_T
#  define USE_32_ಬಿಟ್_ಸಮಯ_T
# endif
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

/* in stddef.h */
#ವ್ಯಾಖ್ಯಾನಿಸು _SIZE_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _SSIZE_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _PTRDIFF_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WCHAR_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _UINTPTR_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _INTPTR_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು 64

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIME32_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _TIME32_T_DEFINED
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ __time32_t;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIME64_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _TIME64_T_DEFINED
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ ದೀರ್ಘ __time64_t;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ಸಮಯ_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಮಯ_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __time32_t time_t;
#ಇಲ್ಲದಿದ್ದರೆ
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __time64_t time_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WCTYPE_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WCTYPE_T_DEFINED
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ wchar_t wctype_t;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WINT_T
#ವ್ಯಾಖ್ಯಾನಿಸು _WINT_T
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __WINT_TYPE__ wint_t;
#ಆದರೆ_ಅಂತ್ಯ

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ errno_t;
#ವ್ಯಾಖ್ಯಾನಿಸು _ERRCODE_DEFINED

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ threadlocaleinfostruct *pthreadlocinfo;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ threadmbcinfostruct *pthreadmbcinfo;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ localeinfo_struct _locale_tstruct,*_locale_t;

/* for winapi */
#ವ್ಯಾಖ್ಯಾನಿಸು _ANONYMOUS_UNION
#ವ್ಯಾಖ್ಯಾನಿಸು _ANONYMOUS_STRUCT
#ವ್ಯಾಖ್ಯಾನಿಸು DECLSPEC_NORETURN __declspec(noreturn)
#ವ್ಯಾಖ್ಯಾನಿಸು DECLARE_STDCALL_P(type) __stdcall type
#ವ್ಯಾಖ್ಯಾನಿಸು NOSERVICE 1
#ವ್ಯಾಖ್ಯಾನಿಸು NOMCX 1
#ವ್ಯಾಖ್ಯಾನಿಸು NOIME 1
#ವ್ಯಾಖ್ಯಾನಿಸು __INTRIN_H_
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ DUMMYUNIONNAME
#  define DUMMYUNIONNAME
#  define DUMMYUNIONNAME1
#  define DUMMYUNIONNAME2
#  define DUMMYUNIONNAME3
#  define DUMMYUNIONNAME4
#  define DUMMYUNIONNAME5
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ DUMMYSTRUCTNAME
#  define DUMMYSTRUCTNAME
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WINVER
# define WINVER 0x0502
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32_WINNT
# define _WIN32_WINNT 0x502
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು __C89_NAMELESS
#ವ್ಯಾಖ್ಯಾನಿಸು __MINGW_EXTENSION
#ವ್ಯಾಖ್ಯಾನಿಸು WINAPI_FAMILY_ವಿಭಜನೆ(X) 1
#ವ್ಯಾಖ್ಯಾನಿಸು MINGW_HAS_SECURE_API
#ವ್ಯಾಖ್ಯಾನಿಸು WIN32 1

#ಆದರೆ_ಅಂತ್ಯ /* __MINGW_H */
