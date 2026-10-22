#ifndef _STDARG_H
#define _STDARG_H

प्रकारव्याख्या __builtin_va_list बहु_सूची;
#define बहु_शुरू __builtin_va_start
#define बहु_तर्क __builtin_va_arg
#define va_copy __builtin_va_copy
#define बहु_पूर्ण __builtin_va_end

/* fix a buggy dependency on GCC in libio.h */
प्रकारव्याख्या बहु_सूची __gnuc_va_list;
#define _VA_LIST_DEFINED

#endif /* _STDARG_H */
