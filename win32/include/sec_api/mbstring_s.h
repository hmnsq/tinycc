/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_MBSTRING_S
#define _INC_MBSTRING_S

#അന്തര്ഭാവ <mbstring.h>

#എങ്കിൽ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

#ifndef _MBSTRING_S_DEFINED
#define _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,സ്ഥിരം unsigned അക്ഷരം *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,സ്ഥിരം unsigned അക്ഷരം *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,സ്ഥിരം unsigned അക്ഷരം *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,സ്ഥിരം unsigned അക്ഷരം *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(unsigned അക്ഷരം *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(unsigned അക്ഷരം *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,സ്ഥിരം unsigned അക്ഷരം *_Src,size_t Max_എണ്ണം);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,സ്ഥിരം unsigned അക്ഷരം *_Src,size_t Max_എണ്ണം,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,സ്ഥിരം unsigned അക്ഷരം *_Src,size_t Max_എണ്ണം);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,സ്ഥിരം unsigned അക്ഷരം *_Src,size_t Max_എണ്ണം,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,unsigned പൂർണ്ണസംഖ്യ _Ch,size_t Max_എണ്ണം);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,unsigned പൂർണ്ണസംഖ്യ _Ch,size_t Max_എണ്ണം,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,സ്ഥിരം unsigned അക്ഷരം *_Src,size_t Max_എണ്ണം);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,സ്ഥിരം unsigned അക്ഷരം *_Src,size_t Max_എണ്ണം,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,സ്ഥിരം unsigned അക്ഷരം *_Src,size_t Max_എണ്ണം);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,സ്ഥിരം unsigned അക്ഷരം *_Src,size_t Max_എണ്ണം,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,unsigned പൂർണ്ണസംഖ്യ _Val,size_t Max_എണ്ണം);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,unsigned പൂർണ്ണസംഖ്യ _Val,size_t Max_എണ്ണം,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,unsigned പൂർണ്ണസംഖ്യ _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,unsigned പൂർണ്ണസംഖ്യ _Val,_locale_t _Locale);
  _CRTIMP unsigned അക്ഷരം *__cdecl _mbstok_s(unsigned അക്ഷരം *_Str,സ്ഥിരം unsigned അക്ഷരം *_Delim,unsigned അക്ഷരം **_Context);
  _CRTIMP unsigned അക്ഷരം *__cdecl _mbstok_s_l(unsigned അക്ഷരം *_Str,സ്ഥിരം unsigned അക്ഷരം *_Delim,unsigned അക്ഷരം **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(unsigned അക്ഷരം *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(unsigned അക്ഷരം *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,പൂർണ്ണസംഖ്യ *_PCopied,സ്ഥിരം unsigned അക്ഷരം *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(unsigned അക്ഷരം *_Dst,size_t _DstSizeInBytes,പൂർണ്ണസംഖ്യ *_PCopied,സ്ഥിരം unsigned അക്ഷരം *_Src,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
