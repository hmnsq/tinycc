/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB
#define _INC_STDLIB

#अन्तर्भाव <_mingw.h>
#अन्तर्भाव <limits.h>

#pragma pack(थप,_CRT_PACKING)

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
  } भाग_प्रकार;

  प्रकारनिर्देश संरचना _ldiv_t {
    दीर्घ quot;
    दीर्घ rem;
  } द_भाग_प्रकार;
#endif

#ifndef _CRT_DOUBLE_DEC
#define _CRT_DOUBLE_DEC

#pragma pack(4)
  प्रकारनिर्देश संरचना {
    अचिन्हित वर्ण ld[10];
  } _LDOUBLE;
#pragma pack()

#define _PTR_LD(x) ((अचिन्हित वर्ण *)(&(x)->ld))

  प्रकारनिर्देश संरचना {
    द्विगुण x;
  } _CRT_DOUBLE;

  प्रकारनिर्देश संरचना {
    भिन्न f;
  } _CRT_FLOAT;

#pragma थप_macro("long")
#undef दीर्घ

  प्रकारनिर्देश संरचना {
    दीर्घ द्विगुण x;
  } _LONGDOUBLE;

#pragma झिक_macro("long")

#pragma pack(4)
  प्रकारनिर्देश संरचना {
    अचिन्हित वर्ण ld12[12];
  } _LDBL12;
#pragma pack()
#endif

#define अक्रम_उच्च 0x7fff

#ifndef MB_CUR_MAX
#define MB_CUR_MAX ___mb_cur_max_func()
#ifndef __mb_cur_max
#ifdef _MSVCRT_
  बाह्य पूर्णाङ्क __mb_cur_max;
#अन्यथा
#define __mb_cur_max    (*_imp____mb_cur_max)
  बाह्य पूर्णाङ्क *_imp____mb_cur_max;
#endif
#endif
#ifdef _MSVCRT_
  बाह्य पूर्णाङ्क __mbcur_max;
#define ___mb_cur_max_func() (__mb_cur_max)
#अन्यथा
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

#define WRITE_ABORT_सन्देश 0x1
#define _CALL_REPORTFAULT 0x2

#define _MAX_ENV 32767

  प्रकारनिर्देश शून्य (__cdecl *_purecall_handler)(शून्य);

  _CRTIMP _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(शून्य);

  प्रकारनिर्देश शून्य (__cdecl *_invalid_parameter_handler)(अचर ब_अक्षर_प्रकार *,अचर ब_अक्षर_प्रकार *,अचर ब_अक्षर_प्रकार *,अचिन्हित पूर्णाङ्क,uintptr_t);
  _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(शून्य);

#ifndef _CRT_ERRNO_DEFINED
#define _CRT_ERRNO_DEFINED
  _CRTIMP पूर्णाङ्क *__cdecl _errno(शून्य);
#define त्रुटि_सं (*_errno())
  errno_t __cdecl _set_errno(पूर्णाङ्क मान_2);
  errno_t __cdecl _get_errno(पूर्णाङ्क *मान_2);
#endif
  _CRTIMP अचिन्हित दीर्घ *__cdecl __doserrno(शून्य);
#define _doserrno (*__doserrno())
  errno_t __cdecl _set_doserrno(अचिन्हित दीर्घ मान_2);
  errno_t __cdecl _get_doserrno(अचिन्हित दीर्घ *मान_2);
#ifdef _MSVCRT_
  बाह्य वर्ण *_sys_errlist[];
  बाह्य पूर्णाङ्क _sys_nerr;
#अन्यथा
  _CRTIMP वर्ण *_sys_errlist[1];
  _CRTIMP पूर्णाङ्क _sys_nerr;
