/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIMEB_H_
#define _TIMEB_H_

#અન્તર્ભાવ <_mingw.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#pragma pack(ધકેલો,_CRT_PACKING)

#ifdef __cplusplus
બાહ્ય "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#નહીંતર
#જો _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
  પ્રકારવ્યાખ્યા long __time32_t;
#define _TIME32_T_DEFINED
#endif

#ifndef _TIME64_T_DEFINED
#જો _INTEGRAL_MAX_BITS >= 64
  પ્રકારવ્યાખ્યા __int64 __time64_t;
#endif
#define _TIME64_T_DEFINED
#endif

#ifndef _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  પ્રકારવ્યાખ્યા __time32_t time_t;
#નહીંતર
  પ્રકારવ્યાખ્યા __time64_t time_t;
#endif
#define _TIME_T_DEFINED
#endif

#ifndef _TIMEB_DEFINED
#define _TIMEB_DEFINED

  સંરચના __timeb32 {
    __time32_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
  };

#ifndef	NO_OLDNAMES
  સંરચના timeb {
    time_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
  };
#endif

#જો _INTEGRAL_MAX_BITS >= 64
  સંરચના __timeb64 {
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
#નહીંતર
#define _timeb __timeb64
#define _ftime _ftime64
#endif
#endif

  _CRTIMP શૂન્ય __cdecl _ftime32(સંરચના __timeb32 *_Time);
#જો _INTEGRAL_MAX_BITS >= 64
  _CRTIMP શૂન્ય __cdecl _ftime64(સંરચના __timeb64 *_Time);
#endif

#ifndef _TIMESPEC_DEFINED
#define _TIMESPEC_DEFINED
સંરચના timespec {
  time_t  tv_sec;   /* Seconds */
  long    tv_nsec;  /* Nanoseconds */
};

સંરચના itimerspec {
  સંરચના timespec  it_interval;  /* Timer period */
  સંરચના timespec  it_value;     /* Timer expiration */
};
#endif

#જો !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE શૂન્ય __cdecl ftime(સંરચના timeb *_Tmb) {
  _ftime32((સંરચના __timeb32 *)_Tmb);
}
#નહીંતર
__CRT_INLINE શૂન્ય __cdecl ftime(સંરચના timeb *_Tmb) {
  _ftime64((સંરચના __timeb64 *)_Tmb);
}
#endif
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(કાઢો)

#અન્તર્ભાવ <sec_api/sys/timeb_s.h>
#endif
