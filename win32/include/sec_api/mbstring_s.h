/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_MBSTRING_S
#परिभाषय _INC_MBSTRING_S

#अन्तर्भाव <mbstring.h>

#यदि defined(MINGW_HAS_SECURE_API)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् _MBSTRING_S_DEFINED
#परिभाषय _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,ध्रुव अचिह्नित वर्ण *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,ध्रुव अचिह्नित वर्ण *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,ध्रुव अचिह्नित वर्ण *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,ध्रुव अचिह्नित वर्ण *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(अचिह्नित वर्ण *_Str,आकार_t आकार_अन्तर्_अष्टकानि);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(अचिह्नित वर्ण *_Str,आकार_t आकार_अन्तर्_अष्टकानि,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,ध्रुव अचिह्नित वर्ण *_Src,आकार_t Max_गणनम्);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,ध्रुव अचिह्नित वर्ण *_Src,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,ध्रुव अचिह्नित वर्ण *_Src,आकार_t Max_गणनम्);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,ध्रुव अचिह्नित वर्ण *_Src,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,अचिह्नित पूर्णाङ्क _Ch,आकार_t Max_गणनम्);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,अचिह्नित पूर्णाङ्क _Ch,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,ध्रुव अचिह्नित वर्ण *_Src,आकार_t Max_गणनम्);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,ध्रुव अचिह्नित वर्ण *_Src,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,ध्रुव अचिह्नित वर्ण *_Src,आकार_t Max_गणनम्);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,ध्रुव अचिह्नित वर्ण *_Src,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,अचिह्नित पूर्णाङ्क _Val,आकार_t Max_गणनम्);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,अचिह्नित पूर्णाङ्क _Val,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,अचिह्नित पूर्णाङ्क _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,अचिह्नित पूर्णाङ्क _Val,_locale_t _Locale);
  _CRTIMP अचिह्नित वर्ण *__cdecl _mbstok_s(अचिह्नित वर्ण *_Str,ध्रुव अचिह्नित वर्ण *_Delim,अचिह्नित वर्ण **_Context);
  _CRTIMP अचिह्नित वर्ण *__cdecl _mbstok_s_l(अचिह्नित वर्ण *_Str,ध्रुव अचिह्नित वर्ण *_Delim,अचिह्नित वर्ण **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(अचिह्नित वर्ण *_Str,आकार_t आकार_अन्तर्_अष्टकानि);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(अचिह्नित वर्ण *_Str,आकार_t आकार_अन्तर्_अष्टकानि,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,पूर्णाङ्क *_PCopied,ध्रुव अचिह्नित वर्ण *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(अचिह्नित वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_अष्टकानि,पूर्णाङ्क *_PCopied,ध्रुव अचिह्नित वर्ण *_Src,_locale_t _Locale);
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#यदि_अन्तः
#यदि_अन्तः
