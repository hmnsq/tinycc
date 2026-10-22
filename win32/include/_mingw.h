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

#अगर_अघोषित __MINGW_H
#घोषणा __MINGW_H

/* some winapi files define these before including _mingw.h --> */
#अघोषित __cdecl
#अघोषित _X86_
#अघोषित WIN32
/* <-- */

#समावेश <stddef.h>
#समावेश <stdarg.h>

#घोषणा __int8 अक्षर
#घोषणा __int16 लघु
#घोषणा __int32 पूर्णांक
#घोषणा __int64 दीर्घ दीर्घ
#घोषणा _HAVE_INT64

#घोषणा __cdecl
#घोषणा __declspec(x) __attribute__((x))
#घोषणा __unaligned __attribute__((packed))
#घोषणा __fastcall __attribute__((fastcall))

#घोषणा __MSVCRT__ 1
#अघोषित _MSVCRT_
#घोषणा __MINGW_IMPORT बाह्य __declspec(dllimport)
#घोषणा __MINGW_ATTRIB_NORETURN __declspec(noreturn)
#घोषणा __MINGW_ATTRIB_CONST
#घोषणा __MINGW_ATTRIB_DEPRECATED
#घोषणा __MINGW_ATTRIB_MALLOC
#घोषणा __MINGW_ATTRIB_PURE
#घोषणा __MINGW_ATTRIB_NONNULL(arg)
#घोषणा __MINGW_NOTHROW
#घोषणा __GNUC_VA_LIST

#घोषणा _CRTIMP बाह्य
#घोषणा __CRT_INLINE अटल __inline__

#घोषणा _CRT_ALIGN(x) __attribute__((aligned(x)))
#घोषणा DECLSPEC_ALIGN(x) __attribute__((aligned(x)))
#घोषणा _CRT_PACKING 8
#घोषणा __CRT_UNALIGNED
#घोषणा _CONST_RETURN

#अगर_अघोषित _TRUNCATE
#घोषणा _TRUNCATE ((माप_प्रकार)-1)
#पूर्ण_अगर

#घोषणा __CRT_STRINGIZE(मूल्य_2) #_Value
#घोषणा _CRT_STRINGIZE(मूल्य_2) __CRT_STRINGIZE(मूल्य_2)
#घोषणा __CRT_WIDE(_String) L ## _String
#घोषणा _CRT_WIDE(_String) __CRT_WIDE(_String)

#अगर_घोषित _WIN64
#घोषणा __stdcall
#अगर defined(__aarch64__)
#घोषणा _M_ARM64 1
#घोषणा _ARM64_ 1
#अन्यथा
#घोषणा _AMD64_ 1
#घोषणा __x86_64 1
#घोषणा _M_X64 100 /* Visual Studio */
#घोषणा _M_AMD64 100 /* Visual Studio */
#पूर्ण_अगर
#अन्यथा
#घोषणा __stdcall __attribute__((__stdcall__))
#घोषणा _X86_ 1
#घोषणा _M_IX86 300 /* Visual Studio */
#अगर_अघोषित __MINGW_USE_VC2005_COMPAT /* time became 64, but not timeval.tv_sec */
# ifndef _USE_32BIT_TIME_T
#  define _USE_32BIT_TIME_T
# endif
#पूर्ण_अगर
#पूर्ण_अगर

/* in stddef.h */
#घोषणा _SIZE_T_DEFINED
#घोषणा _SSIZE_T_DEFINED
#घोषणा _PTRDIFF_T_DEFINED
#घोषणा _WCHAR_T_DEFINED
#घोषणा _UINTPTR_T_DEFINED
#घोषणा _INTPTR_T_DEFINED
#घोषणा _INTEGRAL_MAX_BITS 64

#अगर_अघोषित _TIME32_T_DEFINED
#घोषणा _TIME32_T_DEFINED
प्रकार दीर्घ __time32_t;
#पूर्ण_अगर

#अगर_अघोषित _TIME64_T_DEFINED
#घोषणा _TIME64_T_DEFINED
प्रकार दीर्घ दीर्घ __time64_t;
#पूर्ण_अगर

#अगर_अघोषित _TIME_T_DEFINED
#घोषणा _TIME_T_DEFINED
#अगर_घोषित _USE_32BIT_TIME_T
प्रकार __time32_t समय_प्रकार;
#अन्यथा
प्रकार __time64_t समय_प्रकार;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _WCTYPE_T_DEFINED
#घोषणा _WCTYPE_T_DEFINED
प्रकार ब_अक्षर_प्रकार wctype_t;
#पूर्ण_अगर

#अगर_अघोषित _WINT_T
#घोषणा _WINT_T
प्रकार __WINT_TYPE__ wint_t;
#पूर्ण_अगर

प्रकार पूर्णांक errno_t;
#घोषणा _ERRCODE_DEFINED

प्रकार काष्ठा threadlocaleinfostruct *pthreadlocinfo;
प्रकार काष्ठा threadmbcinfostruct *pthreadmbcinfo;
प्रकार काष्ठा localeinfo_struct _locale_tstruct,*_locale_t;

/* for winapi */
#घोषणा _ANONYMOUS_UNION
#घोषणा _ANONYMOUS_STRUCT
#घोषणा DECLSPEC_NORETURN __declspec(noreturn)
#घोषणा DECLARE_STDCALL_P(type) __stdcall type
#घोषणा NOSERVICE 1
#घोषणा NOMCX 1
#घोषणा NOIME 1
#घोषणा __INTRIN_H_
#अगर_अघोषित DUMMYUNIONNAME
#  define DUMMYUNIONNAME
#  define DUMMYUNIONNAME1
#  define DUMMYUNIONNAME2
#  define DUMMYUNIONNAME3
#  define DUMMYUNIONNAME4
#  define DUMMYUNIONNAME5
#पूर्ण_अगर
#अगर_अघोषित DUMMYSTRUCTNAME
#  define DUMMYSTRUCTNAME
#पूर्ण_अगर
#अगर_अघोषित WINVER
# define WINVER 0x0502
#पूर्ण_अगर
#अगर_अघोषित _WIN32_WINNT
# define _WIN32_WINNT 0x502
#पूर्ण_अगर

#घोषणा __C89_NAMELESS
#घोषणा __MINGW_EXTENSION
#घोषणा WINAPI_FAMILY_PARTITION(X) 1
#घोषणा MINGW_HAS_SECURE_API
#घोषणा WIN32 1

#पूर्ण_अगर /* __MINGW_H */
