/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO_S
#define _INC_STDIO_S

#अन्तर्भाव <stdio.h>

#यदि defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef _STDIO_S_DEFINED
#define _STDIO_S_DEFINED
  _CRTIMP errno_t __cdecl clearerr_s(खाता *_File);
  पूर्णाङ्क __cdecl fprintf_s(खाता *_File,अचर वर्ण *_Format,...);
  माप_प्रकार __cdecl fread_s(शून्य *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार _ElementSize,माप_प्रकार गन्ती_5,खाता *_File);
  _CRTIMP पूर्णाङ्क __cdecl _fscanf_s_l(खाता *_File,अचर वर्ण *_Format,_locale_t _Locale,...);
  पूर्णाङ्क __cdecl printf_s(अचर वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _scanf_l(अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _scanf_s_l(अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _snprintf_s(वर्ण *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार Max_गन्ती,अचर वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _snprintf_c(वर्ण *_DstBuf,माप_प्रकार Max_गन्ती,अचर वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnprintf_c(वर्ण *_DstBuf,माप_प्रकार Max_गन्ती,अचर वर्ण *_Format,बहु_सूची _ArgList);
  पूर्णाङ्क __cdecl sprintf_s(वर्ण *_DstBuf,माप_प्रकार _DstSize,अचर वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _fscanf_l(खाता *_File,अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _sscanf_l(अचर वर्ण *_Src,अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _sscanf_s_l(अचर वर्ण *_Src,अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _snscanf_s(अचर वर्ण *_Src,माप_प्रकार Max_गन्ती,अचर वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _snscanf_l(अचर वर्ण *_Src,माप_प्रकार Max_गन्ती,अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _snscanf_s_l(अचर वर्ण *_Src,माप_प्रकार Max_गन्ती,अचर वर्ण *_Format,_locale_t _Locale,...);
  पूर्णाङ्क __cdecl vfprintf_s(खाता *_File,अचर वर्ण *_Format,बहु_सूची _ArgList);
  पूर्णाङ्क __cdecl vprintf_s(अचर वर्ण *_Format,बहु_सूची _ArgList);
  पूर्णाङ्क __cdecl vsnprintf_s(वर्ण *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार Max_गन्ती,अचर वर्ण *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vsnprintf_s(वर्ण *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार Max_गन्ती,अचर वर्ण *_Format,बहु_सूची _ArgList);
  पूर्णाङ्क __cdecl vsprintf_s(वर्ण *_DstBuf,माप_प्रकार _Size,अचर वर्ण *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fprintf_p(खाता *_File,अचर वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _printf_p(अचर वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _sprintf_p(वर्ण *_Dst,माप_प्रकार Max_गन्ती,अचर वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vfprintf_p(खाता *_File,अचर वर्ण *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vprintf_p(अचर वर्ण *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vsprintf_p(वर्ण *_Dst,माप_प्रकार Max_गन्ती,अचर वर्ण *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _scprintf_p(अचर वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vscprintf_p(अचर वर्ण *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _printf_l(अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _printf_p_l(अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vprintf_l(अचर वर्ण *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vprintf_p_l(अचर वर्ण *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fprintf_l(खाता *_File,अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _fprintf_p_l(खाता *_File,अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vfprintf_l(खाता *_File,अचर वर्ण *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vfprintf_p_l(खाता *_File,अचर वर्ण *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _sprintf_l(वर्ण *_DstBuf,अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _sprintf_p_l(वर्ण *_DstBuf,माप_प्रकार Max_गन्ती,अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsprintf_l(वर्ण *_DstBuf,अचर वर्ण *_Format,_locale_t,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vsprintf_p_l(वर्ण *_DstBuf,माप_प्रकार Max_गन्ती,अचर वर्ण *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _scprintf_l(अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _scprintf_p_l(अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vscprintf_l(अचर वर्ण *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vscprintf_p_l(अचर वर्ण *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _printf_s_l(अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vprintf_s_l(अचर वर्ण *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fprintf_s_l(खाता *_File,अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vfprintf_s_l(खाता *_File,अचर वर्ण *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _sprintf_s_l(वर्ण *_DstBuf,माप_प्रकार _DstSize,अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsprintf_s_l(वर्ण *_DstBuf,माप_प्रकार _DstSize,अचर वर्ण *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snprintf_s_l(वर्ण *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार Max_गन्ती,अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnprintf_s_l(वर्ण *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार Max_गन्ती,अचर वर्ण *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snprintf_l(वर्ण *_DstBuf,माप_प्रकार Max_गन्ती,अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _snprintf_c_l(वर्ण *_DstBuf,माप_प्रकार Max_गन्ती,अचर वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnprintf_l(वर्ण *_DstBuf,माप_प्रकार Max_गन्ती,अचर वर्ण *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vsnprintf_c_l(वर्ण *_DstBuf,माप_प्रकार Max_गन्ती,अचर वर्ण *,_locale_t _Locale,बहु_सूची _ArgList);

#ifndef _WSTDIO_S_DEFINED
#define _WSTDIO_S_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _getws_s(ब_अक्षर_प्रकार *_Str,माप_प्रकार Size_In_शब्दहरू);
  पूर्णाङ्क __cdecl fwprintf_s(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,...);
  पूर्णाङ्क __cdecl wprintf_s(अचर ब_अक्षर_प्रकार *_Format,...);
  पूर्णाङ्क __cdecl vwprintf_s(अचर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  पूर्णाङ्क __cdecl swprintf_s(ब_अक्षर_प्रकार *_Dst,माप_प्रकार Size_In_शब्दहरू,अचर ब_अक्षर_प्रकार *_Format,...);
  पूर्णाङ्क __cdecl vswprintf_s(ब_अक्षर_प्रकार *_Dst,माप_प्रकार Size_In_शब्दहरू,अचर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snwprintf_s(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Dst_Size_In_शब्दहरू,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnwprintf_s(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Dst_Size_In_शब्दहरू,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _wprintf_s_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vwprintf_s_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fwprintf_s_l(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vfwprintf_s_l(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_s_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार _DstSize,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_s_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार _DstSize,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snwprintf_s_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnwprintf_s_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fwscanf_s_l(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _swscanf_s_l(अचर ब_अक्षर_प्रकार *_Src,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _snwscanf_s(अचर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _snwscanf_s_l(अचर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _wscanf_s_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(खाता **_File,अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *_Mode);
  _CRTIMP errno_t __cdecl _wfreopen_s(खाता **_File,अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *_Mode,खाता *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्दहरू);
  _CRTIMP पूर्णाङ्क __cdecl _fwprintf_p(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _wprintf_p(अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vfwprintf_p(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vwprintf_p(अचर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_p(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_p(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _scwprintf_p(अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vscwprintf_p(अचर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _wprintf_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _wprintf_p_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vwprintf_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vwprintf_p_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fwprintf_l(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _fwprintf_p_l(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vfwprintf_l(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vfwprintf_p_l(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_c_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_p_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_c_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_p_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _scwprintf_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _scwprintf_p_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vscwprintf_p_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snwprintf_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnwprintf_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl __swprintf_l(ब_अक्षर_प्रकार *_Dest,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Plocinfo,...);
  _CRTIMP पूर्णाङ्क __cdecl __vswprintf_l(ब_अक्षर_प्रकार *_Dest,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Plocinfo,बहु_सूची _Args);
  _CRTIMP पूर्णाङ्क __cdecl _vscwprintf_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fwscanf_l(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _swscanf_l(अचर ब_अक्षर_प्रकार *_Src,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _snwscanf_l(अचर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _wscanf_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
#endif
#endif

  _CRTIMP माप_प्रकार __cdecl _fread_nolock_s(शून्य *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार _ElementSize,माप_प्रकार गन्ती_5,खाता *_File);

#ifdef __cplusplus
}
#endif
#endif
#endif
