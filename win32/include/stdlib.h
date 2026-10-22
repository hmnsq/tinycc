/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB
#define _INC_STDLIB

#अन्तर्भाव <_mingw.h>
#अन्तर्भाव <limits.h>

#pragma pack(प्रक्षिप,_CRT_PACKING)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef रिक्त
#ifdef __cplusplus
#define रिक्त 0
#अञ्ञथा
#define रिक्त ((शून्य *)0)
#endif
#endif

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#ifndef _ONEXIT_T_DEFINED
#define _ONEXIT_T_DEFINED

  प्रकारनिर्देश पूर्णाङ्क (__cdecl *_onexit_t)(शून्य);

#ifndef NO_OLDNAMES
#define onexit_t _onexit_t
#endif
#endif

#ifndef _DIV_T_DEFINED
#define _DIV_T_DEFINED

  प्रकारनिर्देश संरचना _div_t {
    पूर्णाङ्क quot;
    पूर्णाङ्क rem;
  } div_t;

  प्रकारनिर्देश संरचना _ldiv_t {
    long quot;
    long rem;
  } ldiv_t;
#endif

#ifndef _CRT_DOUBLE_DEC
#define _CRT_DOUBLE_DEC

#pragma pack(4)
  प्रकारनिर्देश संरचना {
    unsigned वर्ण ld[10];
  } _LDOUBLE;
#pragma pack()

#define _PTR_LD(x) ((unsigned वर्ण *)(&(x)->ld))

  प्रकारनिर्देश संरचना {
    द्विगुण x;
  } _CRT_DOUBLE;

  प्रकारनिर्देश संरचना {
    भिन्न f;
  } _CRT_FLOAT;

#pragma प्रक्षिप_macro("long")
#undef long

  प्रकारनिर्देश संरचना {
    long द्विगुण x;
  } _LONGDOUBLE;

#pragma निष्कासय_macro("long")

#pragma pack(4)
  प्रकारनिर्देश संरचना {
    unsigned वर्ण ld12[12];
  } _LDBL12;
#pragma pack()
#endif

#define RAND_MAX 0x7fff

#ifndef MB_CUR_MAX
#define MB_CUR_MAX ___mb_cur_max_func()
#ifndef __mb_cur_max
#ifdef _MSVCRT_
  बाह्य पूर्णाङ्क __mb_cur_max;
#अञ्ञथा
#define __mb_cur_max    (*_imp____mb_cur_max)
  बाह्य पूर्णाङ्क *_imp____mb_cur_max;
#endif
#endif
#ifdef _MSVCRT_
  बाह्य पूर्णाङ्क __mbcur_max;
#define ___mb_cur_max_func() (__mb_cur_max)
#अञ्ञथा
  बाह्य पूर्णाङ्क* _imp____mbcur_max;
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

#define WRITE_ABORT_सन्देशः 0x1
#define _CALL_REPORTFAULT 0x2

#define _MAX_ENV 32767

  प्रकारनिर्देश शून्य (__cdecl *_purecall_handler)(शून्य);

  _CRTIMP _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(शून्य);

  प्रकारनिर्देश शून्य (__cdecl *_invalid_parameter_handler)(ध्रुव wchar_t *,ध्रुव wchar_t *,ध्रुव wchar_t *,unsigned पूर्णाङ्क,uintptr_t);
  _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(शून्य);

#ifndef _CRT_ERRNO_DEFINED
#define _CRT_ERRNO_DEFINED
  _CRTIMP पूर्णाङ्क *__cdecl _errno(शून्य);
#define errno (*_errno())
  errno_t __cdecl _set_errno(पूर्णाङ्क मानम्_2);
  errno_t __cdecl _get_errno(पूर्णाङ्क *मानम्_2);
#endif
  _CRTIMP unsigned long *__cdecl __doserrno(शून्य);
#define _doserrno (*__doserrno())
  errno_t __cdecl _set_doserrno(unsigned long मानम्_2);
  errno_t __cdecl _get_doserrno(unsigned long *मानम्_2);
#ifdef _MSVCRT_
  बाह्य वर्ण *_sys_errlist[];
  बाह्य पूर्णाङ्क _sys_nerr;
