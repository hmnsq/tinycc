/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB_S
#define _INC_STDLIB_S

#অন্তর্ভাব <stdlib.h>

#যদি defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
বাহ্যিক "C" {
#endif

  _CRTIMP errno_t __cdecl _dupenv_s(অক্ষর **_PBuffer,আকার_t *PBuffer_আকার_In_Bytes,ধ্রুবক অক্ষর *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(পূর্ণসংখ্যা মান_2,অক্ষর *_DstBuf,আকার_t আকার_5,পূর্ণসংখ্যা _Radix);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,অক্ষর *_DstBuf,আকার_t আকার_5,পূর্ণসংখ্যা _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(unsigned __int64 _Val,অক্ষর *_DstBuf,আকার_t আকার_5,পূর্ণসংখ্যা _Radix);
#endif
  _CRTIMP errno_t __cdecl _ltoa_s(long _Val,অক্ষর *_DstBuf,আকার_t আকার_5,পূর্ণসংখ্যা _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(আকার_t *Pt_অঙ্ক_Of_Char_Converted,wchar_t *_DstBuf,আকার_t আকার_In_শব্দগুলি,ধ্রুবক অক্ষর *_SrcBuf,আকার_t Max_গুনতি);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(আকার_t *Pt_অঙ্ক_Of_Char_Converted,wchar_t *_DstBuf,আকার_t আকার_In_শব্দগুলি,ধ্রুবক অক্ষর *_SrcBuf,আকার_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(unsigned long _Val,অক্ষর *_DstBuf,আকার_t আকার_5,পূর্ণসংখ্যা _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(পূর্ণসংখ্যা *আকার_Converted,অক্ষর *_MbCh,আকার_t আকার_In_Bytes,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(আকার_t *Pt_অঙ্ক_Of_Char_Converted,অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,ধ্রুবক wchar_t *_Src,আকার_t Max_গুনতি_In_Bytes);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(আকার_t *Pt_অঙ্ক_Of_Char_Converted,অক্ষর *_Dst,আকার_t Dst_আকার_In_Bytes,ধ্রুবক wchar_t *_Src,আকার_t Max_গুনতি_In_Bytes,_locale_t _Locale);

#ifndef _WSTDLIB_S_DEFINED
#define _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (পূর্ণসংখ্যা _Val,wchar_t *_DstBuf,আকার_t আকার_In_শব্দগুলি,পূর্ণসংখ্যা _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (long _Val,wchar_t *_DstBuf,আকার_t আকার_In_শব্দগুলি,পূর্ণসংখ্যা _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (unsigned long _Val,wchar_t *_DstBuf,আকার_t আকার_In_শব্দগুলি,পূর্ণসংখ্যা _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(আকার_t *Return_আকার,wchar_t *_DstBuf,আকার_t Dst_আকার_In_শব্দগুলি,ধ্রুবক wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **বাফার_2,আকার_t *বাফার_আকার_In_শব্দগুলি,ধ্রুবক wchar_t *_VarName);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,আকার_t আকার_In_শব্দগুলি,পূর্ণসংখ্যা _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(unsigned __int64 _Val,wchar_t *_DstBuf,আকার_t আকার_In_শব্দগুলি,পূর্ণসংখ্যা _Radix);
#endif
#endif

#ifndef _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(অক্ষর *_DstBuf,আকার_t আকার_5,দ্বিগুণ _Val,পূর্ণসংখ্যা অঙ্ক_Of_Dights,পূর্ণসংখ্যা *_PtDec,পূর্ণসংখ্যা *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(অক্ষর *_DstBuf,আকার_t আকার_5,দ্বিগুণ _Val,পূর্ণসংখ্যা অঙ্ক_Of_Dec,পূর্ণসংখ্যা *_PtDec,পূর্ণসংখ্যা *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(অক্ষর *_DstBuf,আকার_t আকার_5,দ্বিগুণ _Val,পূর্ণসংখ্যা অঙ্ক_Of_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(অক্ষর *Path_ফলাফল,আকার_t আকার_5,ধ্রুবক অক্ষর *_Drive,ধ্রুবক অক্ষর *_Dir,ধ্রুবক অক্ষর *_Filename,ধ্রুবক অক্ষর *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(ধ্রুবক অক্ষর *_Name,ধ্রুবক অক্ষর *মান_2);
  _CRTIMP errno_t __cdecl _searchenv_s(ধ্রুবক অক্ষর *_Filename,ধ্রুবক অক্ষর *_EnvVar,অক্ষর *ফলাফল_Path,আকার_t আকার_In_Bytes);
  _CRTIMP errno_t __cdecl _splitpath_s(ধ্রুবক অক্ষর *_FullPath,অক্ষর *_Drive,আকার_t Drive_আকার,অক্ষর *_Dir,আকার_t Dir_আকার,অক্ষর *_Filename,আকার_t Filename_আকার,অক্ষর *_Ext,আকার_t Ext_আকার);

#ifndef _WSTDLIBP_S_DEFINED
#define _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *Path_ফলাফল,আকার_t আকার_In_শব্দগুলি,ধ্রুবক wchar_t *_Drive,ধ্রুবক wchar_t *_Dir,ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ধ্রুবক wchar_t *_Name,ধ্রুবক wchar_t *মান_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_EnvVar,wchar_t *ফলাফল_Path,আকার_t আকার_In_শব্দগুলি);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ধ্রুবক wchar_t *_FullPath,wchar_t *_Drive,আকার_t Drive_আকার_In_শব্দগুলি,wchar_t *_Dir,আকার_t Dir_আকার_In_শব্দগুলি,wchar_t *_Filename,আকার_t Filename_আকার_In_শব্দগুলি,wchar_t *_Ext,আকার_t Ext_আকার_In_শব্দগুলি);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
