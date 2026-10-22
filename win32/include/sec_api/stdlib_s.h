/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB_S
#define _INC_STDLIB_S

#include <stdlib.h>

#if defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
extern "C" {
#endif

  _CRTIMP errno_t __cdecl _dupenv_s(char **_PBuffer,size_t *_PBufferSizeInBytes,const char *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(int हालागा_2,char *_DstBuf,size_t _Size,int _Radix);
#if _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,char *_DstBuf,size_t _Size,int _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(unsigned __int64 _Val,char *_DstBuf,size_t _Size,int _Radix);
#endif
  _CRTIMP errno_t __cdecl _ltoa_s(long _Val,char *_DstBuf,size_t _Size,int _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(size_t *Pt_नुमेरो_Of_Char_Converted,wchar_t *_DstBuf,size_t Size_In_मगा_सालिता,const char *_SrcBuf,size_t Max_बिलांग);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(size_t *Pt_नुमेरो_Of_Char_Converted,wchar_t *_DstBuf,size_t Size_In_मगा_सालिता,const char *_SrcBuf,size_t Max_बिलांग,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(unsigned long _Val,char *_DstBuf,size_t _Size,int _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(int *_SizeConverted,char *_MbCh,size_t _SizeInBytes,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(size_t *Pt_नुमेरो_Of_Char_Converted,char *_Dst,size_t _DstSizeInBytes,const wchar_t *_Src,size_t Max_बिलांग_In_Bytes);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(size_t *Pt_नुमेरो_Of_Char_Converted,char *_Dst,size_t _DstSizeInBytes,const wchar_t *_Src,size_t Max_बिलांग_In_Bytes,_locale_t _Locale);

#ifndef _WSTDLIB_S_DEFINED
#define _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (int _Val,wchar_t *_DstBuf,size_t Size_In_मगा_सालिता,int _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (long _Val,wchar_t *_DstBuf,size_t Size_In_मगा_सालिता,int _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (unsigned long _Val,wchar_t *_DstBuf,size_t Size_In_मगा_सालिता,int _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(size_t *_ReturnSize,wchar_t *_DstBuf,size_t Dst_Size_In_मगा_सालिता,const wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **_Buffer,size_t *Buffer_Size_In_मगा_सालिता,const wchar_t *_VarName);
#if _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,size_t Size_In_मगा_सालिता,int _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(unsigned __int64 _Val,wchar_t *_DstBuf,size_t Size_In_मगा_सालिता,int _Radix);
#endif
#endif

#ifndef _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(char *_DstBuf,size_t _Size,double _Val,int नुमेरो_Of_Dights,int *_PtDec,int *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(char *_DstBuf,size_t _Size,double _Val,int नुमेरो_Of_Dec,int *_PtDec,int *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(char *_DstBuf,size_t _Size,double _Val,int नुमेरो_Of_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(char *_PathResult,size_t _Size,const char *_Drive,const char *_Dir,const char *_Filename,const char *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(const char *_Name,const char *हालागा_2);
  _CRTIMP errno_t __cdecl _searchenv_s(const char *_Filename,const char *_EnvVar,char *_ResultPath,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _splitpath_s(const char *_FullPath,char *_Drive,size_t _DriveSize,char *_Dir,size_t _DirSize,char *_Filename,size_t _FilenameSize,char *_Ext,size_t _ExtSize);

#ifndef _WSTDLIBP_S_DEFINED
#define _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_PathResult,size_t Size_In_मगा_सालिता,const wchar_t *_Drive,const wchar_t *_Dir,const wchar_t *_Filename,const wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(const wchar_t *_Name,const wchar_t *हालागा_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(const wchar_t *_Filename,const wchar_t *_EnvVar,wchar_t *_ResultPath,size_t Size_In_मगा_सालिता);
  _CRTIMP errno_t __cdecl _wsplitpath_s(const wchar_t *_FullPath,wchar_t *_Drive,size_t Drive_Size_In_मगा_सालिता,wchar_t *_Dir,size_t Dir_Size_In_मगा_सालिता,wchar_t *_Filename,size_t Filename_Size_In_मगा_सालिता,wchar_t *_Ext,size_t Ext_Size_In_मगा_सालिता);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
