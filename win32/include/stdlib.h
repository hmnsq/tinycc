/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB
#define _INC_STDLIB

#شامل <_mingw.h>
#شامل <limits.h>

#pragma pack(افزودن,_CRT_PACKING)

#ifdef __cplusplus
بیرونی "C" {
#endif

#ifndef پوچ
#ifdef __cplusplus
#define پوچ 0
#وگرنه
#define پوچ ((تهی *)0)
#endif
#endif

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#ifndef _ONEXIT_T_DEFINED
#define _ONEXIT_T_DEFINED

  تعریفنوع صحیح (__cdecl *_onexit_t)(تهی);

#ifndef NO_OLDNAMES
#define onexit_t _onexit_t
#endif
#endif

#ifndef _DIV_T_DEFINED
#define _DIV_T_DEFINED

  تعریفنوع ساختار _div_t {
    صحیح quot;
    صحیح rem;
  } div_t;

  تعریفنوع ساختار _ldiv_t {
    long quot;
    long rem;
  } ldiv_t;
#endif

#ifndef _CRT_DOUBLE_DEC
#define _CRT_DOUBLE_DEC

#pragma pack(4)
  تعریفنوع ساختار {
    unsigned نویسه ld[10];
  } _LDOUBLE;
#pragma pack()

#define _PTR_LD(x) ((unsigned نویسه *)(&(x)->ld))

  تعریفنوع ساختار {
    دوگانه x;
  } _CRT_DOUBLE;

  تعریفنوع ساختار {
    اعشاری f;
  } _CRT_FLOAT;

#pragma افزودن_macro("long")
#undef long

  تعریفنوع ساختار {
    long دوگانه x;
  } _LONGDOUBLE;

#pragma برداشت_macro("long")

#pragma pack(4)
  تعریفنوع ساختار {
    unsigned نویسه ld12[12];
  } _LDBL12;
#pragma pack()
#endif

#define RAND_MAX 0x7fff

#ifndef MB_CUR_MAX
#define MB_CUR_MAX ___mb_cur_max_func()
#ifndef __mb_cur_max
#ifdef _MSVCRT_
  بیرونی صحیح __mb_cur_max;
#وگرنه
#define __mb_cur_max    (*_imp____mb_cur_max)
  بیرونی صحیح *_imp____mb_cur_max;
#endif
#endif
#ifdef _MSVCRT_
  بیرونی صحیح __mbcur_max;
#define ___mb_cur_max_func() (__mb_cur_max)
#وگرنه
  بیرونی صحیح* _imp____mbcur_max;
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

#define WRITE_ABORT_پیام 0x1
#define _CALL_REPORTFAULT 0x2

#define _MAX_ENV 32767

  تعریفنوع تهی (__cdecl *_purecall_handler)(تهی);

  _CRTIMP _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(تهی);

  تعریفنوع تهی (__cdecl *_invalid_parameter_handler)(ثابت wchar_t *,ثابت wchar_t *,ثابت wchar_t *,unsigned صحیح,uintptr_t);
  _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(تهی);

#ifndef _CRT_ERRNO_DEFINED
#define _CRT_ERRNO_DEFINED
  _CRTIMP صحیح *__cdecl _errno(تهی);
#define errno (*_errno())
  errno_t __cdecl _set_errno(صحیح مقدار_2);
  errno_t __cdecl _get_errno(صحیح *مقدار_2);
#endif
  _CRTIMP unsigned long *__cdecl __doserrno(تهی);
#define _doserrno (*__doserrno())
  errno_t __cdecl _set_doserrno(unsigned long مقدار_2);
  errno_t __cdecl _get_doserrno(unsigned long *مقدار_2);
#ifdef _MSVCRT_
  بیرونی نویسه *_sys_errlist[];
  بیرونی صحیح _sys_nerr;
#وگرنه
  _CRTIMP نویسه *_sys_errlist[1];
  _CRTIMP صحیح _sys_nerr;
#endif
#اگر (defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحیح *__cdecl __p___argc(تهی);
  _CRTIMP نویسه ***__cdecl __p___argv(تهی);
  _CRTIMP wchar_t ***__cdecl __p___wargv(تهی);
  _CRTIMP نویسه ***__cdecl __p__environ(تهی);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(تهی);
  _CRTIMP نویسه **__cdecl __p__pgmptr(تهی);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(تهی);
#endif
#ifndef __argc
#ifdef _MSVCRT_
  بیرونی صحیح __argc;
#وگرنه
#define __argc (*_imp____argc)
  بیرونی صحیح *_imp____argc;
#endif
#endif
#ifndef __argv
#ifdef _MSVCRT_
  بیرونی نویسه **__argv;
#وگرنه
#define __argv  (*_imp____argv)
  بیرونی نویسه ***_imp____argv;
#endif
#endif
#ifndef __wargv
#ifdef _MSVCRT_
  بیرونی wchar_t **__wargv;
#وگرنه
#define __wargv (*_imp____wargv)
  بیرونی wchar_t ***_imp____wargv;
#endif
#endif

#ifdef _POSIX_
  بیرونی نویسه **environ;
#وگرنه
#ifndef _environ
#ifdef _MSVCRT_
  بیرونی نویسه **_environ;
#وگرنه
#define _environ (*_imp___environ)
  بیرونی نویسه ***_imp___environ;
#endif
#endif

#ifndef _wenviron
#ifdef _MSVCRT_
  بیرونی wchar_t **_wenviron;
#وگرنه
#define _wenviron       (*_imp___wenviron)
  بیرونی wchar_t ***_imp___wenviron;
#endif
#endif
#endif

#اگر defined __aarch64__
/* something does not work using those from msvcrt.dll */
# undef __argc
# undef __argv
# undef __wargv
# undef _wenviron
# undef _environ
بیرونی صحیح __argc;
بیرونی نویسه **__argv;
بیرونی wchar_t **__wargv;
بیرونی نویسه **_environ;
بیرونی wchar_t **_wenviron;
#endif

#ifndef _pgmptr
#ifdef _MSVCRT_
  بیرونی نویسه *_pgmptr;
#وگرنه
#define _pgmptr (*_imp___pgmptr)
  بیرونی نویسه **_imp___pgmptr;
#endif
#endif

#ifndef _wpgmptr
#ifdef _MSVCRT_
  بیرونی wchar_t *_wpgmptr;
#وگرنه
#define _wpgmptr        (*_imp___wpgmptr)
  بیرونی wchar_t **_imp___wpgmptr;
#endif
#endif
  errno_t __cdecl _get_pgmptr(نویسه **مقدار_2);
  errno_t __cdecl _get_wpgmptr(wchar_t **مقدار_2);
#ifndef _fmode
#ifdef _MSVCRT_
  بیرونی صحیح _fmode;
#وگرنه
#define _fmode  (*_imp___fmode)
  بیرونی صحیح *_imp___fmode;
#endif
#endif
  _CRTIMP errno_t __cdecl _set_fmode(صحیح _Mode);
  _CRTIMP errno_t __cdecl _get_fmode(صحیح *_PMode);

#ifndef _osplatform
#ifdef _MSVCRT_
  بیرونی unsigned صحیح _osplatform;
#وگرنه
#define _osplatform (*_imp___osplatform)
  بیرونی unsigned صحیح *_imp___osplatform;
#endif
#endif

#ifndef _osver
#ifdef _MSVCRT_
  بیرونی unsigned صحیح _osver;
#وگرنه
#define _osver  (*_imp___osver)
  بیرونی unsigned صحیح *_imp___osver;
#endif
#endif

#ifndef _winver
#ifdef _MSVCRT_
  بیرونی unsigned صحیح _winver;
#وگرنه
#define _winver (*_imp___winver)
  بیرونی unsigned صحیح *_imp___winver;
#endif
#endif

#ifndef _winmajor
#ifdef _MSVCRT_
  بیرونی unsigned صحیح _winmajor;
#وگرنه
#define _winmajor       (*_imp___winmajor)
  بیرونی unsigned صحیح *_imp___winmajor;
#endif
#endif

#ifndef _winminor
#ifdef _MSVCRT_
  بیرونی unsigned صحیح _winminor;
#وگرنه
#define _winminor       (*_imp___winminor)
  بیرونی unsigned صحیح *_imp___winminor;
#endif
#endif

  errno_t __cdecl _get_osplatform(unsigned صحیح *مقدار_2);
  errno_t __cdecl _get_osver(unsigned صحیح *مقدار_2);
  errno_t __cdecl _get_winver(unsigned صحیح *مقدار_2);
  errno_t __cdecl _get_winmajor(unsigned صحیح *مقدار_2);
  errno_t __cdecl _get_winminor(unsigned صحیح *مقدار_2);
#ifndef _countof
#ifndef __cplusplus
#define _countof(_Array) (اندازه(_Array) / اندازه(_Array[0]))
#وگرنه
  بیرونی "C++" {
    template <typename _CountofType,size_t _SizeOfArray> نویسه (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];
#define _countof(_Array) اندازه(*__countof_helper(_Array))
  }
#endif
#endif

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  تهی __cdecl __MINGW_NOTHROW exit(صحیح _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP تهی __cdecl __MINGW_NOTHROW _exit(صحیح _Code) __MINGW_ATTRIB_NORETURN;
#اگر !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  تهی __cdecl _Exit(صحیح) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN تهی  __cdecl _Exit(صحیح status)
  {  _exit(status); }
#endif

#pragma افزودن_macro("abort")
#undef abort
  تهی __cdecl __declspec(noreturn) abort(تهی);
#pragma برداشت_macro("abort")

#endif

  _CRTIMP unsigned صحیح __cdecl _set_abort_behavior(unsigned صحیح _Flags,unsigned صحیح _Mask);

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  صحیح __cdecl abs(صحیح _X);
  long __cdecl labs(long _X);
#endif

#اگر _INTEGRAL_MAX_BITS >= 64
  __int64 __cdecl _abs64(__int64);
#endif
  صحیح __cdecl atexit(تهی (__cdecl *)(تهی));
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  دوگانه __cdecl atof(ثابت نویسه *_String);
  دوگانه __cdecl _atof_l(ثابت نویسه *_String,_locale_t _Locale);
#endif
  صحیح __cdecl atoi(ثابت نویسه *_Str);
  _CRTIMP صحیح __cdecl _atoi_l(ثابت نویسه *_Str,_locale_t _Locale);
  long __cdecl atol(ثابت نویسه *_Str);
  _CRTIMP long __cdecl _atol_l(ثابت نویسه *_Str,_locale_t _Locale);
#ifndef _CRT_ALGO_DEFINED
#define _CRT_ALGO_DEFINED
  تهی *__cdecl bsearch(ثابت تهی *کلید_2,ثابت تهی *_Base,size_t رقم_Of_Elements,size_t _SizeOfElements,صحیح (__cdecl *_PtFuncCompare)(ثابت تهی *,ثابت تهی *));
  تهی __cdecl qsort(تهی *_Base,size_t رقم_Of_Elements,size_t _SizeOfElements,صحیح (__cdecl *_PtFuncCompare)(ثابت تهی *,ثابت تهی *));
#endif
  unsigned short __cdecl _byteswap_ushort(unsigned short _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#اگر _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Int64);
#endif
  div_t __cdecl div(صحیح _Numerator,صحیح _Denominator);
  نویسه *__cdecl getenv(ثابت نویسه *_VarName);
  _CRTIMP نویسه *__cdecl _itoa(صحیح مقدار_2,نویسه *_Dest,صحیح _Radix);
#اگر _INTEGRAL_MAX_BITS >= 64
  _CRTIMP نویسه *__cdecl _i64toa(__int64 _Val,نویسه *_DstBuf,صحیح _Radix);
  _CRTIMP نویسه *__cdecl _ui64toa(unsigned __int64 _Val,نویسه *_DstBuf,صحیح _Radix);
  _CRTIMP __int64 __cdecl _atoi64(ثابت نویسه *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(ثابت نویسه *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(ثابت نویسه *_String,نویسه **_EndPtr,صحیح _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(ثابت نویسه *_String,نویسه **_EndPtr,صحیح _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _strtoui64(ثابت نویسه *_String,نویسه **_EndPtr,صحیح _Radix);
  _CRTIMP unsigned __int64 __cdecl _strtoui64_l(ثابت نویسه *_String,نویسه **_EndPtr,صحیح _Radix,_locale_t _Locale);
#endif
  ldiv_t __cdecl ldiv(long _Numerator,long _Denominator);
  _CRTIMP نویسه *__cdecl _ltoa(long مقدار_2,نویسه *_Dest,صحیح _Radix);
  صحیح __cdecl mblen(ثابت نویسه *_Ch,size_t Max_شمار);
  _CRTIMP صحیح __cdecl _mblen_l(ثابت نویسه *_Ch,size_t Max_شمار,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrlen(ثابت نویسه *_Str);
  _CRTIMP size_t __cdecl _mbstrlen_l(ثابت نویسه *_Str,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrnlen(ثابت نویسه *_Str,size_t Max_شمار);
  _CRTIMP size_t __cdecl _mbstrnlen_l(ثابت نویسه *_Str,size_t Max_شمار,_locale_t _Locale);
  صحیح __cdecl mbtowc(wchar_t *_DstCh,ثابت نویسه *_SrcCh,size_t _SrcSizeInBytes);
  _CRTIMP صحیح __cdecl _mbtowc_l(wchar_t *_DstCh,ثابت نویسه *_SrcCh,size_t _SrcSizeInBytes,_locale_t _Locale);
  size_t __cdecl mbstowcs(wchar_t *_Dest,ثابت نویسه *_Source,size_t Max_شمار);
  _CRTIMP size_t __cdecl _mbstowcs_l(wchar_t *_Dest,ثابت نویسه *_Source,size_t Max_شمار,_locale_t _Locale);
  صحیح __cdecl rand(تهی);
  _CRTIMP صحیح __cdecl _set_error_mode(صحیح _Mode);
  تهی __cdecl srand(unsigned صحیح _Seed);
  دوگانه __cdecl strtod(ثابت نویسه *_Str,نویسه **_EndPtr);
#اگر !defined __NO_ISOCEXT  /* in libmingwex.a */
#اگر __TINYC__
  __CRT_INLINE اعشاری __cdecl strtof (ثابت نویسه *p, نویسه ** e) { بازگشت strtod(p, e); }
  __CRT_INLINE long دوگانه __cdecl strtold(ثابت نویسه *p, نویسه ** e) { بازگشت strtod(p, e); }
#وگرنه
  اعشاری __cdecl strtof (ثابت نویسه * __restrict__, نویسه ** __restrict__);
  long دوگانه __cdecl strtold(ثابت نویسه * __restrict__, نویسه ** __restrict__);
#endif
#وگرنه
  اعشاری __cdecl strtof(ثابت نویسه *nptr, نویسه **endptr);
#endif /* __NO_ISOCEXT */
  _CRTIMP دوگانه __cdecl _strtod_l(ثابت نویسه *_Str,نویسه **_EndPtr,_locale_t _Locale);
  long __cdecl strtol(ثابت نویسه *_Str,نویسه **_EndPtr,صحیح _Radix);
  _CRTIMP long __cdecl _strtol_l(ثابت نویسه *_Str,نویسه **_EndPtr,صحیح _Radix,_locale_t _Locale);
  unsigned long __cdecl strtoul(ثابت نویسه *_Str,نویسه **_EndPtr,صحیح _Radix);
  _CRTIMP unsigned long __cdecl _strtoul_l(ثابت نویسه *_Str,نویسه **_EndPtr,صحیح _Radix,_locale_t _Locale);
#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  صحیح __cdecl system(ثابت نویسه *_Command);
#endif
  _CRTIMP نویسه *__cdecl _ultoa(unsigned long مقدار_2,نویسه *_Dest,صحیح _Radix);
  صحیح __cdecl wctomb(نویسه *_MbCh,wchar_t _WCh);
  _CRTIMP صحیح __cdecl _wctomb_l(نویسه *_MbCh,wchar_t _WCh,_locale_t _Locale);
  size_t __cdecl wcstombs(نویسه *_Dest,ثابت wchar_t *_Source,size_t Max_شمار);
  _CRTIMP size_t __cdecl _wcstombs_l(نویسه *_Dest,ثابت wchar_t *_Source,size_t Max_شمار,_locale_t _Locale);

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  تهی *__cdecl calloc(size_t رقم_Of_Elements,size_t _SizeOfElements);
  تهی __cdecl آزاد(تهی *_Memory);
  تهی *__cdecl malloc(size_t _Size);
  تهی *__cdecl realloc(تهی *_Memory,size_t _NewSize);
  _CRTIMP تهی *__cdecl _recalloc(تهی *_Memory,size_t شمار_5,size_t _Size);
  _CRTIMP تهی __cdecl _aligned_free(تهی *_Memory);
  _CRTIMP تهی *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP تهی *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP تهی *__cdecl _aligned_realloc(تهی *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP تهی *__cdecl _aligned_recalloc(تهی *_Memory,size_t شمار_5,size_t _Size,size_t _Alignment);
  _CRTIMP تهی *__cdecl _aligned_offset_realloc(تهی *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP تهی *__cdecl _aligned_offset_recalloc(تهی *_Memory,size_t شمار_5,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(صحیح مقدار_2,wchar_t *_Dest,صحیح _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long مقدار_2,wchar_t *_Dest,صحیح _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long مقدار_2,wchar_t *_Dest,صحیح _Radix);
  دوگانه __cdecl wcstod(ثابت wchar_t *_Str,wchar_t **_EndPtr);
  اعشاری __cdecl wcstof(ثابت wchar_t *nptr, wchar_t **endptr);
#اگر !defined __NO_ISOCEXT /* in libmingwex.a */
  اعشاری __cdecl wcstof( ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
  long دوگانه __cdecl wcstold(ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  _CRTIMP دوگانه __cdecl _wcstod_l(ثابت wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  long __cdecl wcstol(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحیح _Radix);
  _CRTIMP long __cdecl _wcstol_l(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحیح _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحیح _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحیح _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ثابت wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP صحیح __cdecl _wsystem(ثابت wchar_t *_Command);
#endif
  _CRTIMP دوگانه __cdecl _wtof(ثابت wchar_t *_Str);
  _CRTIMP دوگانه __cdecl _wtof_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wtoi(ثابت wchar_t *_Str);
  _CRTIMP صحیح __cdecl _wtoi_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(ثابت wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(ثابت wchar_t *_Str,_locale_t _Locale);

#اگر _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,صحیح _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,صحیح _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ثابت wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحیح _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحیح _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحیح _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(ثابت wchar_t *_Str ,wchar_t **_EndPtr,صحیح _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#define _CVTBUFSIZE (309+40)
  _CRTIMP نویسه *__cdecl _fullpath(نویسه *_FullPath,ثابت نویسه *_Path,size_t _SizeInBytes);
  _CRTIMP نویسه *__cdecl _ecvt(دوگانه _Val,صحیح رقم_Of_Digits,صحیح *_PtDec,صحیح *_PtSign);
  _CRTIMP نویسه *__cdecl _fcvt(دوگانه _Val,صحیح رقم_Of_Dec,صحیح *_PtDec,صحیح *_PtSign);
  _CRTIMP نویسه *__cdecl _gcvt(دوگانه _Val,صحیح رقم_Of_Digits,نویسه *_DstBuf);
  _CRTIMP صحیح __cdecl _atodbl(_CRT_DOUBLE *_Result,نویسه *_Str);
  _CRTIMP صحیح __cdecl _atoldbl(_LDOUBLE *_Result,نویسه *_Str);
  _CRTIMP صحیح __cdecl _atoflt(_CRT_FLOAT *_Result,نویسه *_Str);
  _CRTIMP صحیح __cdecl _atodbl_l(_CRT_DOUBLE *_Result,نویسه *_Str,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _atoldbl_l(_LDOUBLE *_Result,نویسه *_Str,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _atoflt_l(_CRT_FLOAT *_Result,نویسه *_Str,_locale_t _Locale);
  unsigned long __cdecl _lrotl(unsigned long _Val,صحیح _Shift);
  unsigned long __cdecl _lrotr(unsigned long _Val,صحیح _Shift);
  _CRTIMP تهی __cdecl _makepath(نویسه *_Path,ثابت نویسه *_Drive,ثابت نویسه *_Dir,ثابت نویسه *_Filename,ثابت نویسه *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  تهی __cdecl perror(ثابت نویسه *Err_پیام);
#endif
  _CRTIMP صحیح __cdecl _putenv(ثابت نویسه *_EnvString);
  unsigned صحیح __cdecl _rotl(unsigned صحیح _Val,صحیح _Shift);
#اگر _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotl64(unsigned __int64 _Val,صحیح _Shift);
#endif
  unsigned صحیح __cdecl _rotr(unsigned صحیح _Val,صحیح _Shift);
#اگر _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotr64(unsigned __int64 _Val,صحیح _Shift);
#endif
  _CRTIMP تهی __cdecl _searchenv(ثابت نویسه *_Filename,ثابت نویسه *_EnvVar,نویسه *_ResultPath);
  _CRTIMP تهی __cdecl _splitpath(ثابت نویسه *_FullPath,نویسه *_Drive,نویسه *_Dir,نویسه *_Filename,نویسه *_Ext);
  _CRTIMP تهی __cdecl _swab(نویسه *_Buf1,نویسه *_Buf2,صحیح _SizeInBytes);

#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,ثابت wchar_t *_Path,size_t Size_In_واژگان);
  _CRTIMP تهی __cdecl _wmakepath(wchar_t *_ResultPath,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP تهی __cdecl _wperror(ثابت wchar_t *Err_پیام);
#endif
  _CRTIMP صحیح __cdecl _wputenv(ثابت wchar_t *_EnvString);
  _CRTIMP تهی __cdecl _wsearchenv(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP تهی __cdecl _wsplitpath(ثابت wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif

  _CRTIMP تهی __cdecl _beep(unsigned _Frequency,unsigned _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP تهی __cdecl _seterrormode(صحیح _Mode) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP تهی __cdecl _sleep(unsigned long _Duration) __MINGW_ATTRIB_DEPRECATED;
#endif

#ifndef NO_OLDNAMES
#ifndef _POSIX_
#اگر 0
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
  نویسه *__cdecl ecvt(دوگانه _Val,صحیح رقم_Of_Digits,صحیح *_PtDec,صحیح *_PtSign);
  نویسه *__cdecl fcvt(دوگانه _Val,صحیح رقم_Of_Dec,صحیح *_PtDec,صحیح *_PtSign);
  نویسه *__cdecl gcvt(دوگانه _Val,صحیح رقم_Of_Digits,نویسه *_DstBuf);
  نویسه *__cdecl itoa(صحیح _Val,نویسه *_DstBuf,صحیح _Radix);
  نویسه *__cdecl ltoa(long _Val,نویسه *_DstBuf,صحیح _Radix);
  صحیح __cdecl putenv(ثابت نویسه *_EnvString);
  تهی __cdecl swab(نویسه *_Buf1,نویسه *_Buf2,صحیح _SizeInBytes);
  نویسه *__cdecl ultoa(unsigned long _Val,نویسه *_Dstbuf,صحیح _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#endif
#endif

#اگر !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  تعریفنوع ساختار { long long quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(long long, long long);

  __CRT_INLINE long long __cdecl llabs(long long _j) { بازگشت (_j >= 0 ? _j : -_j); }

 #ifdef __TINYC__ /* gr */
  #define strtoll _strtoi64
  #define strtoull _strtoui64
 #وگرنه
  long long  __cdecl strtoll(ثابت نویسه* __restrict__, نویسه** __restrict, صحیح);
  unsigned long long  __cdecl strtoull(ثابت نویسه* __restrict__, نویسه** __restrict__, صحیح);
 #endif

  /* these are stubs for MS _i64 versions */
  long long  __cdecl atoll (ثابت نویسه *);

#ifndef __STRICT_ANSI__
  long long  __cdecl wtoll (ثابت wchar_t *);
  نویسه *__cdecl lltoa (long long, نویسه *, صحیح);
  نویسه *__cdecl ulltoa (unsigned long long , نویسه *, صحیح);
  wchar_t *__cdecl lltow (long long, wchar_t *, صحیح);
  wchar_t *__cdecl ulltow (unsigned long long, wchar_t *, صحیح);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE long long  __cdecl atoll (ثابت نویسه * _c) { بازگشت _atoi64 (_c); }
  __CRT_INLINE نویسه *__cdecl lltoa (long long _n, نویسه * _c, صحیح _i) { بازگشت _i64toa (_n, _c, _i); }
  __CRT_INLINE نویسه *__cdecl ulltoa (unsigned long long _n, نویسه * _c, صحیح _i) { بازگشت _ui64toa (_n, _c, _i); }
  __CRT_INLINE long long  __cdecl wtoll (ثابت wchar_t * _w) { بازگشت _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (long long _n, wchar_t * _w, صحیح _i) { بازگشت _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (unsigned long long _n, wchar_t * _w, صحیح _i) { بازگشت _ui64tow (_n, _w, _i); }
#endif /* (__STRICT_ANSI__)  */

#endif /* !__NO_ISOCEXT */

#ifdef __cplusplus
}
#endif

#pragma pack(برداشت)

#شامل <sec_api/stdlib_s.h>
#شامل <malloc.h>

#endif
