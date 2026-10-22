/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#جيڪڏهن_وصف_نه_ٿيل SYS_وقت_H
#وصف_ڪريو SYS_وقت_H

#ضمن <time.h>

#جيڪڏهن_وصف_ٿيل  __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل __STRICT_ANSI__
#جيڪڏهن_وصف_نه_ٿيل _TIMEVAL_DEFINED /* also in winsock[2].h */
#وصف_ڪريو _TIMEVAL_DEFINED
بنية timeval {
  ڊگهو tv_sec;
  ڊگهو tv_usec;
};
#وصف_ڪريو timerisset(tvp)	 ((tvp)->tv_sec || (tvp)->tv_usec)
#وصف_ڪريو timercmp(tvp, uvp, cmp) \
  (((tvp)->tv_sec != (uvp)->tv_sec) ? \
  ((tvp)->tv_sec cmp (uvp)->tv_sec) : \
  ((tvp)->tv_usec cmp (uvp)->tv_usec))
#وصف_ڪريو timerclear(tvp)	 (tvp)->tv_sec = (tvp)->tv_usec = 0
#جيڪڏهن_پورو /* _TIMEVAL_DEFINED */

#جيڪڏهن_وصف_نه_ٿيل _TIMEZONE_DEFINED /* also in sys/time.h */
#وصف_ڪريو _TIMEZONE_DEFINED
/* Provided for compatibility with code that assumes that
   the presence of gettimeofday function implies a definition
   of struct timezone. */
بنية timezone
{
  صحيح tz_minuteswest; /* of Greenwich */
  صحيح tz_dsttime;     /* type of dst correction to apply */
};

  خارجي صحيح __cdecl mingw_gettimeofday (بنية timeval *p, بنية timezone *z);

#جيڪڏهن_پورو

/*
   Implementation as per:
   The Open Group Base Specifications, Issue 6
   IEEE Std 1003.1, 2004 Edition

   The timezone pointer arg is ignored.  Errors are ignored.
*/
#جيڪڏهن_وصف_نه_ٿيل _GETTIMEOFDAY_DEFINED
#وصف_ڪريو _GETTIMEOFDAY_DEFINED
صحيح __cdecl gettimeofday(بنية timeval *__restrict__,
                         فراغ *__restrict__  /* tzp (unused) */);
#جيڪڏهن_پورو

#جيڪڏهن_پورو /* __STRICT_ANSI__ */

#جيڪڏهن_وصف_ٿيل  __cplusplus
}
#جيڪڏهن_پورو

/* Adding timespec definition.  */
#ضمن <sys/timeb.h>


#جيڪڏهن_پورو /* _SYS_TIME_H_ */
