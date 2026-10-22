/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_UTIME
#define _INC_UTIME

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#अन्तर्भाव <_mingw.h>

#pragma pack(धकेलो,_CRT_PACKING)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
  प्रकारनिर्देश unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#अन्यथा
#यदि _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  प्रकारनिर्देश long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#यदि _INTEGRAL_MAX_BITS >= 64
  प्रकारनिर्देश __int64 __time64_t;
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  प्रकारनिर्देश __time32_t time_t;
#अन्यथा
  प्रकारनिर्देश __time64_t time_t;
#endif
#endif

#ifndef _UTIMBUF_DEFINED
#define _UTIMBUF_DEFINED

  संरचना _utimbuf {
    time_t actime;
    time_t modtime;
  };

  संरचना __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#यदि _INTEGRAL_MAX_BITS >= 64
  संरचना __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#endif

#ifndef	NO_OLDNAMES
  संरचना utimbuf {
    time_t actime;
    time_t modtime;
  };

  संरचना utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#endif
#endif

  _CRTIMP पूर्णाङ्क __cdecl _utime32(ध्रुव वर्ण *_Filename,संरचना __utimbuf32 *_Time);
  _CRTIMP पूर्णाङ्क __cdecl _futime32(पूर्णाङ्क _FileDes,संरचना __utimbuf32 *_Time);
  _CRTIMP पूर्णाङ्क __cdecl _wutime32(ध्रुव wchar_t *_Filename,संरचना __utimbuf32 *_Time);
#यदि _INTEGRAL_MAX_BITS >= 64
  _CRTIMP पूर्णाङ्क __cdecl _utime64(ध्रुव वर्ण *_Filename,संरचना __utimbuf64 *_Time);
  _CRTIMP पूर्णाङ्क __cdecl _futime64(पूर्णाङ्क _FileDes,संरचना __utimbuf64 *_Time);
  _CRTIMP पूर्णाङ्क __cdecl _wutime64(ध्रुव wchar_t *_Filename,संरचना __utimbuf64 *_Time);
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
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
#endif

#ifndef	NO_OLDNAMES
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE पूर्णाङ्क __cdecl utime(ध्रुव वर्ण *_Filename,संरचना utimbuf *_Utimbuf) {
  प्रत्यागम _utime32(_Filename,(संरचना __utimbuf32 *)_Utimbuf);
}
#अन्यथा
__CRT_INLINE पूर्णाङ्क __cdecl utime(ध्रुव वर्ण *_Filename,संरचना utimbuf *_Utimbuf) {
  प्रत्यागम _utime64(_Filename,(संरचना __utimbuf64 *)_Utimbuf);
}
#endif
#endif
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(निकालो)
#endif
