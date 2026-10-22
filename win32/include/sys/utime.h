/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_UTIME
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_UTIME

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
#ਗਲਤੀ Only Win32 ਨਿਸ਼ਾਨਾ is supported!
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

#ਹਦਾਇਤ pack(ਧੱਕੋ,_CRT_PACKING)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRTIMP
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRTIMP __declspec(dllimport)
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WCHAR_T_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ wchar_t;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WCHAR_T_DEFINED
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __TINYC__ /* gr */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ < 64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIME32_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIME32_T_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ __time32_t;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIME64_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIME64_T_DEFINED
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __int64 __time64_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ਸਮਾਂ_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮਾਂ_T_DEFINED
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __time32_t time_t;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __time64_t time_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _UTIMBUF_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _UTIMBUF_DEFINED

  ਬਣਤਰ _utimbuf {
    time_t actime;
    time_t modtime;
  };

  ਬਣਤਰ __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  ਬਣਤਰ __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
  ਬਣਤਰ utimbuf {
    time_t actime;
    time_t modtime;
  };

  ਬਣਤਰ utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

  _CRTIMP ਪੂਰਨ __cdecl _utime32(ਅਚਲ ਅੱਖਰ *_Filename,ਬਣਤਰ __utimbuf32 *ਸਮਾਂ_2);
  _CRTIMP ਪੂਰਨ __cdecl _futime32(ਪੂਰਨ _FileDes,ਬਣਤਰ __utimbuf32 *ਸਮਾਂ_2);
  _CRTIMP ਪੂਰਨ __cdecl _wutime32(ਅਚਲ wchar_t *_Filename,ਬਣਤਰ __utimbuf32 *ਸਮਾਂ_2);
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  _CRTIMP ਪੂਰਨ __cdecl _utime64(ਅਚਲ ਅੱਖਰ *_Filename,ਬਣਤਰ __utimbuf64 *ਸਮਾਂ_2);
  _CRTIMP ਪੂਰਨ __cdecl _futime64(ਪੂਰਨ _FileDes,ਬਣਤਰ __utimbuf64 *ਸਮਾਂ_2);
  _CRTIMP ਪੂਰਨ __cdecl _wutime64(ਅਚਲ wchar_t *_Filename,ਬਣਤਰ __utimbuf64 *ਸਮਾਂ_2);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ RC_INVOKED
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
__CRT_INLINE ਪੂਰਨ __cdecl _utime(ਅਚਲ ਅੱਖਰ *_Filename,ਬਣਤਰ _utimbuf *_Utimbuf) {
  ਵਾਪਸ _utime32(_Filename,(ਬਣਤਰ __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE ਪੂਰਨ __cdecl _futime(ਪੂਰਨ _Desc,ਬਣਤਰ _utimbuf *_Utimbuf) {
  ਵਾਪਸ _futime32(_Desc,(ਬਣਤਰ __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE ਪੂਰਨ __cdecl _wutime(ਅਚਲ wchar_t *_Filename,ਬਣਤਰ _utimbuf *_Utimbuf) {
  ਵਾਪਸ _wutime32(_Filename,(ਬਣਤਰ __utimbuf32 *)_Utimbuf);
}
#ਨਹੀਂਤਾਂ
__CRT_INLINE ਪੂਰਨ __cdecl _utime(ਅਚਲ ਅੱਖਰ *_Filename,ਬਣਤਰ _utimbuf *_Utimbuf) {
  ਵਾਪਸ _utime64(_Filename,(ਬਣਤਰ __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE ਪੂਰਨ __cdecl _futime(ਪੂਰਨ _Desc,ਬਣਤਰ _utimbuf *_Utimbuf) {
  ਵਾਪਸ _futime64(_Desc,(ਬਣਤਰ __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE ਪੂਰਨ __cdecl _wutime(ਅਚਲ wchar_t *_Filename,ਬਣਤਰ _utimbuf *_Utimbuf) {
  ਵਾਪਸ _wutime64(_Filename,(ਬਣਤਰ __utimbuf64 *)_Utimbuf);
}
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
__CRT_INLINE ਪੂਰਨ __cdecl utime(ਅਚਲ ਅੱਖਰ *_Filename,ਬਣਤਰ utimbuf *_Utimbuf) {
  ਵਾਪਸ _utime32(_Filename,(ਬਣਤਰ __utimbuf32 *)_Utimbuf);
}
#ਨਹੀਂਤਾਂ
__CRT_INLINE ਪੂਰਨ __cdecl utime(ਅਚਲ ਅੱਖਰ *_Filename,ਬਣਤਰ utimbuf *_Utimbuf) {
  ਵਾਪਸ _utime64(_Filename,(ਬਣਤਰ __utimbuf64 *)_Utimbuf);
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ pack(ਕੱਢੋ)
#ਜੇ_ਅੰਤ
