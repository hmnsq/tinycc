/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB_S
#define _INC_STDLIB_S

#include <stdlib.h>

#ᱡᱩᱫᱤ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
extern "C" {
#endif

  _CRTIMP errno_t __cdecl _dupenv_s(var_na **_PBuffer,size_t *_PBufferSizeInBytes,const var_na *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(puur_naa_nka _Value,var_na *_DstBuf,size_t _Size,puur_naa_nka _Radix);
#ᱡᱩᱫᱤ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,var_na *_DstBuf,size_t _Size,puur_naa_nka _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(unsigned __int64 _Val,var_na *_DstBuf,size_t _Size,puur_naa_nka _Radix);
#endif
  _CRTIMP errno_t __cdecl _ltoa_s(long _Val,var_na *_DstBuf,size_t _Size,puur_naa_nka _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(size_t *_PtNumOfCharConverted,wchar_t *_DstBuf,size_t _SizeInWords,const var_na *_SrcBuf,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(size_t *_PtNumOfCharConverted,wchar_t *_DstBuf,size_t _SizeInWords,const var_na *_SrcBuf,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(unsigned long _Val,var_na *_DstBuf,size_t _Size,puur_naa_nka _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(puur_naa_nka *_SizeConverted,var_na *_MbCh,size_t _SizeInBytes,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(size_t *_PtNumOfCharConverted,var_na *_Dst,size_t _DstSizeInBytes,const wchar_t *_Src,size_t _MaxCountInBytes);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(size_t *_PtNumOfCharConverted,var_na *_Dst,size_t _DstSizeInBytes,const wchar_t *_Src,size_t _MaxCountInBytes,_locale_t _Locale);

#ifndef _WSTDLIB_S_DEFINED
#define _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (puur_naa_nka _Val,wchar_t *_DstBuf,size_t _SizeInWords,puur_naa_nka _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (long _Val,wchar_t *_DstBuf,size_t _SizeInWords,puur_naa_nka _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (unsigned long _Val,wchar_t *_DstBuf,size_t _SizeInWords,puur_naa_nka _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(size_t *_ReturnSize,wchar_t *_DstBuf,size_t _DstSizeInWords,const wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **_Buffer,size_t *_BufferSizeInWords,const wchar_t *_VarName);
#ᱡᱩᱫᱤ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,size_t _SizeInWords,puur_naa_nka _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(unsigned __int64 _Val,wchar_t *_DstBuf,size_t _SizeInWords,puur_naa_nka _Radix);
#endif
#endif

#ifndef _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(var_na *_DstBuf,size_t _Size,dviguu_na _Val,puur_naa_nka _NumOfDights,puur_naa_nka *_PtDec,puur_naa_nka *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(var_na *_DstBuf,size_t _Size,dviguu_na _Val,puur_naa_nka _NumOfDec,puur_naa_nka *_PtDec,puur_naa_nka *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(var_na *_DstBuf,size_t _Size,dviguu_na _Val,puur_naa_nka _NumOfDigits);
  _CRTIMP errno_t __cdecl _makepath_s(var_na *_PathResult,size_t _Size,const var_na *_Drive,const var_na *_Dir,const var_na *_Filename,const var_na *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(const var_na *_Name,const var_na *_Value);
  _CRTIMP errno_t __cdecl _searchenv_s(const var_na *_Filename,const var_na *_EnvVar,var_na *_ResultPath,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _splitpath_s(const var_na *_FullPath,var_na *_Drive,size_t _DriveSize,var_na *_Dir,size_t _DirSize,var_na *_Filename,size_t _FilenameSize,var_na *_Ext,size_t _ExtSize);

#ifndef _WSTDLIBP_S_DEFINED
#define _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_PathResult,size_t _SizeInWords,const wchar_t *_Drive,const wchar_t *_Dir,const wchar_t *_Filename,const wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(const wchar_t *_Name,const wchar_t *_Value);
  _CRTIMP errno_t __cdecl _wsearchenv_s(const wchar_t *_Filename,const wchar_t *_EnvVar,wchar_t *_ResultPath,size_t _SizeInWords);
  _CRTIMP errno_t __cdecl _wsplitpath_s(const wchar_t *_FullPath,wchar_t *_Drive,size_t _DriveSizeInWords,wchar_t *_Dir,size_t _DirSizeInWords,wchar_t *_Filename,size_t _FilenameSizeInWords,wchar_t *_Ext,size_t _ExtSizeInWords);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
