/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_WCHAR_S
#define _INC_WCHAR_S

#अन्तर्भाव <wchar.h>

#यदि defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef _WIO_S_DEFINED
#define _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ध्रुव ब_अक्षर_प्रकार *_Filename,पूर्णाङ्क _AccessMode);
  _CRTIMP errno_t __cdecl _wmktemp_s(ब_अक्षर_प्रकार *_TemplateName,माप_प्रकार Size_In_शब्दगण);
#endif

#ifndef _WCONIO_S_DEFINED
#define _WCONIO_S_DEFINED
  _CRTIMP errno_t __cdecl _cgetws_s(ब_अक्षर_प्रकार *_Buffer,माप_प्रकार Size_In_शब्दगण,माप_प्रकार *_SizeRead);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_s(ध्रुव ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cwscanf_s(ध्रुव ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cwscanf_s_l(ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_s(ध्रुव ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_s_l(ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_s_l(ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
#endif

#ifndef _WSTDIO_S_DEFINED
#define _WSTDIO_S_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _getws_s(ब_अक्षर_प्रकार *_Str,माप_प्रकार Size_In_शब्दगण);
  पूर्णाङ्क __cdecl fwprintf_s(खाता *_File,ध्रुव ब_अक्षर_प्रकार *_Format,...);
  पूर्णाङ्क __cdecl wprintf_s(ध्रुव ब_अक्षर_प्रकार *_Format,...);
  पूर्णाङ्क __cdecl vfwprintf_s(खाता *_File,ध्रुव ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  पूर्णाङ्क __cdecl vwprintf_s(ध्रुव ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  पूर्णाङ्क __cdecl swprintf_s(ब_अक्षर_प्रकार *_Dst,माप_प्रकार Size_In_शब्दगण,ध्रुव ब_अक्षर_प्रकार *_Format,...);
  पूर्णाङ्क __cdecl vswprintf_s(ब_अक्षर_प्रकार *_Dst,माप_प्रकार Size_In_शब्दगण,ध्रुव ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snwprintf_s(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Dst_Size_In_शब्दगण,माप_प्रकार Max_गिनती,ध्रुव ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnwprintf_s(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Dst_Size_In_शब्दगण,माप_प्रकार Max_गिनती,ध्रुव ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _wprintf_s_l(ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vwprintf_s_l(ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fwprintf_s_l(खाता *_File,ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vfwprintf_s_l(खाता *_File,ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_s_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार _DstSize,ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_s_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार _DstSize,ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snwprintf_s_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार Max_गिनती,ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnwprintf_s_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार Max_गिनती,ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fwscanf_s_l(खाता *_File,ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _swscanf_s_l(ध्रुव ब_अक्षर_प्रकार *_Src,ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _snwscanf_s(ध्रुव ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती,ध्रुव ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _snwscanf_s_l(ध्रुव ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती,ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _wscanf_s_l(ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(खाता **_File,ध्रुव ब_अक्षर_प्रकार *_Filename,ध्रुव ब_अक्षर_प्रकार *_Mode);
  _CRTIMP errno_t __cdecl _wfreopen_s(खाता **_File,ध्रुव ब_अक्षर_प्रकार *_Filename,ध्रुव ब_अक्षर_प्रकार *_Mode,खाता *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्दगण);
#endif

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
#ifndef _WSTDLIBP_S_DEFINED
#define _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(ब_अक्षर_प्रकार *_PathResult,माप_प्रकार Size_In_शब्दगण,ध्रुव ब_अक्षर_प्रकार *_Drive,ध्रुव ब_अक्षर_प्रकार *_Dir,ध्रुव ब_अक्षर_प्रकार *_Filename,ध्रुव ब_अक्षर_प्रकार *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ध्रुव ब_अक्षर_प्रकार *_Name,ध्रुव ब_अक्षर_प्रकार *मूल्य_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ध्रुव ब_अक्षर_प्रकार *_Filename,ध्रुव ब_अक्षर_प्रकार *_EnvVar,ब_अक्षर_प्रकार *_ResultPath,माप_प्रकार Size_In_शब्दगण);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ध्रुव ब_अक्षर_प्रकार *_FullPath,ब_अक्षर_प्रकार *_Drive,माप_प्रकार Drive_Size_In_शब्दगण,ब_अक्षर_प्रकार *_Dir,माप_प्रकार Dir_Size_In_शब्दगण,ब_अक्षर_प्रकार *_Filename,माप_प्रकार Filename_Size_In_शब्दगण,ब_अक्षर_प्रकार *_Ext,माप_प्रकार Ext_Size_In_शब्दगण);
#endif
#endif

#ifndef _WSTRING_S_DEFINED
#define _WSTRING_S_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl wcstok_s(ब_अक्षर_प्रकार *_Str,ध्रुव ब_अक्षर_प्रकार *_Delim,ब_अक्षर_प्रकार **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार Size_In_शब्दगण,पूर्णाङ्क Err_अंक);
  _CRTIMP errno_t __cdecl __wcserror_s(ब_अक्षर_प्रकार *_Buffer,माप_प्रकार Size_In_शब्दगण,ध्रुव ब_अक्षर_प्रकार *Err_संदेश);
  _CRTIMP errno_t __cdecl _wcsnset_s(ब_अक्षर_प्रकार *_Dst,माप_प्रकार Dst_Size_In_शब्दगण,ब_अक्षर_प्रकार _Val,माप_प्रकार Max_गिनती);
  _CRTIMP errno_t __cdecl _wcsset_s(ब_अक्षर_प्रकार *_Str,माप_प्रकार Size_In_शब्दगण,ब_अक्षर_प्रकार _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(ब_अक्षर_प्रकार *_Str,माप_प्रकार Size_In_शब्दगण);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(ब_अक्षर_प्रकार *_Str,माप_प्रकार Size_In_शब्दगण,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(ब_अक्षर_प्रकार *_Str,माप_प्रकार _Size);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(ब_अक्षर_प्रकार *_Str,माप_प्रकार _Size,_locale_t _Locale);
#endif

#ifndef _WTIME_S_DEFINED
#define _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार Size_In_शब्दगण,ध्रुव संरचना पंचांग *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार Size_In_शब्दगण,ध्रुव __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wstrdate_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार Size_In_शब्दगण);
  _CRTIMP errno_t __cdecl _wstrtime_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार Size_In_शब्दगण);
#यदि _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार Size_In_शब्दगण,ध्रुव __time64_t *_Time);
#endif

#यदि !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#define _INC_WTIME_S_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(ब_अक्षर_प्रकार *_Buffer,माप_प्रकार Size_In_शब्दगण,ध्रुव समय_प्रकार *_Time) { प्रत्यागम _wctime32_s(_Buffer,Size_In_शब्दगण,_Time); }
#अन्यथा
__CRT_INLINE errno_t __cdecl _wctime_s(ब_अक्षर_प्रकार *_Buffer,माप_प्रकार Size_In_शब्दगण,ध्रुव समय_प्रकार *_Time) { प्रत्यागम _wctime64_s(_Buffer,Size_In_शब्दगण,_Time); }
#endif
#endif
#endif

  _CRTIMP errno_t __cdecl mbsrtowcs_s(माप_प्रकार *_Retval,ब_अक्षर_प्रकार *_Dst,माप_प्रकार Size_In_शब्दगण,ध्रुव वर्ण **_PSrc,माप_प्रकार _N,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcrtomb_s(माप_प्रकार *_Retval,वर्ण *_Dst,माप_प्रकार _SizeInBytes,ब_अक्षर_प्रकार _Ch,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcsrtombs_s(माप_प्रकार *_Retval,वर्ण *_Dst,माप_प्रकार _SizeInBytes,ध्रुव ब_अक्षर_प्रकार **_Src,माप_प्रकार _Size,mbstate_t *_State);

#ifdef __cplusplus
}
#endif

#endif
#endif
