#اگر_تعریف_نشده _STDALIGN_H
#تعریف_کن _STDALIGN_H

#إذا __STDC_VERSION__ < 201112L && (defined(__GNUC__) || defined(__TINYC__))
# define _Alignas(t) __attribute__((__aligned__(t)))
# define _Alignof(t) __alignof__(t)
#پایان_اگر

#تعریف_کن alignas _Alignas
#تعریف_کن alignof _Alignof

#تعریف_کن __alignas_is_defined 1
#تعریف_کن __alignof_is_defined 1

#پایان_اگر /* _STDALIGN_H */

