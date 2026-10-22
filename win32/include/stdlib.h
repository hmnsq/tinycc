/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB
#define _INC_STDLIB

#ଅନ୍ତର୍ଭାଵ <_mingw.h>
#ଅନ୍ତର୍ଭାଵ <limits.h>

#pragma pack(ଠେଲ,_CRT_PACKING)

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

#ifndef ଖାଲି
#ifdef __cplusplus
#define ଖାଲି 0
#ଅନ୍ୟଥା
#define ଖାଲି ((ଶୂନ୍ୟ *)0)
#endif
#endif

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#ifndef _ONEXIT_T_DEFINED
#define _ONEXIT_T_DEFINED

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା (__cdecl *_onexit_t)(ଶୂନ୍ୟ);

#ifndef NO_OLDNAMES
#define onexit_t _onexit_t
#endif
#endif

#ifndef _DIV_T_DEFINED
#define _DIV_T_DEFINED

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _div_t {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା quot;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା rem;
  } div_t;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _ldiv_t {
    long quot;
    long rem;
  } ldiv_t;
#endif

#ifndef _CRT_DOUBLE_DEC
#define _CRT_DOUBLE_DEC

#pragma pack(4)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
    unsigned ଅକ୍ଷର ld[10];
  } _LDOUBLE;
#pragma pack()

#define _PTR_LD(x) ((unsigned ଅକ୍ଷର *)(&(x)->ld))

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
    ଦ୍ୱିଗୁଣ x;
  } _CRT_DOUBLE;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
    ଦଶମିକ f;
  } _CRT_FLOAT;

#pragma ଠେଲ_macro("long")
#undef long

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
    long ଦ୍ୱିଗୁଣ x;
  } _LONGDOUBLE;

#pragma କାଢ଼_macro("long")

#pragma pack(4)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
    unsigned ଅକ୍ଷର ld12[12];
  } _LDBL12;
#pragma pack()
#endif

#define RAND_MAX 0x7fff

#ifndef MB_CUR_MAX
#define MB_CUR_MAX ___mb_cur_max_func()
#ifndef __mb_cur_max
#ifdef _MSVCRT_
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __mb_cur_max;
#ଅନ୍ୟଥା
#define __mb_cur_max    (*_imp____mb_cur_max)
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_imp____mb_cur_max;
#endif
#endif
#ifdef _MSVCRT_
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __mbcur_max;
#define ___mb_cur_max_func() (__mb_cur_max)
#ଅନ୍ୟଥା
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା* _imp____mbcur_max;
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

#define WRITE_ABORT_ସନ୍ଦେଶ 0x1
#define _CALL_REPORTFAULT 0x2

#define _MAX_ENV 32767

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ଶୂନ୍ୟ (__cdecl *_purecall_handler)(ଶୂନ୍ୟ);

  _CRTIMP _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(ଶୂନ୍ୟ);

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ଶୂନ୍ୟ (__cdecl *_invalid_parameter_handler)(ଅଚଳ wchar_t *,ଅଚଳ wchar_t *,ଅଚଳ wchar_t *,unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା,uintptr_t);
  _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(ଶୂନ୍ୟ);

#ifndef _CRT_ERRNO_DEFINED
#define _CRT_ERRNO_DEFINED
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା *__cdecl _errno(ଶୂନ୍ୟ);
#define errno (*_errno())
  errno_t __cdecl _set_errno(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ_2);
  errno_t __cdecl _get_errno(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ମୂଲ୍ୟ_2);
#endif
  _CRTIMP unsigned long *__cdecl __doserrno(ଶୂନ୍ୟ);
#define _doserrno (*__doserrno())
  errno_t __cdecl _set_doserrno(unsigned long ମୂଲ୍ୟ_2);
  errno_t __cdecl _get_doserrno(unsigned long *ମୂଲ୍ୟ_2);
