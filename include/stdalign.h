#جے_بنا_تعریف _STDALIGN_H
#تعریف_کرو _STDALIGN_H

#إذا __STDC_VERSION__ < 201112L && (defined(__GNUC__) || defined(__TINYC__))
# define _Alignas(t) __attribute__((__aligned__(t)))
# define _Alignof(t) __alignof__(t)
#جے_انت

#تعریف_کرو alignas _Alignas
#تعریف_کرو alignof _Alignof

#تعریف_کرو __alignas_is_defined 1
#تعریف_کرو __alignof_is_defined 1

#جے_انت /* _STDALIGN_H */

