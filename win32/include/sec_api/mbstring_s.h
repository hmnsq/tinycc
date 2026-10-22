/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_MBSTRING_S
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_MBSTRING_S

#ಅನ್ತರ್ಭಾವ <mbstring.h>

#ಆದರೆ defined(MINGW_HAS_SECURE_API)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _MBSTRING_S_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _Ch,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _Ch,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _Val,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _Val,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _Val,_locale_t _Locale);
  _CRTIMP ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *__cdecl _mbstok_s(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Str,ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Delim,ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ **_Context);
  _CRTIMP ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *__cdecl _mbstok_s_l(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Str,ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Delim,ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಪೂರ್ಣಾಂಕ *_PCopied,ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Dst,ಗಾತ್ರ_t Dst_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಪೂರ್ಣಾಂಕ *_PCopied,ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *_Src,_locale_t _Locale);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
