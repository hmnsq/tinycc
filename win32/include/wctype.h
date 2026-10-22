/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_WCTYPE
#నిర్వచించు _INC_WCTYPE

#నిర్వచితం_కాకపోతే _WIN32
#దోషం Only Win32 లక్ష్యం is supported!
#అయితే_ముగింపు

#అన్తర్భావ <_mingw.h>

#సూచన pack(నెట్టు,_CRT_PACKING)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _CRTIMP
#నిర్వచించు _CRTIMP __declspec(dllimport)
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WCHAR_T_DEFINED
  రకనిర్వచనం గుర్తులేని పొట్టి wchar_t;
#నిర్వచించు _WCHAR_T_DEFINED
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WCTYPE_T_DEFINED
  రకనిర్వచనం గుర్తులేని పొట్టి wint_t;
  రకనిర్వచనం గుర్తులేని పొట్టి wctype_t;
#నిర్వచించు _WCTYPE_T_DEFINED
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే WEOF
#నిర్వచించు WEOF (wint_t)(0xFFFF)
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _CRT_CTYPEDATA_DEFINED
#నిర్వచించు _CRT_CTYPEDATA_DEFINED
#నిర్వచితం_కాకపోతే _CTYPE_DISABLE_MACROS

#నిర్వచితం_కాకపోతే __PCTYPE_FUNC
#నిర్వచించు __PCTYPE_FUNC __pctype_func()
#నిర్వచితమైతే _MSVCRT_
#నిర్వచించు __pctype_func() (_pctype)
#లేకపోతే
#నిర్వచించు __pctype_func() (*_imp___pctype)
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _pctype
#నిర్వచితమైతే _MSVCRT_
  బాహ్య గుర్తులేని పొట్టి *_pctype;
#లేకపోతే
  బాహ్య గుర్తులేని పొట్టి **_imp___pctype;
#నిర్వచించు _pctype (*_imp___pctype)
#అయితే_ముగింపు
#అయితే_ముగింపు

#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _CRT_WCTYPEDATA_DEFINED
#నిర్వచించు _CRT_WCTYPEDATA_DEFINED
#నిర్వచితం_కాకపోతే _CTYPE_DISABLE_MACROS
#నిర్వచితం_కాకపోతే _wctype
#నిర్వచితమైతే _MSVCRT_
  బాహ్య గుర్తులేని పొట్టి *_wctype;
#లేకపోతే
  బాహ్య గుర్తులేని పొట్టి **_imp___wctype;
#నిర్వచించు _wctype (*_imp___wctype)
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _pwctype
#నిర్వచితమైతే _MSVCRT_
  బాహ్య గుర్తులేని పొట్టి *_pwctype;
#లేకపోతే
  బాహ్య గుర్తులేని పొట్టి **_imp___pwctype;
#నిర్వచించు _pwctype (*_imp___pwctype)
#నిర్వచించు __pwctype_func() (*_imp___pwctype)
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు పై_3 0x1
#నిర్వచించు క్రింది_2 0x2
#నిర్వచించు _DIGIT 0x4
#నిర్వచించు _SPACE 0x8

#నిర్వచించు _PUNCT 0x10
#నిర్వచించు _CONTROL 0x20
#నిర్వచించు _BLANK 0x40
#నిర్వచించు _HEX 0x80

#నిర్వచించు _LEADBYTE 0x8000
#నిర్వచించు _ALPHA (0x0100|పై_3|క్రింది_2)

#నిర్వచితం_కాకపోతే _WCTYPE_DEFINED
#నిర్వచించు _WCTYPE_DEFINED

  పూర్ణాంకం __cdecl iswalpha(wint_t);
  పూర్ణాంకం __cdecl iswupper(wint_t);
  పూర్ణాంకం __cdecl iswlower(wint_t);
  పూర్ణాంకం __cdecl iswdigit(wint_t);
  పూర్ణాంకం __cdecl iswxdigit(wint_t);
  పూర్ణాంకం __cdecl iswspace(wint_t);
  పూర్ణాంకం __cdecl iswpunct(wint_t);
  పూర్ణాంకం __cdecl iswalnum(wint_t);
  పూర్ణాంకం __cdecl iswprint(wint_t);
  పూర్ణాంకం __cdecl iswgraph(wint_t);
  పూర్ణాంకం __cdecl iswcntrl(wint_t);
  పూర్ణాంకం __cdecl iswascii(wint_t);
  పూర్ణాంకం __cdecl isleadbyte(పూర్ణాంకం);
  wint_t __cdecl towupper(wint_t);
  wint_t __cdecl towlower(wint_t);
  పూర్ణాంకం __cdecl iswctype(wint_t,wctype_t);
  _CRTIMP పూర్ణాంకం __cdecl __iswcsymf(wint_t);
  _CRTIMP పూర్ణాంకం __cdecl __iswcsym(wint_t);
  పూర్ణాంకం __cdecl is_wctype(wint_t,wctype_t);
