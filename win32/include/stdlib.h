/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB
#define _INC_STDLIB

#include <_mingw.h>
#include <limits.h>

#pragma pack(push,_CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#инако
#define NULL ((void *)0)
#endif
#endif

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#ifndef _ONEXIT_T_DEFINED
#define _ONEXIT_T_DEFINED

  typedef цео (__cdecl *_onexit_t)(void);

#ifndef NO_OLDNAMES
#define onexit_t _onexit_t
#endif
#endif

#ifndef _DIV_T_DEFINED
#define _DIV_T_DEFINED

  typedef struct _div_t {
    цео quot;
    цео rem;
  } div_t;

  typedef struct _ldiv_t {
    long quot;
    long rem;
  } ldiv_t;
#endif

#ifndef _CRT_DOUBLE_DEC
#define _CRT_DOUBLE_DEC

#pragma pack(4)
  typedef struct {
    unsigned char ld[10];
  } _LDOUBLE;
#pragma pack()

#define _PTR_LD(x) ((unsigned char *)(&(x)->ld))

  typedef struct {
    double x;
  } _CRT_DOUBLE;

  typedef struct {
    float f;
  } _CRT_FLOAT;

#pragma push_macro("long")
#undef long

  typedef struct {
    long double x;
  } _LONGDOUBLE;

#pragma pop_macro("long")

#pragma pack(4)
  typedef struct {
    unsigned char ld12[12];
  } _LDBL12;
#pragma pack()
#endif

#define RAND_MAX 0x7fff

#ifndef MB_CUR_MAX
#define MB_CUR_MAX ___mb_cur_max_func()
#ifndef __mb_cur_max
#ifdef _MSVCRT_
  extern цео __mb_cur_max;
#инако
#define __mb_cur_max    (*_imp____mb_cur_max)
  extern цео *_imp____mb_cur_max;
#endif
#endif
#ifdef _MSVCRT_
  extern цео __mbcur_max;
#define ___mb_cur_max_func() (__mb_cur_max)
#инако
  extern цео* _imp____mbcur_max;
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

#define _WRITE_ABORT_MSG 0x1
#define _CALL_REPORTFAULT 0x2

#define _MAX_ENV 32767

  typedef void (__cdecl *_purecall_handler)(void);

  _CRTIMP _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(void);

  typedef void (__cdecl *_invalid_parameter_handler)(const wchar_t *,const wchar_t *,const wchar_t *,unsigned цео,uintptr_t);
  _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(void);

#ifndef _CRT_ERRNO_DEFINED
#define _CRT_ERRNO_DEFINED
  _CRTIMP цео *__cdecl _errno(void);
#define errno (*_errno())
  errno_t __cdecl _set_errno(цео _Value);
  errno_t __cdecl _get_errno(цео *_Value);
#endif
  _CRTIMP unsigned long *__cdecl __doserrno(void);
#define _doserrno (*__doserrno())
  errno_t __cdecl _set_doserrno(unsigned long _Value);
  errno_t __cdecl _get_doserrno(unsigned long *_Value);
#ifdef _MSVCRT_
  extern char *_sys_errlist[];
  extern цео _sys_nerr;
#инако
  _CRTIMP char *_sys_errlist[1];
  _CRTIMP цео _sys_nerr;
#endif
#ако (defined(_X86_) && !defined(__x86_64))
  _CRTIMP цео *__cdecl __p___argc(void);
  _CRTIMP char ***__cdecl __p___argv(void);
  _CRTIMP wchar_t ***__cdecl __p___wargv(void);
  _CRTIMP char ***__cdecl __p__environ(void);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(void);
  _CRTIMP char **__cdecl __p__pgmptr(void);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(void);
#endif
#ifndef __argc
#ifdef _MSVCRT_
  extern цео __argc;
#инако
#define __argc (*_imp____argc)
  extern цео *_imp____argc;
#endif
#endif
#ifndef __argv
#ifdef _MSVCRT_
  extern char **__argv;
#инако
#define __argv  (*_imp____argv)
  extern char ***_imp____argv;
#endif
#endif
#ifndef __wargv
#ifdef _MSVCRT_
  extern wchar_t **__wargv;
#инако
#define __wargv (*_imp____wargv)
  extern wchar_t ***_imp____wargv;
#endif
#endif

#ifdef _POSIX_
  extern char **environ;
#инако
#ifndef _environ
#ifdef _MSVCRT_
  extern char **_environ;
#инако
#define _environ (*_imp___environ)
  extern char ***_imp___environ;
#endif
#endif

