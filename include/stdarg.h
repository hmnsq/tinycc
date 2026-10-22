#اگر_غیر_تعریف_شدہ _STDARG_H
#تعریف_کرو _STDARG_H

قسمتعریف __builtin_va_list va_list;
#تعریف_کرو va_start __builtin_va_start
#تعریف_کرو va_arg __builtin_va_arg
#تعریف_کرو va_copy __builtin_va_copy
#تعریف_کرو va_end __builtin_va_end

/* fix a buggy dependency on GCC in libio.h */
قسمتعریف va_list __gnuc_va_list;
#تعریف_کرو _VA_LIST_DEFINED

#اگر_ختم /* _STDARG_H */
