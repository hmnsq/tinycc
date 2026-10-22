/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _TIMEB_H_
#घोषणा _TIMEB_H_

#समावेश <_mingw.h>

#अगर_अघोषित _WIN32
#त्रुटि Only Win32 target is supported!
#पूर्ण_अगर

#आशय pack(धकेलो,_CRT_PACKING)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित _CRTIMP
#घोषणा _CRTIMP __declspec(dllimport)
#पूर्ण_अगर

#अगर_अघोषित __TINYC__ /* gr */
#अगर_घोषित _USE_32BIT_TIME_T
#अगर_घोषित _WIN64
#अघोषित _USE_32BIT_TIME_T
#पूर्ण_अगर
#अन्यथा
#अगर _INTEGRAL_MAX_BITS < 64
#घोषणा _USE_32BIT_TIME_T
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _TIME32_T_DEFINED
  प्रकार दीर्घ __time32_t;
#घोषणा _TIME32_T_DEFINED
#पूर्ण_अगर

#अगर_अघोषित _TIME64_T_DEFINED
#अगर _INTEGRAL_MAX_BITS >= 64
  प्रकार __int64 __time64_t;
#पूर्ण_अगर
#घोषणा _TIME64_T_DEFINED
#पूर्ण_अगर

#अगर_अघोषित _TIME_T_DEFINED
#अगर_घोषित _USE_32BIT_TIME_T
  प्रकार __time32_t समय_प्रकार;
#अन्यथा
  प्रकार __time64_t समय_प्रकार;
#पूर्ण_अगर
#घोषणा _TIME_T_DEFINED
#पूर्ण_अगर

#अगर_अघोषित _TIMEB_DEFINED
#घोषणा _TIMEB_DEFINED

  काष्ठा __timeb32 {
    __time32_t समय;
    अचिन्हित लघु millitm;
    लघु timezone;
    लघु dstflag;
  };

#अगर_अघोषित	NO_OLDNAMES
  काष्ठा timeb {
    समय_प्रकार समय;
    अचिन्हित लघु millitm;
    लघु timezone;
    लघु dstflag;
  };
#पूर्ण_अगर

#अगर _INTEGRAL_MAX_BITS >= 64
  काष्ठा __timeb64 {
    __time64_t समय;
    अचिन्हित लघु millitm;
    लघु timezone;
    लघु dstflag;
  };
#पूर्ण_अगर

#अगर_घोषित _USE_32BIT_TIME_T
#घोषणा _timeb __timeb32
//gr #define _ftime _ftime32
#घोषणा _ftime32 _ftime
#अन्यथा
#घोषणा _timeb __timeb64
#घोषणा _ftime _ftime64
#पूर्ण_अगर
#पूर्ण_अगर

  _CRTIMP व्योम __cdecl _ftime32(काष्ठा __timeb32 *_Time);
#अगर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP व्योम __cdecl _ftime64(काष्ठा __timeb64 *_Time);
#पूर्ण_अगर

#अगर_अघोषित _TIMESPEC_DEFINED
#घोषणा _TIMESPEC_DEFINED
काष्ठा timespec {
  समय_प्रकार  tv_sec;   /* Seconds */
  दीर्घ    tv_nsec;  /* Nanoseconds */
};

काष्ठा itimerspec {
  काष्ठा timespec  it_interval;  /* Timer period */
  काष्ठा timespec  it_value;     /* Timer expiration */
};
#पूर्ण_अगर

#अगर !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
#अगर_घोषित _USE_32BIT_TIME_T
__CRT_INLINE व्योम __cdecl ftime(काष्ठा timeb *_Tmb) {
  _ftime32((काष्ठा __timeb32 *)_Tmb);
}
#अन्यथा
__CRT_INLINE व्योम __cdecl ftime(काष्ठा timeb *_Tmb) {
  _ftime64((काष्ठा __timeb64 *)_Tmb);
}
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#आशय pack(निकालो)

#समावेश <sec_api/sys/timeb_s.h>
#पूर्ण_अगर
