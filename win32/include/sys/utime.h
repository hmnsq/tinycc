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

#ଅନ୍ତର୍ଭାଵ <_mingw.h>

#pragma pack(ଠେଲ,_CRT_PACKING)

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#ଅନ୍ୟଥା
#ଯଦି _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#ଯଦି _INTEGRAL_MAX_BITS >= 64
  ପ୍ରକାରବ୍ୟାଖ୍ୟା __int64 __time64_t;
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  ପ୍ରକାରବ୍ୟାଖ୍ୟା __time32_t time_t;
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା __time64_t time_t;
#endif
#endif

#ifndef _UTIMBUF_DEFINED
#define _UTIMBUF_DEFINED

  ସଂରଚନା _utimbuf {
    time_t actime;
    time_t modtime;
  };

  ସଂରଚନା __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#ଯଦି _INTEGRAL_MAX_BITS >= 64
  ସଂରଚନା __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#endif

#ifndef	NO_OLDNAMES
  ସଂରଚନା utimbuf {
    time_t actime;
    time_t modtime;
  };

  ସଂରଚନା utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#endif
#endif

  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _utime32(ଅଚଳ ଅକ୍ଷର *_Filename,ସଂରଚନା __utimbuf32 *_Time);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _futime32(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileDes,ସଂରଚନା __utimbuf32 *_Time);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wutime32(ଅଚଳ wchar_t *_Filename,ସଂରଚନା __utimbuf32 *_Time);
#ଯଦି _INTEGRAL_MAX_BITS >= 64
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _utime64(ଅଚଳ ଅକ୍ଷର *_Filename,ସଂରଚନା __utimbuf64 *_Time);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _futime64(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileDes,ସଂରଚନା __utimbuf64 *_Time);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wutime64(ଅଚଳ wchar_t *_Filename,ସଂରଚନା __utimbuf64 *_Time);
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _utime(ଅଚଳ ଅକ୍ଷର *_Filename,ସଂରଚନା _utimbuf *_Utimbuf) {
  ଫେରନ୍ତୁ _utime32(_Filename,(ସଂରଚନା __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _futime(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Desc,ସଂରଚନା _utimbuf *_Utimbuf) {
  ଫେରନ୍ତୁ _futime32(_Desc,(ସଂରଚନା __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wutime(ଅଚଳ wchar_t *_Filename,ସଂରଚନା _utimbuf *_Utimbuf) {
  ଫେରନ୍ତୁ _wutime32(_Filename,(ସଂରଚନା __utimbuf32 *)_Utimbuf);
}
#ଅନ୍ୟଥା
__CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _utime(ଅଚଳ ଅକ୍ଷର *_Filename,ସଂରଚନା _utimbuf *_Utimbuf) {
  ଫେରନ୍ତୁ _utime64(_Filename,(ସଂରଚନା __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _futime(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Desc,ସଂରଚନା _utimbuf *_Utimbuf) {
  ଫେରନ୍ତୁ _futime64(_Desc,(ସଂରଚନା __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wutime(ଅଚଳ wchar_t *_Filename,ସଂରଚନା _utimbuf *_Utimbuf) {
  ଫେରନ୍ତୁ _wutime64(_Filename,(ସଂରଚନା __utimbuf64 *)_Utimbuf);
}
#endif

#ifndef	NO_OLDNAMES
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl utime(ଅଚଳ ଅକ୍ଷର *_Filename,ସଂରଚନା utimbuf *_Utimbuf) {
  ଫେରନ୍ତୁ _utime32(_Filename,(ସଂରଚନା __utimbuf32 *)_Utimbuf);
}
#ଅନ୍ୟଥା
__CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl utime(ଅଚଳ ଅକ୍ଷର *_Filename,ସଂରଚନା utimbuf *_Utimbuf) {
  ଫେରନ୍ତୁ _utime64(_Filename,(ସଂରଚନା __utimbuf64 *)_Utimbuf);
}
#endif
#endif
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(କାଢ଼)
#endif
