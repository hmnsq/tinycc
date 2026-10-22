/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB
#define _INC_STDLIB

#ಅನ್ತರ್ಭಾವ <_mingw.h>
#ಅನ್ತರ್ಭಾವ <limits.h>

#pragma pack(ತಳ್ಳು,_CRT_PACKING)

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

#ifndef ರಿಕ್ತ
#ifdef __cplusplus
#define ರಿಕ್ತ 0
#ಅನ್ಯಥಾ
#define ರಿಕ್ತ ((ಶೂನ್ಯ *)0)
#endif
#endif

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#ifndef _ONEXIT_T_DEFINED
#define _ONEXIT_T_DEFINED

  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ (__cdecl *_onexit_t)(ಶೂನ್ಯ);

#ifndef NO_OLDNAMES
#define onexit_t _onexit_t
#endif
#endif

#ifndef _DIV_T_DEFINED
#define _DIV_T_DEFINED

  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _div_t {
    ಪೂರ್ಣಾಙ್ಕ quot;
    ಪೂರ್ಣಾಙ್ಕ rem;
  } div_t;

  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _ldiv_t {
    long quot;
    long rem;
  } ldiv_t;
#endif

#ifndef _CRT_DOUBLE_DEC
#define _CRT_DOUBLE_DEC

#pragma pack(4)
  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
    unsigned ವರ್ಣ ld[10];
  } _LDOUBLE;
#pragma pack()

#define _PTR_LD(x) ((unsigned ವರ್ಣ *)(&(x)->ld))

  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
    ದ್ವಿಗುಣ x;
  } _CRT_DOUBLE;

  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
    ಭಿನ್ನ f;
  } _CRT_FLOAT;

#pragma ತಳ್ಳು_macro("long")
#undef long

  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
    long ದ್ವಿಗುಣ x;
  } _LONGDOUBLE;

#pragma ತೆಗೆ_macro("long")

#pragma pack(4)
  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
    unsigned ವರ್ಣ ld12[12];
  } _LDBL12;
#pragma pack()
#endif

#define RAND_MAX 0x7fff

#ifndef MB_CUR_MAX
#define MB_CUR_MAX ___mb_cur_max_func()
#ifndef __mb_cur_max
#ifdef _MSVCRT_
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __mb_cur_max;
#ಅನ್ಯಥಾ
#define __mb_cur_max    (*_imp____mb_cur_max)
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ *_imp____mb_cur_max;
#endif
#endif
#ifdef _MSVCRT_
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __mbcur_max;
#define ___mb_cur_max_func() (__mb_cur_max)
#ಅನ್ಯಥಾ
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ* _imp____mbcur_max;
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

#define WRITE_ABORT_ಸಂದೇಶ 0x1
#define _CALL_REPORTFAULT 0x2

#define _MAX_ENV 32767

  ಪ್ರಕಾರನಿರ್ದೇಶ ಶೂನ್ಯ (__cdecl *_purecall_handler)(ಶೂನ್ಯ);

  _CRTIMP _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(ಶೂನ್ಯ);

  ಪ್ರಕಾರನಿರ್ದೇಶ ಶೂನ್ಯ (__cdecl *_invalid_parameter_handler)(ಧ್ರುವ wchar_t *,ಧ್ರುವ wchar_t *,ಧ್ರುವ wchar_t *,unsigned ಪೂರ್ಣಾಙ್ಕ,uintptr_t);
  _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(ಶೂನ್ಯ);

#ifndef _CRT_ERRNO_DEFINED
#define _CRT_ERRNO_DEFINED
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ *__cdecl _errno(ಶೂನ್ಯ);
#define errno (*_errno())
  errno_t __cdecl _set_errno(ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ_2);
  errno_t __cdecl _get_errno(ಪೂರ್ಣಾಙ್ಕ *ಮೌಲ್ಯ_2);
#endif
  _CRTIMP unsigned long *__cdecl __doserrno(ಶೂನ್ಯ);
#define _doserrno (*__doserrno())
  errno_t __cdecl _set_doserrno(unsigned long ಮೌಲ್ಯ_2);
  errno_t __cdecl _get_doserrno(unsigned long *ಮೌಲ್ಯ_2);
