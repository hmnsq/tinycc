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

#include <_mingw.h>

#pragma pack(push,_CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
  typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#නැතහොත්
#නම් _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  typedef long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#නම් _INTEGRAL_MAX_BITS >= 64
  typedef __int64 __time64_t;
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  typedef __time32_t time_t;
#නැතහොත්
  typedef __time64_t time_t;
#endif
#endif

#ifndef _UTIMBUF_DEFINED
#define _UTIMBUF_DEFINED

  sa_nracanaa _utimbuf {
    time_t actime;
    time_t modtime;
  };

  sa_nracanaa __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#නම් _INTEGRAL_MAX_BITS >= 64
  sa_nracanaa __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#endif

#ifndef	NO_OLDNAMES
  sa_nracanaa utimbuf {
    time_t actime;
    time_t modtime;
  };

  sa_nracanaa utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#endif
#endif

  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _utime32(const var_na *_Filename,sa_nracanaa __utimbuf32 *_Time);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _futime32(පූර්ණ_සංඛ්‍යා _FileDes,sa_nracanaa __utimbuf32 *_Time);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wutime32(const wchar_t *_Filename,sa_nracanaa __utimbuf32 *_Time);
#නම් _INTEGRAL_MAX_BITS >= 64
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _utime64(const var_na *_Filename,sa_nracanaa __utimbuf64 *_Time);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _futime64(පූර්ණ_සංඛ්‍යා _FileDes,sa_nracanaa __utimbuf64 *_Time);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wutime64(const wchar_t *_Filename,sa_nracanaa __utimbuf64 *_Time);
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE පූර්ණ_සංඛ්‍යා __cdecl _utime(const var_na *_Filename,sa_nracanaa _utimbuf *_Utimbuf) {
  ආපසු _utime32(_Filename,(sa_nracanaa __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE පූර්ණ_සංඛ්‍යා __cdecl _futime(පූර්ණ_සංඛ්‍යා _Desc,sa_nracanaa _utimbuf *_Utimbuf) {
  ආපසු _futime32(_Desc,(sa_nracanaa __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE පූර්ණ_සංඛ්‍යා __cdecl _wutime(const wchar_t *_Filename,sa_nracanaa _utimbuf *_Utimbuf) {
  ආපසු _wutime32(_Filename,(sa_nracanaa __utimbuf32 *)_Utimbuf);
}
#නැතහොත්
__CRT_INLINE පූර්ණ_සංඛ්‍යා __cdecl _utime(const var_na *_Filename,sa_nracanaa _utimbuf *_Utimbuf) {
  ආපසු _utime64(_Filename,(sa_nracanaa __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE පූර්ණ_සංඛ්‍යා __cdecl _futime(පූර්ණ_සංඛ්‍යා _Desc,sa_nracanaa _utimbuf *_Utimbuf) {
  ආපසු _futime64(_Desc,(sa_nracanaa __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE පූර්ණ_සංඛ්‍යා __cdecl _wutime(const wchar_t *_Filename,sa_nracanaa _utimbuf *_Utimbuf) {
  ආපසු _wutime64(_Filename,(sa_nracanaa __utimbuf64 *)_Utimbuf);
}
#endif

#ifndef	NO_OLDNAMES
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE පූර්ණ_සංඛ්‍යා __cdecl utime(const var_na *_Filename,sa_nracanaa utimbuf *_Utimbuf) {
  ආපසු _utime32(_Filename,(sa_nracanaa __utimbuf32 *)_Utimbuf);
}
#නැතහොත්
__CRT_INLINE පූර්ණ_සංඛ්‍යා __cdecl utime(const var_na *_Filename,sa_nracanaa utimbuf *_Utimbuf) {
  ආපසු _utime64(_Filename,(sa_nracanaa __utimbuf64 *)_Utimbuf);
}
#endif
#endif
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(pop)
#endif
