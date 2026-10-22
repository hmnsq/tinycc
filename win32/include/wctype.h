/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_WCTYPE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_WCTYPE

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
#ਗਲਤੀ Only Win32 ਨਿਸ਼ਾਨਾ is supported!
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

#ਹਦਾਇਤ pack(ਧੱਕੋ,_CRT_PACKING)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRTIMP
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRTIMP __declspec(dllimport)
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WCHAR_T_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ wchar_t;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WCHAR_T_DEFINED
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WCTYPE_T_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ wint_t;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ wctype_t;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WCTYPE_T_DEFINED
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WEOF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WEOF (wint_t)(0xFFFF)
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_CTYPEDATA_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_CTYPEDATA_DEFINED
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CTYPE_DISABLE_MACROS

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __PCTYPE_FUNC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __PCTYPE_FUNC __pctype_func()
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __pctype_func() (_pctype)
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __pctype_func() (*_imp___pctype)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _pctype
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ *_pctype;
#ਨਹੀਂਤਾਂ
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ **_imp___pctype;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _pctype (*_imp___pctype)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_WCTYPEDATA_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_WCTYPEDATA_DEFINED
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CTYPE_DISABLE_MACROS
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _wctype
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ *_wctype;
#ਨਹੀਂਤਾਂ
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ **_imp___wctype;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wctype (*_imp___wctype)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _pwctype
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ *_pwctype;
#ਨਹੀਂਤਾਂ
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ **_imp___pwctype;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _pwctype (*_imp___pwctype)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __pwctype_func() (*_imp___pwctype)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਉੱਤਲਾ_3 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਹੇਠਲਾ_2 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _DIGIT 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SPACE 0x8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _PUNCT 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CONTROL 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _BLANK 0x40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _HEX 0x80

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _LEADBYTE 0x8000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _ALPHA (0x0100|ਉੱਤਲਾ_3|ਹੇਠਲਾ_2)

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WCTYPE_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WCTYPE_DEFINED

  ਪੂਰਨ __cdecl iswalpha(wint_t);
  ਪੂਰਨ __cdecl iswupper(wint_t);
  ਪੂਰਨ __cdecl iswlower(wint_t);
  ਪੂਰਨ __cdecl iswdigit(wint_t);
  ਪੂਰਨ __cdecl iswxdigit(wint_t);
  ਪੂਰਨ __cdecl iswspace(wint_t);
  ਪੂਰਨ __cdecl iswpunct(wint_t);
  ਪੂਰਨ __cdecl iswalnum(wint_t);
  ਪੂਰਨ __cdecl iswprint(wint_t);
  ਪੂਰਨ __cdecl iswgraph(wint_t);
  ਪੂਰਨ __cdecl iswcntrl(wint_t);
  ਪੂਰਨ __cdecl iswascii(wint_t);
  ਪੂਰਨ __cdecl isleadbyte(ਪੂਰਨ);
  wint_t __cdecl towupper(wint_t);
  wint_t __cdecl towlower(wint_t);
  ਪੂਰਨ __cdecl iswctype(wint_t,wctype_t);
  _CRTIMP ਪੂਰਨ __cdecl __iswcsymf(wint_t);
  _CRTIMP ਪੂਰਨ __cdecl __iswcsym(wint_t);
  ਪੂਰਨ __cdecl is_wctype(wint_t,wctype_t);
#ਜੇ (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
ਪੂਰਨ __cdecl isblank(ਪੂਰਨ _C);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WCTYPE_INLINE_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WCTYPE_INLINE_DEFINED
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswalpha(_c) (iswctype(_c,_ALPHA))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswupper(_c) (iswctype(_c,ਉੱਤਲਾ_3))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswlower(_c) (iswctype(_c,ਹੇਠਲਾ_2))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswdigit(_c) (iswctype(_c,_DIGIT))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswxdigit(_c) (iswctype(_c,_HEX))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswspace(_c) (iswctype(_c,_SPACE))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswpunct(_c) (iswctype(_c,_PUNCT))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswcntrl(_c) (iswctype(_c,_CONTROL))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswascii(_c) ((ਬਿਨਾਨਿਸ਼ਾਨੀ)(_c) < 0x80)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ isleadbyte(c) (__pctype_func()[(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ)(c)] & _LEADBYTE)
#ਨਹੀਂਤਾਂ
  __CRT_INLINE ਪੂਰਨ __cdecl iswalpha(wint_t _C) {ਵਾਪਸ (iswctype(_C,_ALPHA)); }
  __CRT_INLINE ਪੂਰਨ __cdecl iswupper(wint_t _C) {ਵਾਪਸ (iswctype(_C,ਉੱਤਲਾ_3)); }
  __CRT_INLINE ਪੂਰਨ __cdecl iswlower(wint_t _C) {ਵਾਪਸ (iswctype(_C,ਹੇਠਲਾ_2)); }
  __CRT_INLINE ਪੂਰਨ __cdecl iswdigit(wint_t _C) {ਵਾਪਸ (iswctype(_C,_DIGIT)); }
  __CRT_INLINE ਪੂਰਨ __cdecl iswxdigit(wint_t _C) {ਵਾਪਸ (iswctype(_C,_HEX)); }
  __CRT_INLINE ਪੂਰਨ __cdecl iswspace(wint_t _C) {ਵਾਪਸ (iswctype(_C,_SPACE)); }
  __CRT_INLINE ਪੂਰਨ __cdecl iswpunct(wint_t _C) {ਵਾਪਸ (iswctype(_C,_PUNCT)); }
  __CRT_INLINE ਪੂਰਨ __cdecl iswalnum(wint_t _C) {ਵਾਪਸ (iswctype(_C,_ALPHA|_DIGIT)); }
  __CRT_INLINE ਪੂਰਨ __cdecl iswprint(wint_t _C) {ਵਾਪਸ (iswctype(_C,_BLANK|_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE ਪੂਰਨ __cdecl iswgraph(wint_t _C) {ਵਾਪਸ (iswctype(_C,_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE ਪੂਰਨ __cdecl iswcntrl(wint_t _C) {ਵਾਪਸ (iswctype(_C,_CONTROL)); }
  __CRT_INLINE ਪੂਰਨ __cdecl iswascii(wint_t _C) {ਵਾਪਸ ((ਬਿਨਾਨਿਸ਼ਾਨੀ)(_C) < 0x80); }
  __CRT_INLINE ਪੂਰਨ __cdecl isleadbyte(ਪੂਰਨ _C) {ਵਾਪਸ (__pctype_func()[(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ)(_C)] & _LEADBYTE); }
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ wchar_t wctrans_t;
  wint_t __cdecl towctrans(wint_t,wctrans_t);
  wctrans_t __cdecl wctrans(ਅਚਲ ਅੱਖਰ *);
  wctype_t __cdecl wctype(ਅਚਲ ਅੱਖਰ *);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ pack(ਕੱਢੋ)
#ਜੇ_ਅੰਤ
