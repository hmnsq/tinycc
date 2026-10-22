/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO_S
#define _INC_STDIO_S

#अन्तर्भाव <stdio.h>

#सचे defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef _STDIO_S_DEFINED
#define _STDIO_S_DEFINED
  _CRTIMP errno_t __cdecl clearerr_s(FILE *_File);
  पूर्णाङ्क __cdecl fprintf_s(FILE *_File,ध्रुव वर्ण *_Format,...);
  size_t __cdecl fread_s(शून्य *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t गणनम्_5,FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _fscanf_s_l(FILE *_File,ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  पूर्णाङ्क __cdecl printf_s(ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _scanf_l(ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _scanf_s_l(ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _snprintf_s(वर्ण *_DstBuf,size_t _DstSize,size_t Max_गणनम्,ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _snprintf_c(वर्ण *_DstBuf,size_t Max_गणनम्,ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnprintf_c(वर्ण *_DstBuf,size_t Max_गणनम्,ध्रुव वर्ण *_Format,va_list _ArgList);
  पूर्णाङ्क __cdecl sprintf_s(वर्ण *_DstBuf,size_t _DstSize,ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _fscanf_l(FILE *_File,ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _sscanf_l(ध्रुव वर्ण *_Src,ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _sscanf_s_l(ध्रुव वर्ण *_Src,ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _snscanf_s(ध्रुव वर्ण *_Src,size_t Max_गणनम्,ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _snscanf_l(ध्रुव वर्ण *_Src,size_t Max_गणनम्,ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _snscanf_s_l(ध्रुव वर्ण *_Src,size_t Max_गणनम्,ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  पूर्णाङ्क __cdecl vfprintf_s(FILE *_File,ध्रुव वर्ण *_Format,va_list _ArgList);
  पूर्णाङ्क __cdecl vprintf_s(ध्रुव वर्ण *_Format,va_list _ArgList);
  पूर्णाङ्क __cdecl vsnprintf_s(वर्ण *_DstBuf,size_t _DstSize,size_t Max_गणनम्,ध्रुव वर्ण *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vsnprintf_s(वर्ण *_DstBuf,size_t _DstSize,size_t Max_गणनम्,ध्रुव वर्ण *_Format,va_list _ArgList);
  पूर्णाङ्क __cdecl vsprintf_s(वर्ण *_DstBuf,size_t _Size,ध्रुव वर्ण *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fprintf_p(FILE *_File,ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _printf_p(ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _sprintf_p(वर्ण *_Dst,size_t Max_गणनम्,ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vfprintf_p(FILE *_File,ध्रुव वर्ण *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vprintf_p(ध्रुव वर्ण *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vsprintf_p(वर्ण *_Dst,size_t Max_गणनम्,ध्रुव वर्ण *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _scprintf_p(ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vscprintf_p(ध्रुव वर्ण *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _printf_l(ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _printf_p_l(ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vprintf_l(ध्रुव वर्ण *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vprintf_p_l(ध्रुव वर्ण *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fprintf_l(FILE *_File,ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _fprintf_p_l(FILE *_File,ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vfprintf_l(FILE *_File,ध्रुव वर्ण *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vfprintf_p_l(FILE *_File,ध्रुव वर्ण *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _sprintf_l(वर्ण *_DstBuf,ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _sprintf_p_l(वर्ण *_DstBuf,size_t Max_गणनम्,ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsprintf_l(वर्ण *_DstBuf,ध्रुव वर्ण *_Format,_locale_t,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vsprintf_p_l(वर्ण *_DstBuf,size_t Max_गणनम्,ध्रुव वर्ण *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _scprintf_l(ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _scprintf_p_l(ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vscprintf_l(ध्रुव वर्ण *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vscprintf_p_l(ध्रुव वर्ण *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _printf_s_l(ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vprintf_s_l(ध्रुव वर्ण *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fprintf_s_l(FILE *_File,ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vfprintf_s_l(FILE *_File,ध्रुव वर्ण *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _sprintf_s_l(वर्ण *_DstBuf,size_t _DstSize,ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsprintf_s_l(वर्ण *_DstBuf,size_t _DstSize,ध्रुव वर्ण *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snprintf_s_l(वर्ण *_DstBuf,size_t _DstSize,size_t Max_गणनम्,ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnprintf_s_l(वर्ण *_DstBuf,size_t _DstSize,size_t Max_गणनम्,ध्रुव वर्ण *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snprintf_l(वर्ण *_DstBuf,size_t Max_गणनम्,ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _snprintf_c_l(वर्ण *_DstBuf,size_t Max_गणनम्,ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnprintf_l(वर्ण *_DstBuf,size_t Max_गणनम्,ध्रुव वर्ण *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vsnprintf_c_l(वर्ण *_DstBuf,size_t Max_गणनम्,ध्रुव वर्ण *,_locale_t _Locale,va_list _ArgList);

#ifndef _WSTDIO_S_DEFINED
#define _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,size_t Size_In_शब्दाः);
  पूर्णाङ्क __cdecl fwprintf_s(FILE *_File,ध्रुव wchar_t *_Format,...);
  पूर्णाङ्क __cdecl wprintf_s(ध्रुव wchar_t *_Format,...);
  पूर्णाङ्क __cdecl vwprintf_s(ध्रुव wchar_t *_Format,va_list _ArgList);
  पूर्णाङ्क __cdecl swprintf_s(wchar_t *_Dst,size_t Size_In_शब्दाः,ध्रुव wchar_t *_Format,...);
  पूर्णाङ्क __cdecl vswprintf_s(wchar_t *_Dst,size_t Size_In_शब्दाः,ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snwprintf_s(wchar_t *_DstBuf,size_t Dst_Size_In_शब्दाः,size_t Max_गणनम्,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnwprintf_s(wchar_t *_DstBuf,size_t Dst_Size_In_शब्दाः,size_t Max_गणनम्,ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _wprintf_s_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vwprintf_s_l(ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fwprintf_s_l(FILE *_File,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vfwprintf_s_l(FILE *_File,ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fwscanf_s_l(FILE *_File,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _swscanf_s_l(ध्रुव wchar_t *_Src,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _snwscanf_s(ध्रुव wchar_t *_Src,size_t Max_गणनम्,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _snwscanf_s_l(ध्रुव wchar_t *_Src,size_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _wscanf_s_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_Mode);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_Mode,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,size_t Size_In_शब्दाः);
  _CRTIMP पूर्णाङ्क __cdecl _fwprintf_p(FILE *_File,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _wprintf_p(ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vfwprintf_p(FILE *_File,ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vwprintf_p(ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_p(wchar_t *_DstBuf,size_t Max_गणनम्,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t Max_गणनम्,ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _scwprintf_p(ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vscwprintf_p(ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _wprintf_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _wprintf_p_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vwprintf_l(ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vwprintf_p_l(ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fwprintf_l(FILE *_File,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _fwprintf_p_l(FILE *_File,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vfwprintf_l(FILE *_File,ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vfwprintf_p_l(FILE *_File,ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _scwprintf_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _scwprintf_p_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vscwprintf_p_l(ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl __swprintf_l(wchar_t *_Dest,ध्रुव wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP पूर्णाङ्क __cdecl __vswprintf_l(wchar_t *_Dest,ध्रुव wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
  _CRTIMP पूर्णाङ्क __cdecl _vscwprintf_l(ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fwscanf_l(FILE *_File,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _swscanf_l(ध्रुव wchar_t *_Src,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _snwscanf_l(ध्रुव wchar_t *_Src,size_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _wscanf_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
#endif
#endif

  _CRTIMP size_t __cdecl _fread_nolock_s(शून्य *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t गणनम्_5,FILE *_File);

#ifdef __cplusplus
}
#endif
#endif
#endif
