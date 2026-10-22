/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_TYPES
#నిర్వచించు _INC_TYPES

#నిర్వచితం_కాకపోతే _WIN32
#దోషం Only Win32 లక్ష్యం is supported!
#అయితే_ముగింపు

#అన్తర్భావ <_mingw.h>

#నిర్వచితం_కాకపోతే __TINYC__ /* gr */
#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
#నిర్వచితమైతే _WIN64
#నిర్వచనం_రద్దు USE_32_బిట్టు_సమయం_T
#అయితే_ముగింపు
#లేకపోతే
#ఒకవేళ INTEGRAL_MAX_బిట్లు < 64
#నిర్వచించు USE_32_బిట్టు_సమయం_T
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TIME32_T_DEFINED
#నిర్వచించు _TIME32_T_DEFINED
రకనిర్వచనం దీర్ఘ __time32_t;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TIME64_T_DEFINED
#నిర్వచించు _TIME64_T_DEFINED
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
రకనిర్వచనం __int64 __time64_t;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే సమయం_T_DEFINED
#నిర్వచించు సమయం_T_DEFINED
#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
రకనిర్వచనం __time32_t time_t;
#లేకపోతే
రకనిర్వచనం __time64_t time_t;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _INO_T_DEFINED
#నిర్వచించు _INO_T_DEFINED
రకనిర్వచనం గుర్తులేని పొట్టి _ino_t;
#నిర్వచితం_కాకపోతే	NO_OLDNAMES
రకనిర్వచనం గుర్తులేని పొట్టి ino_t;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _DEV_T_DEFINED
#నిర్వచించు _DEV_T_DEFINED
రకనిర్వచనం గుర్తులేని పూర్ణాంకం _dev_t;
#నిర్వచితం_కాకపోతే	NO_OLDNAMES
రకనిర్వచనం గుర్తులేని పూర్ణాంకం dev_t;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _PID_T_
#నిర్వచించు	_PID_T_
#నిర్వచితం_కాకపోతే _WIN64
రకనిర్వచనం పూర్ణాంకం	_pid_t;
#లేకపోతే
రకనిర్వచనం __int64	_pid_t;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే	NO_OLDNAMES
రకనిర్వచనం _pid_t	pid_t;
#అయితే_ముగింపు
#అయితే_ముగింపు	/* Not _PID_T_ */

#నిర్వచితం_కాకపోతే బహుళకం_T
#నిర్వచించు	బహుళకం_T
రకనిర్వచనం గుర్తులేని పొట్టి బహుళకం_t;

#నిర్వచితం_కాకపోతే	NO_OLDNAMES
రకనిర్వచనం బహుళకం_t	mode_t;
#అయితే_ముగింపు
#అయితే_ముగింపు	/* Not _MODE_T_ */

#నిర్వచితం_కాకపోతే _OFF_T_DEFINED
#నిర్వచించు _OFF_T_DEFINED
#నిర్వచితం_కాకపోతే _OFF_T_
#నిర్వచించు _OFF_T_
  రకనిర్వచనం దీర్ఘ _off_t;
#ఒకవేళ !defined(NO_OLDNAMES) || defined(_POSIX)
  రకనిర్వచనం దీర్ఘ off_t;
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _OFF64_T_DEFINED
#నిర్వచించు _OFF64_T_DEFINED
  రకనిర్వచనం దీర్ఘ దీర్ఘ _off64_t;
#ఒకవేళ !defined(NO_OLDNAMES) || defined(_POSIX)
  రకనిర్వచనం దీర్ఘ దీర్ఘ off64_t;
#అయితే_ముగింపు
#అయితే_ముగింపు

/* required by (unbundled) unistd.h for usleep arg type */
#నిర్వచితం_కాకపోతే __NO_ISOCEXT
రకనిర్వచనం గుర్తులేని పూర్ణాంకం useconds_t;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TIMESPEC_DEFINED
#నిర్వచించు _TIMESPEC_DEFINED
నిర్మాణం timespec {
  time_t  tv_sec;   /* Seconds */
  దీర్ఘ    tv_nsec;  /* Nanoseconds */
};

నిర్మాణం itimerspec {
  నిర్మాణం timespec  it_interval;  /* Timer period */
  నిర్మాణం timespec  it_value;     /* Timer expiration */
};
#అయితే_ముగింపు

#అయితే_ముగింపు