#अञ्ञथा
  _CRTIMP वर्ण *_sys_errlist[1];
  _CRTIMP पूर्णाङ्क _sys_nerr;
#endif
#सचे (defined(_X86_) && !defined(__x86_64))
  _CRTIMP पूर्णाङ्क *__cdecl __p___argc(शून्य);
  _CRTIMP वर्ण ***__cdecl __p___argv(शून्य);
  _CRTIMP wchar_t ***__cdecl __p___wargv(शून्य);
  _CRTIMP वर्ण ***__cdecl __p__environ(शून्य);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(शून्य);
  _CRTIMP वर्ण **__cdecl __p__pgmptr(शून्य);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(शून्य);
#endif
#ifndef __argc
#ifdef _MSVCRT_
  बाह्य पूर्णाङ्क __argc;
#अञ्ञथा
#define __argc (*_imp____argc)
  बाह्य पूर्णाङ्क *_imp____argc;
#endif
#endif
#ifndef __argv
#ifdef _MSVCRT_
  बाह्य वर्ण **__argv;
#अञ्ञथा
#define __argv  (*_imp____argv)
  बाह्य वर्ण ***_imp____argv;
#endif
#endif
#ifndef __wargv
#ifdef _MSVCRT_
  बाह्य wchar_t **__wargv;
#अञ्ञथा
#define __wargv (*_imp____wargv)
  बाह्य wchar_t ***_imp____wargv;
#endif
#endif

#ifdef _POSIX_
  बाह्य वर्ण **environ;
#अञ्ञथा
#ifndef _environ
#ifdef _MSVCRT_
  बाह्य वर्ण **_environ;
#अञ्ञथा
#define _environ (*_imp___environ)
  बाह्य वर्ण ***_imp___environ;
#endif
#endif

#ifndef _wenviron
#ifdef _MSVCRT_
  बाह्य wchar_t **_wenviron;
#अञ्ञथा
#define _wenviron       (*_imp___wenviron)
  बाह्य wchar_t ***_imp___wenviron;
#endif
#endif
#endif

#सचे defined __aarch64__
/* something does not work using those from msvcrt.dll */
# undef __argc
# undef __argv
# undef __wargv
# undef _wenviron
# undef _environ
बाह्य पूर्णाङ्क __argc;
बाह्य वर्ण **__argv;
बाह्य wchar_t **__wargv;
बाह्य वर्ण **_environ;
बाह्य wchar_t **_wenviron;
#endif

#ifndef _pgmptr
#ifdef _MSVCRT_
  बाह्य वर्ण *_pgmptr;
#अञ्ञथा
#define _pgmptr (*_imp___pgmptr)
  बाह्य वर्ण **_imp___pgmptr;
#endif
#endif

#ifndef _wpgmptr
#ifdef _MSVCRT_
  बाह्य wchar_t *_wpgmptr;
#अञ्ञथा
#define _wpgmptr        (*_imp___wpgmptr)
  बाह्य wchar_t **_imp___wpgmptr;
#endif
#endif
  errno_t __cdecl _get_pgmptr(वर्ण **मानम्_2);
  errno_t __cdecl _get_wpgmptr(wchar_t **मानम्_2);
#ifndef _fmode
#ifdef _MSVCRT_
  बाह्य पूर्णाङ्क _fmode;
#अञ्ञथा
#define _fmode  (*_imp___fmode)
  बाह्य पूर्णाङ्क *_imp___fmode;
#endif
#endif
  _CRTIMP errno_t __cdecl _set_fmode(पूर्णाङ्क _Mode);
  _CRTIMP errno_t __cdecl _get_fmode(पूर्णाङ्क *_PMode);

#ifndef _osplatform
#ifdef _MSVCRT_
  बाह्य unsigned पूर्णाङ्क _osplatform;
#अञ्ञथा
#define _osplatform (*_imp___osplatform)
  बाह्य unsigned पूर्णाङ्क *_imp___osplatform;
#endif
#endif

#ifndef _osver
#ifdef _MSVCRT_
  बाह्य unsigned पूर्णाङ्क _osver;
