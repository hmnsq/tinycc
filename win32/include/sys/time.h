/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef _SYS_TIME_H_
#define _SYS_TIME_H_

#شامل <time.h>

#ifdef  __cplusplus
بیرونی "C" {
#endif

#ifndef __STRICT_ANSI__
#ifndef _TIMEVAL_DEFINED /* also in winsock[2].h */
#define _TIMEVAL_DEFINED
ساختار timeval {
  long tv_sec;
  long tv_usec;
};
#define timerisset(tvp)	 ((tvp)->tv_sec || (tvp)->tv_usec)
#define timercmp(tvp, uvp, cmp) \
  (((tvp)->tv_sec != (uvp)->tv_sec) ? \
  ((tvp)->tv_sec cmp (uvp)->tv_sec) : \
  ((tvp)->tv_usec cmp (uvp)->tv_usec))
#define timerclear(tvp)	 (tvp)->tv_sec = (tvp)->tv_usec = 0
#endif /* _TIMEVAL_DEFINED */

#ifndef _TIMEZONE_DEFINED /* also in sys/time.h */
#define _TIMEZONE_DEFINED
/* Provided for compatibility with code that assumes that
   the presence of gettimeofday function implies a definition
   of struct timezone. */
ساختار timezone
{
  صحیح tz_minuteswest; /* of Greenwich */
  صحیح tz_dsttime;     /* type of dst correction to apply */
};

  بیرونی صحیح __cdecl mingw_gettimeofday (ساختار timeval *p, ساختار timezone *z);

#endif

/*
   Implementation as per:
   The Open Group Base Specifications, Issue 6
   IEEE Std 1003.1, 2004 Edition

   The timezone pointer arg is ignored.  Errors are ignored.
*/
#ifndef _GETTIMEOFDAY_DEFINED
#define _GETTIMEOFDAY_DEFINED
صحیح __cdecl gettimeofday(ساختار timeval *__restrict__,
                         تهی *__restrict__  /* tzp (unused) */);
#endif

#endif /* __STRICT_ANSI__ */

#ifdef  __cplusplus
}
#endif

/* Adding timespec definition.  */
#شامل <sys/timeb.h>


#endif /* _SYS_TIME_H_ */
