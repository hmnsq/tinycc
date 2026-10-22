/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده زمان_H_S
#تعریف_کن زمان_H_S

#ضمن <time.h>

#إذا defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

  _CRTIMP errno_t __cdecl _ctime32_s(حرف *_Buf,اندازه_t اندازه_درون_بایتها,ثابت __time32_t *زمان_2);
  _CRTIMP errno_t __cdecl _gmtime32_s(بنية tm *_Tm,ثابت __time32_t *زمان_2);
  _CRTIMP errno_t __cdecl _localtime32_s(بنية tm *_Tm,ثابت __time32_t *زمان_2);
  _CRTIMP errno_t __cdecl _strdate_s(حرف *_Buf,اندازه_t اندازه_درون_بایتها);
  _CRTIMP errno_t __cdecl _strtime_s(حرف *_Buf ,اندازه_t اندازه_درون_بایتها);
#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(حرف *_Buf,اندازه_t اندازه_درون_بایتها,ثابت __time64_t *زمان_2);
  _CRTIMP errno_t __cdecl _gmtime64_s(بنية tm *_Tm,ثابت __time64_t *زمان_2);
  _CRTIMP errno_t __cdecl _localtime64_s(بنية tm *_Tm,ثابت __time64_t *زمان_2);
#پایان_اگر

#اگر_تعریف_نشده _WTIME_S_DEFINED
#تعریف_کن _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,اندازه_t اندازه_درون_واژگان,ثابت بنية tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,اندازه_t اندازه_درون_واژگان,ثابت __time32_t *زمان_2);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,اندازه_t اندازه_درون_واژگان);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,اندازه_t اندازه_درون_واژگان);
#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,اندازه_t اندازه_درون_واژگان,ثابت __time64_t *زمان_2);
#پایان_اگر

#إذا !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#تعریف_کن _INC_WTIME_S_INL
#اگر_تعریف_شده USE_32_بیت_زمان_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *میانگیر_2,اندازه_t اندازه_درون_واژگان,ثابت time_t *زمان_2) { أرجع _wctime32_s(میانگیر_2,اندازه_درون_واژگان,زمان_2); }
#وإلا
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *میانگیر_2,اندازه_t اندازه_درون_واژگان,ثابت time_t *زمان_2) { أرجع _wctime64_s(میانگیر_2,اندازه_درون_واژگان,زمان_2); }
#پایان_اگر
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده RC_INVOKED
#اگر_تعریف_شده USE_32_بیت_زمان_T
__CRT_INLINE errno_t __cdecl localtime_s(بنية tm *_Tm,ثابت time_t *زمان_2) { أرجع _localtime32_s(_Tm,زمان_2); }
#وإلا
__CRT_INLINE errno_t __cdecl localtime_s(بنية tm *_Tm,ثابت time_t *زمان_2) { أرجع _localtime64_s(_Tm,زمان_2); }
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#پایان_اگر
#پایان_اگر
