/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB_S
#define _INC_STDLIB_S

#ضمن <stdlib.h>

#ܐܢ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
خارجي "C" {
#endif

  _CRTIMP errno_t __cdecl _dupenv_s(حرف **_PBuffer,size_t *_PBufferSizeInBytes,ثابت حرف *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(صحيح _Value,حرف *_DstBuf,size_t _Size,صحيح _Radix);
#ܐܢ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,حرف *_DstBuf,size_t _Size,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(unsigned __int64 _Val,حرف *_DstBuf,size_t _Size,صحيح _Radix);
#endif
  _CRTIMP errno_t __cdecl _ltoa_s(long _Val,حرف *_DstBuf,size_t _Size,صحيح _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(size_t *_PtNumOfCharConverted,wchar_t *_DstBuf,size_t _SizeInWords,ثابت حرف *_SrcBuf,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(size_t *_PtNumOfCharConverted,wchar_t *_DstBuf,size_t _SizeInWords,ثابت حرف *_SrcBuf,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(unsigned long _Val,حرف *_DstBuf,size_t _Size,صحيح _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(صحيح *_SizeConverted,حرف *_MbCh,size_t _SizeInBytes,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(size_t *_PtNumOfCharConverted,حرف *_Dst,size_t _DstSizeInBytes,ثابت wchar_t *_Src,size_t _MaxCountInBytes);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(size_t *_PtNumOfCharConverted,حرف *_Dst,size_t _DstSizeInBytes,ثابت wchar_t *_Src,size_t _MaxCountInBytes,_locale_t _Locale);

#ifndef _WSTDLIB_S_DEFINED
#define _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (صحيح _Val,wchar_t *_DstBuf,size_t _SizeInWords,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (long _Val,wchar_t *_DstBuf,size_t _SizeInWords,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (unsigned long _Val,wchar_t *_DstBuf,size_t _SizeInWords,صحيح _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(size_t *_ReturnSize,wchar_t *_DstBuf,size_t _DstSizeInWords,ثابت wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **_Buffer,size_t *_BufferSizeInWords,ثابت wchar_t *_VarName);
#ܐܢ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,size_t _SizeInWords,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(unsigned __int64 _Val,wchar_t *_DstBuf,size_t _SizeInWords,صحيح _Radix);
#endif
#endif

#ifndef _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(حرف *_DstBuf,size_t _Size,مزدوج _Val,صحيح _NumOfDights,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(حرف *_DstBuf,size_t _Size,مزدوج _Val,صحيح _NumOfDec,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(حرف *_DstBuf,size_t _Size,مزدوج _Val,صحيح _NumOfDigits);
  _CRTIMP errno_t __cdecl _makepath_s(حرف *_PathResult,size_t _Size,ثابت حرف *_Drive,ثابت حرف *_Dir,ثابت حرف *_Filename,ثابت حرف *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(ثابت حرف *_Name,ثابت حرف *_Value);
  _CRTIMP errno_t __cdecl _searchenv_s(ثابت حرف *_Filename,ثابت حرف *_EnvVar,حرف *_ResultPath,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _splitpath_s(ثابت حرف *_FullPath,حرف *_Drive,size_t _DriveSize,حرف *_Dir,size_t _DirSize,حرف *_Filename,size_t _FilenameSize,حرف *_Ext,size_t _ExtSize);

#ifndef _WSTDLIBP_S_DEFINED
#define _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_PathResult,size_t _SizeInWords,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ثابت wchar_t *_Name,ثابت wchar_t *_Value);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *_ResultPath,size_t _SizeInWords);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ثابت wchar_t *_FullPath,wchar_t *_Drive,size_t _DriveSizeInWords,wchar_t *_Dir,size_t _DirSizeInWords,wchar_t *_Filename,size_t _FilenameSizeInWords,wchar_t *_Ext,size_t _ExtSizeInWords);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
