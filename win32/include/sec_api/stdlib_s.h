/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_STDLIB_S
#నిర్వచించు _INC_STDLIB_S

#అన్తర్భావ <stdlib.h>

#ఒకవేళ defined(MINGW_HAS_SECURE_API)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

  _CRTIMP errno_t __cdecl _dupenv_s(అక్షరం **_PBuffer,కొలత_t *PBuffer_కొలత_లోపల_బైట్లు,స్థిరరాశి అక్షరం *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(పూర్ణాంకం విలువ_2,అక్షరం *_DstBuf,కొలత_t కొలత_4,పూర్ణాంకం _Radix);
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,అక్షరం *_DstBuf,కొలత_t కొలత_4,పూర్ణాంకం _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(గుర్తులేని __int64 _Val,అక్షరం *_DstBuf,కొలత_t కొలత_4,పూర్ణాంకం _Radix);
#అయితే_ముగింపు
  _CRTIMP errno_t __cdecl _ltoa_s(దీర్ఘ _Val,అక్షరం *_DstBuf,కొలత_t కొలత_4,పూర్ణాంకం _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(కొలత_t *Pt_అంకె_యొక్క_Char_Converted,wchar_t *_DstBuf,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి అక్షరం *_SrcBuf,కొలత_t Max_లెక్క);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(కొలత_t *Pt_అంకె_యొక్క_Char_Converted,wchar_t *_DstBuf,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి అక్షరం *_SrcBuf,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(గుర్తులేని దీర్ఘ _Val,అక్షరం *_DstBuf,కొలత_t కొలత_4,పూర్ణాంకం _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(పూర్ణాంకం *కొలత_Converted,అక్షరం *_MbCh,కొలత_t కొలత_లోపల_బైట్లు,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(కొలత_t *Pt_అంకె_యొక్క_Char_Converted,అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,స్థిరరాశి wchar_t *_Src,కొలత_t Max_లెక్క_లోపల_బైట్లు);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(కొలత_t *Pt_అంకె_యొక్క_Char_Converted,అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,స్థిరరాశి wchar_t *_Src,కొలత_t Max_లెక్క_లోపల_బైట్లు,_locale_t _Locale);

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
  _CRTIMP errno_t __cdecl _ecvt_s(అక్షరం *_DstBuf,కొలత_t కొలత_4,ద్విగుణ _Val,పూర్ణాంకం అంకె_యొక్క_Dights,పూర్ణాంకం *_PtDec,పూర్ణాంకం *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(అక్షరం *_DstBuf,కొలత_t కొలత_4,ద్విగుణ _Val,పూర్ణాంకం అంకె_యొక్క_Dec,పూర్ణాంకం *_PtDec,పూర్ణాంకం *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(అక్షరం *_DstBuf,కొలత_t కొలత_4,ద్విగుణ _Val,పూర్ణాంకం అంకె_యొక్క_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(అక్షరం *మార్గం_ఫలితం,కొలత_t కొలత_4,స్థిరరాశి అక్షరం *_Drive,స్థిరరాశి అక్షరం *_Dir,స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(స్థిరరాశి అక్షరం *_Name,స్థిరరాశి అక్షరం *విలువ_2);
  _CRTIMP errno_t __cdecl _searchenv_s(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_EnvVar,అక్షరం *ఫలితం_మార్గం,కొలత_t కొలత_లోపల_బైట్లు);
  _CRTIMP errno_t __cdecl _splitpath_s(స్థిరరాశి అక్షరం *నిండిన_మార్గం,అక్షరం *_Drive,కొలత_t Drive_కొలత,అక్షరం *_Dir,కొలత_t Dir_కొలత,అక్షరం *_Filename,కొలత_t Filename_కొలత,అక్షరం *_Ext,కొలత_t Ext_కొలత);

#నిర్వచితం_కాకపోతే _WSTDLIBP_S_DEFINED
#నిర్వచించు _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *మార్గం_ఫలితం,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి wchar_t *_Drive,స్థిరరాశి wchar_t *_Dir,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(స్థిరరాశి wchar_t *_Name,స్థిరరాశి wchar_t *విలువ_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_EnvVar,wchar_t *ఫలితం_మార్గం,కొలత_t కొలత_లోపల_పదాలు);
  _CRTIMP errno_t __cdecl _wsplitpath_s(స్థిరరాశి wchar_t *నిండిన_మార్గం,wchar_t *_Drive,కొలత_t Drive_కొలత_లోపల_పదాలు,wchar_t *_Dir,కొలత_t Dir_కొలత_లోపల_పదాలు,wchar_t *_Filename,కొలత_t Filename_కొలత_లోపల_పదాలు,wchar_t *_Ext,కొలత_t Ext_కొలత_లోపల_పదాలు);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#అయితే_ముగింపు
#అయితే_ముగింపు
