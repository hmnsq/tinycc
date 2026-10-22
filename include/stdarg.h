#اگر_تعریف_نشده _STDARG_H
#تعریف_کن _STDARG_H

تعريفنوع __builtin_va_list va_list;
#تعریف_کن va_start __builtin_va_start
#تعریف_کن va_arg __builtin_va_arg
#تعریف_کن va_copy __builtin_va_copy
#تعریف_کن va_end __builtin_va_end

/* fix a buggy dependency on GCC in libio.h */
تعريفنوع va_list __gnuc_va_list;
#تعریف_کن _VA_LIST_DEFINED

#پایان_اگر /* _STDARG_H */
