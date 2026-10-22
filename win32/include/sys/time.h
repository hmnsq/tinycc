/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#నిర్వచితం_కాకపోతే SYS_సమయం_H
#నిర్వచించు SYS_సమయం_H

#అన్తర్భావ <time.h>

#నిర్వచితమైతే  __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే __STRICT_ANSI__
#నిర్వచితం_కాకపోతే _TIMEVAL_DEFINED /* also in winsock[2].h */
#నిర్వచించు _TIMEVAL_DEFINED
నిర్మాణం timeval {
  దీర్ఘ tv_sec;
  దీర్ఘ tv_usec;
};
#నిర్వచించు timerisset(tvp)	 ((tvp)->tv_sec || (tvp)->tv_usec)
#నిర్వచించు timercmp(tvp, uvp, cmp) \
  (((tvp)->tv_sec != (uvp)->tv_sec) ? \
  ((tvp)->tv_sec cmp (uvp)->tv_sec) : \
  ((tvp)->tv_usec cmp (uvp)->tv_usec))
#నిర్వచించు timerclear(tvp)	 (tvp)->tv_sec = (tvp)->tv_usec = 0
#అయితే_ముగింపు /* _TIMEVAL_DEFINED */

#నిర్వచితం_కాకపోతే _TIMEZONE_DEFINED /* also in sys/time.h */
#నిర్వచించు _TIMEZONE_DEFINED
/* Provided for compatibility with code that assumes that
   the presence of gettimeofday function implies a definition
   of struct timezone. */
నిర్మాణం timezone
{
  పూర్ణాంకం tz_minuteswest; /* of Greenwich */
  పూర్ణాంకం tz_dsttime;     /* type of dst correction to apply */
};

  బాహ్య పూర్ణాంకం __cdecl mingw_gettimeofday (నిర్మాణం timeval *p, నిర్మాణం timezone *z);

#అయితే_ముగింపు

/*
   Implementation as per:
   The Open Group Base Specifications, Issue 6
   IEEE Std 1003.1, 2004 Edition

   The timezone pointer arg is ignored.  Errors are ignored.
*/
#నిర్వచితం_కాకపోతే _GETTIMEOFDAY_DEFINED
#నిర్వచించు _GETTIMEOFDAY_DEFINED
పూర్ణాంకం __cdecl gettimeofday(నిర్మాణం timeval *__restrict__,
                         శూన్య *__restrict__  /* tzp (unused) */);
#అయితే_ముగింపు

#అయితే_ముగింపు /* __STRICT_ANSI__ */

#నిర్వచితమైతే  __cplusplus
}
#అయితే_ముగింపు

/* Adding timespec definition.  */
#అన్తర్భావ <sys/timeb.h>


#అయితే_ముగింపు /* _SYS_TIME_H_ */
