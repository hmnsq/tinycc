/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB_S
#define _INC_STDLIB_S

#અન્તર્ભાવ <stdlib.h>

#જો defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
બાહ્ય "C" {
#endif

  _CRTIMP errno_t __cdecl _dupenv_s(અક્ષર **_PBuffer,size_t *_PBufferSizeInBytes,અચલ અક્ષર *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(પૂર્ણાંક કિંમત_2,અક્ષર *_DstBuf,size_t _Size,પૂર્ણાંક _Radix);
#જો _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,અક્ષર *_DstBuf,size_t _Size,પૂર્ણાંક _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(unsigned __int64 _Val,અક્ષર *_DstBuf,size_t _Size,પૂર્ણાંક _Radix);
#endif
  _CRTIMP errno_t __cdecl _ltoa_s(long _Val,અક્ષર *_DstBuf,size_t _Size,પૂર્ણાંક _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(size_t *Pt_અંક_Of_Char_Converted,wchar_t *_DstBuf,size_t Size_In_શબ્દો,અચલ અક્ષર *_SrcBuf,size_t Max_ગણતરી);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(size_t *Pt_અંક_Of_Char_Converted,wchar_t *_DstBuf,size_t Size_In_શબ્દો,અચલ અક્ષર *_SrcBuf,size_t Max_ગણતરી,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(unsigned long _Val,અક્ષર *_DstBuf,size_t _Size,પૂર્ણાંક _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(પૂર્ણાંક *_SizeConverted,અક્ષર *_MbCh,size_t _SizeInBytes,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(size_t *Pt_અંક_Of_Char_Converted,અક્ષર *_Dst,size_t _DstSizeInBytes,અચલ wchar_t *_Src,size_t Max_ગણતરી_In_Bytes);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(size_t *Pt_અંક_Of_Char_Converted,અક્ષર *_Dst,size_t _DstSizeInBytes,અચલ wchar_t *_Src,size_t Max_ગણતરી_In_Bytes,_locale_t _Locale);

#ifndef _WSTDLIB_S_DEFINED
#define _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (પૂર્ણાંક _Val,wchar_t *_DstBuf,size_t Size_In_શબ્દો,પૂર્ણાંક _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (long _Val,wchar_t *_DstBuf,size_t Size_In_શબ્દો,પૂર્ણાંક _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (unsigned long _Val,wchar_t *_DstBuf,size_t Size_In_શબ્દો,પૂર્ણાંક _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(size_t *_ReturnSize,wchar_t *_DstBuf,size_t Dst_Size_In_શબ્દો,અચલ wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **_Buffer,size_t *Buffer_Size_In_શબ્દો,અચલ wchar_t *_VarName);
#જો _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,size_t Size_In_શબ્દો,પૂર્ણાંક _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(unsigned __int64 _Val,wchar_t *_DstBuf,size_t Size_In_શબ્દો,પૂર્ણાંક _Radix);
#endif
#endif

#ifndef _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(અક્ષર *_DstBuf,size_t _Size,દ્વિગુણ _Val,પૂર્ણાંક અંક_Of_Dights,પૂર્ણાંક *_PtDec,પૂર્ણાંક *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(અક્ષર *_DstBuf,size_t _Size,દ્વિગુણ _Val,પૂર્ણાંક અંક_Of_Dec,પૂર્ણાંક *_PtDec,પૂર્ણાંક *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(અક્ષર *_DstBuf,size_t _Size,દ્વિગુણ _Val,પૂર્ણાંક અંક_Of_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(અક્ષર *_PathResult,size_t _Size,અચલ અક્ષર *_Drive,અચલ અક્ષર *_Dir,અચલ અક્ષર *_Filename,અચલ અક્ષર *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(અચલ અક્ષર *_Name,અચલ અક્ષર *કિંમત_2);
  _CRTIMP errno_t __cdecl _searchenv_s(અચલ અક્ષર *_Filename,અચલ અક્ષર *_EnvVar,અક્ષર *_ResultPath,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _splitpath_s(અચલ અક્ષર *_FullPath,અક્ષર *_Drive,size_t _DriveSize,અક્ષર *_Dir,size_t _DirSize,અક્ષર *_Filename,size_t _FilenameSize,અક્ષર *_Ext,size_t _ExtSize);

#ifndef _WSTDLIBP_S_DEFINED
#define _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_PathResult,size_t Size_In_શબ્દો,અચલ wchar_t *_Drive,અચલ wchar_t *_Dir,અચલ wchar_t *_Filename,અચલ wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(અચલ wchar_t *_Name,અચલ wchar_t *કિંમત_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(અચલ wchar_t *_Filename,અચલ wchar_t *_EnvVar,wchar_t *_ResultPath,size_t Size_In_શબ્દો);
  _CRTIMP errno_t __cdecl _wsplitpath_s(અચલ wchar_t *_FullPath,wchar_t *_Drive,size_t Drive_Size_In_શબ્દો,wchar_t *_Dir,size_t Dir_Size_In_શબ્દો,wchar_t *_Filename,size_t Filename_Size_In_શબ્દો,wchar_t *_Ext,size_t Ext_Size_In_શબ્દો);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
