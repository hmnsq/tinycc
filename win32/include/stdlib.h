/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB
#define _INC_STDLIB

#अन्तर्भाव <_mingw.h>
#अन्तर्भाव <limits.h>

#pragma pack(ढकला,_CRT_PACKING)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef रिक्त
#ifdef __cplusplus
#define रिक्त 0
#अन्यथा
#define रिक्त ((शून्य *)0)
#endif
#endif

#define निकास_सफल 0
#define निकास_त्रुटि 1

#ifndef _ONEXIT_T_DEFINED
#define _ONEXIT_T_DEFINED

  प्रकारव्याख्या पूर्णांक (__cdecl *_onexit_t)(शून्य);

#ifndef NO_OLDNAMES
#define onexit_t _onexit_t
#endif
#endif

#ifndef _DIV_T_DEFINED
#define _DIV_T_DEFINED

  प्रकारव्याख्या संरचना _div_t {
    पूर्णांक quot;
    पूर्णांक rem;
  } भाग_प्रकार;

  प्रकारव्याख्या संरचना _ldiv_t {
    दीर्घ quot;
    दीर्घ rem;
  } द_भाग_प्रकार;
#endif

#ifndef _CRT_DOUBLE_DEC
#define _CRT_DOUBLE_DEC

#pragma pack(4)
  प्रकारव्याख्या संरचना {
    अचिन्हित अक्षर ld[10];
  } _LDOUBLE;
#pragma pack()

#define _PTR_LD(x) ((अचिन्हित अक्षर *)(&(x)->ld))

  प्रकारव्याख्या संरचना {
    द्विगुण x;
  } _CRT_DOUBLE;

  प्रकारव्याख्या संरचना {
    दशांश f;
  } _CRT_FLOAT;

#pragma ढकला_macro("long")
#undef दीर्घ

  प्रकारव्याख्या संरचना {
    दीर्घ द्विगुण x;
  } _LONGDOUBLE;

#pragma काढा_macro("long")

#pragma pack(4)
  प्रकारव्याख्या संरचना {
    अचिन्हित अक्षर ld12[12];
  } _LDBL12;
#pragma pack()
#endif

#define अक्रम_उच्च 0x7fff

#ifndef MB_CUR_MAX
#define MB_CUR_MAX ___mb_cur_max_func()
#ifndef __mb_cur_max
#ifdef _MSVCRT_
  बाह्य पूर्णांक __mb_cur_max;
#अन्यथा
#define __mb_cur_max    (*_imp____mb_cur_max)
  बाह्य पूर्णांक *_imp____mb_cur_max;
#endif
#endif
#ifdef _MSVCRT_
  बाह्य पूर्णांक __mbcur_max;
#define ___mb_cur_max_func() (__mb_cur_max)
#अन्यथा
  बाह्य पूर्णांक* _imp____mbcur_max;
#define ___mb_cur_max_func() (*_imp____mb_cur_max)
#endif
#endif

#define __max(a,b) (((a) > (b)) ? (a) : (b))
#define __min(a,b) (((a) < (b)) ? (a) : (b))

#define _MAX_PATH 260
#define _MAX_DRIVE 3
#define _MAX_DIR 256
#define _MAX_FNAME 256
#define _MAX_EXT 256

#define _OUT_TO_DEFAULT 0
#define _OUT_TO_STDERR 1
#define _OUT_TO_MSGBOX 2
#define _REPORT_ERRMODE 3

#define WRITE_ABORT_संदेश 0x1
#define _CALL_REPORTFAULT 0x2

#define _MAX_ENV 32767

  प्रकारव्याख्या शून्य (__cdecl *_purecall_handler)(शून्य);

  _CRTIMP _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(शून्य);

  प्रकारव्याख्या शून्य (__cdecl *_invalid_parameter_handler)(स्थिरांक ब_अक्षर_प्रकार *,स्थिरांक ब_अक्षर_प्रकार *,स्थिरांक ब_अक्षर_प्रकार *,अचिन्हित पूर्णांक,uintptr_t);
  _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(शून्य);

#ifndef _CRT_ERRNO_DEFINED
#define _CRT_ERRNO_DEFINED
  _CRTIMP पूर्णांक *__cdecl _errno(शून्य);
#define त्रुटि_सं (*_errno())
  errno_t __cdecl _set_errno(पूर्णांक मूल्य_2);
  errno_t __cdecl _get_errno(पूर्णांक *मूल्य_2);
