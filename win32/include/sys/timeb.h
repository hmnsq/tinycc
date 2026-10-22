/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIMEB_H_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIMEB_H_

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
#ਗਲਤੀ Only Win32 ਨਿਸ਼ਾਨਾ is supported!
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ pack(ਧੱਕੋ,_CRT_PACKING)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRTIMP
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRTIMP __declspec(dllimport)
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __TINYC__ /* gr */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ < 64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIME32_T_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ __time32_t;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIME32_T_DEFINED
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIME64_T_DEFINED
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __int64 __time64_t;
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIME64_T_DEFINED
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ਸਮਾਂ_T_DEFINED
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __time32_t time_t;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __time64_t time_t;
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮਾਂ_T_DEFINED
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIMEB_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIMEB_DEFINED

  ਬਣਤਰ __timeb32 {
    __time32_t ਸਮਾਂ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ millitm;
    ਛੋਟਾ timezone;
    ਛੋਟਾ dstflag;
  };

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
  ਬਣਤਰ timeb {
    time_t ਸਮਾਂ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ millitm;
    ਛੋਟਾ timezone;
    ਛੋਟਾ dstflag;
  };
#ਜੇ_ਅੰਤ

#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  ਬਣਤਰ __timeb64 {
    __time64_t ਸਮਾਂ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ millitm;
    ਛੋਟਾ timezone;
    ਛੋਟਾ dstflag;
  };
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _timeb __timeb32
//gr #define _ftime _ftime32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _ftime32 _ftime
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _timeb __timeb64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _ftime _ftime64
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

  _CRTIMP ਖਾਲੀ __cdecl _ftime32(ਬਣਤਰ __timeb32 *ਸਮਾਂ_2);
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  _CRTIMP ਖਾਲੀ __cdecl _ftime64(ਬਣਤਰ __timeb64 *ਸਮਾਂ_2);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIMESPEC_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIMESPEC_DEFINED
ਬਣਤਰ timespec {
  time_t  tv_sec;   /* Seconds */
  ਲੰਮਾ    tv_nsec;  /* Nanoseconds */
};

ਬਣਤਰ itimerspec {
  ਬਣਤਰ timespec  it_interval;  /* Timer period */
  ਬਣਤਰ timespec  it_value;     /* Timer expiration */
};
#ਜੇ_ਅੰਤ

#ਜੇ !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
__CRT_INLINE ਖਾਲੀ __cdecl ftime(ਬਣਤਰ timeb *_Tmb) {
  _ftime32((ਬਣਤਰ __timeb32 *)_Tmb);
}
#ਨਹੀਂਤਾਂ
__CRT_INLINE ਖਾਲੀ __cdecl ftime(ਬਣਤਰ timeb *_Tmb) {
  _ftime64((ਬਣਤਰ __timeb64 *)_Tmb);
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ pack(ਕੱਢੋ)

#ਅਨ੍ਤਰ੍ਭਾਵ <sec_api/sys/timeb_s.h>
#ਜੇ_ਅੰਤ
