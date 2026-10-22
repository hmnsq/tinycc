/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_STDLIB
#घोषणा _INC_STDLIB

#समावेश <_mingw.h>
#समावेश <limits.h>

#आशय pack(धकेलो,_CRT_PACKING)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित शून्य
#अगर_घोषित __cplusplus
#घोषणा शून्य 0
#अन्यथा
#घोषणा शून्य ((व्योम *)0)
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा निकास_सफल 0
#घोषणा निकास_त्रुटि 1

#अगर_अघोषित _ONEXIT_T_DEFINED
#घोषणा _ONEXIT_T_DEFINED

  प्रकार पूर्णांक (__cdecl *_onexit_t)(व्योम);

#अगर_अघोषित NO_OLDNAMES
#घोषणा onexit_t _onexit_t
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _DIV_T_DEFINED
#घोषणा _DIV_T_DEFINED

  प्रकार काष्ठा _div_t {
    पूर्णांक quot;
    पूर्णांक rem;
  } भाग_प्रकार;

  प्रकार काष्ठा _ldiv_t {
    दीर्घ quot;
    दीर्घ rem;
  } द_भाग_प्रकार;
#पूर्ण_अगर

#अगर_अघोषित _CRT_DOUBLE_DEC
#घोषणा _CRT_DOUBLE_DEC

#आशय pack(4)
  प्रकार काष्ठा {
    अचिन्हित अक्षर ld[10];
  } _LDOUBLE;
#आशय pack()

#घोषणा _PTR_LD(x) ((अचिन्हित अक्षर *)(&(x)->ld))

  प्रकार काष्ठा {
    द्विगुन x;
  } _CRT_DOUBLE;

  प्रकार काष्ठा {
    भग्न f;
  } _CRT_FLOAT;

#आशय धकेलो_macro("long")
#अघोषित दीर्घ

  प्रकार काष्ठा {
    दीर्घ द्विगुन x;
  } _LONGDOUBLE;

#आशय निकालो_macro("long")

#आशय pack(4)
  प्रकार काष्ठा {
    अचिन्हित अक्षर ld12[12];
  } _LDBL12;
#आशय pack()
#पूर्ण_अगर

#घोषणा अक्रम_उच्च 0x7fff

#अगर_अघोषित MB_CUR_MAX
#घोषणा MB_CUR_MAX ___mb_cur_max_func()
#अगर_अघोषित __mb_cur_max
#अगर_घोषित _MSVCRT_
  बाह्य पूर्णांक __mb_cur_max;
#अन्यथा
#घोषणा __mb_cur_max    (*_imp____mb_cur_max)
  बाह्य पूर्णांक *_imp____mb_cur_max;
#पूर्ण_अगर
#पूर्ण_अगर
#अगर_घोषित _MSVCRT_
  बाह्य पूर्णांक __mbcur_max;
#घोषणा ___mb_cur_max_func() (__mb_cur_max)
#अन्यथा
  बाह्य पूर्णांक* _imp____mbcur_max;
#घोषणा ___mb_cur_max_func() (*_imp____mb_cur_max)
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा __max(a,b) (((a) > (b)) ? (a) : (b))
#घोषणा __min(a,b) (((a) < (b)) ? (a) : (b))

#घोषणा _MAX_PATH 260
#घोषणा _MAX_DRIVE 3
#घोषणा _MAX_DIR 256
#घोषणा _MAX_FNAME 256
#घोषणा _MAX_EXT 256

#घोषणा _OUT_TO_DEFAULT 0
#घोषणा _OUT_TO_STDERR 1
#घोषणा _OUT_TO_MSGBOX 2
#घोषणा _REPORT_ERRMODE 3

#घोषणा WRITE_ABORT_संदेश 0x1
#घोषणा _CALL_REPORTFAULT 0x2

#घोषणा _MAX_ENV 32767

  प्रकार व्योम (__cdecl *_purecall_handler)(व्योम);

  _CRTIMP _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(व्योम);

  प्रकार व्योम (__cdecl *_invalid_parameter_handler)(स्थिर ब_अक्षर_प्रकार *,स्थिर ब_अक्षर_प्रकार *,स्थिर ब_अक्षर_प्रकार *,अचिन्हित पूर्णांक,uintptr_t);
  _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(व्योम);

#अगर_अघोषित _CRT_ERRNO_DEFINED
#घोषणा _CRT_ERRNO_DEFINED
  _CRTIMP पूर्णांक *__cdecl _errno(व्योम);
#घोषणा त्रुटि_सं (*_errno())
  errno_t __cdecl _set_errno(पूर्णांक मूल्य_2);
  errno_t __cdecl _get_errno(पूर्णांक *मूल्य_2);
