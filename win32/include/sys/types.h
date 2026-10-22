/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_TYPES
#وصف_ڪريو _INC_TYPES

#جيڪڏهن_وصف_نه_ٿيل _WIN32
#غلطي Only Win32 هدف is supported!
#جيڪڏهن_پورو

#ضمن <_mingw.h>

#جيڪڏهن_وصف_نه_ٿيل __TINYC__ /* gr */
#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
#جيڪڏهن_وصف_ٿيل _WIN64
#وصف_رد USE_32_ٻٽو_انگ_وقت_T
#جيڪڏهن_پورو
#وإلا
#إذا INTEGRAL_MAX_بٽ < 64
#وصف_ڪريو USE_32_ٻٽو_انگ_وقت_T
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TIME32_T_DEFINED
#وصف_ڪريو _TIME32_T_DEFINED
تعريفنوع ڊگهو __time32_t;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TIME64_T_DEFINED
#وصف_ڪريو _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بٽ >= 64
تعريفنوع __int64 __time64_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل وقت_T_DEFINED
#وصف_ڪريو وقت_T_DEFINED
#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
تعريفنوع __time32_t time_t;
#وإلا
تعريفنوع __time64_t time_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _INO_T_DEFINED
#وصف_ڪريو _INO_T_DEFINED
تعريفنوع بنانشان ننڍو _ino_t;
#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
تعريفنوع بنانشان ننڍو ino_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _DEV_T_DEFINED
#وصف_ڪريو _DEV_T_DEFINED
تعريفنوع بنانشان صحيح _dev_t;
#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
تعريفنوع بنانشان صحيح dev_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _PID_T_
#وصف_ڪريو	_PID_T_
#جيڪڏهن_وصف_نه_ٿيل _WIN64
تعريفنوع صحيح	_pid_t;
#وإلا
تعريفنوع __int64	_pid_t;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
تعريفنوع _pid_t	pid_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو	/* Not _PID_T_ */

#جيڪڏهن_وصف_نه_ٿيل گهڻائي_T
#وصف_ڪريو	گهڻائي_T
تعريفنوع بنانشان ننڍو گهڻائي_t;

#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
تعريفنوع گهڻائي_t	mode_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو	/* Not _MODE_T_ */

#جيڪڏهن_وصف_نه_ٿيل _OFF_T_DEFINED
#وصف_ڪريو _OFF_T_DEFINED
#جيڪڏهن_وصف_نه_ٿيل _OFF_T_
#وصف_ڪريو _OFF_T_
  تعريفنوع ڊگهو _off_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع ڊگهو off_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _OFF64_T_DEFINED
#وصف_ڪريو _OFF64_T_DEFINED
  تعريفنوع ڊگهو ڊگهو _off64_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع ڊگهو ڊگهو off64_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

/* required by (unbundled) unistd.h for usleep arg type */
#جيڪڏهن_وصف_نه_ٿيل __NO_ISOCEXT
تعريفنوع بنانشان صحيح useconds_t;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TIMESPEC_DEFINED
#وصف_ڪريو _TIMESPEC_DEFINED
بنية timespec {
  time_t  tv_sec;   /* Seconds */
  ڊگهو    tv_nsec;  /* Nanoseconds */
};

بنية itimerspec {
  بنية timespec  it_interval;  /* Timer period */
  بنية timespec  it_value;     /* Timer expiration */
};
#جيڪڏهن_پورو

#جيڪڏهن_پورو