#ifdef _MSVCRT_
  ବାହ୍ୟ ଅକ୍ଷର *_sys_errlist[];
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା _sys_nerr;
#ଅନ୍ୟଥା
  _CRTIMP ଅକ୍ଷର *_sys_errlist[1];
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା _sys_nerr;
#endif
#ଯଦି (defined(_X86_) && !defined(__x86_64))
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା *__cdecl __p___argc(ଶୂନ୍ୟ);
  _CRTIMP ଅକ୍ଷର ***__cdecl __p___argv(ଶୂନ୍ୟ);
  _CRTIMP wchar_t ***__cdecl __p___wargv(ଶୂନ୍ୟ);
  _CRTIMP ଅକ୍ଷର ***__cdecl __p__environ(ଶୂନ୍ୟ);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(ଶୂନ୍ୟ);
  _CRTIMP ଅକ୍ଷର **__cdecl __p__pgmptr(ଶୂନ୍ୟ);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(ଶୂନ୍ୟ);
#endif
#ifndef __argc
#ifdef _MSVCRT_
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __argc;
#ଅନ୍ୟଥା
#define __argc (*_imp____argc)
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_imp____argc;
#endif
#endif
#ifndef __argv
#ifdef _MSVCRT_
  ବାହ୍ୟ ଅକ୍ଷର **__argv;
#ଅନ୍ୟଥା
#define __argv  (*_imp____argv)
  ବାହ୍ୟ ଅକ୍ଷର ***_imp____argv;
#endif
#endif
#ifndef __wargv
#ifdef _MSVCRT_
  ବାହ୍ୟ wchar_t **__wargv;
#ଅନ୍ୟଥା
#define __wargv (*_imp____wargv)
  ବାହ୍ୟ wchar_t ***_imp____wargv;
#endif
#endif

#ifdef _POSIX_
  ବାହ୍ୟ ଅକ୍ଷର **environ;
#ଅନ୍ୟଥା
#ifndef _environ
#ifdef _MSVCRT_
  ବାହ୍ୟ ଅକ୍ଷର **_environ;
#ଅନ୍ୟଥା
#define _environ (*_imp___environ)
  ବାହ୍ୟ ଅକ୍ଷର ***_imp___environ;
#endif
#endif

#ifndef _wenviron
#ifdef _MSVCRT_
  ବାହ୍ୟ wchar_t **_wenviron;
#ଅନ୍ୟଥା
#define _wenviron       (*_imp___wenviron)
  ବାହ୍ୟ wchar_t ***_imp___wenviron;
#endif
#endif
#endif

#ଯଦି defined __aarch64__
/* something does not work using those from msvcrt.dll */
# undef __argc
# undef __argv
# undef __wargv
# undef _wenviron
# undef _environ
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __argc;
ବାହ୍ୟ ଅକ୍ଷର **__argv;
ବାହ୍ୟ wchar_t **__wargv;
ବାହ୍ୟ ଅକ୍ଷର **_environ;
ବାହ୍ୟ wchar_t **_wenviron;
#endif

#ifndef _pgmptr
#ifdef _MSVCRT_
  ବାହ୍ୟ ଅକ୍ଷର *_pgmptr;
#ଅନ୍ୟଥା
#define _pgmptr (*_imp___pgmptr)
  ବାହ୍ୟ ଅକ୍ଷର **_imp___pgmptr;
#endif
#endif

#ifndef _wpgmptr
#ifdef _MSVCRT_
  ବାହ୍ୟ wchar_t *_wpgmptr;
#ଅନ୍ୟଥା
#define _wpgmptr        (*_imp___wpgmptr)
  ବାହ୍ୟ wchar_t **_imp___wpgmptr;
#endif
#endif
  errno_t __cdecl _get_pgmptr(ଅକ୍ଷର **ମୂଲ୍ୟ_2);
  errno_t __cdecl _get_wpgmptr(wchar_t **ମୂଲ୍ୟ_2);
