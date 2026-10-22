/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#अगर_अघोषित _SYS_TIME_H_
#घोषणा _SYS_TIME_H_

#समावेश <time.h>

#अगर_घोषित  __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित __STRICT_ANSI__
#अगर_अघोषित _TIMEVAL_DEFINED /* also in winsock[2].h */
#घोषणा _TIMEVAL_DEFINED
काष्ठा timeval {
  दीर्घ tv_sec;
  दीर्घ tv_usec;
};
#घोषणा timerisset(tvp)	 ((tvp)->tv_sec || (tvp)->tv_usec)
#घोषणा timercmp(tvp, uvp, cmp) \
  (((tvp)->tv_sec != (uvp)->tv_sec) ? \
  ((tvp)->tv_sec cmp (uvp)->tv_sec) : \
  ((tvp)->tv_usec cmp (uvp)->tv_usec))
#घोषणा timerclear(tvp)	 (tvp)->tv_sec = (tvp)->tv_usec = 0
#पूर्ण_अगर /* _TIMEVAL_DEFINED */

#अगर_अघोषित _TIMEZONE_DEFINED /* also in sys/time.h */
#घोषणा _TIMEZONE_DEFINED
/* Provided for compatibility with code that assumes that
   the presence of gettimeofday function implies a definition
   of struct timezone. */
काष्ठा timezone
{
  पूर्णांक tz_minuteswest; /* of Greenwich */
  पूर्णांक tz_dsttime;     /* type of dst correction to apply */
};

  बाह्य पूर्णांक __cdecl mingw_gettimeofday (काष्ठा timeval *p, काष्ठा timezone *z);

#पूर्ण_अगर

/*
   Implementation as per:
   The Open Group Base Specifications, Issue 6
   IEEE Std 1003.1, 2004 Edition

   The timezone pointer arg is ignored.  Errors are ignored.
*/
#अगर_अघोषित _GETTIMEOFDAY_DEFINED
#घोषणा _GETTIMEOFDAY_DEFINED
पूर्णांक __cdecl gettimeofday(काष्ठा timeval *__restrict__,
                         व्योम *__restrict__  /* tzp (unused) */);
#पूर्ण_अगर

#पूर्ण_अगर /* __STRICT_ANSI__ */

#अगर_घोषित  __cplusplus
}
#पूर्ण_अगर

/* Adding timespec definition.  */
#समावेश <sys/timeb.h>


#पूर्ण_अगर /* _SYS_TIME_H_ */
