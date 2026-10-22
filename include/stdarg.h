#यदि_अपरिभाषितम् _STDARG_H
#परिभाषय _STDARG_H

प्रकारनिर्देश __builtin_va_list va_list;
#परिभाषय va_start __builtin_va_start
#परिभाषय va_arg __builtin_va_arg
#परिभाषय va_copy __builtin_va_copy
#परिभाषय va_end __builtin_va_end

/* fix a buggy dependency on GCC in libio.h */
प्रकारनिर्देश va_list __gnuc_va_list;
#परिभाषय _VA_LIST_DEFINED

#यदि_अन्तः /* _STDARG_H */
