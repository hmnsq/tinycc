/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB_S
#define _INC_STDLIB_S

#अन्तर्भाव <stdlib.h>

#जर defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
बाह्य "C" {
#endif

  _CRTIMP errno_t __cdecl _dupenv_s(अक्षर **_PBuffer,माप_प्रकार *_PBufferSizeInBytes,स्थिरांक अक्षर *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(पूर्णांक मूल्य_2,अक्षर *_DstBuf,माप_प्रकार _Size,पूर्णांक _Radix);
#जर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,अक्षर *_DstBuf,माप_प्रकार _Size,पूर्णांक _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(अचिन्हित __int64 _Val,अक्षर *_DstBuf,माप_प्रकार _Size,पूर्णांक _Radix);
#endif
  _CRTIMP errno_t __cdecl _ltoa_s(दीर्घ _Val,अक्षर *_DstBuf,माप_प्रकार _Size,पूर्णांक _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(माप_प्रकार *Pt_अंक_Of_Char_Converted,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्द,स्थिरांक अक्षर *_SrcBuf,माप_प्रकार Max_मोजणी);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(माप_प्रकार *Pt_अंक_Of_Char_Converted,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्द,स्थिरांक अक्षर *_SrcBuf,माप_प्रकार Max_मोजणी,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(अचिन्हित दीर्घ _Val,अक्षर *_DstBuf,माप_प्रकार _Size,पूर्णांक _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(पूर्णांक *_SizeConverted,अक्षर *_MbCh,माप_प्रकार _SizeInBytes,ब_अक्षर_प्रकार _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(माप_प्रकार *Pt_अंक_Of_Char_Converted,अक्षर *_Dst,माप_प्रकार _DstSizeInBytes,स्थिरांक ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_मोजणी_In_Bytes);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(माप_प्रकार *Pt_अंक_Of_Char_Converted,अक्षर *_Dst,माप_प्रकार _DstSizeInBytes,स्थिरांक ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_मोजणी_In_Bytes,_locale_t _Locale);

#ifndef _WSTDLIB_S_DEFINED
#define _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (पूर्णांक _Val,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्द,पूर्णांक _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (दीर्घ _Val,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्द,पूर्णांक _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (अचिन्हित दीर्घ _Val,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्द,पूर्णांक _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(माप_प्रकार *_ReturnSize,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Dst_Size_In_शब्द,स्थिरांक ब_अक्षर_प्रकार *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(ब_अक्षर_प्रकार **_Buffer,माप_प्रकार *Buffer_Size_In_शब्द,स्थिरांक ब_अक्षर_प्रकार *_VarName);
#जर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्द,पूर्णांक _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(अचिन्हित __int64 _Val,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्द,पूर्णांक _Radix);
#endif
#endif

#ifndef _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(अक्षर *_DstBuf,माप_प्रकार _Size,द्विगुण _Val,पूर्णांक अंक_Of_Dights,पूर्णांक *_PtDec,पूर्णांक *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(अक्षर *_DstBuf,माप_प्रकार _Size,द्विगुण _Val,पूर्णांक अंक_Of_Dec,पूर्णांक *_PtDec,पूर्णांक *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(अक्षर *_DstBuf,माप_प्रकार _Size,द्विगुण _Val,पूर्णांक अंक_Of_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(अक्षर *_PathResult,माप_प्रकार _Size,स्थिरांक अक्षर *_Drive,स्थिरांक अक्षर *_Dir,स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(स्थिरांक अक्षर *_Name,स्थिरांक अक्षर *मूल्य_2);
  _CRTIMP errno_t __cdecl _searchenv_s(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_EnvVar,अक्षर *_ResultPath,माप_प्रकार _SizeInBytes);
  _CRTIMP errno_t __cdecl _splitpath_s(स्थिरांक अक्षर *_FullPath,अक्षर *_Drive,माप_प्रकार _DriveSize,अक्षर *_Dir,माप_प्रकार _DirSize,अक्षर *_Filename,माप_प्रकार _FilenameSize,अक्षर *_Ext,माप_प्रकार _ExtSize);

#ifndef _WSTDLIBP_S_DEFINED
#define _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(ब_अक्षर_प्रकार *_PathResult,माप_प्रकार Size_In_शब्द,स्थिरांक ब_अक्षर_प्रकार *_Drive,स्थिरांक ब_अक्षर_प्रकार *_Dir,स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(स्थिरांक ब_अक्षर_प्रकार *_Name,स्थिरांक ब_अक्षर_प्रकार *मूल्य_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *_EnvVar,ब_अक्षर_प्रकार *_ResultPath,माप_प्रकार Size_In_शब्द);
  _CRTIMP errno_t __cdecl _wsplitpath_s(स्थिरांक ब_अक्षर_प्रकार *_FullPath,ब_अक्षर_प्रकार *_Drive,माप_प्रकार Drive_Size_In_शब्द,ब_अक्षर_प्रकार *_Dir,माप_प्रकार Dir_Size_In_शब्द,ब_अक्षर_प्रकार *_Filename,माप_प्रकार Filename_Size_In_शब्द,ब_अक्षर_प्रकार *_Ext,माप_प्रकार Ext_Size_In_शब्द);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