#endif
  _CRTIMP अचिन्हित दीर्घ *__cdecl __doserrno(शून्य);
#define _doserrno (*__doserrno())
  errno_t __cdecl _set_doserrno(अचिन्हित दीर्घ मूल्य_2);
  errno_t __cdecl _get_doserrno(अचिन्हित दीर्घ *मूल्य_2);
#ifdef _MSVCRT_
  बाह्य अक्षर *_sys_errlist[];
  बाह्य पूर्णांक _sys_nerr;
#अन्यथा
  _CRTIMP अक्षर *_sys_errlist[1];
  _CRTIMP पूर्णांक _sys_nerr;
#endif
#जर (defined(_X86_) && !defined(__x86_64))
  _CRTIMP पूर्णांक *__cdecl __p___argc(शून्य);
  _CRTIMP अक्षर ***__cdecl __p___argv(शून्य);
  _CRTIMP ब_अक्षर_प्रकार ***__cdecl __p___wargv(शून्य);
  _CRTIMP अक्षर ***__cdecl __p__environ(शून्य);
  _CRTIMP ब_अक्षर_प्रकार ***__cdecl __p__wenviron(शून्य);
  _CRTIMP अक्षर **__cdecl __p__pgmptr(शून्य);
  _CRTIMP ब_अक्षर_प्रकार **__cdecl __p__wpgmptr(शून्य);
#endif
#ifndef __argc
#ifdef _MSVCRT_
  बाह्य पूर्णांक __argc;
#अन्यथा
#define __argc (*_imp____argc)
  बाह्य पूर्णांक *_imp____argc;
#endif
#endif
#ifndef __argv
#ifdef _MSVCRT_
  बाह्य अक्षर **__argv;
#अन्यथा
#define __argv  (*_imp____argv)
  बाह्य अक्षर ***_imp____argv;
#endif
#endif
#ifndef __wargv
#ifdef _MSVCRT_
  बाह्य ब_अक्षर_प्रकार **__wargv;
#अन्यथा
#define __wargv (*_imp____wargv)
  बाह्य ब_अक्षर_प्रकार ***_imp____wargv;
#endif
#endif

#ifdef _POSIX_
  बाह्य अक्षर **environ;
#अन्यथा
#ifndef _environ
#ifdef _MSVCRT_
  बाह्य अक्षर **_environ;
#अन्यथा
#define _environ (*_imp___environ)
  बाह्य अक्षर ***_imp___environ;
#endif
#endif

#ifndef _wenviron
#ifdef _MSVCRT_
  बाह्य ब_अक्षर_प्रकार **_wenviron;
#अन्यथा
#define _wenviron       (*_imp___wenviron)
  बाह्य ब_अक्षर_प्रकार ***_imp___wenviron;
#endif
#endif
#endif

#जर defined __aarch64__
/* something does not work using those from msvcrt.dll */
# undef __argc
# undef __argv
# undef __wargv
# undef _wenviron
# undef _environ
बाह्य पूर्णांक __argc;
बाह्य अक्षर **__argv;
बाह्य ब_अक्षर_प्रकार **__wargv;
बाह्य अक्षर **_environ;
बाह्य ब_अक्षर_प्रकार **_wenviron;
#endif

#ifndef _pgmptr
#ifdef _MSVCRT_
  बाह्य अक्षर *_pgmptr;
#अन्यथा
#define _pgmptr (*_imp___pgmptr)
  बाह्य अक्षर **_imp___pgmptr;
#endif
#endif

#ifndef _wpgmptr
#ifdef _MSVCRT_
  बाह्य ब_अक्षर_प्रकार *_wpgmptr;
#अन्यथा
#define _wpgmptr        (*_imp___wpgmptr)
  बाह्य ब_अक्षर_प्रकार **_imp___wpgmptr;
#endif
#endif
  errno_t __cdecl _get_pgmptr(अक्षर **मूल्य_2);
  errno_t __cdecl _get_wpgmptr(ब_अक्षर_प्रकार **मूल्य_2);
#ifndef _fmode
#ifdef _MSVCRT_
  बाह्य पूर्णांक _fmode;
#अन्यथा
#define _fmode  (*_imp___fmode)
  बाह्य पूर्णांक *_imp___fmode;
#endif
#endif
  _CRTIMP errno_t __cdecl _set_fmode(पूर्णांक _Mode);
  _CRTIMP errno_t __cdecl _get_fmode(पूर्णांक *_PMode);