#पूर्ण_अगर
  _CRTIMP अचिन्हित दीर्घ *__cdecl __doserrno(व्योम);
#घोषणा _doserrno (*__doserrno())
  errno_t __cdecl _set_doserrno(अचिन्हित दीर्घ मूल्य_2);
  errno_t __cdecl _get_doserrno(अचिन्हित दीर्घ *मूल्य_2);
#अगर_घोषित _MSVCRT_
  बाह्य अक्षर *_sys_errlist[];
  बाह्य पूर्णांक _sys_nerr;
#अन्यथा
  _CRTIMP अक्षर *_sys_errlist[1];
  _CRTIMP पूर्णांक _sys_nerr;
#पूर्ण_अगर
#अगर (defined(_X86_) && !defined(__x86_64))
  _CRTIMP पूर्णांक *__cdecl __p___argc(व्योम);
  _CRTIMP अक्षर ***__cdecl __p___argv(व्योम);
  _CRTIMP ब_अक्षर_प्रकार ***__cdecl __p___wargv(व्योम);
  _CRTIMP अक्षर ***__cdecl __p__environ(व्योम);
  _CRTIMP ब_अक्षर_प्रकार ***__cdecl __p__wenviron(व्योम);
  _CRTIMP अक्षर **__cdecl __p__pgmptr(व्योम);
  _CRTIMP ब_अक्षर_प्रकार **__cdecl __p__wpgmptr(व्योम);
#पूर्ण_अगर
#अगर_अघोषित __argc
#अगर_घोषित _MSVCRT_
  बाह्य पूर्णांक __argc;
#अन्यथा
#घोषणा __argc (*_imp____argc)
  बाह्य पूर्णांक *_imp____argc;
#पूर्ण_अगर
#पूर्ण_अगर
#अगर_अघोषित __argv
#अगर_घोषित _MSVCRT_
  बाह्य अक्षर **__argv;
#अन्यथा
#घोषणा __argv  (*_imp____argv)
  बाह्य अक्षर ***_imp____argv;
#पूर्ण_अगर
#पूर्ण_अगर
#अगर_अघोषित __wargv
#अगर_घोषित _MSVCRT_
  बाह्य ब_अक्षर_प्रकार **__wargv;
#अन्यथा
#घोषणा __wargv (*_imp____wargv)
  बाह्य ब_अक्षर_प्रकार ***_imp____wargv;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित _POSIX_
  बाह्य अक्षर **environ;
#अन्यथा
#अगर_अघोषित _environ
#अगर_घोषित _MSVCRT_
  बाह्य अक्षर **_environ;
#अन्यथा
#घोषणा _environ (*_imp___environ)
  बाह्य अक्षर ***_imp___environ;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _wenviron
#अगर_घोषित _MSVCRT_
  बाह्य ब_अक्षर_प्रकार **_wenviron;
#अन्यथा
#घोषणा _wenviron       (*_imp___wenviron)
  बाह्य ब_अक्षर_प्रकार ***_imp___wenviron;
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#अगर defined __aarch64__
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
#पूर्ण_अगर

#अगर_अघोषित _pgmptr
#अगर_घोषित _MSVCRT_
  बाह्य अक्षर *_pgmptr;
#अन्यथा
#घोषणा _pgmptr (*_imp___pgmptr)
  बाह्य अक्षर **_imp___pgmptr;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _wpgmptr
#अगर_घोषित _MSVCRT_
  बाह्य ब_अक्षर_प्रकार *_wpgmptr;
#अन्यथा
#घोषणा _wpgmptr        (*_imp___wpgmptr)
  बाह्य ब_अक्षर_प्रकार **_imp___wpgmptr;
#पूर्ण_अगर
#पूर्ण_अगर
  errno_t __cdecl _get_pgmptr(अक्षर **मूल्य_2);
  errno_t __cdecl _get_wpgmptr(ब_अक्षर_प्रकार **मूल्य_2);
#अगर_अघोषित _fmode
#अगर_घोषित _MSVCRT_
  बाह्य पूर्णांक _fmode;
#अन्यथा
#घोषणा _fmode  (*_imp___fmode)
  बाह्य पूर्णांक *_imp___fmode;
#पूर्ण_अगर
#पूर्ण_अगर
  _CRTIMP errno_t __cdecl _set_fmode(पूर्णांक _Mode);
  _CRTIMP errno_t __cdecl _get_fmode(पूर्णांक *_PMode);

#अगर_अघोषित _osplatform
#अगर_घोषित _MSVCRT_
  बाह्य अचिन्हित पूर्णांक _osplatform;
#अन्यथा
#घोषणा _osplatform (*_imp___osplatform)
  बाह्य अचिन्हित पूर्णांक *_imp___osplatform;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _osver
