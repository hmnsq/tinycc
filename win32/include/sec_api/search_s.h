/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف INC_تلاش_S
#تعریف_کرو INC_تلاش_S

#ضمن <search.h>

#إذا defined(MINGW_HAS_SECURE_API)

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

  _CRTIMP فراغ *__cdecl _lfind_s(ثابت فراغ *کلید_2,ثابت فراغ *ادھار_3,بنانشانی صحيح *عدد_دا_Elements,ناپ_t ناپ_دا_Elements,صحيح (__cdecl *_PtFuncCompare)(فراغ *,ثابت فراغ *,ثابت فراغ *),فراغ *_Context);
  _CRTIMP فراغ *__cdecl _lsearch_s(ثابت فراغ *کلید_2,فراغ *ادھار_3,بنانشانی صحيح *عدد_دا_Elements,ناپ_t ناپ_دا_Elements,صحيح (__cdecl *_PtFuncCompare)(فراغ *,ثابت فراغ *,ثابت فراغ *),فراغ *_Context);

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#جے_انت
#جے_انت
