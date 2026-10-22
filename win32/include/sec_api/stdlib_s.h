/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_STDLIB_S
#تعریف_کن _INC_STDLIB_S

#ضمن <stdlib.h>

#إذا defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

  _CRTIMP errno_t __cdecl _dupenv_s(حرف **_PBuffer,اندازه_t *PBuffer_اندازه_درون_بایتها,ثابت حرف *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(صحيح مقدار_2,حرف *_DstBuf,اندازه_t اندازه_4,صحيح _Radix);
#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,حرف *_DstBuf,اندازه_t اندازه_4,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(بیعلامت __int64 _Val,حرف *_DstBuf,اندازه_t اندازه_4,صحيح _Radix);
#پایان_اگر
  _CRTIMP errno_t __cdecl _ltoa_s(دراز _Val,حرف *_DstBuf,اندازه_t اندازه_4,صحيح _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(اندازه_t *Pt_رقم_از_Char_Converted,wchar_t *_DstBuf,اندازه_t اندازه_درون_واژگان,ثابت حرف *_SrcBuf,اندازه_t Max_شمار);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(اندازه_t *Pt_رقم_از_Char_Converted,wchar_t *_DstBuf,اندازه_t اندازه_درون_واژگان,ثابت حرف *_SrcBuf,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(بیعلامت دراز _Val,حرف *_DstBuf,اندازه_t اندازه_4,صحيح _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(صحيح *اندازه_Converted,حرف *_MbCh,اندازه_t اندازه_درون_بایتها,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(اندازه_t *Pt_رقم_از_Char_Converted,حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,ثابت wchar_t *_Src,اندازه_t Max_شمار_درون_بایتها);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(اندازه_t *Pt_رقم_از_Char_Converted,حرف *_Dst,اندازه_t Dst_اندازه_درون_بایتها,ثابت wchar_t *_Src,اندازه_t Max_شمار_درون_بایتها,_locale_t _Locale);

#اگر_تعریف_نشده _WSTDLIB_S_DEFINED
#تعریف_کن _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (صحيح _Val,wchar_t *_DstBuf,اندازه_t اندازه_درون_واژگان,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (دراز _Val,wchar_t *_DstBuf,اندازه_t اندازه_درون_واژگان,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (بیعلامت دراز _Val,wchar_t *_DstBuf,اندازه_t اندازه_درون_واژگان,صحيح _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(اندازه_t *Return_اندازه,wchar_t *_DstBuf,اندازه_t Dst_اندازه_درون_واژگان,ثابت wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **میانگیر_2,اندازه_t *میانگیر_اندازه_درون_واژگان,ثابت wchar_t *_VarName);
#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,اندازه_t اندازه_درون_واژگان,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(بیعلامت __int64 _Val,wchar_t *_DstBuf,اندازه_t اندازه_درون_واژگان,صحيح _Radix);
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(حرف *_DstBuf,اندازه_t اندازه_4,مزدوج _Val,صحيح رقم_از_Dights,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(حرف *_DstBuf,اندازه_t اندازه_4,مزدوج _Val,صحيح رقم_از_Dec,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(حرف *_DstBuf,اندازه_t اندازه_4,مزدوج _Val,صحيح رقم_از_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(حرف *مسیر_نتیجه,اندازه_t اندازه_4,ثابت حرف *_Drive,ثابت حرف *_Dir,ثابت حرف *_Filename,ثابت حرف *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(ثابت حرف *_Name,ثابت حرف *مقدار_2);
  _CRTIMP errno_t __cdecl _searchenv_s(ثابت حرف *_Filename,ثابت حرف *_EnvVar,حرف *نتیجه_مسیر,اندازه_t اندازه_درون_بایتها);
  _CRTIMP errno_t __cdecl _splitpath_s(ثابت حرف *پر_مسیر,حرف *_Drive,اندازه_t Drive_اندازه,حرف *_Dir,اندازه_t Dir_اندازه,حرف *_Filename,اندازه_t Filename_اندازه,حرف *_Ext,اندازه_t Ext_اندازه);

#اگر_تعریف_نشده _WSTDLIBP_S_DEFINED
#تعریف_کن _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *مسیر_نتیجه,اندازه_t اندازه_درون_واژگان,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ثابت wchar_t *_Name,ثابت wchar_t *مقدار_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *نتیجه_مسیر,اندازه_t اندازه_درون_واژگان);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ثابت wchar_t *پر_مسیر,wchar_t *_Drive,اندازه_t Drive_اندازه_درون_واژگان,wchar_t *_Dir,اندازه_t Dir_اندازه_درون_واژگان,wchar_t *_Filename,اندازه_t Filename_اندازه_درون_واژگان,wchar_t *_Ext,اندازه_t Ext_اندازه_درون_واژگان);
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#پایان_اگر
#پایان_اگر
