/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _INC_STDLIB_S
#تعریف_کرو _INC_STDLIB_S

#ضمن <stdlib.h>

#إذا defined(MINGW_HAS_SECURE_API)

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

  _CRTIMP errno_t __cdecl _dupenv_s(حرف **_PBuffer,ناپ_t *PBuffer_ناپ_وچ_بائٹاں,ثابت حرف *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(صحيح قدر_2,حرف *_DstBuf,ناپ_t ناپ_4,صحيح _Radix);
#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,حرف *_DstBuf,ناپ_t ناپ_4,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(بنانشانی __int64 _Val,حرف *_DstBuf,ناپ_t ناپ_4,صحيح _Radix);
#جے_انت
  _CRTIMP errno_t __cdecl _ltoa_s(لما _Val,حرف *_DstBuf,ناپ_t ناپ_4,صحيح _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(ناپ_t *Pt_عدد_دا_Char_Converted,wchar_t *_DstBuf,ناپ_t ناپ_وچ_الفاظ,ثابت حرف *_SrcBuf,ناپ_t Max_گنتی);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(ناپ_t *Pt_عدد_دا_Char_Converted,wchar_t *_DstBuf,ناپ_t ناپ_وچ_الفاظ,ثابت حرف *_SrcBuf,ناپ_t Max_گنتی,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(بنانشانی لما _Val,حرف *_DstBuf,ناپ_t ناپ_4,صحيح _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(صحيح *ناپ_Converted,حرف *_MbCh,ناپ_t ناپ_وچ_بائٹاں,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(ناپ_t *Pt_عدد_دا_Char_Converted,حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,ثابت wchar_t *_Src,ناپ_t Max_گنتی_وچ_بائٹاں);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(ناپ_t *Pt_عدد_دا_Char_Converted,حرف *_Dst,ناپ_t Dst_ناپ_وچ_بائٹاں,ثابت wchar_t *_Src,ناپ_t Max_گنتی_وچ_بائٹاں,_locale_t _Locale);

#جے_بنا_تعریف _WSTDLIB_S_DEFINED
#تعریف_کرو _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (صحيح _Val,wchar_t *_DstBuf,ناپ_t ناپ_وچ_الفاظ,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (لما _Val,wchar_t *_DstBuf,ناپ_t ناپ_وچ_الفاظ,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (بنانشانی لما _Val,wchar_t *_DstBuf,ناپ_t ناپ_وچ_الفاظ,صحيح _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(ناپ_t *Return_ناپ,wchar_t *_DstBuf,ناپ_t Dst_ناپ_وچ_الفاظ,ثابت wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **بفر_2,ناپ_t *بفر_ناپ_وچ_الفاظ,ثابت wchar_t *_VarName);
#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,ناپ_t ناپ_وچ_الفاظ,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(بنانشانی __int64 _Val,wchar_t *_DstBuf,ناپ_t ناپ_وچ_الفاظ,صحيح _Radix);
#جے_انت
#جے_انت

#جے_بنا_تعریف _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(حرف *_DstBuf,ناپ_t ناپ_4,مزدوج _Val,صحيح عدد_دا_Dights,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(حرف *_DstBuf,ناپ_t ناپ_4,مزدوج _Val,صحيح عدد_دا_Dec,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(حرف *_DstBuf,ناپ_t ناپ_4,مزدوج _Val,صحيح عدد_دا_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(حرف *رستہ_نتیجہ,ناپ_t ناپ_4,ثابت حرف *_Drive,ثابت حرف *_Dir,ثابت حرف *_Filename,ثابت حرف *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(ثابت حرف *_Name,ثابت حرف *قدر_2);
  _CRTIMP errno_t __cdecl _searchenv_s(ثابت حرف *_Filename,ثابت حرف *_EnvVar,حرف *نتیجہ_رستہ,ناپ_t ناپ_وچ_بائٹاں);
  _CRTIMP errno_t __cdecl _splitpath_s(ثابت حرف *بھریا_رستہ,حرف *_Drive,ناپ_t Drive_ناپ,حرف *_Dir,ناپ_t Dir_ناپ,حرف *_Filename,ناپ_t Filename_ناپ,حرف *_Ext,ناپ_t Ext_ناپ);

#جے_بنا_تعریف _WSTDLIBP_S_DEFINED
#تعریف_کرو _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *رستہ_نتیجہ,ناپ_t ناپ_وچ_الفاظ,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ثابت wchar_t *_Name,ثابت wchar_t *قدر_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *نتیجہ_رستہ,ناپ_t ناپ_وچ_الفاظ);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ثابت wchar_t *بھریا_رستہ,wchar_t *_Drive,ناپ_t Drive_ناپ_وچ_الفاظ,wchar_t *_Dir,ناپ_t Dir_ناپ_وچ_الفاظ,wchar_t *_Filename,ناپ_t Filename_ناپ_وچ_الفاظ,wchar_t *_Ext,ناپ_t Ext_ناپ_وچ_الفاظ);
#جے_انت
#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#جے_انت
#جے_انت
