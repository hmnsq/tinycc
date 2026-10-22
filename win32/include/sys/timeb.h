/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIMEB_H_
#define _TIMEB_H_

#অন্তর্ভাব <_mingw.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#pragma pack(ঠেলো,_CRT_PACKING)

#ifdef __cplusplus
বাহ্যিক "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#অন্যথা
#যদি _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
  প্রকারলেখ long __time32_t;
#define _TIME32_T_DEFINED
#endif

#ifndef _TIME64_T_DEFINED
#যদি _INTEGRAL_MAX_BITS >= 64
  প্রকারলেখ __int64 __time64_t;
#endif
#define _TIME64_T_DEFINED
#endif

#ifndef _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  প্রকারলেখ __time32_t time_t;
#অন্যথা
  প্রকারলেখ __time64_t time_t;
#endif
#define _TIME_T_DEFINED
#endif

#ifndef _TIMEB_DEFINED
#define _TIMEB_DEFINED

  কাঠামো __timeb32 {
    __time32_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
  };

#ifndef	NO_OLDNAMES
  কাঠামো timeb {
    time_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
  };
#endif

#যদি _INTEGRAL_MAX_BITS >= 64
  কাঠামো __timeb64 {
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
#অন্যথা
#define _timeb __timeb64
#define _ftime _ftime64
#endif
#endif

  _CRTIMP শূন্য __cdecl _ftime32(কাঠামো __timeb32 *_Time);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP শূন্য __cdecl _ftime64(কাঠামো __timeb64 *_Time);
#endif

#ifndef _TIMESPEC_DEFINED
#define _TIMESPEC_DEFINED
কাঠামো timespec {
  time_t  tv_sec;   /* Seconds */
  long    tv_nsec;  /* Nanoseconds */
};

কাঠামো itimerspec {
  কাঠামো timespec  it_interval;  /* Timer period */
  কাঠামো timespec  it_value;     /* Timer expiration */
};
#endif

#যদি !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE শূন্য __cdecl ftime(কাঠামো timeb *_Tmb) {
  _ftime32((কাঠামো __timeb32 *)_Tmb);
}
#অন্যথা
__CRT_INLINE শূন্য __cdecl ftime(কাঠামো timeb *_Tmb) {
  _ftime64((কাঠামো __timeb64 *)_Tmb);
}
#endif
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(বের_করো)

#অন্তর্ভাব <sec_api/sys/timeb_s.h>
#endif
