/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#اگر_تعریف_نشده SYS_زمان_H
#تعریف_کن SYS_زمان_H

#ضمن <time.h>

#اگر_تعریف_شده  __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده __STRICT_ANSI__
#اگر_تعریف_نشده _TIMEVAL_DEFINED /* also in winsock[2].h */
#تعریف_کن _TIMEVAL_DEFINED
بنية timeval {
  دراز tv_sec;
  دراز tv_usec;
};
#تعریف_کن timerisset(tvp)	 ((tvp)->tv_sec || (tvp)->tv_usec)
#تعریف_کن timercmp(tvp, uvp, cmp) \
  (((tvp)->tv_sec != (uvp)->tv_sec) ? \
  ((tvp)->tv_sec cmp (uvp)->tv_sec) : \
  ((tvp)->tv_usec cmp (uvp)->tv_usec))
#تعریف_کن timerclear(tvp)	 (tvp)->tv_sec = (tvp)->tv_usec = 0
#پایان_اگر /* _TIMEVAL_DEFINED */

#اگر_تعریف_نشده _TIMEZONE_DEFINED /* also in sys/time.h */
#تعریف_کن _TIMEZONE_DEFINED
/* Provided for compatibility with code that assumes that
   the presence of gettimeofday function implies a definition
   of struct timezone. */
بنية timezone
{
  صحيح tz_minuteswest; /* of Greenwich */
  صحيح tz_dsttime;     /* type of dst correction to apply */
};

  خارجي صحيح __cdecl mingw_gettimeofday (بنية timeval *p, بنية timezone *z);

#پایان_اگر

/*
   Implementation as per:
   The Open Group Base Specifications, Issue 6
   IEEE Std 1003.1, 2004 Edition

   The timezone pointer arg is ignored.  Errors are ignored.
*/
#اگر_تعریف_نشده _GETTIMEOFDAY_DEFINED
#تعریف_کن _GETTIMEOFDAY_DEFINED
صحيح __cdecl gettimeofday(بنية timeval *__restrict__,
                         فراغ *__restrict__  /* tzp (unused) */);
#پایان_اگر

#پایان_اگر /* __STRICT_ANSI__ */

#اگر_تعریف_شده  __cplusplus
}
#پایان_اگر

/* Adding timespec definition.  */
#ضمن <sys/timeb.h>


#پایان_اگر /* _SYS_TIME_H_ */
