/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_UTIME
#تعریف_کړه _INC_UTIME

#که_نه_تعریف_شوی _WIN32
#تېروتنه Only Win32 موخه is supported!
#د_که_پای

#ضمن <_mingw.h>

#لارښوونه pack(ټېل,_CRT_PACKING)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی _CRTIMP
#تعریف_کړه _CRTIMP __declspec(dllimport)
#د_که_پای

#که_نه_تعریف_شوی _WCHAR_T_DEFINED
  تعريفنوع بینښه لنډ wchar_t;
#تعریف_کړه _WCHAR_T_DEFINED
#د_که_پای

#که_نه_تعریف_شوی __TINYC__ /* gr */
#که_تعریف_شوی USE_32_بټ_وخت_T
#که_تعریف_شوی _WIN64
#تعریف_لغوه USE_32_بټ_وخت_T
#د_که_پای
#وإلا
#إذا INTEGRAL_MAX_بټونه < 64
#تعریف_کړه USE_32_بټ_وخت_T
#د_که_پای
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _TIME32_T_DEFINED
#تعریف_کړه _TIME32_T_DEFINED
  تعريفنوع اوږد __time32_t;
#د_که_پای

#که_نه_تعریف_شوی _TIME64_T_DEFINED
#تعریف_کړه _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بټونه >= 64
  تعريفنوع __int64 __time64_t;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی وخت_T_DEFINED
#تعریف_کړه وخت_T_DEFINED
#که_تعریف_شوی USE_32_بټ_وخت_T
  تعريفنوع __time32_t time_t;
#وإلا
  تعريفنوع __time64_t time_t;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _UTIMBUF_DEFINED
#تعریف_کړه _UTIMBUF_DEFINED

  بنية _utimbuf {
    time_t actime;
    time_t modtime;
  };

  بنية __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#إذا INTEGRAL_MAX_بټونه >= 64
  بنية __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#د_که_پای

#که_نه_تعریف_شوی	NO_OLDNAMES
  بنية utimbuf {
    time_t actime;
    time_t modtime;
  };

  بنية utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#د_که_پای
#د_که_پای

  _CRTIMP صحيح __cdecl _utime32(ثابت حرف *_Filename,بنية __utimbuf32 *وخت_2);
  _CRTIMP صحيح __cdecl _futime32(صحيح _FileDes,بنية __utimbuf32 *وخت_2);
  _CRTIMP صحيح __cdecl _wutime32(ثابت wchar_t *_Filename,بنية __utimbuf32 *وخت_2);
#إذا INTEGRAL_MAX_بټونه >= 64
  _CRTIMP صحيح __cdecl _utime64(ثابت حرف *_Filename,بنية __utimbuf64 *وخت_2);
  _CRTIMP صحيح __cdecl _futime64(صحيح _FileDes,بنية __utimbuf64 *وخت_2);
  _CRTIMP صحيح __cdecl _wutime64(ثابت wchar_t *_Filename,بنية __utimbuf64 *وخت_2);
#د_که_پای

#که_نه_تعریف_شوی RC_INVOKED
#که_تعریف_شوی USE_32_بټ_وخت_T
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
#د_که_پای

#که_نه_تعریف_شوی	NO_OLDNAMES
#که_تعریف_شوی USE_32_بټ_وخت_T
__CRT_INLINE صحيح __cdecl utime(ثابت حرف *_Filename,بنية utimbuf *_Utimbuf) {
  أرجع _utime32(_Filename,(بنية __utimbuf32 *)_Utimbuf);
}
#وإلا
__CRT_INLINE صحيح __cdecl utime(ثابت حرف *_Filename,بنية utimbuf *_Utimbuf) {
  أرجع _utime64(_Filename,(بنية __utimbuf64 *)_Utimbuf);
}
#د_که_پای
#د_که_پای
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#لارښوونه pack(راوباسه)
#د_که_پای
