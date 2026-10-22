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

#यदि_अपरिभाषितम् __MINGW_H
#परिभाषय __MINGW_H

/* some winapi files define these before including _mingw.h --> */
#अपरिभाषय __cdecl
#अपरिभाषय _X86_
#अपरिभाषय WIN32
/* <-- */

#अन्तर्भाव <stddef.h>
#अन्तर्भाव <stdarg.h>

#परिभाषय __int8 वर्ण
#परिभाषय __int16 ह्रस्व
#परिभाषय __int32 पूर्णाङ्क
#परिभाषय __int64 दीर्घ दीर्घ
#परिभाषय _HAVE_INT64

#परिभाषय __cdecl
#परिभाषय __declspec(x) __attribute__((x))
#परिभाषय __unaligned __attribute__((packed))
#परिभाषय __fastcall __attribute__((fastcall))

#परिभाषय __MSVCRT__ 1
#अपरिभाषय _MSVCRT_
#परिभाषय __MINGW_IMPORT बाह्य __declspec(dllimport)
#परिभाषय __MINGW_ATTRIB_NORETURN __declspec(noreturn)
#परिभाषय __MINGW_ATTRIB_CONST
#परिभाषय __MINGW_ATTRIB_DEPRECATED
#परिभाषय __MINGW_ATTRIB_MALLOC
#परिभाषय __MINGW_ATTRIB_PURE
#परिभाषय __MINGW_ATTRIB_NONNULL(arg)
#परिभाषय __MINGW_NOTHROW
#परिभाषय __GNUC_VA_LIST

#परिभाषय _CRTIMP बाह्य
#परिभाषय __CRT_INLINE स्थिर __inline__

#परिभाषय _CRT_ALIGN(x) __attribute__((aligned(x)))
#परिभाषय DECLSPEC_ALIGN(x) __attribute__((aligned(x)))
#परिभाषय _CRT_PACKING 8
#परिभाषय __CRT_UNALIGNED
#परिभाषय _CONST_RETURN

#यदि_अपरिभाषितम् _TRUNCATE
#परिभाषय _TRUNCATE ((आकार_t)-1)
#यदि_अन्तः

#परिभाषय __CRT_STRINGIZE(मानम्_2) #_Value
#परिभाषय _CRT_STRINGIZE(मानम्_2) __CRT_STRINGIZE(मानम्_2)
#परिभाषय __CRT_WIDE(_String) L ## _String
#परिभाषय _CRT_WIDE(_String) __CRT_WIDE(_String)

#यदि_परिभाषितम् _WIN64
#परिभाषय __stdcall
#यदि defined(__aarch64__)
#परिभाषय _M_ARM64 1
#परिभाषय _ARM64_ 1
#अन्यथा
#परिभाषय _AMD64_ 1
#परिभाषय __x86_64 1
#परिभाषय _M_X64 100 /* Visual Studio */
#परिभाषय _M_AMD64 100 /* Visual Studio */
#यदि_अन्तः
#अन्यथा
#परिभाषय __stdcall __attribute__((__stdcall__))
#परिभाषय _X86_ 1
#परिभाषय _M_IX86 300 /* Visual Studio */
#यदि_अपरिभाषितम् __MINGW_USE_VC2005_COMPAT /* time became 64, but not timeval.tv_sec */
# ifndef _USE_32BIT_TIME_T
#  define _USE_32BIT_TIME_T
# endif
#यदि_अन्तः
#यदि_अन्तः

/* in stddef.h */
#परिभाषय _SIZE_T_DEFINED
#परिभाषय _SSIZE_T_DEFINED
#परिभाषय _PTRDIFF_T_DEFINED
#परिभाषय _WCHAR_T_DEFINED
#परिभाषय _UINTPTR_T_DEFINED
#परिभाषय _INTPTR_T_DEFINED
#परिभाषय INTEGRAL_MAX_द्वयङ्काः 64

#यदि_अपरिभाषितम् _TIME32_T_DEFINED
#परिभाषय _TIME32_T_DEFINED
प्रकारनिर्देश दीर्घ __time32_t;
#यदि_अन्तः

#यदि_अपरिभाषितम् _TIME64_T_DEFINED
#परिभाषय _TIME64_T_DEFINED
प्रकारनिर्देश दीर्घ दीर्घ __time64_t;
#यदि_अन्तः

#यदि_अपरिभाषितम् _TIME_T_DEFINED
#परिभाषय _TIME_T_DEFINED
#यदि_परिभाषितम् _USE_32BIT_TIME_T
प्रकारनिर्देश __time32_t time_t;
#अन्यथा
प्रकारनिर्देश __time64_t time_t;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _WCTYPE_T_DEFINED
#परिभाषय _WCTYPE_T_DEFINED
प्रकारनिर्देश wchar_t wctype_t;
#यदि_अन्तः

#यदि_अपरिभाषितम् _WINT_T
#परिभाषय _WINT_T
प्रकारनिर्देश __WINT_TYPE__ wint_t;
#यदि_अन्तः

प्रकारनिर्देश पूर्णाङ्क errno_t;
#परिभाषय _ERRCODE_DEFINED

प्रकारनिर्देश संरचना threadlocaleinfostruct *pthreadlocinfo;
प्रकारनिर्देश संरचना threadmbcinfostruct *pthreadmbcinfo;
प्रकारनिर्देश संरचना localeinfo_struct _locale_tstruct,*_locale_t;

/* for winapi */
#परिभाषय _ANONYMOUS_UNION
#परिभाषय _ANONYMOUS_STRUCT
#परिभाषय DECLSPEC_NORETURN __declspec(noreturn)
#परिभाषय DECLARE_STDCALL_P(type) __stdcall type
#परिभाषय NOSERVICE 1
#परिभाषय NOMCX 1
#परिभाषय NOIME 1
#परिभाषय __INTRIN_H_
#यदि_अपरिभाषितम् DUMMYUNIONNAME
#  define DUMMYUNIONNAME
#  define DUMMYUNIONNAME1
#  define DUMMYUNIONNAME2
#  define DUMMYUNIONNAME3
#  define DUMMYUNIONNAME4
#  define DUMMYUNIONNAME5
#यदि_अन्तः
#यदि_अपरिभाषितम् DUMMYSTRUCTNAME
#  define DUMMYSTRUCTNAME
#यदि_अन्तः
#यदि_अपरिभाषितम् WINVER
# define WINVER 0x0502
#यदि_अन्तः
#यदि_अपरिभाषितम् _WIN32_WINNT
# define _WIN32_WINNT 0x502
#यदि_अन्तः

#परिभाषय __C89_NAMELESS
#परिभाषय __MINGW_EXTENSION
#परिभाषय WINAPI_FAMILY_PARTITION(X) 1
#परिभाषय MINGW_HAS_SECURE_API
#परिभाषय WIN32 1

#यदि_अन्तः /* __MINGW_H */