#ifndef _fmode
#ifdef _MSVCRT_
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା _fmode;
#ଅନ୍ୟଥା
#define _fmode  (*_imp___fmode)
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_imp___fmode;
#endif
#endif
  _CRTIMP errno_t __cdecl _set_fmode(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode);
  _CRTIMP errno_t __cdecl _get_fmode(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_PMode);

#ifndef _osplatform
#ifdef _MSVCRT_
  ବାହ୍ୟ unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _osplatform;
#ଅନ୍ୟଥା
#define _osplatform (*_imp___osplatform)
  ବାହ୍ୟ unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_imp___osplatform;
#endif
#endif

#ifndef _osver
#ifdef _MSVCRT_
  ବାହ୍ୟ unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _osver;
#ଅନ୍ୟଥା
#define _osver  (*_imp___osver)
  ବାହ୍ୟ unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_imp___osver;
#endif
#endif

#ifndef _winver
#ifdef _MSVCRT_
  ବାହ୍ୟ unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _winver;
#ଅନ୍ୟଥା
#define _winver (*_imp___winver)
  ବାହ୍ୟ unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_imp___winver;
#endif
#endif

#ifndef _winmajor
#ifdef _MSVCRT_
  ବାହ୍ୟ unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _winmajor;
#ଅନ୍ୟଥା
#define _winmajor       (*_imp___winmajor)
  ବାହ୍ୟ unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_imp___winmajor;
#endif
#endif

#ifndef _winminor
#ifdef _MSVCRT_
  ବାହ୍ୟ unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _winminor;
#ଅନ୍ୟଥା
#define _winminor       (*_imp___winminor)
  ବାହ୍ୟ unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_imp___winminor;
#endif
#endif

  errno_t __cdecl _get_osplatform(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ମୂଲ୍ୟ_2);
  errno_t __cdecl _get_osver(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ମୂଲ୍ୟ_2);
  errno_t __cdecl _get_winver(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ମୂଲ୍ୟ_2);
  errno_t __cdecl _get_winmajor(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ମୂଲ୍ୟ_2);
  errno_t __cdecl _get_winminor(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ମୂଲ୍ୟ_2);
#ifndef _countof
#ifndef __cplusplus
#define _countof(_Array) (ଆକାର(_Array) / ଆକାର(_Array[0]))
#ଅନ୍ୟଥା
  ବାହ୍ୟ "C++" {
    template <typename _CountofType,size_t _SizeOfArray> ଅକ୍ଷର (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];
#define _countof(_Array) ଆକାର(*__countof_helper(_Array))
  }
