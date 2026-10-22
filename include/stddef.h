#اگر_تعریف_نشده _STDDEF_H
#تعریف_کن _STDDEF_H

تعريفنوع __SIZE_TYPE__ اندازه_t;
تعريفنوع __PTRDIFF_TYPE__ ssize_t;
تعريفنوع __WCHAR_TYPE__ wchar_t;
تعريفنوع __PTRDIFF_TYPE__ ptrdiff_t;
تعريفنوع __PTRDIFF_TYPE__ intptr_t;
تعريفنوع __SIZE_TYPE__ uintptr_t;

#إذا __STDC_VERSION__ >= 201112L
تعريفنوع اتحاد { دراز دراز __ll; دراز مزدوج __ld; } max_align_t;
#پایان_اگر

#اگر_تعریف_نشده عدم
#تعریف_کن عدم ((فراغ*)0)
#پایان_اگر

#لغو_تعریف offsetof
#تعریف_کن offsetof(type, فیلد) __builtin_offsetof(type, فیلد)

فراغ *alloca(اندازه_t اندازه);

#پایان_اگر

/* Older glibc require a wint_t from <stddef.h> (when requested
   by __need_wint_t, as otherwise stddef.h isn't allowed to
   define this type).   Note that this must be outside the normal
   _STDDEF_H guard, so that it works even when we've included the file
   already (without requiring wint_t).  Some other libs define _WINT_T
   if they've already provided that type, so we can use that as guard.
   TCC defines __WINT_TYPE__ for us.  */
#إذا defined (__need_wint_t)
#اگر_تعریف_نشده _WINT_T
#تعریف_کن _WINT_T
تعريفنوع __WINT_TYPE__ wint_t;
#پایان_اگر
#لغو_تعریف __need_wint_t
#پایان_اگر
