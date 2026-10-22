/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_STRING_S
#परिभाषय _INC_STRING_S

#अन्तर्भाव <string.h>

#यदि defined(MINGW_HAS_SECURE_API)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

  _CRTIMP errno_t __cdecl _strset_s(वर्ण *_Dst,आकार_t Dst_आकार,पूर्णाङ्क मानम्_2);
  _CRTIMP errno_t __cdecl _strerror_s(वर्ण *_Buf,आकार_t आकार_अन्तर्_अष्टकानि,ध्रुव वर्ण *Err_सन्देशः);
  _CRTIMP errno_t __cdecl _strlwr_s(वर्ण *_Str,आकार_t आकार_4);
  _CRTIMP errno_t __cdecl _strlwr_s_l(वर्ण *_Str,आकार_t आकार_4,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(वर्ण *_Str,आकार_t आकार_4,पूर्णाङ्क _Val,आकार_t Max_गणनम्);
  _CRTIMP errno_t __cdecl _strupr_s(वर्ण *_Str,आकार_t आकार_4);
  _CRTIMP errno_t __cdecl _strupr_s_l(वर्ण *_Str,आकार_t आकार_4,_locale_t _Locale);
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

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः
