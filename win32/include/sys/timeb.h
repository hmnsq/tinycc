/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIMEB_H_
#define _TIMEB_H_

#அந்தர்பாவ <_mingw.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#pragma pack(தள்ளு,_CRT_PACKING)

#ifdef __cplusplus
வெளி "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#இல்லையெனில்
#எனில் _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
  வகைவரை long __time32_t;
#define _TIME32_T_DEFINED
#endif

#ifndef _TIME64_T_DEFINED
#எனில் _INTEGRAL_MAX_BITS >= 64
  வகைவரை __int64 __time64_t;
#endif
#define _TIME64_T_DEFINED
#endif

#ifndef _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  வகைவரை __time32_t time_t;
#இல்லையெனில்
  வகைவரை __time64_t time_t;
#endif
#define _TIME_T_DEFINED
#endif

#ifndef _TIMEB_DEFINED
#define _TIMEB_DEFINED

  கட்டமைப்பு __timeb32 {
    __time32_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
  };

#ifndef	NO_OLDNAMES
  கட்டமைப்பு timeb {
    time_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
  };
#endif

#எனில் _INTEGRAL_MAX_BITS >= 64
  கட்டமைப்பு __timeb64 {
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
#இல்லையெனில்
#define _timeb __timeb64
#define _ftime _ftime64
#endif
#endif

  _CRTIMP வெறுமை __cdecl _ftime32(கட்டமைப்பு __timeb32 *_Time);
#எனில் _INTEGRAL_MAX_BITS >= 64
  _CRTIMP வெறுமை __cdecl _ftime64(கட்டமைப்பு __timeb64 *_Time);
#endif

#ifndef _TIMESPEC_DEFINED
#define _TIMESPEC_DEFINED
கட்டமைப்பு timespec {
  time_t  tv_sec;   /* Seconds */
  long    tv_nsec;  /* Nanoseconds */
};

கட்டமைப்பு itimerspec {
  கட்டமைப்பு timespec  it_interval;  /* Timer period */
  கட்டமைப்பு timespec  it_value;     /* Timer expiration */
};
#endif

#எனில் !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE வெறுமை __cdecl ftime(கட்டமைப்பு timeb *_Tmb) {
  _ftime32((கட்டமைப்பு __timeb32 *)_Tmb);
}
#இல்லையெனில்
__CRT_INLINE வெறுமை __cdecl ftime(கட்டமைப்பு timeb *_Tmb) {
  _ftime64((கட்டமைப்பு __timeb64 *)_Tmb);
}
#endif
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(எடு)

#அந்தர்பாவ <sec_api/sys/timeb_s.h>
#endif
