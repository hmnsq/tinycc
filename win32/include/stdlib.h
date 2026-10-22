/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB
#define _INC_STDLIB

#অন্তর্ভাব <_mingw.h>
#অন্তর্ভাব <limits.h>

#pragma pack(ঠেলো,_CRT_PACKING)

#ifdef __cplusplus
বাহ্যিক "C" {
#endif

#ifndef ফাঁকা
#ifdef __cplusplus
#define ফাঁকা 0
#অন্যথা
#define ফাঁকা ((শূন্য *)0)
#endif
#endif

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#ifndef _ONEXIT_T_DEFINED
#define _ONEXIT_T_DEFINED

  প্রকারলেখ পূর্ণসংখ্যা (__cdecl *_onexit_t)(শূন্য);

#ifndef NO_OLDNAMES
#define onexit_t _onexit_t
#endif
#endif

#ifndef _DIV_T_DEFINED
#define _DIV_T_DEFINED

  প্রকারলেখ কাঠামো _div_t {
    পূর্ণসংখ্যা quot;
    পূর্ণসংখ্যা rem;
  } div_t;

  প্রকারলেখ কাঠামো _ldiv_t {
    long quot;
    long rem;
  } ldiv_t;
#endif

#ifndef _CRT_DOUBLE_DEC
#define _CRT_DOUBLE_DEC

#pragma pack(4)
  প্রকারলেখ কাঠামো {
    unsigned অক্ষর ld[10];
  } _LDOUBLE;
#pragma pack()

#define _PTR_LD(x) ((unsigned অক্ষর *)(&(x)->ld))

  প্রকারলেখ কাঠামো {
    দ্বিগুণ x;
  } _CRT_DOUBLE;

  প্রকারলেখ কাঠামো {
    দশমিক f;
  } _CRT_FLOAT;

#pragma ঠেলো_macro("long")
#undef long

  প্রকারলেখ কাঠামো {
    long দ্বিগুণ x;
  } _LONGDOUBLE;

#pragma বের_করো_macro("long")

#pragma pack(4)
  প্রকারলেখ কাঠামো {
    unsigned অক্ষর ld12[12];
  } _LDBL12;
#pragma pack()
#endif

#define RAND_MAX 0x7fff

#ifndef MB_CUR_MAX
#define MB_CUR_MAX ___mb_cur_max_func()
#ifndef __mb_cur_max
#ifdef _MSVCRT_
  বাহ্যিক পূর্ণসংখ্যা __mb_cur_max;
#অন্যথা
#define __mb_cur_max    (*_imp____mb_cur_max)
  বাহ্যিক পূর্ণসংখ্যা *_imp____mb_cur_max;
#endif
#endif
#ifdef _MSVCRT_
  বাহ্যিক পূর্ণসংখ্যা __mbcur_max;
#define ___mb_cur_max_func() (__mb_cur_max)
#অন্যথা
  বাহ্যিক পূর্ণসংখ্যা* _imp____mbcur_max;
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

#define WRITE_ABORT_বার্তা 0x1
#define _CALL_REPORTFAULT 0x2

#define _MAX_ENV 32767

  প্রকারলেখ শূন্য (__cdecl *_purecall_handler)(শূন্য);

  _CRTIMP _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(শূন্য);

  প্রকারলেখ শূন্য (__cdecl *_invalid_parameter_handler)(ধ্রুবক wchar_t *,ধ্রুবক wchar_t *,ধ্রুবক wchar_t *,unsigned পূর্ণসংখ্যা,uintptr_t);
  _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(শূন্য);

#ifndef _CRT_ERRNO_DEFINED
#define _CRT_ERRNO_DEFINED
  _CRTIMP পূর্ণসংখ্যা *__cdecl _errno(শূন্য);
#define errno (*_errno())
  errno_t __cdecl _set_errno(পূর্ণসংখ্যা মান_2);
  errno_t __cdecl _get_errno(পূর্ণসংখ্যা *মান_2);
#endif
  _CRTIMP unsigned long *__cdecl __doserrno(শূন্য);
#define _doserrno (*__doserrno())
  errno_t __cdecl _set_doserrno(unsigned long মান_2);
  errno_t __cdecl _get_doserrno(unsigned long *মান_2);
#ifdef _MSVCRT_
  বাহ্যিক অক্ষর *_sys_errlist[];
  বাহ্যিক পূর্ণসংখ্যা _sys_nerr;
#অন্যথা
  _CRTIMP অক্ষর *_sys_errlist[1];
  _CRTIMP পূর্ণসংখ্যা _sys_nerr;
#endif
#যদি (defined(_X86_) && !defined(__x86_64))
  _CRTIMP পূর্ণসংখ্যা *__cdecl __p___argc(শূন্য);
  _CRTIMP অক্ষর ***__cdecl __p___argv(শূন্য);
  _CRTIMP wchar_t ***__cdecl __p___wargv(শূন্য);
  _CRTIMP অক্ষর ***__cdecl __p__environ(শূন্য);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(শূন্য);
  _CRTIMP অক্ষর **__cdecl __p__pgmptr(শূন্য);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(শূন্য);
#endif
#ifndef __argc
#ifdef _MSVCRT_
  বাহ্যিক পূর্ণসংখ্যা __argc;
#অন্যথা
#define __argc (*_imp____argc)
  বাহ্যিক পূর্ণসংখ্যা *_imp____argc;
#endif
#endif
#ifndef __argv
#ifdef _MSVCRT_
  বাহ্যিক অক্ষর **__argv;
#অন্যথা
#define __argv  (*_imp____argv)
  বাহ্যিক অক্ষর ***_imp____argv;
#endif
#endif
#ifndef __wargv
#ifdef _MSVCRT_
  বাহ্যিক wchar_t **__wargv;
#অন্যথা
#define __wargv (*_imp____wargv)
  বাহ্যিক wchar_t ***_imp____wargv;
#endif
#endif

#ifdef _POSIX_
  বাহ্যিক অক্ষর **environ;
#অন্যথা
#ifndef _environ
#ifdef _MSVCRT_
  বাহ্যিক অক্ষর **_environ;
#অন্যথা
#define _environ (*_imp___environ)
  বাহ্যিক অক্ষর ***_imp___environ;
#endif
#endif

#ifndef _wenviron
#ifdef _MSVCRT_
  বাহ্যিক wchar_t **_wenviron;
#অন্যথা
#define _wenviron       (*_imp___wenviron)
  বাহ্যিক wchar_t ***_imp___wenviron;
#endif
#endif
#endif

#যদি defined __aarch64__
/* something does not work using those from msvcrt.dll */
# undef __argc
# undef __argv
# undef __wargv
# undef _wenviron
# undef _environ
বাহ্যিক পূর্ণসংখ্যা __argc;
বাহ্যিক অক্ষর **__argv;
বাহ্যিক wchar_t **__wargv;
বাহ্যিক অক্ষর **_environ;
বাহ্যিক wchar_t **_wenviron;
#endif

#ifndef _pgmptr
#ifdef _MSVCRT_
  বাহ্যিক অক্ষর *_pgmptr;
#অন্যথা
#define _pgmptr (*_imp___pgmptr)
  বাহ্যিক অক্ষর **_imp___pgmptr;
#endif
#endif

#ifndef _wpgmptr
#ifdef _MSVCRT_
  বাহ্যিক wchar_t *_wpgmptr;
#অন্যথা
#define _wpgmptr        (*_imp___wpgmptr)
  বাহ্যিক wchar_t **_imp___wpgmptr;
#endif
#endif
  errno_t __cdecl _get_pgmptr(অক্ষর **মান_2);
  errno_t __cdecl _get_wpgmptr(wchar_t **মান_2);
#ifndef _fmode
#ifdef _MSVCRT_
  বাহ্যিক পূর্ণসংখ্যা _fmode;
#অন্যথা
#define _fmode  (*_imp___fmode)
  বাহ্যিক পূর্ণসংখ্যা *_imp___fmode;
#endif
#endif
  _CRTIMP errno_t __cdecl _set_fmode(পূর্ণসংখ্যা _Mode);
  _CRTIMP errno_t __cdecl _get_fmode(পূর্ণসংখ্যা *_PMode);

#ifndef _osplatform
#ifdef _MSVCRT_
  বাহ্যিক unsigned পূর্ণসংখ্যা _osplatform;
#অন্যথা
#define _osplatform (*_imp___osplatform)
  বাহ্যিক unsigned পূর্ণসংখ্যা *_imp___osplatform;
#endif
#endif

#ifndef _osver
#ifdef _MSVCRT_
  বাহ্যিক unsigned পূর্ণসংখ্যা _osver;
#অন্যথা
#define _osver  (*_imp___osver)
  বাহ্যিক unsigned পূর্ণসংখ্যা *_imp___osver;
#endif
#endif

#ifndef _winver
#ifdef _MSVCRT_
  বাহ্যিক unsigned পূর্ণসংখ্যা _winver;
#অন্যথা
#define _winver (*_imp___winver)
  বাহ্যিক unsigned পূর্ণসংখ্যা *_imp___winver;
#endif
#endif

#ifndef _winmajor
#ifdef _MSVCRT_
  বাহ্যিক unsigned পূর্ণসংখ্যা _winmajor;
#অন্যথা
#define _winmajor       (*_imp___winmajor)
  বাহ্যিক unsigned পূর্ণসংখ্যা *_imp___winmajor;
#endif
#endif

#ifndef _winminor
#ifdef _MSVCRT_
  বাহ্যিক unsigned পূর্ণসংখ্যা _winminor;
#অন্যথা
#define _winminor       (*_imp___winminor)
  বাহ্যিক unsigned পূর্ণসংখ্যা *_imp___winminor;
#endif
#endif

  errno_t __cdecl _get_osplatform(unsigned পূর্ণসংখ্যা *মান_2);
  errno_t __cdecl _get_osver(unsigned পূর্ণসংখ্যা *মান_2);
  errno_t __cdecl _get_winver(unsigned পূর্ণসংখ্যা *মান_2);
  errno_t __cdecl _get_winmajor(unsigned পূর্ণসংখ্যা *মান_2);
  errno_t __cdecl _get_winminor(unsigned পূর্ণসংখ্যা *মান_2);
#ifndef _countof
#ifndef __cplusplus
#define _countof(_Array) (আকার(_Array) / আকার(_Array[0]))
#অন্যথা
  বাহ্যিক "C++" {
    template <typename _CountofType,আকার_t আকার_Of_Array> অক্ষর (*__countof_helper(UNALIGNED _CountofType (&_Array)[আকার_Of_Array]))[আকার_Of_Array];
#define _countof(_Array) আকার(*__countof_helper(_Array))
  }
#endif
#endif

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  শূন্য __cdecl __MINGW_NOTHROW exit(পূর্ণসংখ্যা _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP শূন্য __cdecl __MINGW_NOTHROW _exit(পূর্ণসংখ্যা _Code) __MINGW_ATTRIB_NORETURN;
#যদি !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  শূন্য __cdecl _Exit(পূর্ণসংখ্যা) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN শূন্য  __cdecl _Exit(পূর্ণসংখ্যা status)
  {  _exit(status); }
#endif

#pragma ঠেলো_macro("abort")
#undef abort
  শূন্য __cdecl __declspec(noreturn) abort(শূন্য);
#pragma বের_করো_macro("abort")

#endif

  _CRTIMP unsigned পূর্ণসংখ্যা __cdecl _set_abort_behavior(unsigned পূর্ণসংখ্যা _Flags,unsigned পূর্ণসংখ্যা _Mask);

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  পূর্ণসংখ্যা __cdecl abs(পূর্ণসংখ্যা _X);
  long __cdecl labs(long _X);
#endif

#যদি _INTEGRAL_MAX_BITS >= 64
  __int64 __cdecl _abs64(__int64);
#endif
  পূর্ণসংখ্যা __cdecl atexit(শূন্য (__cdecl *)(শূন্য));
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  দ্বিগুণ __cdecl atof(ধ্রুবক অক্ষর *_String);
  দ্বিগুণ __cdecl _atof_l(ধ্রুবক অক্ষর *_String,_locale_t _Locale);
#endif
  পূর্ণসংখ্যা __cdecl atoi(ধ্রুবক অক্ষর *_Str);
  _CRTIMP পূর্ণসংখ্যা __cdecl _atoi_l(ধ্রুবক অক্ষর *_Str,_locale_t _Locale);
  long __cdecl atol(ধ্রুবক অক্ষর *_Str);
  _CRTIMP long __cdecl _atol_l(ধ্রুবক অক্ষর *_Str,_locale_t _Locale);
#ifndef _CRT_ALGO_DEFINED
#define _CRT_ALGO_DEFINED
  শূন্য *__cdecl bsearch(ধ্রুবক শূন্য *চাবি_2,ধ্রুবক শূন্য *_Base,আকার_t অঙ্ক_Of_Elements,আকার_t আকার_Of_Elements,পূর্ণসংখ্যা (__cdecl *_PtFuncCompare)(ধ্রুবক শূন্য *,ধ্রুবক শূন্য *));
  শূন্য __cdecl qsort(শূন্য *_Base,আকার_t অঙ্ক_Of_Elements,আকার_t আকার_Of_Elements,পূর্ণসংখ্যা (__cdecl *_PtFuncCompare)(ধ্রুবক শূন্য *,ধ্রুবক শূন্য *));
#endif
  unsigned short __cdecl _byteswap_ushort(unsigned short _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#যদি _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Int64);
#endif
  div_t __cdecl div(পূর্ণসংখ্যা _Numerator,পূর্ণসংখ্যা _Denominator);
  অক্ষর *__cdecl getenv(ধ্রুবক অক্ষর *_VarName);
  _CRTIMP অক্ষর *__cdecl _itoa(পূর্ণসংখ্যা মান_2,অক্ষর *_Dest,পূর্ণসংখ্যা _Radix);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP অক্ষর *__cdecl _i64toa(__int64 _Val,অক্ষর *_DstBuf,পূর্ণসংখ্যা _Radix);
  _CRTIMP অক্ষর *__cdecl _ui64toa(unsigned __int64 _Val,অক্ষর *_DstBuf,পূর্ণসংখ্যা _Radix);
  _CRTIMP __int64 __cdecl _atoi64(ধ্রুবক অক্ষর *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(ধ্রুবক অক্ষর *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(ধ্রুবক অক্ষর *_String,অক্ষর **_EndPtr,পূর্ণসংখ্যা _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(ধ্রুবক অক্ষর *_String,অক্ষর **_EndPtr,পূর্ণসংখ্যা _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _strtoui64(ধ্রুবক অক্ষর *_String,অক্ষর **_EndPtr,পূর্ণসংখ্যা _Radix);
  _CRTIMP unsigned __int64 __cdecl _strtoui64_l(ধ্রুবক অক্ষর *_String,অক্ষর **_EndPtr,পূর্ণসংখ্যা _Radix,_locale_t _Locale);
#endif
  ldiv_t __cdecl ldiv(long _Numerator,long _Denominator);
  _CRTIMP অক্ষর *__cdecl _ltoa(long মান_2,অক্ষর *_Dest,পূর্ণসংখ্যা _Radix);
  পূর্ণসংখ্যা __cdecl mblen(ধ্রুবক অক্ষর *_Ch,আকার_t Max_গুনতি);
  _CRTIMP পূর্ণসংখ্যা __cdecl _mblen_l(ধ্রুবক অক্ষর *_Ch,আকার_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP আকার_t __cdecl _mbstrlen(ধ্রুবক অক্ষর *_Str);
  _CRTIMP আকার_t __cdecl _mbstrlen_l(ধ্রুবক অক্ষর *_Str,_locale_t _Locale);
  _CRTIMP আকার_t __cdecl _mbstrnlen(ধ্রুবক অক্ষর *_Str,আকার_t Max_গুনতি);
  _CRTIMP আকার_t __cdecl _mbstrnlen_l(ধ্রুবক অক্ষর *_Str,আকার_t Max_গুনতি,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl mbtowc(wchar_t *_DstCh,ধ্রুবক অক্ষর *_SrcCh,আকার_t Src_আকার_In_Bytes);
  _CRTIMP পূর্ণসংখ্যা __cdecl _mbtowc_l(wchar_t *_DstCh,ধ্রুবক অক্ষর *_SrcCh,আকার_t Src_আকার_In_Bytes,_locale_t _Locale);
  আকার_t __cdecl mbstowcs(wchar_t *_Dest,ধ্রুবক অক্ষর *_Source,আকার_t Max_গুনতি);
  _CRTIMP আকার_t __cdecl _mbstowcs_l(wchar_t *_Dest,ধ্রুবক অক্ষর *_Source,আকার_t Max_গুনতি,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl rand(শূন্য);
  _CRTIMP পূর্ণসংখ্যা __cdecl _set_error_mode(পূর্ণসংখ্যা _Mode);
  শূন্য __cdecl srand(unsigned পূর্ণসংখ্যা _Seed);
  দ্বিগুণ __cdecl strtod(ধ্রুবক অক্ষর *_Str,অক্ষর **_EndPtr);
#যদি !defined __NO_ISOCEXT  /* in libmingwex.a */
#যদি __TINYC__
  __CRT_INLINE দশমিক __cdecl strtof (ধ্রুবক অক্ষর *p, অক্ষর ** e) { ফেরত strtod(p, e); }
  __CRT_INLINE long দ্বিগুণ __cdecl strtold(ধ্রুবক অক্ষর *p, অক্ষর ** e) { ফেরত strtod(p, e); }
#অন্যথা
  দশমিক __cdecl strtof (ধ্রুবক অক্ষর * __restrict__, অক্ষর ** __restrict__);
  long দ্বিগুণ __cdecl strtold(ধ্রুবক অক্ষর * __restrict__, অক্ষর ** __restrict__);
#endif
#অন্যথা
  দশমিক __cdecl strtof(ধ্রুবক অক্ষর *nptr, অক্ষর **endptr);
#endif /* __NO_ISOCEXT */
  _CRTIMP দ্বিগুণ __cdecl _strtod_l(ধ্রুবক অক্ষর *_Str,অক্ষর **_EndPtr,_locale_t _Locale);
  long __cdecl strtol(ধ্রুবক অক্ষর *_Str,অক্ষর **_EndPtr,পূর্ণসংখ্যা _Radix);
  _CRTIMP long __cdecl _strtol_l(ধ্রুবক অক্ষর *_Str,অক্ষর **_EndPtr,পূর্ণসংখ্যা _Radix,_locale_t _Locale);
  unsigned long __cdecl strtoul(ধ্রুবক অক্ষর *_Str,অক্ষর **_EndPtr,পূর্ণসংখ্যা _Radix);
  _CRTIMP unsigned long __cdecl _strtoul_l(ধ্রুবক অক্ষর *_Str,অক্ষর **_EndPtr,পূর্ণসংখ্যা _Radix,_locale_t _Locale);
#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  পূর্ণসংখ্যা __cdecl system(ধ্রুবক অক্ষর *_Command);
#endif
  _CRTIMP অক্ষর *__cdecl _ultoa(unsigned long মান_2,অক্ষর *_Dest,পূর্ণসংখ্যা _Radix);
  পূর্ণসংখ্যা __cdecl wctomb(অক্ষর *_MbCh,wchar_t _WCh);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wctomb_l(অক্ষর *_MbCh,wchar_t _WCh,_locale_t _Locale);
  আকার_t __cdecl wcstombs(অক্ষর *_Dest,ধ্রুবক wchar_t *_Source,আকার_t Max_গুনতি);
  _CRTIMP আকার_t __cdecl _wcstombs_l(অক্ষর *_Dest,ধ্রুবক wchar_t *_Source,আকার_t Max_গুনতি,_locale_t _Locale);

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  শূন্য *__cdecl calloc(আকার_t অঙ্ক_Of_Elements,আকার_t আকার_Of_Elements);
  শূন্য __cdecl মুক্ত(শূন্য *_Memory);
  শূন্য *__cdecl malloc(আকার_t আকার_5);
  শূন্য *__cdecl realloc(শূন্য *_Memory,আকার_t New_আকার);
  _CRTIMP শূন্য *__cdecl _recalloc(শূন্য *_Memory,আকার_t গুনতি_5,আকার_t আকার_5);
  _CRTIMP শূন্য __cdecl _aligned_free(শূন্য *_Memory);
  _CRTIMP শূন্য *__cdecl _aligned_malloc(আকার_t আকার_5,আকার_t _Alignment);
  _CRTIMP শূন্য *__cdecl _aligned_offset_malloc(আকার_t আকার_5,আকার_t _Alignment,আকার_t _Offset);
  _CRTIMP শূন্য *__cdecl _aligned_realloc(শূন্য *_Memory,আকার_t আকার_5,আকার_t _Alignment);
  _CRTIMP শূন্য *__cdecl _aligned_recalloc(শূন্য *_Memory,আকার_t গুনতি_5,আকার_t আকার_5,আকার_t _Alignment);
  _CRTIMP শূন্য *__cdecl _aligned_offset_realloc(শূন্য *_Memory,আকার_t আকার_5,আকার_t _Alignment,আকার_t _Offset);
  _CRTIMP শূন্য *__cdecl _aligned_offset_recalloc(শূন্য *_Memory,আকার_t গুনতি_5,আকার_t আকার_5,আকার_t _Alignment,আকার_t _Offset);
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(পূর্ণসংখ্যা মান_2,wchar_t *_Dest,পূর্ণসংখ্যা _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long মান_2,wchar_t *_Dest,পূর্ণসংখ্যা _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long মান_2,wchar_t *_Dest,পূর্ণসংখ্যা _Radix);
  দ্বিগুণ __cdecl wcstod(ধ্রুবক wchar_t *_Str,wchar_t **_EndPtr);
  দশমিক __cdecl wcstof(ধ্রুবক wchar_t *nptr, wchar_t **endptr);
#যদি !defined __NO_ISOCEXT /* in libmingwex.a */
  দশমিক __cdecl wcstof( ধ্রুবক wchar_t * __restrict__, wchar_t ** __restrict__);
  long দ্বিগুণ __cdecl wcstold(ধ্রুবক wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  _CRTIMP দ্বিগুণ __cdecl _wcstod_l(ধ্রুবক wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  long __cdecl wcstol(ধ্রুবক wchar_t *_Str,wchar_t **_EndPtr,পূর্ণসংখ্যা _Radix);
  _CRTIMP long __cdecl _wcstol_l(ধ্রুবক wchar_t *_Str,wchar_t **_EndPtr,পূর্ণসংখ্যা _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(ধ্রুবক wchar_t *_Str,wchar_t **_EndPtr,পূর্ণসংখ্যা _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(ধ্রুবক wchar_t *_Str,wchar_t **_EndPtr,পূর্ণসংখ্যা _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ধ্রুবক wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP পূর্ণসংখ্যা __cdecl _wsystem(ধ্রুবক wchar_t *_Command);
#endif
  _CRTIMP দ্বিগুণ __cdecl _wtof(ধ্রুবক wchar_t *_Str);
  _CRTIMP দ্বিগুণ __cdecl _wtof_l(ধ্রুবক wchar_t *_Str,_locale_t _Locale);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wtoi(ধ্রুবক wchar_t *_Str);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wtoi_l(ধ্রুবক wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(ধ্রুবক wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(ধ্রুবক wchar_t *_Str,_locale_t _Locale);

#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,পূর্ণসংখ্যা _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,পূর্ণসংখ্যা _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ধ্রুবক wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ধ্রুবক wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ধ্রুবক wchar_t *_Str,wchar_t **_EndPtr,পূর্ণসংখ্যা _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ধ্রুবক wchar_t *_Str,wchar_t **_EndPtr,পূর্ণসংখ্যা _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(ধ্রুবক wchar_t *_Str,wchar_t **_EndPtr,পূর্ণসংখ্যা _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(ধ্রুবক wchar_t *_Str ,wchar_t **_EndPtr,পূর্ণসংখ্যা _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#define _CVTBUFSIZE (309+40)
  _CRTIMP অক্ষর *__cdecl _fullpath(অক্ষর *_FullPath,ধ্রুবক অক্ষর *_Path,আকার_t আকার_In_Bytes);
  _CRTIMP অক্ষর *__cdecl _ecvt(দ্বিগুণ _Val,পূর্ণসংখ্যা অঙ্ক_Of_Digits,পূর্ণসংখ্যা *_PtDec,পূর্ণসংখ্যা *_PtSign);
  _CRTIMP অক্ষর *__cdecl _fcvt(দ্বিগুণ _Val,পূর্ণসংখ্যা অঙ্ক_Of_Dec,পূর্ণসংখ্যা *_PtDec,পূর্ণসংখ্যা *_PtSign);
  _CRTIMP অক্ষর *__cdecl _gcvt(দ্বিগুণ _Val,পূর্ণসংখ্যা অঙ্ক_Of_Digits,অক্ষর *_DstBuf);
  _CRTIMP পূর্ণসংখ্যা __cdecl _atodbl(_CRT_DOUBLE *ফলাফল_2,অক্ষর *_Str);
  _CRTIMP পূর্ণসংখ্যা __cdecl _atoldbl(_LDOUBLE *ফলাফল_2,অক্ষর *_Str);
  _CRTIMP পূর্ণসংখ্যা __cdecl _atoflt(_CRT_FLOAT *ফলাফল_2,অক্ষর *_Str);
  _CRTIMP পূর্ণসংখ্যা __cdecl _atodbl_l(_CRT_DOUBLE *ফলাফল_2,অক্ষর *_Str,_locale_t _Locale);
  _CRTIMP পূর্ণসংখ্যা __cdecl _atoldbl_l(_LDOUBLE *ফলাফল_2,অক্ষর *_Str,_locale_t _Locale);
  _CRTIMP পূর্ণসংখ্যা __cdecl _atoflt_l(_CRT_FLOAT *ফলাফল_2,অক্ষর *_Str,_locale_t _Locale);
  unsigned long __cdecl _lrotl(unsigned long _Val,পূর্ণসংখ্যা _Shift);
  unsigned long __cdecl _lrotr(unsigned long _Val,পূর্ণসংখ্যা _Shift);
  _CRTIMP শূন্য __cdecl _makepath(অক্ষর *_Path,ধ্রুবক অক্ষর *_Drive,ধ্রুবক অক্ষর *_Dir,ধ্রুবক অক্ষর *_Filename,ধ্রুবক অক্ষর *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  শূন্য __cdecl perror(ধ্রুবক অক্ষর *Err_বার্তা);
#endif
  _CRTIMP পূর্ণসংখ্যা __cdecl _putenv(ধ্রুবক অক্ষর *_EnvString);
  unsigned পূর্ণসংখ্যা __cdecl _rotl(unsigned পূর্ণসংখ্যা _Val,পূর্ণসংখ্যা _Shift);
#যদি _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotl64(unsigned __int64 _Val,পূর্ণসংখ্যা _Shift);
#endif
  unsigned পূর্ণসংখ্যা __cdecl _rotr(unsigned পূর্ণসংখ্যা _Val,পূর্ণসংখ্যা _Shift);
#যদি _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotr64(unsigned __int64 _Val,পূর্ণসংখ্যা _Shift);
#endif
  _CRTIMP শূন্য __cdecl _searchenv(ধ্রুবক অক্ষর *_Filename,ধ্রুবক অক্ষর *_EnvVar,অক্ষর *ফলাফল_Path);
  _CRTIMP শূন্য __cdecl _splitpath(ধ্রুবক অক্ষর *_FullPath,অক্ষর *_Drive,অক্ষর *_Dir,অক্ষর *_Filename,অক্ষর *_Ext);
  _CRTIMP শূন্য __cdecl _swab(অক্ষর *_Buf1,অক্ষর *_Buf2,পূর্ণসংখ্যা আকার_In_Bytes);

#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,ধ্রুবক wchar_t *_Path,আকার_t আকার_In_শব্দগুলি);
  _CRTIMP শূন্য __cdecl _wmakepath(wchar_t *ফলাফল_Path,ধ্রুবক wchar_t *_Drive,ধ্রুবক wchar_t *_Dir,ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP শূন্য __cdecl _wperror(ধ্রুবক wchar_t *Err_বার্তা);
#endif
  _CRTIMP পূর্ণসংখ্যা __cdecl _wputenv(ধ্রুবক wchar_t *_EnvString);
  _CRTIMP শূন্য __cdecl _wsearchenv(ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_EnvVar,wchar_t *ফলাফল_Path);
  _CRTIMP শূন্য __cdecl _wsplitpath(ধ্রুবক wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif

  _CRTIMP শূন্য __cdecl _beep(unsigned _Frequency,unsigned _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP শূন্য __cdecl _seterrormode(পূর্ণসংখ্যা _Mode) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP শূন্য __cdecl _sleep(unsigned long _Duration) __MINGW_ATTRIB_DEPRECATED;
#endif

#ifndef NO_OLDNAMES
#ifndef _POSIX_
#যদি 0
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
  অক্ষর *__cdecl ecvt(দ্বিগুণ _Val,পূর্ণসংখ্যা অঙ্ক_Of_Digits,পূর্ণসংখ্যা *_PtDec,পূর্ণসংখ্যা *_PtSign);
  অক্ষর *__cdecl fcvt(দ্বিগুণ _Val,পূর্ণসংখ্যা অঙ্ক_Of_Dec,পূর্ণসংখ্যা *_PtDec,পূর্ণসংখ্যা *_PtSign);
  অক্ষর *__cdecl gcvt(দ্বিগুণ _Val,পূর্ণসংখ্যা অঙ্ক_Of_Digits,অক্ষর *_DstBuf);
  অক্ষর *__cdecl itoa(পূর্ণসংখ্যা _Val,অক্ষর *_DstBuf,পূর্ণসংখ্যা _Radix);
  অক্ষর *__cdecl ltoa(long _Val,অক্ষর *_DstBuf,পূর্ণসংখ্যা _Radix);
  পূর্ণসংখ্যা __cdecl putenv(ধ্রুবক অক্ষর *_EnvString);
  শূন্য __cdecl swab(অক্ষর *_Buf1,অক্ষর *_Buf2,পূর্ণসংখ্যা আকার_In_Bytes);
  অক্ষর *__cdecl ultoa(unsigned long _Val,অক্ষর *_Dstbuf,পূর্ণসংখ্যা _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#endif
#endif

#যদি !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  প্রকারলেখ কাঠামো { long long quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(long long, long long);

  __CRT_INLINE long long __cdecl llabs(long long _j) { ফেরত (_j >= 0 ? _j : -_j); }

 #ifdef __TINYC__ /* gr */
  #define strtoll _strtoi64
  #define strtoull _strtoui64
 #অন্যথা
  long long  __cdecl strtoll(ধ্রুবক অক্ষর* __restrict__, অক্ষর** __restrict, পূর্ণসংখ্যা);
  unsigned long long  __cdecl strtoull(ধ্রুবক অক্ষর* __restrict__, অক্ষর** __restrict__, পূর্ণসংখ্যা);
 #endif

  /* these are stubs for MS _i64 versions */
  long long  __cdecl atoll (ধ্রুবক অক্ষর *);

#ifndef __STRICT_ANSI__
  long long  __cdecl wtoll (ধ্রুবক wchar_t *);
  অক্ষর *__cdecl lltoa (long long, অক্ষর *, পূর্ণসংখ্যা);
  অক্ষর *__cdecl ulltoa (unsigned long long , অক্ষর *, পূর্ণসংখ্যা);
  wchar_t *__cdecl lltow (long long, wchar_t *, পূর্ণসংখ্যা);
  wchar_t *__cdecl ulltow (unsigned long long, wchar_t *, পূর্ণসংখ্যা);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE long long  __cdecl atoll (ধ্রুবক অক্ষর * _c) { ফেরত _atoi64 (_c); }
  __CRT_INLINE অক্ষর *__cdecl lltoa (long long _n, অক্ষর * _c, পূর্ণসংখ্যা _i) { ফেরত _i64toa (_n, _c, _i); }
  __CRT_INLINE অক্ষর *__cdecl ulltoa (unsigned long long _n, অক্ষর * _c, পূর্ণসংখ্যা _i) { ফেরত _ui64toa (_n, _c, _i); }
  __CRT_INLINE long long  __cdecl wtoll (ধ্রুবক wchar_t * _w) { ফেরত _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (long long _n, wchar_t * _w, পূর্ণসংখ্যা _i) { ফেরত _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (unsigned long long _n, wchar_t * _w, পূর্ণসংখ্যা _i) { ফেরত _ui64tow (_n, _w, _i); }
#endif /* (__STRICT_ANSI__)  */

#endif /* !__NO_ISOCEXT */

#ifdef __cplusplus
}
#endif

#pragma pack(বের_করো)

#অন্তর্ভাব <sec_api/stdlib_s.h>
#অন্তর্ভাব <malloc.h>

#endif
