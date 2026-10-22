#که_نه_تعریف_شوی _STDARG_H
#تعریف_کړه _STDARG_H

تعريفنوع __builtin_va_list va_list;
#تعریف_کړه va_start __builtin_va_start
#تعریف_کړه va_arg __builtin_va_arg
#تعریف_کړه va_copy __builtin_va_copy
#تعریف_کړه va_end __builtin_va_end

/* fix a buggy dependency on GCC in libio.h */
تعريفنوع va_list __gnuc_va_list;
#تعریف_کړه _VA_LIST_DEFINED

#د_که_پای /* _STDARG_H */
