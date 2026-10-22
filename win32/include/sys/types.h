/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_TYPES
#تعریف_کرو _INC_TYPES

#اگر_غیر_تعریف_شدہ _WIN32
#غلطی Only Win32 ہدف is supported!
#اگر_ختم

#شامل <_mingw.h>

#اگر_غیر_تعریف_شدہ __TINYC__ /* gr */
#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
#اگر_تعریف_شدہ _WIN64
#تعریف_منسوخ USE_32_ثنائی_ہندسہ_وقت_T
#اگر_ختم
#ورنہ
#اگر INTEGRAL_MAX_بٹ < 64
#تعریف_کرو USE_32_ثنائی_ہندسہ_وقت_T
#اگر_ختم
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TIME32_T_DEFINED
#تعریف_کرو _TIME32_T_DEFINED
قسمتعریف طویل __time32_t;
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TIME64_T_DEFINED
#تعریف_کرو _TIME64_T_DEFINED
#اگر INTEGRAL_MAX_بٹ >= 64
قسمتعریف __int64 __time64_t;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ وقت_T_DEFINED
#تعریف_کرو وقت_T_DEFINED
#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
قسمتعریف __time32_t time_t;
#ورنہ
قسمتعریف __time64_t time_t;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _INO_T_DEFINED
#تعریف_کرو _INO_T_DEFINED
قسمتعریف غیرعلامتی مختصر _ino_t;
#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
قسمتعریف غیرعلامتی مختصر ino_t;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _DEV_T_DEFINED
#تعریف_کرو _DEV_T_DEFINED
قسمتعریف غیرعلامتی صحیح _dev_t;
#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
قسمتعریف غیرعلامتی صحیح dev_t;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _PID_T_
#تعریف_کرو	_PID_T_
#اگر_غیر_تعریف_شدہ _WIN64
قسمتعریف صحیح	_pid_t;
#ورنہ
قسمتعریف __int64	_pid_t;
#اگر_ختم

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
قسمتعریف _pid_t	pid_t;
#اگر_ختم
#اگر_ختم	/* Not _PID_T_ */

#اگر_غیر_تعریف_شدہ منوال_T
#تعریف_کرو	منوال_T
قسمتعریف غیرعلامتی مختصر منوال_t;

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
قسمتعریف منوال_t	mode_t;
#اگر_ختم
#اگر_ختم	/* Not _MODE_T_ */

#اگر_غیر_تعریف_شدہ _OFF_T_DEFINED
#تعریف_کرو _OFF_T_DEFINED
#اگر_غیر_تعریف_شدہ _OFF_T_
#تعریف_کرو _OFF_T_
  قسمتعریف طویل _off_t;
#اگر !defined(NO_OLDNAMES) || defined(_POSIX)
  قسمتعریف طویل off_t;
#اگر_ختم
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _OFF64_T_DEFINED
#تعریف_کرو _OFF64_T_DEFINED
  قسمتعریف طویل طویل _off64_t;
#اگر !defined(NO_OLDNAMES) || defined(_POSIX)
  قسمتعریف طویل طویل off64_t;
#اگر_ختم
#اگر_ختم

/* required by (unbundled) unistd.h for usleep arg type */
#اگر_غیر_تعریف_شدہ __NO_ISOCEXT
قسمتعریف غیرعلامتی صحیح useconds_t;
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TIMESPEC_DEFINED
#تعریف_کرو _TIMESPEC_DEFINED
ساخت timespec {
  time_t  tv_sec;   /* Seconds */
  طویل    tv_nsec;  /* Nanoseconds */
};

ساخت itimerspec {
  ساخت timespec  it_interval;  /* Timer period */
  ساخت timespec  it_value;     /* Timer expiration */
};
#اگر_ختم

#اگر_ختم
