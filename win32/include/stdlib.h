/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB
#define _INC_STDLIB

#ضمن <_mingw.h>
#ضمن <limits.h>

#pragma pack(ادفع,_CRT_PACKING)

#ifdef __cplusplus
خارجي "C" {
#endif

#ifndef عدم
#ifdef __cplusplus
#define عدم 0
#وإلا
#define عدم ((فراغ *)0)
#endif
#endif

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#ifndef _ONEXIT_T_DEFINED
#define _ONEXIT_T_DEFINED

  تعريفنوع صحيح (__cdecl *_onexit_t)(فراغ);

#ifndef NO_OLDNAMES
#define onexit_t _onexit_t
#endif
#endif

#ifndef _DIV_T_DEFINED
#define _DIV_T_DEFINED

  تعريفنوع بنية _div_t {
    صحيح quot;
    صحيح rem;
  } div_t;

  تعريفنوع بنية _ldiv_t {
    long quot;
    long rem;
  } ldiv_t;
#endif

#ifndef _CRT_DOUBLE_DEC
#define _CRT_DOUBLE_DEC

#pragma pack(4)
  تعريفنوع بنية {
    unsigned حرف ld[10];
  } _LDOUBLE;
#pragma pack()

#define _PTR_LD(x) ((unsigned حرف *)(&(x)->ld))

  تعريفنوع بنية {
    مزدوج x;
  } _CRT_DOUBLE;

  تعريفنوع بنية {
    عائم f;
  } _CRT_FLOAT;

#pragma ادفع_macro("long")
#undef long

  تعريفنوع بنية {
    long مزدوج x;
  } _LONGDOUBLE;

#pragma اسحب_macro("long")

#pragma pack(4)
  تعريفنوع بنية {
    unsigned حرف ld12[12];
  } _LDBL12;
#pragma pack()
#endif

#define RAND_MAX 0x7fff

#ifndef MB_CUR_MAX
#define MB_CUR_MAX ___mb_cur_max_func()
#ifndef __mb_cur_max
#ifdef _MSVCRT_
  خارجي صحيح __mb_cur_max;
#وإلا
#define __mb_cur_max    (*_imp____mb_cur_max)
  خارجي صحيح *_imp____mb_cur_max;
#endif
#endif
#ifdef _MSVCRT_
  خارجي صحيح __mbcur_max;
#define ___mb_cur_max_func() (__mb_cur_max)
#وإلا
  خارجي صحيح* _imp____mbcur_max;
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

#define WRITE_ABORT_رسالة 0x1
#define _CALL_REPORTFAULT 0x2

#define _MAX_ENV 32767

  تعريفنوع فراغ (__cdecl *_purecall_handler)(فراغ);

  _CRTIMP _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(فراغ);

  تعريفنوع فراغ (__cdecl *_invalid_parameter_handler)(ثابت wchar_t *,ثابت wchar_t *,ثابت wchar_t *,unsigned صحيح,uintptr_t);
  _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(فراغ);

#ifndef _CRT_ERRNO_DEFINED
#define _CRT_ERRNO_DEFINED
  _CRTIMP صحيح *__cdecl _errno(فراغ);
#define errno (*_errno())
  errno_t __cdecl _set_errno(صحيح قيمة_2);
  errno_t __cdecl _get_errno(صحيح *قيمة_2);
#endif
  _CRTIMP unsigned long *__cdecl __doserrno(فراغ);
#define _doserrno (*__doserrno())
  errno_t __cdecl _set_doserrno(unsigned long قيمة_2);
  errno_t __cdecl _get_doserrno(unsigned long *قيمة_2);
#ifdef _MSVCRT_
  خارجي حرف *_sys_errlist[];
  خارجي صحيح _sys_nerr;
#وإلا
  _CRTIMP حرف *_sys_errlist[1];
  _CRTIMP صحيح _sys_nerr;
#endif
#إذا (defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحيح *__cdecl __p___argc(فراغ);
  _CRTIMP حرف ***__cdecl __p___argv(فراغ);
  _CRTIMP wchar_t ***__cdecl __p___wargv(فراغ);
  _CRTIMP حرف ***__cdecl __p__environ(فراغ);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(فراغ);
  _CRTIMP حرف **__cdecl __p__pgmptr(فراغ);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(فراغ);
#endif
#ifndef __argc
#ifdef _MSVCRT_
  خارجي صحيح __argc;
#وإلا
#define __argc (*_imp____argc)
  خارجي صحيح *_imp____argc;
#endif
#endif
#ifndef __argv
#ifdef _MSVCRT_
  خارجي حرف **__argv;
#وإلا
#define __argv  (*_imp____argv)
  خارجي حرف ***_imp____argv;
#endif
#endif
#ifndef __wargv
#ifdef _MSVCRT_
  خارجي wchar_t **__wargv;
#وإلا
#define __wargv (*_imp____wargv)
  خارجي wchar_t ***_imp____wargv;
#endif
#endif

#ifdef _POSIX_
  خارجي حرف **environ;
#وإلا
#ifndef _environ
#ifdef _MSVCRT_
  خارجي حرف **_environ;
#وإلا
#define _environ (*_imp___environ)
  خارجي حرف ***_imp___environ;
#endif
#endif

#ifndef _wenviron
#ifdef _MSVCRT_
  خارجي wchar_t **_wenviron;
#وإلا
#define _wenviron       (*_imp___wenviron)
  خارجي wchar_t ***_imp___wenviron;
#endif
#endif
#endif

#إذا defined __aarch64__
/* something does not work using those from msvcrt.dll */
# undef __argc
# undef __argv
# undef __wargv
# undef _wenviron
# undef _environ
خارجي صحيح __argc;
خارجي حرف **__argv;
خارجي wchar_t **__wargv;
خارجي حرف **_environ;
خارجي wchar_t **_wenviron;
#endif

#ifndef _pgmptr
#ifdef _MSVCRT_
  خارجي حرف *_pgmptr;
#وإلا
#define _pgmptr (*_imp___pgmptr)
  خارجي حرف **_imp___pgmptr;
#endif
#endif

#ifndef _wpgmptr
#ifdef _MSVCRT_
  خارجي wchar_t *_wpgmptr;
#وإلا
#define _wpgmptr        (*_imp___wpgmptr)
  خارجي wchar_t **_imp___wpgmptr;
#endif
#endif
  errno_t __cdecl _get_pgmptr(حرف **قيمة_2);
  errno_t __cdecl _get_wpgmptr(wchar_t **قيمة_2);
#ifndef _fmode
#ifdef _MSVCRT_
  خارجي صحيح _fmode;
#وإلا
#define _fmode  (*_imp___fmode)
  خارجي صحيح *_imp___fmode;
#endif
#endif
  _CRTIMP errno_t __cdecl _set_fmode(صحيح _Mode);
  _CRTIMP errno_t __cdecl _get_fmode(صحيح *_PMode);

#ifndef _osplatform
#ifdef _MSVCRT_
  خارجي unsigned صحيح _osplatform;
#وإلا
#define _osplatform (*_imp___osplatform)
  خارجي unsigned صحيح *_imp___osplatform;
#endif
#endif

#ifndef _osver
#ifdef _MSVCRT_
  خارجي unsigned صحيح _osver;
#وإلا
#define _osver  (*_imp___osver)
  خارجي unsigned صحيح *_imp___osver;
#endif
#endif

#ifndef _winver
#ifdef _MSVCRT_
  خارجي unsigned صحيح _winver;
#وإلا
#define _winver (*_imp___winver)
  خارجي unsigned صحيح *_imp___winver;
#endif
#endif

#ifndef _winmajor
#ifdef _MSVCRT_
  خارجي unsigned صحيح _winmajor;
#وإلا
#define _winmajor       (*_imp___winmajor)
  خارجي unsigned صحيح *_imp___winmajor;
#endif
#endif

#ifndef _winminor
#ifdef _MSVCRT_
  خارجي unsigned صحيح _winminor;
#وإلا
#define _winminor       (*_imp___winminor)
  خارجي unsigned صحيح *_imp___winminor;
#endif
#endif

  errno_t __cdecl _get_osplatform(unsigned صحيح *قيمة_2);
  errno_t __cdecl _get_osver(unsigned صحيح *قيمة_2);
  errno_t __cdecl _get_winver(unsigned صحيح *قيمة_2);
  errno_t __cdecl _get_winmajor(unsigned صحيح *قيمة_2);
  errno_t __cdecl _get_winminor(unsigned صحيح *قيمة_2);
#ifndef _countof
#ifndef __cplusplus
#define _countof(_Array) (حجم(_Array) / حجم(_Array[0]))
#وإلا
  خارجي "C++" {
    template <typename _CountofType,size_t _SizeOfArray> حرف (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];
#define _countof(_Array) حجم(*__countof_helper(_Array))
  }
#endif
#endif

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  فراغ __cdecl __MINGW_NOTHROW exit(صحيح _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP فراغ __cdecl __MINGW_NOTHROW _exit(صحيح _Code) __MINGW_ATTRIB_NORETURN;
#إذا !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  فراغ __cdecl _Exit(صحيح) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN فراغ  __cdecl _Exit(صحيح status)
  {  _exit(status); }
#endif

#pragma ادفع_macro("abort")
#undef abort
  فراغ __cdecl __declspec(noreturn) abort(فراغ);
#pragma اسحب_macro("abort")

#endif

  _CRTIMP unsigned صحيح __cdecl _set_abort_behavior(unsigned صحيح _Flags,unsigned صحيح _Mask);

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  صحيح __cdecl abs(صحيح _X);
  long __cdecl labs(long _X);
#endif

#إذا _INTEGRAL_MAX_BITS >= 64
  __int64 __cdecl _abs64(__int64);
#endif
  صحيح __cdecl atexit(فراغ (__cdecl *)(فراغ));
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  مزدوج __cdecl atof(ثابت حرف *_String);
  مزدوج __cdecl _atof_l(ثابت حرف *_String,_locale_t _Locale);
#endif
  صحيح __cdecl atoi(ثابت حرف *_Str);
  _CRTIMP صحيح __cdecl _atoi_l(ثابت حرف *_Str,_locale_t _Locale);
  long __cdecl atol(ثابت حرف *_Str);
  _CRTIMP long __cdecl _atol_l(ثابت حرف *_Str,_locale_t _Locale);
#ifndef _CRT_ALGO_DEFINED
#define _CRT_ALGO_DEFINED
  فراغ *__cdecl bsearch(ثابت فراغ *مفتاح_2,ثابت فراغ *_Base,size_t رقم_Of_Elements,size_t _SizeOfElements,صحيح (__cdecl *_PtFuncCompare)(ثابت فراغ *,ثابت فراغ *));
  فراغ __cdecl qsort(فراغ *_Base,size_t رقم_Of_Elements,size_t _SizeOfElements,صحيح (__cdecl *_PtFuncCompare)(ثابت فراغ *,ثابت فراغ *));
#endif
  unsigned short __cdecl _byteswap_ushort(unsigned short _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#إذا _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Int64);
#endif
  div_t __cdecl div(صحيح _Numerator,صحيح _Denominator);
  حرف *__cdecl getenv(ثابت حرف *_VarName);
  _CRTIMP حرف *__cdecl _itoa(صحيح قيمة_2,حرف *_Dest,صحيح _Radix);
#إذا _INTEGRAL_MAX_BITS >= 64
  _CRTIMP حرف *__cdecl _i64toa(__int64 _Val,حرف *_DstBuf,صحيح _Radix);
  _CRTIMP حرف *__cdecl _ui64toa(unsigned __int64 _Val,حرف *_DstBuf,صحيح _Radix);
  _CRTIMP __int64 __cdecl _atoi64(ثابت حرف *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(ثابت حرف *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(ثابت حرف *_String,حرف **_EndPtr,صحيح _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(ثابت حرف *_String,حرف **_EndPtr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _strtoui64(ثابت حرف *_String,حرف **_EndPtr,صحيح _Radix);
  _CRTIMP unsigned __int64 __cdecl _strtoui64_l(ثابت حرف *_String,حرف **_EndPtr,صحيح _Radix,_locale_t _Locale);
#endif
  ldiv_t __cdecl ldiv(long _Numerator,long _Denominator);
  _CRTIMP حرف *__cdecl _ltoa(long قيمة_2,حرف *_Dest,صحيح _Radix);
  صحيح __cdecl mblen(ثابت حرف *_Ch,size_t Max_عدد);
  _CRTIMP صحيح __cdecl _mblen_l(ثابت حرف *_Ch,size_t Max_عدد,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrlen(ثابت حرف *_Str);
  _CRTIMP size_t __cdecl _mbstrlen_l(ثابت حرف *_Str,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrnlen(ثابت حرف *_Str,size_t Max_عدد);
  _CRTIMP size_t __cdecl _mbstrnlen_l(ثابت حرف *_Str,size_t Max_عدد,_locale_t _Locale);
  صحيح __cdecl mbtowc(wchar_t *_DstCh,ثابت حرف *_SrcCh,size_t _SrcSizeInBytes);
  _CRTIMP صحيح __cdecl _mbtowc_l(wchar_t *_DstCh,ثابت حرف *_SrcCh,size_t _SrcSizeInBytes,_locale_t _Locale);
  size_t __cdecl mbstowcs(wchar_t *_Dest,ثابت حرف *_Source,size_t Max_عدد);
  _CRTIMP size_t __cdecl _mbstowcs_l(wchar_t *_Dest,ثابت حرف *_Source,size_t Max_عدد,_locale_t _Locale);
  صحيح __cdecl rand(فراغ);
  _CRTIMP صحيح __cdecl _set_error_mode(صحيح _Mode);
  فراغ __cdecl srand(unsigned صحيح _Seed);
  مزدوج __cdecl strtod(ثابت حرف *_Str,حرف **_EndPtr);
#إذا !defined __NO_ISOCEXT  /* in libmingwex.a */
#إذا __TINYC__
  __CRT_INLINE عائم __cdecl strtof (ثابت حرف *p, حرف ** e) { أرجع strtod(p, e); }
  __CRT_INLINE long مزدوج __cdecl strtold(ثابت حرف *p, حرف ** e) { أرجع strtod(p, e); }
#وإلا
  عائم __cdecl strtof (ثابت حرف * __restrict__, حرف ** __restrict__);
  long مزدوج __cdecl strtold(ثابت حرف * __restrict__, حرف ** __restrict__);
#endif
#وإلا
  عائم __cdecl strtof(ثابت حرف *nptr, حرف **endptr);
#endif /* __NO_ISOCEXT */
  _CRTIMP مزدوج __cdecl _strtod_l(ثابت حرف *_Str,حرف **_EndPtr,_locale_t _Locale);
  long __cdecl strtol(ثابت حرف *_Str,حرف **_EndPtr,صحيح _Radix);
  _CRTIMP long __cdecl _strtol_l(ثابت حرف *_Str,حرف **_EndPtr,صحيح _Radix,_locale_t _Locale);
  unsigned long __cdecl strtoul(ثابت حرف *_Str,حرف **_EndPtr,صحيح _Radix);
  _CRTIMP unsigned long __cdecl _strtoul_l(ثابت حرف *_Str,حرف **_EndPtr,صحيح _Radix,_locale_t _Locale);
#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  صحيح __cdecl system(ثابت حرف *_Command);
#endif
  _CRTIMP حرف *__cdecl _ultoa(unsigned long قيمة_2,حرف *_Dest,صحيح _Radix);
  صحيح __cdecl wctomb(حرف *_MbCh,wchar_t _WCh);
  _CRTIMP صحيح __cdecl _wctomb_l(حرف *_MbCh,wchar_t _WCh,_locale_t _Locale);
  size_t __cdecl wcstombs(حرف *_Dest,ثابت wchar_t *_Source,size_t Max_عدد);
  _CRTIMP size_t __cdecl _wcstombs_l(حرف *_Dest,ثابت wchar_t *_Source,size_t Max_عدد,_locale_t _Locale);

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  فراغ *__cdecl calloc(size_t رقم_Of_Elements,size_t _SizeOfElements);
  فراغ __cdecl حرر(فراغ *_Memory);
  فراغ *__cdecl malloc(size_t _Size);
  فراغ *__cdecl realloc(فراغ *_Memory,size_t _NewSize);
  _CRTIMP فراغ *__cdecl _recalloc(فراغ *_Memory,size_t عدد_5,size_t _Size);
  _CRTIMP فراغ __cdecl _aligned_free(فراغ *_Memory);
  _CRTIMP فراغ *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP فراغ *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP فراغ *__cdecl _aligned_realloc(فراغ *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP فراغ *__cdecl _aligned_recalloc(فراغ *_Memory,size_t عدد_5,size_t _Size,size_t _Alignment);
  _CRTIMP فراغ *__cdecl _aligned_offset_realloc(فراغ *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP فراغ *__cdecl _aligned_offset_recalloc(فراغ *_Memory,size_t عدد_5,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(صحيح قيمة_2,wchar_t *_Dest,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long قيمة_2,wchar_t *_Dest,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long قيمة_2,wchar_t *_Dest,صحيح _Radix);
  مزدوج __cdecl wcstod(ثابت wchar_t *_Str,wchar_t **_EndPtr);
  عائم __cdecl wcstof(ثابت wchar_t *nptr, wchar_t **endptr);
#إذا !defined __NO_ISOCEXT /* in libmingwex.a */
  عائم __cdecl wcstof( ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
  long مزدوج __cdecl wcstold(ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  _CRTIMP مزدوج __cdecl _wcstod_l(ثابت wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  long __cdecl wcstol(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحيح _Radix);
  _CRTIMP long __cdecl _wcstol_l(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحيح _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحيح _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ثابت wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP صحيح __cdecl _wsystem(ثابت wchar_t *_Command);
#endif
  _CRTIMP مزدوج __cdecl _wtof(ثابت wchar_t *_Str);
  _CRTIMP مزدوج __cdecl _wtof_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wtoi(ثابت wchar_t *_Str);
  _CRTIMP صحيح __cdecl _wtoi_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(ثابت wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(ثابت wchar_t *_Str,_locale_t _Locale);

#إذا _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,صحيح _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ثابت wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحيح _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحيح _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(ثابت wchar_t *_Str ,wchar_t **_EndPtr,صحيح _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#define _CVTBUFSIZE (309+40)
  _CRTIMP حرف *__cdecl _fullpath(حرف *_FullPath,ثابت حرف *_Path,size_t _SizeInBytes);
  _CRTIMP حرف *__cdecl _ecvt(مزدوج _Val,صحيح رقم_Of_Digits,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP حرف *__cdecl _fcvt(مزدوج _Val,صحيح رقم_Of_Dec,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP حرف *__cdecl _gcvt(مزدوج _Val,صحيح رقم_Of_Digits,حرف *_DstBuf);
  _CRTIMP صحيح __cdecl _atodbl(_CRT_DOUBLE *_Result,حرف *_Str);
  _CRTIMP صحيح __cdecl _atoldbl(_LDOUBLE *_Result,حرف *_Str);
  _CRTIMP صحيح __cdecl _atoflt(_CRT_FLOAT *_Result,حرف *_Str);
  _CRTIMP صحيح __cdecl _atodbl_l(_CRT_DOUBLE *_Result,حرف *_Str,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _atoldbl_l(_LDOUBLE *_Result,حرف *_Str,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _atoflt_l(_CRT_FLOAT *_Result,حرف *_Str,_locale_t _Locale);
  unsigned long __cdecl _lrotl(unsigned long _Val,صحيح _Shift);
  unsigned long __cdecl _lrotr(unsigned long _Val,صحيح _Shift);
  _CRTIMP فراغ __cdecl _makepath(حرف *_Path,ثابت حرف *_Drive,ثابت حرف *_Dir,ثابت حرف *_Filename,ثابت حرف *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  فراغ __cdecl perror(ثابت حرف *Err_رسالة);
#endif
  _CRTIMP صحيح __cdecl _putenv(ثابت حرف *_EnvString);
  unsigned صحيح __cdecl _rotl(unsigned صحيح _Val,صحيح _Shift);
#إذا _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotl64(unsigned __int64 _Val,صحيح _Shift);
#endif
  unsigned صحيح __cdecl _rotr(unsigned صحيح _Val,صحيح _Shift);
#إذا _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotr64(unsigned __int64 _Val,صحيح _Shift);
#endif
  _CRTIMP فراغ __cdecl _searchenv(ثابت حرف *_Filename,ثابت حرف *_EnvVar,حرف *_ResultPath);
  _CRTIMP فراغ __cdecl _splitpath(ثابت حرف *_FullPath,حرف *_Drive,حرف *_Dir,حرف *_Filename,حرف *_Ext);
  _CRTIMP فراغ __cdecl _swab(حرف *_Buf1,حرف *_Buf2,صحيح _SizeInBytes);

#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,ثابت wchar_t *_Path,size_t Size_In_كلمات);
  _CRTIMP فراغ __cdecl _wmakepath(wchar_t *_ResultPath,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP فراغ __cdecl _wperror(ثابت wchar_t *Err_رسالة);
#endif
  _CRTIMP صحيح __cdecl _wputenv(ثابت wchar_t *_EnvString);
  _CRTIMP فراغ __cdecl _wsearchenv(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP فراغ __cdecl _wsplitpath(ثابت wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif

  _CRTIMP فراغ __cdecl _beep(unsigned _Frequency,unsigned _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP فراغ __cdecl _seterrormode(صحيح _Mode) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP فراغ __cdecl _sleep(unsigned long _Duration) __MINGW_ATTRIB_DEPRECATED;
#endif

#ifndef NO_OLDNAMES
#ifndef _POSIX_
#إذا 0
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
  حرف *__cdecl ecvt(مزدوج _Val,صحيح رقم_Of_Digits,صحيح *_PtDec,صحيح *_PtSign);
  حرف *__cdecl fcvt(مزدوج _Val,صحيح رقم_Of_Dec,صحيح *_PtDec,صحيح *_PtSign);
  حرف *__cdecl gcvt(مزدوج _Val,صحيح رقم_Of_Digits,حرف *_DstBuf);
  حرف *__cdecl itoa(صحيح _Val,حرف *_DstBuf,صحيح _Radix);
  حرف *__cdecl ltoa(long _Val,حرف *_DstBuf,صحيح _Radix);
  صحيح __cdecl putenv(ثابت حرف *_EnvString);
  فراغ __cdecl swab(حرف *_Buf1,حرف *_Buf2,صحيح _SizeInBytes);
  حرف *__cdecl ultoa(unsigned long _Val,حرف *_Dstbuf,صحيح _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#endif
#endif

#إذا !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  تعريفنوع بنية { long long quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(long long, long long);

  __CRT_INLINE long long __cdecl llabs(long long _j) { أرجع (_j >= 0 ? _j : -_j); }

 #ifdef __TINYC__ /* gr */
  #define strtoll _strtoi64
  #define strtoull _strtoui64
 #وإلا
  long long  __cdecl strtoll(ثابت حرف* __restrict__, حرف** __restrict, صحيح);
  unsigned long long  __cdecl strtoull(ثابت حرف* __restrict__, حرف** __restrict__, صحيح);
 #endif

  /* these are stubs for MS _i64 versions */
  long long  __cdecl atoll (ثابت حرف *);

#ifndef __STRICT_ANSI__
  long long  __cdecl wtoll (ثابت wchar_t *);
  حرف *__cdecl lltoa (long long, حرف *, صحيح);
  حرف *__cdecl ulltoa (unsigned long long , حرف *, صحيح);
  wchar_t *__cdecl lltow (long long, wchar_t *, صحيح);
  wchar_t *__cdecl ulltow (unsigned long long, wchar_t *, صحيح);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE long long  __cdecl atoll (ثابت حرف * _c) { أرجع _atoi64 (_c); }
  __CRT_INLINE حرف *__cdecl lltoa (long long _n, حرف * _c, صحيح _i) { أرجع _i64toa (_n, _c, _i); }
  __CRT_INLINE حرف *__cdecl ulltoa (unsigned long long _n, حرف * _c, صحيح _i) { أرجع _ui64toa (_n, _c, _i); }
  __CRT_INLINE long long  __cdecl wtoll (ثابت wchar_t * _w) { أرجع _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (long long _n, wchar_t * _w, صحيح _i) { أرجع _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (unsigned long long _n, wchar_t * _w, صحيح _i) { أرجع _ui64tow (_n, _w, _i); }
#endif /* (__STRICT_ANSI__)  */

#endif /* !__NO_ISOCEXT */

#ifdef __cplusplus
}
#endif

#pragma pack(اسحب)

#ضمن <sec_api/stdlib_s.h>
#ضمن <malloc.h>

#endif
