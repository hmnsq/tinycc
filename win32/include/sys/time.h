/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#که_نه_تعریف_شوی SYS_وخت_H
#تعریف_کړه SYS_وخت_H

#ضمن <time.h>

#که_تعریف_شوی  __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی __STRICT_ANSI__
#که_نه_تعریف_شوی _TIMEVAL_DEFINED /* also in winsock[2].h */
#تعریف_کړه _TIMEVAL_DEFINED
بنية timeval {
  اوږد tv_sec;
  اوږد tv_usec;
};
#تعریف_کړه timerisset(tvp)	 ((tvp)->tv_sec || (tvp)->tv_usec)
#تعریف_کړه timercmp(tvp, uvp, cmp) \
  (((tvp)->tv_sec != (uvp)->tv_sec) ? \
  ((tvp)->tv_sec cmp (uvp)->tv_sec) : \
  ((tvp)->tv_usec cmp (uvp)->tv_usec))
#تعریف_کړه timerclear(tvp)	 (tvp)->tv_sec = (tvp)->tv_usec = 0
#د_که_پای /* _TIMEVAL_DEFINED */

#که_نه_تعریف_شوی _TIMEZONE_DEFINED /* also in sys/time.h */
#تعریف_کړه _TIMEZONE_DEFINED
/* Provided for compatibility with code that assumes that
   the presence of gettimeofday function implies a definition
   of struct timezone. */
بنية timezone
{
  صحيح tz_minuteswest; /* of Greenwich */
  صحيح tz_dsttime;     /* type of dst correction to apply */
};

  خارجي صحيح __cdecl mingw_gettimeofday (بنية timeval *p, بنية timezone *z);

#د_که_پای

/*
   Implementation as per:
   The Open Group Base Specifications, Issue 6
   IEEE Std 1003.1, 2004 Edition

   The timezone pointer arg is ignored.  Errors are ignored.
*/
#که_نه_تعریف_شوی _GETTIMEOFDAY_DEFINED
#تعریف_کړه _GETTIMEOFDAY_DEFINED
صحيح __cdecl gettimeofday(بنية timeval *__restrict__,
                         فراغ *__restrict__  /* tzp (unused) */);
#د_که_پای

#د_که_پای /* __STRICT_ANSI__ */

#که_تعریف_شوی  __cplusplus
}
#د_که_پای

/* Adding timespec definition.  */
#ضمن <sys/timeb.h>


#د_که_پای /* _SYS_TIME_H_ */