#अगर_घोषित _MSVCRT_
  बाह्य अचिन्हित पूर्णांक _osver;
#अन्यथा
#घोषणा _osver  (*_imp___osver)
  बाह्य अचिन्हित पूर्णांक *_imp___osver;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _winver
#अगर_घोषित _MSVCRT_
  बाह्य अचिन्हित पूर्णांक _winver;
#अन्यथा
#घोषणा _winver (*_imp___winver)
  बाह्य अचिन्हित पूर्णांक *_imp___winver;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _winmajor
#अगर_घोषित _MSVCRT_
  बाह्य अचिन्हित पूर्णांक _winmajor;
#अन्यथा
#घोषणा _winmajor       (*_imp___winmajor)
  बाह्य अचिन्हित पूर्णांक *_imp___winmajor;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _winminor
#अगर_घोषित _MSVCRT_
  बाह्य अचिन्हित पूर्णांक _winminor;
#अन्यथा
#घोषणा _winminor       (*_imp___winminor)
  बाह्य अचिन्हित पूर्णांक *_imp___winminor;
#पूर्ण_अगर
#पूर्ण_अगर

  errno_t __cdecl _get_osplatform(अचिन्हित पूर्णांक *मूल्य_2);
  errno_t __cdecl _get_osver(अचिन्हित पूर्णांक *मूल्य_2);
  errno_t __cdecl _get_winver(अचिन्हित पूर्णांक *मूल्य_2);
  errno_t __cdecl _get_winmajor(अचिन्हित पूर्णांक *मूल्य_2);
  errno_t __cdecl _get_winminor(अचिन्हित पूर्णांक *मूल्य_2);
