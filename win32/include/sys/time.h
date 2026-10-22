/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ SYS_ਸਮਾਂ_H
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYS_ਸਮਾਂ_H

#ਅਨ੍ਤਰ੍ਭਾਵ <time.h>

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ  __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __STRICT_ANSI__
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIMEVAL_DEFINED /* also in winsock[2].h */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIMEVAL_DEFINED
ਬਣਤਰ timeval {
  ਲੰਮਾ tv_sec;
  ਲੰਮਾ tv_usec;
};
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ timerisset(tvp)	 ((tvp)->tv_sec || (tvp)->tv_usec)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ timercmp(tvp, uvp, cmp) \
  (((tvp)->tv_sec != (uvp)->tv_sec) ? \
  ((tvp)->tv_sec cmp (uvp)->tv_sec) : \
  ((tvp)->tv_usec cmp (uvp)->tv_usec))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ timerclear(tvp)	 (tvp)->tv_sec = (tvp)->tv_usec = 0
#ਜੇ_ਅੰਤ /* _TIMEVAL_DEFINED */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIMEZONE_DEFINED /* also in sys/time.h */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIMEZONE_DEFINED
/* Provided for compatibility with code that assumes that
   the presence of gettimeofday function implies a definition
   of struct timezone. */
ਬਣਤਰ timezone
{
  ਪੂਰਨ tz_minuteswest; /* of Greenwich */
  ਪੂਰਨ tz_dsttime;     /* type of dst correction to apply */
};

  ਬਾਹਰੀ ਪੂਰਨ __cdecl mingw_gettimeofday (ਬਣਤਰ timeval *p, ਬਣਤਰ timezone *z);

#ਜੇ_ਅੰਤ

/*
   Implementation as per:
   The Open Group Base Specifications, Issue 6
   IEEE Std 1003.1, 2004 Edition

   The timezone pointer arg is ignored.  Errors are ignored.
*/
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _GETTIMEOFDAY_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _GETTIMEOFDAY_DEFINED
ਪੂਰਨ __cdecl gettimeofday(ਬਣਤਰ timeval *__restrict__,
                         ਖਾਲੀ *__restrict__  /* tzp (unused) */);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ /* __STRICT_ANSI__ */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ  __cplusplus
}
#ਜੇ_ਅੰਤ

/* Adding timespec definition.  */
#ਅਨ੍ਤਰ੍ਭਾਵ <sys/timeb.h>


#ਜੇ_ਅੰਤ /* _SYS_TIME_H_ */
