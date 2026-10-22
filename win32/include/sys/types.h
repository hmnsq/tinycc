/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_TYPES
#تعریف_کن _INC_TYPES

#اگر_تعریف_نشده _WIN32
#خطا Only Win32 هدف is supported!
#پایان_اگر

#ضمن <_mingw.h>

#اگر_تعریف_نشده __TINYC__ /* gr */
#اگر_تعریف_شده USE_32_بیت_زمان_T
#اگر_تعریف_شده _WIN64
#لغو_تعریف USE_32_بیت_زمان_T
#پایان_اگر
#وإلا
#إذا INTEGRAL_MAX_بیتها < 64
#تعریف_کن USE_32_بیت_زمان_T
#پایان_اگر
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _TIME32_T_DEFINED
#تعریف_کن _TIME32_T_DEFINED
تعريفنوع دراز __time32_t;
#پایان_اگر

#اگر_تعریف_نشده _TIME64_T_DEFINED
#تعریف_کن _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بیتها >= 64
تعريفنوع __int64 __time64_t;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده زمان_T_DEFINED
#تعریف_کن زمان_T_DEFINED
#اگر_تعریف_شده USE_32_بیت_زمان_T
تعريفنوع __time32_t time_t;
#وإلا
تعريفنوع __time64_t time_t;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _INO_T_DEFINED
#تعریف_کن _INO_T_DEFINED
تعريفنوع بیعلامت کوتاه _ino_t;
#اگر_تعریف_نشده	NO_OLDNAMES
تعريفنوع بیعلامت کوتاه ino_t;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _DEV_T_DEFINED
#تعریف_کن _DEV_T_DEFINED
تعريفنوع بیعلامت صحيح _dev_t;
#اگر_تعریف_نشده	NO_OLDNAMES
تعريفنوع بیعلامت صحيح dev_t;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _PID_T_
#تعریف_کن	_PID_T_
#اگر_تعریف_نشده _WIN64
تعريفنوع صحيح	_pid_t;
#وإلا
تعريفنوع __int64	_pid_t;
#پایان_اگر

#اگر_تعریف_نشده	NO_OLDNAMES
تعريفنوع _pid_t	pid_t;
#پایان_اگر
#پایان_اگر	/* Not _PID_T_ */

#اگر_تعریف_نشده نما_T
#تعریف_کن	نما_T
تعريفنوع بیعلامت کوتاه نما_t;

#اگر_تعریف_نشده	NO_OLDNAMES
تعريفنوع نما_t	mode_t;
#پایان_اگر
#پایان_اگر	/* Not _MODE_T_ */

#اگر_تعریف_نشده _OFF_T_DEFINED
#تعریف_کن _OFF_T_DEFINED
#اگر_تعریف_نشده _OFF_T_
#تعریف_کن _OFF_T_
  تعريفنوع دراز _off_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع دراز off_t;
#پایان_اگر
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _OFF64_T_DEFINED
#تعریف_کن _OFF64_T_DEFINED
  تعريفنوع دراز دراز _off64_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع دراز دراز off64_t;
#پایان_اگر
#پایان_اگر

/* required by (unbundled) unistd.h for usleep arg type */
#اگر_تعریف_نشده __NO_ISOCEXT
تعريفنوع بیعلامت صحيح useconds_t;
#پایان_اگر

#اگر_تعریف_نشده _TIMESPEC_DEFINED
#تعریف_کن _TIMESPEC_DEFINED
بنية timespec {
  time_t  tv_sec;   /* Seconds */
  دراز    tv_nsec;  /* Nanoseconds */
};

بنية itimerspec {
  بنية timespec  it_interval;  /* Timer period */
  بنية timespec  it_value;     /* Timer expiration */
};
#پایان_اگر

#پایان_اگر
