/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_STDIO_S
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_STDIO_S

#ಅನ್ತರ್ಭಾವ <stdio.h>

#ಆದರೆ defined(MINGW_HAS_SECURE_API)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _STDIO_S_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _STDIO_S_DEFINED
  _CRTIMP errno_t __cdecl clearerr_s(FILE *_File);
  ಪೂರ್ಣಾಂಕ __cdecl fprintf_s(FILE *_File,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  ಗಾತ್ರ_t __cdecl fread_s(ಶೂನ್ಯ *_DstBuf,ಗಾತ್ರ_t Dst_ಗಾತ್ರ,ಗಾತ್ರ_t Element_ಗಾತ್ರ,ಗಾತ್ರ_t ಎಣಿಕೆ_6,FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fscanf_s_l(FILE *_File,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  ಪೂರ್ಣಾಂಕ __cdecl printf_s(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _scanf_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _scanf_s_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snprintf_s(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t Dst_ಗಾತ್ರ,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snprintf_c(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vsnprintf_c(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list _ArgList);
  ಪೂರ್ಣಾಂಕ __cdecl sprintf_s(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t Dst_ಗಾತ್ರ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fscanf_l(FILE *_File,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _sscanf_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Src,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _sscanf_s_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Src,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snscanf_s(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snscanf_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snscanf_s_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  ಪೂರ್ಣಾಂಕ __cdecl vfprintf_s(FILE *_File,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list _ArgList);
  ಪೂರ್ಣಾಂಕ __cdecl vprintf_s(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list _ArgList);
  ಪೂರ್ಣಾಂಕ __cdecl vsnprintf_s(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t Dst_ಗಾತ್ರ,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vsnprintf_s(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t Dst_ಗಾತ್ರ,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list _ArgList);
  ಪೂರ್ಣಾಂಕ __cdecl vsprintf_s(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_5,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fprintf_p(FILE *_File,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _printf_p(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _sprintf_p(ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vfprintf_p(FILE *_File,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vprintf_p(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vsprintf_p(ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _scprintf_p(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vscprintf_p(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _printf_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _printf_p_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vprintf_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vprintf_p_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fprintf_l(FILE *_File,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fprintf_p_l(FILE *_File,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vfprintf_l(FILE *_File,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vfprintf_p_l(FILE *_File,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _sprintf_l(ಅಕ್ಷರ *_DstBuf,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _sprintf_p_l(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vsprintf_l(ಅಕ್ಷರ *_DstBuf,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vsprintf_p_l(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _scprintf_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _scprintf_p_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vscprintf_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vscprintf_p_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _printf_s_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vprintf_s_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fprintf_s_l(FILE *_File,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vfprintf_s_l(FILE *_File,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _sprintf_s_l(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t Dst_ಗಾತ್ರ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vsprintf_s_l(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t Dst_ಗಾತ್ರ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snprintf_s_l(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t Dst_ಗಾತ್ರ,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vsnprintf_s_l(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t Dst_ಗಾತ್ರ,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snprintf_l(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snprintf_c_l(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vsnprintf_l(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vsnprintf_c_l(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *,_locale_t _Locale,va_list _ArgList);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WSTDIO_S_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
  ಪೂರ್ಣಾಂಕ __cdecl fwprintf_s(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  ಪೂರ್ಣಾಂಕ __cdecl wprintf_s(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
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
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fwprintf_p(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wprintf_p(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vfwprintf_p(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vwprintf_p(ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _swprintf_p(wchar_t *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vswprintf_p(wchar_t *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _scwprintf_p(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vscwprintf_p(ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wprintf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wprintf_p_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vwprintf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vwprintf_p_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fwprintf_l(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fwprintf_p_l(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vfwprintf_l(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vfwprintf_p_l(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _swprintf_c_l(wchar_t *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _swprintf_p_l(wchar_t *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vswprintf_c_l(wchar_t *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vswprintf_p_l(wchar_t *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _scwprintf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _scwprintf_p_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vscwprintf_p_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snwprintf_l(wchar_t *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vsnwprintf_l(wchar_t *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl __swprintf_l(wchar_t *_Dest,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl __vswprintf_l(wchar_t *_Dest,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Plocinfo,va_list ವಾದಗಳು_2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vscwprintf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fwscanf_l(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _swscanf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Src,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snwscanf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wscanf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP ಗಾತ್ರ_t __cdecl _fread_nolock_s(ಶೂನ್ಯ *_DstBuf,ಗಾತ್ರ_t Dst_ಗಾತ್ರ,ಗಾತ್ರ_t Element_ಗಾತ್ರ,ಗಾತ್ರ_t ಎಣಿಕೆ_6,FILE *_File);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
