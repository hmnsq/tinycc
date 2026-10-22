/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ INC_تلاش_S
#تعریف_کرو INC_تلاش_S

#شامل <search.h>

#اگر defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

  _CRTIMP خالی *__cdecl _lfind_s(ثابت خالی *کلید_2,ثابت خالی *بنیاد_3,غیرعلامتی صحیح *عدد_کا_Elements,سائز_t سائز_کا_Elements,صحیح (__cdecl *_PtFuncCompare)(خالی *,ثابت خالی *,ثابت خالی *),خالی *_Context);
  _CRTIMP خالی *__cdecl _lsearch_s(ثابت خالی *کلید_2,خالی *بنیاد_3,غیرعلامتی صحیح *عدد_کا_Elements,سائز_t سائز_کا_Elements,صحیح (__cdecl *_PtFuncCompare)(خالی *,ثابت خالی *,ثابت خالی *),خالی *_Context);

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#اگر_ختم
#اگر_ختم