#ifndef _wenviron
#ifdef _MSVCRT_
  extern wchar_t **_wenviron;
#инако
#define _wenviron       (*_imp___wenviron)
  extern wchar_t ***_imp___wenviron;
#endif
#endif
#endif

#ако defined __aarch64__
/* something does not work using those from msvcrt.dll */
# undef __argc
# undef __argv
# undef __wargv
# undef _wenviron
# undef _environ
extern цео __argc;
extern char **__argv;
extern wchar_t **__wargv;
extern char **_environ;
extern wchar_t **_wenviron;
#endif

#ifndef _pgmptr
#ifdef _MSVCRT_
  extern char *_pgmptr;
#инако
#define _pgmptr (*_imp___pgmptr)
  extern char **_imp___pgmptr;
#endif
#endif

#ifndef _wpgmptr
#ifdef _MSVCRT_
  extern wchar_t *_wpgmptr;
#инако
#define _wpgmptr        (*_imp___wpgmptr)
  extern wchar_t **_imp___wpgmptr;
#endif
#endif
  errno_t __cdecl _get_pgmptr(char **_Value);
  errno_t __cdecl _get_wpgmptr(wchar_t **_Value);
#ifndef _fmode
#ifdef _MSVCRT_
  extern цео _fmode;
#инако
#define _fmode  (*_imp___fmode)
  extern цео *_imp___fmode;
#endif
#endif
  _CRTIMP errno_t __cdecl _set_fmode(цео _Mode);
  _CRTIMP errno_t __cdecl _get_fmode(цео *_PMode);

#ifndef _osplatform
#ifdef _MSVCRT_
  extern unsigned цео _osplatform;
#инако
#define _osplatform (*_imp___osplatform)
  extern unsigned цео *_imp___osplatform;
#endif
#endif

#ifndef _osver
#ifdef _MSVCRT_
  extern unsigned цео _osver;
#инако
#define _osver  (*_imp___osver)
  extern unsigned цео *_imp___osver;
#endif
#endif

#ifndef _winver
#ifdef _MSVCRT_
  extern unsigned цео _winver;
#инако
#define _winver (*_imp___winver)
  extern unsigned цео *_imp___winver;
#endif
#endif

#ifndef _winmajor
#ifdef _MSVCRT_
  extern unsigned цео _winmajor;
#инако
#define _winmajor       (*_imp___winmajor)
  extern unsigned цео *_imp___winmajor;
#endif
#endif

#ifndef _winminor
#ifdef _MSVCRT_
  extern unsigned цео _winminor;
#инако
#define _winminor       (*_imp___winminor)
  extern unsigned цео *_imp___winminor;
#endif
#endif

  errno_t __cdecl _get_osplatform(unsigned цео *_Value);
  errno_t __cdecl _get_osver(unsigned цео *_Value);
  errno_t __cdecl _get_winver(unsigned цео *_Value);
  errno_t __cdecl _get_winmajor(unsigned цео *_Value);
  errno_t __cdecl _get_winminor(unsigned цео *_Value);
#ifndef _countof
#ifndef __cplusplus
#define _countof(_Array) (sizeof(_Array) / sizeof(_Array[0]))
#инако
  extern "C++" {
    template <typename _CountofType,size_t _SizeOfArray> char (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];
#define _countof(_Array) sizeof(*__countof_helper(_Array))
  }
