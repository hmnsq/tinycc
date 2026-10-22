/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _TIMEB_H_
#परिभाषय _TIMEB_H_

#अन्तर्भाव <_mingw.h>

#यदि_अपरिभाषितम् _WIN32
#दोषः Only Win32 target is supported!
#यदि_अन्तः

#निर्देशः pack(प्रक्षिप,_CRT_PACKING)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् _CRTIMP
#परिभाषय _CRTIMP __declspec(dllimport)
#यदि_अन्तः

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
  प्रकारनिर्देश दीर्घ __time32_t;
#परिभाषय _TIME32_T_DEFINED
#यदि_अन्तः

#यदि_अपरिभाषितम् _TIME64_T_DEFINED
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  प्रकारनिर्देश __int64 __time64_t;
#यदि_अन्तः
#परिभाषय _TIME64_T_DEFINED
#यदि_अन्तः

#यदि_अपरिभाषितम् _TIME_T_DEFINED
#यदि_परिभाषितम् _USE_32BIT_TIME_T
  प्रकारनिर्देश __time32_t time_t;
#अन्यथा
  प्रकारनिर्देश __time64_t time_t;
#यदि_अन्तः
#परिभाषय _TIME_T_DEFINED
#यदि_अन्तः

#यदि_अपरिभाषितम् _TIMEB_DEFINED
#परिभाषय _TIMEB_DEFINED

  संरचना __timeb32 {
    __time32_t time;
    अचिह्नित ह्रस्व millitm;
    ह्रस्व timezone;
    ह्रस्व dstflag;
  };

#यदि_अपरिभाषितम्	NO_OLDNAMES
  संरचना timeb {
    time_t time;
    अचिह्नित ह्रस्व millitm;
    ह्रस्व timezone;
    ह्रस्व dstflag;
  };
#यदि_अन्तः

#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  संरचना __timeb64 {
    __time64_t time;
    अचिह्नित ह्रस्व millitm;
    ह्रस्व timezone;
    ह्रस्व dstflag;
  };
#यदि_अन्तः

#यदि_परिभाषितम् _USE_32BIT_TIME_T
#परिभाषय _timeb __timeb32
//gr #define _ftime _ftime32
#परिभाषय _ftime32 _ftime
#अन्यथा
#परिभाषय _timeb __timeb64
#परिभाषय _ftime _ftime64
#यदि_अन्तः
#यदि_अन्तः

  _CRTIMP शून्य __cdecl _ftime32(संरचना __timeb32 *_Time);
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  _CRTIMP शून्य __cdecl _ftime64(संरचना __timeb64 *_Time);
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

#यदि !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
#यदि_परिभाषितम् _USE_32BIT_TIME_T
__CRT_INLINE शून्य __cdecl ftime(संरचना timeb *_Tmb) {
  _ftime32((संरचना __timeb32 *)_Tmb);
}
#अन्यथा
__CRT_INLINE शून्य __cdecl ftime(संरचना timeb *_Tmb) {
  _ftime64((संरचना __timeb64 *)_Tmb);
}
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#निर्देशः pack(निष्कासय)

#अन्तर्भाव <sec_api/sys/timeb_s.h>
#यदि_अन्तः
