#جے_بنا_تعریف _STDDEF_H
#تعریف_کرو _STDDEF_H

تعريفنوع __SIZE_TYPE__ ناپ_t;
تعريفنوع __PTRDIFF_TYPE__ ssize_t;
تعريفنوع __WCHAR_TYPE__ wchar_t;
تعريفنوع __PTRDIFF_TYPE__ ptrdiff_t;
تعريفنوع __PTRDIFF_TYPE__ intptr_t;
تعريفنوع __SIZE_TYPE__ uintptr_t;

#إذا __STDC_VERSION__ >= 201112L
تعريفنوع اتحاد { لما لما __ll; لما مزدوج __ld; } max_align_t;
#جے_انت

#جے_بنا_تعریف عدم
#تعریف_کرو عدم ((فراغ*)0)
#جے_انت

#تعریف_رد offsetof
#تعریف_کرو offsetof(type, میدان) __builtin_offsetof(type, میدان)

فراغ *alloca(ناپ_t ناپ);

#جے_انت

/* Older glibc require a wint_t from <stddef.h> (when requested
   by __need_wint_t, as otherwise stddef.h isn't allowed to
   define this type).   Note that this must be outside the normal
   _STDDEF_H guard, so that it works even when we've included the file
   already (without requiring wint_t).  Some other libs define _WINT_T
   if they've already provided that type, so we can use that as guard.
   TCC defines __WINT_TYPE__ for us.  */
#إذا defined (__need_wint_t)
#جے_بنا_تعریف _WINT_T
#تعریف_کرو _WINT_T
تعريفنوع __WINT_TYPE__ wint_t;
#جے_انت
#تعریف_رد __need_wint_t
#جے_انت
