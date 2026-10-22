/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_MBSTRING_S
#define _INC_MBSTRING_S

#अन्तर्भाव <mbstring.h>

#यदि defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef _MBSTRING_S_DEFINED
#define _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,ध्रुव अचिन्हित वर्ण *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,ध्रुव अचिन्हित वर्ण *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,ध्रुव अचिन्हित वर्ण *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,ध्रुव अचिन्हित वर्ण *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(अचिन्हित वर्ण *_Str,माप_प्रकार _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(अचिन्हित वर्ण *_Str,माप_प्रकार _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,ध्रुव अचिन्हित वर्ण *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,ध्रुव अचिन्हित वर्ण *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,ध्रुव अचिन्हित वर्ण *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,ध्रुव अचिन्हित वर्ण *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,अचिन्हित पूर्णाङ्क _Ch,माप_प्रकार Max_गिनती);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,अचिन्हित पूर्णाङ्क _Ch,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,ध्रुव अचिन्हित वर्ण *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,ध्रुव अचिन्हित वर्ण *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,ध्रुव अचिन्हित वर्ण *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,ध्रुव अचिन्हित वर्ण *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,अचिन्हित पूर्णाङ्क _Val,माप_प्रकार Max_गिनती);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,अचिन्हित पूर्णाङ्क _Val,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,अचिन्हित पूर्णाङ्क _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,अचिन्हित पूर्णाङ्क _Val,_locale_t _Locale);
  _CRTIMP अचिन्हित वर्ण *__cdecl _mbstok_s(अचिन्हित वर्ण *_Str,ध्रुव अचिन्हित वर्ण *_Delim,अचिन्हित वर्ण **_Context);
  _CRTIMP अचिन्हित वर्ण *__cdecl _mbstok_s_l(अचिन्हित वर्ण *_Str,ध्रुव अचिन्हित वर्ण *_Delim,अचिन्हित वर्ण **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(अचिन्हित वर्ण *_Str,माप_प्रकार _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(अचिन्हित वर्ण *_Str,माप_प्रकार _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,पूर्णाङ्क *_PCopied,ध्रुव अचिन्हित वर्ण *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(अचिन्हित वर्ण *_Dst,माप_प्रकार _DstSizeInBytes,पूर्णाङ्क *_PCopied,ध्रुव अचिन्हित वर्ण *_Src,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
