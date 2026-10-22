/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_WCHAR_S
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_WCHAR_S

#ಅನ್ತರ್ಭಾವ <wchar.h>

#ಆದರೆ defined(MINGW_HAS_SECURE_API)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIO_S_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಪೂರ್ಣಾಂಕ Access_ಬಹುಲಕ);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WCONIO_S_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WCONIO_S_DEFINED
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *ಬಫರ್_2,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಗಾತ್ರ_t *ಗಾತ್ರ_Read);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwprintf_s(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwscanf_s(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwscanf_s_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vcwprintf_s(ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwprintf_s_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vcwprintf_s_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WSTDIO_S_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
  ಪೂರ್ಣಾಂಕ __cdecl fwprintf_s(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  ಪೂರ್ಣಾಂಕ __cdecl wprintf_s(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  ಪೂರ್ಣಾಂಕ __cdecl vfwprintf_s(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  ಪೂರ್ಣಾಂಕ __cdecl vwprintf_s(ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  ಪೂರ್ಣಾಂಕ __cdecl swprintf_s(wchar_t *_Dst,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  ಪೂರ್ಣಾಂಕ __cdecl vswprintf_s(wchar_t *_Dst,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snwprintf_s(wchar_t *_DstBuf,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vsnwprintf_s(wchar_t *_DstBuf,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wprintf_s_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vwprintf_s_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fwprintf_s_l(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vfwprintf_s_l(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _swprintf_s_l(wchar_t *_DstBuf,ಗಾತ್ರ_t Dst_ಗಾತ್ರ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vswprintf_s_l(wchar_t *_DstBuf,ಗಾತ್ರ_t Dst_ಗಾತ್ರ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snwprintf_s_l(wchar_t *_DstBuf,ಗಾತ್ರ_t Dst_ಗಾತ್ರ,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,ಗಾತ್ರ_t Dst_ಗಾತ್ರ,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fwscanf_s_l(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _swscanf_s_l(ಸ್ಥಿರಾಂಕ wchar_t *_Src,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snwscanf_s(ಸ್ಥಿರಾಂಕ wchar_t *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snwscanf_s_l(ಸ್ಥಿರಾಂಕ wchar_t *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wscanf_s_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಬಹುಲಕ_3);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಬಹುಲಕ_3,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
#ಆದರೆ_ಅಂತ್ಯ

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
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WSTDLIBP_S_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *ಮಾರ್ಗ_ಫಲಿತಾಂಶ,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ wchar_t *_Drive,ಸ್ಥಿರಾಂಕ wchar_t *_Dir,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ಸ್ಥಿರಾಂಕ wchar_t *_Name,ಸ್ಥಿರಾಂಕ wchar_t *ಮೌಲ್ಯ_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_EnvVar,wchar_t *ಫಲಿತಾಂಶ_ಮಾರ್ಗ,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ಸ್ಥಿರಾಂಕ wchar_t *ತುಂಬಿದ_ಮಾರ್ಗ,wchar_t *_Drive,ಗಾತ್ರ_t Drive_ಗಾತ್ರ_ಒಳ_ಪದಗಳು,wchar_t *_Dir,ಗಾತ್ರ_t Dir_ಗಾತ್ರ_ಒಳ_ಪದಗಳು,wchar_t *_Filename,ಗಾತ್ರ_t Filename_ಗಾತ್ರ_ಒಳ_ಪದಗಳು,wchar_t *_Ext,ಗಾತ್ರ_t Ext_ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WSTRING_S_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,ಸ್ಥಿರಾಂಕ wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಪೂರ್ಣಾಂಕ Err_ಅಂಕೆ);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *ಬಫರ್_2,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ wchar_t *Err_ಸಂದೇಶ);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಪದಗಳು,wchar_t _Val,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_5);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_5,_locale_t _Locale);
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

  _CRTIMP errno_t __cdecl mbsrtowcs_s(ಗಾತ್ರ_t *_Retval,wchar_t *_Dst,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ **_PSrc,ಗಾತ್ರ_t _N,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcrtomb_s(ಗಾತ್ರ_t *_Retval,ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,wchar_t _Ch,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcsrtombs_s(ಗಾತ್ರ_t *_Retval,ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ wchar_t **_Src,ಗಾತ್ರ_t ಗಾತ್ರ_5,mbstate_t *_State);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
