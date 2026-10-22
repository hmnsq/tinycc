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

  _CRTIMP errno_t __cdecl _dupenv_s(वर्ण **_PBuffer,माप_प्रकार *_PBufferSizeInBytes,ध्रुव वर्ण *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(पूर्णाङ्क मूल्य_2,वर्ण *_DstBuf,माप_प्रकार _Size,पूर्णाङ्क _Radix);
#यदि _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,वर्ण *_DstBuf,माप_प्रकार _Size,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(अचिन्हित __int64 _Val,वर्ण *_DstBuf,माप_प्रकार _Size,पूर्णाङ्क _Radix);
#endif
  _CRTIMP errno_t __cdecl _ltoa_s(दीर्घ _Val,वर्ण *_DstBuf,माप_प्रकार _Size,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(माप_प्रकार *Pt_अंक_Of_Char_Converted,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्दगण,ध्रुव वर्ण *_SrcBuf,माप_प्रकार Max_गिनती);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(माप_प्रकार *Pt_अंक_Of_Char_Converted,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्दगण,ध्रुव वर्ण *_SrcBuf,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(अचिन्हित दीर्घ _Val,वर्ण *_DstBuf,माप_प्रकार _Size,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(पूर्णाङ्क *_SizeConverted,वर्ण *_MbCh,माप_प्रकार _SizeInBytes,ब_अक्षर_प्रकार _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(माप_प्रकार *Pt_अंक_Of_Char_Converted,वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,ध्रुव ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती_In_Bytes);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(माप_प्रकार *Pt_अंक_Of_Char_Converted,वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,ध्रुव ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती_In_Bytes,_locale_t _Locale);

#ifndef _WSTDLIB_S_DEFINED
#define _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (पूर्णाङ्क _Val,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्दगण,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (दीर्घ _Val,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्दगण,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (अचिन्हित दीर्घ _Val,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्दगण,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(माप_प्रकार *_ReturnSize,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Dst_Size_In_शब्दगण,ध्रुव ब_अक्षर_प्रकार *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(ब_अक्षर_प्रकार **_Buffer,माप_प्रकार *Buffer_Size_In_शब्दगण,ध्रुव ब_अक्षर_प्रकार *_VarName);
#यदि _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्दगण,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(अचिन्हित __int64 _Val,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्दगण,पूर्णाङ्क _Radix);
#endif
#endif

#ifndef _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(वर्ण *_DstBuf,माप_प्रकार _Size,द्विगुण _Val,पूर्णाङ्क अंक_Of_Dights,पूर्णाङ्क *_PtDec,पूर्णाङ्क *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(वर्ण *_DstBuf,माप_प्रकार _Size,द्विगुण _Val,पूर्णाङ्क अंक_Of_Dec,पूर्णाङ्क *_PtDec,पूर्णाङ्क *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(वर्ण *_DstBuf,माप_प्रकार _Size,द्विगुण _Val,पूर्णाङ्क अंक_Of_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(वर्ण *_PathResult,माप_प्रकार _Size,ध्रुव वर्ण *_Drive,ध्रुव वर्ण *_Dir,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(ध्रुव वर्ण *_Name,ध्रुव वर्ण *मूल्य_2);
  _CRTIMP errno_t __cdecl _searchenv_s(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_EnvVar,वर्ण *_ResultPath,माप_प्रकार _SizeInBytes);
  _CRTIMP errno_t __cdecl _splitpath_s(ध्रुव वर्ण *_FullPath,वर्ण *_Drive,माप_प्रकार _DriveSize,वर्ण *_Dir,माप_प्रकार _DirSize,वर्ण *_Filename,माप_प्रकार _FilenameSize,वर्ण *_Ext,माप_प्रकार _ExtSize);

#ifndef _WSTDLIBP_S_DEFINED
#define _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(ब_अक्षर_प्रकार *_PathResult,माप_प्रकार Size_In_शब्दगण,ध्रुव ब_अक्षर_प्रकार *_Drive,ध्रुव ब_अक्षर_प्रकार *_Dir,ध्रुव ब_अक्षर_प्रकार *_Filename,ध्रुव ब_अक्षर_प्रकार *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ध्रुव ब_अक्षर_प्रकार *_Name,ध्रुव ब_अक्षर_प्रकार *मूल्य_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ध्रुव ब_अक्षर_प्रकार *_Filename,ध्रुव ब_अक्षर_प्रकार *_EnvVar,ब_अक्षर_प्रकार *_ResultPath,माप_प्रकार Size_In_शब्दगण);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ध्रुव ब_अक्षर_प्रकार *_FullPath,ब_अक्षर_प्रकार *_Drive,माप_प्रकार Drive_Size_In_शब्दगण,ब_अक्षर_प्रकार *_Dir,माप_प्रकार Dir_Size_In_शब्दगण,ब_अक्षर_प्रकार *_Filename,माप_प्रकार Filename_Size_In_शब्दगण,ब_अक्षर_प्रकार *_Ext,माप_प्रकार Ext_Size_In_शब्दगण);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
