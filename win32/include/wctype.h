/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_WCTYPE
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_WCTYPE

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
#ದೋಷ Only Win32 ಗುರಿ is supported!
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ಸೂಚನೆ pack(ತಳ್ಳು,_CRT_PACKING)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRTIMP
#ವ್ಯಾಖ್ಯಾನಿಸು _CRTIMP __declspec(dllimport)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WCHAR_T_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ wchar_t;
#ವ್ಯಾಖ್ಯಾನಿಸು _WCHAR_T_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WCTYPE_T_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ wint_t;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ wctype_t;
#ವ್ಯಾಖ್ಯಾನಿಸು _WCTYPE_T_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WEOF
#ವ್ಯಾಖ್ಯಾನಿಸು WEOF (wint_t)(0xFFFF)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_CTYPEDATA_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_CTYPEDATA_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CTYPE_DISABLE_MACROS

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __PCTYPE_FUNC
#ವ್ಯಾಖ್ಯಾನಿಸು __PCTYPE_FUNC __pctype_func()
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
#ವ್ಯಾಖ್ಯಾನಿಸು __pctype_func() (_pctype)
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು __pctype_func() (*_imp___pctype)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _pctype
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ *_pctype;
#ಇಲ್ಲದಿದ್ದರೆ
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ **_imp___pctype;
#ವ್ಯಾಖ್ಯಾನಿಸು _pctype (*_imp___pctype)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_WCTYPEDATA_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_WCTYPEDATA_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CTYPE_DISABLE_MACROS
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _wctype
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ *_wctype;
#ಇಲ್ಲದಿದ್ದರೆ
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ **_imp___wctype;
#ವ್ಯಾಖ್ಯಾನಿಸು _wctype (*_imp___wctype)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _pwctype
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ *_pwctype;
#ಇಲ್ಲದಿದ್ದರೆ
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ **_imp___pwctype;
#ವ್ಯಾಖ್ಯಾನಿಸು _pwctype (*_imp___pwctype)
#ವ್ಯಾಖ್ಯಾನಿಸು __pwctype_func() (*_imp___pwctype)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು ಊರ್ಧ್ವ_3 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು ಅಧೋ_2 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು _DIGIT 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು _SPACE 0x8

#ವ್ಯಾಖ್ಯಾನಿಸು _PUNCT 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು _CONTROL 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು _BLANK 0x40
#ವ್ಯಾಖ್ಯಾನಿಸು _HEX 0x80

#ವ್ಯಾಖ್ಯಾನಿಸು _LEADBYTE 0x8000
#ವ್ಯಾಖ್ಯಾನಿಸು _ALPHA (0x0100|ಊರ್ಧ್ವ_3|ಅಧೋ_2)

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WCTYPE_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WCTYPE_DEFINED

  ಪೂರ್ಣಾಂಕ __cdecl iswalpha(wint_t);
  ಪೂರ್ಣಾಂಕ __cdecl iswupper(wint_t);
  ಪೂರ್ಣಾಂಕ __cdecl iswlower(wint_t);
  ಪೂರ್ಣಾಂಕ __cdecl iswdigit(wint_t);
  ಪೂರ್ಣಾಂಕ __cdecl iswxdigit(wint_t);
  ಪೂರ್ಣಾಂಕ __cdecl iswspace(wint_t);
  ಪೂರ್ಣಾಂಕ __cdecl iswpunct(wint_t);
  ಪೂರ್ಣಾಂಕ __cdecl iswalnum(wint_t);
  ಪೂರ್ಣಾಂಕ __cdecl iswprint(wint_t);
  ಪೂರ್ಣಾಂಕ __cdecl iswgraph(wint_t);
  ಪೂರ್ಣಾಂಕ __cdecl iswcntrl(wint_t);
  ಪೂರ್ಣಾಂಕ __cdecl iswascii(wint_t);
  ಪೂರ್ಣಾಂಕ __cdecl isleadbyte(ಪೂರ್ಣಾಂಕ);
  wint_t __cdecl towupper(wint_t);
  wint_t __cdecl towlower(wint_t);
  ಪೂರ್ಣಾಂಕ __cdecl iswctype(wint_t,wctype_t);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl __iswcsymf(wint_t);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl __iswcsym(wint_t);
  ಪೂರ್ಣಾಂಕ __cdecl is_wctype(wint_t,wctype_t);
