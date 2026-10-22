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
বাহ্য "C" {
#endif

  _CRTIMP errno_t __cdecl _dupenv_s(বর্ণ **_PBuffer,size_t *_PBufferSizeInBytes,ধ্রুব বর্ণ *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(পূর্ণাঙ্ক মান_2,বর্ণ *_DstBuf,size_t _Size,পূর্ণাঙ্ক _Radix);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,বর্ণ *_DstBuf,size_t _Size,পূর্ণাঙ্ক _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(unsigned __int64 _Val,বর্ণ *_DstBuf,size_t _Size,পূর্ণাঙ্ক _Radix);
#endif
  _CRTIMP errno_t __cdecl _ltoa_s(long _Val,বর্ণ *_DstBuf,size_t _Size,পূর্ণাঙ্ক _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(size_t *Pt_অঙ্ক_Of_Char_Converted,wchar_t *_DstBuf,size_t Size_In_শব্দগুলি,ধ্রুব বর্ণ *_SrcBuf,size_t Max_গুনতি);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(size_t *Pt_অঙ্ক_Of_Char_Converted,wchar_t *_DstBuf,size_t Size_In_শব্দগুলি,ধ্রুব বর্ণ *_SrcBuf,size_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(unsigned long _Val,বর্ণ *_DstBuf,size_t _Size,পূর্ণাঙ্ক _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(পূর্ণাঙ্ক *_SizeConverted,বর্ণ *_MbCh,size_t _SizeInBytes,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(size_t *Pt_অঙ্ক_Of_Char_Converted,বর্ণ *_Dst,size_t _DstSizeInBytes,ধ্রুব wchar_t *_Src,size_t Max_গুনতি_In_Bytes);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(size_t *Pt_অঙ্ক_Of_Char_Converted,বর্ণ *_Dst,size_t _DstSizeInBytes,ধ্রুব wchar_t *_Src,size_t Max_গুনতি_In_Bytes,_locale_t _Locale);

#ifndef _WSTDLIB_S_DEFINED
#define _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (পূর্ণাঙ্ক _Val,wchar_t *_DstBuf,size_t Size_In_শব্দগুলি,পূর্ণাঙ্ক _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (long _Val,wchar_t *_DstBuf,size_t Size_In_শব্দগুলি,পূর্ণাঙ্ক _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (unsigned long _Val,wchar_t *_DstBuf,size_t Size_In_শব্দগুলি,পূর্ণাঙ্ক _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(size_t *_ReturnSize,wchar_t *_DstBuf,size_t Dst_Size_In_শব্দগুলি,ধ্রুব wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **_Buffer,size_t *Buffer_Size_In_শব্দগুলি,ধ্রুব wchar_t *_VarName);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,size_t Size_In_শব্দগুলি,পূর্ণাঙ্ক _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(unsigned __int64 _Val,wchar_t *_DstBuf,size_t Size_In_শব্দগুলি,পূর্ণাঙ্ক _Radix);
#endif
#endif

#ifndef _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(বর্ণ *_DstBuf,size_t _Size,দ্বিগুণ _Val,পূর্ণাঙ্ক অঙ্ক_Of_Dights,পূর্ণাঙ্ক *_PtDec,পূর্ণাঙ্ক *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(বর্ণ *_DstBuf,size_t _Size,দ্বিগুণ _Val,পূর্ণাঙ্ক অঙ্ক_Of_Dec,পূর্ণাঙ্ক *_PtDec,পূর্ণাঙ্ক *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(বর্ণ *_DstBuf,size_t _Size,দ্বিগুণ _Val,পূর্ণাঙ্ক অঙ্ক_Of_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(বর্ণ *_PathResult,size_t _Size,ধ্রুব বর্ণ *_Drive,ধ্রুব বর্ণ *_Dir,ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(ধ্রুব বর্ণ *_Name,ধ্রুব বর্ণ *মান_2);
  _CRTIMP errno_t __cdecl _searchenv_s(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_EnvVar,বর্ণ *_ResultPath,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _splitpath_s(ধ্রুব বর্ণ *_FullPath,বর্ণ *_Drive,size_t _DriveSize,বর্ণ *_Dir,size_t _DirSize,বর্ণ *_Filename,size_t _FilenameSize,বর্ণ *_Ext,size_t _ExtSize);

#ifndef _WSTDLIBP_S_DEFINED
#define _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_PathResult,size_t Size_In_শব্দগুলি,ধ্রুব wchar_t *_Drive,ধ্রুব wchar_t *_Dir,ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ধ্রুব wchar_t *_Name,ধ্রুব wchar_t *মান_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_EnvVar,wchar_t *_ResultPath,size_t Size_In_শব্দগুলি);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ধ্রুব wchar_t *_FullPath,wchar_t *_Drive,size_t Drive_Size_In_শব্দগুলি,wchar_t *_Dir,size_t Dir_Size_In_শব্দগুলি,wchar_t *_Filename,size_t Filename_Size_In_শব্দগুলি,wchar_t *_Ext,size_t Ext_Size_In_শব্দগুলি);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
