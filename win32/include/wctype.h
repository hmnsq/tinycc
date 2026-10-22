/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_WCTYPE
#تعریف_کرو _INC_WCTYPE

#اگر_غیر_تعریف_شدہ _WIN32
#غلطی Only Win32 ہدف is supported!
#اگر_ختم

#شامل <_mingw.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ _CRTIMP
#تعریف_کرو _CRTIMP __declspec(dllimport)
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WCHAR_T_DEFINED
  قسمتعریف غیرعلامتی مختصر wchar_t;
#تعریف_کرو _WCHAR_T_DEFINED
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WCTYPE_T_DEFINED
  قسمتعریف غیرعلامتی مختصر wint_t;
  قسمتعریف غیرعلامتی مختصر wctype_t;
#تعریف_کرو _WCTYPE_T_DEFINED
#اگر_ختم

#اگر_غیر_تعریف_شدہ WEOF
#تعریف_کرو WEOF (wint_t)(0xFFFF)
#اگر_ختم

#اگر_غیر_تعریف_شدہ _CRT_CTYPEDATA_DEFINED
#تعریف_کرو _CRT_CTYPEDATA_DEFINED
#اگر_غیر_تعریف_شدہ _CTYPE_DISABLE_MACROS

#اگر_غیر_تعریف_شدہ __PCTYPE_FUNC
#تعریف_کرو __PCTYPE_FUNC __pctype_func()
#اگر_تعریف_شدہ _MSVCRT_
#تعریف_کرو __pctype_func() (_pctype)
#ورنہ
#تعریف_کرو __pctype_func() (*_imp___pctype)
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _pctype
#اگر_تعریف_شدہ _MSVCRT_
  خارجی غیرعلامتی مختصر *_pctype;
#ورنہ
  خارجی غیرعلامتی مختصر **_imp___pctype;
#تعریف_کرو _pctype (*_imp___pctype)
#اگر_ختم
#اگر_ختم

#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _CRT_WCTYPEDATA_DEFINED
#تعریف_کرو _CRT_WCTYPEDATA_DEFINED
#اگر_غیر_تعریف_شدہ _CTYPE_DISABLE_MACROS
#اگر_غیر_تعریف_شدہ _wctype
#اگر_تعریف_شدہ _MSVCRT_
  خارجی غیرعلامتی مختصر *_wctype;
#ورنہ
  خارجی غیرعلامتی مختصر **_imp___wctype;
#تعریف_کرو _wctype (*_imp___wctype)
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _pwctype
#اگر_تعریف_شدہ _MSVCRT_
  خارجی غیرعلامتی مختصر *_pwctype;
#ورنہ
  خارجی غیرعلامتی مختصر **_imp___pwctype;
#تعریف_کرو _pwctype (*_imp___pwctype)
#تعریف_کرو __pwctype_func() (*_imp___pwctype)
#اگر_ختم
#اگر_ختم
#اگر_ختم
#اگر_ختم

#تعریف_کرو بالائی_3 0x1
#تعریف_کرو زیریں_2 0x2
#تعریف_کرو _DIGIT 0x4
#تعریف_کرو _SPACE 0x8

#تعریف_کرو _PUNCT 0x10
#تعریف_کرو _CONTROL 0x20
#تعریف_کرو _BLANK 0x40
#تعریف_کرو _HEX 0x80

#تعریف_کرو _LEADBYTE 0x8000
#تعریف_کرو _ALPHA (0x0100|بالائی_3|زیریں_2)

