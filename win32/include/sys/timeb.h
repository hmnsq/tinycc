/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIMEB_H_
#define _TIMEB_H_

#अन्तर्भाव <_mingw.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#pragma pack(प्रक्षिप,_CRT_PACKING)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#अण्णहा
#जइ _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
  प्रकारनिर्देश long __time32_t;
#define _TIME32_T_DEFINED
#endif

#ifndef _TIME64_T_DEFINED
#जइ _INTEGRAL_MAX_BITS >= 64
  प्रकारनिर्देश __int64 __time64_t;
#endif
#define _TIME64_T_DEFINED
#endif

#ifndef _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  प्रकारनिर्देश __time32_t time_t;
#अण्णहा
  प्रकारनिर्देश __time64_t time_t;
#endif
#define _TIME_T_DEFINED
#endif

#ifndef _TIMEB_DEFINED
#define _TIMEB_DEFINED

  संरचना __timeb32 {
    __time32_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
  };

#ifndef	NO_OLDNAMES
  संरचना timeb {
    time_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
  };
#endif

#जइ _INTEGRAL_MAX_BITS >= 64
  संरचना __timeb64 {
    __time64_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
  };
#endif

#ifdef _USE_32BIT_TIME_T
#define _timeb __timeb32
//gr #define _ftime _ftime32
#define _ftime32 _ftime
#अण्णहा
#define _timeb __timeb64
#define _ftime _ftime64
#endif
#endif

  _CRTIMP शून्य __cdecl _ftime32(संरचना __timeb32 *_Time);
#जइ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP शून्य __cdecl _ftime64(संरचना __timeb64 *_Time);
#endif

#ifndef _TIMESPEC_DEFINED
#define _TIMESPEC_DEFINED
संरचना timespec {
  time_t  tv_sec;   /* Seconds */
  long    tv_nsec;  /* Nanoseconds */
};

संरचना itimerspec {
  संरचना timespec  it_interval;  /* Timer period */
  संरचना timespec  it_value;     /* Timer expiration */
};
#endif

#जइ !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE शून्य __cdecl ftime(संरचना timeb *_Tmb) {
  _ftime32((संरचना __timeb32 *)_Tmb);
}
#अण्णहा
__CRT_INLINE शून्य __cdecl ftime(संरचना timeb *_Tmb) {
  _ftime64((संरचना __timeb64 *)_Tmb);
}
#endif
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(निष्कासय)

#अन्तर्भाव <sec_api/sys/timeb_s.h>
#endif
