/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ಸಮಯ_H_S
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಮಯ_H_S

#ಅನ್ತರ್ಭಾವ <time.h>

#ಆದರೆ defined(MINGW_HAS_SECURE_API)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP errno_t __cdecl _ctime32_s(ಅಕ್ಷರ *_Buf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ __time32_t *ಸಮಯ_2);
  _CRTIMP errno_t __cdecl _gmtime32_s(ರಚನೆ tm *_Tm,ಸ್ಥಿರಾಂಕ __time32_t *ಸಮಯ_2);
  _CRTIMP errno_t __cdecl _localtime32_s(ರಚನೆ tm *_Tm,ಸ್ಥಿರಾಂಕ __time32_t *ಸಮಯ_2);
  _CRTIMP errno_t __cdecl _strdate_s(ಅಕ್ಷರ *_Buf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು);
  _CRTIMP errno_t __cdecl _strtime_s(ಅಕ್ಷರ *_Buf ,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು);
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(ಅಕ್ಷರ *_Buf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ __time64_t *ಸಮಯ_2);
  _CRTIMP errno_t __cdecl _gmtime64_s(ರಚನೆ tm *_Tm,ಸ್ಥಿರಾಂಕ __time64_t *ಸಮಯ_2);
  _CRTIMP errno_t __cdecl _localtime64_s(ರಚನೆ tm *_Tm,ಸ್ಥಿರಾಂಕ __time64_t *ಸಮಯ_2);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WTIME_S_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ ರಚನೆ tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ __time32_t *ಸಮಯ_2);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ __time64_t *ಸಮಯ_2);
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_WTIME_S_INL
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *ಬಫರ್_2,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ time_t *ಸಮಯ_2) { ಹಿಂತಿರುಗಿ _wctime32_s(ಬಫರ್_2,ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸಮಯ_2); }
#ಇಲ್ಲದಿದ್ದರೆ
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *ಬಫರ್_2,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ time_t *ಸಮಯ_2) { ಹಿಂತಿರುಗಿ _wctime64_s(ಬಫರ್_2,ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸಮಯ_2); }
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ RC_INVOKED
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
__CRT_INLINE errno_t __cdecl localtime_s(ರಚನೆ tm *_Tm,ಸ್ಥಿರಾಂಕ time_t *ಸಮಯ_2) { ಹಿಂತಿರುಗಿ _localtime32_s(_Tm,ಸಮಯ_2); }
#ಇಲ್ಲದಿದ್ದರೆ
__CRT_INLINE errno_t __cdecl localtime_s(ರಚನೆ tm *_Tm,ಸ್ಥಿರಾಂಕ time_t *ಸಮಯ_2) { ಹಿಂತಿರುಗಿ _localtime64_s(_Tm,ಸಮಯ_2); }
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
