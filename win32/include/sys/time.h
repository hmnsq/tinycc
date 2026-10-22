/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#اگر_غیر_تعریف_شدہ SYS_وقت_H
#تعریف_کرو SYS_وقت_H

#شامل <time.h>

#اگر_تعریف_شدہ  __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ __STRICT_ANSI__
#اگر_غیر_تعریف_شدہ _TIMEVAL_DEFINED /* also in winsock[2].h */
#تعریف_کرو _TIMEVAL_DEFINED
ساخت timeval {
  طویل tv_sec;
  طویل tv_usec;
};
#تعریف_کرو timerisset(tvp)	 ((tvp)->tv_sec || (tvp)->tv_usec)
#تعریف_کرو timercmp(tvp, uvp, cmp) \
  (((tvp)->tv_sec != (uvp)->tv_sec) ? \
  ((tvp)->tv_sec cmp (uvp)->tv_sec) : \
  ((tvp)->tv_usec cmp (uvp)->tv_usec))
#تعریف_کرو timerclear(tvp)	 (tvp)->tv_sec = (tvp)->tv_usec = 0
#اگر_ختم /* _TIMEVAL_DEFINED */

#اگر_غیر_تعریف_شدہ _TIMEZONE_DEFINED /* also in sys/time.h */
#تعریف_کرو _TIMEZONE_DEFINED
/* Provided for compatibility with code that assumes that
   the presence of gettimeofday function implies a definition
   of struct timezone. */
ساخت timezone
{
  صحیح tz_minuteswest; /* of Greenwich */
  صحیح tz_dsttime;     /* type of dst correction to apply */
};

  خارجی صحیح __cdecl mingw_gettimeofday (ساخت timeval *p, ساخت timezone *z);

#اگر_ختم

/*
   Implementation as per:
   The Open Group Base Specifications, Issue 6
   IEEE Std 1003.1, 2004 Edition

   The timezone pointer arg is ignored.  Errors are ignored.
*/
#اگر_غیر_تعریف_شدہ _GETTIMEOFDAY_DEFINED
#تعریف_کرو _GETTIMEOFDAY_DEFINED
صحیح __cdecl gettimeofday(ساخت timeval *__restrict__,
                         خالی *__restrict__  /* tzp (unused) */);
#اگر_ختم

#اگر_ختم /* __STRICT_ANSI__ */

#اگر_تعریف_شدہ  __cplusplus
}
#اگر_ختم

/* Adding timespec definition.  */
#شامل <sys/timeb.h>


#اگر_ختم /* _SYS_TIME_H_ */
