/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_STDLIB_S
#تعریف_کړه _INC_STDLIB_S

#ضمن <stdlib.h>

#إذا defined(MINGW_HAS_SECURE_API)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

  _CRTIMP errno_t __cdecl _dupenv_s(حرف **_PBuffer,اندازه_t *PBuffer_اندازه_دننه_بایټونه,ثابت حرف *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(صحيح ارزښت_2,حرف *_DstBuf,اندازه_t اندازه_4,صحيح _Radix);
#إذا INTEGRAL_MAX_بټونه >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,حرف *_DstBuf,اندازه_t اندازه_4,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(بینښه __int64 _Val,حرف *_DstBuf,اندازه_t اندازه_4,صحيح _Radix);
#د_که_پای
  _CRTIMP errno_t __cdecl _ltoa_s(اوږد _Val,حرف *_DstBuf,اندازه_t اندازه_4,صحيح _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(اندازه_t *Pt_عدد_د_Char_Converted,wchar_t *_DstBuf,اندازه_t اندازه_دننه_ټکي,ثابت حرف *_SrcBuf,اندازه_t Max_شمېر);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(اندازه_t *Pt_عدد_د_Char_Converted,wchar_t *_DstBuf,اندازه_t اندازه_دننه_ټکي,ثابت حرف *_SrcBuf,اندازه_t Max_شمېر,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(بینښه اوږد _Val,حرف *_DstBuf,اندازه_t اندازه_4,صحيح _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(صحيح *اندازه_Converted,حرف *_MbCh,اندازه_t اندازه_دننه_بایټونه,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(اندازه_t *Pt_عدد_د_Char_Converted,حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,ثابت wchar_t *_Src,اندازه_t Max_شمېر_دننه_بایټونه);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(اندازه_t *Pt_عدد_د_Char_Converted,حرف *_Dst,اندازه_t Dst_اندازه_دننه_بایټونه,ثابت wchar_t *_Src,اندازه_t Max_شمېر_دننه_بایټونه,_locale_t _Locale);

#که_نه_تعریف_شوی _WSTDLIB_S_DEFINED
#تعریف_کړه _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (صحيح _Val,wchar_t *_DstBuf,اندازه_t اندازه_دننه_ټکي,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (اوږد _Val,wchar_t *_DstBuf,اندازه_t اندازه_دننه_ټکي,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (بینښه اوږد _Val,wchar_t *_DstBuf,اندازه_t اندازه_دننه_ټکي,صحيح _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(اندازه_t *Return_اندازه,wchar_t *_DstBuf,اندازه_t Dst_اندازه_دننه_ټکي,ثابت wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **بفر_2,اندازه_t *بفر_اندازه_دننه_ټکي,ثابت wchar_t *_VarName);
#إذا INTEGRAL_MAX_بټونه >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,اندازه_t اندازه_دننه_ټکي,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(بینښه __int64 _Val,wchar_t *_DstBuf,اندازه_t اندازه_دننه_ټکي,صحيح _Radix);
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(حرف *_DstBuf,اندازه_t اندازه_4,مزدوج _Val,صحيح عدد_د_Dights,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(حرف *_DstBuf,اندازه_t اندازه_4,مزدوج _Val,صحيح عدد_د_Dec,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(حرف *_DstBuf,اندازه_t اندازه_4,مزدوج _Val,صحيح عدد_د_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(حرف *لار_پایله,اندازه_t اندازه_4,ثابت حرف *_Drive,ثابت حرف *_Dir,ثابت حرف *_Filename,ثابت حرف *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(ثابت حرف *_Name,ثابت حرف *ارزښت_2);
  _CRTIMP errno_t __cdecl _searchenv_s(ثابت حرف *_Filename,ثابت حرف *_EnvVar,حرف *پایله_لار,اندازه_t اندازه_دننه_بایټونه);
  _CRTIMP errno_t __cdecl _splitpath_s(ثابت حرف *ډک_لار,حرف *_Drive,اندازه_t Drive_اندازه,حرف *_Dir,اندازه_t Dir_اندازه,حرف *_Filename,اندازه_t Filename_اندازه,حرف *_Ext,اندازه_t Ext_اندازه);

#که_نه_تعریف_شوی _WSTDLIBP_S_DEFINED
#تعریف_کړه _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *لار_پایله,اندازه_t اندازه_دننه_ټکي,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ثابت wchar_t *_Name,ثابت wchar_t *ارزښت_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *پایله_لار,اندازه_t اندازه_دننه_ټکي);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ثابت wchar_t *ډک_لار,wchar_t *_Drive,اندازه_t Drive_اندازه_دننه_ټکي,wchar_t *_Dir,اندازه_t Dir_اندازه_دننه_ټکي,wchar_t *_Filename,اندازه_t Filename_اندازه_دننه_ټکي,wchar_t *_Ext,اندازه_t Ext_اندازه_دننه_ټکي);
#د_که_پای
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#د_که_پای
#د_که_پای
