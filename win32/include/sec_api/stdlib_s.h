/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_STDLIB_S
#تعریف_کرو _INC_STDLIB_S

#شامل <stdlib.h>

#اگر defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

  _CRTIMP errno_t __cdecl _dupenv_s(حرف **_PBuffer,سائز_t *PBuffer_سائز_اندر_بائٹیں,ثابت حرف *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(صحیح قدر_2,حرف *_DstBuf,سائز_t سائز_4,صحیح _Radix);
#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,حرف *_DstBuf,سائز_t سائز_4,صحیح _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(غیرعلامتی __int64 _Val,حرف *_DstBuf,سائز_t سائز_4,صحیح _Radix);
#اگر_ختم
  _CRTIMP errno_t __cdecl _ltoa_s(طویل _Val,حرف *_DstBuf,سائز_t سائز_4,صحیح _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(سائز_t *Pt_عدد_کا_Char_Converted,wchar_t *_DstBuf,سائز_t سائز_اندر_الفاظ,ثابت حرف *_SrcBuf,سائز_t Max_گنتی);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(سائز_t *Pt_عدد_کا_Char_Converted,wchar_t *_DstBuf,سائز_t سائز_اندر_الفاظ,ثابت حرف *_SrcBuf,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(غیرعلامتی طویل _Val,حرف *_DstBuf,سائز_t سائز_4,صحیح _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(صحیح *سائز_Converted,حرف *_MbCh,سائز_t سائز_اندر_بائٹیں,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(سائز_t *Pt_عدد_کا_Char_Converted,حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,ثابت wchar_t *_Src,سائز_t Max_گنتی_اندر_بائٹیں);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(سائز_t *Pt_عدد_کا_Char_Converted,حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,ثابت wchar_t *_Src,سائز_t Max_گنتی_اندر_بائٹیں,_locale_t _Locale);

#اگر_غیر_تعریف_شدہ _WSTDLIB_S_DEFINED
#تعریف_کرو _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (صحیح _Val,wchar_t *_DstBuf,سائز_t سائز_اندر_الفاظ,صحیح _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (طویل _Val,wchar_t *_DstBuf,سائز_t سائز_اندر_الفاظ,صحیح _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (غیرعلامتی طویل _Val,wchar_t *_DstBuf,سائز_t سائز_اندر_الفاظ,صحیح _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(سائز_t *Return_سائز,wchar_t *_DstBuf,سائز_t Dst_سائز_اندر_الفاظ,ثابت wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **بفر_2,سائز_t *بفر_سائز_اندر_الفاظ,ثابت wchar_t *_VarName);
#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,سائز_t سائز_اندر_الفاظ,صحیح _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(غیرعلامتی __int64 _Val,wchar_t *_DstBuf,سائز_t سائز_اندر_الفاظ,صحیح _Radix);
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(حرف *_DstBuf,سائز_t سائز_4,دوہرا _Val,صحیح عدد_کا_Dights,صحیح *_PtDec,صحیح *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(حرف *_DstBuf,سائز_t سائز_4,دوہرا _Val,صحیح عدد_کا_Dec,صحیح *_PtDec,صحیح *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(حرف *_DstBuf,سائز_t سائز_4,دوہرا _Val,صحیح عدد_کا_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(حرف *راستہ_نتیجہ,سائز_t سائز_4,ثابت حرف *_Drive,ثابت حرف *_Dir,ثابت حرف *_Filename,ثابت حرف *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(ثابت حرف *_Name,ثابت حرف *قدر_2);
  _CRTIMP errno_t __cdecl _searchenv_s(ثابت حرف *_Filename,ثابت حرف *_EnvVar,حرف *نتیجہ_راستہ,سائز_t سائز_اندر_بائٹیں);
  _CRTIMP errno_t __cdecl _splitpath_s(ثابت حرف *بھرا_راستہ,حرف *_Drive,سائز_t Drive_سائز,حرف *_Dir,سائز_t Dir_سائز,حرف *_Filename,سائز_t Filename_سائز,حرف *_Ext,سائز_t Ext_سائز);

#اگر_غیر_تعریف_شدہ _WSTDLIBP_S_DEFINED
#تعریف_کرو _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *راستہ_نتیجہ,سائز_t سائز_اندر_الفاظ,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ثابت wchar_t *_Name,ثابت wchar_t *قدر_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *نتیجہ_راستہ,سائز_t سائز_اندر_الفاظ);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ثابت wchar_t *بھرا_راستہ,wchar_t *_Drive,سائز_t Drive_سائز_اندر_الفاظ,wchar_t *_Dir,سائز_t Dir_سائز_اندر_الفاظ,wchar_t *_Filename,سائز_t Filename_سائز_اندر_الفاظ,wchar_t *_Ext,سائز_t Ext_سائز_اندر_الفاظ);
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#اگر_ختم
#اگر_ختم