#ifdef _MSVCRT_
  ಬಾಹ್ಯ ವರ್ಣ *_sys_errlist[];
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ _sys_nerr;
#ಅನ್ಯಥಾ
  _CRTIMP ವರ್ಣ *_sys_errlist[1];
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ _sys_nerr;
#endif
#ಯದಿ (defined(_X86_) && !defined(__x86_64))
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ *__cdecl __p___argc(ಶೂನ್ಯ);
  _CRTIMP ವರ್ಣ ***__cdecl __p___argv(ಶೂನ್ಯ);
  _CRTIMP wchar_t ***__cdecl __p___wargv(ಶೂನ್ಯ);
  _CRTIMP ವರ್ಣ ***__cdecl __p__environ(ಶೂನ್ಯ);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(ಶೂನ್ಯ);
  _CRTIMP ವರ್ಣ **__cdecl __p__pgmptr(ಶೂನ್ಯ);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(ಶೂನ್ಯ);
#endif
#ifndef __argc
#ifdef _MSVCRT_
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __argc;
#ಅನ್ಯಥಾ
#define __argc (*_imp____argc)
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ *_imp____argc;
#endif
#endif
#ifndef __argv
#ifdef _MSVCRT_
  ಬಾಹ್ಯ ವರ್ಣ **__argv;
#ಅನ್ಯಥಾ
#define __argv  (*_imp____argv)
  ಬಾಹ್ಯ ವರ್ಣ ***_imp____argv;
#endif
#endif
#ifndef __wargv
#ifdef _MSVCRT_
  ಬಾಹ್ಯ wchar_t **__wargv;
#ಅನ್ಯಥಾ
#define __wargv (*_imp____wargv)
  ಬಾಹ್ಯ wchar_t ***_imp____wargv;
#endif
#endif

#ifdef _POSIX_
  ಬಾಹ್ಯ ವರ್ಣ **environ;
#ಅನ್ಯಥಾ
#ifndef _environ
#ifdef _MSVCRT_
  ಬಾಹ್ಯ ವರ್ಣ **_environ;
#ಅನ್ಯಥಾ
#define _environ (*_imp___environ)
  ಬಾಹ್ಯ ವರ್ಣ ***_imp___environ;
#endif
#endif

#ifndef _wenviron
#ifdef _MSVCRT_
  ಬಾಹ್ಯ wchar_t **_wenviron;
#ಅನ್ಯಥಾ
#define _wenviron       (*_imp___wenviron)
  ಬಾಹ್ಯ wchar_t ***_imp___wenviron;
#endif
#endif
#endif

#ಯದಿ defined __aarch64__
/* something does not work using those from msvcrt.dll */
# undef __argc
# undef __argv
# undef __wargv
# undef _wenviron
# undef _environ
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __argc;
ಬಾಹ್ಯ ವರ್ಣ **__argv;
ಬಾಹ್ಯ wchar_t **__wargv;
ಬಾಹ್ಯ ವರ್ಣ **_environ;
ಬಾಹ್ಯ wchar_t **_wenviron;
#endif

#ifndef _pgmptr
#ifdef _MSVCRT_
  ಬಾಹ್ಯ ವರ್ಣ *_pgmptr;
#ಅನ್ಯಥಾ
#define _pgmptr (*_imp___pgmptr)
  ಬಾಹ್ಯ ವರ್ಣ **_imp___pgmptr;
#endif
#endif

#ifndef _wpgmptr
#ifdef _MSVCRT_
  ಬಾಹ್ಯ wchar_t *_wpgmptr;
#ಅನ್ಯಥಾ
#define _wpgmptr        (*_imp___wpgmptr)
  ಬಾಹ್ಯ wchar_t **_imp___wpgmptr;
#endif
#endif
  errno_t __cdecl _get_pgmptr(ವರ್ಣ **ಮೌಲ್ಯ_2);
  errno_t __cdecl _get_wpgmptr(wchar_t **ಮೌಲ್ಯ_2);
#ifndef _fmode
#ifdef _MSVCRT_
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ _fmode;
#ಅನ್ಯಥಾ
#define _fmode  (*_imp___fmode)
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ *_imp___fmode;
#endif
#endif
  _CRTIMP errno_t __cdecl _set_fmode(ಪೂರ್ಣಾಙ್ಕ _Mode);
  _CRTIMP errno_t __cdecl _get_fmode(ಪೂರ್ಣಾಙ್ಕ *_PMode);

#ifndef _osplatform
#ifdef _MSVCRT_
  ಬಾಹ್ಯ unsigned ಪೂರ್ಣಾಙ್ಕ _osplatform;
#ಅನ್ಯಥಾ
#define _osplatform (*_imp___osplatform)
  ಬಾಹ್ಯ unsigned ಪೂರ್ಣಾಙ್ಕ *_imp___osplatform;
