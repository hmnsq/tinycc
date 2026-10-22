/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ SYS_ಸಮಯ_H
#ವ್ಯಾಖ್ಯಾನಿಸು SYS_ಸಮಯ_H

#ಅನ್ತರ್ಭಾವ <time.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ  __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __STRICT_ANSI__
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIMEVAL_DEFINED /* also in winsock[2].h */
#ವ್ಯಾಖ್ಯಾನಿಸು _TIMEVAL_DEFINED
ರಚನೆ timeval {
  ದೀರ್ಘ tv_sec;
  ದೀರ್ಘ tv_usec;
};
#ವ್ಯಾಖ್ಯಾನಿಸು timerisset(tvp)	 ((tvp)->tv_sec || (tvp)->tv_usec)
#ವ್ಯಾಖ್ಯಾನಿಸು timercmp(tvp, uvp, cmp) \
  (((tvp)->tv_sec != (uvp)->tv_sec) ? \
  ((tvp)->tv_sec cmp (uvp)->tv_sec) : \
  ((tvp)->tv_usec cmp (uvp)->tv_usec))
#ವ್ಯಾಖ್ಯಾನಿಸು timerclear(tvp)	 (tvp)->tv_sec = (tvp)->tv_usec = 0
#ಆದರೆ_ಅಂತ್ಯ /* _TIMEVAL_DEFINED */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIMEZONE_DEFINED /* also in sys/time.h */
#ವ್ಯಾಖ್ಯಾನಿಸು _TIMEZONE_DEFINED
/* Provided for compatibility with code that assumes that
   the presence of gettimeofday function implies a definition
   of struct timezone. */
ರಚನೆ timezone
{
  ಪೂರ್ಣಾಂಕ tz_minuteswest; /* of Greenwich */
  ಪೂರ್ಣಾಂಕ tz_dsttime;     /* type of dst correction to apply */
};

  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl mingw_gettimeofday (ರಚನೆ timeval *p, ರಚನೆ timezone *z);

#ಆದರೆ_ಅಂತ್ಯ

/*
   Implementation as per:
   The Open Group Base Specifications, Issue 6
   IEEE Std 1003.1, 2004 Edition

   The timezone pointer arg is ignored.  Errors are ignored.
*/
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _GETTIMEOFDAY_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _GETTIMEOFDAY_DEFINED
ಪೂರ್ಣಾಂಕ __cdecl gettimeofday(ರಚನೆ timeval *__restrict__,
                         ಶೂನ್ಯ *__restrict__  /* tzp (unused) */);
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ_ಅಂತ್ಯ /* __STRICT_ANSI__ */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ  __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

/* Adding timespec definition.  */
#ಅನ್ತರ್ಭಾವ <sys/timeb.h>


#ಆದರೆ_ಅಂತ್ಯ /* _SYS_TIME_H_ */
