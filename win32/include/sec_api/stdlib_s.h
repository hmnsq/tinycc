/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB_S
#define _INC_STDLIB_S

#அந்தர்பாவ <stdlib.h>

#எனில் defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
வெளி "C" {
#endif

  _CRTIMP errno_t __cdecl _dupenv_s(எழுத்து **_PBuffer,size_t *_PBufferSizeInBytes,மாறிலி எழுத்து *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(முழு மதிப்பு_2,எழுத்து *_DstBuf,size_t _Size,முழு _Radix);
#எனில் _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,எழுத்து *_DstBuf,size_t _Size,முழு _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(unsigned __int64 _Val,எழுத்து *_DstBuf,size_t _Size,முழு _Radix);
#endif
  _CRTIMP errno_t __cdecl _ltoa_s(long _Val,எழுத்து *_DstBuf,size_t _Size,முழு _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(size_t *Pt_இலக்கம்_Of_Char_Converted,wchar_t *_DstBuf,size_t Size_In_சொற்கள்,மாறிலி எழுத்து *_SrcBuf,size_t Max_மொத்தம்);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(size_t *Pt_இலக்கம்_Of_Char_Converted,wchar_t *_DstBuf,size_t Size_In_சொற்கள்,மாறிலி எழுத்து *_SrcBuf,size_t Max_மொத்தம்,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(unsigned long _Val,எழுத்து *_DstBuf,size_t _Size,முழு _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(முழு *_SizeConverted,எழுத்து *_MbCh,size_t _SizeInBytes,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(size_t *Pt_இலக்கம்_Of_Char_Converted,எழுத்து *_Dst,size_t _DstSizeInBytes,மாறிலி wchar_t *_Src,size_t Max_மொத்தம்_In_Bytes);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(size_t *Pt_இலக்கம்_Of_Char_Converted,எழுத்து *_Dst,size_t _DstSizeInBytes,மாறிலி wchar_t *_Src,size_t Max_மொத்தம்_In_Bytes,_locale_t _Locale);

#ifndef _WSTDLIB_S_DEFINED
#define _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (முழு _Val,wchar_t *_DstBuf,size_t Size_In_சொற்கள்,முழு _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (long _Val,wchar_t *_DstBuf,size_t Size_In_சொற்கள்,முழு _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (unsigned long _Val,wchar_t *_DstBuf,size_t Size_In_சொற்கள்,முழு _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(size_t *_ReturnSize,wchar_t *_DstBuf,size_t Dst_Size_In_சொற்கள்,மாறிலி wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **_Buffer,size_t *Buffer_Size_In_சொற்கள்,மாறிலி wchar_t *_VarName);
#எனில் _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,size_t Size_In_சொற்கள்,முழு _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(unsigned __int64 _Val,wchar_t *_DstBuf,size_t Size_In_சொற்கள்,முழு _Radix);
#endif
#endif

#ifndef _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(எழுத்து *_DstBuf,size_t _Size,இரட்டை _Val,முழு இலக்கம்_Of_Dights,முழு *_PtDec,முழு *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(எழுத்து *_DstBuf,size_t _Size,இரட்டை _Val,முழு இலக்கம்_Of_Dec,முழு *_PtDec,முழு *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(எழுத்து *_DstBuf,size_t _Size,இரட்டை _Val,முழு இலக்கம்_Of_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(எழுத்து *_PathResult,size_t _Size,மாறிலி எழுத்து *_Drive,மாறிலி எழுத்து *_Dir,மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(மாறிலி எழுத்து *_Name,மாறிலி எழுத்து *மதிப்பு_2);
  _CRTIMP errno_t __cdecl _searchenv_s(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_EnvVar,எழுத்து *_ResultPath,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _splitpath_s(மாறிலி எழுத்து *_FullPath,எழுத்து *_Drive,size_t _DriveSize,எழுத்து *_Dir,size_t _DirSize,எழுத்து *_Filename,size_t _FilenameSize,எழுத்து *_Ext,size_t _ExtSize);

#ifndef _WSTDLIBP_S_DEFINED
#define _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_PathResult,size_t Size_In_சொற்கள்,மாறிலி wchar_t *_Drive,மாறிலி wchar_t *_Dir,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(மாறிலி wchar_t *_Name,மாறிலி wchar_t *மதிப்பு_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_EnvVar,wchar_t *_ResultPath,size_t Size_In_சொற்கள்);
  _CRTIMP errno_t __cdecl _wsplitpath_s(மாறிலி wchar_t *_FullPath,wchar_t *_Drive,size_t Drive_Size_In_சொற்கள்,wchar_t *_Dir,size_t Dir_Size_In_சொற்கள்,wchar_t *_Filename,size_t Filename_Size_In_சொற்கள்,wchar_t *_Ext,size_t Ext_Size_In_சொற்கள்);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
