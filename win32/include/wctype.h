/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_WCTYPE
#घोषणा _INC_WCTYPE

#अगर_अघोषित _WIN32
#त्रुटि Only Win32 target is supported!
#पूर्ण_अगर

#समावेश <_mingw.h>

#आशय pack(धकेलो,_CRT_PACKING)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित _CRTIMP
#घोषणा _CRTIMP __declspec(dllimport)
#पूर्ण_अगर

#अगर_अघोषित _WCHAR_T_DEFINED
  प्रकार अचिन्हित लघु ब_अक्षर_प्रकार;
#घोषणा _WCHAR_T_DEFINED
#पूर्ण_अगर

#अगर_अघोषित _WCTYPE_T_DEFINED
  प्रकार अचिन्हित लघु wint_t;
  प्रकार अचिन्हित लघु wctype_t;
#घोषणा _WCTYPE_T_DEFINED
#पूर्ण_अगर

#अगर_अघोषित WEOF
#घोषणा WEOF (wint_t)(0xFFFF)
#पूर्ण_अगर

#अगर_अघोषित _CRT_CTYPEDATA_DEFINED
#घोषणा _CRT_CTYPEDATA_DEFINED
#अगर_अघोषित _CTYPE_DISABLE_MACROS

#अगर_अघोषित __PCTYPE_FUNC
#घोषणा __PCTYPE_FUNC __pctype_func()
#अगर_घोषित _MSVCRT_
#घोषणा __pctype_func() (_pctype)
#अन्यथा
#घोषणा __pctype_func() (*_imp___pctype)
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _pctype
#अगर_घोषित _MSVCRT_
  बाह्य अचिन्हित लघु *_pctype;
#अन्यथा
  बाह्य अचिन्हित लघु **_imp___pctype;
#घोषणा _pctype (*_imp___pctype)
#पूर्ण_अगर
#पूर्ण_अगर

#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _CRT_WCTYPEDATA_DEFINED
#घोषणा _CRT_WCTYPEDATA_DEFINED
#अगर_अघोषित _CTYPE_DISABLE_MACROS
#अगर_अघोषित _wctype
#अगर_घोषित _MSVCRT_
  बाह्य अचिन्हित लघु *_wctype;
#अन्यथा
  बाह्य अचिन्हित लघु **_imp___wctype;
#घोषणा _wctype (*_imp___wctype)
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _pwctype
#अगर_घोषित _MSVCRT_
  बाह्य अचिन्हित लघु *_pwctype;
#अन्यथा
  बाह्य अचिन्हित लघु **_imp___pwctype;
#घोषणा _pwctype (*_imp___pwctype)
#घोषणा __pwctype_func() (*_imp___pwctype)
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा _UPPER 0x1
#घोषणा _LOWER 0x2
#घोषणा _DIGIT 0x4
#घोषणा _SPACE 0x8

#घोषणा _PUNCT 0x10
#घोषणा _CONTROL 0x20
#घोषणा _BLANK 0x40
#घोषणा _HEX 0x80

#घोषणा _LEADBYTE 0x8000
#घोषणा _ALPHA (0x0100|_UPPER|_LOWER)

#अगर_अघोषित _WCTYPE_DEFINED
#घोषणा _WCTYPE_DEFINED

  पूर्णांक __cdecl iswalpha(wint_t);
  पूर्णांक __cdecl iswupper(wint_t);
  पूर्णांक __cdecl iswlower(wint_t);
  पूर्णांक __cdecl iswdigit(wint_t);
  पूर्णांक __cdecl iswxdigit(wint_t);
  पूर्णांक __cdecl iswspace(wint_t);
  पूर्णांक __cdecl iswpunct(wint_t);
  पूर्णांक __cdecl iswalnum(wint_t);
  पूर्णांक __cdecl iswprint(wint_t);
  पूर्णांक __cdecl iswgraph(wint_t);
  पूर्णांक __cdecl iswcntrl(wint_t);
  पूर्णांक __cdecl iswascii(wint_t);
  पूर्णांक __cdecl isleadbyte(पूर्णांक);
  wint_t __cdecl towupper(wint_t);
  wint_t __cdecl towlower(wint_t);
  पूर्णांक __cdecl iswctype(wint_t,wctype_t);
  _CRTIMP पूर्णांक __cdecl __iswcsymf(wint_t);
  _CRTIMP पूर्णांक __cdecl __iswcsym(wint_t);
  पूर्णांक __cdecl is_wctype(wint_t,wctype_t);
