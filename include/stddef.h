#جيڪڏهن_وصف_نه_ٿيل _STDDEF_H
#وصف_ڪريو _STDDEF_H

تعريفنوع __SIZE_TYPE__ سائيز_t;
تعريفنوع __PTRDIFF_TYPE__ ssize_t;
تعريفنوع __WCHAR_TYPE__ wchar_t;
تعريفنوع __PTRDIFF_TYPE__ ptrdiff_t;
تعريفنوع __PTRDIFF_TYPE__ intptr_t;
تعريفنوع __SIZE_TYPE__ uintptr_t;

#إذا __STDC_VERSION__ >= 201112L
تعريفنوع اتحاد { ڊگهو ڊگهو __ll; ڊگهو مزدوج __ld; } max_align_t;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل عدم
#وصف_ڪريو عدم ((فراغ*)0)
#جيڪڏهن_پورو

#وصف_رد offsetof
#وصف_ڪريو offsetof(type, ميدان) __builtin_offsetof(type, ميدان)

فراغ *alloca(سائيز_t سائيز);

#جيڪڏهن_پورو

/* Older glibc require a wint_t from <stddef.h> (when requested
   by __need_wint_t, as otherwise stddef.h isn't allowed to
   define this type).   Note that this must be outside the normal
   _STDDEF_H guard, so that it works even when we've included the file
   already (without requiring wint_t).  Some other libs define _WINT_T
   if they've already provided that type, so we can use that as guard.
   TCC defines __WINT_TYPE__ for us.  */
#إذا defined (__need_wint_t)
#جيڪڏهن_وصف_نه_ٿيل _WINT_T
#وصف_ڪريو _WINT_T
تعريفنوع __WINT_TYPE__ wint_t;
#جيڪڏهن_پورو
#وصف_رد __need_wint_t
#جيڪڏهن_پورو