#ఒకవేళ (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
పూర్ణాంకం __cdecl isblank(పూర్ణాంకం _C);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WCTYPE_INLINE_DEFINED
#నిర్వచించు _WCTYPE_INLINE_DEFINED
#నిర్వచితం_కాకపోతే __cplusplus
#నిర్వచించు iswalpha(_c) (iswctype(_c,_ALPHA))
#నిర్వచించు iswupper(_c) (iswctype(_c,పై_3))
#నిర్వచించు iswlower(_c) (iswctype(_c,క్రింది_2))
#నిర్వచించు iswdigit(_c) (iswctype(_c,_DIGIT))
#నిర్వచించు iswxdigit(_c) (iswctype(_c,_HEX))
#నిర్వచించు iswspace(_c) (iswctype(_c,_SPACE))
#నిర్వచించు iswpunct(_c) (iswctype(_c,_PUNCT))
#నిర్వచించు iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#నిర్వచించు iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#నిర్వచించు iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#నిర్వచించు iswcntrl(_c) (iswctype(_c,_CONTROL))
#నిర్వచించు iswascii(_c) ((గుర్తులేని)(_c) < 0x80)
#నిర్వచించు isleadbyte(c) (__pctype_func()[(గుర్తులేని అక్షరం)(c)] & _LEADBYTE)
#లేకపోతే
  __CRT_INLINE పూర్ణాంకం __cdecl iswalpha(wint_t _C) {తిరిగి (iswctype(_C,_ALPHA)); }
  __CRT_INLINE పూర్ణాంకం __cdecl iswupper(wint_t _C) {తిరిగి (iswctype(_C,పై_3)); }
  __CRT_INLINE పూర్ణాంకం __cdecl iswlower(wint_t _C) {తిరిగి (iswctype(_C,క్రింది_2)); }
  __CRT_INLINE పూర్ణాంకం __cdecl iswdigit(wint_t _C) {తిరిగి (iswctype(_C,_DIGIT)); }
  __CRT_INLINE పూర్ణాంకం __cdecl iswxdigit(wint_t _C) {తిరిగి (iswctype(_C,_HEX)); }
  __CRT_INLINE పూర్ణాంకం __cdecl iswspace(wint_t _C) {తిరిగి (iswctype(_C,_SPACE)); }
  __CRT_INLINE పూర్ణాంకం __cdecl iswpunct(wint_t _C) {తిరిగి (iswctype(_C,_PUNCT)); }
  __CRT_INLINE పూర్ణాంకం __cdecl iswalnum(wint_t _C) {తిరిగి (iswctype(_C,_ALPHA|_DIGIT)); }
  __CRT_INLINE పూర్ణాంకం __cdecl iswprint(wint_t _C) {తిరిగి (iswctype(_C,_BLANK|_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE పూర్ణాంకం __cdecl iswgraph(wint_t _C) {తిరిగి (iswctype(_C,_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE పూర్ణాంకం __cdecl iswcntrl(wint_t _C) {తిరిగి (iswctype(_C,_CONTROL)); }
  __CRT_INLINE పూర్ణాంకం __cdecl iswascii(wint_t _C) {తిరిగి ((గుర్తులేని)(_C) < 0x80); }
  __CRT_INLINE పూర్ణాంకం __cdecl isleadbyte(పూర్ణాంకం _C) {తిరిగి (__pctype_func()[(గుర్తులేని అక్షరం)(_C)] & _LEADBYTE); }
#అయితే_ముగింపు
#అయితే_ముగింపు

  రకనిర్వచనం wchar_t wctrans_t;
  wint_t __cdecl towctrans(wint_t,wctrans_t);
  wctrans_t __cdecl wctrans(స్థిరరాశి అక్షరం *);
  wctype_t __cdecl wctype(స్థిరరాశి అక్షరం *);

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#సూచన pack(తీయి)
#అయితే_ముగింపు
