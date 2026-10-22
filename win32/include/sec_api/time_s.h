/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ وقت_H_S
#تعریف_کرو وقت_H_S

#شامل <time.h>

#اگر defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

  _CRTIMP errno_t __cdecl _ctime32_s(حرف *_Buf,سائز_t سائز_اندر_بائٹیں,ثابت __time32_t *وقت_2);
  _CRTIMP errno_t __cdecl _gmtime32_s(ساخت tm *_Tm,ثابت __time32_t *وقت_2);
  _CRTIMP errno_t __cdecl _localtime32_s(ساخت tm *_Tm,ثابت __time32_t *وقت_2);
  _CRTIMP errno_t __cdecl _strdate_s(حرف *_Buf,سائز_t سائز_اندر_بائٹیں);
  _CRTIMP errno_t __cdecl _strtime_s(حرف *_Buf ,سائز_t سائز_اندر_بائٹیں);
#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(حرف *_Buf,سائز_t سائز_اندر_بائٹیں,ثابت __time64_t *وقت_2);
  _CRTIMP errno_t __cdecl _gmtime64_s(ساخت tm *_Tm,ثابت __time64_t *وقت_2);
  _CRTIMP errno_t __cdecl _localtime64_s(ساخت tm *_Tm,ثابت __time64_t *وقت_2);
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WTIME_S_DEFINED
#تعریف_کرو _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,سائز_t سائز_اندر_الفاظ,ثابت ساخت tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,سائز_t سائز_اندر_الفاظ,ثابت __time32_t *وقت_2);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,سائز_t سائز_اندر_الفاظ);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,سائز_t سائز_اندر_الفاظ);
#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,سائز_t سائز_اندر_الفاظ,ثابت __time64_t *وقت_2);
#اگر_ختم

#اگر !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#تعریف_کرو _INC_WTIME_S_INL
#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *بفر_2,سائز_t سائز_اندر_الفاظ,ثابت time_t *وقت_2) { واپس _wctime32_s(بفر_2,سائز_اندر_الفاظ,وقت_2); }
#ورنہ
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *بفر_2,سائز_t سائز_اندر_الفاظ,ثابت time_t *وقت_2) { واپس _wctime64_s(بفر_2,سائز_اندر_الفاظ,وقت_2); }
#اگر_ختم
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ RC_INVOKED
#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
__CRT_INLINE errno_t __cdecl localtime_s(ساخت tm *_Tm,ثابت time_t *وقت_2) { واپس _localtime32_s(_Tm,وقت_2); }
#ورنہ
__CRT_INLINE errno_t __cdecl localtime_s(ساخت tm *_Tm,ثابت time_t *وقت_2) { واپس _localtime64_s(_Tm,وقت_2); }
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#اگر_ختم
#اگر_ختم
