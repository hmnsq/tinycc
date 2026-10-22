/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _TIMEB_H_
#تعریف_کرو _TIMEB_H_

#ضمن <_mingw.h>

#جے_بنا_تعریف _WIN32
#غلطی Only Win32 نشانہ is supported!
#جے_انت

#ہدایت pack(ڈالو,_CRT_PACKING)

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف _CRTIMP
#تعریف_کرو _CRTIMP __declspec(dllimport)
#جے_انت

#جے_بنا_تعریف __TINYC__ /* gr */
#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
#جے_تعریف_شدہ _WIN64
#تعریف_رد USE_32_ثنائی_ہندسہ_ویلا_T
#جے_انت
#وإلا
#إذا INTEGRAL_MAX_بٹ < 64
#تعریف_کرو USE_32_ثنائی_ہندسہ_ویلا_T
#جے_انت
#جے_انت
#جے_انت

#جے_بنا_تعریف _TIME32_T_DEFINED
  تعريفنوع لما __time32_t;
#تعریف_کرو _TIME32_T_DEFINED
#جے_انت

#جے_بنا_تعریف _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بٹ >= 64
  تعريفنوع __int64 __time64_t;
#جے_انت
#تعریف_کرو _TIME64_T_DEFINED
#جے_انت

#جے_بنا_تعریف ویلا_T_DEFINED
#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
  تعريفنوع __time32_t time_t;
#وإلا
  تعريفنوع __time64_t time_t;
#جے_انت
#تعریف_کرو ویلا_T_DEFINED
#جے_انت

#جے_بنا_تعریف _TIMEB_DEFINED
#تعریف_کرو _TIMEB_DEFINED

  بنية __timeb32 {
    __time32_t ویلا;
    بنانشانی چھوٹا millitm;
    چھوٹا timezone;
    چھوٹا dstflag;
  };

#جے_بنا_تعریف	NO_OLDNAMES
  بنية timeb {
    time_t ویلا;
    بنانشانی چھوٹا millitm;
    چھوٹا timezone;
    چھوٹا dstflag;
  };
#جے_انت

#إذا INTEGRAL_MAX_بٹ >= 64
  بنية __timeb64 {
    __time64_t ویلا;
    بنانشانی چھوٹا millitm;
    چھوٹا timezone;
    چھوٹا dstflag;
  };
#جے_انت

#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
#تعریف_کرو _timeb __timeb32
//gr #define _ftime _ftime32
#تعریف_کرو _ftime32 _ftime
#وإلا
#تعریف_کرو _timeb __timeb64
#تعریف_کرو _ftime _ftime64
#جے_انت
#جے_انت

  _CRTIMP فراغ __cdecl _ftime32(بنية __timeb32 *ویلا_2);
#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP فراغ __cdecl _ftime64(بنية __timeb64 *ویلا_2);
#جے_انت

#جے_بنا_تعریف _TIMESPEC_DEFINED
#تعریف_کرو _TIMESPEC_DEFINED
بنية timespec {
  time_t  tv_sec;   /* Seconds */
  لما    tv_nsec;  /* Nanoseconds */
};

بنية itimerspec {
  بنية timespec  it_interval;  /* Timer period */
  بنية timespec  it_value;     /* Timer expiration */
};
#جے_انت

#إذا !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
__CRT_INLINE فراغ __cdecl ftime(بنية timeb *_Tmb) {
  _ftime32((بنية __timeb32 *)_Tmb);
}
#وإلا
__CRT_INLINE فراغ __cdecl ftime(بنية timeb *_Tmb) {
  _ftime64((بنية __timeb64 *)_Tmb);
}
#جے_انت
#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#ہدایت pack(نکالو)

#ضمن <sec_api/sys/timeb_s.h>
#جے_انت
