/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_TYPES
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_TYPES

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
#ਗਲਤੀ Only Win32 ਨਿਸ਼ਾਨਾ is supported!
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __TINYC__ /* gr */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ < 64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIME32_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIME32_T_DEFINED
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ __time32_t;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIME64_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIME64_T_DEFINED
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
ਕਿਸਮਪਰਿਭਾਸ਼ਾ __int64 __time64_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ਸਮਾਂ_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮਾਂ_T_DEFINED
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
ਕਿਸਮਪਰਿਭਾਸ਼ਾ __time32_t time_t;
#ਨਹੀਂਤਾਂ
ਕਿਸਮਪਰਿਭਾਸ਼ਾ __time64_t time_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INO_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INO_T_DEFINED
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ _ino_t;
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ino_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _DEV_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _DEV_T_DEFINED
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _dev_t;
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ dev_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _PID_T_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	_PID_T_
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN64
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ	_pid_t;
#ਨਹੀਂਤਾਂ
ਕਿਸਮਪਰਿਭਾਸ਼ਾ __int64	_pid_t;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _pid_t	pid_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ	/* Not _PID_T_ */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ਬਹੁਲਕ_T
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	ਬਹੁਲਕ_T
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਬਹੁਲਕ_t;

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਹੁਲਕ_t	mode_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ	/* Not _MODE_T_ */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _OFF_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _OFF_T_DEFINED
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _OFF_T_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _OFF_T_
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ _off_t;
#ਜੇ !defined(NO_OLDNAMES) || defined(_POSIX)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ off_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _OFF64_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _OFF64_T_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ ਲੰਮਾ _off64_t;
#ਜੇ !defined(NO_OLDNAMES) || defined(_POSIX)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ ਲੰਮਾ off64_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

/* required by (unbundled) unistd.h for usleep arg type */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __NO_ISOCEXT
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ useconds_t;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIMESPEC_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIMESPEC_DEFINED
ਬਣਤਰ timespec {
  time_t  tv_sec;   /* Seconds */
  ਲੰਮਾ    tv_nsec;  /* Nanoseconds */
};

ਬਣਤਰ itimerspec {
  ਬਣਤਰ timespec  it_interval;  /* Timer period */
  ਬਣਤਰ timespec  it_value;     /* Timer expiration */
};
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ
