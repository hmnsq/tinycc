/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB_S
#define _INC_STDLIB_S

#अन्तर्भाव <stdlib.h>

#यदि defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
बाह्य "C" {
#endif

  _CRTIMP errno_t __cdecl _dupenv_s(वर्ण **_PBuffer,size_t *_PBufferSizeInBytes,ध्रुव वर्ण *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(पूर्णाङ्क मूल्य_2,वर्ण *_DstBuf,size_t _Size,पूर्णाङ्क _Radix);
#यदि _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,वर्ण *_DstBuf,size_t _Size,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(unsigned __int64 _Val,वर्ण *_DstBuf,size_t _Size,पूर्णाङ्क _Radix);
#endif
  _CRTIMP errno_t __cdecl _ltoa_s(long _Val,वर्ण *_DstBuf,size_t _Size,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(size_t *Pt_अंक_Of_Char_Converted,wchar_t *_DstBuf,size_t Size_In_शब्द,ध्रुव वर्ण *_SrcBuf,size_t Max_मोजणी);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(size_t *Pt_अंक_Of_Char_Converted,wchar_t *_DstBuf,size_t Size_In_शब्द,ध्रुव वर्ण *_SrcBuf,size_t Max_मोजणी,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(unsigned long _Val,वर्ण *_DstBuf,size_t _Size,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(पूर्णाङ्क *_SizeConverted,वर्ण *_MbCh,size_t _SizeInBytes,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(size_t *Pt_अंक_Of_Char_Converted,वर्ण *_Dst,size_t _DstSizeInBytes,ध्रुव wchar_t *_Src,size_t Max_मोजणी_In_Bytes);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(size_t *Pt_अंक_Of_Char_Converted,वर्ण *_Dst,size_t _DstSizeInBytes,ध्रुव wchar_t *_Src,size_t Max_मोजणी_In_Bytes,_locale_t _Locale);

#ifndef _WSTDLIB_S_DEFINED
#define _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (पूर्णाङ्क _Val,wchar_t *_DstBuf,size_t Size_In_शब्द,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (long _Val,wchar_t *_DstBuf,size_t Size_In_शब्द,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (unsigned long _Val,wchar_t *_DstBuf,size_t Size_In_शब्द,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(size_t *_ReturnSize,wchar_t *_DstBuf,size_t Dst_Size_In_शब्द,ध्रुव wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **_Buffer,size_t *Buffer_Size_In_शब्द,ध्रुव wchar_t *_VarName);
#यदि _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,size_t Size_In_शब्द,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(unsigned __int64 _Val,wchar_t *_DstBuf,size_t Size_In_शब्द,पूर्णाङ्क _Radix);
#endif
#endif

#ifndef _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(वर्ण *_DstBuf,size_t _Size,द्विगुण _Val,पूर्णाङ्क अंक_Of_Dights,पूर्णाङ्क *_PtDec,पूर्णाङ्क *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(वर्ण *_DstBuf,size_t _Size,द्विगुण _Val,पूर्णाङ्क अंक_Of_Dec,पूर्णाङ्क *_PtDec,पूर्णाङ्क *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(वर्ण *_DstBuf,size_t _Size,द्विगुण _Val,पूर्णाङ्क अंक_Of_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(वर्ण *_PathResult,size_t _Size,ध्रुव वर्ण *_Drive,ध्रुव वर्ण *_Dir,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(ध्रुव वर्ण *_Name,ध्रुव वर्ण *मूल्य_2);
  _CRTIMP errno_t __cdecl _searchenv_s(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_EnvVar,वर्ण *_ResultPath,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _splitpath_s(ध्रुव वर्ण *_FullPath,वर्ण *_Drive,size_t _DriveSize,वर्ण *_Dir,size_t _DirSize,वर्ण *_Filename,size_t _FilenameSize,वर्ण *_Ext,size_t _ExtSize);

#ifndef _WSTDLIBP_S_DEFINED
#define _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_PathResult,size_t Size_In_शब्द,ध्रुव wchar_t *_Drive,ध्रुव wchar_t *_Dir,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ध्रुव wchar_t *_Name,ध्रुव wchar_t *मूल्य_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_EnvVar,wchar_t *_ResultPath,size_t Size_In_शब्द);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ध्रुव wchar_t *_FullPath,wchar_t *_Drive,size_t Drive_Size_In_शब्द,wchar_t *_Dir,size_t Dir_Size_In_शब्द,wchar_t *_Filename,size_t Filename_Size_In_शब्द,wchar_t *_Ext,size_t Ext_Size_In_शब्द);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