#endif
#यदि (defined(_X86_) && !defined(__x86_64))
  _CRTIMP पूर्णाङ्क *__cdecl __p___argc(शून्य);
  _CRTIMP वर्ण ***__cdecl __p___argv(शून्य);
  _CRTIMP ब_अक्षर_प्रकार ***__cdecl __p___wargv(शून्य);
  _CRTIMP वर्ण ***__cdecl __p__environ(शून्य);
  _CRTIMP ब_अक्षर_प्रकार ***__cdecl __p__wenviron(शून्य);
  _CRTIMP वर्ण **__cdecl __p__pgmptr(शून्य);
  _CRTIMP ब_अक्षर_प्रकार **__cdecl __p__wpgmptr(शून्य);
#endif
#ifndef __argc
#ifdef _MSVCRT_
  बाह्य पूर्णाङ्क __argc;
#अन्यथा
#define __argc (*_imp____argc)
  बाह्य पूर्णाङ्क *_imp____argc;
#endif
#endif
#ifndef __argv
#ifdef _MSVCRT_
  बाह्य वर्ण **__argv;
#अन्यथा
#define __argv  (*_imp____argv)
  बाह्य वर्ण ***_imp____argv;
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
  बाह्य वर्ण **environ;
#अन्यथा
#ifndef _environ
#ifdef _MSVCRT_
  बाह्य वर्ण **_environ;
#अन्यथा
#define _environ (*_imp___environ)
  बाह्य वर्ण ***_imp___environ;
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

#यदि defined __aarch64__
/* something does not work using those from msvcrt.dll */
# undef __argc
# undef __argv
# undef __wargv
# undef _wenviron
# undef _environ
बाह्य पूर्णाङ्क __argc;
बाह्य वर्ण **__argv;
बाह्य ब_अक्षर_प्रकार **__wargv;
बाह्य वर्ण **_environ;
बाह्य ब_अक्षर_प्रकार **_wenviron;
#endif

#ifndef _pgmptr
#ifdef _MSVCRT_
  बाह्य वर्ण *_pgmptr;
#अन्यथा
#define _pgmptr (*_imp___pgmptr)
  बाह्य वर्ण **_imp___pgmptr;
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
  errno_t __cdecl _get_pgmptr(वर्ण **मान_2);
  errno_t __cdecl _get_wpgmptr(ब_अक्षर_प्रकार **मान_2);
#ifndef _fmode
#ifdef _MSVCRT_
  बाह्य पूर्णाङ्क _fmode;
#अन्यथा
#define _fmode  (*_imp___fmode)
  बाह्य पूर्णाङ्क *_imp___fmode;
#endif
#endif
  _CRTIMP errno_t __cdecl _set_fmode(पूर्णाङ्क _Mode);
  _CRTIMP errno_t __cdecl _get_fmode(पूर्णाङ्क *_PMode);

#ifndef _osplatform
#ifdef _MSVCRT_
  बाह्य अचिन्हित पूर्णाङ्क _osplatform;
#अन्यथा
#define _osplatform (*_imp___osplatform)
  बाह्य अचिन्हित पूर्णाङ्क *_imp___osplatform;
#endif
#endif

#ifndef _osver
#ifdef _MSVCRT_
  बाह्य अचिन्हित पूर्णाङ्क _osver;
#अन्यथा
#define _osver  (*_imp___osver)
  बाह्य अचिन्हित पूर्णाङ्क *_imp___osver;
#endif
#endif

#ifndef _winver
#ifdef _MSVCRT_
  बाह्य अचिन्हित पूर्णाङ्क _winver;
#अन्यथा
#define _winver (*_imp___winver)
  बाह्य अचिन्हित पूर्णाङ्क *_imp___winver;
#endif
#endif

#ifndef _winmajor
#ifdef _MSVCRT_
  बाह्य अचिन्हित पूर्णाङ्क _winmajor;
#अन्यथा
#define _winmajor       (*_imp___winmajor)
  बाह्य अचिन्हित पूर्णाङ्क *_imp___winmajor;
#endif
#endif

#ifndef _winminor
#ifdef _MSVCRT_
  बाह्य अचिन्हित पूर्णाङ्क _winminor;
#अन्यथा
#define _winminor       (*_imp___winminor)
  बाह्य अचिन्हित पूर्णाङ्क *_imp___winminor;