#अगर_अघोषित _countof
#अगर_अघोषित __cplusplus
#घोषणा _countof(_Array) (माप(_Array) / माप(_Array[0]))
#अन्यथा
  बाह्य "C++" {
    ढाँचा <typename _CountofType,माप_प्रकार आकार_Of_Array> अक्षर (*__countof_helper(UNALIGNED _CountofType (&_Array)[आकार_Of_Array]))[आकार_Of_Array];
#घोषणा _countof(_Array) माप(*__countof_helper(_Array))
  }
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _CRT_TERMINATE_DEFINED
#घोषणा _CRT_TERMINATE_DEFINED
  व्योम __cdecl __MINGW_NOTHROW निकास(पूर्णांक _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP व्योम __cdecl __MINGW_NOTHROW _निकास(पूर्णांक _Code) __MINGW_ATTRIB_NORETURN;
#अगर !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  व्योम __cdecl _Exit(पूर्णांक) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN व्योम  __cdecl _Exit(पूर्णांक status)
  {  _निकास(status); }
#पूर्ण_अगर

#आशय धकेलो_macro("abort")
#अघोषित पात
  व्योम __cdecl __declspec(noreturn) पात(व्योम);
#आशय निकालो_macro("abort")

#पूर्ण_अगर

  _CRTIMP अचिन्हित पूर्णांक __cdecl _set_abort_behavior(अचिन्हित पूर्णांक _Flags,अचिन्हित पूर्णांक _Mask);

#अगर_अघोषित _CRT_ABS_DEFINED
#घोषणा _CRT_ABS_DEFINED
  पूर्णांक __cdecl असल(पूर्णांक _X);
  दीर्घ __cdecl द_असल(दीर्घ _X);
#पूर्ण_अगर

#अगर _INTEGRAL_MAX_BITS >= 64
  __int64 __cdecl _abs64(__int64);
#पूर्ण_अगर
  पूर्णांक __cdecl निकास_पर(व्योम (__cdecl *)(व्योम));
#अगर_अघोषित _CRT_ATOF_DEFINED
#घोषणा _CRT_ATOF_DEFINED
  द्विगुन __cdecl म_से_भ(स्थिर अक्षर *_String);
  द्विगुन __cdecl _atof_l(स्थिर अक्षर *_String,_locale_t _Locale);
#पूर्ण_अगर
  पूर्णांक __cdecl म_से_प(स्थिर अक्षर *_Str);
  _CRTIMP पूर्णांक __cdecl _atoi_l(स्थिर अक्षर *_Str,_locale_t _Locale);
  दीर्घ __cdecl म_से_द(स्थिर अक्षर *_Str);
  _CRTIMP दीर्घ __cdecl _atol_l(स्थिर अक्षर *_Str,_locale_t _Locale);
#अगर_अघोषित _CRT_ALGO_DEFINED
#घोषणा _CRT_ALGO_DEFINED
  व्योम *__cdecl द्वा_खोज(स्थिर व्योम *कुंजी_2,स्थिर व्योम *_Base,माप_प्रकार अंक_Of_Elements,माप_प्रकार आकार_Of_Elements,पूर्णांक (__cdecl *_PtFuncCompare)(स्थिर व्योम *,स्थिर व्योम *));
  व्योम __cdecl क्विक(व्योम *_Base,माप_प्रकार अंक_Of_Elements,माप_प्रकार आकार_Of_Elements,पूर्णांक (__cdecl *_PtFuncCompare)(स्थिर व्योम *,स्थिर व्योम *));
#पूर्ण_अगर
  अचिन्हित लघु __cdecl _byteswap_ushort(अचिन्हित लघु _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#अगर _INTEGRAL_MAX_BITS >= 64
  अचिन्हित __int64 __cdecl _byteswap_uint64(अचिन्हित __int64 _Int64);
#पूर्ण_अगर
  भाग_प्रकार __cdecl भाग(पूर्णांक _Numerator,पूर्णांक _Denominator);
  अक्षर *__cdecl दो_पर्या(स्थिर अक्षर *_VarName);
  _CRTIMP अक्षर *__cdecl _itoa(पूर्णांक मूल्य_2,अक्षर *_Dest,पूर्णांक _Radix);
#अगर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP अक्षर *__cdecl _i64toa(__int64 _Val,अक्षर *_DstBuf,पूर्णांक _Radix);
  _CRTIMP अक्षर *__cdecl _ui64toa(अचिन्हित __int64 _Val,अक्षर *_DstBuf,पूर्णांक _Radix);
  _CRTIMP __int64 __cdecl _atoi64(स्थिर अक्षर *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(स्थिर अक्षर *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(स्थिर अक्षर *_String,अक्षर **_EndPtr,पूर्णांक _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(स्थिर अक्षर *_String,अक्षर **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
  _CRTIMP अचिन्हित __int64 __cdecl _strtoui64(स्थिर अक्षर *_String,अक्षर **_EndPtr,पूर्णांक _Radix);
  _CRTIMP अचिन्हित __int64 __cdecl _strtoui64_l(स्थिर अक्षर *_String,अक्षर **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
#पूर्ण_अगर
  द_भाग_प्रकार __cdecl द_भाग(दीर्घ _Numerator,दीर्घ _Denominator);
  _CRTIMP अक्षर *__cdecl _ltoa(दीर्घ मूल्य_2,अक्षर *_Dest,पूर्णांक _Radix);
  पूर्णांक __cdecl mblen(स्थिर अक्षर *_Ch,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _mblen_l(स्थिर अक्षर *_Ch,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP माप_प्रकार __cdecl _mbstrlen(स्थिर अक्षर *_Str);
  _CRTIMP माप_प्रकार __cdecl _mbstrlen_l(स्थिर अक्षर *_Str,_locale_t _Locale);
  _CRTIMP माप_प्रकार __cdecl _mbstrnlen(स्थिर अक्षर *_Str,माप_प्रकार Max_गिनती);
  _CRTIMP माप_प्रकार __cdecl _mbstrnlen_l(स्थिर अक्षर *_Str,माप_प्रकार Max_गिनती,_locale_t _Locale);
  पूर्णांक __cdecl mbtowc(ब_अक्षर_प्रकार *_DstCh,स्थिर अक्षर *_SrcCh,माप_प्रकार Src_आकार_In_Bytes);
  _CRTIMP पूर्णांक __cdecl _mbtowc_l(ब_अक्षर_प्रकार *_DstCh,स्थिर अक्षर *_SrcCh,माप_प्रकार Src_आकार_In_Bytes,_locale_t _Locale);
  माप_प्रकार __cdecl mbstowcs(ब_अक्षर_प्रकार *_Dest,स्थिर अक्षर *_Source,माप_प्रकार Max_गिनती);
  _CRTIMP माप_प्रकार __cdecl _mbstowcs_l(ब_अक्षर_प्रकार *_Dest,स्थिर अक्षर *_Source,माप_प्रकार Max_गिनती,_locale_t _Locale);
  पूर्णांक __cdecl अक्रम(व्योम);
  _CRTIMP पूर्णांक __cdecl _set_error_mode(पूर्णांक _Mode);
  व्योम __cdecl बेक्रम(अचिन्हित पूर्णांक _Seed);
  द्विगुन __cdecl म_से_भग्न(स्थिर अक्षर *_Str,अक्षर **_EndPtr);
#अगर !defined __NO_ISOCEXT  /* in libmingwex.a */
#अगर __TINYC__
  __CRT_INLINE भग्न __cdecl strtof (स्थिर अक्षर *p, अक्षर ** e) { वापस म_से_भग्न(p, e); }
  __CRT_INLINE दीर्घ द्विगुन __cdecl strtold(स्थिर अक्षर *p, अक्षर ** e) { वापस म_से_भग्न(p, e); }
#अन्यथा
  भग्न __cdecl strtof (स्थिर अक्षर * __restrict__, अक्षर ** __restrict__);
  दीर्घ द्विगुन __cdecl strtold(स्थिर अक्षर * __restrict__, अक्षर ** __restrict__);
#पूर्ण_अगर
#अन्यथा
  भग्न __cdecl strtof(स्थिर अक्षर *nptr, अक्षर **endptr);
#पूर्ण_अगर /* __NO_ISOCEXT */
  _CRTIMP द्विगुन __cdecl _strtod_l(स्थिर अक्षर *_Str,अक्षर **_EndPtr,_locale_t _Locale);
  दीर्घ __cdecl म_से_दीर्घ(स्थिर अक्षर *_Str,अक्षर **_EndPtr,पूर्णांक _Radix);
  _CRTIMP दीर्घ __cdecl _strtol_l(स्थिर अक्षर *_Str,अक्षर **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
  अचिन्हित दीर्घ __cdecl म_से_अदीर्घ(स्थिर अक्षर *_Str,अक्षर **_EndPtr,पूर्णांक _Radix);
  _CRTIMP अचिन्हित दीर्घ __cdecl _strtoul_l(स्थिर अक्षर *_Str,अक्षर **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
#अगर_अघोषित _CRT_SYSTEM_DEFINED
#घोषणा _CRT_SYSTEM_DEFINED
  पूर्णांक __cdecl प्रणाली(स्थिर अक्षर *_Command);
#पूर्ण_अगर
  _CRTIMP अक्षर *__cdecl _ultoa(अचिन्हित दीर्घ मूल्य_2,अक्षर *_Dest,पूर्णांक _Radix);
  पूर्णांक __cdecl wctomb(अक्षर *_MbCh,ब_अक्षर_प्रकार _WCh);
  _CRTIMP पूर्णांक __cdecl _wctomb_l(अक्षर *_MbCh,ब_अक्षर_प्रकार _WCh,_locale_t _Locale);
  माप_प्रकार __cdecl wcstombs(अक्षर *_Dest,स्थिर ब_अक्षर_प्रकार *_Source,माप_प्रकार Max_गिनती);
  _CRTIMP माप_प्रकार __cdecl _wcstombs_l(अक्षर *_Dest,स्थिर ब_अक्षर_प्रकार *_Source,माप_प्रकार Max_गिनती,_locale_t _Locale);

#अगर_अघोषित _CRT_ALLOCATION_DEFINED
#घोषणा _CRT_ALLOCATION_DEFINED
  व्योम *__cdecl सुस्मृति(माप_प्रकार अंक_Of_Elements,माप_प्रकार आकार_Of_Elements);
  व्योम __cdecl मुक्त(व्योम *_Memory);
  व्योम *__cdecl दो_स्मृति(माप_प्रकार आकार_4);
  व्योम *__cdecl पुनः_स्मृति(व्योम *_Memory,माप_प्रकार New_आकार);
  _CRTIMP व्योम *__cdecl _recalloc(व्योम *_Memory,माप_प्रकार गिनती_5,माप_प्रकार आकार_4);
  _CRTIMP व्योम __cdecl _aligned_free(व्योम *_Memory);
  _CRTIMP व्योम *__cdecl _aligned_malloc(माप_प्रकार आकार_4,माप_प्रकार _Alignment);
  _CRTIMP व्योम *__cdecl _aligned_offset_malloc(माप_प्रकार आकार_4,माप_प्रकार _Alignment,माप_प्रकार _Offset);
  _CRTIMP व्योम *__cdecl _aligned_realloc(व्योम *_Memory,माप_प्रकार आकार_4,माप_प्रकार _Alignment);
  _CRTIMP व्योम *__cdecl _aligned_recalloc(व्योम *_Memory,माप_प्रकार गिनती_5,माप_प्रकार आकार_4,माप_प्रकार _Alignment);
  _CRTIMP व्योम *__cdecl _aligned_offset_realloc(व्योम *_Memory,माप_प्रकार आकार_4,माप_प्रकार _Alignment,माप_प्रकार _Offset);
  _CRTIMP व्योम *__cdecl _aligned_offset_recalloc(व्योम *_Memory,माप_प्रकार गिनती_5,माप_प्रकार आकार_4,माप_प्रकार _Alignment,माप_प्रकार _Offset);
#पूर्ण_अगर

#अगर_अघोषित _WSTDLIB_DEFINED
#घोषणा _WSTDLIB_DEFINED

  _CRTIMP ब_अक्षर_प्रकार *__cdecl _itow(पूर्णांक मूल्य_2,ब_अक्षर_प्रकार *_Dest,पूर्णांक _Radix);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _ltow(दीर्घ मूल्य_2,ब_अक्षर_प्रकार *_Dest,पूर्णांक _Radix);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _ultow(अचिन्हित दीर्घ मूल्य_2,ब_अक्षर_प्रकार *_Dest,पूर्णांक _Radix);
  द्विगुन __cdecl wcstod(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr);
  भग्न __cdecl wcstof(स्थिर ब_अक्षर_प्रकार *nptr, ब_अक्षर_प्रकार **endptr);
#अगर !defined __NO_ISOCEXT /* in libmingwex.a */
  भग्न __cdecl wcstof( स्थिर ब_अक्षर_प्रकार * __restrict__, ब_अक्षर_प्रकार ** __restrict__);
  दीर्घ द्विगुन __cdecl wcstold(स्थिर ब_अक्षर_प्रकार * __restrict__, ब_अक्षर_प्रकार ** __restrict__);
#पूर्ण_अगर /* __NO_ISOCEXT */
  _CRTIMP द्विगुन __cdecl _wcstod_l(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,_locale_t _Locale);
  दीर्घ __cdecl wcstol(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix);
  _CRTIMP दीर्घ __cdecl _wcstol_l(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
  अचिन्हित दीर्घ __cdecl wcstoul(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix);
  _CRTIMP अचिन्हित दीर्घ __cdecl _wcstoul_l(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wgetenv(स्थिर ब_अक्षर_प्रकार *_VarName);
#अगर_अघोषित _CRT_WSYSTEM_DEFINED
#घोषणा _CRT_WSYSTEM_DEFINED
  _CRTIMP पूर्णांक __cdecl _wsystem(स्थिर ब_अक्षर_प्रकार *_Command);
#पूर्ण_अगर
  _CRTIMP द्विगुन __cdecl _wtof(स्थिर ब_अक्षर_प्रकार *_Str);
  _CRTIMP द्विगुन __cdecl _wtof_l(स्थिर ब_अक्षर_प्रकार *_Str,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _wtoi(स्थिर ब_अक्षर_प्रकार *_Str);
  _CRTIMP पूर्णांक __cdecl _wtoi_l(स्थिर ब_अक्षर_प्रकार *_Str,_locale_t _Locale);
  _CRTIMP दीर्घ __cdecl _wtol(स्थिर ब_अक्षर_प्रकार *_Str);
  _CRTIMP दीर्घ __cdecl _wtol_l(स्थिर ब_अक्षर_प्रकार *_Str,_locale_t _Locale);

#अगर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _i64tow(__int64 _Val,ब_अक्षर_प्रकार *_DstBuf,पूर्णांक _Radix);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _ui64tow(अचिन्हित __int64 _Val,ब_अक्षर_प्रकार *_DstBuf,पूर्णांक _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(स्थिर ब_अक्षर_प्रकार *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(स्थिर ब_अक्षर_प्रकार *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
  _CRTIMP अचिन्हित __int64 __cdecl _wcstoui64(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix);
  _CRTIMP अचिन्हित __int64 __cdecl _wcstoui64_l(स्थिर ब_अक्षर_प्रकार *_Str ,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _POSIX_
#घोषणा _CVTBUFSIZE (309+40)
  _CRTIMP अक्षर *__cdecl _fullpath(अक्षर *_FullPath,स्थिर अक्षर *_Path,माप_प्रकार आकार_In_Bytes);
  _CRTIMP अक्षर *__cdecl _ecvt(द्विगुन _Val,पूर्णांक अंक_Of_Digits,पूर्णांक *_PtDec,पूर्णांक *_PtSign);
  _CRTIMP अक्षर *__cdecl _fcvt(द्विगुन _Val,पूर्णांक अंक_Of_Dec,पूर्णांक *_PtDec,पूर्णांक *_PtSign);
  _CRTIMP अक्षर *__cdecl _gcvt(द्विगुन _Val,पूर्णांक अंक_Of_Digits,अक्षर *_DstBuf);
  _CRTIMP पूर्णांक __cdecl _atodbl(_CRT_DOUBLE *परिणाम_2,अक्षर *_Str);
  _CRTIMP पूर्णांक __cdecl _atoldbl(_LDOUBLE *परिणाम_2,अक्षर *_Str);
  _CRTIMP पूर्णांक __cdecl _atoflt(_CRT_FLOAT *परिणाम_2,अक्षर *_Str);
  _CRTIMP पूर्णांक __cdecl _atodbl_l(_CRT_DOUBLE *परिणाम_2,अक्षर *_Str,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _atoldbl_l(_LDOUBLE *परिणाम_2,अक्षर *_Str,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _atoflt_l(_CRT_FLOAT *परिणाम_2,अक्षर *_Str,_locale_t _Locale);
  अचिन्हित दीर्घ __cdecl _lrotl(अचिन्हित दीर्घ _Val,पूर्णांक _Shift);
  अचिन्हित दीर्घ __cdecl _lrotr(अचिन्हित दीर्घ _Val,पूर्णांक _Shift);
  _CRTIMP व्योम __cdecl _makepath(अक्षर *_Path,स्थिर अक्षर *_Drive,स्थिर अक्षर *_Dir,स्थिर अक्षर *_Filename,स्थिर अक्षर *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#अगर_अघोषित _CRT_PERROR_DEFINED
#घोषणा _CRT_PERROR_DEFINED
  व्योम __cdecl लिखो_त्रुटि(स्थिर अक्षर *Err_संदेश);
#पूर्ण_अगर
  _CRTIMP पूर्णांक __cdecl _putenv(स्थिर अक्षर *_EnvString);
  अचिन्हित पूर्णांक __cdecl _rotl(अचिन्हित पूर्णांक _Val,पूर्णांक _Shift);
#अगर _INTEGRAL_MAX_BITS >= 64
  अचिन्हित __int64 __cdecl _rotl64(अचिन्हित __int64 _Val,पूर्णांक _Shift);
#पूर्ण_अगर
  अचिन्हित पूर्णांक __cdecl _rotr(अचिन्हित पूर्णांक _Val,पूर्णांक _Shift);
#अगर _INTEGRAL_MAX_BITS >= 64
  अचिन्हित __int64 __cdecl _rotr64(अचिन्हित __int64 _Val,पूर्णांक _Shift);
#पूर्ण_अगर
  _CRTIMP व्योम __cdecl _searchenv(स्थिर अक्षर *_Filename,स्थिर अक्षर *_EnvVar,अक्षर *परिणाम_Path);
  _CRTIMP व्योम __cdecl _splitpath(स्थिर अक्षर *_FullPath,अक्षर *_Drive,अक्षर *_Dir,अक्षर *_Filename,अक्षर *_Ext);
  _CRTIMP व्योम __cdecl _swab(अक्षर *_Buf1,अक्षर *_Buf2,पूर्णांक आकार_In_Bytes);

#अगर_अघोषित _WSTDLIBP_DEFINED
#घोषणा _WSTDLIBP_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wfullpath(ब_अक्षर_प्रकार *_FullPath,स्थिर ब_अक्षर_प्रकार *_Path,माप_प्रकार आकार_In_शब्दगण);
  _CRTIMP व्योम __cdecl _wmakepath(ब_अक्षर_प्रकार *परिणाम_Path,स्थिर ब_अक्षर_प्रकार *_Drive,स्थिर ब_अक्षर_प्रकार *_Dir,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_Ext);
#अगर_अघोषित _CRT_WPERROR_DEFINED
#घोषणा _CRT_WPERROR_DEFINED
  _CRTIMP व्योम __cdecl _wperror(स्थिर ब_अक्षर_प्रकार *Err_संदेश);
#पूर्ण_अगर
  _CRTIMP पूर्णांक __cdecl _wputenv(स्थिर ब_अक्षर_प्रकार *_EnvString);
  _CRTIMP व्योम __cdecl _wsearchenv(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_EnvVar,ब_अक्षर_प्रकार *परिणाम_Path);
  _CRTIMP व्योम __cdecl _wsplitpath(स्थिर ब_अक्षर_प्रकार *_FullPath,ब_अक्षर_प्रकार *_Drive,ब_अक्षर_प्रकार *_Dir,ब_अक्षर_प्रकार *_Filename,ब_अक्षर_प्रकार *_Ext);
#पूर्ण_अगर

  _CRTIMP व्योम __cdecl _beep(अचिन्हित _Frequency,अचिन्हित _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP व्योम __cdecl _seterrormode(पूर्णांक _Mode) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP व्योम __cdecl _sleep(अचिन्हित दीर्घ _Duration) __MINGW_ATTRIB_DEPRECATED;
#पूर्ण_अगर

#अगर_अघोषित NO_OLDNAMES
#अगर_अघोषित _POSIX_
#अगर 0
#अगर_अघोषित __cplusplus
#अगर_अघोषित NOMINMAX
#अगर_अघोषित max
#घोषणा max(a,b) (((a) > (b)) ? (a) : (b))
#पूर्ण_अगर
#अगर_अघोषित min
#घोषणा min(a,b) (((a) < (b)) ? (a) : (b))
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा sys_errlist _sys_errlist
#घोषणा sys_nerr _sys_nerr
#घोषणा environ _environ
  अक्षर *__cdecl ecvt(द्विगुन _Val,पूर्णांक अंक_Of_Digits,पूर्णांक *_PtDec,पूर्णांक *_PtSign);
  अक्षर *__cdecl fcvt(द्विगुन _Val,पूर्णांक अंक_Of_Dec,पूर्णांक *_PtDec,पूर्णांक *_PtSign);
  अक्षर *__cdecl gcvt(द्विगुन _Val,पूर्णांक अंक_Of_Digits,अक्षर *_DstBuf);
  अक्षर *__cdecl itoa(पूर्णांक _Val,अक्षर *_DstBuf,पूर्णांक _Radix);
  अक्षर *__cdecl ltoa(दीर्घ _Val,अक्षर *_DstBuf,पूर्णांक _Radix);
  पूर्णांक __cdecl putenv(स्थिर अक्षर *_EnvString);
  व्योम __cdecl swab(अक्षर *_Buf1,अक्षर *_Buf2,पूर्णांक आकार_In_Bytes);
  अक्षर *__cdecl ultoa(अचिन्हित दीर्घ _Val,अक्षर *_Dstbuf,पूर्णांक _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#पूर्ण_अगर
#पूर्ण_अगर

#अगर !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  प्रकार काष्ठा { दीर्घ दीर्घ quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(दीर्घ दीर्घ, दीर्घ दीर्घ);

  __CRT_INLINE दीर्घ दीर्घ __cdecl llabs(दीर्घ दीर्घ _j) { वापस (_j >= 0 ? _j : -_j); }

 #अगर_घोषित __TINYC__ /* gr */
  #घोषणा strtoll _strtoi64
  #घोषणा strtoull _strtoui64
 #अन्यथा
  दीर्घ दीर्घ  __cdecl strtoll(स्थिर अक्षर* __restrict__, अक्षर** __restrict, पूर्णांक);
  अचिन्हित दीर्घ दीर्घ  __cdecl strtoull(स्थिर अक्षर* __restrict__, अक्षर** __restrict__, पूर्णांक);
 #पूर्ण_अगर

  /* these are stubs for MS _i64 versions */
  दीर्घ दीर्घ  __cdecl atoll (स्थिर अक्षर *);

#अगर_अघोषित __STRICT_ANSI__
  दीर्घ दीर्घ  __cdecl wtoll (स्थिर ब_अक्षर_प्रकार *);
  अक्षर *__cdecl lltoa (दीर्घ दीर्घ, अक्षर *, पूर्णांक);
  अक्षर *__cdecl ulltoa (अचिन्हित दीर्घ दीर्घ , अक्षर *, पूर्णांक);
  ब_अक्षर_प्रकार *__cdecl lltow (दीर्घ दीर्घ, ब_अक्षर_प्रकार *, पूर्णांक);
  ब_अक्षर_प्रकार *__cdecl ulltow (अचिन्हित दीर्घ दीर्घ, ब_अक्षर_प्रकार *, पूर्णांक);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE दीर्घ दीर्घ  __cdecl atoll (स्थिर अक्षर * _c) { वापस _atoi64 (_c); }
  __CRT_INLINE अक्षर *__cdecl lltoa (दीर्घ दीर्घ _n, अक्षर * _c, पूर्णांक _i) { वापस _i64toa (_n, _c, _i); }
  __CRT_INLINE अक्षर *__cdecl ulltoa (अचिन्हित दीर्घ दीर्घ _n, अक्षर * _c, पूर्णांक _i) { वापस _ui64toa (_n, _c, _i); }
  __CRT_INLINE दीर्घ दीर्घ  __cdecl wtoll (स्थिर ब_अक्षर_प्रकार * _w) { वापस _wtoi64 (_w); }
  __CRT_INLINE ब_अक्षर_प्रकार *__cdecl lltow (दीर्घ दीर्घ _n, ब_अक्षर_प्रकार * _w, पूर्णांक _i) { वापस _i64tow (_n, _w, _i); }
  __CRT_INLINE ब_अक्षर_प्रकार *__cdecl ulltow (अचिन्हित दीर्घ दीर्घ _n, ब_अक्षर_प्रकार * _w, पूर्णांक _i) { वापस _ui64tow (_n, _w, _i); }
#पूर्ण_अगर /* (__STRICT_ANSI__)  */

#पूर्ण_अगर /* !__NO_ISOCEXT */

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#आशय pack(निकालो)

#समावेश <sec_api/stdlib_s.h>
#समावेश <malloc.h>

#पूर्ण_अगर
