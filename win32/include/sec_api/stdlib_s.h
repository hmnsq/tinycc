/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB_S
#define _INC_STDLIB_S

#ଅନ୍ତର୍ଭାଵ <stdlib.h>

#ଯଦି defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

  _CRTIMP errno_t __cdecl _dupenv_s(ଅକ୍ଷର **_PBuffer,size_t *_PBufferSizeInBytes,ଅଚଳ ଅକ୍ଷର *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ_2,ଅକ୍ଷର *_DstBuf,size_t _Size,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
#ଯଦି _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,ଅକ୍ଷର *_DstBuf,size_t _Size,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(unsigned __int64 _Val,ଅକ୍ଷର *_DstBuf,size_t _Size,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
#endif
  _CRTIMP errno_t __cdecl _ltoa_s(long _Val,ଅକ୍ଷର *_DstBuf,size_t _Size,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(size_t *Pt_ଅଙ୍କ_Of_Char_Converted,wchar_t *_DstBuf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ ଅକ୍ଷର *_SrcBuf,size_t Max_ଗଣନା);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(size_t *Pt_ଅଙ୍କ_Of_Char_Converted,wchar_t *_DstBuf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ ଅକ୍ଷର *_SrcBuf,size_t Max_ଗଣନା,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(unsigned long _Val,ଅକ୍ଷର *_DstBuf,size_t _Size,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_SizeConverted,ଅକ୍ଷର *_MbCh,size_t _SizeInBytes,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(size_t *Pt_ଅଙ୍କ_Of_Char_Converted,ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,ଅଚଳ wchar_t *_Src,size_t Max_ଗଣନା_In_Bytes);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(size_t *Pt_ଅଙ୍କ_Of_Char_Converted,ଅକ୍ଷର *_Dst,size_t _DstSizeInBytes,ଅଚଳ wchar_t *_Src,size_t Max_ଗଣନା_In_Bytes,_locale_t _Locale);

#ifndef _WSTDLIB_S_DEFINED
#define _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Val,wchar_t *_DstBuf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (long _Val,wchar_t *_DstBuf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (unsigned long _Val,wchar_t *_DstBuf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(size_t *_ReturnSize,wchar_t *_DstBuf,size_t Dst_Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **_Buffer,size_t *Buffer_Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ wchar_t *_VarName);
#ଯଦି _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(unsigned __int64 _Val,wchar_t *_DstBuf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
#endif
#endif

#ifndef _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(ଅକ୍ଷର *_DstBuf,size_t _Size,ଦ୍ୱିଗୁଣ _Val,ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଅଙ୍କ_Of_Dights,ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_PtDec,ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(ଅକ୍ଷର *_DstBuf,size_t _Size,ଦ୍ୱିଗୁଣ _Val,ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଅଙ୍କ_Of_Dec,ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_PtDec,ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(ଅକ୍ଷର *_DstBuf,size_t _Size,ଦ୍ୱିଗୁଣ _Val,ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଅଙ୍କ_Of_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(ଅକ୍ଷର *_PathResult,size_t _Size,ଅଚଳ ଅକ୍ଷର *_Drive,ଅଚଳ ଅକ୍ଷର *_Dir,ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(ଅଚଳ ଅକ୍ଷର *_Name,ଅଚଳ ଅକ୍ଷର *ମୂଲ୍ୟ_2);
  _CRTIMP errno_t __cdecl _searchenv_s(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_EnvVar,ଅକ୍ଷର *_ResultPath,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _splitpath_s(ଅଚଳ ଅକ୍ଷର *_FullPath,ଅକ୍ଷର *_Drive,size_t _DriveSize,ଅକ୍ଷର *_Dir,size_t _DirSize,ଅକ୍ଷର *_Filename,size_t _FilenameSize,ଅକ୍ଷର *_Ext,size_t _ExtSize);

#ifndef _WSTDLIBP_S_DEFINED
#define _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_PathResult,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ wchar_t *_Drive,ଅଚଳ wchar_t *_Dir,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ଅଚଳ wchar_t *_Name,ଅଚଳ wchar_t *ମୂଲ୍ୟ_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_EnvVar,wchar_t *_ResultPath,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ଅଚଳ wchar_t *_FullPath,wchar_t *_Drive,size_t Drive_Size_In_ଶବ୍ଦଗୁଡ଼ିକ,wchar_t *_Dir,size_t Dir_Size_In_ଶବ୍ଦଗୁଡ଼ିକ,wchar_t *_Filename,size_t Filename_Size_In_ଶବ୍ଦଗୁଡ଼ିକ,wchar_t *_Ext,size_t Ext_Size_In_ଶବ୍ଦଗୁଡ଼ିକ);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
