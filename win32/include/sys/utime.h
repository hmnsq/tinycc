/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _INC_UTIME
#تعریف_کرو _INC_UTIME

#جے_بنا_تعریف _WIN32
#غلطی Only Win32 نشانہ is supported!
#جے_انت

#ضمن <_mingw.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف _CRTIMP
#تعریف_کرو _CRTIMP __declspec(dllimport)
#جے_انت

#جے_بنا_تعریف _WCHAR_T_DEFINED
  تعريفنوع بنانشانی چھوٹا wchar_t;
#تعریف_کرو _WCHAR_T_DEFINED
#جے_انت

#جے_بنا_تعریف __TINYC__ /* gr */
#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
#جے_تعریف_شدہ _WIN64
#تعریف_رد USE_32_ثنائی_ہندسہ_ویلا_T
#جے_انت
#وإلا
#إذا INTEGRAL_MAX_بٹ < 64
#تعریف_کرو USE_32_ثنائی_ہندسہ_ویلا_T
#جے_انت
#جے_انت
#جے_انت

#جے_بنا_تعریف _TIME32_T_DEFINED
#تعریف_کرو _TIME32_T_DEFINED
  تعريفنوع لما __time32_t;
#جے_انت

#جے_بنا_تعریف _TIME64_T_DEFINED
#تعریف_کرو _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بٹ >= 64
  تعريفنوع __int64 __time64_t;
#جے_انت
#جے_انت

#جے_بنا_تعریف ویلا_T_DEFINED
#تعریف_کرو ویلا_T_DEFINED
#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
  تعريفنوع __time32_t time_t;
#وإلا
  تعريفنوع __time64_t time_t;
#جے_انت
#جے_انت

#جے_بنا_تعریف _UTIMBUF_DEFINED
#تعریف_کرو _UTIMBUF_DEFINED

  بنية _utimbuf {
    time_t actime;
    time_t modtime;
  };

  بنية __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#إذا INTEGRAL_MAX_بٹ >= 64
  بنية __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#جے_انت

#جے_بنا_تعریف	NO_OLDNAMES
  بنية utimbuf {
    time_t actime;
    time_t modtime;
  };

  بنية utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#جے_انت
#جے_انت

  _CRTIMP صحيح __cdecl _utime32(ثابت حرف *_Filename,بنية __utimbuf32 *ویلا_2);
  _CRTIMP صحيح __cdecl _futime32(صحيح _FileDes,بنية __utimbuf32 *ویلا_2);
  _CRTIMP صحيح __cdecl _wutime32(ثابت wchar_t *_Filename,بنية __utimbuf32 *ویلا_2);
#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP صحيح __cdecl _utime64(ثابت حرف *_Filename,بنية __utimbuf64 *ویلا_2);
  _CRTIMP صحيح __cdecl _futime64(صحيح _FileDes,بنية __utimbuf64 *ویلا_2);
  _CRTIMP صحيح __cdecl _wutime64(ثابت wchar_t *_Filename,بنية __utimbuf64 *ویلا_2);
#جے_انت

#جے_بنا_تعریف RC_INVOKED
#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
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
#جے_انت

#جے_بنا_تعریف	NO_OLDNAMES
#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
__CRT_INLINE صحيح __cdecl utime(ثابت حرف *_Filename,بنية utimbuf *_Utimbuf) {
  أرجع _utime32(_Filename,(بنية __utimbuf32 *)_Utimbuf);
}
#وإلا
__CRT_INLINE صحيح __cdecl utime(ثابت حرف *_Filename,بنية utimbuf *_Utimbuf) {
  أرجع _utime64(_Filename,(بنية __utimbuf64 *)_Utimbuf);
}
#جے_انت
#جے_انت
#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#ہدایت pack(نکالو)
#جے_انت
