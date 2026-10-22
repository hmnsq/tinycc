/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_STDLIB_S
#परिभाषय _INC_STDLIB_S

#अन्तर्भाव <stdlib.h>

#यदि defined(MINGW_HAS_SECURE_API)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

  _CRTIMP errno_t __cdecl _dupenv_s(वर्ण **_PBuffer,आकार_t *PBuffer_आकार_अन्तर्_अष्टकानि,ध्रुव वर्ण *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(पूर्णाङ्क मानम्_2,वर्ण *_DstBuf,आकार_t आकार_4,पूर्णाङ्क _Radix);
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,वर्ण *_DstBuf,आकार_t आकार_4,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(अचिह्नित __int64 _Val,वर्ण *_DstBuf,आकार_t आकार_4,पूर्णाङ्क _Radix);
#यदि_अन्तः
  _CRTIMP errno_t __cdecl _ltoa_s(दीर्घ _Val,वर्ण *_DstBuf,आकार_t आकार_4,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(आकार_t *Pt_अङ्कः_सम्बन्धि_Char_Converted,wchar_t *_DstBuf,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव वर्ण *_SrcBuf,आकार_t Max_गणनम्);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(आकार_t *Pt_अङ्कः_सम्बन्धि_Char_Converted,wchar_t *_DstBuf,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव वर्ण *_SrcBuf,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(अचिह्नित दीर्घ _Val,वर्ण *_DstBuf,आकार_t आकार_4,पूर्णाङ्क _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(पूर्णाङ्क *आकार_Converted,वर्ण *_MbCh,आकार_t आकार_अन्तर्_अष्टकानि,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(आकार_t *Pt_अङ्कः_सम्बन्धि_Char_Converted,वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,ध्रुव wchar_t *_Src,आकार_t Max_गणनम्_अन्तर्_अष्टकानि);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(आकार_t *Pt_अङ्कः_सम्बन्धि_Char_Converted,वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,ध्रुव wchar_t *_Src,आकार_t Max_गणनम्_अन्तर्_अष्टकानि,_locale_t _Locale);

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
  _CRTIMP errno_t __cdecl _ecvt_s(वर्ण *_DstBuf,आकार_t आकार_4,द्विगुण _Val,पूर्णाङ्क अङ्कः_सम्बन्धि_Dights,पूर्णाङ्क *_PtDec,पूर्णाङ्क *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(वर्ण *_DstBuf,आकार_t आकार_4,द्विगुण _Val,पूर्णाङ्क अङ्कः_सम्बन्धि_Dec,पूर्णाङ्क *_PtDec,पूर्णाङ्क *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(वर्ण *_DstBuf,आकार_t आकार_4,द्विगुण _Val,पूर्णाङ्क अङ्कः_सम्बन्धि_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(वर्ण *मार्गः_परिणाम,आकार_t आकार_4,ध्रुव वर्ण *_Drive,ध्रुव वर्ण *_Dir,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(ध्रुव वर्ण *_Name,ध्रुव वर्ण *मानम्_2);
  _CRTIMP errno_t __cdecl _searchenv_s(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_EnvVar,वर्ण *परिणाम_मार्गः,आकार_t आकार_अन्तर्_अष्टकानि);
  _CRTIMP errno_t __cdecl _splitpath_s(ध्रुव वर्ण *पूर्णम्_मार्गः,वर्ण *_Drive,आकार_t Drive_आकार,वर्ण *_Dir,आकार_t Dir_आकार,वर्ण *_Filename,आकार_t Filename_आकार,वर्ण *_Ext,आकार_t Ext_आकार);

#यदि_अपरिभाषितम् _WSTDLIBP_S_DEFINED
#परिभाषय _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *मार्गः_परिणाम,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव wchar_t *_Drive,ध्रुव wchar_t *_Dir,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ध्रुव wchar_t *_Name,ध्रुव wchar_t *मानम्_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_EnvVar,wchar_t *परिणाम_मार्गः,आकार_t आकार_अन्तर्_शब्दाः);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ध्रुव wchar_t *पूर्णम्_मार्गः,wchar_t *_Drive,आकार_t Drive_आकार_अन्तर्_शब्दाः,wchar_t *_Dir,आकार_t Dir_आकार_अन्तर्_शब्दाः,wchar_t *_Filename,आकार_t Filename_आकार_अन्तर्_शब्दाः,wchar_t *_Ext,आकार_t Ext_आकार_अन्तर्_शब्दाः);
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#यदि_अन्तः
#यदि_अन्तः