#endif
#endif

  errno_t __cdecl _get_osplatform(अचिन्हित पूर्णाङ्क *मान_2);
  errno_t __cdecl _get_osver(अचिन्हित पूर्णाङ्क *मान_2);
  errno_t __cdecl _get_winver(अचिन्हित पूर्णाङ्क *मान_2);
  errno_t __cdecl _get_winmajor(अचिन्हित पूर्णाङ्क *मान_2);
  errno_t __cdecl _get_winminor(अचिन्हित पूर्णाङ्क *मान_2);
#ifndef _countof
#ifndef __cplusplus
#define _countof(_Array) (परिमाण(_Array) / परिमाण(_Array[0]))
#अन्यथा
  बाह्य "C++" {
    ढाँचा <typename _CountofType,माप_प्रकार _SizeOfArray> वर्ण (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];
#define _countof(_Array) परिमाण(*__countof_helper(_Array))
  }
#endif
#endif

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  शून्य __cdecl __MINGW_NOTHROW निकास(पूर्णाङ्क _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP शून्य __cdecl __MINGW_NOTHROW _exit(पूर्णाङ्क _Code) __MINGW_ATTRIB_NORETURN;
#यदि !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  शून्य __cdecl _Exit(पूर्णाङ्क) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN शून्य  __cdecl _Exit(पूर्णाङ्क status)
  {  _exit(status); }
#endif

#pragma थप_macro("abort")
#undef पात
  शून्य __cdecl __declspec(noreturn) पात(शून्य);
#pragma झिक_macro("abort")

#endif

  _CRTIMP अचिन्हित पूर्णाङ्क __cdecl _set_abort_behavior(अचिन्हित पूर्णाङ्क _Flags,अचिन्हित पूर्णाङ्क _Mask);

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  पूर्णाङ्क __cdecl असल(पूर्णाङ्क _X);
  दीर्घ __cdecl द_असल(दीर्घ _X);
#endif

#यदि _INTEGRAL_MAX_BITS >= 64
  __int64 __cdecl _abs64(__int64);
#endif
  पूर्णाङ्क __cdecl निकास_पर(शून्य (__cdecl *)(शून्य));
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  द्विगुण __cdecl म_से_भ(अचर वर्ण *_String);
  द्विगुण __cdecl _atof_l(अचर वर्ण *_String,_locale_t _Locale);
#endif
  पूर्णाङ्क __cdecl म_से_प(अचर वर्ण *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _atoi_l(अचर वर्ण *_Str,_locale_t _Locale);
  दीर्घ __cdecl म_से_द(अचर वर्ण *_Str);
  _CRTIMP दीर्घ __cdecl _atol_l(अचर वर्ण *_Str,_locale_t _Locale);
#ifndef _CRT_ALGO_DEFINED
#define _CRT_ALGO_DEFINED
  शून्य *__cdecl द्वा_खोज(अचर शून्य *साँचो_2,अचर शून्य *_Base,माप_प्रकार अङ्क_Of_Elements,माप_प्रकार _SizeOfElements,पूर्णाङ्क (__cdecl *_PtFuncCompare)(अचर शून्य *,अचर शून्य *));
  शून्य __cdecl क्विक(शून्य *_Base,माप_प्रकार अङ्क_Of_Elements,माप_प्रकार _SizeOfElements,पूर्णाङ्क (__cdecl *_PtFuncCompare)(अचर शून्य *,अचर शून्य *));
#endif
  अचिन्हित लघु __cdecl _byteswap_ushort(अचिन्हित लघु _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#यदि _INTEGRAL_MAX_BITS >= 64
  अचिन्हित __int64 __cdecl _byteswap_uint64(अचिन्हित __int64 _Int64);
#endif
  भाग_प्रकार __cdecl भाग(पूर्णाङ्क _Numerator,पूर्णाङ्क _Denominator);
  वर्ण *__cdecl दो_पर्या(अचर वर्ण *_VarName);
  _CRTIMP वर्ण *__cdecl _itoa(पूर्णाङ्क मान_2,वर्ण *_Dest,पूर्णाङ्क _Radix);
#यदि _INTEGRAL_MAX_BITS >= 64
  _CRTIMP वर्ण *__cdecl _i64toa(__int64 _Val,वर्ण *_DstBuf,पूर्णाङ्क _Radix);
  _CRTIMP वर्ण *__cdecl _ui64toa(अचिन्हित __int64 _Val,वर्ण *_DstBuf,पूर्णाङ्क _Radix);
  _CRTIMP __int64 __cdecl _atoi64(अचर वर्ण *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(अचर वर्ण *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(अचर वर्ण *_String,वर्ण **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(अचर वर्ण *_String,वर्ण **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
  _CRTIMP अचिन्हित __int64 __cdecl _strtoui64(अचर वर्ण *_String,वर्ण **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP अचिन्हित __int64 __cdecl _strtoui64_l(अचर वर्ण *_String,वर्ण **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
#endif
  द_भाग_प्रकार __cdecl द_भाग(दीर्घ _Numerator,दीर्घ _Denominator);
  _CRTIMP वर्ण *__cdecl _ltoa(दीर्घ मान_2,वर्ण *_Dest,पूर्णाङ्क _Radix);
  पूर्णाङ्क __cdecl mblen(अचर वर्ण *_Ch,माप_प्रकार Max_गन्ती);
  _CRTIMP पूर्णाङ्क __cdecl _mblen_l(अचर वर्ण *_Ch,माप_प्रकार Max_गन्ती,_locale_t _Locale);
  _CRTIMP माप_प्रकार __cdecl _mbstrlen(अचर वर्ण *_Str);
  _CRTIMP माप_प्रकार __cdecl _mbstrlen_l(अचर वर्ण *_Str,_locale_t _Locale);
  _CRTIMP माप_प्रकार __cdecl _mbstrnlen(अचर वर्ण *_Str,माप_प्रकार Max_गन्ती);
  _CRTIMP माप_प्रकार __cdecl _mbstrnlen_l(अचर वर्ण *_Str,माप_प्रकार Max_गन्ती,_locale_t _Locale);
  पूर्णाङ्क __cdecl mbtowc(ब_अक्षर_प्रकार *_DstCh,अचर वर्ण *_SrcCh,माप_प्रकार _SrcSizeInBytes);
  _CRTIMP पूर्णाङ्क __cdecl _mbtowc_l(ब_अक्षर_प्रकार *_DstCh,अचर वर्ण *_SrcCh,माप_प्रकार _SrcSizeInBytes,_locale_t _Locale);
  माप_प्रकार __cdecl mbstowcs(ब_अक्षर_प्रकार *_Dest,अचर वर्ण *_Source,माप_प्रकार Max_गन्ती);
  _CRTIMP माप_प्रकार __cdecl _mbstowcs_l(ब_अक्षर_प्रकार *_Dest,अचर वर्ण *_Source,माप_प्रकार Max_गन्ती,_locale_t _Locale);
  पूर्णाङ्क __cdecl अक्रम(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _set_error_mode(पूर्णाङ्क _Mode);
  शून्य __cdecl बेक्रम(अचिन्हित पूर्णाङ्क _Seed);
  द्विगुण __cdecl म_से_भग्न(अचर वर्ण *_Str,वर्ण **_EndPtr);
#यदि !defined __NO_ISOCEXT  /* in libmingwex.a */
#यदि __TINYC__
  __CRT_INLINE भिन्न __cdecl strtof (अचर वर्ण *p, वर्ण ** e) { फर्काऊ म_से_भग्न(p, e); }
  __CRT_INLINE दीर्घ द्विगुण __cdecl strtold(अचर वर्ण *p, वर्ण ** e) { फर्काऊ म_से_भग्न(p, e); }
#अन्यथा
  भिन्न __cdecl strtof (अचर वर्ण * __restrict__, वर्ण ** __restrict__);
  दीर्घ द्विगुण __cdecl strtold(अचर वर्ण * __restrict__, वर्ण ** __restrict__);
#endif
#अन्यथा
  भिन्न __cdecl strtof(अचर वर्ण *nptr, वर्ण **endptr);
#endif /* __NO_ISOCEXT */
  _CRTIMP द्विगुण __cdecl _strtod_l(अचर वर्ण *_Str,वर्ण **_EndPtr,_locale_t _Locale);
  दीर्घ __cdecl म_से_दीर्घ(अचर वर्ण *_Str,वर्ण **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP दीर्घ __cdecl _strtol_l(अचर वर्ण *_Str,वर्ण **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
  अचिन्हित दीर्घ __cdecl म_से_अदीर्घ(अचर वर्ण *_Str,वर्ण **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP अचिन्हित दीर्घ __cdecl _strtoul_l(अचर वर्ण *_Str,वर्ण **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  पूर्णाङ्क __cdecl प्रणाली(अचर वर्ण *_Command);
#endif
  _CRTIMP वर्ण *__cdecl _ultoa(अचिन्हित दीर्घ मान_2,वर्ण *_Dest,पूर्णाङ्क _Radix);
  पूर्णाङ्क __cdecl wctomb(वर्ण *_MbCh,ब_अक्षर_प्रकार _WCh);
  _CRTIMP पूर्णाङ्क __cdecl _wctomb_l(वर्ण *_MbCh,ब_अक्षर_प्रकार _WCh,_locale_t _Locale);
  माप_प्रकार __cdecl wcstombs(वर्ण *_Dest,अचर ब_अक्षर_प्रकार *_Source,माप_प्रकार Max_गन्ती);
  _CRTIMP माप_प्रकार __cdecl _wcstombs_l(वर्ण *_Dest,अचर ब_अक्षर_प्रकार *_Source,माप_प्रकार Max_गन्ती,_locale_t _Locale);

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  शून्य *__cdecl सुस्मृति(माप_प्रकार अङ्क_Of_Elements,माप_प्रकार _SizeOfElements);
  शून्य __cdecl मुक्त(शून्य *_Memory);
  शून्य *__cdecl दो_स्मृति(माप_प्रकार _Size);
  शून्य *__cdecl पुनः_स्मृति(शून्य *_Memory,माप_प्रकार _NewSize);
  _CRTIMP शून्य *__cdecl _recalloc(शून्य *_Memory,माप_प्रकार गन्ती_5,माप_प्रकार _Size);
  _CRTIMP शून्य __cdecl _aligned_free(शून्य *_Memory);
  _CRTIMP शून्य *__cdecl _aligned_malloc(माप_प्रकार _Size,माप_प्रकार _Alignment);
  _CRTIMP शून्य *__cdecl _aligned_offset_malloc(माप_प्रकार _Size,माप_प्रकार _Alignment,माप_प्रकार _Offset);
  _CRTIMP शून्य *__cdecl _aligned_realloc(शून्य *_Memory,माप_प्रकार _Size,माप_प्रकार _Alignment);
  _CRTIMP शून्य *__cdecl _aligned_recalloc(शून्य *_Memory,माप_प्रकार गन्ती_5,माप_प्रकार _Size,माप_प्रकार _Alignment);
  _CRTIMP शून्य *__cdecl _aligned_offset_realloc(शून्य *_Memory,माप_प्रकार _Size,माप_प्रकार _Alignment,माप_प्रकार _Offset);
  _CRTIMP शून्य *__cdecl _aligned_offset_recalloc(शून्य *_Memory,माप_प्रकार गन्ती_5,माप_प्रकार _Size,माप_प्रकार _Alignment,माप_प्रकार _Offset);
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP ब_अक्षर_प्रकार *__cdecl _itow(पूर्णाङ्क मान_2,ब_अक्षर_प्रकार *_Dest,पूर्णाङ्क _Radix);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _ltow(दीर्घ मान_2,ब_अक्षर_प्रकार *_Dest,पूर्णाङ्क _Radix);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _ultow(अचिन्हित दीर्घ मान_2,ब_अक्षर_प्रकार *_Dest,पूर्णाङ्क _Radix);
  द्विगुण __cdecl wcstod(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr);
  भिन्न __cdecl wcstof(अचर ब_अक्षर_प्रकार *nptr, ब_अक्षर_प्रकार **endptr);
#यदि !defined __NO_ISOCEXT /* in libmingwex.a */
  भिन्न __cdecl wcstof( अचर ब_अक्षर_प्रकार * __restrict__, ब_अक्षर_प्रकार ** __restrict__);
  दीर्घ द्विगुण __cdecl wcstold(अचर ब_अक्षर_प्रकार * __restrict__, ब_अक्षर_प्रकार ** __restrict__);
#endif /* __NO_ISOCEXT */
  _CRTIMP द्विगुण __cdecl _wcstod_l(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,_locale_t _Locale);
  दीर्घ __cdecl wcstol(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP दीर्घ __cdecl _wcstol_l(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
  अचिन्हित दीर्घ __cdecl wcstoul(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP अचिन्हित दीर्घ __cdecl _wcstoul_l(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wgetenv(अचर ब_अक्षर_प्रकार *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP पूर्णाङ्क __cdecl _wsystem(अचर ब_अक्षर_प्रकार *_Command);
#endif
  _CRTIMP द्विगुण __cdecl _wtof(अचर ब_अक्षर_प्रकार *_Str);
  _CRTIMP द्विगुण __cdecl _wtof_l(अचर ब_अक्षर_प्रकार *_Str,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wtoi(अचर ब_अक्षर_प्रकार *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _wtoi_l(अचर ब_अक्षर_प्रकार *_Str,_locale_t _Locale);
  _CRTIMP दीर्घ __cdecl _wtol(अचर ब_अक्षर_प्रकार *_Str);
  _CRTIMP दीर्घ __cdecl _wtol_l(अचर ब_अक्षर_प्रकार *_Str,_locale_t _Locale);

#यदि _INTEGRAL_MAX_BITS >= 64
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _i64tow(__int64 _Val,ब_अक्षर_प्रकार *_DstBuf,पूर्णाङ्क _Radix);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _ui64tow(अचिन्हित __int64 _Val,ब_अक्षर_प्रकार *_DstBuf,पूर्णाङ्क _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(अचर ब_अक्षर_प्रकार *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(अचर ब_अक्षर_प्रकार *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
  _CRTIMP अचिन्हित __int64 __cdecl _wcstoui64(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP अचिन्हित __int64 __cdecl _wcstoui64_l(अचर ब_अक्षर_प्रकार *_Str ,ब_अक्षर_प्रकार **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#define _CVTBUFSIZE (309+40)
  _CRTIMP वर्ण *__cdecl _fullpath(वर्ण *_FullPath,अचर वर्ण *_Path,माप_प्रकार _SizeInBytes);
  _CRTIMP वर्ण *__cdecl _ecvt(द्विगुण _Val,पूर्णाङ्क अङ्क_Of_Digits,पूर्णाङ्क *_PtDec,पूर्णाङ्क *_PtSign);
  _CRTIMP वर्ण *__cdecl _fcvt(द्विगुण _Val,पूर्णाङ्क अङ्क_Of_Dec,पूर्णाङ्क *_PtDec,पूर्णाङ्क *_PtSign);
  _CRTIMP वर्ण *__cdecl _gcvt(द्विगुण _Val,पूर्णाङ्क अङ्क_Of_Digits,वर्ण *_DstBuf);
  _CRTIMP पूर्णाङ्क __cdecl _atodbl(_CRT_DOUBLE *_Result,वर्ण *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _atoldbl(_LDOUBLE *_Result,वर्ण *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _atoflt(_CRT_FLOAT *_Result,वर्ण *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _atodbl_l(_CRT_DOUBLE *_Result,वर्ण *_Str,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _atoldbl_l(_LDOUBLE *_Result,वर्ण *_Str,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _atoflt_l(_CRT_FLOAT *_Result,वर्ण *_Str,_locale_t _Locale);
  अचिन्हित दीर्घ __cdecl _lrotl(अचिन्हित दीर्घ _Val,पूर्णाङ्क _Shift);
  अचिन्हित दीर्घ __cdecl _lrotr(अचिन्हित दीर्घ _Val,पूर्णाङ्क _Shift);
  _CRTIMP शून्य __cdecl _makepath(वर्ण *_Path,अचर वर्ण *_Drive,अचर वर्ण *_Dir,अचर वर्ण *_Filename,अचर वर्ण *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  शून्य __cdecl लिखो_त्रुटि(अचर वर्ण *Err_सन्देश);
#endif
  _CRTIMP पूर्णाङ्क __cdecl _putenv(अचर वर्ण *_EnvString);
  अचिन्हित पूर्णाङ्क __cdecl _rotl(अचिन्हित पूर्णाङ्क _Val,पूर्णाङ्क _Shift);
#यदि _INTEGRAL_MAX_BITS >= 64
  अचिन्हित __int64 __cdecl _rotl64(अचिन्हित __int64 _Val,पूर्णाङ्क _Shift);
#endif
  अचिन्हित पूर्णाङ्क __cdecl _rotr(अचिन्हित पूर्णाङ्क _Val,पूर्णाङ्क _Shift);
#यदि _INTEGRAL_MAX_BITS >= 64
  अचिन्हित __int64 __cdecl _rotr64(अचिन्हित __int64 _Val,पूर्णाङ्क _Shift);
#endif
  _CRTIMP शून्य __cdecl _searchenv(अचर वर्ण *_Filename,अचर वर्ण *_EnvVar,वर्ण *_ResultPath);
  _CRTIMP शून्य __cdecl _splitpath(अचर वर्ण *_FullPath,वर्ण *_Drive,वर्ण *_Dir,वर्ण *_Filename,वर्ण *_Ext);
  _CRTIMP शून्य __cdecl _swab(वर्ण *_Buf1,वर्ण *_Buf2,पूर्णाङ्क _SizeInBytes);

#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wfullpath(ब_अक्षर_प्रकार *_FullPath,अचर ब_अक्षर_प्रकार *_Path,माप_प्रकार Size_In_शब्दहरू);
  _CRTIMP शून्य __cdecl _wmakepath(ब_अक्षर_प्रकार *_ResultPath,अचर ब_अक्षर_प्रकार *_Drive,अचर ब_अक्षर_प्रकार *_Dir,अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP शून्य __cdecl _wperror(अचर ब_अक्षर_प्रकार *Err_सन्देश);
#endif
  _CRTIMP पूर्णाङ्क __cdecl _wputenv(अचर ब_अक्षर_प्रकार *_EnvString);
  _CRTIMP शून्य __cdecl _wsearchenv(अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *_EnvVar,ब_अक्षर_प्रकार *_ResultPath);
  _CRTIMP शून्य __cdecl _wsplitpath(अचर ब_अक्षर_प्रकार *_FullPath,ब_अक्षर_प्रकार *_Drive,ब_अक्षर_प्रकार *_Dir,ब_अक्षर_प्रकार *_Filename,ब_अक्षर_प्रकार *_Ext);
#endif

  _CRTIMP शून्य __cdecl _beep(अचिन्हित _Frequency,अचिन्हित _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP शून्य __cdecl _seterrormode(पूर्णाङ्क _Mode) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP शून्य __cdecl _sleep(अचिन्हित दीर्घ _Duration) __MINGW_ATTRIB_DEPRECATED;
#endif

#ifndef NO_OLDNAMES
#ifndef _POSIX_
#यदि 0
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
  वर्ण *__cdecl ecvt(द्विगुण _Val,पूर्णाङ्क अङ्क_Of_Digits,पूर्णाङ्क *_PtDec,पूर्णाङ्क *_PtSign);
  वर्ण *__cdecl fcvt(द्विगुण _Val,पूर्णाङ्क अङ्क_Of_Dec,पूर्णाङ्क *_PtDec,पूर्णाङ्क *_PtSign);
  वर्ण *__cdecl gcvt(द्विगुण _Val,पूर्णाङ्क अङ्क_Of_Digits,वर्ण *_DstBuf);
  वर्ण *__cdecl itoa(पूर्णाङ्क _Val,वर्ण *_DstBuf,पूर्णाङ्क _Radix);
  वर्ण *__cdecl ltoa(दीर्घ _Val,वर्ण *_DstBuf,पूर्णाङ्क _Radix);
  पूर्णाङ्क __cdecl putenv(अचर वर्ण *_EnvString);
  शून्य __cdecl swab(वर्ण *_Buf1,वर्ण *_Buf2,पूर्णाङ्क _SizeInBytes);
  वर्ण *__cdecl ultoa(अचिन्हित दीर्घ _Val,वर्ण *_Dstbuf,पूर्णाङ्क _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#endif
#endif

#यदि !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  प्रकारनिर्देश संरचना { दीर्घ दीर्घ quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(दीर्घ दीर्घ, दीर्घ दीर्घ);

  __CRT_INLINE दीर्घ दीर्घ __cdecl llabs(दीर्घ दीर्घ _j) { फर्काऊ (_j >= 0 ? _j : -_j); }

 #ifdef __TINYC__ /* gr */
  #define strtoll _strtoi64
  #define strtoull _strtoui64
 #अन्यथा
  दीर्घ दीर्घ  __cdecl strtoll(अचर वर्ण* __restrict__, वर्ण** __restrict, पूर्णाङ्क);
  अचिन्हित दीर्घ दीर्घ  __cdecl strtoull(अचर वर्ण* __restrict__, वर्ण** __restrict__, पूर्णाङ्क);
 #endif

  /* these are stubs for MS _i64 versions */
  दीर्घ दीर्घ  __cdecl atoll (अचर वर्ण *);

#ifndef __STRICT_ANSI__
  दीर्घ दीर्घ  __cdecl wtoll (अचर ब_अक्षर_प्रकार *);
  वर्ण *__cdecl lltoa (दीर्घ दीर्घ, वर्ण *, पूर्णाङ्क);
  वर्ण *__cdecl ulltoa (अचिन्हित दीर्घ दीर्घ , वर्ण *, पूर्णाङ्क);
  ब_अक्षर_प्रकार *__cdecl lltow (दीर्घ दीर्घ, ब_अक्षर_प्रकार *, पूर्णाङ्क);
  ब_अक्षर_प्रकार *__cdecl ulltow (अचिन्हित दीर्घ दीर्घ, ब_अक्षर_प्रकार *, पूर्णाङ्क);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE दीर्घ दीर्घ  __cdecl atoll (अचर वर्ण * _c) { फर्काऊ _atoi64 (_c); }
  __CRT_INLINE वर्ण *__cdecl lltoa (दीर्घ दीर्घ _n, वर्ण * _c, पूर्णाङ्क _i) { फर्काऊ _i64toa (_n, _c, _i); }
  __CRT_INLINE वर्ण *__cdecl ulltoa (अचिन्हित दीर्घ दीर्घ _n, वर्ण * _c, पूर्णाङ्क _i) { फर्काऊ _ui64toa (_n, _c, _i); }
  __CRT_INLINE दीर्घ दीर्घ  __cdecl wtoll (अचर ब_अक्षर_प्रकार * _w) { फर्काऊ _wtoi64 (_w); }
  __CRT_INLINE ब_अक्षर_प्रकार *__cdecl lltow (दीर्घ दीर्घ _n, ब_अक्षर_प्रकार * _w, पूर्णाङ्क _i) { फर्काऊ _i64tow (_n, _w, _i); }
  __CRT_INLINE ब_अक्षर_प्रकार *__cdecl ulltow (अचिन्हित दीर्घ दीर्घ _n, ब_अक्षर_प्रकार * _w, पूर्णाङ्क _i) { फर्काऊ _ui64tow (_n, _w, _i); }
#endif /* (__STRICT_ANSI__)  */

#endif /* !__NO_ISOCEXT */

#ifdef __cplusplus
}
#endif

#pragma pack(झिक)

#अन्तर्भाव <sec_api/stdlib_s.h>
#अन्तर्भाव <malloc.h>

#endif
