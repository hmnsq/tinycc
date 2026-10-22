/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIMEB_H_
#define _TIMEB_H_

#شامل <_mingw.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#pragma pack(افزودن,_CRT_PACKING)

#ifdef __cplusplus
بیرونی "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#وگرنه
#اگر _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
  تعریفنوع long __time32_t;
#define _TIME32_T_DEFINED
#endif

#ifndef _TIME64_T_DEFINED
#اگر _INTEGRAL_MAX_BITS >= 64
  تعریفنوع __int64 __time64_t;
#endif
#define _TIME64_T_DEFINED
#endif

#ifndef _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  تعریفنوع __time32_t time_t;
#وگرنه
  تعریفنوع __time64_t time_t;
#endif
#define _TIME_T_DEFINED
#endif

#ifndef _TIMEB_DEFINED
#define _TIMEB_DEFINED

  ساختار __timeb32 {
    __time32_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
  };

#ifndef	NO_OLDNAMES
  ساختار timeb {
    time_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
  };
#endif

#اگر _INTEGRAL_MAX_BITS >= 64
  ساختار __timeb64 {
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
#وگرنه
#define _timeb __timeb64
#define _ftime _ftime64
#endif
#endif

  _CRTIMP تهی __cdecl _ftime32(ساختار __timeb32 *_Time);
#اگر _INTEGRAL_MAX_BITS >= 64
  _CRTIMP تهی __cdecl _ftime64(ساختار __timeb64 *_Time);
#endif

#ifndef _TIMESPEC_DEFINED
#define _TIMESPEC_DEFINED
ساختار timespec {
  time_t  tv_sec;   /* Seconds */
  long    tv_nsec;  /* Nanoseconds */
};

ساختار itimerspec {
  ساختار timespec  it_interval;  /* Timer period */
  ساختار timespec  it_value;     /* Timer expiration */
};
#endif

#اگر !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE تهی __cdecl ftime(ساختار timeb *_Tmb) {
  _ftime32((ساختار __timeb32 *)_Tmb);
}
#وگرنه
__CRT_INLINE تهی __cdecl ftime(ساختار timeb *_Tmb) {
  _ftime64((ساختار __timeb64 *)_Tmb);
}
#endif
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(برداشت)

#شامل <sec_api/sys/timeb_s.h>
#endif
