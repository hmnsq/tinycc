#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _STDDEF_H
#ವ್ಯಾಖ್ಯಾನಿಸು _STDDEF_H

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __SIZE_TYPE__ ಗಾತ್ರ_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __PTRDIFF_TYPE__ ssize_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __WCHAR_TYPE__ wchar_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __PTRDIFF_TYPE__ ptrdiff_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __PTRDIFF_TYPE__ intptr_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __SIZE_TYPE__ uintptr_t;

#ಆದರೆ __STDC_VERSION__ >= 201112L
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಒಕ್ಕೂಟ { ದೀರ್ಘ ದೀರ್ಘ __ll; ದೀರ್ಘ ದ್ವಿಗುಣ __ld; } max_align_t;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ಖಾಲಿ
#ವ್ಯಾಖ್ಯಾನಿಸು ಖಾಲಿ ((ಶೂನ್ಯ*)0)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು offsetof
#ವ್ಯಾಖ್ಯಾನಿಸು offsetof(type, ಕ್ಷೇತ್ರ) __builtin_offsetof(type, ಕ್ಷೇತ್ರ)

ಶೂನ್ಯ *alloca(ಗಾತ್ರ_t ಗಾತ್ರ_2);

#ಆದರೆ_ಅಂತ್ಯ

/* Older glibc require a wint_t from <stddef.h> (when requested
   by __need_wint_t, as otherwise stddef.h isn't allowed to
   define this type).   Note that this must be outside the normal
   _STDDEF_H guard, so that it works even when we've included the file
   already (without requiring wint_t).  Some other libs define _WINT_T
   if they've already provided that type, so we can use that as guard.
   TCC defines __WINT_TYPE__ for us.  */
#ಆದರೆ defined (__need_wint_t)
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WINT_T
#ವ್ಯಾಖ್ಯಾನಿಸು _WINT_T
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __WINT_TYPE__ wint_t;
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು __need_wint_t
#ಆದರೆ_ಅಂತ್ಯ
