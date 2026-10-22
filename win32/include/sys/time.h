/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#جے_بنا_تعریف SYS_ویلا_H
#تعریف_کرو SYS_ویلا_H

#ضمن <time.h>

#جے_تعریف_شدہ  __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف __STRICT_ANSI__
#جے_بنا_تعریف _TIMEVAL_DEFINED /* also in winsock[2].h */
#تعریف_کرو _TIMEVAL_DEFINED
بنية timeval {
  لما tv_sec;
  لما tv_usec;
};
#تعریف_کرو timerisset(tvp)	 ((tvp)->tv_sec || (tvp)->tv_usec)
#تعریف_کرو timercmp(tvp, uvp, cmp) \
  (((tvp)->tv_sec != (uvp)->tv_sec) ? \
  ((tvp)->tv_sec cmp (uvp)->tv_sec) : \
  ((tvp)->tv_usec cmp (uvp)->tv_usec))
#تعریف_کرو timerclear(tvp)	 (tvp)->tv_sec = (tvp)->tv_usec = 0
#جے_انت /* _TIMEVAL_DEFINED */

#جے_بنا_تعریف _TIMEZONE_DEFINED /* also in sys/time.h */
#تعریف_کرو _TIMEZONE_DEFINED
/* Provided for compatibility with code that assumes that
   the presence of gettimeofday function implies a definition
   of struct timezone. */
بنية timezone
{
  صحيح tz_minuteswest; /* of Greenwich */
  صحيح tz_dsttime;     /* type of dst correction to apply */
};

  خارجي صحيح __cdecl mingw_gettimeofday (بنية timeval *p, بنية timezone *z);

#جے_انت

/*
   Implementation as per:
   The Open Group Base Specifications, Issue 6
   IEEE Std 1003.1, 2004 Edition

   The timezone pointer arg is ignored.  Errors are ignored.
*/
#جے_بنا_تعریف _GETTIMEOFDAY_DEFINED
#تعریف_کرو _GETTIMEOFDAY_DEFINED
صحيح __cdecl gettimeofday(بنية timeval *__restrict__,
                         فراغ *__restrict__  /* tzp (unused) */);
#جے_انت

#جے_انت /* __STRICT_ANSI__ */

#جے_تعریف_شدہ  __cplusplus
}
#جے_انت

/* Adding timespec definition.  */
#ضمن <sys/timeb.h>


#جے_انت /* _SYS_TIME_H_ */
