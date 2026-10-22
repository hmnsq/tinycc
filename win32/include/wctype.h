/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _INC_WCTYPE
#تعریف_کرو _INC_WCTYPE

#جے_بنا_تعریف _WIN32
#غلطی Only Win32 نشانہ is supported!
#جے_انت

#ضمن <_mingw.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف _CRTIMP
#تعریف_کرو _CRTIMP __declspec(dllimport)
#جے_انت

#جے_بنا_تعریف _WCHAR_T_DEFINED
  تعريفنوع بنانشانی چھوٹا wchar_t;
#تعریف_کرو _WCHAR_T_DEFINED
#جے_انت

#جے_بنا_تعریف _WCTYPE_T_DEFINED
  تعريفنوع بنانشانی چھوٹا wint_t;
  تعريفنوع بنانشانی چھوٹا wctype_t;
#تعریف_کرو _WCTYPE_T_DEFINED
#جے_انت

#جے_بنا_تعریف WEOF
#تعریف_کرو WEOF (wint_t)(0xFFFF)
#جے_انت

#جے_بنا_تعریف _CRT_CTYPEDATA_DEFINED
#تعریف_کرو _CRT_CTYPEDATA_DEFINED
#جے_بنا_تعریف _CTYPE_DISABLE_MACROS

#جے_بنا_تعریف __PCTYPE_FUNC
#تعریف_کرو __PCTYPE_FUNC __pctype_func()
#جے_تعریف_شدہ _MSVCRT_
#تعریف_کرو __pctype_func() (_pctype)
#وإلا
#تعریف_کرو __pctype_func() (*_imp___pctype)
#جے_انت
#جے_انت

#جے_بنا_تعریف _pctype
#جے_تعریف_شدہ _MSVCRT_
  خارجي بنانشانی چھوٹا *_pctype;
#وإلا
  خارجي بنانشانی چھوٹا **_imp___pctype;
#تعریف_کرو _pctype (*_imp___pctype)
#جے_انت
#جے_انت

#جے_انت
#جے_انت

#جے_بنا_تعریف _CRT_WCTYPEDATA_DEFINED
#تعریف_کرو _CRT_WCTYPEDATA_DEFINED
#جے_بنا_تعریف _CTYPE_DISABLE_MACROS
#جے_بنا_تعریف _wctype
#جے_تعریف_شدہ _MSVCRT_
  خارجي بنانشانی چھوٹا *_wctype;
#وإلا
  خارجي بنانشانی چھوٹا **_imp___wctype;
#تعریف_کرو _wctype (*_imp___wctype)
#جے_انت
#جے_انت

#جے_بنا_تعریف _pwctype
#جے_تعریف_شدہ _MSVCRT_
  خارجي بنانشانی چھوٹا *_pwctype;
#وإلا
  خارجي بنانشانی چھوٹا **_imp___pwctype;
#تعریف_کرو _pwctype (*_imp___pwctype)
#تعریف_کرو __pwctype_func() (*_imp___pwctype)
#جے_انت
#جے_انت
#جے_انت
#جے_انت

#تعریف_کرو اتلا_3 0x1
#تعریف_کرو ہیٹھلا_2 0x2
#تعریف_کرو _DIGIT 0x4
#تعریف_کرو _SPACE 0x8

#تعریف_کرو _PUNCT 0x10
#تعریف_کرو _CONTROL 0x20
#تعریف_کرو _BLANK 0x40
#تعریف_کرو _HEX 0x80

#تعریف_کرو _LEADBYTE 0x8000
#تعریف_کرو _ALPHA (0x0100|اتلا_3|ہیٹھلا_2)

#جے_بنا_تعریف _WCTYPE_DEFINED
#تعریف_کرو _WCTYPE_DEFINED

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
#جے_انت
#جے_انت

#جے_بنا_تعریف _WCTYPE_INLINE_DEFINED
#تعریف_کرو _WCTYPE_INLINE_DEFINED
#جے_بنا_تعریف __cplusplus
#تعریف_کرو iswalpha(_c) (iswctype(_c,_ALPHA))
#تعریف_کرو iswupper(_c) (iswctype(_c,اتلا_3))
#تعریف_کرو iswlower(_c) (iswctype(_c,ہیٹھلا_2))
#تعریف_کرو iswdigit(_c) (iswctype(_c,_DIGIT))
#تعریف_کرو iswxdigit(_c) (iswctype(_c,_HEX))
#تعریف_کرو iswspace(_c) (iswctype(_c,_SPACE))
#تعریف_کرو iswpunct(_c) (iswctype(_c,_PUNCT))
#تعریف_کرو iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#تعریف_کرو iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#تعریف_کرو iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#تعریف_کرو iswcntrl(_c) (iswctype(_c,_CONTROL))
#تعریف_کرو iswascii(_c) ((بنانشانی)(_c) < 0x80)
#تعریف_کرو isleadbyte(c) (__pctype_func()[(بنانشانی حرف)(c)] & _LEADBYTE)
#وإلا
  __CRT_INLINE صحيح __cdecl iswalpha(wint_t _C) {أرجع (iswctype(_C,_ALPHA)); }
  __CRT_INLINE صحيح __cdecl iswupper(wint_t _C) {أرجع (iswctype(_C,اتلا_3)); }
  __CRT_INLINE صحيح __cdecl iswlower(wint_t _C) {أرجع (iswctype(_C,ہیٹھلا_2)); }
  __CRT_INLINE صحيح __cdecl iswdigit(wint_t _C) {أرجع (iswctype(_C,_DIGIT)); }
  __CRT_INLINE صحيح __cdecl iswxdigit(wint_t _C) {أرجع (iswctype(_C,_HEX)); }
  __CRT_INLINE صحيح __cdecl iswspace(wint_t _C) {أرجع (iswctype(_C,_SPACE)); }
  __CRT_INLINE صحيح __cdecl iswpunct(wint_t _C) {أرجع (iswctype(_C,_PUNCT)); }
  __CRT_INLINE صحيح __cdecl iswalnum(wint_t _C) {أرجع (iswctype(_C,_ALPHA|_DIGIT)); }
  __CRT_INLINE صحيح __cdecl iswprint(wint_t _C) {أرجع (iswctype(_C,_BLANK|_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE صحيح __cdecl iswgraph(wint_t _C) {أرجع (iswctype(_C,_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE صحيح __cdecl iswcntrl(wint_t _C) {أرجع (iswctype(_C,_CONTROL)); }
  __CRT_INLINE صحيح __cdecl iswascii(wint_t _C) {أرجع ((بنانشانی)(_C) < 0x80); }
  __CRT_INLINE صحيح __cdecl isleadbyte(صحيح _C) {أرجع (__pctype_func()[(بنانشانی حرف)(_C)] & _LEADBYTE); }
#جے_انت
#جے_انت

  تعريفنوع wchar_t wctrans_t;
  wint_t __cdecl towctrans(wint_t,wctrans_t);
  wctrans_t __cdecl wctrans(ثابت حرف *);
  wctype_t __cdecl wctype(ثابت حرف *);

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#ہدایت pack(نکالو)
#جے_انت
