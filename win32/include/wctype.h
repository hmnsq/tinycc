/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_WCTYPE
#تعریف_کړه _INC_WCTYPE

#که_نه_تعریف_شوی _WIN32
#تېروتنه Only Win32 موخه is supported!
#د_که_پای

#ضمن <_mingw.h>

#لارښوونه pack(ټېل,_CRT_PACKING)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی _CRTIMP
#تعریف_کړه _CRTIMP __declspec(dllimport)
#د_که_پای

#که_نه_تعریف_شوی _WCHAR_T_DEFINED
  تعريفنوع بینښه لنډ wchar_t;
#تعریف_کړه _WCHAR_T_DEFINED
#د_که_پای

#که_نه_تعریف_شوی _WCTYPE_T_DEFINED
  تعريفنوع بینښه لنډ wint_t;
  تعريفنوع بینښه لنډ wctype_t;
#تعریف_کړه _WCTYPE_T_DEFINED
#د_که_پای

#که_نه_تعریف_شوی WEOF
#تعریف_کړه WEOF (wint_t)(0xFFFF)
#د_که_پای

#که_نه_تعریف_شوی _CRT_CTYPEDATA_DEFINED
#تعریف_کړه _CRT_CTYPEDATA_DEFINED
#که_نه_تعریف_شوی _CTYPE_DISABLE_MACROS

#که_نه_تعریف_شوی __PCTYPE_FUNC
#تعریف_کړه __PCTYPE_FUNC __pctype_func()
#که_تعریف_شوی _MSVCRT_
#تعریف_کړه __pctype_func() (_pctype)
#وإلا
#تعریف_کړه __pctype_func() (*_imp___pctype)
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _pctype
#که_تعریف_شوی _MSVCRT_
  خارجي بینښه لنډ *_pctype;
#وإلا
  خارجي بینښه لنډ **_imp___pctype;
#تعریف_کړه _pctype (*_imp___pctype)
#د_که_پای
#د_که_پای

#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _CRT_WCTYPEDATA_DEFINED
#تعریف_کړه _CRT_WCTYPEDATA_DEFINED
#که_نه_تعریف_شوی _CTYPE_DISABLE_MACROS
#که_نه_تعریف_شوی _wctype
#که_تعریف_شوی _MSVCRT_
  خارجي بینښه لنډ *_wctype;
#وإلا
  خارجي بینښه لنډ **_imp___wctype;
#تعریف_کړه _wctype (*_imp___wctype)
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _pwctype
#که_تعریف_شوی _MSVCRT_
  خارجي بینښه لنډ *_pwctype;
#وإلا
  خارجي بینښه لنډ **_imp___pwctype;
#تعریف_کړه _pwctype (*_imp___pwctype)
#تعریف_کړه __pwctype_func() (*_imp___pwctype)
#د_که_پای
#د_که_پای
#د_که_پای
#د_که_پای

#تعریف_کړه پاسنی_3 0x1
#تعریف_کړه ښکتنی_2 0x2
#تعریف_کړه _DIGIT 0x4
#تعریف_کړه _SPACE 0x8

#تعریف_کړه _PUNCT 0x10
#تعریف_کړه _CONTROL 0x20
#تعریف_کړه _BLANK 0x40
#تعریف_کړه _HEX 0x80

#تعریف_کړه _LEADBYTE 0x8000
#تعریف_کړه _ALPHA (0x0100|پاسنی_3|ښکتنی_2)

#که_نه_تعریف_شوی _WCTYPE_DEFINED
#تعریف_کړه _WCTYPE_DEFINED

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
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _WCTYPE_INLINE_DEFINED
#تعریف_کړه _WCTYPE_INLINE_DEFINED
#که_نه_تعریف_شوی __cplusplus
#تعریف_کړه iswalpha(_c) (iswctype(_c,_ALPHA))
#تعریف_کړه iswupper(_c) (iswctype(_c,پاسنی_3))
#تعریف_کړه iswlower(_c) (iswctype(_c,ښکتنی_2))
#تعریف_کړه iswdigit(_c) (iswctype(_c,_DIGIT))
#تعریف_کړه iswxdigit(_c) (iswctype(_c,_HEX))
#تعریف_کړه iswspace(_c) (iswctype(_c,_SPACE))
#تعریف_کړه iswpunct(_c) (iswctype(_c,_PUNCT))
#تعریف_کړه iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#تعریف_کړه iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#تعریف_کړه iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#تعریف_کړه iswcntrl(_c) (iswctype(_c,_CONTROL))
#تعریف_کړه iswascii(_c) ((بینښه)(_c) < 0x80)
#تعریف_کړه isleadbyte(c) (__pctype_func()[(بینښه حرف)(c)] & _LEADBYTE)
#وإلا
  __CRT_INLINE صحيح __cdecl iswalpha(wint_t _C) {أرجع (iswctype(_C,_ALPHA)); }
  __CRT_INLINE صحيح __cdecl iswupper(wint_t _C) {أرجع (iswctype(_C,پاسنی_3)); }
  __CRT_INLINE صحيح __cdecl iswlower(wint_t _C) {أرجع (iswctype(_C,ښکتنی_2)); }
  __CRT_INLINE صحيح __cdecl iswdigit(wint_t _C) {أرجع (iswctype(_C,_DIGIT)); }
  __CRT_INLINE صحيح __cdecl iswxdigit(wint_t _C) {أرجع (iswctype(_C,_HEX)); }
  __CRT_INLINE صحيح __cdecl iswspace(wint_t _C) {أرجع (iswctype(_C,_SPACE)); }
  __CRT_INLINE صحيح __cdecl iswpunct(wint_t _C) {أرجع (iswctype(_C,_PUNCT)); }
  __CRT_INLINE صحيح __cdecl iswalnum(wint_t _C) {أرجع (iswctype(_C,_ALPHA|_DIGIT)); }
  __CRT_INLINE صحيح __cdecl iswprint(wint_t _C) {أرجع (iswctype(_C,_BLANK|_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE صحيح __cdecl iswgraph(wint_t _C) {أرجع (iswctype(_C,_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE صحيح __cdecl iswcntrl(wint_t _C) {أرجع (iswctype(_C,_CONTROL)); }
  __CRT_INLINE صحيح __cdecl iswascii(wint_t _C) {أرجع ((بینښه)(_C) < 0x80); }
  __CRT_INLINE صحيح __cdecl isleadbyte(صحيح _C) {أرجع (__pctype_func()[(بینښه حرف)(_C)] & _LEADBYTE); }
#د_که_پای
#د_که_پای

  تعريفنوع wchar_t wctrans_t;
  wint_t __cdecl towctrans(wint_t,wctrans_t);
  wctrans_t __cdecl wctrans(ثابت حرف *);
  wctype_t __cdecl wctype(ثابت حرف *);

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#لارښوونه pack(راوباسه)
#د_که_پای
