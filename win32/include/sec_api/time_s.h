/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل وقت_H_S
#وصف_ڪريو وقت_H_S

#ضمن <time.h>

#إذا defined(MINGW_HAS_SECURE_API)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

  _CRTIMP errno_t __cdecl _ctime32_s(حرف *_Buf,سائيز_t سائيز_اندريون_بائيٽون,ثابت __time32_t *وقت_2);
  _CRTIMP errno_t __cdecl _gmtime32_s(بنية tm *_Tm,ثابت __time32_t *وقت_2);
  _CRTIMP errno_t __cdecl _localtime32_s(بنية tm *_Tm,ثابت __time32_t *وقت_2);
  _CRTIMP errno_t __cdecl _strdate_s(حرف *_Buf,سائيز_t سائيز_اندريون_بائيٽون);
  _CRTIMP errno_t __cdecl _strtime_s(حرف *_Buf ,سائيز_t سائيز_اندريون_بائيٽون);
#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(حرف *_Buf,سائيز_t سائيز_اندريون_بائيٽون,ثابت __time64_t *وقت_2);
  _CRTIMP errno_t __cdecl _gmtime64_s(بنية tm *_Tm,ثابت __time64_t *وقت_2);
  _CRTIMP errno_t __cdecl _localtime64_s(بنية tm *_Tm,ثابت __time64_t *وقت_2);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WTIME_S_DEFINED
#وصف_ڪريو _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,سائيز_t سائيز_اندريون_لفظ,ثابت بنية tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,سائيز_t سائيز_اندريون_لفظ,ثابت __time32_t *وقت_2);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,سائيز_t سائيز_اندريون_لفظ);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,سائيز_t سائيز_اندريون_لفظ);
#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,سائيز_t سائيز_اندريون_لفظ,ثابت __time64_t *وقت_2);
#جيڪڏهن_پورو

#إذا !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#وصف_ڪريو _INC_WTIME_S_INL
#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *بفر_2,سائيز_t سائيز_اندريون_لفظ,ثابت time_t *وقت_2) { أرجع _wctime32_s(بفر_2,سائيز_اندريون_لفظ,وقت_2); }
#وإلا
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *بفر_2,سائيز_t سائيز_اندريون_لفظ,ثابت time_t *وقت_2) { أرجع _wctime64_s(بفر_2,سائيز_اندريون_لفظ,وقت_2); }
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل RC_INVOKED
#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
__CRT_INLINE errno_t __cdecl localtime_s(بنية tm *_Tm,ثابت time_t *وقت_2) { أرجع _localtime32_s(_Tm,وقت_2); }
#وإلا
__CRT_INLINE errno_t __cdecl localtime_s(بنية tm *_Tm,ثابت time_t *وقت_2) { أرجع _localtime64_s(_Tm,وقت_2); }
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#جيڪڏهن_پورو
#جيڪڏهن_پورو
