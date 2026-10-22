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

#അന്തര്ഭാവ <_mingw.h>

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#അല്ലെങ്കിൽ
#എങ്കിൽ _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
തരനിർവചനം long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
തരനിർവചനം __int64 __time64_t;
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
തരനിർവചനം __time32_t time_t;
#അല്ലെങ്കിൽ
തരനിർവചനം __time64_t time_t;
#endif
#endif

#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
തരനിർവചനം unsigned short _ino_t;
#ifndef	NO_OLDNAMES
തരനിർവചനം unsigned short ino_t;
#endif
#endif

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ _dev_t;
#ifndef	NO_OLDNAMES
തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ dev_t;
#endif
#endif

#ifndef _PID_T_
#define	_PID_T_
#ifndef _WIN64
തരനിർവചനം പൂർണ്ണസംഖ്യ	_pid_t;
#അല്ലെങ്കിൽ
തരനിർവചനം __int64	_pid_t;
#endif

#ifndef	NO_OLDNAMES
തരനിർവചനം _pid_t	pid_t;
#endif
#endif	/* Not _PID_T_ */

#ifndef _MODE_T_
#define	_MODE_T_
തരനിർവചനം unsigned short _mode_t;

#ifndef	NO_OLDNAMES
തരനിർവചനം _mode_t	mode_t;
#endif
#endif	/* Not _MODE_T_ */

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  തരനിർവചനം long _off_t;
#എങ്കിൽ !defined(NO_OLDNAMES) || defined(_POSIX)
  തരനിർവചനം long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  തരനിർവചനം long long _off64_t;
#എങ്കിൽ !defined(NO_OLDNAMES) || defined(_POSIX)
  തരനിർവചനം long long off64_t;
#endif
#endif

/* required by (unbundled) unistd.h for usleep arg type */
#ifndef __NO_ISOCEXT
തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ useconds_t;
#endif

#ifndef _TIMESPEC_DEFINED
#define _TIMESPEC_DEFINED
ഘടന timespec {
  time_t  tv_sec;   /* Seconds */
  long    tv_nsec;  /* Nanoseconds */
};

ഘടന itimerspec {
  ഘടന timespec  it_interval;  /* Timer period */
  ഘടന timespec  it_value;     /* Timer expiration */
};
#endif

#endif
