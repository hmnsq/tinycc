/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_STDLIB_S
#وصف_ڪريو _INC_STDLIB_S

#ضمن <stdlib.h>

#إذا defined(MINGW_HAS_SECURE_API)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

  _CRTIMP errno_t __cdecl _dupenv_s(حرف **_PBuffer,سائيز_t *PBuffer_سائيز_اندريون_بائيٽون,ثابت حرف *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(صحيح قدر_2,حرف *_DstBuf,سائيز_t سائيز_4,صحيح _Radix);
#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,حرف *_DstBuf,سائيز_t سائيز_4,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(بنانشان __int64 _Val,حرف *_DstBuf,سائيز_t سائيز_4,صحيح _Radix);
#جيڪڏهن_پورو
  _CRTIMP errno_t __cdecl _ltoa_s(ڊگهو _Val,حرف *_DstBuf,سائيز_t سائيز_4,صحيح _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(سائيز_t *Pt_انگ_جو_Char_Converted,wchar_t *_DstBuf,سائيز_t سائيز_اندريون_لفظ,ثابت حرف *_SrcBuf,سائيز_t Max_ڳڻپ);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(سائيز_t *Pt_انگ_جو_Char_Converted,wchar_t *_DstBuf,سائيز_t سائيز_اندريون_لفظ,ثابت حرف *_SrcBuf,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(بنانشان ڊگهو _Val,حرف *_DstBuf,سائيز_t سائيز_4,صحيح _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(صحيح *سائيز_Converted,حرف *_MbCh,سائيز_t سائيز_اندريون_بائيٽون,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(سائيز_t *Pt_انگ_جو_Char_Converted,حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,ثابت wchar_t *_Src,سائيز_t Max_ڳڻپ_اندريون_بائيٽون);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(سائيز_t *Pt_انگ_جو_Char_Converted,حرف *_Dst,سائيز_t Dst_سائيز_اندريون_بائيٽون,ثابت wchar_t *_Src,سائيز_t Max_ڳڻپ_اندريون_بائيٽون,_locale_t _Locale);

#جيڪڏهن_وصف_نه_ٿيل _WSTDLIB_S_DEFINED
#وصف_ڪريو _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (صحيح _Val,wchar_t *_DstBuf,سائيز_t سائيز_اندريون_لفظ,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (ڊگهو _Val,wchar_t *_DstBuf,سائيز_t سائيز_اندريون_لفظ,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (بنانشان ڊگهو _Val,wchar_t *_DstBuf,سائيز_t سائيز_اندريون_لفظ,صحيح _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(سائيز_t *Return_سائيز,wchar_t *_DstBuf,سائيز_t Dst_سائيز_اندريون_لفظ,ثابت wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **بفر_2,سائيز_t *بفر_سائيز_اندريون_لفظ,ثابت wchar_t *_VarName);
#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,سائيز_t سائيز_اندريون_لفظ,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(بنانشان __int64 _Val,wchar_t *_DstBuf,سائيز_t سائيز_اندريون_لفظ,صحيح _Radix);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(حرف *_DstBuf,سائيز_t سائيز_4,مزدوج _Val,صحيح انگ_جو_Dights,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(حرف *_DstBuf,سائيز_t سائيز_4,مزدوج _Val,صحيح انگ_جو_Dec,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(حرف *_DstBuf,سائيز_t سائيز_4,مزدوج _Val,صحيح انگ_جو_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(حرف *رستو_نتيجو,سائيز_t سائيز_4,ثابت حرف *_Drive,ثابت حرف *_Dir,ثابت حرف *_Filename,ثابت حرف *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(ثابت حرف *_Name,ثابت حرف *قدر_2);
  _CRTIMP errno_t __cdecl _searchenv_s(ثابت حرف *_Filename,ثابت حرف *_EnvVar,حرف *نتيجو_رستو,سائيز_t سائيز_اندريون_بائيٽون);
  _CRTIMP errno_t __cdecl _splitpath_s(ثابت حرف *ڀريل_رستو,حرف *_Drive,سائيز_t Drive_سائيز,حرف *_Dir,سائيز_t Dir_سائيز,حرف *_Filename,سائيز_t Filename_سائيز,حرف *_Ext,سائيز_t Ext_سائيز);

#جيڪڏهن_وصف_نه_ٿيل _WSTDLIBP_S_DEFINED
#وصف_ڪريو _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *رستو_نتيجو,سائيز_t سائيز_اندريون_لفظ,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ثابت wchar_t *_Name,ثابت wchar_t *قدر_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *نتيجو_رستو,سائيز_t سائيز_اندريون_لفظ);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ثابت wchar_t *ڀريل_رستو,wchar_t *_Drive,سائيز_t Drive_سائيز_اندريون_لفظ,wchar_t *_Dir,سائيز_t Dir_سائيز_اندريون_لفظ,wchar_t *_Filename,سائيز_t Filename_سائيز_اندريون_لفظ,wchar_t *_Ext,سائيز_t Ext_سائيز_اندريون_لفظ);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#جيڪڏهن_پورو
#جيڪڏهن_پورو