#endif
#endif

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  void __cdecl __MINGW_NOTHROW exit(цео _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP void __cdecl __MINGW_NOTHROW _exit(цео _Code) __MINGW_ATTRIB_NORETURN;
#ако !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  void __cdecl _Exit(цео) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN void  __cdecl _Exit(цео status)
  {  _exit(status); }
#endif

#pragma push_macro("abort")
#undef abort
  void __cdecl __declspec(noreturn) abort(void);
#pragma pop_macro("abort")

#endif

  _CRTIMP unsigned цео __cdecl _set_abort_behavior(unsigned цео _Flags,unsigned цео _Mask);

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  цео __cdecl abs(цео _X);
  long __cdecl labs(long _X);
#endif

#ако _INTEGRAL_MAX_BITS >= 64
  __int64 __cdecl _abs64(__int64);
#endif
  цео __cdecl atexit(void (__cdecl *)(void));
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  double __cdecl atof(const char *_String);
  double __cdecl _atof_l(const char *_String,_locale_t _Locale);
#endif
  цео __cdecl atoi(const char *_Str);
  _CRTIMP цео __cdecl _atoi_l(const char *_Str,_locale_t _Locale);
  long __cdecl atol(const char *_Str);
  _CRTIMP long __cdecl _atol_l(const char *_Str,_locale_t _Locale);
#ifndef _CRT_ALGO_DEFINED
#define _CRT_ALGO_DEFINED
  void *__cdecl bsearch(const void *_Key,const void *_Base,size_t _NumOfElements,size_t _SizeOfElements,цео (__cdecl *_PtFuncCompare)(const void *,const void *));
  void __cdecl qsort(void *_Base,size_t _NumOfElements,size_t _SizeOfElements,цео (__cdecl *_PtFuncCompare)(const void *,const void *));
#endif
  unsigned short __cdecl _byteswap_ushort(unsigned short _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#ако _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Int64);
#endif
  div_t __cdecl div(цео _Numerator,цео _Denominator);
  char *__cdecl getenv(const char *_VarName);
  _CRTIMP char *__cdecl _itoa(цео _Value,char *_Dest,цео _Radix);
#ако _INTEGRAL_MAX_BITS >= 64
  _CRTIMP char *__cdecl _i64toa(__int64 _Val,char *_DstBuf,цео _Radix);
  _CRTIMP char *__cdecl _ui64toa(unsigned __int64 _Val,char *_DstBuf,цео _Radix);
  _CRTIMP __int64 __cdecl _atoi64(const char *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(const char *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(const char *_String,char **_EndPtr,цео _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(const char *_String,char **_EndPtr,цео _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _strtoui64(const char *_String,char **_EndPtr,цео _Radix);
  _CRTIMP unsigned __int64 __cdecl _strtoui64_l(const char *_String,char **_EndPtr,цео _Radix,_locale_t _Locale);
#endif
  ldiv_t __cdecl ldiv(long _Numerator,long _Denominator);
  _CRTIMP char *__cdecl _ltoa(long _Value,char *_Dest,цео _Radix);
  цео __cdecl mblen(const char *_Ch,size_t _MaxCount);
  _CRTIMP цео __cdecl _mblen_l(const char *_Ch,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrlen(const char *_Str);
  _CRTIMP size_t __cdecl _mbstrlen_l(const char *_Str,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrnlen(const char *_Str,size_t _MaxCount);
  _CRTIMP size_t __cdecl _mbstrnlen_l(const char *_Str,size_t _MaxCount,_locale_t _Locale);
  цео __cdecl mbtowc(wchar_t *_DstCh,const char *_SrcCh,size_t _SrcSizeInBytes);
  _CRTIMP цео __cdecl _mbtowc_l(wchar_t *_DstCh,const char *_SrcCh,size_t _SrcSizeInBytes,_locale_t _Locale);
  size_t __cdecl mbstowcs(wchar_t *_Dest,const char *_Source,size_t _MaxCount);
  _CRTIMP size_t __cdecl _mbstowcs_l(wchar_t *_Dest,const char *_Source,size_t _MaxCount,_locale_t _Locale);
  цео __cdecl rand(void);
  _CRTIMP цео __cdecl _set_error_mode(цео _Mode);
  void __cdecl srand(unsigned цео _Seed);
  double __cdecl strtod(const char *_Str,char **_EndPtr);
#ако !defined __NO_ISOCEXT  /* in libmingwex.a */
#ако __TINYC__
  __CRT_INLINE float __cdecl strtof (const char *p, char ** e) { врати strtod(p, e); }
  __CRT_INLINE long double __cdecl strtold(const char *p, char ** e) { врати strtod(p, e); }
#инако
  float __cdecl strtof (const char * __restrict__, char ** __restrict__);
  long double __cdecl strtold(const char * __restrict__, char ** __restrict__);
#endif
#инако
  float __cdecl strtof(const char *nptr, char **endptr);
#endif /* __NO_ISOCEXT */
  _CRTIMP double __cdecl _strtod_l(const char *_Str,char **_EndPtr,_locale_t _Locale);
  long __cdecl strtol(const char *_Str,char **_EndPtr,цео _Radix);
  _CRTIMP long __cdecl _strtol_l(const char *_Str,char **_EndPtr,цео _Radix,_locale_t _Locale);
  unsigned long __cdecl strtoul(const char *_Str,char **_EndPtr,цео _Radix);
  _CRTIMP unsigned long __cdecl _strtoul_l(const char *_Str,char **_EndPtr,цео _Radix,_locale_t _Locale);
#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  цео __cdecl system(const char *_Command);
#endif
  _CRTIMP char *__cdecl _ultoa(unsigned long _Value,char *_Dest,цео _Radix);
  цео __cdecl wctomb(char *_MbCh,wchar_t _WCh);
  _CRTIMP цео __cdecl _wctomb_l(char *_MbCh,wchar_t _WCh,_locale_t _Locale);
  size_t __cdecl wcstombs(char *_Dest,const wchar_t *_Source,size_t _MaxCount);
  _CRTIMP size_t __cdecl _wcstombs_l(char *_Dest,const wchar_t *_Source,size_t _MaxCount,_locale_t _Locale);

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  void *__cdecl calloc(size_t _NumOfElements,size_t _SizeOfElements);
  void __cdecl free(void *_Memory);
  void *__cdecl malloc(size_t _Size);
  void *__cdecl realloc(void *_Memory,size_t _NewSize);
  _CRTIMP void *__cdecl _recalloc(void *_Memory,size_t _Count,size_t _Size);
  _CRTIMP void __cdecl _aligned_free(void *_Memory);
  _CRTIMP void *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP void *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP void *__cdecl _aligned_realloc(void *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP void *__cdecl _aligned_recalloc(void *_Memory,size_t _Count,size_t _Size,size_t _Alignment);
  _CRTIMP void *__cdecl _aligned_offset_realloc(void *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP void *__cdecl _aligned_offset_recalloc(void *_Memory,size_t _Count,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(цео _Value,wchar_t *_Dest,цео _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long _Value,wchar_t *_Dest,цео _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long _Value,wchar_t *_Dest,цео _Radix);
  double __cdecl wcstod(const wchar_t *_Str,wchar_t **_EndPtr);
  float __cdecl wcstof(const wchar_t *nptr, wchar_t **endptr);
#ако !defined __NO_ISOCEXT /* in libmingwex.a */
  float __cdecl wcstof( const wchar_t * __restrict__, wchar_t ** __restrict__);
  long double __cdecl wcstold(const wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  _CRTIMP double __cdecl _wcstod_l(const wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  long __cdecl wcstol(const wchar_t *_Str,wchar_t **_EndPtr,цео _Radix);
  _CRTIMP long __cdecl _wcstol_l(const wchar_t *_Str,wchar_t **_EndPtr,цео _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(const wchar_t *_Str,wchar_t **_EndPtr,цео _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(const wchar_t *_Str,wchar_t **_EndPtr,цео _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(const wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP цео __cdecl _wsystem(const wchar_t *_Command);
#endif
  _CRTIMP double __cdecl _wtof(const wchar_t *_Str);
  _CRTIMP double __cdecl _wtof_l(const wchar_t *_Str,_locale_t _Locale);
  _CRTIMP цео __cdecl _wtoi(const wchar_t *_Str);
  _CRTIMP цео __cdecl _wtoi_l(const wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(const wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(const wchar_t *_Str,_locale_t _Locale);

#ако _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,цео _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,цео _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(const wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(const wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(const wchar_t *_Str,wchar_t **_EndPtr,цео _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(const wchar_t *_Str,wchar_t **_EndPtr,цео _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(const wchar_t *_Str,wchar_t **_EndPtr,цео _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(const wchar_t *_Str ,wchar_t **_EndPtr,цео _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#define _CVTBUFSIZE (309+40)
  _CRTIMP char *__cdecl _fullpath(char *_FullPath,const char *_Path,size_t _SizeInBytes);
  _CRTIMP char *__cdecl _ecvt(double _Val,цео _NumOfDigits,цео *_PtDec,цео *_PtSign);
  _CRTIMP char *__cdecl _fcvt(double _Val,цео _NumOfDec,цео *_PtDec,цео *_PtSign);
  _CRTIMP char *__cdecl _gcvt(double _Val,цео _NumOfDigits,char *_DstBuf);
  _CRTIMP цео __cdecl _atodbl(_CRT_DOUBLE *_Result,char *_Str);
  _CRTIMP цео __cdecl _atoldbl(_LDOUBLE *_Result,char *_Str);
  _CRTIMP цео __cdecl _atoflt(_CRT_FLOAT *_Result,char *_Str);
  _CRTIMP цео __cdecl _atodbl_l(_CRT_DOUBLE *_Result,char *_Str,_locale_t _Locale);
  _CRTIMP цео __cdecl _atoldbl_l(_LDOUBLE *_Result,char *_Str,_locale_t _Locale);
  _CRTIMP цео __cdecl _atoflt_l(_CRT_FLOAT *_Result,char *_Str,_locale_t _Locale);
  unsigned long __cdecl _lrotl(unsigned long _Val,цео _Shift);
  unsigned long __cdecl _lrotr(unsigned long _Val,цео _Shift);
  _CRTIMP void __cdecl _makepath(char *_Path,const char *_Drive,const char *_Dir,const char *_Filename,const char *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  void __cdecl perror(const char *_ErrMsg);
#endif
  _CRTIMP цео __cdecl _putenv(const char *_EnvString);
  unsigned цео __cdecl _rotl(unsigned цео _Val,цео _Shift);
#ако _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotl64(unsigned __int64 _Val,цео _Shift);
#endif
  unsigned цео __cdecl _rotr(unsigned цео _Val,цео _Shift);
#ако _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotr64(unsigned __int64 _Val,цео _Shift);
#endif
  _CRTIMP void __cdecl _searchenv(const char *_Filename,const char *_EnvVar,char *_ResultPath);
  _CRTIMP void __cdecl _splitpath(const char *_FullPath,char *_Drive,char *_Dir,char *_Filename,char *_Ext);
  _CRTIMP void __cdecl _swab(char *_Buf1,char *_Buf2,цео _SizeInBytes);

#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,const wchar_t *_Path,size_t _SizeInWords);
  _CRTIMP void __cdecl _wmakepath(wchar_t *_ResultPath,const wchar_t *_Drive,const wchar_t *_Dir,const wchar_t *_Filename,const wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP void __cdecl _wperror(const wchar_t *_ErrMsg);
#endif
  _CRTIMP цео __cdecl _wputenv(const wchar_t *_EnvString);
  _CRTIMP void __cdecl _wsearchenv(const wchar_t *_Filename,const wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP void __cdecl _wsplitpath(const wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif

  _CRTIMP void __cdecl _beep(unsigned _Frequency,unsigned _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP void __cdecl _seterrormode(цео _Mode) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP void __cdecl _sleep(unsigned long _Duration) __MINGW_ATTRIB_DEPRECATED;
#endif

#ifndef NO_OLDNAMES
#ifndef _POSIX_
#ако 0
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
  char *__cdecl ecvt(double _Val,цео _NumOfDigits,цео *_PtDec,цео *_PtSign);
  char *__cdecl fcvt(double _Val,цео _NumOfDec,цео *_PtDec,цео *_PtSign);
  char *__cdecl gcvt(double _Val,цео _NumOfDigits,char *_DstBuf);
  char *__cdecl itoa(цео _Val,char *_DstBuf,цео _Radix);
  char *__cdecl ltoa(long _Val,char *_DstBuf,цео _Radix);
  цео __cdecl putenv(const char *_EnvString);
  void __cdecl swab(char *_Buf1,char *_Buf2,цео _SizeInBytes);
  char *__cdecl ultoa(unsigned long _Val,char *_Dstbuf,цео _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#endif
#endif

#ако !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  typedef struct { long long quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(long long, long long);

  __CRT_INLINE long long __cdecl llabs(long long _j) { врати (_j >= 0 ? _j : -_j); }

 #ifdef __TINYC__ /* gr */
  #define strtoll _strtoi64
  #define strtoull _strtoui64
 #инако
  long long  __cdecl strtoll(const char* __restrict__, char** __restrict, цео);
  unsigned long long  __cdecl strtoull(const char* __restrict__, char** __restrict__, цео);
 #endif

  /* these are stubs for MS _i64 versions */
  long long  __cdecl atoll (const char *);

#ifndef __STRICT_ANSI__
  long long  __cdecl wtoll (const wchar_t *);
  char *__cdecl lltoa (long long, char *, цео);
  char *__cdecl ulltoa (unsigned long long , char *, цео);
  wchar_t *__cdecl lltow (long long, wchar_t *, цео);
  wchar_t *__cdecl ulltow (unsigned long long, wchar_t *, цео);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE long long  __cdecl atoll (const char * _c) { врати _atoi64 (_c); }
  __CRT_INLINE char *__cdecl lltoa (long long _n, char * _c, цео _i) { врати _i64toa (_n, _c, _i); }
  __CRT_INLINE char *__cdecl ulltoa (unsigned long long _n, char * _c, цео _i) { врати _ui64toa (_n, _c, _i); }
  __CRT_INLINE long long  __cdecl wtoll (const wchar_t * _w) { врати _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (long long _n, wchar_t * _w, цео _i) { врати _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (unsigned long long _n, wchar_t * _w, цео _i) { врати _ui64tow (_n, _w, _i); }
#endif /* (__STRICT_ANSI__)  */

#endif /* !__NO_ISOCEXT */

#ifdef __cplusplus
}
#endif

#pragma pack(pop)

#include <sec_api/stdlib_s.h>
#include <malloc.h>

#endif
