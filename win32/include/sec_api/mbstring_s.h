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
  _CRTIMP errno_t __cdecl _mbscat_s(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,ध्रुव unsigned वर्ण *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,ध्रुव unsigned वर्ण *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,ध्रुव unsigned वर्ण *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,ध्रुव unsigned वर्ण *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(unsigned वर्ण *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(unsigned वर्ण *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,ध्रुव unsigned वर्ण *_Src,size_t Max_मोजणी);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,ध्रुव unsigned वर्ण *_Src,size_t Max_मोजणी,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,ध्रुव unsigned वर्ण *_Src,size_t Max_मोजणी);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,ध्रुव unsigned वर्ण *_Src,size_t Max_मोजणी,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,unsigned पूर्णाङ्क _Ch,size_t Max_मोजणी);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,unsigned पूर्णाङ्क _Ch,size_t Max_मोजणी,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,ध्रुव unsigned वर्ण *_Src,size_t Max_मोजणी);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,ध्रुव unsigned वर्ण *_Src,size_t Max_मोजणी,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,ध्रुव unsigned वर्ण *_Src,size_t Max_मोजणी);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,ध्रुव unsigned वर्ण *_Src,size_t Max_मोजणी,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,unsigned पूर्णाङ्क _Val,size_t Max_मोजणी);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,unsigned पूर्णाङ्क _Val,size_t Max_मोजणी,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,unsigned पूर्णाङ्क _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,unsigned पूर्णाङ्क _Val,_locale_t _Locale);
  _CRTIMP unsigned वर्ण *__cdecl _mbstok_s(unsigned वर्ण *_Str,ध्रुव unsigned वर्ण *_Delim,unsigned वर्ण **_Context);
  _CRTIMP unsigned वर्ण *__cdecl _mbstok_s_l(unsigned वर्ण *_Str,ध्रुव unsigned वर्ण *_Delim,unsigned वर्ण **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(unsigned वर्ण *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(unsigned वर्ण *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,पूर्णाङ्क *_PCopied,ध्रुव unsigned वर्ण *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(unsigned वर्ण *_Dst,size_t _DstSizeInBytes,पूर्णाङ्क *_PCopied,ध्रुव unsigned वर्ण *_Src,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
