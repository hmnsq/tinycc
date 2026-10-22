/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی وخت_H_S
#تعریف_کړه وخت_H_S

#ضمن <time.h>

#إذا defined(MINGW_HAS_SECURE_API)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

  _CRTIMP errno_t __cdecl _ctime32_s(حرف *_Buf,اندازه_t اندازه_دننه_بایټونه,ثابت __time32_t *وخت_2);
  _CRTIMP errno_t __cdecl _gmtime32_s(بنية tm *_Tm,ثابت __time32_t *وخت_2);
  _CRTIMP errno_t __cdecl _localtime32_s(بنية tm *_Tm,ثابت __time32_t *وخت_2);
  _CRTIMP errno_t __cdecl _strdate_s(حرف *_Buf,اندازه_t اندازه_دننه_بایټونه);
  _CRTIMP errno_t __cdecl _strtime_s(حرف *_Buf ,اندازه_t اندازه_دننه_بایټونه);
#إذا INTEGRAL_MAX_بټونه >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(حرف *_Buf,اندازه_t اندازه_دننه_بایټونه,ثابت __time64_t *وخت_2);
  _CRTIMP errno_t __cdecl _gmtime64_s(بنية tm *_Tm,ثابت __time64_t *وخت_2);
  _CRTIMP errno_t __cdecl _localtime64_s(بنية tm *_Tm,ثابت __time64_t *وخت_2);
#د_که_پای

#که_نه_تعریف_شوی _WTIME_S_DEFINED
#تعریف_کړه _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,اندازه_t اندازه_دننه_ټکي,ثابت بنية tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,اندازه_t اندازه_دننه_ټکي,ثابت __time32_t *وخت_2);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,اندازه_t اندازه_دننه_ټکي);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,اندازه_t اندازه_دننه_ټکي);
#إذا INTEGRAL_MAX_بټونه >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,اندازه_t اندازه_دننه_ټکي,ثابت __time64_t *وخت_2);
#د_که_پای

#إذا !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#تعریف_کړه _INC_WTIME_S_INL
#که_تعریف_شوی USE_32_بټ_وخت_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *بفر_2,اندازه_t اندازه_دننه_ټکي,ثابت time_t *وخت_2) { أرجع _wctime32_s(بفر_2,اندازه_دننه_ټکي,وخت_2); }
#وإلا
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *بفر_2,اندازه_t اندازه_دننه_ټکي,ثابت time_t *وخت_2) { أرجع _wctime64_s(بفر_2,اندازه_دننه_ټکي,وخت_2); }
#د_که_پای
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی RC_INVOKED
#که_تعریف_شوی USE_32_بټ_وخت_T
__CRT_INLINE errno_t __cdecl localtime_s(بنية tm *_Tm,ثابت time_t *وخت_2) { أرجع _localtime32_s(_Tm,وخت_2); }
#وإلا
__CRT_INLINE errno_t __cdecl localtime_s(بنية tm *_Tm,ثابت time_t *وخت_2) { أرجع _localtime64_s(_Tm,وخت_2); }
#د_که_پای
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#د_که_پای
#د_که_پای
