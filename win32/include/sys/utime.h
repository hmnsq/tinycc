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

#અન્તર્ભાવ <_mingw.h>

#pragma pack(ધકેલો,_CRT_PACKING)

#ifdef __cplusplus
બાહ્ય "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
  પ્રકારવ્યાખ્યા unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#નહીંતર
#જો _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  પ્રકારવ્યાખ્યા long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#જો _INTEGRAL_MAX_BITS >= 64
  પ્રકારવ્યાખ્યા __int64 __time64_t;
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  પ્રકારવ્યાખ્યા __time32_t time_t;
#નહીંતર
  પ્રકારવ્યાખ્યા __time64_t time_t;
#endif
#endif

#ifndef _UTIMBUF_DEFINED
#define _UTIMBUF_DEFINED

  સંરચના _utimbuf {
    time_t actime;
    time_t modtime;
  };

  સંરચના __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#જો _INTEGRAL_MAX_BITS >= 64
  સંરચના __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#endif

#ifndef	NO_OLDNAMES
  સંરચના utimbuf {
    time_t actime;
    time_t modtime;
  };

  સંરચના utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#endif
#endif

  _CRTIMP પૂર્ણાંક __cdecl _utime32(અચલ અક્ષર *_Filename,સંરચના __utimbuf32 *_Time);
  _CRTIMP પૂર્ણાંક __cdecl _futime32(પૂર્ણાંક _FileDes,સંરચના __utimbuf32 *_Time);
  _CRTIMP પૂર્ણાંક __cdecl _wutime32(અચલ wchar_t *_Filename,સંરચના __utimbuf32 *_Time);
#જો _INTEGRAL_MAX_BITS >= 64
  _CRTIMP પૂર્ણાંક __cdecl _utime64(અચલ અક્ષર *_Filename,સંરચના __utimbuf64 *_Time);
  _CRTIMP પૂર્ણાંક __cdecl _futime64(પૂર્ણાંક _FileDes,સંરચના __utimbuf64 *_Time);
  _CRTIMP પૂર્ણાંક __cdecl _wutime64(અચલ wchar_t *_Filename,સંરચના __utimbuf64 *_Time);
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE પૂર્ણાંક __cdecl _utime(અચલ અક્ષર *_Filename,સંરચના _utimbuf *_Utimbuf) {
  પાછા _utime32(_Filename,(સંરચના __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE પૂર્ણાંક __cdecl _futime(પૂર્ણાંક _Desc,સંરચના _utimbuf *_Utimbuf) {
  પાછા _futime32(_Desc,(સંરચના __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE પૂર્ણાંક __cdecl _wutime(અચલ wchar_t *_Filename,સંરચના _utimbuf *_Utimbuf) {
  પાછા _wutime32(_Filename,(સંરચના __utimbuf32 *)_Utimbuf);
}
#નહીંતર
__CRT_INLINE પૂર્ણાંક __cdecl _utime(અચલ અક્ષર *_Filename,સંરચના _utimbuf *_Utimbuf) {
  પાછા _utime64(_Filename,(સંરચના __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE પૂર્ણાંક __cdecl _futime(પૂર્ણાંક _Desc,સંરચના _utimbuf *_Utimbuf) {
  પાછા _futime64(_Desc,(સંરચના __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE પૂર્ણાંક __cdecl _wutime(અચલ wchar_t *_Filename,સંરચના _utimbuf *_Utimbuf) {
  પાછા _wutime64(_Filename,(સંરચના __utimbuf64 *)_Utimbuf);
}
#endif

#ifndef	NO_OLDNAMES
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE પૂર્ણાંક __cdecl utime(અચલ અક્ષર *_Filename,સંરચના utimbuf *_Utimbuf) {
  પાછા _utime32(_Filename,(સંરચના __utimbuf32 *)_Utimbuf);
}
#નહીંતર
__CRT_INLINE પૂર્ણાંક __cdecl utime(અચલ અક્ષર *_Filename,સંરચના utimbuf *_Utimbuf) {
  પાછા _utime64(_Filename,(સંરચના __utimbuf64 *)_Utimbuf);
}
#endif
#endif
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(કાઢો)
#endif
