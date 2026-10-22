/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB_S
#define _INC_STDLIB_S

#അന്തര്ഭാവ <stdlib.h>

#എങ്കിൽ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

  _CRTIMP errno_t __cdecl _dupenv_s(അക്ഷരം **_PBuffer,size_t *_PBufferSizeInBytes,സ്ഥിരം അക്ഷരം *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(പൂർണ്ണസംഖ്യ മൂല്യം_2,അക്ഷരം *_DstBuf,size_t _Size,പൂർണ്ണസംഖ്യ _Radix);
#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,അക്ഷരം *_DstBuf,size_t _Size,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(unsigned __int64 _Val,അക്ഷരം *_DstBuf,size_t _Size,പൂർണ്ണസംഖ്യ _Radix);
#endif
  _CRTIMP errno_t __cdecl _ltoa_s(long _Val,അക്ഷരം *_DstBuf,size_t _Size,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(size_t *Pt_അക്കം_Of_Char_Converted,wchar_t *_DstBuf,size_t Size_In_വാക്കുകൾ,സ്ഥിരം അക്ഷരം *_SrcBuf,size_t Max_എണ്ണം);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(size_t *Pt_അക്കം_Of_Char_Converted,wchar_t *_DstBuf,size_t Size_In_വാക്കുകൾ,സ്ഥിരം അക്ഷരം *_SrcBuf,size_t Max_എണ്ണം,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(unsigned long _Val,അക്ഷരം *_DstBuf,size_t _Size,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(പൂർണ്ണസംഖ്യ *_SizeConverted,അക്ഷരം *_MbCh,size_t _SizeInBytes,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(size_t *Pt_അക്കം_Of_Char_Converted,അക്ഷരം *_Dst,size_t _DstSizeInBytes,സ്ഥിരം wchar_t *_Src,size_t Max_എണ്ണം_In_Bytes);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(size_t *Pt_അക്കം_Of_Char_Converted,അക്ഷരം *_Dst,size_t _DstSizeInBytes,സ്ഥിരം wchar_t *_Src,size_t Max_എണ്ണം_In_Bytes,_locale_t _Locale);

#ifndef _WSTDLIB_S_DEFINED
#define _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (പൂർണ്ണസംഖ്യ _Val,wchar_t *_DstBuf,size_t Size_In_വാക്കുകൾ,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (long _Val,wchar_t *_DstBuf,size_t Size_In_വാക്കുകൾ,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (unsigned long _Val,wchar_t *_DstBuf,size_t Size_In_വാക്കുകൾ,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(size_t *_ReturnSize,wchar_t *_DstBuf,size_t Dst_Size_In_വാക്കുകൾ,സ്ഥിരം wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **_Buffer,size_t *Buffer_Size_In_വാക്കുകൾ,സ്ഥിരം wchar_t *_VarName);
#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,size_t Size_In_വാക്കുകൾ,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(unsigned __int64 _Val,wchar_t *_DstBuf,size_t Size_In_വാക്കുകൾ,പൂർണ്ണസംഖ്യ _Radix);
#endif
#endif

#ifndef _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(അക്ഷരം *_DstBuf,size_t _Size,ഇരട്ട _Val,പൂർണ്ണസംഖ്യ അക്കം_Of_Dights,പൂർണ്ണസംഖ്യ *_PtDec,പൂർണ്ണസംഖ്യ *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(അക്ഷരം *_DstBuf,size_t _Size,ഇരട്ട _Val,പൂർണ്ണസംഖ്യ അക്കം_Of_Dec,പൂർണ്ണസംഖ്യ *_PtDec,പൂർണ്ണസംഖ്യ *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(അക്ഷരം *_DstBuf,size_t _Size,ഇരട്ട _Val,പൂർണ്ണസംഖ്യ അക്കം_Of_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(അക്ഷരം *_PathResult,size_t _Size,സ്ഥിരം അക്ഷരം *_Drive,സ്ഥിരം അക്ഷരം *_Dir,സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(സ്ഥിരം അക്ഷരം *_Name,സ്ഥിരം അക്ഷരം *മൂല്യം_2);
  _CRTIMP errno_t __cdecl _searchenv_s(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_EnvVar,അക്ഷരം *_ResultPath,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _splitpath_s(സ്ഥിരം അക്ഷരം *_FullPath,അക്ഷരം *_Drive,size_t _DriveSize,അക്ഷരം *_Dir,size_t _DirSize,അക്ഷരം *_Filename,size_t _FilenameSize,അക്ഷരം *_Ext,size_t _ExtSize);

#ifndef _WSTDLIBP_S_DEFINED
#define _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_PathResult,size_t Size_In_വാക്കുകൾ,സ്ഥിരം wchar_t *_Drive,സ്ഥിരം wchar_t *_Dir,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(സ്ഥിരം wchar_t *_Name,സ്ഥിരം wchar_t *മൂല്യം_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_EnvVar,wchar_t *_ResultPath,size_t Size_In_വാക്കുകൾ);
  _CRTIMP errno_t __cdecl _wsplitpath_s(സ്ഥിരം wchar_t *_FullPath,wchar_t *_Drive,size_t Drive_Size_In_വാക്കുകൾ,wchar_t *_Dir,size_t Dir_Size_In_വാക്കുകൾ,wchar_t *_Filename,size_t Filename_Size_In_വാക്കുകൾ,wchar_t *_Ext,size_t Ext_Size_In_വാക്കുകൾ);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
