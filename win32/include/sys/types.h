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

#अन्तर्भाव <_mingw.h>

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#अन्यथा
#जर _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
प्रकारव्याख्या दीर्घ __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#जर _INTEGRAL_MAX_BITS >= 64
प्रकारव्याख्या __int64 __time64_t;
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
प्रकारव्याख्या __time32_t समय_प्रकार;
#अन्यथा
प्रकारव्याख्या __time64_t समय_प्रकार;
#endif
#endif

#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
प्रकारव्याख्या अचिन्हित लघु _ino_t;
#ifndef	NO_OLDNAMES
प्रकारव्याख्या अचिन्हित लघु ino_t;
#endif
#endif

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
प्रकारव्याख्या अचिन्हित पूर्णांक _dev_t;
#ifndef	NO_OLDNAMES
प्रकारव्याख्या अचिन्हित पूर्णांक dev_t;
#endif
#endif

#ifndef _PID_T_
#define	_PID_T_
#ifndef _WIN64
प्रकारव्याख्या पूर्णांक	_pid_t;
#अन्यथा
प्रकारव्याख्या __int64	_pid_t;
#endif

#ifndef	NO_OLDNAMES
प्रकारव्याख्या _pid_t	pid_t;
#endif
#endif	/* Not _PID_T_ */

#ifndef _MODE_T_
#define	_MODE_T_
प्रकारव्याख्या अचिन्हित लघु _mode_t;

#ifndef	NO_OLDNAMES
प्रकारव्याख्या _mode_t	mode_t;
#endif
#endif	/* Not _MODE_T_ */

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  प्रकारव्याख्या दीर्घ _off_t;
#जर !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारव्याख्या दीर्घ off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  प्रकारव्याख्या दीर्घ दीर्घ _off64_t;
#जर !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारव्याख्या दीर्घ दीर्घ off64_t;
#endif
#endif

/* required by (unbundled) unistd.h for usleep arg type */
#ifndef __NO_ISOCEXT
प्रकारव्याख्या अचिन्हित पूर्णांक useconds_t;
#endif

#ifndef _TIMESPEC_DEFINED
#define _TIMESPEC_DEFINED
संरचना timespec {
  समय_प्रकार  tv_sec;   /* Seconds */
  दीर्घ    tv_nsec;  /* Nanoseconds */
};

संरचना itimerspec {
  संरचना timespec  it_interval;  /* Timer period */
  संरचना timespec  it_value;     /* Timer expiration */
};
#endif

#endif