#ಆದರೆ (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
ಪೂರ್ಣಾಂಕ __cdecl isblank(ಪೂರ್ಣಾಂಕ _C);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WCTYPE_INLINE_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WCTYPE_INLINE_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು iswalpha(_c) (iswctype(_c,_ALPHA))
#ವ್ಯಾಖ್ಯಾನಿಸು iswupper(_c) (iswctype(_c,ಊರ್ಧ್ವ_3))
#ವ್ಯಾಖ್ಯಾನಿಸು iswlower(_c) (iswctype(_c,ಅಧೋ_2))
#ವ್ಯಾಖ್ಯಾನಿಸು iswdigit(_c) (iswctype(_c,_DIGIT))
#ವ್ಯಾಖ್ಯಾನಿಸು iswxdigit(_c) (iswctype(_c,_HEX))
#ವ್ಯಾಖ್ಯಾನಿಸು iswspace(_c) (iswctype(_c,_SPACE))
#ವ್ಯಾಖ್ಯಾನಿಸು iswpunct(_c) (iswctype(_c,_PUNCT))
#ವ್ಯಾಖ್ಯಾನಿಸು iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#ವ್ಯಾಖ್ಯಾನಿಸು iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#ವ್ಯಾಖ್ಯಾನಿಸು iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#ವ್ಯಾಖ್ಯಾನಿಸು iswcntrl(_c) (iswctype(_c,_CONTROL))
#ವ್ಯಾಖ್ಯಾನಿಸು iswascii(_c) ((ಚಿಹ್ನೆರಹಿತ)(_c) < 0x80)
#ವ್ಯಾಖ್ಯಾನಿಸು isleadbyte(c) (__pctype_func()[(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ)(c)] & _LEADBYTE)
#ಇಲ್ಲದಿದ್ದರೆ
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl iswalpha(wint_t _C) {ಹಿಂತಿರುಗಿ (iswctype(_C,_ALPHA)); }
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl iswupper(wint_t _C) {ಹಿಂತಿರುಗಿ (iswctype(_C,ಊರ್ಧ್ವ_3)); }
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl iswlower(wint_t _C) {ಹಿಂತಿರುಗಿ (iswctype(_C,ಅಧೋ_2)); }
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl iswdigit(wint_t _C) {ಹಿಂತಿರುಗಿ (iswctype(_C,_DIGIT)); }
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl iswxdigit(wint_t _C) {ಹಿಂತಿರುಗಿ (iswctype(_C,_HEX)); }
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl iswspace(wint_t _C) {ಹಿಂತಿರುಗಿ (iswctype(_C,_SPACE)); }
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl iswpunct(wint_t _C) {ಹಿಂತಿರುಗಿ (iswctype(_C,_PUNCT)); }
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl iswalnum(wint_t _C) {ಹಿಂತಿರುಗಿ (iswctype(_C,_ALPHA|_DIGIT)); }
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl iswprint(wint_t _C) {ಹಿಂತಿರುಗಿ (iswctype(_C,_BLANK|_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl iswgraph(wint_t _C) {ಹಿಂತಿರುಗಿ (iswctype(_C,_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl iswcntrl(wint_t _C) {ಹಿಂತಿರುಗಿ (iswctype(_C,_CONTROL)); }
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl iswascii(wint_t _C) {ಹಿಂತಿರುಗಿ ((ಚಿಹ್ನೆರಹಿತ)(_C) < 0x80); }
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl isleadbyte(ಪೂರ್ಣಾಂಕ _C) {ಹಿಂತಿರುಗಿ (__pctype_func()[(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ)(_C)] & _LEADBYTE); }
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ wchar_t wctrans_t;
  wint_t __cdecl towctrans(wint_t,wctrans_t);
  wctrans_t __cdecl wctrans(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *);
  wctype_t __cdecl wctype(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ pack(ತೆಗೆ)
#ಆದರೆ_ಅಂತ್ಯ
