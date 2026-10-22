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

#pragma pack(ढकला,_CRT_PACKING)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
  प्रकारव्याख्या अचिन्हित लघु ब_अक्षर_प्रकार;
#define _WCHAR_T_DEFINED
#endif

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#अन्यथा
#जर _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  प्रकारव्याख्या दीर्घ __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#जर _INTEGRAL_MAX_BITS >= 64
  प्रकारव्याख्या __int64 __time64_t;
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  प्रकारव्याख्या __time32_t समय_प्रकार;
#अन्यथा
  प्रकारव्याख्या __time64_t समय_प्रकार;
#endif
#endif

#ifndef _UTIMBUF_DEFINED
#define _UTIMBUF_DEFINED

  संरचना _utimbuf {
    समय_प्रकार actime;
    समय_प्रकार modtime;
  };

  संरचना __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#जर _INTEGRAL_MAX_BITS >= 64
  संरचना __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#endif

#ifndef	NO_OLDNAMES
  संरचना utimbuf {
    समय_प्रकार actime;
    समय_प्रकार modtime;
  };

  संरचना utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#endif
#endif

  _CRTIMP पूर्णांक __cdecl _utime32(स्थिरांक अक्षर *_Filename,संरचना __utimbuf32 *_Time);
  _CRTIMP पूर्णांक __cdecl _futime32(पूर्णांक _FileDes,संरचना __utimbuf32 *_Time);
  _CRTIMP पूर्णांक __cdecl _wutime32(स्थिरांक ब_अक्षर_प्रकार *_Filename,संरचना __utimbuf32 *_Time);
#जर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP पूर्णांक __cdecl _utime64(स्थिरांक अक्षर *_Filename,संरचना __utimbuf64 *_Time);
  _CRTIMP पूर्णांक __cdecl _futime64(पूर्णांक _FileDes,संरचना __utimbuf64 *_Time);
  _CRTIMP पूर्णांक __cdecl _wutime64(स्थिरांक ब_अक्षर_प्रकार *_Filename,संरचना __utimbuf64 *_Time);
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE पूर्णांक __cdecl _utime(स्थिरांक अक्षर *_Filename,संरचना _utimbuf *_Utimbuf) {
  परत _utime32(_Filename,(संरचना __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE पूर्णांक __cdecl _futime(पूर्णांक _Desc,संरचना _utimbuf *_Utimbuf) {
  परत _futime32(_Desc,(संरचना __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE पूर्णांक __cdecl _wutime(स्थिरांक ब_अक्षर_प्रकार *_Filename,संरचना _utimbuf *_Utimbuf) {
  परत _wutime32(_Filename,(संरचना __utimbuf32 *)_Utimbuf);
}
#अन्यथा
__CRT_INLINE पूर्णांक __cdecl _utime(स्थिरांक अक्षर *_Filename,संरचना _utimbuf *_Utimbuf) {
  परत _utime64(_Filename,(संरचना __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE पूर्णांक __cdecl _futime(पूर्णांक _Desc,संरचना _utimbuf *_Utimbuf) {
  परत _futime64(_Desc,(संरचना __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE पूर्णांक __cdecl _wutime(स्थिरांक ब_अक्षर_प्रकार *_Filename,संरचना _utimbuf *_Utimbuf) {
  परत _wutime64(_Filename,(संरचना __utimbuf64 *)_Utimbuf);
}
#endif

#ifndef	NO_OLDNAMES
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE पूर्णांक __cdecl utime(स्थिरांक अक्षर *_Filename,संरचना utimbuf *_Utimbuf) {
  परत _utime32(_Filename,(संरचना __utimbuf32 *)_Utimbuf);
}
#अन्यथा
__CRT_INLINE पूर्णांक __cdecl utime(स्थिरांक अक्षर *_Filename,संरचना utimbuf *_Utimbuf) {
  परत _utime64(_Filename,(संरचना __utimbuf64 *)_Utimbuf);
}
#endif
#endif
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(काढा)
#endif
