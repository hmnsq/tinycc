/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO_S
#define _INC_STDIO_S

#अन्तर्भाव <stdio.h>

#जर defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef _STDIO_S_DEFINED
#define _STDIO_S_DEFINED
  _CRTIMP errno_t __cdecl clearerr_s(खाता *_File);
  पूर्णांक __cdecl fprintf_s(खाता *_File,स्थिरांक अक्षर *_Format,...);
  माप_प्रकार __cdecl fread_s(शून्य *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार _ElementSize,माप_प्रकार मोजणी_5,खाता *_File);
  _CRTIMP पूर्णांक __cdecl _fscanf_s_l(खाता *_File,स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  पूर्णांक __cdecl printf_s(स्थिरांक अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _scanf_l(स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _scanf_s_l(स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _snprintf_s(अक्षर *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _snprintf_c(अक्षर *_DstBuf,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vsnprintf_c(अक्षर *_DstBuf,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,बहु_सूची _ArgList);
  पूर्णांक __cdecl sprintf_s(अक्षर *_DstBuf,माप_प्रकार _DstSize,स्थिरांक अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _fscanf_l(खाता *_File,स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _sscanf_l(स्थिरांक अक्षर *_Src,स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _sscanf_s_l(स्थिरांक अक्षर *_Src,स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _snscanf_s(स्थिरांक अक्षर *_Src,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _snscanf_l(स्थिरांक अक्षर *_Src,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _snscanf_s_l(स्थिरांक अक्षर *_Src,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  पूर्णांक __cdecl vfprintf_s(खाता *_File,स्थिरांक अक्षर *_Format,बहु_सूची _ArgList);
  पूर्णांक __cdecl vprintf_s(स्थिरांक अक्षर *_Format,बहु_सूची _ArgList);
  पूर्णांक __cdecl vsnprintf_s(अक्षर *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _vsnprintf_s(अक्षर *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,बहु_सूची _ArgList);
  पूर्णांक __cdecl vsprintf_s(अक्षर *_DstBuf,माप_प्रकार _Size,स्थिरांक अक्षर *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _fprintf_p(खाता *_File,स्थिरांक अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _printf_p(स्थिरांक अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _sprintf_p(अक्षर *_Dst,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vfprintf_p(खाता *_File,स्थिरांक अक्षर *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _vprintf_p(स्थिरांक अक्षर *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _vsprintf_p(अक्षर *_Dst,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _scprintf_p(स्थिरांक अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vscprintf_p(स्थिरांक अक्षर *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _printf_l(स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _printf_p_l(स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vprintf_l(स्थिरांक अक्षर *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _vprintf_p_l(स्थिरांक अक्षर *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _fprintf_l(खाता *_File,स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _fprintf_p_l(खाता *_File,स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vfprintf_l(खाता *_File,स्थिरांक अक्षर *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _vfprintf_p_l(खाता *_File,स्थिरांक अक्षर *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _sprintf_l(अक्षर *_DstBuf,स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _sprintf_p_l(अक्षर *_DstBuf,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vsprintf_l(अक्षर *_DstBuf,स्थिरांक अक्षर *_Format,_locale_t,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _vsprintf_p_l(अक्षर *_DstBuf,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _scprintf_l(स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _scprintf_p_l(स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vscprintf_l(स्थिरांक अक्षर *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _vscprintf_p_l(स्थिरांक अक्षर *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _printf_s_l(स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vprintf_s_l(स्थिरांक अक्षर *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _fprintf_s_l(खाता *_File,स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vfprintf_s_l(खाता *_File,स्थिरांक अक्षर *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _sprintf_s_l(अक्षर *_DstBuf,माप_प्रकार _DstSize,स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vsprintf_s_l(अक्षर *_DstBuf,माप_प्रकार _DstSize,स्थिरांक अक्षर *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _snprintf_s_l(अक्षर *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vsnprintf_s_l(अक्षर *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _snprintf_l(अक्षर *_DstBuf,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _snprintf_c_l(अक्षर *_DstBuf,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vsnprintf_l(अक्षर *_DstBuf,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _vsnprintf_c_l(अक्षर *_DstBuf,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *,_locale_t _Locale,बहु_सूची _ArgList);

#ifndef _WSTDIO_S_DEFINED
#define _WSTDIO_S_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _getws_s(ब_अक्षर_प्रकार *_Str,माप_प्रकार Size_In_शब्द);
  पूर्णांक __cdecl fwprintf_s(खाता *_File,स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  पूर्णांक __cdecl wprintf_s(स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  पूर्णांक __cdecl vwprintf_s(स्थिरांक ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  पूर्णांक __cdecl swprintf_s(ब_अक्षर_प्रकार *_Dst,माप_प्रकार Size_In_शब्द,स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  पूर्णांक __cdecl vswprintf_s(ब_अक्षर_प्रकार *_Dst,माप_प्रकार Size_In_शब्द,स्थिरांक ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _snwprintf_s(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Dst_Size_In_शब्द,माप_प्रकार Max_मोजणी,स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vsnwprintf_s(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Dst_Size_In_शब्द,माप_प्रकार Max_मोजणी,स्थिरांक ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _wprintf_s_l(स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vwprintf_s_l(स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _fwprintf_s_l(खाता *_File,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vfwprintf_s_l(खाता *_File,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _swprintf_s_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार _DstSize,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vswprintf_s_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार _DstSize,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _snwprintf_s_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार Max_मोजणी,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vsnwprintf_s_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार Max_मोजणी,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _fwscanf_s_l(खाता *_File,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _swscanf_s_l(स्थिरांक ब_अक्षर_प्रकार *_Src,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _snwscanf_s(स्थिरांक ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_मोजणी,स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _snwscanf_s_l(स्थिरांक ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_मोजणी,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _wscanf_s_l(स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(खाता **_File,स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *_Mode);
  _CRTIMP errno_t __cdecl _wfreopen_s(खाता **_File,स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *_Mode,खाता *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्द);
  _CRTIMP पूर्णांक __cdecl _fwprintf_p(खाता *_File,स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _wprintf_p(स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vfwprintf_p(खाता *_File,स्थिरांक ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _vwprintf_p(स्थिरांक ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _swprintf_p(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_मोजणी,स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vswprintf_p(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_मोजणी,स्थिरांक ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _scwprintf_p(स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vscwprintf_p(स्थिरांक ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _wprintf_l(स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _wprintf_p_l(स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vwprintf_l(स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _vwprintf_p_l(स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _fwprintf_l(खाता *_File,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _fwprintf_p_l(खाता *_File,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vfwprintf_l(खाता *_File,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _vfwprintf_p_l(खाता *_File,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _swprintf_c_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_मोजणी,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _swprintf_p_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_मोजणी,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vswprintf_c_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_मोजणी,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _vswprintf_p_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_मोजणी,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _scwprintf_l(स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _scwprintf_p_l(स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vscwprintf_p_l(स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _snwprintf_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_मोजणी,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vsnwprintf_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_मोजणी,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl __swprintf_l(ब_अक्षर_प्रकार *_Dest,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Plocinfo,...);
  _CRTIMP पूर्णांक __cdecl __vswprintf_l(ब_अक्षर_प्रकार *_Dest,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Plocinfo,बहु_सूची _Args);
  _CRTIMP पूर्णांक __cdecl _vscwprintf_l(स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _fwscanf_l(खाता *_File,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _swscanf_l(स्थिरांक ब_अक्षर_प्रकार *_Src,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _snwscanf_l(स्थिरांक ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_मोजणी,स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _wscanf_l(स्थिरांक ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
#endif
#endif

  _CRTIMP माप_प्रकार __cdecl _fread_nolock_s(शून्य *_DstBuf,माप_प्रकार _DstSize,माप_प्रकार _ElementSize,माप_प्रकार मोजणी_5,खाता *_File);

#ifdef __cplusplus
}
#endif
#endif
#endif
