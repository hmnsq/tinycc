/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_TYPES
#define _INC_TYPES

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#ଅନ୍ତର୍ଭାଵ <_mingw.h>

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#ଅନ୍ୟଥା
#ଯଦି _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
ପ୍ରକାରବ୍ୟାଖ୍ୟା long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#ଯଦି _INTEGRAL_MAX_BITS >= 64
ପ୍ରକାରବ୍ୟାଖ୍ୟା __int64 __time64_t;
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
ପ୍ରକାରବ୍ୟାଖ୍ୟା __time32_t time_t;
#ଅନ୍ୟଥା
ପ୍ରକାରବ୍ୟାଖ୍ୟା __time64_t time_t;
#endif
#endif

#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned short _ino_t;
#ifndef	NO_OLDNAMES
ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned short ino_t;
#endif
#endif

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _dev_t;
#ifndef	NO_OLDNAMES
ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା dev_t;
#endif
#endif

#ifndef _PID_T_
#define	_PID_T_
#ifndef _WIN64
ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା	_pid_t;
#ଅନ୍ୟଥା
ପ୍ରକାରବ୍ୟାଖ୍ୟା __int64	_pid_t;
#endif

#ifndef	NO_OLDNAMES
ପ୍ରକାରବ୍ୟାଖ୍ୟା _pid_t	pid_t;
#endif
#endif	/* Not _PID_T_ */

#ifndef _MODE_T_
#define	_MODE_T_
ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned short _mode_t;

#ifndef	NO_OLDNAMES
ପ୍ରକାରବ୍ୟାଖ୍ୟା _mode_t	mode_t;
#endif
#endif	/* Not _MODE_T_ */

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long _off_t;
#ଯଦି !defined(NO_OLDNAMES) || defined(_POSIX)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long long _off64_t;
#ଯଦି !defined(NO_OLDNAMES) || defined(_POSIX)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long long off64_t;
#endif
#endif

/* required by (unbundled) unistd.h for usleep arg type */
#ifndef __NO_ISOCEXT
ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା useconds_t;
#endif

#ifndef _TIMESPEC_DEFINED
#define _TIMESPEC_DEFINED
ସଂରଚନା timespec {
  time_t  tv_sec;   /* Seconds */
  long    tv_nsec;  /* Nanoseconds */
};

ସଂରଚନା itimerspec {
  ସଂରଚନା timespec  it_interval;  /* Timer period */
  ସଂରଚନା timespec  it_value;     /* Timer expiration */
};
#endif

#endif
