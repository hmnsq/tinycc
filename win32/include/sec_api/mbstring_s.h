/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_MBSTRING_S
#నిర్వచించు _INC_MBSTRING_S

#అన్తర్భావ <mbstring.h>

#ఒకవేళ defined(MINGW_HAS_SECURE_API)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _MBSTRING_S_DEFINED
#నిర్వచించు _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,స్థిరరాశి గుర్తులేని అక్షరం *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,స్థిరరాశి గుర్తులేని అక్షరం *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,స్థిరరాశి గుర్తులేని అక్షరం *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,స్థిరరాశి గుర్తులేని అక్షరం *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(గుర్తులేని అక్షరం *_Str,కొలత_t కొలత_లోపల_బైట్లు);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(గుర్తులేని అక్షరం *_Str,కొలత_t కొలత_లోపల_బైట్లు,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,స్థిరరాశి గుర్తులేని అక్షరం *_Src,కొలత_t Max_లెక్క);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,స్థిరరాశి గుర్తులేని అక్షరం *_Src,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,స్థిరరాశి గుర్తులేని అక్షరం *_Src,కొలత_t Max_లెక్క);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,స్థిరరాశి గుర్తులేని అక్షరం *_Src,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,గుర్తులేని పూర్ణాంకం _Ch,కొలత_t Max_లెక్క);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,గుర్తులేని పూర్ణాంకం _Ch,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,స్థిరరాశి గుర్తులేని అక్షరం *_Src,కొలత_t Max_లెక్క);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,స్థిరరాశి గుర్తులేని అక్షరం *_Src,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,స్థిరరాశి గుర్తులేని అక్షరం *_Src,కొలత_t Max_లెక్క);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,స్థిరరాశి గుర్తులేని అక్షరం *_Src,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,గుర్తులేని పూర్ణాంకం _Val,కొలత_t Max_లెక్క);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,గుర్తులేని పూర్ణాంకం _Val,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,గుర్తులేని పూర్ణాంకం _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,గుర్తులేని పూర్ణాంకం _Val,_locale_t _Locale);
  _CRTIMP గుర్తులేని అక్షరం *__cdecl _mbstok_s(గుర్తులేని అక్షరం *_Str,స్థిరరాశి గుర్తులేని అక్షరం *_Delim,గుర్తులేని అక్షరం **_Context);
  _CRTIMP గుర్తులేని అక్షరం *__cdecl _mbstok_s_l(గుర్తులేని అక్షరం *_Str,స్థిరరాశి గుర్తులేని అక్షరం *_Delim,గుర్తులేని అక్షరం **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(గుర్తులేని అక్షరం *_Str,కొలత_t కొలత_లోపల_బైట్లు);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(గుర్తులేని అక్షరం *_Str,కొలత_t కొలత_లోపల_బైట్లు,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,పూర్ణాంకం *_PCopied,స్థిరరాశి గుర్తులేని అక్షరం *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(గుర్తులేని అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_బైట్లు,పూర్ణాంకం *_PCopied,స్థిరరాశి గుర్తులేని అక్షరం *_Src,_locale_t _Locale);
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#అయితే_ముగింపు
#అయితే_ముగింపు
