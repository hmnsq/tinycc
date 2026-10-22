/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_TYPES
#परिभाषय _INC_TYPES

#यदि_अपरिभाषितम् _WIN32
#दोषः Only Win32 target is supported!
#यदि_अन्तः

#अन्तर्भाव <_mingw.h>

#यदि_अपरिभाषितम् __TINYC__ /* gr */
#यदि_परिभाषितम् _USE_32BIT_TIME_T
#यदि_परिभाषितम् _WIN64
#अपरिभाषय _USE_32BIT_TIME_T
#यदि_अन्तः
#अन्यथा
#यदि INTEGRAL_MAX_द्वयङ्काः < 64
#परिभाषय _USE_32BIT_TIME_T
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _TIME32_T_DEFINED
#परिभाषय _TIME32_T_DEFINED
प्रकारनिर्देश दीर्घ __time32_t;
#यदि_अन्तः

#यदि_अपरिभाषितम् _TIME64_T_DEFINED
#परिभाषय _TIME64_T_DEFINED
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
प्रकारनिर्देश __int64 __time64_t;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _TIME_T_DEFINED
#परिभाषय _TIME_T_DEFINED
#यदि_परिभाषितम् _USE_32BIT_TIME_T
प्रकारनिर्देश __time32_t time_t;
#अन्यथा
प्रकारनिर्देश __time64_t time_t;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _INO_T_DEFINED
#परिभाषय _INO_T_DEFINED
प्रकारनिर्देश अचिह्नित ह्रस्व _ino_t;
#यदि_अपरिभाषितम्	NO_OLDNAMES
प्रकारनिर्देश अचिह्नित ह्रस्व ino_t;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _DEV_T_DEFINED
#परिभाषय _DEV_T_DEFINED
प्रकारनिर्देश अचिह्नित पूर्णाङ्क _dev_t;
#यदि_अपरिभाषितम्	NO_OLDNAMES
प्रकारनिर्देश अचिह्नित पूर्णाङ्क dev_t;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _PID_T_
#परिभाषय	_PID_T_
#यदि_अपरिभाषितम् _WIN64
प्रकारनिर्देश पूर्णाङ्क	_pid_t;
#अन्यथा
प्रकारनिर्देश __int64	_pid_t;
#यदि_अन्तः

#यदि_अपरिभाषितम्	NO_OLDNAMES
प्रकारनिर्देश _pid_t	pid_t;
#यदि_अन्तः
#यदि_अन्तः	/* Not _PID_T_ */

#यदि_अपरिभाषितम् बहुलकम्_T
#परिभाषय	बहुलकम्_T
प्रकारनिर्देश अचिह्नित ह्रस्व बहुलकम्_t;

#यदि_अपरिभाषितम्	NO_OLDNAMES
प्रकारनिर्देश बहुलकम्_t	mode_t;
#यदि_अन्तः
#यदि_अन्तः	/* Not _MODE_T_ */

#यदि_अपरिभाषितम् _OFF_T_DEFINED
#परिभाषय _OFF_T_DEFINED
#यदि_अपरिभाषितम् _OFF_T_
#परिभाषय _OFF_T_
  प्रकारनिर्देश दीर्घ _off_t;
#यदि !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारनिर्देश दीर्घ off_t;
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _OFF64_T_DEFINED
#परिभाषय _OFF64_T_DEFINED
  प्रकारनिर्देश दीर्घ दीर्घ _off64_t;
#यदि !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारनिर्देश दीर्घ दीर्घ off64_t;
#यदि_अन्तः
#यदि_अन्तः

/* required by (unbundled) unistd.h for usleep arg type */
#यदि_अपरिभाषितम् __NO_ISOCEXT
प्रकारनिर्देश अचिह्नित पूर्णाङ्क useconds_t;
#यदि_अन्तः

#यदि_अपरिभाषितम् _TIMESPEC_DEFINED
#परिभाषय _TIMESPEC_DEFINED
संरचना timespec {
  time_t  tv_sec;   /* Seconds */
  दीर्घ    tv_nsec;  /* Nanoseconds */
};

संरचना itimerspec {
  संरचना timespec  it_interval;  /* Timer period */
  संरचना timespec  it_value;     /* Timer expiration */
};
#यदि_अन्तः

#यदि_अन्तः