#अञ्ञथा
#define _osver  (*_imp___osver)
  बाह्य unsigned पूर्णाङ्क *_imp___osver;
#endif
#endif

#ifndef _winver
#ifdef _MSVCRT_
  बाह्य unsigned पूर्णाङ्क _winver;
#अञ्ञथा
#define _winver (*_imp___winver)
  बाह्य unsigned पूर्णाङ्क *_imp___winver;
#endif
#endif

#ifndef _winmajor
#ifdef _MSVCRT_
  बाह्य unsigned पूर्णाङ्क _winmajor;
#अञ्ञथा
#define _winmajor       (*_imp___winmajor)
  बाह्य unsigned पूर्णाङ्क *_imp___winmajor;
#endif
#endif

#ifndef _winminor
#ifdef _MSVCRT_
  बाह्य unsigned पूर्णाङ्क _winminor;
#अञ्ञथा
#define _winminor       (*_imp___winminor)
  बाह्य unsigned पूर्णाङ्क *_imp___winminor;
#endif
#endif

  errno_t __cdecl _get_osplatform(unsigned पूर्णाङ्क *मानम्_2);
  errno_t __cdecl _get_osver(unsigned पूर्णाङ्क *मानम्_2);
  errno_t __cdecl _get_winver(unsigned पूर्णाङ्क *मानम्_2);
  errno_t __cdecl _get_winmajor(unsigned पूर्णाङ्क *मानम्_2);
  errno_t __cdecl _get_winminor(unsigned पूर्णाङ्क *मानम्_2);
#ifndef _countof
#ifndef __cplusplus
#define _countof(_Array) (परिमाण(_Array) / परिमाण(_Array[0]))
#अञ्ञथा
  बाह्य "C++" {
    template <typename _CountofType,size_t _SizeOfArray> वर्ण (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];
#define _countof(_Array) परिमाण(*__countof_helper(_Array))
  }
