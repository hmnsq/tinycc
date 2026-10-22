/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_TYPES
#تعریف_کړه _INC_TYPES

#که_نه_تعریف_شوی _WIN32
#تېروتنه Only Win32 موخه is supported!
#د_که_پای

#ضمن <_mingw.h>

#که_نه_تعریف_شوی __TINYC__ /* gr */
#که_تعریف_شوی USE_32_بټ_وخت_T
#که_تعریف_شوی _WIN64
#تعریف_لغوه USE_32_بټ_وخت_T
#د_که_پای
#وإلا
#إذا INTEGRAL_MAX_بټونه < 64
#تعریف_کړه USE_32_بټ_وخت_T
#د_که_پای
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _TIME32_T_DEFINED
#تعریف_کړه _TIME32_T_DEFINED
تعريفنوع اوږد __time32_t;
#د_که_پای

#که_نه_تعریف_شوی _TIME64_T_DEFINED
#تعریف_کړه _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بټونه >= 64
تعريفنوع __int64 __time64_t;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی وخت_T_DEFINED
#تعریف_کړه وخت_T_DEFINED
#که_تعریف_شوی USE_32_بټ_وخت_T
تعريفنوع __time32_t time_t;
#وإلا
تعريفنوع __time64_t time_t;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _INO_T_DEFINED
#تعریف_کړه _INO_T_DEFINED
تعريفنوع بینښه لنډ _ino_t;
#که_نه_تعریف_شوی	NO_OLDNAMES
تعريفنوع بینښه لنډ ino_t;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _DEV_T_DEFINED
#تعریف_کړه _DEV_T_DEFINED
تعريفنوع بینښه صحيح _dev_t;
#که_نه_تعریف_شوی	NO_OLDNAMES
تعريفنوع بینښه صحيح dev_t;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _PID_T_
#تعریف_کړه	_PID_T_
#که_نه_تعریف_شوی _WIN64
تعريفنوع صحيح	_pid_t;
#وإلا
تعريفنوع __int64	_pid_t;
#د_که_پای

#که_نه_تعریف_شوی	NO_OLDNAMES
تعريفنوع _pid_t	pid_t;
#د_که_پای
#د_که_پای	/* Not _PID_T_ */

#که_نه_تعریف_شوی ډېرپېښ_T
#تعریف_کړه	ډېرپېښ_T
تعريفنوع بینښه لنډ ډېرپېښ_t;

#که_نه_تعریف_شوی	NO_OLDNAMES
تعريفنوع ډېرپېښ_t	mode_t;
#د_که_پای
#د_که_پای	/* Not _MODE_T_ */

#که_نه_تعریف_شوی _OFF_T_DEFINED
#تعریف_کړه _OFF_T_DEFINED
#که_نه_تعریف_شوی _OFF_T_
#تعریف_کړه _OFF_T_
  تعريفنوع اوږد _off_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع اوږد off_t;
#د_که_پای
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _OFF64_T_DEFINED
#تعریف_کړه _OFF64_T_DEFINED
  تعريفنوع اوږد اوږد _off64_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع اوږد اوږد off64_t;
#د_که_پای
#د_که_پای

/* required by (unbundled) unistd.h for usleep arg type */
#که_نه_تعریف_شوی __NO_ISOCEXT
تعريفنوع بینښه صحيح useconds_t;
#د_که_پای

#که_نه_تعریف_شوی _TIMESPEC_DEFINED
#تعریف_کړه _TIMESPEC_DEFINED
بنية timespec {
  time_t  tv_sec;   /* Seconds */
  اوږد    tv_nsec;  /* Nanoseconds */
};

بنية itimerspec {
  بنية timespec  it_interval;  /* Timer period */
  بنية timespec  it_value;     /* Timer expiration */
};
#د_که_پای

#د_که_پای
