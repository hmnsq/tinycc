#اگر_غیر_تعریف_شدہ _STDALIGN_H
#تعریف_کرو _STDALIGN_H

#اگر __STDC_VERSION__ < 201112L && (defined(__GNUC__) || defined(__TINYC__))
# define _Alignas(t) __attribute__((__aligned__(t)))
# define _Alignof(t) __alignof__(t)
#اگر_ختم

#تعریف_کرو alignas _Alignas
#تعریف_کرو alignof _Alignof

#تعریف_کرو __alignas_is_defined 1
#تعریف_کرو __alignof_is_defined 1

#اگر_ختم /* _STDALIGN_H */