#اگر_غیر_تعریف_شدہ _WCTYPE_DEFINED
#تعریف_کرو _WCTYPE_DEFINED

  صحیح __cdecl iswalpha(wint_t);
  صحیح __cdecl iswupper(wint_t);
  صحیح __cdecl iswlower(wint_t);
  صحیح __cdecl iswdigit(wint_t);
  صحیح __cdecl iswxdigit(wint_t);
  صحیح __cdecl iswspace(wint_t);
  صحیح __cdecl iswpunct(wint_t);
  صحیح __cdecl iswalnum(wint_t);
  صحیح __cdecl iswprint(wint_t);
  صحیح __cdecl iswgraph(wint_t);
  صحیح __cdecl iswcntrl(wint_t);
  صحیح __cdecl iswascii(wint_t);
  صحیح __cdecl isleadbyte(صحیح);
  wint_t __cdecl towupper(wint_t);
  wint_t __cdecl towlower(wint_t);
  صحیح __cdecl iswctype(wint_t,wctype_t);
  _CRTIMP صحیح __cdecl __iswcsymf(wint_t);
  _CRTIMP صحیح __cdecl __iswcsym(wint_t);
  صحیح __cdecl is_wctype(wint_t,wctype_t);
#اگر (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
صحیح __cdecl isblank(صحیح _C);
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WCTYPE_INLINE_DEFINED
#تعریف_کرو _WCTYPE_INLINE_DEFINED
#اگر_غیر_تعریف_شدہ __cplusplus
#تعریف_کرو iswalpha(_c) (iswctype(_c,_ALPHA))
#تعریف_کرو iswupper(_c) (iswctype(_c,بالائی_3))
#تعریف_کرو iswlower(_c) (iswctype(_c,زیریں_2))
#تعریف_کرو iswdigit(_c) (iswctype(_c,_DIGIT))
#تعریف_کرو iswxdigit(_c) (iswctype(_c,_HEX))
#تعریف_کرو iswspace(_c) (iswctype(_c,_SPACE))
#تعریف_کرو iswpunct(_c) (iswctype(_c,_PUNCT))
#تعریف_کرو iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#تعریف_کرو iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#تعریف_کرو iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#تعریف_کرو iswcntrl(_c) (iswctype(_c,_CONTROL))
#تعریف_کرو iswascii(_c) ((غیرعلامتی)(_c) < 0x80)
#تعریف_کرو isleadbyte(c) (__pctype_func()[(غیرعلامتی حرف)(c)] & _LEADBYTE)
#ورنہ
  __CRT_INLINE صحیح __cdecl iswalpha(wint_t _C) {واپس (iswctype(_C,_ALPHA)); }
  __CRT_INLINE صحیح __cdecl iswupper(wint_t _C) {واپس (iswctype(_C,بالائی_3)); }
  __CRT_INLINE صحیح __cdecl iswlower(wint_t _C) {واپس (iswctype(_C,زیریں_2)); }
  __CRT_INLINE صحیح __cdecl iswdigit(wint_t _C) {واپس (iswctype(_C,_DIGIT)); }
  __CRT_INLINE صحیح __cdecl iswxdigit(wint_t _C) {واپس (iswctype(_C,_HEX)); }
  __CRT_INLINE صحیح __cdecl iswspace(wint_t _C) {واپس (iswctype(_C,_SPACE)); }
  __CRT_INLINE صحیح __cdecl iswpunct(wint_t _C) {واپس (iswctype(_C,_PUNCT)); }
  __CRT_INLINE صحیح __cdecl iswalnum(wint_t _C) {واپس (iswctype(_C,_ALPHA|_DIGIT)); }
  __CRT_INLINE صحیح __cdecl iswprint(wint_t _C) {واپس (iswctype(_C,_BLANK|_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE صحیح __cdecl iswgraph(wint_t _C) {واپس (iswctype(_C,_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE صحیح __cdecl iswcntrl(wint_t _C) {واپس (iswctype(_C,_CONTROL)); }
  __CRT_INLINE صحیح __cdecl iswascii(wint_t _C) {واپس ((غیرعلامتی)(_C) < 0x80); }
  __CRT_INLINE صحیح __cdecl isleadbyte(صحیح _C) {واپس (__pctype_func()[(غیرعلامتی حرف)(_C)] & _LEADBYTE); }
#اگر_ختم
#اگر_ختم

  قسمتعریف wchar_t wctrans_t;
  wint_t __cdecl towctrans(wint_t,wctrans_t);
  wctrans_t __cdecl wctrans(ثابت حرف *);
  wctype_t __cdecl wctype(ثابت حرف *);

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#ہدایت pack(نکالو)
#اگر_ختم
