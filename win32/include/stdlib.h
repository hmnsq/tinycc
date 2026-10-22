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
বাহ্য "C" {
#endif

#ifndef রিক্ত
#ifdef __cplusplus
#define রিক্ত 0
#অন্যথা
#define রিক্ত ((শূন্য *)0)
#endif
#endif

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#ifndef _ONEXIT_T_DEFINED
#define _ONEXIT_T_DEFINED

  প্রকারনির্দেশ পূর্ণাঙ্ক (__cdecl *_onexit_t)(শূন্য);

#ifndef NO_OLDNAMES
#define onexit_t _onexit_t
#endif
#endif

#ifndef _DIV_T_DEFINED
#define _DIV_T_DEFINED

  প্রকারনির্দেশ সংরচনা _div_t {
    পূর্ণাঙ্ক quot;
    পূর্ণাঙ্ক rem;
  } div_t;

  প্রকারনির্দেশ সংরচনা _ldiv_t {
    long quot;
    long rem;
  } ldiv_t;
#endif

#ifndef _CRT_DOUBLE_DEC
#define _CRT_DOUBLE_DEC

#pragma pack(4)
  প্রকারনির্দেশ সংরচনা {
    unsigned বর্ণ ld[10];
  } _LDOUBLE;
#pragma pack()

#define _PTR_LD(x) ((unsigned বর্ণ *)(&(x)->ld))

  প্রকারনির্দেশ সংরচনা {
    দ্বিগুণ x;
  } _CRT_DOUBLE;

  প্রকারনির্দেশ সংরচনা {
    ভিন্ন f;
  } _CRT_FLOAT;

#pragma ঠেলো_macro("long")
#undef long

  প্রকারনির্দেশ সংরচনা {
    long দ্বিগুণ x;
  } _LONGDOUBLE;

#pragma বের_করো_macro("long")

#pragma pack(4)
  প্রকারনির্দেশ সংরচনা {
    unsigned বর্ণ ld12[12];
  } _LDBL12;
#pragma pack()
#endif

#define RAND_MAX 0x7fff

#ifndef MB_CUR_MAX
#define MB_CUR_MAX ___mb_cur_max_func()
#ifndef __mb_cur_max
#ifdef _MSVCRT_
  বাহ্য পূর্ণাঙ্ক __mb_cur_max;
#অন্যথা
#define __mb_cur_max    (*_imp____mb_cur_max)
  বাহ্য পূর্ণাঙ্ক *_imp____mb_cur_max;
#endif
#endif
#ifdef _MSVCRT_
  বাহ্য পূর্ণাঙ্ক __mbcur_max;
#define ___mb_cur_max_func() (__mb_cur_max)
#অন্যথা
  বাহ্য পূর্ণাঙ্ক* _imp____mbcur_max;
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

  প্রকারনির্দেশ শূন্য (__cdecl *_purecall_handler)(শূন্য);

  _CRTIMP _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(শূন্য);

  প্রকারনির্দেশ শূন্য (__cdecl *_invalid_parameter_handler)(ধ্রুব wchar_t *,ধ্রুব wchar_t *,ধ্রুব wchar_t *,unsigned পূর্ণাঙ্ক,uintptr_t);
  _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(শূন্য);

#ifndef _CRT_ERRNO_DEFINED
#define _CRT_ERRNO_DEFINED
  _CRTIMP পূর্ণাঙ্ক *__cdecl _errno(শূন্য);
#define errno (*_errno())
  errno_t __cdecl _set_errno(পূর্ণাঙ্ক মান_2);
  errno_t __cdecl _get_errno(পূর্ণাঙ্ক *মান_2);
#endif
  _CRTIMP unsigned long *__cdecl __doserrno(শূন্য);
#define _doserrno (*__doserrno())
  errno_t __cdecl _set_doserrno(unsigned long মান_2);
  errno_t __cdecl _get_doserrno(unsigned long *মান_2);
#ifdef _MSVCRT_
  বাহ্য বর্ণ *_sys_errlist[];
  বাহ্য পূর্ণাঙ্ক _sys_nerr;
#অন্যথা
  _CRTIMP বর্ণ *_sys_errlist[1];
  _CRTIMP পূর্ণাঙ্ক _sys_nerr;
#endif
#যদি (defined(_X86_) && !defined(__x86_64))
  _CRTIMP পূর্ণাঙ্ক *__cdecl __p___argc(শূন্য);
  _CRTIMP বর্ণ ***__cdecl __p___argv(শূন্য);
  _CRTIMP wchar_t ***__cdecl __p___wargv(শূন্য);
  _CRTIMP বর্ণ ***__cdecl __p__environ(শূন্য);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(শূন্য);
  _CRTIMP বর্ণ **__cdecl __p__pgmptr(শূন্য);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(শূন্য);
#endif
#ifndef __argc
#ifdef _MSVCRT_
  বাহ্য পূর্ণাঙ্ক __argc;
#অন্যথা
#define __argc (*_imp____argc)
  বাহ্য পূর্ণাঙ্ক *_imp____argc;
#endif
#endif
#ifndef __argv
#ifdef _MSVCRT_
  বাহ্য বর্ণ **__argv;
#অন্যথা
#define __argv  (*_imp____argv)
  বাহ্য বর্ণ ***_imp____argv;
#endif
#endif
#ifndef __wargv
#ifdef _MSVCRT_
  বাহ্য wchar_t **__wargv;
#অন্যথা
#define __wargv (*_imp____wargv)
  বাহ্য wchar_t ***_imp____wargv;
#endif
#endif

#ifdef _POSIX_
  বাহ্য বর্ণ **environ;
#অন্যথা
#ifndef _environ
#ifdef _MSVCRT_
  বাহ্য বর্ণ **_environ;
#অন্যথা
#define _environ (*_imp___environ)
  বাহ্য বর্ণ ***_imp___environ;
#endif
#endif

#ifndef _wenviron
#ifdef _MSVCRT_
  বাহ্য wchar_t **_wenviron;
#অন্যথা
#define _wenviron       (*_imp___wenviron)
  বাহ্য wchar_t ***_imp___wenviron;
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
বাহ্য পূর্ণাঙ্ক __argc;
বাহ্য বর্ণ **__argv;
বাহ্য wchar_t **__wargv;
বাহ্য বর্ণ **_environ;
বাহ্য wchar_t **_wenviron;
#endif

#ifndef _pgmptr
#ifdef _MSVCRT_
  বাহ্য বর্ণ *_pgmptr;
#অন্যথা
#define _pgmptr (*_imp___pgmptr)
  বাহ্য বর্ণ **_imp___pgmptr;
#endif
#endif

#ifndef _wpgmptr
#ifdef _MSVCRT_
  বাহ্য wchar_t *_wpgmptr;
#অন্যথা
#define _wpgmptr        (*_imp___wpgmptr)
  বাহ্য wchar_t **_imp___wpgmptr;
#endif
#endif
  errno_t __cdecl _get_pgmptr(বর্ণ **মান_2);
  errno_t __cdecl _get_wpgmptr(wchar_t **মান_2);
#ifndef _fmode
#ifdef _MSVCRT_
  বাহ্য পূর্ণাঙ্ক _fmode;
#অন্যথা
#define _fmode  (*_imp___fmode)
  বাহ্য পূর্ণাঙ্ক *_imp___fmode;
#endif
#endif
  _CRTIMP errno_t __cdecl _set_fmode(পূর্ণাঙ্ক _Mode);
  _CRTIMP errno_t __cdecl _get_fmode(পূর্ণাঙ্ক *_PMode);

#ifndef _osplatform
#ifdef _MSVCRT_
  বাহ্য unsigned পূর্ণাঙ্ক _osplatform;
#অন্যথা
#define _osplatform (*_imp___osplatform)
  বাহ্য unsigned পূর্ণাঙ্ক *_imp___osplatform;
#endif
#endif

#ifndef _osver
#ifdef _MSVCRT_
  বাহ্য unsigned পূর্ণাঙ্ক _osver;
#অন্যথা
#define _osver  (*_imp___osver)
  বাহ্য unsigned পূর্ণাঙ্ক *_imp___osver;
#endif
#endif

#ifndef _winver
#ifdef _MSVCRT_
  বাহ্য unsigned পূর্ণাঙ্ক _winver;
#অন্যথা
#define _winver (*_imp___winver)
  বাহ্য unsigned পূর্ণাঙ্ক *_imp___winver;
#endif
#endif

#ifndef _winmajor
#ifdef _MSVCRT_
  বাহ্য unsigned পূর্ণাঙ্ক _winmajor;
#অন্যথা
#define _winmajor       (*_imp___winmajor)
  বাহ্য unsigned পূর্ণাঙ্ক *_imp___winmajor;
#endif
#endif

#ifndef _winminor
#ifdef _MSVCRT_
  বাহ্য unsigned পূর্ণাঙ্ক _winminor;
#অন্যথা
#define _winminor       (*_imp___winminor)
  বাহ্য unsigned পূর্ণাঙ্ক *_imp___winminor;
#endif
#endif

  errno_t __cdecl _get_osplatform(unsigned পূর্ণাঙ্ক *মান_2);
  errno_t __cdecl _get_osver(unsigned পূর্ণাঙ্ক *মান_2);
  errno_t __cdecl _get_winver(unsigned পূর্ণাঙ্ক *মান_2);
  errno_t __cdecl _get_winmajor(unsigned পূর্ণাঙ্ক *মান_2);
  errno_t __cdecl _get_winminor(unsigned পূর্ণাঙ্ক *মান_2);
#ifndef _countof
#ifndef __cplusplus
#define _countof(_Array) (পরিমাণ(_Array) / পরিমাণ(_Array[0]))
#অন্যথা
  বাহ্য "C++" {
    template <typename _CountofType,size_t _SizeOfArray> বর্ণ (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];
#define _countof(_Array) পরিমাণ(*__countof_helper(_Array))
  }
#endif
#endif

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  শূন্য __cdecl __MINGW_NOTHROW exit(পূর্ণাঙ্ক _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP শূন্য __cdecl __MINGW_NOTHROW _exit(পূর্ণাঙ্ক _Code) __MINGW_ATTRIB_NORETURN;
#যদি !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  শূন্য __cdecl _Exit(পূর্ণাঙ্ক) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN শূন্য  __cdecl _Exit(পূর্ণাঙ্ক status)
  {  _exit(status); }
#endif

#pragma ঠেলো_macro("abort")
#undef abort
  শূন্য __cdecl __declspec(noreturn) abort(শূন্য);
#pragma বের_করো_macro("abort")

#endif

  _CRTIMP unsigned পূর্ণাঙ্ক __cdecl _set_abort_behavior(unsigned পূর্ণাঙ্ক _Flags,unsigned পূর্ণাঙ্ক _Mask);

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  পূর্ণাঙ্ক __cdecl abs(পূর্ণাঙ্ক _X);
  long __cdecl labs(long _X);
#endif

#যদি _INTEGRAL_MAX_BITS >= 64
  __int64 __cdecl _abs64(__int64);
#endif
  পূর্ণাঙ্ক __cdecl atexit(শূন্য (__cdecl *)(শূন্য));
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  দ্বিগুণ __cdecl atof(ধ্রুব বর্ণ *_String);
  দ্বিগুণ __cdecl _atof_l(ধ্রুব বর্ণ *_String,_locale_t _Locale);
#endif
  পূর্ণাঙ্ক __cdecl atoi(ধ্রুব বর্ণ *_Str);
  _CRTIMP পূর্ণাঙ্ক __cdecl _atoi_l(ধ্রুব বর্ণ *_Str,_locale_t _Locale);
  long __cdecl atol(ধ্রুব বর্ণ *_Str);
  _CRTIMP long __cdecl _atol_l(ধ্রুব বর্ণ *_Str,_locale_t _Locale);
#ifndef _CRT_ALGO_DEFINED
#define _CRT_ALGO_DEFINED
  শূন্য *__cdecl bsearch(ধ্রুব শূন্য *চাবি_2,ধ্রুব শূন্য *_Base,size_t অঙ্ক_Of_Elements,size_t _SizeOfElements,পূর্ণাঙ্ক (__cdecl *_PtFuncCompare)(ধ্রুব শূন্য *,ধ্রুব শূন্য *));
  শূন্য __cdecl qsort(শূন্য *_Base,size_t অঙ্ক_Of_Elements,size_t _SizeOfElements,পূর্ণাঙ্ক (__cdecl *_PtFuncCompare)(ধ্রুব শূন্য *,ধ্রুব শূন্য *));
#endif
  unsigned short __cdecl _byteswap_ushort(unsigned short _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#যদি _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Int64);
#endif
  div_t __cdecl div(পূর্ণাঙ্ক _Numerator,পূর্ণাঙ্ক _Denominator);
  বর্ণ *__cdecl getenv(ধ্রুব বর্ণ *_VarName);
  _CRTIMP বর্ণ *__cdecl _itoa(পূর্ণাঙ্ক মান_2,বর্ণ *_Dest,পূর্ণাঙ্ক _Radix);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP বর্ণ *__cdecl _i64toa(__int64 _Val,বর্ণ *_DstBuf,পূর্ণাঙ্ক _Radix);
  _CRTIMP বর্ণ *__cdecl _ui64toa(unsigned __int64 _Val,বর্ণ *_DstBuf,পূর্ণাঙ্ক _Radix);
  _CRTIMP __int64 __cdecl _atoi64(ধ্রুব বর্ণ *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(ধ্রুব বর্ণ *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(ধ্রুব বর্ণ *_String,বর্ণ **_EndPtr,পূর্ণাঙ্ক _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(ধ্রুব বর্ণ *_String,বর্ণ **_EndPtr,পূর্ণাঙ্ক _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _strtoui64(ধ্রুব বর্ণ *_String,বর্ণ **_EndPtr,পূর্ণাঙ্ক _Radix);
  _CRTIMP unsigned __int64 __cdecl _strtoui64_l(ধ্রুব বর্ণ *_String,বর্ণ **_EndPtr,পূর্ণাঙ্ক _Radix,_locale_t _Locale);
#endif
  ldiv_t __cdecl ldiv(long _Numerator,long _Denominator);
  _CRTIMP বর্ণ *__cdecl _ltoa(long মান_2,বর্ণ *_Dest,পূর্ণাঙ্ক _Radix);
  পূর্ণাঙ্ক __cdecl mblen(ধ্রুব বর্ণ *_Ch,size_t Max_গুনতি);
  _CRTIMP পূর্ণাঙ্ক __cdecl _mblen_l(ধ্রুব বর্ণ *_Ch,size_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrlen(ধ্রুব বর্ণ *_Str);
  _CRTIMP size_t __cdecl _mbstrlen_l(ধ্রুব বর্ণ *_Str,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrnlen(ধ্রুব বর্ণ *_Str,size_t Max_গুনতি);
  _CRTIMP size_t __cdecl _mbstrnlen_l(ধ্রুব বর্ণ *_Str,size_t Max_গুনতি,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl mbtowc(wchar_t *_DstCh,ধ্রুব বর্ণ *_SrcCh,size_t _SrcSizeInBytes);
  _CRTIMP পূর্ণাঙ্ক __cdecl _mbtowc_l(wchar_t *_DstCh,ধ্রুব বর্ণ *_SrcCh,size_t _SrcSizeInBytes,_locale_t _Locale);
  size_t __cdecl mbstowcs(wchar_t *_Dest,ধ্রুব বর্ণ *_Source,size_t Max_গুনতি);
  _CRTIMP size_t __cdecl _mbstowcs_l(wchar_t *_Dest,ধ্রুব বর্ণ *_Source,size_t Max_গুনতি,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl rand(শূন্য);
  _CRTIMP পূর্ণাঙ্ক __cdecl _set_error_mode(পূর্ণাঙ্ক _Mode);
  শূন্য __cdecl srand(unsigned পূর্ণাঙ্ক _Seed);
  দ্বিগুণ __cdecl strtod(ধ্রুব বর্ণ *_Str,বর্ণ **_EndPtr);
#যদি !defined __NO_ISOCEXT  /* in libmingwex.a */
#যদি __TINYC__
  __CRT_INLINE ভিন্ন __cdecl strtof (ধ্রুব বর্ণ *p, বর্ণ ** e) { প্রত্যাগম strtod(p, e); }
  __CRT_INLINE long দ্বিগুণ __cdecl strtold(ধ্রুব বর্ণ *p, বর্ণ ** e) { প্রত্যাগম strtod(p, e); }
#অন্যথা
  ভিন্ন __cdecl strtof (ধ্রুব বর্ণ * __restrict__, বর্ণ ** __restrict__);
  long দ্বিগুণ __cdecl strtold(ধ্রুব বর্ণ * __restrict__, বর্ণ ** __restrict__);
#endif
#অন্যথা
  ভিন্ন __cdecl strtof(ধ্রুব বর্ণ *nptr, বর্ণ **endptr);
#endif /* __NO_ISOCEXT */
  _CRTIMP দ্বিগুণ __cdecl _strtod_l(ধ্রুব বর্ণ *_Str,বর্ণ **_EndPtr,_locale_t _Locale);
  long __cdecl strtol(ধ্রুব বর্ণ *_Str,বর্ণ **_EndPtr,পূর্ণাঙ্ক _Radix);
  _CRTIMP long __cdecl _strtol_l(ধ্রুব বর্ণ *_Str,বর্ণ **_EndPtr,পূর্ণাঙ্ক _Radix,_locale_t _Locale);
  unsigned long __cdecl strtoul(ধ্রুব বর্ণ *_Str,বর্ণ **_EndPtr,পূর্ণাঙ্ক _Radix);
  _CRTIMP unsigned long __cdecl _strtoul_l(ধ্রুব বর্ণ *_Str,বর্ণ **_EndPtr,পূর্ণাঙ্ক _Radix,_locale_t _Locale);
#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  পূর্ণাঙ্ক __cdecl system(ধ্রুব বর্ণ *_Command);
#endif
  _CRTIMP বর্ণ *__cdecl _ultoa(unsigned long মান_2,বর্ণ *_Dest,পূর্ণাঙ্ক _Radix);
  পূর্ণাঙ্ক __cdecl wctomb(বর্ণ *_MbCh,wchar_t _WCh);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wctomb_l(বর্ণ *_MbCh,wchar_t _WCh,_locale_t _Locale);
  size_t __cdecl wcstombs(বর্ণ *_Dest,ধ্রুব wchar_t *_Source,size_t Max_গুনতি);
  _CRTIMP size_t __cdecl _wcstombs_l(বর্ণ *_Dest,ধ্রুব wchar_t *_Source,size_t Max_গুনতি,_locale_t _Locale);

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  শূন্য *__cdecl calloc(size_t অঙ্ক_Of_Elements,size_t _SizeOfElements);
  শূন্য __cdecl মুক্ত(শূন্য *_Memory);
  শূন্য *__cdecl malloc(size_t _Size);
  শূন্য *__cdecl realloc(শূন্য *_Memory,size_t _NewSize);
  _CRTIMP শূন্য *__cdecl _recalloc(শূন্য *_Memory,size_t গুনতি_5,size_t _Size);
  _CRTIMP শূন্য __cdecl _aligned_free(শূন্য *_Memory);
  _CRTIMP শূন্য *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP শূন্য *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP শূন্য *__cdecl _aligned_realloc(শূন্য *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP শূন্য *__cdecl _aligned_recalloc(শূন্য *_Memory,size_t গুনতি_5,size_t _Size,size_t _Alignment);
  _CRTIMP শূন্য *__cdecl _aligned_offset_realloc(শূন্য *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP শূন্য *__cdecl _aligned_offset_recalloc(শূন্য *_Memory,size_t গুনতি_5,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(পূর্ণাঙ্ক মান_2,wchar_t *_Dest,পূর্ণাঙ্ক _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long মান_2,wchar_t *_Dest,পূর্ণাঙ্ক _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long মান_2,wchar_t *_Dest,পূর্ণাঙ্ক _Radix);
  দ্বিগুণ __cdecl wcstod(ধ্রুব wchar_t *_Str,wchar_t **_EndPtr);
  ভিন্ন __cdecl wcstof(ধ্রুব wchar_t *nptr, wchar_t **endptr);
#যদি !defined __NO_ISOCEXT /* in libmingwex.a */
  ভিন্ন __cdecl wcstof( ধ্রুব wchar_t * __restrict__, wchar_t ** __restrict__);
  long দ্বিগুণ __cdecl wcstold(ধ্রুব wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  _CRTIMP দ্বিগুণ __cdecl _wcstod_l(ধ্রুব wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  long __cdecl wcstol(ধ্রুব wchar_t *_Str,wchar_t **_EndPtr,পূর্ণাঙ্ক _Radix);
  _CRTIMP long __cdecl _wcstol_l(ধ্রুব wchar_t *_Str,wchar_t **_EndPtr,পূর্ণাঙ্ক _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(ধ্রুব wchar_t *_Str,wchar_t **_EndPtr,পূর্ণাঙ্ক _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(ধ্রুব wchar_t *_Str,wchar_t **_EndPtr,পূর্ণাঙ্ক _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ধ্রুব wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP পূর্ণাঙ্ক __cdecl _wsystem(ধ্রুব wchar_t *_Command);
#endif
  _CRTIMP দ্বিগুণ __cdecl _wtof(ধ্রুব wchar_t *_Str);
  _CRTIMP দ্বিগুণ __cdecl _wtof_l(ধ্রুব wchar_t *_Str,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wtoi(ধ্রুব wchar_t *_Str);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wtoi_l(ধ্রুব wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(ধ্রুব wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(ধ্রুব wchar_t *_Str,_locale_t _Locale);

#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,পূর্ণাঙ্ক _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,পূর্ণাঙ্ক _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ধ্রুব wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ধ্রুব wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ধ্রুব wchar_t *_Str,wchar_t **_EndPtr,পূর্ণাঙ্ক _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ধ্রুব wchar_t *_Str,wchar_t **_EndPtr,পূর্ণাঙ্ক _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(ধ্রুব wchar_t *_Str,wchar_t **_EndPtr,পূর্ণাঙ্ক _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(ধ্রুব wchar_t *_Str ,wchar_t **_EndPtr,পূর্ণাঙ্ক _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#define _CVTBUFSIZE (309+40)
  _CRTIMP বর্ণ *__cdecl _fullpath(বর্ণ *_FullPath,ধ্রুব বর্ণ *_Path,size_t _SizeInBytes);
  _CRTIMP বর্ণ *__cdecl _ecvt(দ্বিগুণ _Val,পূর্ণাঙ্ক অঙ্ক_Of_Digits,পূর্ণাঙ্ক *_PtDec,পূর্ণাঙ্ক *_PtSign);
  _CRTIMP বর্ণ *__cdecl _fcvt(দ্বিগুণ _Val,পূর্ণাঙ্ক অঙ্ক_Of_Dec,পূর্ণাঙ্ক *_PtDec,পূর্ণাঙ্ক *_PtSign);
  _CRTIMP বর্ণ *__cdecl _gcvt(দ্বিগুণ _Val,পূর্ণাঙ্ক অঙ্ক_Of_Digits,বর্ণ *_DstBuf);
  _CRTIMP পূর্ণাঙ্ক __cdecl _atodbl(_CRT_DOUBLE *_Result,বর্ণ *_Str);
  _CRTIMP পূর্ণাঙ্ক __cdecl _atoldbl(_LDOUBLE *_Result,বর্ণ *_Str);
  _CRTIMP পূর্ণাঙ্ক __cdecl _atoflt(_CRT_FLOAT *_Result,বর্ণ *_Str);
  _CRTIMP পূর্ণাঙ্ক __cdecl _atodbl_l(_CRT_DOUBLE *_Result,বর্ণ *_Str,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl _atoldbl_l(_LDOUBLE *_Result,বর্ণ *_Str,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl _atoflt_l(_CRT_FLOAT *_Result,বর্ণ *_Str,_locale_t _Locale);
  unsigned long __cdecl _lrotl(unsigned long _Val,পূর্ণাঙ্ক _Shift);
  unsigned long __cdecl _lrotr(unsigned long _Val,পূর্ণাঙ্ক _Shift);
  _CRTIMP শূন্য __cdecl _makepath(বর্ণ *_Path,ধ্রুব বর্ণ *_Drive,ধ্রুব বর্ণ *_Dir,ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  শূন্য __cdecl perror(ধ্রুব বর্ণ *Err_বার্তা);
#endif
  _CRTIMP পূর্ণাঙ্ক __cdecl _putenv(ধ্রুব বর্ণ *_EnvString);
  unsigned পূর্ণাঙ্ক __cdecl _rotl(unsigned পূর্ণাঙ্ক _Val,পূর্ণাঙ্ক _Shift);
#যদি _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotl64(unsigned __int64 _Val,পূর্ণাঙ্ক _Shift);
#endif
  unsigned পূর্ণাঙ্ক __cdecl _rotr(unsigned পূর্ণাঙ্ক _Val,পূর্ণাঙ্ক _Shift);
#যদি _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotr64(unsigned __int64 _Val,পূর্ণাঙ্ক _Shift);
#endif
  _CRTIMP শূন্য __cdecl _searchenv(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_EnvVar,বর্ণ *_ResultPath);
  _CRTIMP শূন্য __cdecl _splitpath(ধ্রুব বর্ণ *_FullPath,বর্ণ *_Drive,বর্ণ *_Dir,বর্ণ *_Filename,বর্ণ *_Ext);
  _CRTIMP শূন্য __cdecl _swab(বর্ণ *_Buf1,বর্ণ *_Buf2,পূর্ণাঙ্ক _SizeInBytes);

#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,ধ্রুব wchar_t *_Path,size_t Size_In_শব্দগুলি);
  _CRTIMP শূন্য __cdecl _wmakepath(wchar_t *_ResultPath,ধ্রুব wchar_t *_Drive,ধ্রুব wchar_t *_Dir,ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP শূন্য __cdecl _wperror(ধ্রুব wchar_t *Err_বার্তা);
#endif
  _CRTIMP পূর্ণাঙ্ক __cdecl _wputenv(ধ্রুব wchar_t *_EnvString);
  _CRTIMP শূন্য __cdecl _wsearchenv(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP শূন্য __cdecl _wsplitpath(ধ্রুব wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif

  _CRTIMP শূন্য __cdecl _beep(unsigned _Frequency,unsigned _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP শূন্য __cdecl _seterrormode(পূর্ণাঙ্ক _Mode) __MINGW_ATTRIB_DEPRECATED;
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
  বর্ণ *__cdecl ecvt(দ্বিগুণ _Val,পূর্ণাঙ্ক অঙ্ক_Of_Digits,পূর্ণাঙ্ক *_PtDec,পূর্ণাঙ্ক *_PtSign);
  বর্ণ *__cdecl fcvt(দ্বিগুণ _Val,পূর্ণাঙ্ক অঙ্ক_Of_Dec,পূর্ণাঙ্ক *_PtDec,পূর্ণাঙ্ক *_PtSign);
  বর্ণ *__cdecl gcvt(দ্বিগুণ _Val,পূর্ণাঙ্ক অঙ্ক_Of_Digits,বর্ণ *_DstBuf);
  বর্ণ *__cdecl itoa(পূর্ণাঙ্ক _Val,বর্ণ *_DstBuf,পূর্ণাঙ্ক _Radix);
  বর্ণ *__cdecl ltoa(long _Val,বর্ণ *_DstBuf,পূর্ণাঙ্ক _Radix);
  পূর্ণাঙ্ক __cdecl putenv(ধ্রুব বর্ণ *_EnvString);
  শূন্য __cdecl swab(বর্ণ *_Buf1,বর্ণ *_Buf2,পূর্ণাঙ্ক _SizeInBytes);
  বর্ণ *__cdecl ultoa(unsigned long _Val,বর্ণ *_Dstbuf,পূর্ণাঙ্ক _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#endif
#endif

#যদি !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  প্রকারনির্দেশ সংরচনা { long long quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(long long, long long);

  __CRT_INLINE long long __cdecl llabs(long long _j) { প্রত্যাগম (_j >= 0 ? _j : -_j); }

 #ifdef __TINYC__ /* gr */
  #define strtoll _strtoi64
  #define strtoull _strtoui64
 #অন্যথা
  long long  __cdecl strtoll(ধ্রুব বর্ণ* __restrict__, বর্ণ** __restrict, পূর্ণাঙ্ক);
  unsigned long long  __cdecl strtoull(ধ্রুব বর্ণ* __restrict__, বর্ণ** __restrict__, পূর্ণাঙ্ক);
 #endif

  /* these are stubs for MS _i64 versions */
  long long  __cdecl atoll (ধ্রুব বর্ণ *);

#ifndef __STRICT_ANSI__
  long long  __cdecl wtoll (ধ্রুব wchar_t *);
  বর্ণ *__cdecl lltoa (long long, বর্ণ *, পূর্ণাঙ্ক);
  বর্ণ *__cdecl ulltoa (unsigned long long , বর্ণ *, পূর্ণাঙ্ক);
  wchar_t *__cdecl lltow (long long, wchar_t *, পূর্ণাঙ্ক);
  wchar_t *__cdecl ulltow (unsigned long long, wchar_t *, পূর্ণাঙ্ক);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE long long  __cdecl atoll (ধ্রুব বর্ণ * _c) { প্রত্যাগম _atoi64 (_c); }
  __CRT_INLINE বর্ণ *__cdecl lltoa (long long _n, বর্ণ * _c, পূর্ণাঙ্ক _i) { প্রত্যাগম _i64toa (_n, _c, _i); }
  __CRT_INLINE বর্ণ *__cdecl ulltoa (unsigned long long _n, বর্ণ * _c, পূর্ণাঙ্ক _i) { প্রত্যাগম _ui64toa (_n, _c, _i); }
  __CRT_INLINE long long  __cdecl wtoll (ধ্রুব wchar_t * _w) { প্রত্যাগম _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (long long _n, wchar_t * _w, পূর্ণাঙ্ক _i) { প্রত্যাগম _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (unsigned long long _n, wchar_t * _w, পূর্ণাঙ্ক _i) { প্রত্যাগম _ui64tow (_n, _w, _i); }
#endif /* (__STRICT_ANSI__)  */

#endif /* !__NO_ISOCEXT */

#ifdef __cplusplus
}
#endif

#pragma pack(বের_করো)

#অন্তর্ভাব <sec_api/stdlib_s.h>
#অন্তর্ভাব <malloc.h>

#endif
