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

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#ಅನ್ಯಥಾ
#ಯದಿ _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
ಪ್ರಕಾರನಿರ್ದೇಶ long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#ಯದಿ _INTEGRAL_MAX_BITS >= 64
ಪ್ರಕಾರನಿರ್ದೇಶ __int64 __time64_t;
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
ಪ್ರಕಾರನಿರ್ದೇಶ __time32_t time_t;
#ಅನ್ಯಥಾ
ಪ್ರಕಾರನಿರ್ದೇಶ __time64_t time_t;
#endif
#endif

#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned short _ino_t;
#ifndef	NO_OLDNAMES
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned short ino_t;
#endif
#endif

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ _dev_t;
#ifndef	NO_OLDNAMES
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ dev_t;
#endif
#endif

#ifndef _PID_T_
#define	_PID_T_
#ifndef _WIN64
ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ	_pid_t;
#ಅನ್ಯಥಾ
ಪ್ರಕಾರನಿರ್ದೇಶ __int64	_pid_t;
#endif

#ifndef	NO_OLDNAMES
ಪ್ರಕಾರನಿರ್ದೇಶ _pid_t	pid_t;
#endif
#endif	/* Not _PID_T_ */

#ifndef _MODE_T_
#define	_MODE_T_
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned short _mode_t;

#ifndef	NO_OLDNAMES
ಪ್ರಕಾರನಿರ್ದೇಶ _mode_t	mode_t;
#endif
#endif	/* Not _MODE_T_ */

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  ಪ್ರಕಾರನಿರ್ದೇಶ long _off_t;
#ಯದಿ !defined(NO_OLDNAMES) || defined(_POSIX)
  ಪ್ರಕಾರನಿರ್ದೇಶ long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  ಪ್ರಕಾರನಿರ್ದೇಶ long long _off64_t;
#ಯದಿ !defined(NO_OLDNAMES) || defined(_POSIX)
  ಪ್ರಕಾರನಿರ್ದೇಶ long long off64_t;
#endif
#endif

/* required by (unbundled) unistd.h for usleep arg type */
#ifndef __NO_ISOCEXT
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ useconds_t;
#endif

#ifndef _TIMESPEC_DEFINED
#define _TIMESPEC_DEFINED
ಸಂರಚನಾ timespec {
  time_t  tv_sec;   /* Seconds */
  long    tv_nsec;  /* Nanoseconds */
};

ಸಂರಚನಾ itimerspec {
  ಸಂರಚನಾ timespec  it_interval;  /* Timer period */
  ಸಂರಚನಾ timespec  it_value;     /* Timer expiration */
};
#endif

#endif
