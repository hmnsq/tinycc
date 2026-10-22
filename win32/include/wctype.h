/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_WCTYPE
#تعریف_کن _INC_WCTYPE

#اگر_تعریف_نشده _WIN32
#خطا Only Win32 هدف is supported!
#پایان_اگر

#ضمن <_mingw.h>

#رهنمود pack(افزودن,_CRT_PACKING)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده _CRTIMP
#تعریف_کن _CRTIMP __declspec(dllimport)
#پایان_اگر

#اگر_تعریف_نشده _WCHAR_T_DEFINED
  تعريفنوع بیعلامت کوتاه wchar_t;
#تعریف_کن _WCHAR_T_DEFINED
#پایان_اگر

#اگر_تعریف_نشده _WCTYPE_T_DEFINED
  تعريفنوع بیعلامت کوتاه wint_t;
  تعريفنوع بیعلامت کوتاه wctype_t;
#تعریف_کن _WCTYPE_T_DEFINED
#پایان_اگر

#اگر_تعریف_نشده WEOF
#تعریف_کن WEOF (wint_t)(0xFFFF)
#پایان_اگر

#اگر_تعریف_نشده _CRT_CTYPEDATA_DEFINED
#تعریف_کن _CRT_CTYPEDATA_DEFINED
#اگر_تعریف_نشده _CTYPE_DISABLE_MACROS

#اگر_تعریف_نشده __PCTYPE_FUNC
#تعریف_کن __PCTYPE_FUNC __pctype_func()
#اگر_تعریف_شده _MSVCRT_
#تعریف_کن __pctype_func() (_pctype)
#وإلا
#تعریف_کن __pctype_func() (*_imp___pctype)
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _pctype
#اگر_تعریف_شده _MSVCRT_
  خارجي بیعلامت کوتاه *_pctype;
#وإلا
  خارجي بیعلامت کوتاه **_imp___pctype;
#تعریف_کن _pctype (*_imp___pctype)
#پایان_اگر
#پایان_اگر

#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _CRT_WCTYPEDATA_DEFINED
#تعریف_کن _CRT_WCTYPEDATA_DEFINED
#اگر_تعریف_نشده _CTYPE_DISABLE_MACROS
#اگر_تعریف_نشده _wctype
#اگر_تعریف_شده _MSVCRT_
  خارجي بیعلامت کوتاه *_wctype;
#وإلا
  خارجي بیعلامت کوتاه **_imp___wctype;
#تعریف_کن _wctype (*_imp___wctype)
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _pwctype
#اگر_تعریف_شده _MSVCRT_
  خارجي بیعلامت کوتاه *_pwctype;
#وإلا
  خارجي بیعلامت کوتاه **_imp___pwctype;
#تعریف_کن _pwctype (*_imp___pwctype)
#تعریف_کن __pwctype_func() (*_imp___pwctype)
#پایان_اگر
#پایان_اگر
#پایان_اگر
#پایان_اگر

#تعریف_کن فوقانی_3 0x1
#تعریف_کن پایینی_2 0x2
#تعریف_کن _DIGIT 0x4
#تعریف_کن _SPACE 0x8

#تعریف_کن _PUNCT 0x10
#تعریف_کن _CONTROL 0x20
#تعریف_کن _BLANK 0x40
#تعریف_کن _HEX 0x80

#تعریف_کن _LEADBYTE 0x8000
#تعریف_کن _ALPHA (0x0100|فوقانی_3|پایینی_2)

