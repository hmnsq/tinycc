/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _TIMEB_H_
#تعریف_کن _TIMEB_H_

#ضمن <_mingw.h>

#اگر_تعریف_نشده _WIN32
#خطا Only Win32 هدف is supported!
#پایان_اگر

#رهنمود pack(افزودن,_CRT_PACKING)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده _CRTIMP
#تعریف_کن _CRTIMP __declspec(dllimport)
#پایان_اگر

#اگر_تعریف_نشده __TINYC__ /* gr */
#اگر_تعریف_شده USE_32_بیت_زمان_T
#اگر_تعریف_شده _WIN64
#لغو_تعریف USE_32_بیت_زمان_T
#پایان_اگر
#وإلا
#إذا INTEGRAL_MAX_بیتها < 64
#تعریف_کن USE_32_بیت_زمان_T
#پایان_اگر
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _TIME32_T_DEFINED
  تعريفنوع دراز __time32_t;
#تعریف_کن _TIME32_T_DEFINED
#پایان_اگر

#اگر_تعریف_نشده _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بیتها >= 64
  تعريفنوع __int64 __time64_t;
#پایان_اگر
#تعریف_کن _TIME64_T_DEFINED
#پایان_اگر

#اگر_تعریف_نشده زمان_T_DEFINED
#اگر_تعریف_شده USE_32_بیت_زمان_T
  تعريفنوع __time32_t time_t;
#وإلا
  تعريفنوع __time64_t time_t;
#پایان_اگر
#تعریف_کن زمان_T_DEFINED
#پایان_اگر

#اگر_تعریف_نشده _TIMEB_DEFINED
#تعریف_کن _TIMEB_DEFINED

  بنية __timeb32 {
    __time32_t زمان;
    بیعلامت کوتاه millitm;
    کوتاه timezone;
    کوتاه dstflag;
  };

#اگر_تعریف_نشده	NO_OLDNAMES
  بنية timeb {
    time_t زمان;
    بیعلامت کوتاه millitm;
    کوتاه timezone;
    کوتاه dstflag;
  };
#پایان_اگر

#إذا INTEGRAL_MAX_بیتها >= 64
  بنية __timeb64 {
    __time64_t زمان;
    بیعلامت کوتاه millitm;
    کوتاه timezone;
    کوتاه dstflag;
  };
#پایان_اگر

#اگر_تعریف_شده USE_32_بیت_زمان_T
#تعریف_کن _timeb __timeb32
//gr #define _ftime _ftime32
#تعریف_کن _ftime32 _ftime
#وإلا
#تعریف_کن _timeb __timeb64
#تعریف_کن _ftime _ftime64
#پایان_اگر
#پایان_اگر

  _CRTIMP فراغ __cdecl _ftime32(بنية __timeb32 *زمان_2);
#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP فراغ __cdecl _ftime64(بنية __timeb64 *زمان_2);
#پایان_اگر

#اگر_تعریف_نشده _TIMESPEC_DEFINED
#تعریف_کن _TIMESPEC_DEFINED
بنية timespec {
  time_t  tv_sec;   /* Seconds */
  دراز    tv_nsec;  /* Nanoseconds */
};

بنية itimerspec {
  بنية timespec  it_interval;  /* Timer period */
  بنية timespec  it_value;     /* Timer expiration */
};
#پایان_اگر

#إذا !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
#اگر_تعریف_شده USE_32_بیت_زمان_T
__CRT_INLINE فراغ __cdecl ftime(بنية timeb *_Tmb) {
  _ftime32((بنية __timeb32 *)_Tmb);
}
#وإلا
__CRT_INLINE فراغ __cdecl ftime(بنية timeb *_Tmb) {
  _ftime64((بنية __timeb64 *)_Tmb);
}
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#رهنمود pack(برداشت)

#ضمن <sec_api/sys/timeb_s.h>
#پایان_اگر