#endif
#endif

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  ଶୂନ୍ୟ __cdecl __MINGW_NOTHROW exit(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP ଶୂନ୍ୟ __cdecl __MINGW_NOTHROW _exit(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Code) __MINGW_ATTRIB_NORETURN;
#ଯଦି !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  ଶୂନ୍ୟ __cdecl _Exit(ପୂର୍ଣ୍ଣସଂଖ୍ୟା) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN ଶୂନ୍ୟ  __cdecl _Exit(ପୂର୍ଣ୍ଣସଂଖ୍ୟା status)
  {  _exit(status); }
#endif

#pragma ଠେଲ_macro("abort")
#undef abort
  ଶୂନ୍ୟ __cdecl __declspec(noreturn) abort(ଶୂନ୍ୟ);
#pragma କାଢ଼_macro("abort")

#endif

  _CRTIMP unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _set_abort_behavior(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Flags,unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mask);

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl abs(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _X);
  long __cdecl labs(long _X);
#endif

#ଯଦି _INTEGRAL_MAX_BITS >= 64
  __int64 __cdecl _abs64(__int64);
#endif
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl atexit(ଶୂନ୍ୟ (__cdecl *)(ଶୂନ୍ୟ));
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  ଦ୍ୱିଗୁଣ __cdecl atof(ଅଚଳ ଅକ୍ଷର *_String);
  ଦ୍ୱିଗୁଣ __cdecl _atof_l(ଅଚଳ ଅକ୍ଷର *_String,_locale_t _Locale);
#endif
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl atoi(ଅଚଳ ଅକ୍ଷର *_Str);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _atoi_l(ଅଚଳ ଅକ୍ଷର *_Str,_locale_t _Locale);
  long __cdecl atol(ଅଚଳ ଅକ୍ଷର *_Str);
  _CRTIMP long __cdecl _atol_l(ଅଚଳ ଅକ୍ଷର *_Str,_locale_t _Locale);
#ifndef _CRT_ALGO_DEFINED
#define _CRT_ALGO_DEFINED
  ଶୂନ୍ୟ *__cdecl bsearch(ଅଚଳ ଶୂନ୍ୟ *ଚାବି_2,ଅଚଳ ଶୂନ୍ୟ *_Base,size_t ଅଙ୍କ_Of_Elements,size_t _SizeOfElements,ପୂର୍ଣ୍ଣସଂଖ୍ୟା (__cdecl *_PtFuncCompare)(ଅଚଳ ଶୂନ୍ୟ *,ଅଚଳ ଶୂନ୍ୟ *));
  ଶୂନ୍ୟ __cdecl qsort(ଶୂନ୍ୟ *_Base,size_t ଅଙ୍କ_Of_Elements,size_t _SizeOfElements,ପୂର୍ଣ୍ଣସଂଖ୍ୟା (__cdecl *_PtFuncCompare)(ଅଚଳ ଶୂନ୍ୟ *,ଅଚଳ ଶୂନ୍ୟ *));
#endif
  unsigned short __cdecl _byteswap_ushort(unsigned short _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#ଯଦି _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Int64);
#endif
  div_t __cdecl div(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Numerator,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Denominator);
  ଅକ୍ଷର *__cdecl getenv(ଅଚଳ ଅକ୍ଷର *_VarName);
  _CRTIMP ଅକ୍ଷର *__cdecl _itoa(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ_2,ଅକ୍ଷର *_Dest,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
#ଯଦି _INTEGRAL_MAX_BITS >= 64
  _CRTIMP ଅକ୍ଷର *__cdecl _i64toa(__int64 _Val,ଅକ୍ଷର *_DstBuf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP ଅକ୍ଷର *__cdecl _ui64toa(unsigned __int64 _Val,ଅକ୍ଷର *_DstBuf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP __int64 __cdecl _atoi64(ଅଚଳ ଅକ୍ଷର *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(ଅଚଳ ଅକ୍ଷର *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(ଅଚଳ ଅକ୍ଷର *_String,ଅକ୍ଷର **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(ଅଚଳ ଅକ୍ଷର *_String,ଅକ୍ଷର **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _strtoui64(ଅଚଳ ଅକ୍ଷର *_String,ଅକ୍ଷର **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP unsigned __int64 __cdecl _strtoui64_l(ଅଚଳ ଅକ୍ଷର *_String,ଅକ୍ଷର **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix,_locale_t _Locale);
#endif
  ldiv_t __cdecl ldiv(long _Numerator,long _Denominator);
  _CRTIMP ଅକ୍ଷର *__cdecl _ltoa(long ମୂଲ୍ୟ_2,ଅକ୍ଷର *_Dest,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl mblen(ଅଚଳ ଅକ୍ଷର *_Ch,size_t Max_ଗଣନା);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _mblen_l(ଅଚଳ ଅକ୍ଷର *_Ch,size_t Max_ଗଣନା,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrlen(ଅଚଳ ଅକ୍ଷର *_Str);
  _CRTIMP size_t __cdecl _mbstrlen_l(ଅଚଳ ଅକ୍ଷର *_Str,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrnlen(ଅଚଳ ଅକ୍ଷର *_Str,size_t Max_ଗଣନା);
  _CRTIMP size_t __cdecl _mbstrnlen_l(ଅଚଳ ଅକ୍ଷର *_Str,size_t Max_ଗଣନା,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl mbtowc(wchar_t *_DstCh,ଅଚଳ ଅକ୍ଷର *_SrcCh,size_t _SrcSizeInBytes);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _mbtowc_l(wchar_t *_DstCh,ଅଚଳ ଅକ୍ଷର *_SrcCh,size_t _SrcSizeInBytes,_locale_t _Locale);
  size_t __cdecl mbstowcs(wchar_t *_Dest,ଅଚଳ ଅକ୍ଷର *_Source,size_t Max_ଗଣନା);
  _CRTIMP size_t __cdecl _mbstowcs_l(wchar_t *_Dest,ଅଚଳ ଅକ୍ଷର *_Source,size_t Max_ଗଣନା,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl rand(ଶୂନ୍ୟ);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _set_error_mode(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode);
  ଶୂନ୍ୟ __cdecl srand(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Seed);
  ଦ୍ୱିଗୁଣ __cdecl strtod(ଅଚଳ ଅକ୍ଷର *_Str,ଅକ୍ଷର **_EndPtr);
#ଯଦି !defined __NO_ISOCEXT  /* in libmingwex.a */
#ଯଦି __TINYC__
  __CRT_INLINE ଦଶମିକ __cdecl strtof (ଅଚଳ ଅକ୍ଷର *p, ଅକ୍ଷର ** e) { ଫେରନ୍ତୁ strtod(p, e); }
  __CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl strtold(ଅଚଳ ଅକ୍ଷର *p, ଅକ୍ଷର ** e) { ଫେରନ୍ତୁ strtod(p, e); }
#ଅନ୍ୟଥା
  ଦଶମିକ __cdecl strtof (ଅଚଳ ଅକ୍ଷର * __restrict__, ଅକ୍ଷର ** __restrict__);
  long ଦ୍ୱିଗୁଣ __cdecl strtold(ଅଚଳ ଅକ୍ଷର * __restrict__, ଅକ୍ଷର ** __restrict__);
#endif
#ଅନ୍ୟଥା
  ଦଶମିକ __cdecl strtof(ଅଚଳ ଅକ୍ଷର *nptr, ଅକ୍ଷର **endptr);
#endif /* __NO_ISOCEXT */
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl _strtod_l(ଅଚଳ ଅକ୍ଷର *_Str,ଅକ୍ଷର **_EndPtr,_locale_t _Locale);
  long __cdecl strtol(ଅଚଳ ଅକ୍ଷର *_Str,ଅକ୍ଷର **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP long __cdecl _strtol_l(ଅଚଳ ଅକ୍ଷର *_Str,ଅକ୍ଷର **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix,_locale_t _Locale);
  unsigned long __cdecl strtoul(ଅଚଳ ଅକ୍ଷର *_Str,ଅକ୍ଷର **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP unsigned long __cdecl _strtoul_l(ଅଚଳ ଅକ୍ଷର *_Str,ଅକ୍ଷର **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix,_locale_t _Locale);
#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl system(ଅଚଳ ଅକ୍ଷର *_Command);
#endif
  _CRTIMP ଅକ୍ଷର *__cdecl _ultoa(unsigned long ମୂଲ୍ୟ_2,ଅକ୍ଷର *_Dest,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wctomb(ଅକ୍ଷର *_MbCh,wchar_t _WCh);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wctomb_l(ଅକ୍ଷର *_MbCh,wchar_t _WCh,_locale_t _Locale);
  size_t __cdecl wcstombs(ଅକ୍ଷର *_Dest,ଅଚଳ wchar_t *_Source,size_t Max_ଗଣନା);
  _CRTIMP size_t __cdecl _wcstombs_l(ଅକ୍ଷର *_Dest,ଅଚଳ wchar_t *_Source,size_t Max_ଗଣନା,_locale_t _Locale);

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  ଶୂନ୍ୟ *__cdecl calloc(size_t ଅଙ୍କ_Of_Elements,size_t _SizeOfElements);
  ଶୂନ୍ୟ __cdecl ମୁକ୍ତ(ଶୂନ୍ୟ *_Memory);
  ଶୂନ୍ୟ *__cdecl malloc(size_t _Size);
  ଶୂନ୍ୟ *__cdecl realloc(ଶୂନ୍ୟ *_Memory,size_t _NewSize);
  _CRTIMP ଶୂନ୍ୟ *__cdecl _recalloc(ଶୂନ୍ୟ *_Memory,size_t ଗଣନା_6,size_t _Size);
  _CRTIMP ଶୂନ୍ୟ __cdecl _aligned_free(ଶୂନ୍ୟ *_Memory);
  _CRTIMP ଶୂନ୍ୟ *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP ଶୂନ୍ୟ *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP ଶୂନ୍ୟ *__cdecl _aligned_realloc(ଶୂନ୍ୟ *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP ଶୂନ୍ୟ *__cdecl _aligned_recalloc(ଶୂନ୍ୟ *_Memory,size_t ଗଣନା_6,size_t _Size,size_t _Alignment);
  _CRTIMP ଶୂନ୍ୟ *__cdecl _aligned_offset_realloc(ଶୂନ୍ୟ *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP ଶୂନ୍ୟ *__cdecl _aligned_offset_recalloc(ଶୂନ୍ୟ *_Memory,size_t ଗଣନା_6,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ_2,wchar_t *_Dest,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long ମୂଲ୍ୟ_2,wchar_t *_Dest,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long ମୂଲ୍ୟ_2,wchar_t *_Dest,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  ଦ୍ୱିଗୁଣ __cdecl wcstod(ଅଚଳ wchar_t *_Str,wchar_t **_EndPtr);
  ଦଶମିକ __cdecl wcstof(ଅଚଳ wchar_t *nptr, wchar_t **endptr);
#ଯଦି !defined __NO_ISOCEXT /* in libmingwex.a */
  ଦଶମିକ __cdecl wcstof( ଅଚଳ wchar_t * __restrict__, wchar_t ** __restrict__);
  long ଦ୍ୱିଗୁଣ __cdecl wcstold(ଅଚଳ wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl _wcstod_l(ଅଚଳ wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  long __cdecl wcstol(ଅଚଳ wchar_t *_Str,wchar_t **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP long __cdecl _wcstol_l(ଅଚଳ wchar_t *_Str,wchar_t **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(ଅଚଳ wchar_t *_Str,wchar_t **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(ଅଚଳ wchar_t *_Str,wchar_t **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ଅଚଳ wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wsystem(ଅଚଳ wchar_t *_Command);
#endif
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl _wtof(ଅଚଳ wchar_t *_Str);
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl _wtof_l(ଅଚଳ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wtoi(ଅଚଳ wchar_t *_Str);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wtoi_l(ଅଚଳ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(ଅଚଳ wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(ଅଚଳ wchar_t *_Str,_locale_t _Locale);

#ଯଦି _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ଅଚଳ wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ଅଚଳ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ଅଚଳ wchar_t *_Str,wchar_t **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ଅଚଳ wchar_t *_Str,wchar_t **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(ଅଚଳ wchar_t *_Str,wchar_t **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(ଅଚଳ wchar_t *_Str ,wchar_t **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#define _CVTBUFSIZE (309+40)
  _CRTIMP ଅକ୍ଷର *__cdecl _fullpath(ଅକ୍ଷର *_FullPath,ଅଚଳ ଅକ୍ଷର *_Path,size_t _SizeInBytes);
  _CRTIMP ଅକ୍ଷର *__cdecl _ecvt(ଦ୍ୱିଗୁଣ _Val,ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଅଙ୍କ_Of_Digits,ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_PtDec,ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_PtSign);
  _CRTIMP ଅକ୍ଷର *__cdecl _fcvt(ଦ୍ୱିଗୁଣ _Val,ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଅଙ୍କ_Of_Dec,ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_PtDec,ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_PtSign);
  _CRTIMP ଅକ୍ଷର *__cdecl _gcvt(ଦ୍ୱିଗୁଣ _Val,ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଅଙ୍କ_Of_Digits,ଅକ୍ଷର *_DstBuf);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _atodbl(_CRT_DOUBLE *_Result,ଅକ୍ଷର *_Str);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _atoldbl(_LDOUBLE *_Result,ଅକ୍ଷର *_Str);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _atoflt(_CRT_FLOAT *_Result,ଅକ୍ଷର *_Str);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _atodbl_l(_CRT_DOUBLE *_Result,ଅକ୍ଷର *_Str,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _atoldbl_l(_LDOUBLE *_Result,ଅକ୍ଷର *_Str,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _atoflt_l(_CRT_FLOAT *_Result,ଅକ୍ଷର *_Str,_locale_t _Locale);
  unsigned long __cdecl _lrotl(unsigned long _Val,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Shift);
  unsigned long __cdecl _lrotr(unsigned long _Val,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Shift);
  _CRTIMP ଶୂନ୍ୟ __cdecl _makepath(ଅକ୍ଷର *_Path,ଅଚଳ ଅକ୍ଷର *_Drive,ଅଚଳ ଅକ୍ଷର *_Dir,ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  ଶୂନ୍ୟ __cdecl perror(ଅଚଳ ଅକ୍ଷର *Err_ସନ୍ଦେଶ);
#endif
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _putenv(ଅଚଳ ଅକ୍ଷର *_EnvString);
  unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _rotl(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Val,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Shift);
#ଯଦି _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotl64(unsigned __int64 _Val,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Shift);
#endif
  unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _rotr(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Val,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Shift);
#ଯଦି _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotr64(unsigned __int64 _Val,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Shift);
#endif
  _CRTIMP ଶୂନ୍ୟ __cdecl _searchenv(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_EnvVar,ଅକ୍ଷର *_ResultPath);
  _CRTIMP ଶୂନ୍ୟ __cdecl _splitpath(ଅଚଳ ଅକ୍ଷର *_FullPath,ଅକ୍ଷର *_Drive,ଅକ୍ଷର *_Dir,ଅକ୍ଷର *_Filename,ଅକ୍ଷର *_Ext);
  _CRTIMP ଶୂନ୍ୟ __cdecl _swab(ଅକ୍ଷର *_Buf1,ଅକ୍ଷର *_Buf2,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _SizeInBytes);

#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,ଅଚଳ wchar_t *_Path,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ);
  _CRTIMP ଶୂନ୍ୟ __cdecl _wmakepath(wchar_t *_ResultPath,ଅଚଳ wchar_t *_Drive,ଅଚଳ wchar_t *_Dir,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP ଶୂନ୍ୟ __cdecl _wperror(ଅଚଳ wchar_t *Err_ସନ୍ଦେଶ);
#endif
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wputenv(ଅଚଳ wchar_t *_EnvString);
  _CRTIMP ଶୂନ୍ୟ __cdecl _wsearchenv(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP ଶୂନ୍ୟ __cdecl _wsplitpath(ଅଚଳ wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif

  _CRTIMP ଶୂନ୍ୟ __cdecl _beep(unsigned _Frequency,unsigned _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP ଶୂନ୍ୟ __cdecl _seterrormode(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP ଶୂନ୍ୟ __cdecl _sleep(unsigned long _Duration) __MINGW_ATTRIB_DEPRECATED;
#endif

#ifndef NO_OLDNAMES
#ifndef _POSIX_
#ଯଦି 0
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
  ଅକ୍ଷର *__cdecl ecvt(ଦ୍ୱିଗୁଣ _Val,ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଅଙ୍କ_Of_Digits,ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_PtDec,ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_PtSign);
  ଅକ୍ଷର *__cdecl fcvt(ଦ୍ୱିଗୁଣ _Val,ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଅଙ୍କ_Of_Dec,ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_PtDec,ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_PtSign);
  ଅକ୍ଷର *__cdecl gcvt(ଦ୍ୱିଗୁଣ _Val,ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଅଙ୍କ_Of_Digits,ଅକ୍ଷର *_DstBuf);
  ଅକ୍ଷର *__cdecl itoa(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Val,ଅକ୍ଷର *_DstBuf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  ଅକ୍ଷର *__cdecl ltoa(long _Val,ଅକ୍ଷର *_DstBuf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl putenv(ଅଚଳ ଅକ୍ଷର *_EnvString);
  ଶୂନ୍ୟ __cdecl swab(ଅକ୍ଷର *_Buf1,ଅକ୍ଷର *_Buf2,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _SizeInBytes);
  ଅକ୍ଷର *__cdecl ultoa(unsigned long _Val,ଅକ୍ଷର *_Dstbuf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#endif
#endif

#ଯଦି !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { long long quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(long long, long long);

  __CRT_INLINE long long __cdecl llabs(long long _j) { ଫେରନ୍ତୁ (_j >= 0 ? _j : -_j); }

 #ifdef __TINYC__ /* gr */
  #define strtoll _strtoi64
  #define strtoull _strtoui64
 #ଅନ୍ୟଥା
  long long  __cdecl strtoll(ଅଚଳ ଅକ୍ଷର* __restrict__, ଅକ୍ଷର** __restrict, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
  unsigned long long  __cdecl strtoull(ଅଚଳ ଅକ୍ଷର* __restrict__, ଅକ୍ଷର** __restrict__, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
 #endif

  /* these are stubs for MS _i64 versions */
  long long  __cdecl atoll (ଅଚଳ ଅକ୍ଷର *);

#ifndef __STRICT_ANSI__
  long long  __cdecl wtoll (ଅଚଳ wchar_t *);
  ଅକ୍ଷର *__cdecl lltoa (long long, ଅକ୍ଷର *, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
  ଅକ୍ଷର *__cdecl ulltoa (unsigned long long , ଅକ୍ଷର *, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
  wchar_t *__cdecl lltow (long long, wchar_t *, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
  wchar_t *__cdecl ulltow (unsigned long long, wchar_t *, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE long long  __cdecl atoll (ଅଚଳ ଅକ୍ଷର * _c) { ଫେରନ୍ତୁ _atoi64 (_c); }
  __CRT_INLINE ଅକ୍ଷର *__cdecl lltoa (long long _n, ଅକ୍ଷର * _c, ପୂର୍ଣ୍ଣସଂଖ୍ୟା _i) { ଫେରନ୍ତୁ _i64toa (_n, _c, _i); }
  __CRT_INLINE ଅକ୍ଷର *__cdecl ulltoa (unsigned long long _n, ଅକ୍ଷର * _c, ପୂର୍ଣ୍ଣସଂଖ୍ୟା _i) { ଫେରନ୍ତୁ _ui64toa (_n, _c, _i); }
  __CRT_INLINE long long  __cdecl wtoll (ଅଚଳ wchar_t * _w) { ଫେରନ୍ତୁ _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (long long _n, wchar_t * _w, ପୂର୍ଣ୍ଣସଂଖ୍ୟା _i) { ଫେରନ୍ତୁ _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (unsigned long long _n, wchar_t * _w, ପୂର୍ଣ୍ଣସଂଖ୍ୟା _i) { ଫେରନ୍ତୁ _ui64tow (_n, _w, _i); }
#endif /* (__STRICT_ANSI__)  */

#endif /* !__NO_ISOCEXT */

#ifdef __cplusplus
}
#endif

#pragma pack(କାଢ଼)

#ଅନ୍ତର୍ଭାଵ <sec_api/stdlib_s.h>
#ଅନ୍ତର୍ଭାଵ <malloc.h>

#endif
