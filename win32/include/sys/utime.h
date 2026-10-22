/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_UTIME
#परिभाषय _INC_UTIME

#यदि_अपरिभाषितम् _WIN32
#दोषः Only Win32 target is supported!
#यदि_अन्तः

#अन्तर्भाव <_mingw.h>

#निर्देशः pack(प्रक्षिप,_CRT_PACKING)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् _CRTIMP
#परिभाषय _CRTIMP __declspec(dllimport)
#यदि_अन्तः

#यदि_अपरिभाषितम् _WCHAR_T_DEFINED
  प्रकारनिर्देश अचिह्नित ह्रस्व wchar_t;
#परिभाषय _WCHAR_T_DEFINED
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

#यदि_अपरिभाषितम् _UTIMBUF_DEFINED
#परिभाषय _UTIMBUF_DEFINED

  संरचना _utimbuf {
    time_t actime;
    time_t modtime;
  };

  संरचना __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  संरचना __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#यदि_अन्तः

#यदि_अपरिभाषितम्	NO_OLDNAMES
  संरचना utimbuf {
    time_t actime;
    time_t modtime;
  };

  संरचना utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#यदि_अन्तः
#यदि_अन्तः

  _CRTIMP पूर्णाङ्क __cdecl _utime32(ध्रुव वर्ण *_Filename,संरचना __utimbuf32 *_Time);
  _CRTIMP पूर्णाङ्क __cdecl _futime32(पूर्णाङ्क _FileDes,संरचना __utimbuf32 *_Time);
  _CRTIMP पूर्णाङ्क __cdecl _wutime32(ध्रुव wchar_t *_Filename,संरचना __utimbuf32 *_Time);
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  _CRTIMP पूर्णाङ्क __cdecl _utime64(ध्रुव वर्ण *_Filename,संरचना __utimbuf64 *_Time);
  _CRTIMP पूर्णाङ्क __cdecl _futime64(पूर्णाङ्क _FileDes,संरचना __utimbuf64 *_Time);
  _CRTIMP पूर्णाङ्क __cdecl _wutime64(ध्रुव wchar_t *_Filename,संरचना __utimbuf64 *_Time);
#यदि_अन्तः

#यदि_अपरिभाषितम् RC_INVOKED
#यदि_परिभाषितम् _USE_32BIT_TIME_T
__CRT_INLINE पूर्णाङ्क __cdecl _utime(ध्रुव वर्ण *_Filename,संरचना _utimbuf *_Utimbuf) {
  प्रत्यागम _utime32(_Filename,(संरचना __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE पूर्णाङ्क __cdecl _futime(पूर्णाङ्क _Desc,संरचना _utimbuf *_Utimbuf) {
  प्रत्यागम _futime32(_Desc,(संरचना __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE पूर्णाङ्क __cdecl _wutime(ध्रुव wchar_t *_Filename,संरचना _utimbuf *_Utimbuf) {
  प्रत्यागम _wutime32(_Filename,(संरचना __utimbuf32 *)_Utimbuf);
}
#अन्यथा
__CRT_INLINE पूर्णाङ्क __cdecl _utime(ध्रुव वर्ण *_Filename,संरचना _utimbuf *_Utimbuf) {
  प्रत्यागम _utime64(_Filename,(संरचना __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE पूर्णाङ्क __cdecl _futime(पूर्णाङ्क _Desc,संरचना _utimbuf *_Utimbuf) {
  प्रत्यागम _futime64(_Desc,(संरचना __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE पूर्णाङ्क __cdecl _wutime(ध्रुव wchar_t *_Filename,संरचना _utimbuf *_Utimbuf) {
  प्रत्यागम _wutime64(_Filename,(संरचना __utimbuf64 *)_Utimbuf);
}
#यदि_अन्तः

#यदि_अपरिभाषितम्	NO_OLDNAMES
#यदि_परिभाषितम् _USE_32BIT_TIME_T
__CRT_INLINE पूर्णाङ्क __cdecl utime(ध्रुव वर्ण *_Filename,संरचना utimbuf *_Utimbuf) {
  प्रत्यागम _utime32(_Filename,(संरचना __utimbuf32 *)_Utimbuf);
}
#अन्यथा
__CRT_INLINE पूर्णाङ्क __cdecl utime(ध्रुव वर्ण *_Filename,संरचना utimbuf *_Utimbuf) {
  प्रत्यागम _utime64(_Filename,(संरचना __utimbuf64 *)_Utimbuf);
}
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#निर्देशः pack(निष्कासय)
#यदि_अन्तः
