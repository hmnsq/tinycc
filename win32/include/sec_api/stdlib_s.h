/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_STDLIB_S
#घोषणा _INC_STDLIB_S

#समावेश <stdlib.h>

#अगर defined(MINGW_HAS_SECURE_API)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

  _CRTIMP errno_t __cdecl _dupenv_s(अक्षर **_PBuffer,माप_प्रकार *PBuffer_आकार_In_Bytes,स्थिर अक्षर *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(पूर्णांक मूल्य_2,अक्षर *_DstBuf,माप_प्रकार आकार_4,पूर्णांक _Radix);
#अगर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,अक्षर *_DstBuf,माप_प्रकार आकार_4,पूर्णांक _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(अचिन्हित __int64 _Val,अक्षर *_DstBuf,माप_प्रकार आकार_4,पूर्णांक _Radix);
#पूर्ण_अगर
  _CRTIMP errno_t __cdecl _ltoa_s(दीर्घ _Val,अक्षर *_DstBuf,माप_प्रकार आकार_4,पूर्णांक _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(माप_प्रकार *Pt_अंक_Of_Char_Converted,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार आकार_In_शब्दगण,स्थिर अक्षर *_SrcBuf,माप_प्रकार Max_गिनती);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(माप_प्रकार *Pt_अंक_Of_Char_Converted,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार आकार_In_शब्दगण,स्थिर अक्षर *_SrcBuf,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(अचिन्हित दीर्घ _Val,अक्षर *_DstBuf,माप_प्रकार आकार_4,पूर्णांक _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(पूर्णांक *आकार_Converted,अक्षर *_MbCh,माप_प्रकार आकार_In_Bytes,ब_अक्षर_प्रकार _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(माप_प्रकार *Pt_अंक_Of_Char_Converted,अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,स्थिर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती_In_Bytes);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(माप_प्रकार *Pt_अंक_Of_Char_Converted,अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,स्थिर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती_In_Bytes,_locale_t _Locale);

#अगर_अघोषित _WSTDLIB_S_DEFINED
#घोषणा _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (पूर्णांक _Val,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार आकार_In_शब्दगण,पूर्णांक _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (दीर्घ _Val,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार आकार_In_शब्दगण,पूर्णांक _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (अचिन्हित दीर्घ _Val,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार आकार_In_शब्दगण,पूर्णांक _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(माप_प्रकार *Return_आकार,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Dst_आकार_In_शब्दगण,स्थिर ब_अक्षर_प्रकार *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(ब_अक्षर_प्रकार **बफर_2,माप_प्रकार *बफर_आकार_In_शब्दगण,स्थिर ब_अक्षर_प्रकार *_VarName);
#अगर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार आकार_In_शब्दगण,पूर्णांक _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(अचिन्हित __int64 _Val,ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार आकार_In_शब्दगण,पूर्णांक _Radix);
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(अक्षर *_DstBuf,माप_प्रकार आकार_4,द्विगुन _Val,पूर्णांक अंक_Of_Dights,पूर्णांक *_PtDec,पूर्णांक *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(अक्षर *_DstBuf,माप_प्रकार आकार_4,द्विगुन _Val,पूर्णांक अंक_Of_Dec,पूर्णांक *_PtDec,पूर्णांक *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(अक्षर *_DstBuf,माप_प्रकार आकार_4,द्विगुन _Val,पूर्णांक अंक_Of_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(अक्षर *Path_परिणाम,माप_प्रकार आकार_4,स्थिर अक्षर *_Drive,स्थिर अक्षर *_Dir,स्थिर अक्षर *_Filename,स्थिर अक्षर *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(स्थिर अक्षर *_Name,स्थिर अक्षर *मूल्य_2);
  _CRTIMP errno_t __cdecl _searchenv_s(स्थिर अक्षर *_Filename,स्थिर अक्षर *_EnvVar,अक्षर *परिणाम_Path,माप_प्रकार आकार_In_Bytes);
  _CRTIMP errno_t __cdecl _splitpath_s(स्थिर अक्षर *_FullPath,अक्षर *_Drive,माप_प्रकार Drive_आकार,अक्षर *_Dir,माप_प्रकार Dir_आकार,अक्षर *_Filename,माप_प्रकार Filename_आकार,अक्षर *_Ext,माप_प्रकार Ext_आकार);

#अगर_अघोषित _WSTDLIBP_S_DEFINED
#घोषणा _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(ब_अक्षर_प्रकार *Path_परिणाम,माप_प्रकार आकार_In_शब्दगण,स्थिर ब_अक्षर_प्रकार *_Drive,स्थिर ब_अक्षर_प्रकार *_Dir,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(स्थिर ब_अक्षर_प्रकार *_Name,स्थिर ब_अक्षर_प्रकार *मूल्य_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_EnvVar,ब_अक्षर_प्रकार *परिणाम_Path,माप_प्रकार आकार_In_शब्दगण);
  _CRTIMP errno_t __cdecl _wsplitpath_s(स्थिर ब_अक्षर_प्रकार *_FullPath,ब_अक्षर_प्रकार *_Drive,माप_प्रकार Drive_आकार_In_शब्दगण,ब_अक्षर_प्रकार *_Dir,माप_प्रकार Dir_आकार_In_शब्दगण,ब_अक्षर_प्रकार *_Filename,माप_प्रकार Filename_आकार_In_शब्दगण,ब_अक्षर_प्रकार *_Ext,माप_प्रकार Ext_आकार_In_शब्दगण);
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#पूर्ण_अगर
#पूर्ण_अगर
