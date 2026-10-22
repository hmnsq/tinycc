/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _TIMEB_H_
#تعریف_کړه _TIMEB_H_

#ضمن <_mingw.h>

#که_نه_تعریف_شوی _WIN32
#تېروتنه Only Win32 موخه is supported!
#د_که_پای

#لارښوونه pack(ټېل,_CRT_PACKING)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی _CRTIMP
#تعریف_کړه _CRTIMP __declspec(dllimport)
#د_که_پای

#که_نه_تعریف_شوی __TINYC__ /* gr */
#که_تعریف_شوی USE_32_بټ_وخت_T
#که_تعریف_شوی _WIN64
#تعریف_لغوه USE_32_بټ_وخت_T
#د_که_پای
#وإلا
#إذا INTEGRAL_MAX_بټونه < 64
#تعریف_کړه USE_32_بټ_وخت_T
#د_که_پای
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _TIME32_T_DEFINED
  تعريفنوع اوږد __time32_t;
#تعریف_کړه _TIME32_T_DEFINED
#د_که_پای

#که_نه_تعریف_شوی _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بټونه >= 64
  تعريفنوع __int64 __time64_t;
#د_که_پای
#تعریف_کړه _TIME64_T_DEFINED
#د_که_پای

#که_نه_تعریف_شوی وخت_T_DEFINED
#که_تعریف_شوی USE_32_بټ_وخت_T
  تعريفنوع __time32_t time_t;
#وإلا
  تعريفنوع __time64_t time_t;
#د_که_پای
#تعریف_کړه وخت_T_DEFINED
#د_که_پای

#که_نه_تعریف_شوی _TIMEB_DEFINED
#تعریف_کړه _TIMEB_DEFINED

  بنية __timeb32 {
    __time32_t وخت;
    بینښه لنډ millitm;
    لنډ timezone;
    لنډ dstflag;
  };

#که_نه_تعریف_شوی	NO_OLDNAMES
  بنية timeb {
    time_t وخت;
    بینښه لنډ millitm;
    لنډ timezone;
    لنډ dstflag;
  };
#د_که_پای

#إذا INTEGRAL_MAX_بټونه >= 64
  بنية __timeb64 {
    __time64_t وخت;
    بینښه لنډ millitm;
    لنډ timezone;
    لنډ dstflag;
  };
#د_که_پای

#که_تعریف_شوی USE_32_بټ_وخت_T
#تعریف_کړه _timeb __timeb32
//gr #define _ftime _ftime32
#تعریف_کړه _ftime32 _ftime
#وإلا
#تعریف_کړه _timeb __timeb64
#تعریف_کړه _ftime _ftime64
#د_که_پای
#د_که_پای

  _CRTIMP فراغ __cdecl _ftime32(بنية __timeb32 *وخت_2);
#إذا INTEGRAL_MAX_بټونه >= 64
  _CRTIMP فراغ __cdecl _ftime64(بنية __timeb64 *وخت_2);
#د_که_پای

#که_نه_تعریف_شوی _TIMESPEC_DEFINED
#تعریف_کړه _TIMESPEC_DEFINED
بنية timespec {
  time_t  tv_sec;   /* Seconds */
  اوږد    tv_nsec;  /* Nanoseconds */
};

بنية itimerspec {
  بنية timespec  it_interval;  /* Timer period */
  بنية timespec  it_value;     /* Timer expiration */
};
#د_که_پای

#إذا !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
#که_تعریف_شوی USE_32_بټ_وخت_T
__CRT_INLINE فراغ __cdecl ftime(بنية timeb *_Tmb) {
  _ftime32((بنية __timeb32 *)_Tmb);
}
#وإلا
__CRT_INLINE فراغ __cdecl ftime(بنية timeb *_Tmb) {
  _ftime64((بنية __timeb64 *)_Tmb);
}
#د_که_پای
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#لارښوونه pack(راوباسه)

#ضمن <sec_api/sys/timeb_s.h>
#د_که_پای
