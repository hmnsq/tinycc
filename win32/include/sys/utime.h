/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_UTIME
#تعریف_کن _INC_UTIME

#اگر_تعریف_نشده _WIN32
#خطا Only Win32 هدف is supported!
#پایان_اگر

#ضمن <_mingw.h>

#رهنمود pack(افزودن,_CRT_PACKING)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده _CRTIMP
#تعریف_کن _CRTIMP __declspec(dllimport)
#پایان_اگر

#اگر_تعریف_نشده _WCHAR_T_DEFINED
  تعريفنوع بیعلامت کوتاه wchar_t;
#تعریف_کن _WCHAR_T_DEFINED
#پایان_اگر

#اگر_تعریف_نشده __TINYC__ /* gr */
#اگر_تعریف_شده USE_32_بیت_زمان_T
#اگر_تعریف_شده _WIN64
#لغو_تعریف USE_32_بیت_زمان_T
#پایان_اگر
#وإلا
#إذا INTEGRAL_MAX_بیتها < 64
#تعریف_کن USE_32_بیت_زمان_T
#پایان_اگر
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _TIME32_T_DEFINED
#تعریف_کن _TIME32_T_DEFINED
  تعريفنوع دراز __time32_t;
#پایان_اگر

#اگر_تعریف_نشده _TIME64_T_DEFINED
#تعریف_کن _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بیتها >= 64
  تعريفنوع __int64 __time64_t;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده زمان_T_DEFINED
#تعریف_کن زمان_T_DEFINED
#اگر_تعریف_شده USE_32_بیت_زمان_T
  تعريفنوع __time32_t time_t;
#وإلا
  تعريفنوع __time64_t time_t;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _UTIMBUF_DEFINED
#تعریف_کن _UTIMBUF_DEFINED

  بنية _utimbuf {
    time_t actime;
    time_t modtime;
  };

  بنية __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#إذا INTEGRAL_MAX_بیتها >= 64
  بنية __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#پایان_اگر

#اگر_تعریف_نشده	NO_OLDNAMES
  بنية utimbuf {
    time_t actime;
    time_t modtime;
  };

  بنية utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#پایان_اگر
#پایان_اگر

  _CRTIMP صحيح __cdecl _utime32(ثابت حرف *_Filename,بنية __utimbuf32 *زمان_2);
  _CRTIMP صحيح __cdecl _futime32(صحيح _FileDes,بنية __utimbuf32 *زمان_2);
  _CRTIMP صحيح __cdecl _wutime32(ثابت wchar_t *_Filename,بنية __utimbuf32 *زمان_2);
#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP صحيح __cdecl _utime64(ثابت حرف *_Filename,بنية __utimbuf64 *زمان_2);
  _CRTIMP صحيح __cdecl _futime64(صحيح _FileDes,بنية __utimbuf64 *زمان_2);
  _CRTIMP صحيح __cdecl _wutime64(ثابت wchar_t *_Filename,بنية __utimbuf64 *زمان_2);
#پایان_اگر

#اگر_تعریف_نشده RC_INVOKED
#اگر_تعریف_شده USE_32_بیت_زمان_T
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
#پایان_اگر

#اگر_تعریف_نشده	NO_OLDNAMES
#اگر_تعریف_شده USE_32_بیت_زمان_T
__CRT_INLINE صحيح __cdecl utime(ثابت حرف *_Filename,بنية utimbuf *_Utimbuf) {
  أرجع _utime32(_Filename,(بنية __utimbuf32 *)_Utimbuf);
}
#وإلا
__CRT_INLINE صحيح __cdecl utime(ثابت حرف *_Filename,بنية utimbuf *_Utimbuf) {
  أرجع _utime64(_Filename,(بنية __utimbuf64 *)_Utimbuf);
}
#پایان_اگر
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#رهنمود pack(برداشت)
#پایان_اگر
