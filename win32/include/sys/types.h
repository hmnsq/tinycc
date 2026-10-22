/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_TYPES
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_TYPES

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
#ದೋಷ Only Win32 ಗುರಿ is supported!
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __TINYC__ /* gr */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು USE_32_ಬಿಟ್_ಸಮಯ_T
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು < 64
#ವ್ಯಾಖ್ಯಾನಿಸು USE_32_ಬಿಟ್_ಸಮಯ_T
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIME32_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _TIME32_T_DEFINED
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ __time32_t;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIME64_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _TIME64_T_DEFINED
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __int64 __time64_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ಸಮಯ_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಮಯ_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __time32_t time_t;
#ಇಲ್ಲದಿದ್ದರೆ
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __time64_t time_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INO_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _INO_T_DEFINED
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ _ino_t;
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ino_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _DEV_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _DEV_T_DEFINED
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _dev_t;
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ dev_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _PID_T_
#ವ್ಯಾಖ್ಯಾನಿಸು	_PID_T_
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN64
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ	_pid_t;
#ಇಲ್ಲದಿದ್ದರೆ
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __int64	_pid_t;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _pid_t	pid_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ	/* Not _PID_T_ */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ಬಹುಲಕ_T
#ವ್ಯಾಖ್ಯಾನಿಸು	ಬಹುಲಕ_T
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಬಹುಲಕ_t;

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಬಹುಲಕ_t	mode_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ	/* Not _MODE_T_ */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _OFF_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _OFF_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _OFF_T_
#ವ್ಯಾಖ್ಯಾನಿಸು _OFF_T_
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ _off_t;
#ಆದರೆ !defined(NO_OLDNAMES) || defined(_POSIX)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ off_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _OFF64_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _OFF64_T_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ ದೀರ್ಘ _off64_t;
#ಆದರೆ !defined(NO_OLDNAMES) || defined(_POSIX)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ ದೀರ್ಘ off64_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

/* required by (unbundled) unistd.h for usleep arg type */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __NO_ISOCEXT
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ useconds_t;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIMESPEC_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _TIMESPEC_DEFINED
ರಚನೆ timespec {
  time_t  tv_sec;   /* Seconds */
  ದೀರ್ಘ    tv_nsec;  /* Nanoseconds */
};

ರಚನೆ itimerspec {
  ರಚನೆ timespec  it_interval;  /* Timer period */
  ರಚನೆ timespec  it_value;     /* Timer expiration */
};
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ_ಅಂತ್ಯ