#endif
#endif

#ifndef _osver
#ifdef _MSVCRT_
  ಬಾಹ್ಯ unsigned ಪೂರ್ಣಾಙ್ಕ _osver;
#ಅನ್ಯಥಾ
#define _osver  (*_imp___osver)
  ಬಾಹ್ಯ unsigned ಪೂರ್ಣಾಙ್ಕ *_imp___osver;
#endif
#endif

#ifndef _winver
#ifdef _MSVCRT_
  ಬಾಹ್ಯ unsigned ಪೂರ್ಣಾಙ್ಕ _winver;
#ಅನ್ಯಥಾ
#define _winver (*_imp___winver)
  ಬಾಹ್ಯ unsigned ಪೂರ್ಣಾಙ್ಕ *_imp___winver;
#endif
#endif

#ifndef _winmajor
#ifdef _MSVCRT_
  ಬಾಹ್ಯ unsigned ಪೂರ್ಣಾಙ್ಕ _winmajor;
#ಅನ್ಯಥಾ
#define _winmajor       (*_imp___winmajor)
  ಬಾಹ್ಯ unsigned ಪೂರ್ಣಾಙ್ಕ *_imp___winmajor;
#endif
#endif

#ifndef _winminor
#ifdef _MSVCRT_
  ಬಾಹ್ಯ unsigned ಪೂರ್ಣಾಙ್ಕ _winminor;
#ಅನ್ಯಥಾ
#define _winminor       (*_imp___winminor)
  ಬಾಹ್ಯ unsigned ಪೂರ್ಣಾಙ್ಕ *_imp___winminor;
#endif
#endif

  errno_t __cdecl _get_osplatform(unsigned ಪೂರ್ಣಾಙ್ಕ *ಮೌಲ್ಯ_2);
  errno_t __cdecl _get_osver(unsigned ಪೂರ್ಣಾಙ್ಕ *ಮೌಲ್ಯ_2);
  errno_t __cdecl _get_winver(unsigned ಪೂರ್ಣಾಙ್ಕ *ಮೌಲ್ಯ_2);
  errno_t __cdecl _get_winmajor(unsigned ಪೂರ್ಣಾಙ್ಕ *ಮೌಲ್ಯ_2);
  errno_t __cdecl _get_winminor(unsigned ಪೂರ್ಣಾಙ್ಕ *ಮೌಲ್ಯ_2);
#ifndef _countof
#ifndef __cplusplus
#define _countof(_Array) (ಪರಿಮಾಣ(_Array) / ಪರಿಮಾಣ(_Array[0]))
#ಅನ್ಯಥಾ
  ಬಾಹ್ಯ "C++" {
    template <typename _CountofType,size_t _SizeOfArray> ವರ್ಣ (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];
#define _countof(_Array) ಪರಿಮಾಣ(*__countof_helper(_Array))
  }
