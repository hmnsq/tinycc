/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIMEB_H_
#define _TIMEB_H_

#ଅନ୍ତର୍ଭାଵ <_mingw.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#pragma pack(ଠେଲ,_CRT_PACKING)

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#ଅନ୍ୟଥା
#ଯଦି _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long __time32_t;
#define _TIME32_T_DEFINED
#endif

#ifndef _TIME64_T_DEFINED
#ଯଦି _INTEGRAL_MAX_BITS >= 64
  ପ୍ରକାରବ୍ୟାଖ୍ୟା __int64 __time64_t;
#endif
#define _TIME64_T_DEFINED
#endif

#ifndef _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  ପ୍ରକାରବ୍ୟାଖ୍ୟା __time32_t time_t;
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା __time64_t time_t;
#endif
#define _TIME_T_DEFINED
#endif

#ifndef _TIMEB_DEFINED
#define _TIMEB_DEFINED

  ସଂରଚନା __timeb32 {
    __time32_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
  };

#ifndef	NO_OLDNAMES
  ସଂରଚନା timeb {
    time_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
  };
#endif

#ଯଦି _INTEGRAL_MAX_BITS >= 64
  ସଂରଚନା __timeb64 {
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
#ଅନ୍ୟଥା
#define _timeb __timeb64
#define _ftime _ftime64
#endif
#endif

  _CRTIMP ଶୂନ୍ୟ __cdecl _ftime32(ସଂରଚନା __timeb32 *_Time);
#ଯଦି _INTEGRAL_MAX_BITS >= 64
  _CRTIMP ଶୂନ୍ୟ __cdecl _ftime64(ସଂରଚନା __timeb64 *_Time);
#endif

#ifndef _TIMESPEC_DEFINED
#define _TIMESPEC_DEFINED
ସଂରଚନା timespec {
  time_t  tv_sec;   /* Seconds */
  long    tv_nsec;  /* Nanoseconds */
};

ସଂରଚନା itimerspec {
  ସଂରଚନା timespec  it_interval;  /* Timer period */
  ସଂରଚନା timespec  it_value;     /* Timer expiration */
};
#endif

#ଯଦି !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE ଶୂନ୍ୟ __cdecl ftime(ସଂରଚନା timeb *_Tmb) {
  _ftime32((ସଂରଚନା __timeb32 *)_Tmb);
}
#ଅନ୍ୟଥା
__CRT_INLINE ଶୂନ୍ୟ __cdecl ftime(ସଂରଚନା timeb *_Tmb) {
  _ftime64((ସଂରଚନା __timeb64 *)_Tmb);
}
#endif
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(କାଢ଼)

#ଅନ୍ତର୍ଭାଵ <sec_api/sys/timeb_s.h>
#endif
