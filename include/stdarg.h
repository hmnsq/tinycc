#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _STDARG_H
#ವ್ಯಾಖ್ಯಾನಿಸು _STDARG_H

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __builtin_va_list va_list;
#ವ್ಯಾಖ್ಯಾನಿಸು va_start __builtin_va_start
#ವ್ಯಾಖ್ಯಾನಿಸು va_arg __builtin_va_arg
#ವ್ಯಾಖ್ಯಾನಿಸು va_copy __builtin_va_copy
#ವ್ಯಾಖ್ಯಾನಿಸು va_end __builtin_va_end

/* fix a buggy dependency on GCC in libio.h */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ va_list __gnuc_va_list;
#ವ್ಯಾಖ್ಯಾನಿಸು _VA_LIST_DEFINED

#ಆದರೆ_ಅಂತ್ಯ /* _STDARG_H */
