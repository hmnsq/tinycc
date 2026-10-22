/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_TYPES
#घोषणा _INC_TYPES

#अगर_अघोषित _WIN32
#त्रुटि Only Win32 target is supported!
#पूर्ण_अगर

#समावेश <_mingw.h>

#अगर_अघोषित __TINYC__ /* gr */
#अगर_घोषित _USE_32BIT_TIME_T
#अगर_घोषित _WIN64
#अघोषित _USE_32BIT_TIME_T
#पूर्ण_अगर
#अन्यथा
#अगर _INTEGRAL_MAX_BITS < 64
#घोषणा _USE_32BIT_TIME_T
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _TIME32_T_DEFINED
#घोषणा _TIME32_T_DEFINED
प्रकार दीर्घ __time32_t;
#पूर्ण_अगर

#अगर_अघोषित _TIME64_T_DEFINED
#घोषणा _TIME64_T_DEFINED
#अगर _INTEGRAL_MAX_BITS >= 64
प्रकार __int64 __time64_t;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _TIME_T_DEFINED
#घोषणा _TIME_T_DEFINED
#अगर_घोषित _USE_32BIT_TIME_T
प्रकार __time32_t समय_प्रकार;
#अन्यथा
प्रकार __time64_t समय_प्रकार;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _INO_T_DEFINED
#घोषणा _INO_T_DEFINED
प्रकार अचिन्हित लघु _ino_t;
#अगर_अघोषित	NO_OLDNAMES
प्रकार अचिन्हित लघु ino_t;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _DEV_T_DEFINED
#घोषणा _DEV_T_DEFINED
प्रकार अचिन्हित पूर्णांक _dev_t;
#अगर_अघोषित	NO_OLDNAMES
प्रकार अचिन्हित पूर्णांक dev_t;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _PID_T_
#घोषणा	_PID_T_
#अगर_अघोषित _WIN64
प्रकार पूर्णांक	_pid_t;
#अन्यथा
प्रकार __int64	_pid_t;
#पूर्ण_अगर

#अगर_अघोषित	NO_OLDNAMES
प्रकार _pid_t	pid_t;
#पूर्ण_अगर
#पूर्ण_अगर	/* Not _PID_T_ */

#अगर_अघोषित _MODE_T_
#घोषणा	_MODE_T_
प्रकार अचिन्हित लघु _mode_t;

#अगर_अघोषित	NO_OLDNAMES
प्रकार _mode_t	mode_t;
#पूर्ण_अगर
#पूर्ण_अगर	/* Not _MODE_T_ */

#अगर_अघोषित _OFF_T_DEFINED
#घोषणा _OFF_T_DEFINED
#अगर_अघोषित _OFF_T_
#घोषणा _OFF_T_
  प्रकार दीर्घ _off_t;
#अगर !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकार दीर्घ off_t;
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _OFF64_T_DEFINED
#घोषणा _OFF64_T_DEFINED
  प्रकार दीर्घ दीर्घ _off64_t;
#अगर !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकार दीर्घ दीर्घ off64_t;
#पूर्ण_अगर
#पूर्ण_अगर

/* required by (unbundled) unistd.h for usleep arg type */
#अगर_अघोषित __NO_ISOCEXT
प्रकार अचिन्हित पूर्णांक useconds_t;
#पूर्ण_अगर

#अगर_अघोषित _TIMESPEC_DEFINED
#घोषणा _TIMESPEC_DEFINED
काष्ठा timespec {
  समय_प्रकार  tv_sec;   /* Seconds */
  दीर्घ    tv_nsec;  /* Nanoseconds */
};

काष्ठा itimerspec {
  काष्ठा timespec  it_interval;  /* Timer period */
  काष्ठा timespec  it_value;     /* Timer expiration */
};
#पूर्ण_अगर

#पूर्ण_अगर
