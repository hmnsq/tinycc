/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB_S
#define _INC_STDLIB_S

#شامل <stdlib.h>

#اگر defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
بیرونی "C" {
#endif

  _CRTIMP errno_t __cdecl _dupenv_s(نویسه **_PBuffer,size_t *_PBufferSizeInBytes,ثابت نویسه *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(صحیح مقدار_2,نویسه *_DstBuf,size_t _Size,صحیح _Radix);
#اگر _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,نویسه *_DstBuf,size_t _Size,صحیح _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(unsigned __int64 _Val,نویسه *_DstBuf,size_t _Size,صحیح _Radix);
#endif
  _CRTIMP errno_t __cdecl _ltoa_s(long _Val,نویسه *_DstBuf,size_t _Size,صحیح _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(size_t *Pt_رقم_Of_Char_Converted,wchar_t *_DstBuf,size_t Size_In_واژگان,ثابت نویسه *_SrcBuf,size_t Max_شمار);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(size_t *Pt_رقم_Of_Char_Converted,wchar_t *_DstBuf,size_t Size_In_واژگان,ثابت نویسه *_SrcBuf,size_t Max_شمار,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(unsigned long _Val,نویسه *_DstBuf,size_t _Size,صحیح _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(صحیح *_SizeConverted,نویسه *_MbCh,size_t _SizeInBytes,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(size_t *Pt_رقم_Of_Char_Converted,نویسه *_Dst,size_t _DstSizeInBytes,ثابت wchar_t *_Src,size_t Max_شمار_In_Bytes);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(size_t *Pt_رقم_Of_Char_Converted,نویسه *_Dst,size_t _DstSizeInBytes,ثابت wchar_t *_Src,size_t Max_شمار_In_Bytes,_locale_t _Locale);

#ifndef _WSTDLIB_S_DEFINED
#define _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (صحیح _Val,wchar_t *_DstBuf,size_t Size_In_واژگان,صحیح _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (long _Val,wchar_t *_DstBuf,size_t Size_In_واژگان,صحیح _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (unsigned long _Val,wchar_t *_DstBuf,size_t Size_In_واژگان,صحیح _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(size_t *_ReturnSize,wchar_t *_DstBuf,size_t Dst_Size_In_واژگان,ثابت wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **_Buffer,size_t *Buffer_Size_In_واژگان,ثابت wchar_t *_VarName);
#اگر _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,size_t Size_In_واژگان,صحیح _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(unsigned __int64 _Val,wchar_t *_DstBuf,size_t Size_In_واژگان,صحیح _Radix);
#endif
#endif

#ifndef _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(نویسه *_DstBuf,size_t _Size,دوگانه _Val,صحیح رقم_Of_Dights,صحیح *_PtDec,صحیح *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(نویسه *_DstBuf,size_t _Size,دوگانه _Val,صحیح رقم_Of_Dec,صحیح *_PtDec,صحیح *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(نویسه *_DstBuf,size_t _Size,دوگانه _Val,صحیح رقم_Of_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(نویسه *_PathResult,size_t _Size,ثابت نویسه *_Drive,ثابت نویسه *_Dir,ثابت نویسه *_Filename,ثابت نویسه *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(ثابت نویسه *_Name,ثابت نویسه *مقدار_2);
  _CRTIMP errno_t __cdecl _searchenv_s(ثابت نویسه *_Filename,ثابت نویسه *_EnvVar,نویسه *_ResultPath,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _splitpath_s(ثابت نویسه *_FullPath,نویسه *_Drive,size_t _DriveSize,نویسه *_Dir,size_t _DirSize,نویسه *_Filename,size_t _FilenameSize,نویسه *_Ext,size_t _ExtSize);

#ifndef _WSTDLIBP_S_DEFINED
#define _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_PathResult,size_t Size_In_واژگان,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ثابت wchar_t *_Name,ثابت wchar_t *مقدار_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *_ResultPath,size_t Size_In_واژگان);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ثابت wchar_t *_FullPath,wchar_t *_Drive,size_t Drive_Size_In_واژگان,wchar_t *_Dir,size_t Dir_Size_In_واژگان,wchar_t *_Filename,size_t Filename_Size_In_واژگان,wchar_t *_Ext,size_t Ext_Size_In_واژگان);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
