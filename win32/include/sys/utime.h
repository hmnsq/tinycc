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

#அந்தர்பாவ <_mingw.h>

#pragma pack(தள்ளு,_CRT_PACKING)

#ifdef __cplusplus
வெளி "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
  வகைவரை unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#இல்லையெனில்
#எனில் _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  வகைவரை long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#எனில் _INTEGRAL_MAX_BITS >= 64
  வகைவரை __int64 __time64_t;
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  வகைவரை __time32_t time_t;
#இல்லையெனில்
  வகைவரை __time64_t time_t;
#endif
#endif

#ifndef _UTIMBUF_DEFINED
#define _UTIMBUF_DEFINED

  கட்டமைப்பு _utimbuf {
    time_t actime;
    time_t modtime;
  };

  கட்டமைப்பு __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#எனில் _INTEGRAL_MAX_BITS >= 64
  கட்டமைப்பு __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#endif

#ifndef	NO_OLDNAMES
  கட்டமைப்பு utimbuf {
    time_t actime;
    time_t modtime;
  };

  கட்டமைப்பு utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#endif
#endif

  _CRTIMP முழு __cdecl _utime32(மாறிலி எழுத்து *_Filename,கட்டமைப்பு __utimbuf32 *_Time);
  _CRTIMP முழு __cdecl _futime32(முழு _FileDes,கட்டமைப்பு __utimbuf32 *_Time);
  _CRTIMP முழு __cdecl _wutime32(மாறிலி wchar_t *_Filename,கட்டமைப்பு __utimbuf32 *_Time);
#எனில் _INTEGRAL_MAX_BITS >= 64
  _CRTIMP முழு __cdecl _utime64(மாறிலி எழுத்து *_Filename,கட்டமைப்பு __utimbuf64 *_Time);
  _CRTIMP முழு __cdecl _futime64(முழு _FileDes,கட்டமைப்பு __utimbuf64 *_Time);
  _CRTIMP முழு __cdecl _wutime64(மாறிலி wchar_t *_Filename,கட்டமைப்பு __utimbuf64 *_Time);
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE முழு __cdecl _utime(மாறிலி எழுத்து *_Filename,கட்டமைப்பு _utimbuf *_Utimbuf) {
  திரும்பு _utime32(_Filename,(கட்டமைப்பு __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE முழு __cdecl _futime(முழு _Desc,கட்டமைப்பு _utimbuf *_Utimbuf) {
  திரும்பு _futime32(_Desc,(கட்டமைப்பு __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE முழு __cdecl _wutime(மாறிலி wchar_t *_Filename,கட்டமைப்பு _utimbuf *_Utimbuf) {
  திரும்பு _wutime32(_Filename,(கட்டமைப்பு __utimbuf32 *)_Utimbuf);
}
#இல்லையெனில்
__CRT_INLINE முழு __cdecl _utime(மாறிலி எழுத்து *_Filename,கட்டமைப்பு _utimbuf *_Utimbuf) {
  திரும்பு _utime64(_Filename,(கட்டமைப்பு __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE முழு __cdecl _futime(முழு _Desc,கட்டமைப்பு _utimbuf *_Utimbuf) {
  திரும்பு _futime64(_Desc,(கட்டமைப்பு __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE முழு __cdecl _wutime(மாறிலி wchar_t *_Filename,கட்டமைப்பு _utimbuf *_Utimbuf) {
  திரும்பு _wutime64(_Filename,(கட்டமைப்பு __utimbuf64 *)_Utimbuf);
}
#endif

#ifndef	NO_OLDNAMES
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE முழு __cdecl utime(மாறிலி எழுத்து *_Filename,கட்டமைப்பு utimbuf *_Utimbuf) {
  திரும்பு _utime32(_Filename,(கட்டமைப்பு __utimbuf32 *)_Utimbuf);
}
#இல்லையெனில்
__CRT_INLINE முழு __cdecl utime(மாறிலி எழுத்து *_Filename,கட்டமைப்பு utimbuf *_Utimbuf) {
  திரும்பு _utime64(_Filename,(கட்டமைப்பு __utimbuf64 *)_Utimbuf);
}
#endif
#endif
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(எடு)
#endif
