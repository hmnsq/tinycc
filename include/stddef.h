#నిర్వచితం_కాకపోతే _STDDEF_H
#నిర్వచించు _STDDEF_H

రకనిర్వచనం __SIZE_TYPE__ కొలత_t;
రకనిర్వచనం __PTRDIFF_TYPE__ ssize_t;
రకనిర్వచనం __WCHAR_TYPE__ wchar_t;
రకనిర్వచనం __PTRDIFF_TYPE__ ptrdiff_t;
రకనిర్వచనం __PTRDIFF_TYPE__ intptr_t;
రకనిర్వచనం __SIZE_TYPE__ uintptr_t;

#ఒకవేళ __STDC_VERSION__ >= 201112L
రకనిర్వచనం సంఘం { దీర్ఘ దీర్ఘ __ll; దీర్ఘ ద్విగుణ __ld; } max_align_t;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే ఖాళీ
#నిర్వచించు ఖాళీ ((శూన్య*)0)
#అయితే_ముగింపు

#నిర్వచనం_రద్దు offsetof
#నిర్వచించు offsetof(type, క్షేత్రం) __builtin_offsetof(type, క్షేత్రం)

శూన్య *alloca(కొలత_t కొలత);

#అయితే_ముగింపు

/* Older glibc require a wint_t from <stddef.h> (when requested
   by __need_wint_t, as otherwise stddef.h isn't allowed to
   define this type).   Note that this must be outside the normal
   _STDDEF_H guard, so that it works even when we've included the file
   already (without requiring wint_t).  Some other libs define _WINT_T
   if they've already provided that type, so we can use that as guard.
   TCC defines __WINT_TYPE__ for us.  */
#ఒకవేళ defined (__need_wint_t)
#నిర్వచితం_కాకపోతే _WINT_T
#నిర్వచించు _WINT_T
రకనిర్వచనం __WINT_TYPE__ wint_t;
#అయితే_ముగింపు
#నిర్వచనం_రద్దు __need_wint_t
#అయితే_ముగింపు
