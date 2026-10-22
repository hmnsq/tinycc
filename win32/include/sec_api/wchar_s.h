/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_WCHAR_S
#परिभाषय _INC_WCHAR_S

#अन्तर्भाव <wchar.h>

#यदि defined(MINGW_HAS_SECURE_API)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् _WIO_S_DEFINED
#परिभाषय _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ध्रुव wchar_t *_Filename,पूर्णाङ्क Access_बहुलकम्);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,आकार_t आकार_अन्तर्_शब्दाः);
#यदि_अन्तः

#यदि_अपरिभाषितम् _WCONIO_S_DEFINED
#परिभाषय _WCONIO_S_DEFINED
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *बफर_2,आकार_t आकार_अन्तर्_शब्दाः,आकार_t *आकार_Read);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_s(ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cwscanf_s(ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cwscanf_s_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_s(ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_s_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_s_l(ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#यदि_अन्तः

#यदि_अपरिभाषितम् _WSTDIO_S_DEFINED
#परिभाषय _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,आकार_t आकार_अन्तर्_शब्दाः);
  पूर्णाङ्क __cdecl fwprintf_s(FILE *_File,ध्रुव wchar_t *_Format,...);
  पूर्णाङ्क __cdecl wprintf_s(ध्रुव wchar_t *_Format,...);
  पूर्णाङ्क __cdecl vfwprintf_s(FILE *_File,ध्रुव wchar_t *_Format,va_list _ArgList);
  पूर्णाङ्क __cdecl vwprintf_s(ध्रुव wchar_t *_Format,va_list _ArgList);
  पूर्णाङ्क __cdecl swprintf_s(wchar_t *_Dst,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव wchar_t *_Format,...);
  पूर्णाङ्क __cdecl vswprintf_s(wchar_t *_Dst,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snwprintf_s(wchar_t *_DstBuf,आकार_t Dst_आकार_अन्तर्_शब्दाः,आकार_t Max_गणनम्,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnwprintf_s(wchar_t *_DstBuf,आकार_t Dst_आकार_अन्तर्_शब्दाः,आकार_t Max_गणनम्,ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _wprintf_s_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vwprintf_s_l(ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fwprintf_s_l(FILE *_File,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vfwprintf_s_l(FILE *_File,ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_s_l(wchar_t *_DstBuf,आकार_t Dst_आकार,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_s_l(wchar_t *_DstBuf,आकार_t Dst_आकार,ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snwprintf_s_l(wchar_t *_DstBuf,आकार_t Dst_आकार,आकार_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,आकार_t Dst_आकार,आकार_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fwscanf_s_l(FILE *_File,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _swscanf_s_l(ध्रुव wchar_t *_Src,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _snwscanf_s(ध्रुव wchar_t *_Src,आकार_t Max_गणनम्,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _snwscanf_s_l(ध्रुव wchar_t *_Src,आकार_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _wscanf_s_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *बहुलकम्_3);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *बहुलकम्_3,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,आकार_t आकार_अन्तर्_शब्दाः);
#यदि_अन्तः

#यदि_अपरिभाषितम् _WSTDLIB_S_DEFINED
#परिभाषय _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (पूर्णाङ्क _Val,wchar_t *_DstBuf,आकार_t आकार_अन्तर्_शब्दाः,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (दीर्घ _Val,wchar_t *_DstBuf,आकार_t आकार_अन्तर्_शब्दाः,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (अचिह्नित दीर्घ _Val,wchar_t *_DstBuf,आकार_t आकार_अन्तर्_शब्दाः,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(आकार_t *Return_आकार,wchar_t *_DstBuf,आकार_t Dst_आकार_अन्तर्_शब्दाः,ध्रुव wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **बफर_2,आकार_t *बफर_आकार_अन्तर्_शब्दाः,ध्रुव wchar_t *_VarName);
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,आकार_t आकार_अन्तर्_शब्दाः,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(अचिह्नित __int64 _Val,wchar_t *_DstBuf,आकार_t आकार_अन्तर्_शब्दाः,पूर्णाङ्क _Radix);
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _POSIX_
#यदि_अपरिभाषितम् _WSTDLIBP_S_DEFINED
#परिभाषय _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *मार्गः_परिणाम,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव wchar_t *_Drive,ध्रुव wchar_t *_Dir,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ध्रुव wchar_t *_Name,ध्रुव wchar_t *मानम्_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_EnvVar,wchar_t *परिणाम_मार्गः,आकार_t आकार_अन्तर्_शब्दाः);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ध्रुव wchar_t *पूर्णम्_मार्गः,wchar_t *_Drive,आकार_t Drive_आकार_अन्तर्_शब्दाः,wchar_t *_Dir,आकार_t Dir_आकार_अन्तर्_शब्दाः,wchar_t *_Filename,आकार_t Filename_आकार_अन्तर्_शब्दाः,wchar_t *_Ext,आकार_t Ext_आकार_अन्तर्_शब्दाः);
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _WSTRING_S_DEFINED
#परिभाषय _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,ध्रुव wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,आकार_t आकार_अन्तर्_शब्दाः,पूर्णाङ्क Err_अङ्कः);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *बफर_2,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव wchar_t *Err_सन्देशः);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,आकार_t Dst_आकार_अन्तर्_शब्दाः,wchar_t _Val,आकार_t Max_गणनम्);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,आकार_t आकार_अन्तर्_शब्दाः,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,आकार_t आकार_अन्तर्_शब्दाः);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,आकार_t आकार_अन्तर्_शब्दाः,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,आकार_t आकार_4);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,आकार_t आकार_4,_locale_t _Locale);
#यदि_अन्तः

#यदि_अपरिभाषितम् _WTIME_S_DEFINED
#परिभाषय _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव संरचना tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,आकार_t आकार_अन्तर्_शब्दाः);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,आकार_t आकार_अन्तर्_शब्दाः);
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव __time64_t *_Time);
#यदि_अन्तः

#यदि !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#परिभाषय _INC_WTIME_S_INL
#यदि_परिभाषितम् _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *बफर_2,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव time_t *_Time) { प्रत्यागम _wctime32_s(बफर_2,आकार_अन्तर्_शब्दाः,_Time); }
#अन्यथा
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *बफर_2,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव time_t *_Time) { प्रत्यागम _wctime64_s(बफर_2,आकार_अन्तर्_शब्दाः,_Time); }
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

  _CRTIMP errno_t __cdecl mbsrtowcs_s(आकार_t *_Retval,wchar_t *_Dst,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव वर्ण **_PSrc,आकार_t _N,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcrtomb_s(आकार_t *_Retval,वर्ण *_Dst,आकार_t आकार_अन्तर्_अष्टकानि,wchar_t _Ch,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcsrtombs_s(आकार_t *_Retval,वर्ण *_Dst,आकार_t आकार_अन्तर्_अष्टकानि,ध्रुव wchar_t **_Src,आकार_t आकार_4,mbstate_t *_State);

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#यदि_अन्तः
#यदि_अन्तः