#अगर (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
पूर्णांक __cdecl isblank(पूर्णांक _C);
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _WCTYPE_INLINE_DEFINED
#घोषणा _WCTYPE_INLINE_DEFINED
#अगर_अघोषित __cplusplus
#घोषणा iswalpha(_c) (iswctype(_c,_ALPHA))
#घोषणा iswupper(_c) (iswctype(_c,_UPPER))
#घोषणा iswlower(_c) (iswctype(_c,_LOWER))
#घोषणा iswdigit(_c) (iswctype(_c,_DIGIT))
#घोषणा iswxdigit(_c) (iswctype(_c,_HEX))
#घोषणा iswspace(_c) (iswctype(_c,_SPACE))
#घोषणा iswpunct(_c) (iswctype(_c,_PUNCT))
#घोषणा iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#घोषणा iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#घोषणा iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#घोषणा iswcntrl(_c) (iswctype(_c,_CONTROL))
#घोषणा iswascii(_c) ((अचिन्हित)(_c) < 0x80)
#घोषणा isleadbyte(c) (__pctype_func()[(अचिन्हित अक्षर)(c)] & _LEADBYTE)
#अन्यथा
  __CRT_INLINE पूर्णांक __cdecl iswalpha(wint_t _C) {वापस (iswctype(_C,_ALPHA)); }
  __CRT_INLINE पूर्णांक __cdecl iswupper(wint_t _C) {वापस (iswctype(_C,_UPPER)); }
  __CRT_INLINE पूर्णांक __cdecl iswlower(wint_t _C) {वापस (iswctype(_C,_LOWER)); }
  __CRT_INLINE पूर्णांक __cdecl iswdigit(wint_t _C) {वापस (iswctype(_C,_DIGIT)); }
  __CRT_INLINE पूर्णांक __cdecl iswxdigit(wint_t _C) {वापस (iswctype(_C,_HEX)); }
  __CRT_INLINE पूर्णांक __cdecl iswspace(wint_t _C) {वापस (iswctype(_C,_SPACE)); }
  __CRT_INLINE पूर्णांक __cdecl iswpunct(wint_t _C) {वापस (iswctype(_C,_PUNCT)); }
  __CRT_INLINE पूर्णांक __cdecl iswalnum(wint_t _C) {वापस (iswctype(_C,_ALPHA|_DIGIT)); }
  __CRT_INLINE पूर्णांक __cdecl iswprint(wint_t _C) {वापस (iswctype(_C,_BLANK|_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE पूर्णांक __cdecl iswgraph(wint_t _C) {वापस (iswctype(_C,_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE पूर्णांक __cdecl iswcntrl(wint_t _C) {वापस (iswctype(_C,_CONTROL)); }
  __CRT_INLINE पूर्णांक __cdecl iswascii(wint_t _C) {वापस ((अचिन्हित)(_C) < 0x80); }
  __CRT_INLINE पूर्णांक __cdecl isleadbyte(पूर्णांक _C) {वापस (__pctype_func()[(अचिन्हित अक्षर)(_C)] & _LEADBYTE); }
#पूर्ण_अगर
#पूर्ण_अगर

  प्रकार ब_अक्षर_प्रकार wctrans_t;
  wint_t __cdecl towctrans(wint_t,wctrans_t);
  wctrans_t __cdecl wctrans(स्थिर अक्षर *);
  wctype_t __cdecl wctype(स्थिर अक्षर *);

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#आशय pack(निकालो)
#पूर्ण_अगर
