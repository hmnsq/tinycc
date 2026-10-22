/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIMEB_H_
#ವ್ಯಾಖ್ಯಾನಿಸು _TIMEB_H_

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
#ದೋಷ Only Win32 ಗುರಿ is supported!
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ pack(ತಳ್ಳು,_CRT_PACKING)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRTIMP
#ವ್ಯಾಖ್ಯಾನಿಸು _CRTIMP __declspec(dllimport)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __TINYC__ /* gr */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು USE_32_ಬಿಟ್_ಸಮಯ_T
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು < 64
#ವ್ಯಾಖ್ಯಾನಿಸು USE_32_ಬಿಟ್_ಸಮಯ_T
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIME32_T_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ __time32_t;
#ವ್ಯಾಖ್ಯಾನಿಸು _TIME32_T_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIME64_T_DEFINED
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __int64 __time64_t;
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು _TIME64_T_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ಸಮಯ_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __time32_t time_t;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __time64_t time_t;
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಮಯ_T_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIMEB_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _TIMEB_DEFINED

  ರಚನೆ __timeb32 {
    __time32_t ಸಮಯ;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ millitm;
    ಗಿಡ್ಡ timezone;
    ಗಿಡ್ಡ dstflag;
  };

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
  ರಚನೆ timeb {
    time_t ಸಮಯ;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ millitm;
    ಗಿಡ್ಡ timezone;
    ಗಿಡ್ಡ dstflag;
  };
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  ರಚನೆ __timeb64 {
    __time64_t ಸಮಯ;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ millitm;
    ಗಿಡ್ಡ timezone;
    ಗಿಡ್ಡ dstflag;
  };
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
#ವ್ಯಾಖ್ಯಾನಿಸು _timeb __timeb32
//gr #define _ftime _ftime32
#ವ್ಯಾಖ್ಯಾನಿಸು _ftime32 _ftime
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _timeb __timeb64
#ವ್ಯಾಖ್ಯಾನಿಸು _ftime _ftime64
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP ಶೂನ್ಯ __cdecl _ftime32(ರಚನೆ __timeb32 *ಸಮಯ_2);
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  _CRTIMP ಶೂನ್ಯ __cdecl _ftime64(ರಚನೆ __timeb64 *ಸಮಯ_2);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIMESPEC_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _TIMESPEC_DEFINED
ರಚನೆ timespec {
  time_t  tv_sec;   /* Seconds */
  ದೀರ್ಘ    tv_nsec;  /* Nanoseconds */
};

ರಚನೆ itimerspec {
  ರಚನೆ timespec  it_interval;  /* Timer period */
  ರಚನೆ timespec  it_value;     /* Timer expiration */
};
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
__CRT_INLINE ಶೂನ್ಯ __cdecl ftime(ರಚನೆ timeb *_Tmb) {
  _ftime32((ರಚನೆ __timeb32 *)_Tmb);
}
#ಇಲ್ಲದಿದ್ದರೆ
__CRT_INLINE ಶೂನ್ಯ __cdecl ftime(ರಚನೆ timeb *_Tmb) {
  _ftime64((ರಚನೆ __timeb64 *)_Tmb);
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ pack(ತೆಗೆ)

#ಅನ್ತರ್ಭಾವ <sec_api/sys/timeb_s.h>
#ಆದರೆ_ಅಂತ್ಯ
