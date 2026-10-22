/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ਸਮਾਂ_H_S
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮਾਂ_H_S

#ਅਨ੍ਤਰ੍ਭਾਵ <time.h>

#ਜੇ defined(MINGW_HAS_SECURE_API)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

  _CRTIMP errno_t __cdecl _ctime32_s(ਅੱਖਰ *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ __time32_t *ਸਮਾਂ_2);
  _CRTIMP errno_t __cdecl _gmtime32_s(ਬਣਤਰ tm *_Tm,ਅਚਲ __time32_t *ਸਮਾਂ_2);
  _CRTIMP errno_t __cdecl _localtime32_s(ਬਣਤਰ tm *_Tm,ਅਚਲ __time32_t *ਸਮਾਂ_2);
  _CRTIMP errno_t __cdecl _strdate_s(ਅੱਖਰ *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ);
  _CRTIMP errno_t __cdecl _strtime_s(ਅੱਖਰ *_Buf ,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ);
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(ਅੱਖਰ *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ __time64_t *ਸਮਾਂ_2);
  _CRTIMP errno_t __cdecl _gmtime64_s(ਬਣਤਰ tm *_Tm,ਅਚਲ __time64_t *ਸਮਾਂ_2);
  _CRTIMP errno_t __cdecl _localtime64_s(ਬਣਤਰ tm *_Tm,ਅਚਲ __time64_t *ਸਮਾਂ_2);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WTIME_S_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ ਬਣਤਰ tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ __time32_t *ਸਮਾਂ_2);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ __time64_t *ਸਮਾਂ_2);
#ਜੇ_ਅੰਤ

#ਜੇ !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_WTIME_S_INL
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *ਬਫਰ_2,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ time_t *ਸਮਾਂ_2) { ਵਾਪਸ _wctime32_s(ਬਫਰ_2,ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਸਮਾਂ_2); }
#ਨਹੀਂਤਾਂ
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *ਬਫਰ_2,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ time_t *ਸਮਾਂ_2) { ਵਾਪਸ _wctime64_s(ਬਫਰ_2,ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਸਮਾਂ_2); }
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ RC_INVOKED
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
__CRT_INLINE errno_t __cdecl localtime_s(ਬਣਤਰ tm *_Tm,ਅਚਲ time_t *ਸਮਾਂ_2) { ਵਾਪਸ _localtime32_s(_Tm,ਸਮਾਂ_2); }
#ਨਹੀਂਤਾਂ
__CRT_INLINE errno_t __cdecl localtime_s(ਬਣਤਰ tm *_Tm,ਅਚਲ time_t *ਸਮਾਂ_2) { ਵਾਪਸ _localtime64_s(_Tm,ਸਮਾਂ_2); }
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
