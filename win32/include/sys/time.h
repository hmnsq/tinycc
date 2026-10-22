/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#यदि_अपरिभाषितम् _SYS_TIME_H_
#परिभाषय _SYS_TIME_H_

#अन्तर्भाव <time.h>

#यदि_परिभाषितम्  __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् __STRICT_ANSI__
#यदि_अपरिभाषितम् _TIMEVAL_DEFINED /* also in winsock[2].h */
#परिभाषय _TIMEVAL_DEFINED
संरचना timeval {
  दीर्घ tv_sec;
  दीर्घ tv_usec;
};
#परिभाषय timerisset(tvp)	 ((tvp)->tv_sec || (tvp)->tv_usec)
#परिभाषय timercmp(tvp, uvp, cmp) \
  (((tvp)->tv_sec != (uvp)->tv_sec) ? \
  ((tvp)->tv_sec cmp (uvp)->tv_sec) : \
  ((tvp)->tv_usec cmp (uvp)->tv_usec))
#परिभाषय timerclear(tvp)	 (tvp)->tv_sec = (tvp)->tv_usec = 0
#यदि_अन्तः /* _TIMEVAL_DEFINED */

#यदि_अपरिभाषितम् _TIMEZONE_DEFINED /* also in sys/time.h */
#परिभाषय _TIMEZONE_DEFINED
/* Provided for compatibility with code that assumes that
   the presence of gettimeofday function implies a definition
   of struct timezone. */
संरचना timezone
{
  पूर्णाङ्क tz_minuteswest; /* of Greenwich */
  पूर्णाङ्क tz_dsttime;     /* type of dst correction to apply */
};

  बाह्य पूर्णाङ्क __cdecl mingw_gettimeofday (संरचना timeval *p, संरचना timezone *z);

#यदि_अन्तः

/*
   Implementation as per:
   The Open Group Base Specifications, Issue 6
   IEEE Std 1003.1, 2004 Edition

   The timezone pointer arg is ignored.  Errors are ignored.
*/
#यदि_अपरिभाषितम् _GETTIMEOFDAY_DEFINED
#परिभाषय _GETTIMEOFDAY_DEFINED
पूर्णाङ्क __cdecl gettimeofday(संरचना timeval *__restrict__,
                         शून्य *__restrict__  /* tzp (unused) */);
#यदि_अन्तः

#यदि_अन्तः /* __STRICT_ANSI__ */

#यदि_परिभाषितम्  __cplusplus
}
#यदि_अन्तः

/* Adding timespec definition.  */
#अन्तर्भाव <sys/timeb.h>


#यदि_अन्तः /* _SYS_TIME_H_ */
