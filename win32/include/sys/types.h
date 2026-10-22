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

#ضمن <_mingw.h>

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#وإلا
#𐡄𐡍 _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
تعريفنوع long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#𐡄𐡍 _INTEGRAL_MAX_BITS >= 64
تعريفنوع __int64 __time64_t;
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
تعريفنوع __time32_t time_t;
#وإلا
تعريفنوع __time64_t time_t;
#endif
#endif

#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
تعريفنوع unsigned short _ino_t;
#ifndef	NO_OLDNAMES
تعريفنوع unsigned short ino_t;
#endif
#endif

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
تعريفنوع unsigned صحيح _dev_t;
#ifndef	NO_OLDNAMES
تعريفنوع unsigned صحيح dev_t;
#endif
#endif

#ifndef _PID_T_
#define	_PID_T_
#ifndef _WIN64
تعريفنوع صحيح	_pid_t;
#وإلا
تعريفنوع __int64	_pid_t;
#endif

#ifndef	NO_OLDNAMES
تعريفنوع _pid_t	pid_t;
#endif
#endif	/* Not _PID_T_ */

#ifndef _MODE_T_
#define	_MODE_T_
تعريفنوع unsigned short _mode_t;

#ifndef	NO_OLDNAMES
تعريفنوع _mode_t	mode_t;
#endif
#endif	/* Not _MODE_T_ */

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  تعريفنوع long _off_t;
#𐡄𐡍 !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  تعريفنوع long long _off64_t;
#𐡄𐡍 !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع long long off64_t;
#endif
#endif

/* required by (unbundled) unistd.h for usleep arg type */
#ifndef __NO_ISOCEXT
تعريفنوع unsigned صحيح useconds_t;
#endif

#ifndef _TIMESPEC_DEFINED
#define _TIMESPEC_DEFINED
بنية timespec {
  time_t  tv_sec;   /* Seconds */
  long    tv_nsec;  /* Nanoseconds */
};

بنية itimerspec {
  بنية timespec  it_interval;  /* Timer period */
  بنية timespec  it_value;     /* Timer expiration */
};
#endif

#endif