#ifndef _osplatform
#ifdef _MSVCRT_
  बाह्य अचिन्हित पूर्णांक _osplatform;
#अन्यथा
#define _osplatform (*_imp___osplatform)
  बाह्य अचिन्हित पूर्णांक *_imp___osplatform;
#endif
#endif

#ifndef _osver
#ifdef _MSVCRT_
  बाह्य अचिन्हित पूर्णांक _osver;
#अन्यथा
#define _osver  (*_imp___osver)
  बाह्य अचिन्हित पूर्णांक *_imp___osver;
#endif
#endif

#ifndef _winver
#ifdef _MSVCRT_
  बाह्य अचिन्हित पूर्णांक _winver;
#अन्यथा
#define _winver (*_imp___winver)
  बाह्य अचिन्हित पूर्णांक *_imp___winver;
#endif
#endif

#ifndef _winmajor
#ifdef _MSVCRT_
  बाह्य अचिन्हित पूर्णांक _winmajor;
#अन्यथा
#define _winmajor       (*_imp___winmajor)
  बाह्य अचिन्हित पूर्णांक *_imp___winmajor;
#endif
#endif

#ifndef _winminor
#ifdef _MSVCRT_
  बाह्य अचिन्हित पूर्णांक _winminor;
#अन्यथा
#define _winminor       (*_imp___winminor)
  बाह्य अचिन्हित पूर्णांक *_imp___winminor;
#endif
#endif

  errno_t __cdecl _get_osplatform(अचिन्हित पूर्णांक *मूल्य_2);
  errno_t __cdecl _get_osver(अचिन्हित पूर्णांक *मूल्य_2);
  errno_t __cdecl _get_winver(अचिन्हित पूर्णांक *मूल्य_2);
  errno_t __cdecl _get_winmajor(अचिन्हित पूर्णांक *मूल्य_2);
  errno_t __cdecl _get_winminor(अचिन्हित पूर्णांक *मूल्य_2);
#ifndef _countof
#ifndef __cplusplus
#define _countof(_Array) (आकार(_Array) / आकार(_Array[0]))
#अन्यथा
  बाह्य "C++" {
    ढाँचा <typename _CountofType,माप_प्रकार _SizeOfArray> अक्षर (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];
#define _countof(_Array) आकार(*__countof_helper(_Array))
  }
