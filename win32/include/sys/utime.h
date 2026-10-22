/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_UTIME
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_UTIME

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
#ದೋಷ Only Win32 ಗುರಿ is supported!
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ಸೂಚನೆ pack(ತಳ್ಳು,_CRT_PACKING)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRTIMP
#ವ್ಯಾಖ್ಯಾನಿಸು _CRTIMP __declspec(dllimport)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WCHAR_T_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ wchar_t;
#ವ್ಯಾಖ್ಯಾನಿಸು _WCHAR_T_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __TINYC__ /* gr */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು USE_32_ಬಿಟ್_ಸಮಯ_T
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು < 64
#ವ್ಯಾಖ್ಯಾನಿಸು USE_32_ಬಿಟ್_ಸಮಯ_T
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIME32_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _TIME32_T_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ __time32_t;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIME64_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _TIME64_T_DEFINED
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __int64 __time64_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ಸಮಯ_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಮಯ_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __time32_t time_t;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __time64_t time_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _UTIMBUF_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _UTIMBUF_DEFINED

  ರಚನೆ _utimbuf {
    time_t actime;
    time_t modtime;
  };

  ರಚನೆ __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  ರಚನೆ __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
  ರಚನೆ utimbuf {
    time_t actime;
    time_t modtime;
  };

  ರಚನೆ utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _utime32(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ರಚನೆ __utimbuf32 *ಸಮಯ_2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _futime32(ಪೂರ್ಣಾಂಕ _FileDes,ರಚನೆ __utimbuf32 *ಸಮಯ_2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wutime32(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ರಚನೆ __utimbuf32 *ಸಮಯ_2);
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _utime64(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ರಚನೆ __utimbuf64 *ಸಮಯ_2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _futime64(ಪೂರ್ಣಾಂಕ _FileDes,ರಚನೆ __utimbuf64 *ಸಮಯ_2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wutime64(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ರಚನೆ __utimbuf64 *ಸಮಯ_2);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ RC_INVOKED
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl _utime(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ರಚನೆ _utimbuf *_Utimbuf) {
  ಹಿಂತಿರುಗಿ _utime32(_Filename,(ರಚನೆ __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl _futime(ಪೂರ್ಣಾಂಕ _Desc,ರಚನೆ _utimbuf *_Utimbuf) {
  ಹಿಂತಿರುಗಿ _futime32(_Desc,(ರಚನೆ __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl _wutime(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ರಚನೆ _utimbuf *_Utimbuf) {
  ಹಿಂತಿರುಗಿ _wutime32(_Filename,(ರಚನೆ __utimbuf32 *)_Utimbuf);
}
#ಇಲ್ಲದಿದ್ದರೆ
__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl _utime(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ರಚನೆ _utimbuf *_Utimbuf) {
  ಹಿಂತಿರುಗಿ _utime64(_Filename,(ರಚನೆ __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl _futime(ಪೂರ್ಣಾಂಕ _Desc,ರಚನೆ _utimbuf *_Utimbuf) {
  ಹಿಂತಿರುಗಿ _futime64(_Desc,(ರಚನೆ __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl _wutime(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ರಚನೆ _utimbuf *_Utimbuf) {
  ಹಿಂತಿರುಗಿ _wutime64(_Filename,(ರಚನೆ __utimbuf64 *)_Utimbuf);
}
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl utime(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ರಚನೆ utimbuf *_Utimbuf) {
  ಹಿಂತಿರುಗಿ _utime32(_Filename,(ರಚನೆ __utimbuf32 *)_Utimbuf);
}
#ಇಲ್ಲದಿದ್ದರೆ
__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl utime(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ರಚನೆ utimbuf *_Utimbuf) {
  ಹಿಂತಿರುಗಿ _utime64(_Filename,(ರಚನೆ __utimbuf64 *)_Utimbuf);
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ pack(ತೆಗೆ)
#ಆದರೆ_ಅಂತ್ಯ
