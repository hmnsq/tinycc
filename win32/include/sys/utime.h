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

#അന്തര്ഭാവ <_mingw.h>

#pragma pack(തള്ളുക,_CRT_PACKING)

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
  തരനിർവചനം unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#അല്ലെങ്കിൽ
#എങ്കിൽ _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  തരനിർവചനം long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  തരനിർവചനം __int64 __time64_t;
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  തരനിർവചനം __time32_t time_t;
#അല്ലെങ്കിൽ
  തരനിർവചനം __time64_t time_t;
#endif
#endif

#ifndef _UTIMBUF_DEFINED
#define _UTIMBUF_DEFINED

  ഘടന _utimbuf {
    time_t actime;
    time_t modtime;
  };

  ഘടന __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  ഘടന __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#endif

#ifndef	NO_OLDNAMES
  ഘടന utimbuf {
    time_t actime;
    time_t modtime;
  };

  ഘടന utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#endif
#endif

  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _utime32(സ്ഥിരം അക്ഷരം *_Filename,ഘടന __utimbuf32 *_Time);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _futime32(പൂർണ്ണസംഖ്യ _FileDes,ഘടന __utimbuf32 *_Time);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wutime32(സ്ഥിരം wchar_t *_Filename,ഘടന __utimbuf32 *_Time);
#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _utime64(സ്ഥിരം അക്ഷരം *_Filename,ഘടന __utimbuf64 *_Time);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _futime64(പൂർണ്ണസംഖ്യ _FileDes,ഘടന __utimbuf64 *_Time);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wutime64(സ്ഥിരം wchar_t *_Filename,ഘടന __utimbuf64 *_Time);
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl _utime(സ്ഥിരം അക്ഷരം *_Filename,ഘടന _utimbuf *_Utimbuf) {
  തിരികെ _utime32(_Filename,(ഘടന __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl _futime(പൂർണ്ണസംഖ്യ _Desc,ഘടന _utimbuf *_Utimbuf) {
  തിരികെ _futime32(_Desc,(ഘടന __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl _wutime(സ്ഥിരം wchar_t *_Filename,ഘടന _utimbuf *_Utimbuf) {
  തിരികെ _wutime32(_Filename,(ഘടന __utimbuf32 *)_Utimbuf);
}
#അല്ലെങ്കിൽ
__CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl _utime(സ്ഥിരം അക്ഷരം *_Filename,ഘടന _utimbuf *_Utimbuf) {
  തിരികെ _utime64(_Filename,(ഘടന __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl _futime(പൂർണ്ണസംഖ്യ _Desc,ഘടന _utimbuf *_Utimbuf) {
  തിരികെ _futime64(_Desc,(ഘടന __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl _wutime(സ്ഥിരം wchar_t *_Filename,ഘടന _utimbuf *_Utimbuf) {
  തിരികെ _wutime64(_Filename,(ഘടന __utimbuf64 *)_Utimbuf);
}
#endif

#ifndef	NO_OLDNAMES
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl utime(സ്ഥിരം അക്ഷരം *_Filename,ഘടന utimbuf *_Utimbuf) {
  തിരികെ _utime32(_Filename,(ഘടന __utimbuf32 *)_Utimbuf);
}
#അല്ലെങ്കിൽ
__CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl utime(സ്ഥിരം അക്ഷരം *_Filename,ഘടന utimbuf *_Utimbuf) {
  തിരികെ _utime64(_Filename,(ഘടന __utimbuf64 *)_Utimbuf);
}
#endif
#endif
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(എടുക്കുക)
#endif