#endif
#endif

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  ಶೂನ್ಯ __cdecl __MINGW_NOTHROW exit(ಪೂರ್ಣಾಙ್ಕ _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP ಶೂನ್ಯ __cdecl __MINGW_NOTHROW _exit(ಪೂರ್ಣಾಙ್ಕ _Code) __MINGW_ATTRIB_NORETURN;
#ಯದಿ !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  ಶೂನ್ಯ __cdecl _Exit(ಪೂರ್ಣಾಙ್ಕ) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN ಶೂನ್ಯ  __cdecl _Exit(ಪೂರ್ಣಾಙ್ಕ status)
  {  _exit(status); }
#endif

#pragma ತಳ್ಳು_macro("abort")
#undef abort
  ಶೂನ್ಯ __cdecl __declspec(noreturn) abort(ಶೂನ್ಯ);
#pragma ತೆಗೆ_macro("abort")

#endif

  _CRTIMP unsigned ಪೂರ್ಣಾಙ್ಕ __cdecl _set_abort_behavior(unsigned ಪೂರ್ಣಾಙ್ಕ _Flags,unsigned ಪೂರ್ಣಾಙ್ಕ _Mask);

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  ಪೂರ್ಣಾಙ್ಕ __cdecl abs(ಪೂರ್ಣಾಙ್ಕ _X);
  long __cdecl labs(long _X);
#endif

#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  __int64 __cdecl _abs64(__int64);
#endif
  ಪೂರ್ಣಾಙ್ಕ __cdecl atexit(ಶೂನ್ಯ (__cdecl *)(ಶೂನ್ಯ));
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  ದ್ವಿಗುಣ __cdecl atof(ಧ್ರುವ ವರ್ಣ *_String);
  ದ್ವಿಗುಣ __cdecl _atof_l(ಧ್ರುವ ವರ್ಣ *_String,_locale_t _Locale);
#endif
  ಪೂರ್ಣಾಙ್ಕ __cdecl atoi(ಧ್ರುವ ವರ್ಣ *_Str);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _atoi_l(ಧ್ರುವ ವರ್ಣ *_Str,_locale_t _Locale);
  long __cdecl atol(ಧ್ರುವ ವರ್ಣ *_Str);
  _CRTIMP long __cdecl _atol_l(ಧ್ರುವ ವರ್ಣ *_Str,_locale_t _Locale);
#ifndef _CRT_ALGO_DEFINED
#define _CRT_ALGO_DEFINED
  ಶೂನ್ಯ *__cdecl bsearch(ಧ್ರುವ ಶೂನ್ಯ *ಕೀಲಿ_2,ಧ್ರುವ ಶೂನ್ಯ *_Base,size_t ಅಂಕೆ_Of_Elements,size_t _SizeOfElements,ಪೂರ್ಣಾಙ್ಕ (__cdecl *_PtFuncCompare)(ಧ್ರುವ ಶೂನ್ಯ *,ಧ್ರುವ ಶೂನ್ಯ *));
  ಶೂನ್ಯ __cdecl qsort(ಶೂನ್ಯ *_Base,size_t ಅಂಕೆ_Of_Elements,size_t _SizeOfElements,ಪೂರ್ಣಾಙ್ಕ (__cdecl *_PtFuncCompare)(ಧ್ರುವ ಶೂನ್ಯ *,ಧ್ರುವ ಶೂನ್ಯ *));
#endif
  unsigned short __cdecl _byteswap_ushort(unsigned short _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Int64);
#endif
  div_t __cdecl div(ಪೂರ್ಣಾಙ್ಕ _Numerator,ಪೂರ್ಣಾಙ್ಕ _Denominator);
  ವರ್ಣ *__cdecl getenv(ಧ್ರುವ ವರ್ಣ *_VarName);
  _CRTIMP ವರ್ಣ *__cdecl _itoa(ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ_2,ವರ್ಣ *_Dest,ಪೂರ್ಣಾಙ್ಕ _Radix);
#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP ವರ್ಣ *__cdecl _i64toa(__int64 _Val,ವರ್ಣ *_DstBuf,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP ವರ್ಣ *__cdecl _ui64toa(unsigned __int64 _Val,ವರ್ಣ *_DstBuf,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP __int64 __cdecl _atoi64(ಧ್ರುವ ವರ್ಣ *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(ಧ್ರುವ ವರ್ಣ *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(ಧ್ರುವ ವರ್ಣ *_String,ವರ್ಣ **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(ಧ್ರುವ ವರ್ಣ *_String,ವರ್ಣ **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _strtoui64(ಧ್ರುವ ವರ್ಣ *_String,ವರ್ಣ **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP unsigned __int64 __cdecl _strtoui64_l(ಧ್ರುವ ವರ್ಣ *_String,ವರ್ಣ **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix,_locale_t _Locale);
#endif
  ldiv_t __cdecl ldiv(long _Numerator,long _Denominator);
  _CRTIMP ವರ್ಣ *__cdecl _ltoa(long ಮೌಲ್ಯ_2,ವರ್ಣ *_Dest,ಪೂರ್ಣಾಙ್ಕ _Radix);
  ಪೂರ್ಣಾಙ್ಕ __cdecl mblen(ಧ್ರುವ ವರ್ಣ *_Ch,size_t Max_ಎಣಿಕೆ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _mblen_l(ಧ್ರುವ ವರ್ಣ *_Ch,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrlen(ಧ್ರುವ ವರ್ಣ *_Str);
  _CRTIMP size_t __cdecl _mbstrlen_l(ಧ್ರುವ ವರ್ಣ *_Str,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrnlen(ಧ್ರುವ ವರ್ಣ *_Str,size_t Max_ಎಣಿಕೆ);
  _CRTIMP size_t __cdecl _mbstrnlen_l(ಧ್ರುವ ವರ್ಣ *_Str,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl mbtowc(wchar_t *_DstCh,ಧ್ರುವ ವರ್ಣ *_SrcCh,size_t _SrcSizeInBytes);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _mbtowc_l(wchar_t *_DstCh,ಧ್ರುವ ವರ್ಣ *_SrcCh,size_t _SrcSizeInBytes,_locale_t _Locale);
  size_t __cdecl mbstowcs(wchar_t *_Dest,ಧ್ರುವ ವರ್ಣ *_Source,size_t Max_ಎಣಿಕೆ);
  _CRTIMP size_t __cdecl _mbstowcs_l(wchar_t *_Dest,ಧ್ರುವ ವರ್ಣ *_Source,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl rand(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _set_error_mode(ಪೂರ್ಣಾಙ್ಕ _Mode);
  ಶೂನ್ಯ __cdecl srand(unsigned ಪೂರ್ಣಾಙ್ಕ _Seed);
  ದ್ವಿಗುಣ __cdecl strtod(ಧ್ರುವ ವರ್ಣ *_Str,ವರ್ಣ **_EndPtr);
#ಯದಿ !defined __NO_ISOCEXT  /* in libmingwex.a */
#ಯದಿ __TINYC__
  __CRT_INLINE ಭಿನ್ನ __cdecl strtof (ಧ್ರುವ ವರ್ಣ *p, ವರ್ಣ ** e) { ಪ್ರತ್ಯಾಗಮ strtod(p, e); }
  __CRT_INLINE long ದ್ವಿಗುಣ __cdecl strtold(ಧ್ರುವ ವರ್ಣ *p, ವರ್ಣ ** e) { ಪ್ರತ್ಯಾಗಮ strtod(p, e); }
#ಅನ್ಯಥಾ
  ಭಿನ್ನ __cdecl strtof (ಧ್ರುವ ವರ್ಣ * __restrict__, ವರ್ಣ ** __restrict__);
  long ದ್ವಿಗುಣ __cdecl strtold(ಧ್ರುವ ವರ್ಣ * __restrict__, ವರ್ಣ ** __restrict__);
#endif
#ಅನ್ಯಥಾ
  ಭಿನ್ನ __cdecl strtof(ಧ್ರುವ ವರ್ಣ *nptr, ವರ್ಣ **endptr);
#endif /* __NO_ISOCEXT */
  _CRTIMP ದ್ವಿಗುಣ __cdecl _strtod_l(ಧ್ರುವ ವರ್ಣ *_Str,ವರ್ಣ **_EndPtr,_locale_t _Locale);
  long __cdecl strtol(ಧ್ರುವ ವರ್ಣ *_Str,ವರ್ಣ **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP long __cdecl _strtol_l(ಧ್ರುವ ವರ್ಣ *_Str,ವರ್ಣ **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix,_locale_t _Locale);
  unsigned long __cdecl strtoul(ಧ್ರುವ ವರ್ಣ *_Str,ವರ್ಣ **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP unsigned long __cdecl _strtoul_l(ಧ್ರುವ ವರ್ಣ *_Str,ವರ್ಣ **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix,_locale_t _Locale);
#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  ಪೂರ್ಣಾಙ್ಕ __cdecl system(ಧ್ರುವ ವರ್ಣ *_Command);
#endif
  _CRTIMP ವರ್ಣ *__cdecl _ultoa(unsigned long ಮೌಲ್ಯ_2,ವರ್ಣ *_Dest,ಪೂರ್ಣಾಙ್ಕ _Radix);
  ಪೂರ್ಣಾಙ್ಕ __cdecl wctomb(ವರ್ಣ *_MbCh,wchar_t _WCh);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wctomb_l(ವರ್ಣ *_MbCh,wchar_t _WCh,_locale_t _Locale);
  size_t __cdecl wcstombs(ವರ್ಣ *_Dest,ಧ್ರುವ wchar_t *_Source,size_t Max_ಎಣಿಕೆ);
  _CRTIMP size_t __cdecl _wcstombs_l(ವರ್ಣ *_Dest,ಧ್ರುವ wchar_t *_Source,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  ಶೂನ್ಯ *__cdecl calloc(size_t ಅಂಕೆ_Of_Elements,size_t _SizeOfElements);
  ಶೂನ್ಯ __cdecl ಮುಕ್ತ(ಶೂನ್ಯ *_Memory);
  ಶೂನ್ಯ *__cdecl malloc(size_t _Size);
  ಶೂನ್ಯ *__cdecl realloc(ಶೂನ್ಯ *_Memory,size_t _NewSize);
  _CRTIMP ಶೂನ್ಯ *__cdecl _recalloc(ಶೂನ್ಯ *_Memory,size_t ಎಣಿಕೆ_5,size_t _Size);
  _CRTIMP ಶೂನ್ಯ __cdecl _aligned_free(ಶೂನ್ಯ *_Memory);
  _CRTIMP ಶೂನ್ಯ *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP ಶೂನ್ಯ *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP ಶೂನ್ಯ *__cdecl _aligned_realloc(ಶೂನ್ಯ *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP ಶೂನ್ಯ *__cdecl _aligned_recalloc(ಶೂನ್ಯ *_Memory,size_t ಎಣಿಕೆ_5,size_t _Size,size_t _Alignment);
  _CRTIMP ಶೂನ್ಯ *__cdecl _aligned_offset_realloc(ಶೂನ್ಯ *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP ಶೂನ್ಯ *__cdecl _aligned_offset_recalloc(ಶೂನ್ಯ *_Memory,size_t ಎಣಿಕೆ_5,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ_2,wchar_t *_Dest,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long ಮೌಲ್ಯ_2,wchar_t *_Dest,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long ಮೌಲ್ಯ_2,wchar_t *_Dest,ಪೂರ್ಣಾಙ್ಕ _Radix);
  ದ್ವಿಗುಣ __cdecl wcstod(ಧ್ರುವ wchar_t *_Str,wchar_t **_EndPtr);
  ಭಿನ್ನ __cdecl wcstof(ಧ್ರುವ wchar_t *nptr, wchar_t **endptr);
#ಯದಿ !defined __NO_ISOCEXT /* in libmingwex.a */
  ಭಿನ್ನ __cdecl wcstof( ಧ್ರುವ wchar_t * __restrict__, wchar_t ** __restrict__);
  long ದ್ವಿಗುಣ __cdecl wcstold(ಧ್ರುವ wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  _CRTIMP ದ್ವಿಗುಣ __cdecl _wcstod_l(ಧ್ರುವ wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  long __cdecl wcstol(ಧ್ರುವ wchar_t *_Str,wchar_t **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP long __cdecl _wcstol_l(ಧ್ರುವ wchar_t *_Str,wchar_t **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(ಧ್ರುವ wchar_t *_Str,wchar_t **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(ಧ್ರುವ wchar_t *_Str,wchar_t **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ಧ್ರುವ wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wsystem(ಧ್ರುವ wchar_t *_Command);
#endif
  _CRTIMP ದ್ವಿಗುಣ __cdecl _wtof(ಧ್ರುವ wchar_t *_Str);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _wtof_l(ಧ್ರುವ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wtoi(ಧ್ರುವ wchar_t *_Str);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wtoi_l(ಧ್ರುವ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(ಧ್ರುವ wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(ಧ್ರುವ wchar_t *_Str,_locale_t _Locale);

#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ಧ್ರುವ wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ಧ್ರುವ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ಧ್ರುವ wchar_t *_Str,wchar_t **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ಧ್ರುವ wchar_t *_Str,wchar_t **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(ಧ್ರುವ wchar_t *_Str,wchar_t **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(ಧ್ರುವ wchar_t *_Str ,wchar_t **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#define _CVTBUFSIZE (309+40)
  _CRTIMP ವರ್ಣ *__cdecl _fullpath(ವರ್ಣ *_FullPath,ಧ್ರುವ ವರ್ಣ *_Path,size_t _SizeInBytes);
  _CRTIMP ವರ್ಣ *__cdecl _ecvt(ದ್ವಿಗುಣ _Val,ಪೂರ್ಣಾಙ್ಕ ಅಂಕೆ_Of_Digits,ಪೂರ್ಣಾಙ್ಕ *_PtDec,ಪೂರ್ಣಾಙ್ಕ *_PtSign);
  _CRTIMP ವರ್ಣ *__cdecl _fcvt(ದ್ವಿಗುಣ _Val,ಪೂರ್ಣಾಙ್ಕ ಅಂಕೆ_Of_Dec,ಪೂರ್ಣಾಙ್ಕ *_PtDec,ಪೂರ್ಣಾಙ್ಕ *_PtSign);
  _CRTIMP ವರ್ಣ *__cdecl _gcvt(ದ್ವಿಗುಣ _Val,ಪೂರ್ಣಾಙ್ಕ ಅಂಕೆ_Of_Digits,ವರ್ಣ *_DstBuf);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _atodbl(_CRT_DOUBLE *_Result,ವರ್ಣ *_Str);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _atoldbl(_LDOUBLE *_Result,ವರ್ಣ *_Str);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _atoflt(_CRT_FLOAT *_Result,ವರ್ಣ *_Str);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _atodbl_l(_CRT_DOUBLE *_Result,ವರ್ಣ *_Str,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _atoldbl_l(_LDOUBLE *_Result,ವರ್ಣ *_Str,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _atoflt_l(_CRT_FLOAT *_Result,ವರ್ಣ *_Str,_locale_t _Locale);
  unsigned long __cdecl _lrotl(unsigned long _Val,ಪೂರ್ಣಾಙ್ಕ _Shift);
  unsigned long __cdecl _lrotr(unsigned long _Val,ಪೂರ್ಣಾಙ್ಕ _Shift);
  _CRTIMP ಶೂನ್ಯ __cdecl _makepath(ವರ್ಣ *_Path,ಧ್ರುವ ವರ್ಣ *_Drive,ಧ್ರುವ ವರ್ಣ *_Dir,ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  ಶೂನ್ಯ __cdecl perror(ಧ್ರುವ ವರ್ಣ *Err_ಸಂದೇಶ);
#endif
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _putenv(ಧ್ರುವ ವರ್ಣ *_EnvString);
  unsigned ಪೂರ್ಣಾಙ್ಕ __cdecl _rotl(unsigned ಪೂರ್ಣಾಙ್ಕ _Val,ಪೂರ್ಣಾಙ್ಕ _Shift);
#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotl64(unsigned __int64 _Val,ಪೂರ್ಣಾಙ್ಕ _Shift);
#endif
  unsigned ಪೂರ್ಣಾಙ್ಕ __cdecl _rotr(unsigned ಪೂರ್ಣಾಙ್ಕ _Val,ಪೂರ್ಣಾಙ್ಕ _Shift);
#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotr64(unsigned __int64 _Val,ಪೂರ್ಣಾಙ್ಕ _Shift);
#endif
  _CRTIMP ಶೂನ್ಯ __cdecl _searchenv(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_EnvVar,ವರ್ಣ *_ResultPath);
  _CRTIMP ಶೂನ್ಯ __cdecl _splitpath(ಧ್ರುವ ವರ್ಣ *_FullPath,ವರ್ಣ *_Drive,ವರ್ಣ *_Dir,ವರ್ಣ *_Filename,ವರ್ಣ *_Ext);
  _CRTIMP ಶೂನ್ಯ __cdecl _swab(ವರ್ಣ *_Buf1,ವರ್ಣ *_Buf2,ಪೂರ್ಣಾಙ್ಕ _SizeInBytes);

#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,ಧ್ರುವ wchar_t *_Path,size_t Size_In_ಪದಗಳು);
  _CRTIMP ಶೂನ್ಯ __cdecl _wmakepath(wchar_t *_ResultPath,ಧ್ರುವ wchar_t *_Drive,ಧ್ರುವ wchar_t *_Dir,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP ಶೂನ್ಯ __cdecl _wperror(ಧ್ರುವ wchar_t *Err_ಸಂದೇಶ);
#endif
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wputenv(ಧ್ರುವ wchar_t *_EnvString);
  _CRTIMP ಶೂನ್ಯ __cdecl _wsearchenv(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP ಶೂನ್ಯ __cdecl _wsplitpath(ಧ್ರುವ wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif

  _CRTIMP ಶೂನ್ಯ __cdecl _beep(unsigned _Frequency,unsigned _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP ಶೂನ್ಯ __cdecl _seterrormode(ಪೂರ್ಣಾಙ್ಕ _Mode) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP ಶೂನ್ಯ __cdecl _sleep(unsigned long _Duration) __MINGW_ATTRIB_DEPRECATED;
#endif

#ifndef NO_OLDNAMES
#ifndef _POSIX_
#ಯದಿ 0
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
  ವರ್ಣ *__cdecl ecvt(ದ್ವಿಗುಣ _Val,ಪೂರ್ಣಾಙ್ಕ ಅಂಕೆ_Of_Digits,ಪೂರ್ಣಾಙ್ಕ *_PtDec,ಪೂರ್ಣಾಙ್ಕ *_PtSign);
  ವರ್ಣ *__cdecl fcvt(ದ್ವಿಗುಣ _Val,ಪೂರ್ಣಾಙ್ಕ ಅಂಕೆ_Of_Dec,ಪೂರ್ಣಾಙ್ಕ *_PtDec,ಪೂರ್ಣಾಙ್ಕ *_PtSign);
  ವರ್ಣ *__cdecl gcvt(ದ್ವಿಗುಣ _Val,ಪೂರ್ಣಾಙ್ಕ ಅಂಕೆ_Of_Digits,ವರ್ಣ *_DstBuf);
  ವರ್ಣ *__cdecl itoa(ಪೂರ್ಣಾಙ್ಕ _Val,ವರ್ಣ *_DstBuf,ಪೂರ್ಣಾಙ್ಕ _Radix);
  ವರ್ಣ *__cdecl ltoa(long _Val,ವರ್ಣ *_DstBuf,ಪೂರ್ಣಾಙ್ಕ _Radix);
  ಪೂರ್ಣಾಙ್ಕ __cdecl putenv(ಧ್ರುವ ವರ್ಣ *_EnvString);
  ಶೂನ್ಯ __cdecl swab(ವರ್ಣ *_Buf1,ವರ್ಣ *_Buf2,ಪೂರ್ಣಾಙ್ಕ _SizeInBytes);
  ವರ್ಣ *__cdecl ultoa(unsigned long _Val,ವರ್ಣ *_Dstbuf,ಪೂರ್ಣಾಙ್ಕ _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#endif
#endif

#ಯದಿ !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { long long quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(long long, long long);

  __CRT_INLINE long long __cdecl llabs(long long _j) { ಪ್ರತ್ಯಾಗಮ (_j >= 0 ? _j : -_j); }

 #ifdef __TINYC__ /* gr */
  #define strtoll _strtoi64
  #define strtoull _strtoui64
 #ಅನ್ಯಥಾ
  long long  __cdecl strtoll(ಧ್ರುವ ವರ್ಣ* __restrict__, ವರ್ಣ** __restrict, ಪೂರ್ಣಾಙ್ಕ);
  unsigned long long  __cdecl strtoull(ಧ್ರುವ ವರ್ಣ* __restrict__, ವರ್ಣ** __restrict__, ಪೂರ್ಣಾಙ್ಕ);
 #endif

  /* these are stubs for MS _i64 versions */
  long long  __cdecl atoll (ಧ್ರುವ ವರ್ಣ *);

#ifndef __STRICT_ANSI__
  long long  __cdecl wtoll (ಧ್ರುವ wchar_t *);
  ವರ್ಣ *__cdecl lltoa (long long, ವರ್ಣ *, ಪೂರ್ಣಾಙ್ಕ);
  ವರ್ಣ *__cdecl ulltoa (unsigned long long , ವರ್ಣ *, ಪೂರ್ಣಾಙ್ಕ);
  wchar_t *__cdecl lltow (long long, wchar_t *, ಪೂರ್ಣಾಙ್ಕ);
  wchar_t *__cdecl ulltow (unsigned long long, wchar_t *, ಪೂರ್ಣಾಙ್ಕ);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE long long  __cdecl atoll (ಧ್ರುವ ವರ್ಣ * _c) { ಪ್ರತ್ಯಾಗಮ _atoi64 (_c); }
  __CRT_INLINE ವರ್ಣ *__cdecl lltoa (long long _n, ವರ್ಣ * _c, ಪೂರ್ಣಾಙ್ಕ _i) { ಪ್ರತ್ಯಾಗಮ _i64toa (_n, _c, _i); }
  __CRT_INLINE ವರ್ಣ *__cdecl ulltoa (unsigned long long _n, ವರ್ಣ * _c, ಪೂರ್ಣಾಙ್ಕ _i) { ಪ್ರತ್ಯಾಗಮ _ui64toa (_n, _c, _i); }
  __CRT_INLINE long long  __cdecl wtoll (ಧ್ರುವ wchar_t * _w) { ಪ್ರತ್ಯಾಗಮ _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (long long _n, wchar_t * _w, ಪೂರ್ಣಾಙ್ಕ _i) { ಪ್ರತ್ಯಾಗಮ _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (unsigned long long _n, wchar_t * _w, ಪೂರ್ಣಾಙ್ಕ _i) { ಪ್ರತ್ಯಾಗಮ _ui64tow (_n, _w, _i); }
#endif /* (__STRICT_ANSI__)  */

#endif /* !__NO_ISOCEXT */

#ifdef __cplusplus
}
#endif

#pragma pack(ತೆಗೆ)

#ಅನ್ತರ್ಭಾವ <sec_api/stdlib_s.h>
#ಅನ್ತರ್ಭಾವ <malloc.h>

#endif
