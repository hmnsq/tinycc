/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB_S
#define _INC_STDLIB_S

#ಅನ್ತರ್ಭಾವ <stdlib.h>

#ಯದಿ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

  _CRTIMP errno_t __cdecl _dupenv_s(ವರ್ಣ **_PBuffer,size_t *_PBufferSizeInBytes,ಧ್ರುವ ವರ್ಣ *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ_2,ವರ್ಣ *_DstBuf,size_t _Size,ಪೂರ್ಣಾಙ್ಕ _Radix);
#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,ವರ್ಣ *_DstBuf,size_t _Size,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(unsigned __int64 _Val,ವರ್ಣ *_DstBuf,size_t _Size,ಪೂರ್ಣಾಙ್ಕ _Radix);
#endif
  _CRTIMP errno_t __cdecl _ltoa_s(long _Val,ವರ್ಣ *_DstBuf,size_t _Size,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(size_t *Pt_ಅಂಕೆ_Of_Char_Converted,wchar_t *_DstBuf,size_t Size_In_ಪದಗಳು,ಧ್ರುವ ವರ್ಣ *_SrcBuf,size_t Max_ಎಣಿಕೆ);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(size_t *Pt_ಅಂಕೆ_Of_Char_Converted,wchar_t *_DstBuf,size_t Size_In_ಪದಗಳು,ಧ್ರುವ ವರ್ಣ *_SrcBuf,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(unsigned long _Val,ವರ್ಣ *_DstBuf,size_t _Size,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(ಪೂರ್ಣಾಙ್ಕ *_SizeConverted,ವರ್ಣ *_MbCh,size_t _SizeInBytes,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(size_t *Pt_ಅಂಕೆ_Of_Char_Converted,ವರ್ಣ *_Dst,size_t _DstSizeInBytes,ಧ್ರುವ wchar_t *_Src,size_t Max_ಎಣಿಕೆ_In_Bytes);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(size_t *Pt_ಅಂಕೆ_Of_Char_Converted,ವರ್ಣ *_Dst,size_t _DstSizeInBytes,ಧ್ರುವ wchar_t *_Src,size_t Max_ಎಣಿಕೆ_In_Bytes,_locale_t _Locale);

#ifndef _WSTDLIB_S_DEFINED
#define _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (ಪೂರ್ಣಾಙ್ಕ _Val,wchar_t *_DstBuf,size_t Size_In_ಪದಗಳು,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (long _Val,wchar_t *_DstBuf,size_t Size_In_ಪದಗಳು,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (unsigned long _Val,wchar_t *_DstBuf,size_t Size_In_ಪದಗಳು,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(size_t *_ReturnSize,wchar_t *_DstBuf,size_t Dst_Size_In_ಪದಗಳು,ಧ್ರುವ wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **_Buffer,size_t *Buffer_Size_In_ಪದಗಳು,ಧ್ರುವ wchar_t *_VarName);
#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,size_t Size_In_ಪದಗಳು,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(unsigned __int64 _Val,wchar_t *_DstBuf,size_t Size_In_ಪದಗಳು,ಪೂರ್ಣಾಙ್ಕ _Radix);
#endif
#endif

#ifndef _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(ವರ್ಣ *_DstBuf,size_t _Size,ದ್ವಿಗುಣ _Val,ಪೂರ್ಣಾಙ್ಕ ಅಂಕೆ_Of_Dights,ಪೂರ್ಣಾಙ್ಕ *_PtDec,ಪೂರ್ಣಾಙ್ಕ *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(ವರ್ಣ *_DstBuf,size_t _Size,ದ್ವಿಗುಣ _Val,ಪೂರ್ಣಾಙ್ಕ ಅಂಕೆ_Of_Dec,ಪೂರ್ಣಾಙ್ಕ *_PtDec,ಪೂರ್ಣಾಙ್ಕ *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(ವರ್ಣ *_DstBuf,size_t _Size,ದ್ವಿಗುಣ _Val,ಪೂರ್ಣಾಙ್ಕ ಅಂಕೆ_Of_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(ವರ್ಣ *_PathResult,size_t _Size,ಧ್ರುವ ವರ್ಣ *_Drive,ಧ್ರುವ ವರ್ಣ *_Dir,ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(ಧ್ರುವ ವರ್ಣ *_Name,ಧ್ರುವ ವರ್ಣ *ಮೌಲ್ಯ_2);
  _CRTIMP errno_t __cdecl _searchenv_s(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_EnvVar,ವರ್ಣ *_ResultPath,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _splitpath_s(ಧ್ರುವ ವರ್ಣ *_FullPath,ವರ್ಣ *_Drive,size_t _DriveSize,ವರ್ಣ *_Dir,size_t _DirSize,ವರ್ಣ *_Filename,size_t _FilenameSize,ವರ್ಣ *_Ext,size_t _ExtSize);

#ifndef _WSTDLIBP_S_DEFINED
#define _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_PathResult,size_t Size_In_ಪದಗಳು,ಧ್ರುವ wchar_t *_Drive,ಧ್ರುವ wchar_t *_Dir,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ಧ್ರುವ wchar_t *_Name,ಧ್ರುವ wchar_t *ಮೌಲ್ಯ_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_EnvVar,wchar_t *_ResultPath,size_t Size_In_ಪದಗಳು);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ಧ್ರುವ wchar_t *_FullPath,wchar_t *_Drive,size_t Drive_Size_In_ಪದಗಳು,wchar_t *_Dir,size_t Dir_Size_In_ಪದಗಳು,wchar_t *_Filename,size_t Filename_Size_In_ಪದಗಳು,wchar_t *_Ext,size_t Ext_Size_In_ಪದಗಳು);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
