/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_UTIME
#تعریف_کرو _INC_UTIME

#اگر_غیر_تعریف_شدہ _WIN32
#غلطی Only Win32 ہدف is supported!
#اگر_ختم

#شامل <_mingw.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ _CRTIMP
#تعریف_کرو _CRTIMP __declspec(dllimport)
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WCHAR_T_DEFINED
  قسمتعریف غیرعلامتی مختصر wchar_t;
#تعریف_کرو _WCHAR_T_DEFINED
#اگر_ختم

#اگر_غیر_تعریف_شدہ __TINYC__ /* gr */
#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
#اگر_تعریف_شدہ _WIN64
#تعریف_منسوخ USE_32_ثنائی_ہندسہ_وقت_T
#اگر_ختم
#ورنہ
#اگر INTEGRAL_MAX_بٹ < 64
#تعریف_کرو USE_32_ثنائی_ہندسہ_وقت_T
#اگر_ختم
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TIME32_T_DEFINED
#تعریف_کرو _TIME32_T_DEFINED
  قسمتعریف طویل __time32_t;
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TIME64_T_DEFINED
#تعریف_کرو _TIME64_T_DEFINED
#اگر INTEGRAL_MAX_بٹ >= 64
  قسمتعریف __int64 __time64_t;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ وقت_T_DEFINED
#تعریف_کرو وقت_T_DEFINED
#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
  قسمتعریف __time32_t time_t;
#ورنہ
  قسمتعریف __time64_t time_t;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _UTIMBUF_DEFINED
#تعریف_کرو _UTIMBUF_DEFINED

  ساخت _utimbuf {
    time_t actime;
    time_t modtime;
  };

  ساخت __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#اگر INTEGRAL_MAX_بٹ >= 64
  ساخت __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#اگر_ختم

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
  ساخت utimbuf {
    time_t actime;
    time_t modtime;
  };

  ساخت utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#اگر_ختم
#اگر_ختم

  _CRTIMP صحیح __cdecl _utime32(ثابت حرف *_Filename,ساخت __utimbuf32 *وقت_2);
  _CRTIMP صحیح __cdecl _futime32(صحیح _FileDes,ساخت __utimbuf32 *وقت_2);
  _CRTIMP صحیح __cdecl _wutime32(ثابت wchar_t *_Filename,ساخت __utimbuf32 *وقت_2);
#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP صحیح __cdecl _utime64(ثابت حرف *_Filename,ساخت __utimbuf64 *وقت_2);
  _CRTIMP صحیح __cdecl _futime64(صحیح _FileDes,ساخت __utimbuf64 *وقت_2);
  _CRTIMP صحیح __cdecl _wutime64(ثابت wchar_t *_Filename,ساخت __utimbuf64 *وقت_2);
#اگر_ختم

#اگر_غیر_تعریف_شدہ RC_INVOKED
#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
__CRT_INLINE صحیح __cdecl _utime(ثابت حرف *_Filename,ساخت _utimbuf *_Utimbuf) {
  واپس _utime32(_Filename,(ساخت __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE صحیح __cdecl _futime(صحیح _Desc,ساخت _utimbuf *_Utimbuf) {
  واپس _futime32(_Desc,(ساخت __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE صحیح __cdecl _wutime(ثابت wchar_t *_Filename,ساخت _utimbuf *_Utimbuf) {
  واپس _wutime32(_Filename,(ساخت __utimbuf32 *)_Utimbuf);
}
#ورنہ
__CRT_INLINE صحیح __cdecl _utime(ثابت حرف *_Filename,ساخت _utimbuf *_Utimbuf) {
  واپس _utime64(_Filename,(ساخت __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE صحیح __cdecl _futime(صحیح _Desc,ساخت _utimbuf *_Utimbuf) {
  واپس _futime64(_Desc,(ساخت __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE صحیح __cdecl _wutime(ثابت wchar_t *_Filename,ساخت _utimbuf *_Utimbuf) {
  واپس _wutime64(_Filename,(ساخت __utimbuf64 *)_Utimbuf);
}
#اگر_ختم

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
__CRT_INLINE صحیح __cdecl utime(ثابت حرف *_Filename,ساخت utimbuf *_Utimbuf) {
  واپس _utime32(_Filename,(ساخت __utimbuf32 *)_Utimbuf);
}
#ورنہ
__CRT_INLINE صحیح __cdecl utime(ثابت حرف *_Filename,ساخت utimbuf *_Utimbuf) {
  واپس _utime64(_Filename,(ساخت __utimbuf64 *)_Utimbuf);
}
#اگر_ختم
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#ہدایت pack(نکالو)
#اگر_ختم
