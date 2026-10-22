/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_WCHAR_S
#घोषणा _INC_WCHAR_S

#समावेश <wchar.h>

#अगर defined(MINGW_HAS_SECURE_API)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित _WIO_S_DEFINED
#घोषणा _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(स्थिर ब_अक्षर_प्रकार *_Filename,पूर्णांक _AccessMode);
  _CRTIMP errno_t __cdecl _wmktemp_s(ब_अक्षर_प्रकार *_TemplateName,माप_प्रकार आकार_In_शब्दगण);
#पूर्ण_अगर

#अगर_अघोषित _WCONIO_S_DEFINED
#घोषणा _WCONIO_S_DEFINED
  _CRTIMP errno_t __cdecl _cgetws_s(ब_अक्षर_प्रकार *बफर_2,माप_प्रकार आकार_In_शब्दगण,माप_प्रकार *आकार_Read);
  _CRTIMP पूर्णांक __cdecl _cwprintf_s(स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _cwscanf_s(स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _cwscanf_s_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vcwprintf_s(स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _cwprintf_s_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vcwprintf_s_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
#पूर्ण_अगर

#अगर_अघोषित _WSTDIO_S_DEFINED
#घोषणा _WSTDIO_S_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _getws_s(ब_अक्षर_प्रकार *_Str,माप_प्रकार आकार_In_शब्दगण);
  पूर्णांक __cdecl fwprintf_s(खाता *_File,स्थिर ब_अक्षर_प्रकार *_Format,...);
  पूर्णांक __cdecl wprintf_s(स्थिर ब_अक्षर_प्रकार *_Format,...);
  पूर्णांक __cdecl vfwprintf_s(खाता *_File,स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  पूर्णांक __cdecl vwprintf_s(स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  पूर्णांक __cdecl swprintf_s(ब_अक्षर_प्रकार *_Dst,माप_प्रकार आकार_In_शब्दगण,स्थिर ब_अक्षर_प्रकार *_Format,...);
  पूर्णांक __cdecl vswprintf_s(ब_अक्षर_प्रकार *_Dst,माप_प्रकार आकार_In_शब्दगण,स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _snwprintf_s(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Dst_आकार_In_शब्दगण,माप_प्रकार Max_गिनती,स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vsnwprintf_s(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Dst_आकार_In_शब्दगण,माप_प्रकार Max_गिनती,स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _wprintf_s_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vwprintf_s_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _fwprintf_s_l(खाता *_File,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vfwprintf_s_l(खाता *_File,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _swprintf_s_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Dst_आकार,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vswprintf_s_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Dst_आकार,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _snwprintf_s_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Dst_आकार,माप_प्रकार Max_गिनती,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vsnwprintf_s_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Dst_आकार,माप_प्रकार Max_गिनती,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _fwscanf_s_l(खाता *_File,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _swscanf_s_l(स्थिर ब_अक्षर_प्रकार *_Src,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _snwscanf_s(स्थिर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती,स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _snwscanf_s_l(स्थिर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _wscanf_s_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(खाता **_File,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_Mode);
  _CRTIMP errno_t __cdecl _wfreopen_s(खाता **_File,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_Mode,खाता *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार आकार_In_शब्दगण);
#पूर्ण_अगर

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
#अगर_अघोषित _WSTDLIBP_S_DEFINED
#घोषणा _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(ब_अक्षर_प्रकार *Path_परिणाम,माप_प्रकार आकार_In_शब्दगण,स्थिर ब_अक्षर_प्रकार *_Drive,स्थिर ब_अक्षर_प्रकार *_Dir,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(स्थिर ब_अक्षर_प्रकार *_Name,स्थिर ब_अक्षर_प्रकार *मूल्य_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_EnvVar,ब_अक्षर_प्रकार *परिणाम_Path,माप_प्रकार आकार_In_शब्दगण);
  _CRTIMP errno_t __cdecl _wsplitpath_s(स्थिर ब_अक्षर_प्रकार *_FullPath,ब_अक्षर_प्रकार *_Drive,माप_प्रकार Drive_आकार_In_शब्दगण,ब_अक्षर_प्रकार *_Dir,माप_प्रकार Dir_आकार_In_शब्दगण,ब_अक्षर_प्रकार *_Filename,माप_प्रकार Filename_आकार_In_शब्दगण,ब_अक्षर_प्रकार *_Ext,माप_प्रकार Ext_आकार_In_शब्दगण);
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _WSTRING_S_DEFINED
#घोषणा _WSTRING_S_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl wcstok_s(ब_अक्षर_प्रकार *_Str,स्थिर ब_अक्षर_प्रकार *_Delim,ब_अक्षर_प्रकार **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार आकार_In_शब्दगण,पूर्णांक Err_अंक);
  _CRTIMP errno_t __cdecl __wcserror_s(ब_अक्षर_प्रकार *बफर_2,माप_प्रकार आकार_In_शब्दगण,स्थिर ब_अक्षर_प्रकार *Err_संदेश);
  _CRTIMP errno_t __cdecl _wcsnset_s(ब_अक्षर_प्रकार *_Dst,माप_प्रकार Dst_आकार_In_शब्दगण,ब_अक्षर_प्रकार _Val,माप_प्रकार Max_गिनती);
  _CRTIMP errno_t __cdecl _wcsset_s(ब_अक्षर_प्रकार *_Str,माप_प्रकार आकार_In_शब्दगण,ब_अक्षर_प्रकार _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(ब_अक्षर_प्रकार *_Str,माप_प्रकार आकार_In_शब्दगण);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(ब_अक्षर_प्रकार *_Str,माप_प्रकार आकार_In_शब्दगण,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(ब_अक्षर_प्रकार *_Str,माप_प्रकार आकार_4);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(ब_अक्षर_प्रकार *_Str,माप_प्रकार आकार_4,_locale_t _Locale);
#पूर्ण_अगर

#अगर_अघोषित _WTIME_S_DEFINED
#घोषणा _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार आकार_In_शब्दगण,स्थिर काष्ठा पंचांग *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार आकार_In_शब्दगण,स्थिर __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wstrdate_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार आकार_In_शब्दगण);
  _CRTIMP errno_t __cdecl _wstrtime_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार आकार_In_शब्दगण);
#अगर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार आकार_In_शब्दगण,स्थिर __time64_t *_Time);
#पूर्ण_अगर

#अगर !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#घोषणा _INC_WTIME_S_INL
#अगर_घोषित _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(ब_अक्षर_प्रकार *बफर_2,माप_प्रकार आकार_In_शब्दगण,स्थिर समय_प्रकार *_Time) { वापस _wctime32_s(बफर_2,आकार_In_शब्दगण,_Time); }
#अन्यथा
__CRT_INLINE errno_t __cdecl _wctime_s(ब_अक्षर_प्रकार *बफर_2,माप_प्रकार आकार_In_शब्दगण,स्थिर समय_प्रकार *_Time) { वापस _wctime64_s(बफर_2,आकार_In_शब्दगण,_Time); }
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

  _CRTIMP errno_t __cdecl mbsrtowcs_s(माप_प्रकार *_Retval,ब_अक्षर_प्रकार *_Dst,माप_प्रकार आकार_In_शब्दगण,स्थिर अक्षर **_PSrc,माप_प्रकार _N,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcrtomb_s(माप_प्रकार *_Retval,अक्षर *_Dst,माप_प्रकार आकार_In_Bytes,ब_अक्षर_प्रकार _Ch,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcsrtombs_s(माप_प्रकार *_Retval,अक्षर *_Dst,माप_प्रकार आकार_In_Bytes,स्थिर ब_अक्षर_प्रकार **_Src,माप_प्रकार आकार_4,mbstate_t *_State);

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#पूर्ण_अगर
#पूर्ण_अगर
