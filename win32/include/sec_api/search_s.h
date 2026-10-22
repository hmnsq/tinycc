/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده INC_جستجو_S
#تعریف_کن INC_جستجو_S

#ضمن <search.h>

#إذا defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

  _CRTIMP فراغ *__cdecl _lfind_s(ثابت فراغ *کلید_2,ثابت فراغ *پایه_3,بیعلامت صحيح *رقم_از_Elements,اندازه_t اندازه_از_Elements,صحيح (__cdecl *_PtFuncCompare)(فراغ *,ثابت فراغ *,ثابت فراغ *),فراغ *_Context);
  _CRTIMP فراغ *__cdecl _lsearch_s(ثابت فراغ *کلید_2,فراغ *پایه_3,بیعلامت صحيح *رقم_از_Elements,اندازه_t اندازه_از_Elements,صحيح (__cdecl *_PtFuncCompare)(فراغ *,ثابت فراغ *,ثابت فراغ *),فراغ *_Context);

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#پایان_اگر
#پایان_اگر