#endif
#endif

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  शून्य __cdecl __MINGW_NOTHROW निकास(पूर्णांक _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP शून्य __cdecl __MINGW_NOTHROW _exit(पूर्णांक _Code) __MINGW_ATTRIB_NORETURN;
#जर !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  शून्य __cdecl _Exit(पूर्णांक) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN शून्य  __cdecl _Exit(पूर्णांक status)
  {  _exit(status); }
#endif

#pragma ढकला_macro("abort")
#undef पात
  शून्य __cdecl __declspec(noreturn) पात(शून्य);
#pragma काढा_macro("abort")

#endif

  _CRTIMP अचिन्हित पूर्णांक __cdecl _set_abort_behavior(अचिन्हित पूर्णांक _Flags,अचिन्हित पूर्णांक _Mask);

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  पूर्णांक __cdecl असल(पूर्णांक _X);
  दीर्घ __cdecl द_असल(दीर्घ _X);
#endif

#जर _INTEGRAL_MAX_BITS >= 64
  __int64 __cdecl _abs64(__int64);
#endif
  पूर्णांक __cdecl निकास_पर(शून्य (__cdecl *)(शून्य));
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  द्विगुण __cdecl म_से_भ(स्थिरांक अक्षर *_String);
  द्विगुण __cdecl _atof_l(स्थिरांक अक्षर *_String,_locale_t _Locale);
#endif
  पूर्णांक __cdecl म_से_प(स्थिरांक अक्षर *_Str);
  _CRTIMP पूर्णांक __cdecl _atoi_l(स्थिरांक अक्षर *_Str,_locale_t _Locale);
  दीर्घ __cdecl म_से_द(स्थिरांक अक्षर *_Str);
  _CRTIMP दीर्घ __cdecl _atol_l(स्थिरांक अक्षर *_Str,_locale_t _Locale);
#ifndef _CRT_ALGO_DEFINED
#define _CRT_ALGO_DEFINED
  शून्य *__cdecl द्वा_खोज(स्थिरांक शून्य *किल्ली_2,स्थिरांक शून्य *_Base,माप_प्रकार अंक_Of_Elements,माप_प्रकार _SizeOfElements,पूर्णांक (__cdecl *_PtFuncCompare)(स्थिरांक शून्य *,स्थिरांक शून्य *));
  शून्य __cdecl क्विक(शून्य *_Base,माप_प्रकार अंक_Of_Elements,माप_प्रकार _SizeOfElements,पूर्णांक (__cdecl *_PtFuncCompare)(स्थिरांक शून्य *,स्थिरांक शून्य *));
#endif
  अचिन्हित लघु __cdecl _byteswap_ushort(अचिन्हित लघु _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#जर _INTEGRAL_MAX_BITS >= 64
  अचिन्हित __int64 __cdecl _byteswap_uint64(अचिन्हित __int64 _Int64);
#endif
  भाग_प्रकार __cdecl भाग(पूर्णांक _Numerator,पूर्णांक _Denominator);
  अक्षर *__cdecl दो_पर्या(स्थिरांक अक्षर *_VarName);
  _CRTIMP अक्षर *__cdecl _itoa(पूर्णांक मूल्य_2,अक्षर *_Dest,पूर्णांक _Radix);
#जर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP अक्षर *__cdecl _i64toa(__int64 _Val,अक्षर *_DstBuf,पूर्णांक _Radix);
  _CRTIMP अक्षर *__cdecl _ui64toa(अचिन्हित __int64 _Val,अक्षर *_DstBuf,पूर्णांक _Radix);
  _CRTIMP __int64 __cdecl _atoi64(स्थिरांक अक्षर *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(स्थिरांक अक्षर *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(स्थिरांक अक्षर *_String,अक्षर **_EndPtr,पूर्णांक _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(स्थिरांक अक्षर *_String,अक्षर **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
  _CRTIMP अचिन्हित __int64 __cdecl _strtoui64(स्थिरांक अक्षर *_String,अक्षर **_EndPtr,पूर्णांक _Radix);
  _CRTIMP अचिन्हित __int64 __cdecl _strtoui64_l(स्थिरांक अक्षर *_String,अक्षर **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
#endif
  द_भाग_प्रकार __cdecl द_भाग(दीर्घ _Numerator,दीर्घ _Denominator);
  _CRTIMP अक्षर *__cdecl _ltoa(दीर्घ मूल्य_2,अक्षर *_Dest,पूर्णांक _Radix);
  पूर्णांक __cdecl mblen(स्थिरांक अक्षर *_Ch,माप_प्रकार Max_मोजणी);
  _CRTIMP पूर्णांक __cdecl _mblen_l(स्थिरांक अक्षर *_Ch,माप_प्रकार Max_मोजणी,_locale_t _Locale);
  _CRTIMP माप_प्रकार __cdecl _mbstrlen(स्थिरांक अक्षर *_Str);
  _CRTIMP माप_प्रकार __cdecl _mbstrlen_l(स्थिरांक अक्षर *_Str,_locale_t _Locale);
  _CRTIMP माप_प्रकार __cdecl _mbstrnlen(स्थिरांक अक्षर *_Str,माप_प्रकार Max_मोजणी);
  _CRTIMP माप_प्रकार __cdecl _mbstrnlen_l(स्थिरांक अक्षर *_Str,माप_प्रकार Max_मोजणी,_locale_t _Locale);
  पूर्णांक __cdecl mbtowc(ब_अक्षर_प्रकार *_DstCh,स्थिरांक अक्षर *_SrcCh,माप_प्रकार _SrcSizeInBytes);
  _CRTIMP पूर्णांक __cdecl _mbtowc_l(ब_अक्षर_प्रकार *_DstCh,स्थिरांक अक्षर *_SrcCh,माप_प्रकार _SrcSizeInBytes,_locale_t _Locale);
  माप_प्रकार __cdecl mbstowcs(ब_अक्षर_प्रकार *_Dest,स्थिरांक अक्षर *_Source,माप_प्रकार Max_मोजणी);
  _CRTIMP माप_प्रकार __cdecl _mbstowcs_l(ब_अक्षर_प्रकार *_Dest,स्थिरांक अक्षर *_Source,माप_प्रकार Max_मोजणी,_locale_t _Locale);
  पूर्णांक __cdecl अक्रम(शून्य);
  _CRTIMP पूर्णांक __cdecl _set_error_mode(पूर्णांक _Mode);
  शून्य __cdecl बेक्रम(अचिन्हित पूर्णांक _Seed);
  द्विगुण __cdecl म_से_भग्न(स्थिरांक अक्षर *_Str,अक्षर **_EndPtr);
#जर !defined __NO_ISOCEXT  /* in libmingwex.a */
#जर __TINYC__
  __CRT_INLINE दशांश __cdecl strtof (स्थिरांक अक्षर *p, अक्षर ** e) { परत म_से_भग्न(p, e); }
  __CRT_INLINE दीर्घ द्विगुण __cdecl strtold(स्थिरांक अक्षर *p, अक्षर ** e) { परत म_से_भग्न(p, e); }
#अन्यथा
  दशांश __cdecl strtof (स्थिरांक अक्षर * __restrict__, अक्षर ** __restrict__);
  दीर्घ द्विगुण __cdecl strtold(स्थिरांक अक्षर * __restrict__, अक्षर ** __restrict__);
#endif
#अन्यथा
  दशांश __cdecl strtof(स्थिरांक अक्षर *nptr, अक्षर **endptr);
#endif /* __NO_ISOCEXT */
  _CRTIMP द्विगुण __cdecl _strtod_l(स्थिरांक अक्षर *_Str,अक्षर **_EndPtr,_locale_t _Locale);
  दीर्घ __cdecl म_से_दीर्घ(स्थिरांक अक्षर *_Str,अक्षर **_EndPtr,पूर्णांक _Radix);
  _CRTIMP दीर्घ __cdecl _strtol_l(स्थिरांक अक्षर *_Str,अक्षर **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
  अचिन्हित दीर्घ __cdecl म_से_अदीर्घ(स्थिरांक अक्षर *_Str,अक्षर **_EndPtr,पूर्णांक _Radix);
  _CRTIMP अचिन्हित दीर्घ __cdecl _strtoul_l(स्थिरांक अक्षर *_Str,अक्षर **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  पूर्णांक __cdecl प्रणाली(स्थिरांक अक्षर *_Command);
#endif
  _CRTIMP अक्षर *__cdecl _ultoa(अचिन्हित दीर्घ मूल्य_2,अक्षर *_Dest,पूर्णांक _Radix);
  पूर्णांक __cdecl wctomb(अक्षर *_MbCh,ब_अक्षर_प्रकार _WCh);
  _CRTIMP पूर्णांक __cdecl _wctomb_l(अक्षर *_MbCh,ब_अक्षर_प्रकार _WCh,_locale_t _Locale);
  माप_प्रकार __cdecl wcstombs(अक्षर *_Dest,स्थिरांक ब_अक्षर_प्रकार *_Source,माप_प्रकार Max_मोजणी);
  _CRTIMP माप_प्रकार __cdecl _wcstombs_l(अक्षर *_Dest,स्थिरांक ब_अक्षर_प्रकार *_Source,माप_प्रकार Max_मोजणी,_locale_t _Locale);

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  शून्य *__cdecl सुस्मृति(माप_प्रकार अंक_Of_Elements,माप_प्रकार _SizeOfElements);
  शून्य __cdecl मुक्त(शून्य *_Memory);
  शून्य *__cdecl दो_स्मृति(माप_प्रकार _Size);
  शून्य *__cdecl पुनः_स्मृति(शून्य *_Memory,माप_प्रकार _NewSize);
  _CRTIMP शून्य *__cdecl _recalloc(शून्य *_Memory,माप_प्रकार मोजणी_5,माप_प्रकार _Size);
  _CRTIMP शून्य __cdecl _aligned_free(शून्य *_Memory);
  _CRTIMP शून्य *__cdecl _aligned_malloc(माप_प्रकार _Size,माप_प्रकार _Alignment);
  _CRTIMP शून्य *__cdecl _aligned_offset_malloc(माप_प्रकार _Size,माप_प्रकार _Alignment,माप_प्रकार _Offset);
  _CRTIMP शून्य *__cdecl _aligned_realloc(शून्य *_Memory,माप_प्रकार _Size,माप_प्रकार _Alignment);
  _CRTIMP शून्य *__cdecl _aligned_recalloc(शून्य *_Memory,माप_प्रकार मोजणी_5,माप_प्रकार _Size,माप_प्रकार _Alignment);
  _CRTIMP शून्य *__cdecl _aligned_offset_realloc(शून्य *_Memory,माप_प्रकार _Size,माप_प्रकार _Alignment,माप_प्रकार _Offset);
  _CRTIMP शून्य *__cdecl _aligned_offset_recalloc(शून्य *_Memory,माप_प्रकार मोजणी_5,माप_प्रकार _Size,माप_प्रकार _Alignment,माप_प्रकार _Offset);
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP ब_अक्षर_प्रकार *__cdecl _itow(पूर्णांक मूल्य_2,ब_अक्षर_प्रकार *_Dest,पूर्णांक _Radix);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _ltow(दीर्घ मूल्य_2,ब_अक्षर_प्रकार *_Dest,पूर्णांक _Radix);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _ultow(अचिन्हित दीर्घ मूल्य_2,ब_अक्षर_प्रकार *_Dest,पूर्णांक _Radix);
  द्विगुण __cdecl wcstod(स्थिरांक ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr);
  दशांश __cdecl wcstof(स्थिरांक ब_अक्षर_प्रकार *nptr, ब_अक्षर_प्रकार **endptr);
#जर !defined __NO_ISOCEXT /* in libmingwex.a */
  दशांश __cdecl wcstof( स्थिरांक ब_अक्षर_प्रकार * __restrict__, ब_अक्षर_प्रकार ** __restrict__);
  दीर्घ द्विगुण __cdecl wcstold(स्थिरांक ब_अक्षर_प्रकार * __restrict__, ब_अक्षर_प्रकार ** __restrict__);
#endif /* __NO_ISOCEXT */
  _CRTIMP द्विगुण __cdecl _wcstod_l(स्थिरांक ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,_locale_t _Locale);
  दीर्घ __cdecl wcstol(स्थिरांक ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix);
  _CRTIMP दीर्घ __cdecl _wcstol_l(स्थिरांक ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
  अचिन्हित दीर्घ __cdecl wcstoul(स्थिरांक ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix);
  _CRTIMP अचिन्हित दीर्घ __cdecl _wcstoul_l(स्थिरांक ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wgetenv(स्थिरांक ब_अक्षर_प्रकार *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP पूर्णांक __cdecl _wsystem(स्थिरांक ब_अक्षर_प्रकार *_Command);
#endif
  _CRTIMP द्विगुण __cdecl _wtof(स्थिरांक ब_अक्षर_प्रकार *_Str);
  _CRTIMP द्विगुण __cdecl _wtof_l(स्थिरांक ब_अक्षर_प्रकार *_Str,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _wtoi(स्थिरांक ब_अक्षर_प्रकार *_Str);
  _CRTIMP पूर्णांक __cdecl _wtoi_l(स्थिरांक ब_अक्षर_प्रकार *_Str,_locale_t _Locale);
  _CRTIMP दीर्घ __cdecl _wtol(स्थिरांक ब_अक्षर_प्रकार *_Str);
  _CRTIMP दीर्घ __cdecl _wtol_l(स्थिरांक ब_अक्षर_प्रकार *_Str,_locale_t _Locale);

#जर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _i64tow(__int64 _Val,ब_अक्षर_प्रकार *_DstBuf,पूर्णांक _Radix);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _ui64tow(अचिन्हित __int64 _Val,ब_अक्षर_प्रकार *_DstBuf,पूर्णांक _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(स्थिरांक ब_अक्षर_प्रकार *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(स्थिरांक ब_अक्षर_प्रकार *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(स्थिरांक ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(स्थिरांक ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
  _CRTIMP अचिन्हित __int64 __cdecl _wcstoui64(स्थिरांक ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix);
  _CRTIMP अचिन्हित __int64 __cdecl _wcstoui64_l(स्थिरांक ब_अक्षर_प्रकार *_Str ,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#define _CVTBUFSIZE (309+40)
  _CRTIMP अक्षर *__cdecl _fullpath(अक्षर *_FullPath,स्थिरांक अक्षर *_Path,माप_प्रकार _SizeInBytes);
  _CRTIMP अक्षर *__cdecl _ecvt(द्विगुण _Val,पूर्णांक अंक_Of_Digits,पूर्णांक *_PtDec,पूर्णांक *_PtSign);
  _CRTIMP अक्षर *__cdecl _fcvt(द्विगुण _Val,पूर्णांक अंक_Of_Dec,पूर्णांक *_PtDec,पूर्णांक *_PtSign);
  _CRTIMP अक्षर *__cdecl _gcvt(द्विगुण _Val,पूर्णांक अंक_Of_Digits,अक्षर *_DstBuf);
  _CRTIMP पूर्णांक __cdecl _atodbl(_CRT_DOUBLE *_Result,अक्षर *_Str);
  _CRTIMP पूर्णांक __cdecl _atoldbl(_LDOUBLE *_Result,अक्षर *_Str);
  _CRTIMP पूर्णांक __cdecl _atoflt(_CRT_FLOAT *_Result,अक्षर *_Str);
  _CRTIMP पूर्णांक __cdecl _atodbl_l(_CRT_DOUBLE *_Result,अक्षर *_Str,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _atoldbl_l(_LDOUBLE *_Result,अक्षर *_Str,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _atoflt_l(_CRT_FLOAT *_Result,अक्षर *_Str,_locale_t _Locale);
  अचिन्हित दीर्घ __cdecl _lrotl(अचिन्हित दीर्घ _Val,पूर्णांक _Shift);
  अचिन्हित दीर्घ __cdecl _lrotr(अचिन्हित दीर्घ _Val,पूर्णांक _Shift);
  _CRTIMP शून्य __cdecl _makepath(अक्षर *_Path,स्थिरांक अक्षर *_Drive,स्थिरांक अक्षर *_Dir,स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  शून्य __cdecl लिखो_त्रुटि(स्थिरांक अक्षर *Err_संदेश);
#endif
  _CRTIMP पूर्णांक __cdecl _putenv(स्थिरांक अक्षर *_EnvString);
  अचिन्हित पूर्णांक __cdecl _rotl(अचिन्हित पूर्णांक _Val,पूर्णांक _Shift);
#जर _INTEGRAL_MAX_BITS >= 64
  अचिन्हित __int64 __cdecl _rotl64(अचिन्हित __int64 _Val,पूर्णांक _Shift);
#endif
  अचिन्हित पूर्णांक __cdecl _rotr(अचिन्हित पूर्णांक _Val,पूर्णांक _Shift);
#जर _INTEGRAL_MAX_BITS >= 64
  अचिन्हित __int64 __cdecl _rotr64(अचिन्हित __int64 _Val,पूर्णांक _Shift);
#endif
  _CRTIMP शून्य __cdecl _searchenv(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_EnvVar,अक्षर *_ResultPath);
  _CRTIMP शून्य __cdecl _splitpath(स्थिरांक अक्षर *_FullPath,अक्षर *_Drive,अक्षर *_Dir,अक्षर *_Filename,अक्षर *_Ext);
  _CRTIMP शून्य __cdecl _swab(अक्षर *_Buf1,अक्षर *_Buf2,पूर्णांक _SizeInBytes);

#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wfullpath(ब_अक्षर_प्रकार *_FullPath,स्थिरांक ब_अक्षर_प्रकार *_Path,माप_प्रकार Size_In_शब्द);
  _CRTIMP शून्य __cdecl _wmakepath(ब_अक्षर_प्रकार *_ResultPath,स्थिरांक ब_अक्षर_प्रकार *_Drive,स्थिरांक ब_अक्षर_प्रकार *_Dir,स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP शून्य __cdecl _wperror(स्थिरांक ब_अक्षर_प्रकार *Err_संदेश);
#endif
  _CRTIMP पूर्णांक __cdecl _wputenv(स्थिरांक ब_अक्षर_प्रकार *_EnvString);
  _CRTIMP शून्य __cdecl _wsearchenv(स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *_EnvVar,ब_अक्षर_प्रकार *_ResultPath);
  _CRTIMP शून्य __cdecl _wsplitpath(स्थिरांक ब_अक्षर_प्रकार *_FullPath,ब_अक्षर_प्रकार *_Drive,ब_अक्षर_प्रकार *_Dir,ब_अक्षर_प्रकार *_Filename,ब_अक्षर_प्रकार *_Ext);
#endif

  _CRTIMP शून्य __cdecl _beep(अचिन्हित _Frequency,अचिन्हित _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP शून्य __cdecl _seterrormode(पूर्णांक _Mode) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP शून्य __cdecl _sleep(अचिन्हित दीर्घ _Duration) __MINGW_ATTRIB_DEPRECATED;
#endif

#ifndef NO_OLDNAMES
#ifndef _POSIX_
#जर 0
#ifndef __cplusplus
#ifndef NOMINMAX
#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif
#endif
#endif
#endif

#define sys_errlist _sys_errlist
#define sys_nerr _sys_nerr
#define environ _environ
  अक्षर *__cdecl ecvt(द्विगुण _Val,पूर्णांक अंक_Of_Digits,पूर्णांक *_PtDec,पूर्णांक *_PtSign);
  अक्षर *__cdecl fcvt(द्विगुण _Val,पूर्णांक अंक_Of_Dec,पूर्णांक *_PtDec,पूर्णांक *_PtSign);
  अक्षर *__cdecl gcvt(द्विगुण _Val,पूर्णांक अंक_Of_Digits,अक्षर *_DstBuf);
  अक्षर *__cdecl itoa(पूर्णांक _Val,अक्षर *_DstBuf,पूर्णांक _Radix);
  अक्षर *__cdecl ltoa(दीर्घ _Val,अक्षर *_DstBuf,पूर्णांक _Radix);
  पूर्णांक __cdecl putenv(स्थिरांक अक्षर *_EnvString);
  शून्य __cdecl swab(अक्षर *_Buf1,अक्षर *_Buf2,पूर्णांक _SizeInBytes);
  अक्षर *__cdecl ultoa(अचिन्हित दीर्घ _Val,अक्षर *_Dstbuf,पूर्णांक _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#endif
#endif

#जर !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  प्रकारव्याख्या संरचना { दीर्घ दीर्घ quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(दीर्घ दीर्घ, दीर्घ दीर्घ);

  __CRT_INLINE दीर्घ दीर्घ __cdecl llabs(दीर्घ दीर्घ _j) { परत (_j >= 0 ? _j : -_j); }

 #ifdef __TINYC__ /* gr */
  #define strtoll _strtoi64
  #define strtoull _strtoui64
 #अन्यथा
  दीर्घ दीर्घ  __cdecl strtoll(स्थिरांक अक्षर* __restrict__, अक्षर** __restrict, पूर्णांक);
  अचिन्हित दीर्घ दीर्घ  __cdecl strtoull(स्थिरांक अक्षर* __restrict__, अक्षर** __restrict__, पूर्णांक);
 #endif

  /* these are stubs for MS _i64 versions */
  दीर्घ दीर्घ  __cdecl atoll (स्थिरांक अक्षर *);

#ifndef __STRICT_ANSI__
  दीर्घ दीर्घ  __cdecl wtoll (स्थिरांक ब_अक्षर_प्रकार *);
  अक्षर *__cdecl lltoa (दीर्घ दीर्घ, अक्षर *, पूर्णांक);
  अक्षर *__cdecl ulltoa (अचिन्हित दीर्घ दीर्घ , अक्षर *, पूर्णांक);
  ब_अक्षर_प्रकार *__cdecl lltow (दीर्घ दीर्घ, ब_अक्षर_प्रकार *, पूर्णांक);
  ब_अक्षर_प्रकार *__cdecl ulltow (अचिन्हित दीर्घ दीर्घ, ब_अक्षर_प्रकार *, पूर्णांक);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE दीर्घ दीर्घ  __cdecl atoll (स्थिरांक अक्षर * _c) { परत _atoi64 (_c); }
  __CRT_INLINE अक्षर *__cdecl lltoa (दीर्घ दीर्घ _n, अक्षर * _c, पूर्णांक _i) { परत _i64toa (_n, _c, _i); }
  __CRT_INLINE अक्षर *__cdecl ulltoa (अचिन्हित दीर्घ दीर्घ _n, अक्षर * _c, पूर्णांक _i) { परत _ui64toa (_n, _c, _i); }
  __CRT_INLINE दीर्घ दीर्घ  __cdecl wtoll (स्थिरांक ब_अक्षर_प्रकार * _w) { परत _wtoi64 (_w); }
  __CRT_INLINE ब_अक्षर_प्रकार *__cdecl lltow (दीर्घ दीर्घ _n, ब_अक्षर_प्रकार * _w, पूर्णांक _i) { परत _i64tow (_n, _w, _i); }
  __CRT_INLINE ब_अक्षर_प्रकार *__cdecl ulltow (अचिन्हित दीर्घ दीर्घ _n, ब_अक्षर_प्रकार * _w, पूर्णांक _i) { परत _ui64tow (_n, _w, _i); }
#endif /* (__STRICT_ANSI__)  */

#endif /* !__NO_ISOCEXT */

#ifdef __cplusplus
}
#endif

#pragma pack(काढा)

#अन्तर्भाव <sec_api/stdlib_s.h>
#अन्तर्भाव <malloc.h>

#endif
