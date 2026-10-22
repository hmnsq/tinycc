#که_نه_تعریف_شوی _STDALIGN_H
#تعریف_کړه _STDALIGN_H

#إذا __STDC_VERSION__ < 201112L && (defined(__GNUC__) || defined(__TINYC__))
# define _Alignas(t) __attribute__((__aligned__(t)))
# define _Alignof(t) __alignof__(t)
#د_که_پای

#تعریف_کړه alignas _Alignas
#تعریف_کړه alignof _Alignof

#تعریف_کړه __alignas_is_defined 1
#تعریف_کړه __alignof_is_defined 1

#د_که_پای /* _STDALIGN_H */

