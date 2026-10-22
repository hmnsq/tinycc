/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_UTIME
#وصف_ڪريو _INC_UTIME

#جيڪڏهن_وصف_نه_ٿيل _WIN32
#غلطي Only Win32 هدف is supported!
#جيڪڏهن_پورو

#ضمن <_mingw.h>

#هدايت pack(ڌڪو,_CRT_PACKING)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _CRTIMP
#وصف_ڪريو _CRTIMP __declspec(dllimport)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WCHAR_T_DEFINED
  تعريفنوع بنانشان ننڍو wchar_t;
#وصف_ڪريو _WCHAR_T_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل __TINYC__ /* gr */
#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
#جيڪڏهن_وصف_ٿيل _WIN64
#وصف_رد USE_32_ٻٽو_انگ_وقت_T
#جيڪڏهن_پورو
#وإلا
#إذا INTEGRAL_MAX_بٽ < 64
#وصف_ڪريو USE_32_ٻٽو_انگ_وقت_T
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TIME32_T_DEFINED
#وصف_ڪريو _TIME32_T_DEFINED
  تعريفنوع ڊگهو __time32_t;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TIME64_T_DEFINED
#وصف_ڪريو _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بٽ >= 64
  تعريفنوع __int64 __time64_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل وقت_T_DEFINED
#وصف_ڪريو وقت_T_DEFINED
#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
  تعريفنوع __time32_t time_t;
#وإلا
  تعريفنوع __time64_t time_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _UTIMBUF_DEFINED
#وصف_ڪريو _UTIMBUF_DEFINED

  بنية _utimbuf {
    time_t actime;
    time_t modtime;
  };

  بنية __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#إذا INTEGRAL_MAX_بٽ >= 64
  بنية __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
  بنية utimbuf {
    time_t actime;
    time_t modtime;
  };

  بنية utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#جيڪڏهن_پورو
#جيڪڏهن_پورو

  _CRTIMP صحيح __cdecl _utime32(ثابت حرف *_Filename,بنية __utimbuf32 *وقت_2);
  _CRTIMP صحيح __cdecl _futime32(صحيح _FileDes,بنية __utimbuf32 *وقت_2);
  _CRTIMP صحيح __cdecl _wutime32(ثابت wchar_t *_Filename,بنية __utimbuf32 *وقت_2);
#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP صحيح __cdecl _utime64(ثابت حرف *_Filename,بنية __utimbuf64 *وقت_2);
  _CRTIMP صحيح __cdecl _futime64(صحيح _FileDes,بنية __utimbuf64 *وقت_2);
  _CRTIMP صحيح __cdecl _wutime64(ثابت wchar_t *_Filename,بنية __utimbuf64 *وقت_2);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل RC_INVOKED
#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
__CRT_INLINE صحيح __cdecl _utime(ثابت حرف *_Filename,بنية _utimbuf *_Utimbuf) {
  أرجع _utime32(_Filename,(بنية __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE صحيح __cdecl _futime(صحيح _Desc,بنية _utimbuf *_Utimbuf) {
  أرجع _futime32(_Desc,(بنية __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE صحيح __cdecl _wutime(ثابت wchar_t *_Filename,بنية _utimbuf *_Utimbuf) {
  أرجع _wutime32(_Filename,(بنية __utimbuf32 *)_Utimbuf);
}
#وإلا
__CRT_INLINE صحيح __cdecl _utime(ثابت حرف *_Filename,بنية _utimbuf *_Utimbuf) {
  أرجع _utime64(_Filename,(بنية __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE صحيح __cdecl _futime(صحيح _Desc,بنية _utimbuf *_Utimbuf) {
  أرجع _futime64(_Desc,(بنية __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE صحيح __cdecl _wutime(ثابت wchar_t *_Filename,بنية _utimbuf *_Utimbuf) {
  أرجع _wutime64(_Filename,(بنية __utimbuf64 *)_Utimbuf);
}
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
__CRT_INLINE صحيح __cdecl utime(ثابت حرف *_Filename,بنية utimbuf *_Utimbuf) {
  أرجع _utime32(_Filename,(بنية __utimbuf32 *)_Utimbuf);
}
#وإلا
__CRT_INLINE صحيح __cdecl utime(ثابت حرف *_Filename,بنية utimbuf *_Utimbuf) {
  أرجع _utime64(_Filename,(بنية __utimbuf64 *)_Utimbuf);
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#هدايت pack(ڪڍو)
#جيڪڏهن_پورو
