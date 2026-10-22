/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _TIMEB_H_
#تعریف_کرو _TIMEB_H_

#شامل <_mingw.h>

#اگر_غیر_تعریف_شدہ _WIN32
#غلطی Only Win32 ہدف is supported!
#اگر_ختم

#ہدایت pack(ڈالو,_CRT_PACKING)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ _CRTIMP
#تعریف_کرو _CRTIMP __declspec(dllimport)
#اگر_ختم

#اگر_غیر_تعریف_شدہ __TINYC__ /* gr */
#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
#اگر_تعریف_شدہ _WIN64
#تعریف_منسوخ USE_32_ثنائی_ہندسہ_وقت_T
#اگر_ختم
#ورنہ
#اگر INTEGRAL_MAX_بٹ < 64
#تعریف_کرو USE_32_ثنائی_ہندسہ_وقت_T
#اگر_ختم
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TIME32_T_DEFINED
  قسمتعریف طویل __time32_t;
#تعریف_کرو _TIME32_T_DEFINED
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TIME64_T_DEFINED
#اگر INTEGRAL_MAX_بٹ >= 64
  قسمتعریف __int64 __time64_t;
#اگر_ختم
#تعریف_کرو _TIME64_T_DEFINED
#اگر_ختم

#اگر_غیر_تعریف_شدہ وقت_T_DEFINED
#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
  قسمتعریف __time32_t time_t;
#ورنہ
  قسمتعریف __time64_t time_t;
#اگر_ختم
#تعریف_کرو وقت_T_DEFINED
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TIMEB_DEFINED
#تعریف_کرو _TIMEB_DEFINED

  ساخت __timeb32 {
    __time32_t وقت;
    غیرعلامتی مختصر millitm;
    مختصر timezone;
    مختصر dstflag;
  };

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
  ساخت timeb {
    time_t وقت;
    غیرعلامتی مختصر millitm;
    مختصر timezone;
    مختصر dstflag;
  };
#اگر_ختم

#اگر INTEGRAL_MAX_بٹ >= 64
  ساخت __timeb64 {
    __time64_t وقت;
    غیرعلامتی مختصر millitm;
    مختصر timezone;
    مختصر dstflag;
  };
#اگر_ختم

#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
#تعریف_کرو _timeb __timeb32
//gr #define _ftime _ftime32
#تعریف_کرو _ftime32 _ftime
#ورنہ
#تعریف_کرو _timeb __timeb64
#تعریف_کرو _ftime _ftime64
#اگر_ختم
#اگر_ختم

  _CRTIMP خالی __cdecl _ftime32(ساخت __timeb32 *وقت_2);
#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP خالی __cdecl _ftime64(ساخت __timeb64 *وقت_2);
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TIMESPEC_DEFINED
#تعریف_کرو _TIMESPEC_DEFINED
ساخت timespec {
  time_t  tv_sec;   /* Seconds */
  طویل    tv_nsec;  /* Nanoseconds */
};

ساخت itimerspec {
  ساخت timespec  it_interval;  /* Timer period */
  ساخت timespec  it_value;     /* Timer expiration */
};
#اگر_ختم

#اگر !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
__CRT_INLINE خالی __cdecl ftime(ساخت timeb *_Tmb) {
  _ftime32((ساخت __timeb32 *)_Tmb);
}
#ورنہ
__CRT_INLINE خالی __cdecl ftime(ساخت timeb *_Tmb) {
  _ftime64((ساخت __timeb64 *)_Tmb);
}
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#ہدایت pack(نکالو)

#شامل <sec_api/sys/timeb_s.h>
#اگر_ختم