#endif
#endif

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  शून्य __cdecl __MINGW_NOTHROW exit(पूर्णाङ्क _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP शून्य __cdecl __MINGW_NOTHROW _exit(पूर्णाङ्क _Code) __MINGW_ATTRIB_NORETURN;
#सचे !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  शून्य __cdecl _Exit(पूर्णाङ्क) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN शून्य  __cdecl _Exit(पूर्णाङ्क status)
  {  _exit(status); }
#endif

#pragma प्रक्षिप_macro("abort")
#undef abort
  शून्य __cdecl __declspec(noreturn) abort(शून्य);
#pragma निष्कासय_macro("abort")

#endif

  _CRTIMP unsigned पूर्णाङ्क __cdecl _set_abort_behavior(unsigned पूर्णाङ्क _Flags,unsigned पूर्णाङ्क _Mask);

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  पूर्णाङ्क __cdecl abs(पूर्णाङ्क _X);
  long __cdecl labs(long _X);
#endif

#सचे _INTEGRAL_MAX_BITS >= 64
  __int64 __cdecl _abs64(__int64);
#endif
  पूर्णाङ्क __cdecl atexit(शून्य (__cdecl *)(शून्य));
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  द्विगुण __cdecl atof(ध्रुव वर्ण *_String);
  द्विगुण __cdecl _atof_l(ध्रुव वर्ण *_String,_locale_t _Locale);
#endif
  पूर्णाङ्क __cdecl atoi(ध्रुव वर्ण *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _atoi_l(ध्रुव वर्ण *_Str,_locale_t _Locale);
  long __cdecl atol(ध्रुव वर्ण *_Str);
  _CRTIMP long __cdecl _atol_l(ध्रुव वर्ण *_Str,_locale_t _Locale);
#ifndef _CRT_ALGO_DEFINED
#define _CRT_ALGO_DEFINED
  शून्य *__cdecl bsearch(ध्रुव शून्य *कुञ्चिका_2,ध्रुव शून्य *_Base,size_t अङ्कः_Of_Elements,size_t _SizeOfElements,पूर्णाङ्क (__cdecl *_PtFuncCompare)(ध्रुव शून्य *,ध्रुव शून्य *));
  शून्य __cdecl qsort(शून्य *_Base,size_t अङ्कः_Of_Elements,size_t _SizeOfElements,पूर्णाङ्क (__cdecl *_PtFuncCompare)(ध्रुव शून्य *,ध्रुव शून्य *));
#endif
  unsigned short __cdecl _byteswap_ushort(unsigned short _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#सचे _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Int64);
#endif
  div_t __cdecl div(पूर्णाङ्क _Numerator,पूर्णाङ्क _Denominator);
  वर्ण *__cdecl getenv(ध्रुव वर्ण *_VarName);
  _CRTIMP वर्ण *__cdecl _itoa(पूर्णाङ्क मानम्_2,वर्ण *_Dest,पूर्णाङ्क _Radix);
#सचे _INTEGRAL_MAX_BITS >= 64
  _CRTIMP वर्ण *__cdecl _i64toa(__int64 _Val,वर्ण *_DstBuf,पूर्णाङ्क _Radix);
  _CRTIMP वर्ण *__cdecl _ui64toa(unsigned __int64 _Val,वर्ण *_DstBuf,पूर्णाङ्क _Radix);
  _CRTIMP __int64 __cdecl _atoi64(ध्रुव वर्ण *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(ध्रुव वर्ण *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(ध्रुव वर्ण *_String,वर्ण **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(ध्रुव वर्ण *_String,वर्ण **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _strtoui64(ध्रुव वर्ण *_String,वर्ण **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP unsigned __int64 __cdecl _strtoui64_l(ध्रुव वर्ण *_String,वर्ण **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
#endif
  ldiv_t __cdecl ldiv(long _Numerator,long _Denominator);
  _CRTIMP वर्ण *__cdecl _ltoa(long मानम्_2,वर्ण *_Dest,पूर्णाङ्क _Radix);
  पूर्णाङ्क __cdecl mblen(ध्रुव वर्ण *_Ch,size_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _mblen_l(ध्रुव वर्ण *_Ch,size_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrlen(ध्रुव वर्ण *_Str);
  _CRTIMP size_t __cdecl _mbstrlen_l(ध्रुव वर्ण *_Str,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrnlen(ध्रुव वर्ण *_Str,size_t Max_गणनम्);
  _CRTIMP size_t __cdecl _mbstrnlen_l(ध्रुव वर्ण *_Str,size_t Max_गणनम्,_locale_t _Locale);
  पूर्णाङ्क __cdecl mbtowc(wchar_t *_DstCh,ध्रुव वर्ण *_SrcCh,size_t _SrcSizeInBytes);
  _CRTIMP पूर्णाङ्क __cdecl _mbtowc_l(wchar_t *_DstCh,ध्रुव वर्ण *_SrcCh,size_t _SrcSizeInBytes,_locale_t _Locale);
  size_t __cdecl mbstowcs(wchar_t *_Dest,ध्रुव वर्ण *_Source,size_t Max_गणनम्);
  _CRTIMP size_t __cdecl _mbstowcs_l(wchar_t *_Dest,ध्रुव वर्ण *_Source,size_t Max_गणनम्,_locale_t _Locale);
  पूर्णाङ्क __cdecl rand(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _set_error_mode(पूर्णाङ्क _Mode);
  शून्य __cdecl srand(unsigned पूर्णाङ्क _Seed);
  द्विगुण __cdecl strtod(ध्रुव वर्ण *_Str,वर्ण **_EndPtr);
#सचे !defined __NO_ISOCEXT  /* in libmingwex.a */
#सचे __TINYC__
  __CRT_INLINE भिन्न __cdecl strtof (ध्रुव वर्ण *p, वर्ण ** e) { पटिनिवत्त strtod(p, e); }
  __CRT_INLINE long द्विगुण __cdecl strtold(ध्रुव वर्ण *p, वर्ण ** e) { पटिनिवत्त strtod(p, e); }
#अञ्ञथा
  भिन्न __cdecl strtof (ध्रुव वर्ण * __restrict__, वर्ण ** __restrict__);
  long द्विगुण __cdecl strtold(ध्रुव वर्ण * __restrict__, वर्ण ** __restrict__);
#endif
#अञ्ञथा
  भिन्न __cdecl strtof(ध्रुव वर्ण *nptr, वर्ण **endptr);
#endif /* __NO_ISOCEXT */
  _CRTIMP द्विगुण __cdecl _strtod_l(ध्रुव वर्ण *_Str,वर्ण **_EndPtr,_locale_t _Locale);
  long __cdecl strtol(ध्रुव वर्ण *_Str,वर्ण **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP long __cdecl _strtol_l(ध्रुव वर्ण *_Str,वर्ण **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
  unsigned long __cdecl strtoul(ध्रुव वर्ण *_Str,वर्ण **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP unsigned long __cdecl _strtoul_l(ध्रुव वर्ण *_Str,वर्ण **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  पूर्णाङ्क __cdecl system(ध्रुव वर्ण *_Command);
#endif
  _CRTIMP वर्ण *__cdecl _ultoa(unsigned long मानम्_2,वर्ण *_Dest,पूर्णाङ्क _Radix);
  पूर्णाङ्क __cdecl wctomb(वर्ण *_MbCh,wchar_t _WCh);
  _CRTIMP पूर्णाङ्क __cdecl _wctomb_l(वर्ण *_MbCh,wchar_t _WCh,_locale_t _Locale);
  size_t __cdecl wcstombs(वर्ण *_Dest,ध्रुव wchar_t *_Source,size_t Max_गणनम्);
  _CRTIMP size_t __cdecl _wcstombs_l(वर्ण *_Dest,ध्रुव wchar_t *_Source,size_t Max_गणनम्,_locale_t _Locale);

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  शून्य *__cdecl calloc(size_t अङ्कः_Of_Elements,size_t _SizeOfElements);
  शून्य __cdecl मुक्त(शून्य *_Memory);
  शून्य *__cdecl malloc(size_t _Size);
  शून्य *__cdecl realloc(शून्य *_Memory,size_t _NewSize);
  _CRTIMP शून्य *__cdecl _recalloc(शून्य *_Memory,size_t गणनम्_5,size_t _Size);
  _CRTIMP शून्य __cdecl _aligned_free(शून्य *_Memory);
  _CRTIMP शून्य *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP शून्य *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP शून्य *__cdecl _aligned_realloc(शून्य *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP शून्य *__cdecl _aligned_recalloc(शून्य *_Memory,size_t गणनम्_5,size_t _Size,size_t _Alignment);
  _CRTIMP शून्य *__cdecl _aligned_offset_realloc(शून्य *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP शून्य *__cdecl _aligned_offset_recalloc(शून्य *_Memory,size_t गणनम्_5,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(पूर्णाङ्क मानम्_2,wchar_t *_Dest,पूर्णाङ्क _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long मानम्_2,wchar_t *_Dest,पूर्णाङ्क _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long मानम्_2,wchar_t *_Dest,पूर्णाङ्क _Radix);
  द्विगुण __cdecl wcstod(ध्रुव wchar_t *_Str,wchar_t **_EndPtr);
  भिन्न __cdecl wcstof(ध्रुव wchar_t *nptr, wchar_t **endptr);
#सचे !defined __NO_ISOCEXT /* in libmingwex.a */
  भिन्न __cdecl wcstof( ध्रुव wchar_t * __restrict__, wchar_t ** __restrict__);
  long द्विगुण __cdecl wcstold(ध्रुव wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  _CRTIMP द्विगुण __cdecl _wcstod_l(ध्रुव wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  long __cdecl wcstol(ध्रुव wchar_t *_Str,wchar_t **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP long __cdecl _wcstol_l(ध्रुव wchar_t *_Str,wchar_t **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(ध्रुव wchar_t *_Str,wchar_t **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(ध्रुव wchar_t *_Str,wchar_t **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ध्रुव wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP पूर्णाङ्क __cdecl _wsystem(ध्रुव wchar_t *_Command);
#endif
  _CRTIMP द्विगुण __cdecl _wtof(ध्रुव wchar_t *_Str);
  _CRTIMP द्विगुण __cdecl _wtof_l(ध्रुव wchar_t *_Str,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wtoi(ध्रुव wchar_t *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _wtoi_l(ध्रुव wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(ध्रुव wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(ध्रुव wchar_t *_Str,_locale_t _Locale);

#सचे _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,पूर्णाङ्क _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,पूर्णाङ्क _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ध्रुव wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ध्रुव wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ध्रुव wchar_t *_Str,wchar_t **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ध्रुव wchar_t *_Str,wchar_t **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(ध्रुव wchar_t *_Str,wchar_t **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(ध्रुव wchar_t *_Str ,wchar_t **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#define _CVTBUFSIZE (309+40)
  _CRTIMP वर्ण *__cdecl _fullpath(वर्ण *_FullPath,ध्रुव वर्ण *_Path,size_t _SizeInBytes);
  _CRTIMP वर्ण *__cdecl _ecvt(द्विगुण _Val,पूर्णाङ्क अङ्कः_Of_Digits,पूर्णाङ्क *_PtDec,पूर्णाङ्क *_PtSign);
  _CRTIMP वर्ण *__cdecl _fcvt(द्विगुण _Val,पूर्णाङ्क अङ्कः_Of_Dec,पूर्णाङ्क *_PtDec,पूर्णाङ्क *_PtSign);
  _CRTIMP वर्ण *__cdecl _gcvt(द्विगुण _Val,पूर्णाङ्क अङ्कः_Of_Digits,वर्ण *_DstBuf);
  _CRTIMP पूर्णाङ्क __cdecl _atodbl(_CRT_DOUBLE *_Result,वर्ण *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _atoldbl(_LDOUBLE *_Result,वर्ण *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _atoflt(_CRT_FLOAT *_Result,वर्ण *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _atodbl_l(_CRT_DOUBLE *_Result,वर्ण *_Str,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _atoldbl_l(_LDOUBLE *_Result,वर्ण *_Str,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _atoflt_l(_CRT_FLOAT *_Result,वर्ण *_Str,_locale_t _Locale);
  unsigned long __cdecl _lrotl(unsigned long _Val,पूर्णाङ्क _Shift);
  unsigned long __cdecl _lrotr(unsigned long _Val,पूर्णाङ्क _Shift);
  _CRTIMP शून्य __cdecl _makepath(वर्ण *_Path,ध्रुव वर्ण *_Drive,ध्रुव वर्ण *_Dir,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  शून्य __cdecl perror(ध्रुव वर्ण *Err_सन्देशः);
#endif
  _CRTIMP पूर्णाङ्क __cdecl _putenv(ध्रुव वर्ण *_EnvString);
  unsigned पूर्णाङ्क __cdecl _rotl(unsigned पूर्णाङ्क _Val,पूर्णाङ्क _Shift);
#सचे _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotl64(unsigned __int64 _Val,पूर्णाङ्क _Shift);
#endif
  unsigned पूर्णाङ्क __cdecl _rotr(unsigned पूर्णाङ्क _Val,पूर्णाङ्क _Shift);
#सचे _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotr64(unsigned __int64 _Val,पूर्णाङ्क _Shift);
#endif
  _CRTIMP शून्य __cdecl _searchenv(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_EnvVar,वर्ण *_ResultPath);
  _CRTIMP शून्य __cdecl _splitpath(ध्रुव वर्ण *_FullPath,वर्ण *_Drive,वर्ण *_Dir,वर्ण *_Filename,वर्ण *_Ext);
  _CRTIMP शून्य __cdecl _swab(वर्ण *_Buf1,वर्ण *_Buf2,पूर्णाङ्क _SizeInBytes);

#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,ध्रुव wchar_t *_Path,size_t Size_In_शब्दाः);
  _CRTIMP शून्य __cdecl _wmakepath(wchar_t *_ResultPath,ध्रुव wchar_t *_Drive,ध्रुव wchar_t *_Dir,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP शून्य __cdecl _wperror(ध्रुव wchar_t *Err_सन्देशः);
#endif
  _CRTIMP पूर्णाङ्क __cdecl _wputenv(ध्रुव wchar_t *_EnvString);
  _CRTIMP शून्य __cdecl _wsearchenv(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP शून्य __cdecl _wsplitpath(ध्रुव wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif

  _CRTIMP शून्य __cdecl _beep(unsigned _Frequency,unsigned _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP शून्य __cdecl _seterrormode(पूर्णाङ्क _Mode) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP शून्य __cdecl _sleep(unsigned long _Duration) __MINGW_ATTRIB_DEPRECATED;
#endif

#ifndef NO_OLDNAMES
#ifndef _POSIX_
#सचे 0
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
  वर्ण *__cdecl ecvt(द्विगुण _Val,पूर्णाङ्क अङ्कः_Of_Digits,पूर्णाङ्क *_PtDec,पूर्णाङ्क *_PtSign);
  वर्ण *__cdecl fcvt(द्विगुण _Val,पूर्णाङ्क अङ्कः_Of_Dec,पूर्णाङ्क *_PtDec,पूर्णाङ्क *_PtSign);
  वर्ण *__cdecl gcvt(द्विगुण _Val,पूर्णाङ्क अङ्कः_Of_Digits,वर्ण *_DstBuf);
  वर्ण *__cdecl itoa(पूर्णाङ्क _Val,वर्ण *_DstBuf,पूर्णाङ्क _Radix);
  वर्ण *__cdecl ltoa(long _Val,वर्ण *_DstBuf,पूर्णाङ्क _Radix);
  पूर्णाङ्क __cdecl putenv(ध्रुव वर्ण *_EnvString);
  शून्य __cdecl swab(वर्ण *_Buf1,वर्ण *_Buf2,पूर्णाङ्क _SizeInBytes);
  वर्ण *__cdecl ultoa(unsigned long _Val,वर्ण *_Dstbuf,पूर्णाङ्क _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#endif
#endif

#सचे !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  प्रकारनिर्देश संरचना { long long quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(long long, long long);

  __CRT_INLINE long long __cdecl llabs(long long _j) { पटिनिवत्त (_j >= 0 ? _j : -_j); }

 #ifdef __TINYC__ /* gr */
  #define strtoll _strtoi64
  #define strtoull _strtoui64
 #अञ्ञथा
  long long  __cdecl strtoll(ध्रुव वर्ण* __restrict__, वर्ण** __restrict, पूर्णाङ्क);
  unsigned long long  __cdecl strtoull(ध्रुव वर्ण* __restrict__, वर्ण** __restrict__, पूर्णाङ्क);
 #endif

  /* these are stubs for MS _i64 versions */
  long long  __cdecl atoll (ध्रुव वर्ण *);

#ifndef __STRICT_ANSI__
  long long  __cdecl wtoll (ध्रुव wchar_t *);
  वर्ण *__cdecl lltoa (long long, वर्ण *, पूर्णाङ्क);
  वर्ण *__cdecl ulltoa (unsigned long long , वर्ण *, पूर्णाङ्क);
  wchar_t *__cdecl lltow (long long, wchar_t *, पूर्णाङ्क);
  wchar_t *__cdecl ulltow (unsigned long long, wchar_t *, पूर्णाङ्क);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE long long  __cdecl atoll (ध्रुव वर्ण * _c) { पटिनिवत्त _atoi64 (_c); }
  __CRT_INLINE वर्ण *__cdecl lltoa (long long _n, वर्ण * _c, पूर्णाङ्क _i) { पटिनिवत्त _i64toa (_n, _c, _i); }
  __CRT_INLINE वर्ण *__cdecl ulltoa (unsigned long long _n, वर्ण * _c, पूर्णाङ्क _i) { पटिनिवत्त _ui64toa (_n, _c, _i); }
  __CRT_INLINE long long  __cdecl wtoll (ध्रुव wchar_t * _w) { पटिनिवत्त _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (long long _n, wchar_t * _w, पूर्णाङ्क _i) { पटिनिवत्त _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (unsigned long long _n, wchar_t * _w, पूर्णाङ्क _i) { पटिनिवत्त _ui64tow (_n, _w, _i); }
#endif /* (__STRICT_ANSI__)  */

#endif /* !__NO_ISOCEXT */

#ifdef __cplusplus
}
#endif

#pragma pack(निष्कासय)

#अन्तर्भाव <sec_api/stdlib_s.h>
#अन्तर्भाव <malloc.h>

#endif
