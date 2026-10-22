/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_WCHAR_S
#నిర్వచించు _INC_WCHAR_S

#అన్తర్భావ <wchar.h>

#ఒకవేళ defined(MINGW_HAS_SECURE_API)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WIO_S_DEFINED
#నిర్వచించు _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(స్థిరరాశి wchar_t *_Filename,పూర్ణాంకం Access_బహుళకం);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,కొలత_t కొలత_లోపల_పదాలు);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WCONIO_S_DEFINED
#నిర్వచించు _WCONIO_S_DEFINED
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *బఫరు_2,కొలత_t కొలత_లోపల_పదాలు,కొలత_t *కొలత_Read);
  _CRTIMP పూర్ణాంకం __cdecl _cwprintf_s(స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _cwscanf_s(స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _cwscanf_s_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vcwprintf_s(స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _cwprintf_s_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vcwprintf_s_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WSTDIO_S_DEFINED
#నిర్వచించు _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,కొలత_t కొలత_లోపల_పదాలు);
  పూర్ణాంకం __cdecl fwprintf_s(FILE *_File,స్థిరరాశి wchar_t *_Format,...);
  పూర్ణాంకం __cdecl wprintf_s(స్థిరరాశి wchar_t *_Format,...);
  పూర్ణాంకం __cdecl vfwprintf_s(FILE *_File,స్థిరరాశి wchar_t *_Format,va_list _ArgList);
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
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WSTDLIB_S_DEFINED
#నిర్వచించు _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (పూర్ణాంకం _Val,wchar_t *_DstBuf,కొలత_t కొలత_లోపల_పదాలు,పూర్ణాంకం _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (దీర్ఘ _Val,wchar_t *_DstBuf,కొలత_t కొలత_లోపల_పదాలు,పూర్ణాంకం _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (గుర్తులేని దీర్ఘ _Val,wchar_t *_DstBuf,కొలత_t కొలత_లోపల_పదాలు,పూర్ణాంకం _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(కొలత_t *Return_కొలత,wchar_t *_DstBuf,కొలత_t Dst_కొలత_లోపల_పదాలు,స్థిరరాశి wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **బఫరు_2,కొలత_t *బఫరు_కొలత_లోపల_పదాలు,స్థిరరాశి wchar_t *_VarName);
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,కొలత_t కొలత_లోపల_పదాలు,పూర్ణాంకం _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(గుర్తులేని __int64 _Val,wchar_t *_DstBuf,కొలత_t కొలత_లోపల_పదాలు,పూర్ణాంకం _Radix);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _POSIX_
#నిర్వచితం_కాకపోతే _WSTDLIBP_S_DEFINED
#నిర్వచించు _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *మార్గం_ఫలితం,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి wchar_t *_Drive,స్థిరరాశి wchar_t *_Dir,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(స్థిరరాశి wchar_t *_Name,స్థిరరాశి wchar_t *విలువ_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_EnvVar,wchar_t *ఫలితం_మార్గం,కొలత_t కొలత_లోపల_పదాలు);
  _CRTIMP errno_t __cdecl _wsplitpath_s(స్థిరరాశి wchar_t *నిండిన_మార్గం,wchar_t *_Drive,కొలత_t Drive_కొలత_లోపల_పదాలు,wchar_t *_Dir,కొలత_t Dir_కొలత_లోపల_పదాలు,wchar_t *_Filename,కొలత_t Filename_కొలత_లోపల_పదాలు,wchar_t *_Ext,కొలత_t Ext_కొలత_లోపల_పదాలు);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WSTRING_S_DEFINED
#నిర్వచించు _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,స్థిరరాశి wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,కొలత_t కొలత_లోపల_పదాలు,పూర్ణాంకం Err_అంకె);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *బఫరు_2,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి wchar_t *Err_సందేశం);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,కొలత_t Dst_కొలత_లోపల_పదాలు,wchar_t _Val,కొలత_t Max_లెక్క);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,కొలత_t కొలత_లోపల_పదాలు,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,కొలత_t కొలత_లోపల_పదాలు);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,కొలత_t కొలత_లోపల_పదాలు,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,కొలత_t కొలత_4);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,కొలత_t కొలత_4,_locale_t _Locale);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WTIME_S_DEFINED
#నిర్వచించు _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి నిర్మాణం tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి __time32_t *సమయం_2);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,కొలత_t కొలత_లోపల_పదాలు);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,కొలత_t కొలత_లోపల_పదాలు);
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి __time64_t *సమయం_2);
#అయితే_ముగింపు

#ఒకవేళ !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#నిర్వచించు _INC_WTIME_S_INL
#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *బఫరు_2,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి time_t *సమయం_2) { తిరిగి _wctime32_s(బఫరు_2,కొలత_లోపల_పదాలు,సమయం_2); }
#లేకపోతే
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *బఫరు_2,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి time_t *సమయం_2) { తిరిగి _wctime64_s(బఫరు_2,కొలత_లోపల_పదాలు,సమయం_2); }
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

  _CRTIMP errno_t __cdecl mbsrtowcs_s(కొలత_t *_Retval,wchar_t *_Dst,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి అక్షరం **_PSrc,కొలత_t _N,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcrtomb_s(కొలత_t *_Retval,అక్షరం *_Dst,కొలత_t కొలత_లోపల_బైట్లు,wchar_t _Ch,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcsrtombs_s(కొలత_t *_Retval,అక్షరం *_Dst,కొలత_t కొలత_లోపల_బైట్లు,స్థిరరాశి wchar_t **_Src,కొలత_t కొలత_4,mbstate_t *_State);

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#అయితే_ముగింపు
#అయితే_ముగింపు
