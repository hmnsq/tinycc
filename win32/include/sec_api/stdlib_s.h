/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_STDLIB_S
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_STDLIB_S

#ಅನ್ತರ್ಭಾವ <stdlib.h>

#ಆದರೆ defined(MINGW_HAS_SECURE_API)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP errno_t __cdecl _dupenv_s(ಅಕ್ಷರ **_PBuffer,ಗಾತ್ರ_t *PBuffer_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ_2,ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_5,ಪೂರ್ಣಾಂಕ _Radix);
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_5,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(ಚಿಹ್ನೆರಹಿತ __int64 _Val,ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_5,ಪೂರ್ಣಾಂಕ _Radix);
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP errno_t __cdecl _ltoa_s(ದೀರ್ಘ _Val,ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_5,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(ಗಾತ್ರ_t *Pt_ಅಂಕೆ_ದ_Char_Converted,wchar_t *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_SrcBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(ಗಾತ್ರ_t *Pt_ಅಂಕೆ_ದ_Char_Converted,wchar_t *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_SrcBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ _Val,ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_5,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(ಪೂರ್ಣಾಂಕ *ಗಾತ್ರ_Converted,ಅಕ್ಷರ *_MbCh,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(ಗಾತ್ರ_t *Pt_ಅಂಕೆ_ದ_Char_Converted,ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ wchar_t *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ_ಒಳ_ಬೈಟುಗಳು);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(ಗಾತ್ರ_t *Pt_ಅಂಕೆ_ದ_Char_Converted,ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ wchar_t *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ_ಒಳ_ಬೈಟುಗಳು,_locale_t _Locale);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WSTDLIB_S_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (ಪೂರ್ಣಾಂಕ _Val,wchar_t *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (ದೀರ್ಘ _Val,wchar_t *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ _Val,wchar_t *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(ಗಾತ್ರ_t *Return_ಗಾತ್ರ,wchar_t *_DstBuf,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **ಬಫರ್_2,ಗಾತ್ರ_t *ಬಫರ್_ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ wchar_t *_VarName);
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(ಚಿಹ್ನೆರಹಿತ __int64 _Val,wchar_t *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಪೂರ್ಣಾಂಕ _Radix);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_5,ದ್ವಿಗುಣ _Val,ಪೂರ್ಣಾಂಕ ಅಂಕೆ_ದ_Dights,ಪೂರ್ಣಾಂಕ *_PtDec,ಪೂರ್ಣಾಂಕ *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_5,ದ್ವಿಗುಣ _Val,ಪೂರ್ಣಾಂಕ ಅಂಕೆ_ದ_Dec,ಪೂರ್ಣಾಂಕ *_PtDec,ಪೂರ್ಣಾಂಕ *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_5,ದ್ವಿಗುಣ _Val,ಪೂರ್ಣಾಂಕ ಅಂಕೆ_ದ_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(ಅಕ್ಷರ *ಮಾರ್ಗ_ಫಲಿತಾಂಶ,ಗಾತ್ರ_t ಗಾತ್ರ_5,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Drive,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Dir,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Name,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮೌಲ್ಯ_2);
  _CRTIMP errno_t __cdecl _searchenv_s(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_EnvVar,ಅಕ್ಷರ *ಫಲಿತಾಂಶ_ಮಾರ್ಗ,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು);
  _CRTIMP errno_t __cdecl _splitpath_s(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ತುಂಬಿದ_ಮಾರ್ಗ,ಅಕ್ಷರ *_Drive,ಗಾತ್ರ_t Drive_ಗಾತ್ರ,ಅಕ್ಷರ *_Dir,ಗಾತ್ರ_t Dir_ಗಾತ್ರ,ಅಕ್ಷರ *_Filename,ಗಾತ್ರ_t Filename_ಗಾತ್ರ,ಅಕ್ಷರ *_Ext,ಗಾತ್ರ_t Ext_ಗಾತ್ರ);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WSTDLIBP_S_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *ಮಾರ್ಗ_ಫಲಿತಾಂಶ,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ wchar_t *_Drive,ಸ್ಥಿರಾಂಕ wchar_t *_Dir,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ಸ್ಥಿರಾಂಕ wchar_t *_Name,ಸ್ಥಿರಾಂಕ wchar_t *ಮೌಲ್ಯ_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_EnvVar,wchar_t *ಫಲಿತಾಂಶ_ಮಾರ್ಗ,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ಸ್ಥಿರಾಂಕ wchar_t *ತುಂಬಿದ_ಮಾರ್ಗ,wchar_t *_Drive,ಗಾತ್ರ_t Drive_ಗಾತ್ರ_ಒಳ_ಪದಗಳು,wchar_t *_Dir,ಗಾತ್ರ_t Dir_ಗಾತ್ರ_ಒಳ_ಪದಗಳು,wchar_t *_Filename,ಗಾತ್ರ_t Filename_ಗಾತ್ರ_ಒಳ_ಪದಗಳು,wchar_t *_Ext,ಗಾತ್ರ_t Ext_ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
