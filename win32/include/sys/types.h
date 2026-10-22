/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _INC_TYPES
#تعریف_کرو _INC_TYPES

#جے_بنا_تعریف _WIN32
#غلطی Only Win32 نشانہ is supported!
#جے_انت

#ضمن <_mingw.h>

#جے_بنا_تعریف __TINYC__ /* gr */
#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
#جے_تعریف_شدہ _WIN64
#تعریف_رد USE_32_ثنائی_ہندسہ_ویلا_T
#جے_انت
#وإلا
#إذا INTEGRAL_MAX_بٹ < 64
#تعریف_کرو USE_32_ثنائی_ہندسہ_ویلا_T
#جے_انت
#جے_انت
#جے_انت

#جے_بنا_تعریف _TIME32_T_DEFINED
#تعریف_کرو _TIME32_T_DEFINED
تعريفنوع لما __time32_t;
#جے_انت

#جے_بنا_تعریف _TIME64_T_DEFINED
#تعریف_کرو _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بٹ >= 64
تعريفنوع __int64 __time64_t;
#جے_انت
#جے_انت

#جے_بنا_تعریف ویلا_T_DEFINED
#تعریف_کرو ویلا_T_DEFINED
#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
تعريفنوع __time32_t time_t;
#وإلا
تعريفنوع __time64_t time_t;
#جے_انت
#جے_انت

#جے_بنا_تعریف _INO_T_DEFINED
#تعریف_کرو _INO_T_DEFINED
تعريفنوع بنانشانی چھوٹا _ino_t;
#جے_بنا_تعریف	NO_OLDNAMES
تعريفنوع بنانشانی چھوٹا ino_t;
#جے_انت
#جے_انت

#جے_بنا_تعریف _DEV_T_DEFINED
#تعریف_کرو _DEV_T_DEFINED
تعريفنوع بنانشانی صحيح _dev_t;
#جے_بنا_تعریف	NO_OLDNAMES
تعريفنوع بنانشانی صحيح dev_t;
#جے_انت
#جے_انت

#جے_بنا_تعریف _PID_T_
#تعریف_کرو	_PID_T_
#جے_بنا_تعریف _WIN64
تعريفنوع صحيح	_pid_t;
#وإلا
تعريفنوع __int64	_pid_t;
#جے_انت

#جے_بنا_تعریف	NO_OLDNAMES
تعريفنوع _pid_t	pid_t;
#جے_انت
#جے_انت	/* Not _PID_T_ */

#جے_بنا_تعریف منوال_T
#تعریف_کرو	منوال_T
تعريفنوع بنانشانی چھوٹا منوال_t;

#جے_بنا_تعریف	NO_OLDNAMES
تعريفنوع منوال_t	mode_t;
#جے_انت
#جے_انت	/* Not _MODE_T_ */

#جے_بنا_تعریف _OFF_T_DEFINED
#تعریف_کرو _OFF_T_DEFINED
#جے_بنا_تعریف _OFF_T_
#تعریف_کرو _OFF_T_
  تعريفنوع لما _off_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع لما off_t;
#جے_انت
#جے_انت
#جے_انت

#جے_بنا_تعریف _OFF64_T_DEFINED
#تعریف_کرو _OFF64_T_DEFINED
  تعريفنوع لما لما _off64_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع لما لما off64_t;
#جے_انت
#جے_انت

/* required by (unbundled) unistd.h for usleep arg type */
#جے_بنا_تعریف __NO_ISOCEXT
تعريفنوع بنانشانی صحيح useconds_t;
#جے_انت

#جے_بنا_تعریف _TIMESPEC_DEFINED
#تعریف_کرو _TIMESPEC_DEFINED
بنية timespec {
  time_t  tv_sec;   /* Seconds */
  لما    tv_nsec;  /* Nanoseconds */
};

بنية itimerspec {
  بنية timespec  it_interval;  /* Timer period */
  بنية timespec  it_value;     /* Timer expiration */
};
#جے_انت

#جے_انت
