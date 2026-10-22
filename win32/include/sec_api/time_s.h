/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف ویلا_H_S
#تعریف_کرو ویلا_H_S

#ضمن <time.h>

#إذا defined(MINGW_HAS_SECURE_API)

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

  _CRTIMP errno_t __cdecl _ctime32_s(حرف *_Buf,ناپ_t ناپ_وچ_بائٹاں,ثابت __time32_t *ویلا_2);
  _CRTIMP errno_t __cdecl _gmtime32_s(بنية tm *_Tm,ثابت __time32_t *ویلا_2);
  _CRTIMP errno_t __cdecl _localtime32_s(بنية tm *_Tm,ثابت __time32_t *ویلا_2);
  _CRTIMP errno_t __cdecl _strdate_s(حرف *_Buf,ناپ_t ناپ_وچ_بائٹاں);
  _CRTIMP errno_t __cdecl _strtime_s(حرف *_Buf ,ناپ_t ناپ_وچ_بائٹاں);
#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(حرف *_Buf,ناپ_t ناپ_وچ_بائٹاں,ثابت __time64_t *ویلا_2);
  _CRTIMP errno_t __cdecl _gmtime64_s(بنية tm *_Tm,ثابت __time64_t *ویلا_2);
  _CRTIMP errno_t __cdecl _localtime64_s(بنية tm *_Tm,ثابت __time64_t *ویلا_2);
#جے_انت

#جے_بنا_تعریف _WTIME_S_DEFINED
#تعریف_کرو _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,ناپ_t ناپ_وچ_الفاظ,ثابت بنية tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,ناپ_t ناپ_وچ_الفاظ,ثابت __time32_t *ویلا_2);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,ناپ_t ناپ_وچ_الفاظ);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,ناپ_t ناپ_وچ_الفاظ);
#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,ناپ_t ناپ_وچ_الفاظ,ثابت __time64_t *ویلا_2);
#جے_انت

#إذا !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#تعریف_کرو _INC_WTIME_S_INL
#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *بفر_2,ناپ_t ناپ_وچ_الفاظ,ثابت time_t *ویلا_2) { أرجع _wctime32_s(بفر_2,ناپ_وچ_الفاظ,ویلا_2); }
#وإلا
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *بفر_2,ناپ_t ناپ_وچ_الفاظ,ثابت time_t *ویلا_2) { أرجع _wctime64_s(بفر_2,ناپ_وچ_الفاظ,ویلا_2); }
#جے_انت
#جے_انت
#جے_انت

#جے_بنا_تعریف RC_INVOKED
#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
__CRT_INLINE errno_t __cdecl localtime_s(بنية tm *_Tm,ثابت time_t *ویلا_2) { أرجع _localtime32_s(_Tm,ویلا_2); }
#وإلا
__CRT_INLINE errno_t __cdecl localtime_s(بنية tm *_Tm,ثابت time_t *ویلا_2) { أرجع _localtime64_s(_Tm,ویلا_2); }
#جے_انت
#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#جے_انت
#جے_انت
