/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_STDIO_S
#నిర్వచించు _INC_STDIO_S

#అన్తర్భావ <stdio.h>

#ఒకవేళ defined(MINGW_HAS_SECURE_API)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _STDIO_S_DEFINED
#నిర్వచించు _STDIO_S_DEFINED
  _CRTIMP errno_t __cdecl clearerr_s(FILE *_File);
  పూర్ణాంకం __cdecl fprintf_s(FILE *_File,స్థిరరాశి అక్షరం *_Format,...);
  కొలత_t __cdecl fread_s(శూన్య *_DstBuf,కొలత_t Dst_కొలత,కొలత_t Element_కొలత,కొలత_t లెక్క_5,FILE *_File);
  _CRTIMP పూర్ణాంకం __cdecl _fscanf_s_l(FILE *_File,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  పూర్ణాంకం __cdecl printf_s(స్థిరరాశి అక్షరం *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _scanf_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _scanf_s_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _snprintf_s(అక్షరం *_DstBuf,కొలత_t Dst_కొలత,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _snprintf_c(అక్షరం *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vsnprintf_c(అక్షరం *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,va_list _ArgList);
  పూర్ణాంకం __cdecl sprintf_s(అక్షరం *_DstBuf,కొలత_t Dst_కొలత,స్థిరరాశి అక్షరం *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _fscanf_l(FILE *_File,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _sscanf_l(స్థిరరాశి అక్షరం *_Src,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _sscanf_s_l(స్థిరరాశి అక్షరం *_Src,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _snscanf_s(స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _snscanf_l(స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _snscanf_s_l(స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  పూర్ణాంకం __cdecl vfprintf_s(FILE *_File,స్థిరరాశి అక్షరం *_Format,va_list _ArgList);
  పూర్ణాంకం __cdecl vprintf_s(స్థిరరాశి అక్షరం *_Format,va_list _ArgList);
  పూర్ణాంకం __cdecl vsnprintf_s(అక్షరం *_DstBuf,కొలత_t Dst_కొలత,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _vsnprintf_s(అక్షరం *_DstBuf,కొలత_t Dst_కొలత,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,va_list _ArgList);
  పూర్ణాంకం __cdecl vsprintf_s(అక్షరం *_DstBuf,కొలత_t కొలత_4,స్థిరరాశి అక్షరం *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _fprintf_p(FILE *_File,స్థిరరాశి అక్షరం *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _printf_p(స్థిరరాశి అక్షరం *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _sprintf_p(అక్షరం *_Dst,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vfprintf_p(FILE *_File,స్థిరరాశి అక్షరం *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _vprintf_p(స్థిరరాశి అక్షరం *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _vsprintf_p(అక్షరం *_Dst,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _scprintf_p(స్థిరరాశి అక్షరం *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vscprintf_p(స్థిరరాశి అక్షరం *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _printf_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _printf_p_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vprintf_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _vprintf_p_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _fprintf_l(FILE *_File,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _fprintf_p_l(FILE *_File,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vfprintf_l(FILE *_File,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _vfprintf_p_l(FILE *_File,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _sprintf_l(అక్షరం *_DstBuf,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _sprintf_p_l(అక్షరం *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vsprintf_l(అక్షరం *_DstBuf,స్థిరరాశి అక్షరం *_Format,_locale_t,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _vsprintf_p_l(అక్షరం *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _scprintf_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _scprintf_p_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vscprintf_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _vscprintf_p_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _printf_s_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vprintf_s_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _fprintf_s_l(FILE *_File,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vfprintf_s_l(FILE *_File,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _sprintf_s_l(అక్షరం *_DstBuf,కొలత_t Dst_కొలత,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vsprintf_s_l(అక్షరం *_DstBuf,కొలత_t Dst_కొలత,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _snprintf_s_l(అక్షరం *_DstBuf,కొలత_t Dst_కొలత,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vsnprintf_s_l(అక్షరం *_DstBuf,కొలత_t Dst_కొలత,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _snprintf_l(అక్షరం *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _snprintf_c_l(అక్షరం *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vsnprintf_l(అక్షరం *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _vsnprintf_c_l(అక్షరం *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *,_locale_t _Locale,va_list _ArgList);

#నిర్వచితం_కాకపోతే _WSTDIO_S_DEFINED
#నిర్వచించు _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,కొలత_t కొలత_లోపల_పదాలు);
  పూర్ణాంకం __cdecl fwprintf_s(FILE *_File,స్థిరరాశి wchar_t *_Format,...);
  పూర్ణాంకం __cdecl wprintf_s(స్థిరరాశి wchar_t *_Format,...);
  పూర్ణాంకం __cdecl vwprintf_s(స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  పూర్ణాంకం __cdecl swprintf_s(wchar_t *_Dst,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి wchar_t *_Format,...);
  పూర్ణాంకం __cdecl vswprintf_s(wchar_t *_Dst,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _snwprintf_s(wchar_t *_DstBuf,కొలత_t Dst_కొలత_లోపల_పదాలు,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vsnwprintf_s(wchar_t *_DstBuf,కొలత_t Dst_కొలత_లోపల_పదాలు,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _wprintf_s_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vwprintf_s_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _fwprintf_s_l(FILE *_File,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vfwprintf_s_l(FILE *_File,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _swprintf_s_l(wchar_t *_DstBuf,కొలత_t Dst_కొలత,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vswprintf_s_l(wchar_t *_DstBuf,కొలత_t Dst_కొలత,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _snwprintf_s_l(wchar_t *_DstBuf,కొలత_t Dst_కొలత,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,కొలత_t Dst_కొలత,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _fwscanf_s_l(FILE *_File,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _swscanf_s_l(స్థిరరాశి wchar_t *_Src,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _snwscanf_s(స్థిరరాశి wchar_t *_Src,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _snwscanf_s_l(స్థిరరాశి wchar_t *_Src,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _wscanf_s_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *బహుళకం_3);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *బహుళకం_3,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,కొలత_t కొలత_లోపల_పదాలు);
  _CRTIMP పూర్ణాంకం __cdecl _fwprintf_p(FILE *_File,స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _wprintf_p(స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vfwprintf_p(FILE *_File,స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _vwprintf_p(స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _swprintf_p(wchar_t *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vswprintf_p(wchar_t *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _scwprintf_p(స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vscwprintf_p(స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _wprintf_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _wprintf_p_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vwprintf_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _vwprintf_p_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _fwprintf_l(FILE *_File,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _fwprintf_p_l(FILE *_File,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vfwprintf_l(FILE *_File,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _vfwprintf_p_l(FILE *_File,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _swprintf_c_l(wchar_t *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _swprintf_p_l(wchar_t *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vswprintf_c_l(wchar_t *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _vswprintf_p_l(wchar_t *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _scwprintf_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _scwprintf_p_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vscwprintf_p_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _snwprintf_l(wchar_t *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vsnwprintf_l(wchar_t *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl __swprintf_l(wchar_t *_Dest,స్థిరరాశి wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP పూర్ణాంకం __cdecl __vswprintf_l(wchar_t *_Dest,స్థిరరాశి wchar_t *_Format,_locale_t _Plocinfo,va_list వాదనలు_2);
  _CRTIMP పూర్ణాంకం __cdecl _vscwprintf_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _fwscanf_l(FILE *_File,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _swscanf_l(స్థిరరాశి wchar_t *_Src,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _snwscanf_l(స్థిరరాశి wchar_t *_Src,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _wscanf_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
#అయితే_ముగింపు
#అయితే_ముగింపు

  _CRTIMP కొలత_t __cdecl _fread_nolock_s(శూన్య *_DstBuf,కొలత_t Dst_కొలత,కొలత_t Element_కొలత,కొలత_t లెక్క_5,FILE *_File);

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు
