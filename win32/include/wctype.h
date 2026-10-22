/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_WCTYPE
#وصف_ڪريو _INC_WCTYPE

#جيڪڏهن_وصف_نه_ٿيل _WIN32
#غلطي Only Win32 هدف is supported!
#جيڪڏهن_پورو

#ضمن <_mingw.h>

#هدايت pack(ڌڪو,_CRT_PACKING)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _CRTIMP
#وصف_ڪريو _CRTIMP __declspec(dllimport)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WCHAR_T_DEFINED
  تعريفنوع بنانشان ننڍو wchar_t;
#وصف_ڪريو _WCHAR_T_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WCTYPE_T_DEFINED
  تعريفنوع بنانشان ننڍو wint_t;
  تعريفنوع بنانشان ننڍو wctype_t;
#وصف_ڪريو _WCTYPE_T_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل WEOF
#وصف_ڪريو WEOF (wint_t)(0xFFFF)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _CRT_CTYPEDATA_DEFINED
#وصف_ڪريو _CRT_CTYPEDATA_DEFINED
#جيڪڏهن_وصف_نه_ٿيل _CTYPE_DISABLE_MACROS

#جيڪڏهن_وصف_نه_ٿيل __PCTYPE_FUNC
#وصف_ڪريو __PCTYPE_FUNC __pctype_func()
#جيڪڏهن_وصف_ٿيل _MSVCRT_
#وصف_ڪريو __pctype_func() (_pctype)
#وإلا
#وصف_ڪريو __pctype_func() (*_imp___pctype)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _pctype
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي بنانشان ننڍو *_pctype;
#وإلا
  خارجي بنانشان ننڍو **_imp___pctype;
#وصف_ڪريو _pctype (*_imp___pctype)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _CRT_WCTYPEDATA_DEFINED
#وصف_ڪريو _CRT_WCTYPEDATA_DEFINED
#جيڪڏهن_وصف_نه_ٿيل _CTYPE_DISABLE_MACROS
#جيڪڏهن_وصف_نه_ٿيل _wctype
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي بنانشان ننڍو *_wctype;
#وإلا
  خارجي بنانشان ننڍو **_imp___wctype;
#وصف_ڪريو _wctype (*_imp___wctype)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _pwctype
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي بنانشان ننڍو *_pwctype;
#وإلا
  خارجي بنانشان ننڍو **_imp___pwctype;
#وصف_ڪريو _pwctype (*_imp___pwctype)
#وصف_ڪريو __pwctype_func() (*_imp___pwctype)
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو مٿانهون_3 0x1
#وصف_ڪريو هيٺاهون_2 0x2
#وصف_ڪريو _DIGIT 0x4
#وصف_ڪريو _SPACE 0x8

#وصف_ڪريو _PUNCT 0x10
#وصف_ڪريو _CONTROL 0x20
#وصف_ڪريو _BLANK 0x40
#وصف_ڪريو _HEX 0x80

#وصف_ڪريو _LEADBYTE 0x8000
#وصف_ڪريو _ALPHA (0x0100|مٿانهون_3|هيٺاهون_2)

#جيڪڏهن_وصف_نه_ٿيل _WCTYPE_DEFINED
#وصف_ڪريو _WCTYPE_DEFINED

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
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WCTYPE_INLINE_DEFINED
#وصف_ڪريو _WCTYPE_INLINE_DEFINED
#جيڪڏهن_وصف_نه_ٿيل __cplusplus
#وصف_ڪريو iswalpha(_c) (iswctype(_c,_ALPHA))
#وصف_ڪريو iswupper(_c) (iswctype(_c,مٿانهون_3))
#وصف_ڪريو iswlower(_c) (iswctype(_c,هيٺاهون_2))
#وصف_ڪريو iswdigit(_c) (iswctype(_c,_DIGIT))
#وصف_ڪريو iswxdigit(_c) (iswctype(_c,_HEX))
#وصف_ڪريو iswspace(_c) (iswctype(_c,_SPACE))
#وصف_ڪريو iswpunct(_c) (iswctype(_c,_PUNCT))
#وصف_ڪريو iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#وصف_ڪريو iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#وصف_ڪريو iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#وصف_ڪريو iswcntrl(_c) (iswctype(_c,_CONTROL))
#وصف_ڪريو iswascii(_c) ((بنانشان)(_c) < 0x80)
#وصف_ڪريو isleadbyte(c) (__pctype_func()[(بنانشان حرف)(c)] & _LEADBYTE)
#وإلا
  __CRT_INLINE صحيح __cdecl iswalpha(wint_t _C) {أرجع (iswctype(_C,_ALPHA)); }
  __CRT_INLINE صحيح __cdecl iswupper(wint_t _C) {أرجع (iswctype(_C,مٿانهون_3)); }
  __CRT_INLINE صحيح __cdecl iswlower(wint_t _C) {أرجع (iswctype(_C,هيٺاهون_2)); }
  __CRT_INLINE صحيح __cdecl iswdigit(wint_t _C) {أرجع (iswctype(_C,_DIGIT)); }
  __CRT_INLINE صحيح __cdecl iswxdigit(wint_t _C) {أرجع (iswctype(_C,_HEX)); }
  __CRT_INLINE صحيح __cdecl iswspace(wint_t _C) {أرجع (iswctype(_C,_SPACE)); }
  __CRT_INLINE صحيح __cdecl iswpunct(wint_t _C) {أرجع (iswctype(_C,_PUNCT)); }
  __CRT_INLINE صحيح __cdecl iswalnum(wint_t _C) {أرجع (iswctype(_C,_ALPHA|_DIGIT)); }
  __CRT_INLINE صحيح __cdecl iswprint(wint_t _C) {أرجع (iswctype(_C,_BLANK|_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE صحيح __cdecl iswgraph(wint_t _C) {أرجع (iswctype(_C,_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE صحيح __cdecl iswcntrl(wint_t _C) {أرجع (iswctype(_C,_CONTROL)); }
  __CRT_INLINE صحيح __cdecl iswascii(wint_t _C) {أرجع ((بنانشان)(_C) < 0x80); }
  __CRT_INLINE صحيح __cdecl isleadbyte(صحيح _C) {أرجع (__pctype_func()[(بنانشان حرف)(_C)] & _LEADBYTE); }
#جيڪڏهن_پورو
#جيڪڏهن_پورو

  تعريفنوع wchar_t wctrans_t;
  wint_t __cdecl towctrans(wint_t,wctrans_t);
  wctrans_t __cdecl wctrans(ثابت حرف *);
  wctype_t __cdecl wctype(ثابت حرف *);

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#هدايت pack(ڪڍو)
#جيڪڏهن_پورو
