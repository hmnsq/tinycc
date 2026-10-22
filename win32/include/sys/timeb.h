/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _TIMEB_H_
#وصف_ڪريو _TIMEB_H_

#ضمن <_mingw.h>

#جيڪڏهن_وصف_نه_ٿيل _WIN32
#غلطي Only Win32 هدف is supported!
#جيڪڏهن_پورو

#هدايت pack(ڌڪو,_CRT_PACKING)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _CRTIMP
#وصف_ڪريو _CRTIMP __declspec(dllimport)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل __TINYC__ /* gr */
#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
#جيڪڏهن_وصف_ٿيل _WIN64
#وصف_رد USE_32_ٻٽو_انگ_وقت_T
#جيڪڏهن_پورو
#وإلا
#إذا INTEGRAL_MAX_بٽ < 64
#وصف_ڪريو USE_32_ٻٽو_انگ_وقت_T
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TIME32_T_DEFINED
  تعريفنوع ڊگهو __time32_t;
#وصف_ڪريو _TIME32_T_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بٽ >= 64
  تعريفنوع __int64 __time64_t;
#جيڪڏهن_پورو
#وصف_ڪريو _TIME64_T_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل وقت_T_DEFINED
#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
  تعريفنوع __time32_t time_t;
#وإلا
  تعريفنوع __time64_t time_t;
#جيڪڏهن_پورو
#وصف_ڪريو وقت_T_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TIMEB_DEFINED
#وصف_ڪريو _TIMEB_DEFINED

  بنية __timeb32 {
    __time32_t وقت;
    بنانشان ننڍو millitm;
    ننڍو timezone;
    ننڍو dstflag;
  };

#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
  بنية timeb {
    time_t وقت;
    بنانشان ننڍو millitm;
    ننڍو timezone;
    ننڍو dstflag;
  };
#جيڪڏهن_پورو

#إذا INTEGRAL_MAX_بٽ >= 64
  بنية __timeb64 {
    __time64_t وقت;
    بنانشان ننڍو millitm;
    ننڍو timezone;
    ننڍو dstflag;
  };
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
#وصف_ڪريو _timeb __timeb32
//gr #define _ftime _ftime32
#وصف_ڪريو _ftime32 _ftime
#وإلا
#وصف_ڪريو _timeb __timeb64
#وصف_ڪريو _ftime _ftime64
#جيڪڏهن_پورو
#جيڪڏهن_پورو

  _CRTIMP فراغ __cdecl _ftime32(بنية __timeb32 *وقت_2);
#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP فراغ __cdecl _ftime64(بنية __timeb64 *وقت_2);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TIMESPEC_DEFINED
#وصف_ڪريو _TIMESPEC_DEFINED
بنية timespec {
  time_t  tv_sec;   /* Seconds */
  ڊگهو    tv_nsec;  /* Nanoseconds */
};

بنية itimerspec {
  بنية timespec  it_interval;  /* Timer period */
  بنية timespec  it_value;     /* Timer expiration */
};
#جيڪڏهن_پورو

#إذا !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
__CRT_INLINE فراغ __cdecl ftime(بنية timeb *_Tmb) {
  _ftime32((بنية __timeb32 *)_Tmb);
}
#وإلا
__CRT_INLINE فراغ __cdecl ftime(بنية timeb *_Tmb) {
  _ftime64((بنية __timeb64 *)_Tmb);
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#هدايت pack(ڪڍو)

#ضمن <sec_api/sys/timeb_s.h>
#جيڪڏهن_پورو