#اگر_تعریف_نشده _WCTYPE_DEFINED
#تعریف_کن _WCTYPE_DEFINED

  صحيح __cdecl iswalpha(wint_t);
  صحيح __cdecl iswupper(wint_t);
  صحيح __cdecl iswlower(wint_t);
  صحيح __cdecl iswdigit(wint_t);
  صحيح __cdecl iswxdigit(wint_t);
  صحيح __cdecl iswspace(wint_t);
  صحيح __cdecl iswpunct(wint_t);
  صحيح __cdecl iswalnum(wint_t);
  صحيح __cdecl iswprint(wint_t);
  صحيح __cdecl iswgraph(wint_t);
  صحيح __cdecl iswcntrl(wint_t);
  صحيح __cdecl iswascii(wint_t);
  صحيح __cdecl isleadbyte(صحيح);
  wint_t __cdecl towupper(wint_t);
  wint_t __cdecl towlower(wint_t);
  صحيح __cdecl iswctype(wint_t,wctype_t);
  _CRTIMP صحيح __cdecl __iswcsymf(wint_t);
  _CRTIMP صحيح __cdecl __iswcsym(wint_t);
  صحيح __cdecl is_wctype(wint_t,wctype_t);
#إذا (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
صحيح __cdecl isblank(صحيح _C);
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _WCTYPE_INLINE_DEFINED
#تعریف_کن _WCTYPE_INLINE_DEFINED
#اگر_تعریف_نشده __cplusplus
#تعریف_کن iswalpha(_c) (iswctype(_c,_ALPHA))
#تعریف_کن iswupper(_c) (iswctype(_c,فوقانی_3))
#تعریف_کن iswlower(_c) (iswctype(_c,پایینی_2))
#تعریف_کن iswdigit(_c) (iswctype(_c,_DIGIT))
#تعریف_کن iswxdigit(_c) (iswctype(_c,_HEX))
#تعریف_کن iswspace(_c) (iswctype(_c,_SPACE))
#تعریف_کن iswpunct(_c) (iswctype(_c,_PUNCT))
#تعریف_کن iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#تعریف_کن iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#تعریف_کن iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#تعریف_کن iswcntrl(_c) (iswctype(_c,_CONTROL))
#تعریف_کن iswascii(_c) ((بیعلامت)(_c) < 0x80)
#تعریف_کن isleadbyte(c) (__pctype_func()[(بیعلامت حرف)(c)] & _LEADBYTE)
#وإلا
  __CRT_INLINE صحيح __cdecl iswalpha(wint_t _C) {أرجع (iswctype(_C,_ALPHA)); }
  __CRT_INLINE صحيح __cdecl iswupper(wint_t _C) {أرجع (iswctype(_C,فوقانی_3)); }
  __CRT_INLINE صحيح __cdecl iswlower(wint_t _C) {أرجع (iswctype(_C,پایینی_2)); }
  __CRT_INLINE صحيح __cdecl iswdigit(wint_t _C) {أرجع (iswctype(_C,_DIGIT)); }
  __CRT_INLINE صحيح __cdecl iswxdigit(wint_t _C) {أرجع (iswctype(_C,_HEX)); }
  __CRT_INLINE صحيح __cdecl iswspace(wint_t _C) {أرجع (iswctype(_C,_SPACE)); }
  __CRT_INLINE صحيح __cdecl iswpunct(wint_t _C) {أرجع (iswctype(_C,_PUNCT)); }
  __CRT_INLINE صحيح __cdecl iswalnum(wint_t _C) {أرجع (iswctype(_C,_ALPHA|_DIGIT)); }
  __CRT_INLINE صحيح __cdecl iswprint(wint_t _C) {أرجع (iswctype(_C,_BLANK|_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE صحيح __cdecl iswgraph(wint_t _C) {أرجع (iswctype(_C,_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE صحيح __cdecl iswcntrl(wint_t _C) {أرجع (iswctype(_C,_CONTROL)); }
  __CRT_INLINE صحيح __cdecl iswascii(wint_t _C) {أرجع ((بیعلامت)(_C) < 0x80); }
  __CRT_INLINE صحيح __cdecl isleadbyte(صحيح _C) {أرجع (__pctype_func()[(بیعلامت حرف)(_C)] & _LEADBYTE); }
#پایان_اگر
#پایان_اگر

  تعريفنوع wchar_t wctrans_t;
  wint_t __cdecl towctrans(wint_t,wctrans_t);
  wctrans_t __cdecl wctrans(ثابت حرف *);
  wctype_t __cdecl wctype(ثابت حرف *);

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#رهنمود pack(برداشت)
#پایان_اگر
