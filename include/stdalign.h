#جيڪڏهن_وصف_نه_ٿيل _STDALIGN_H
#وصف_ڪريو _STDALIGN_H

#إذا __STDC_VERSION__ < 201112L && (defined(__GNUC__) || defined(__TINYC__))
# define _Alignas(t) __attribute__((__aligned__(t)))
# define _Alignof(t) __alignof__(t)
#جيڪڏهن_پورو

#وصف_ڪريو alignas _Alignas
#وصف_ڪريو alignof _Alignof

#وصف_ڪريو __alignas_is_defined 1
#وصف_ڪريو __alignof_is_defined 1

#جيڪڏهن_پورو /* _STDALIGN_H */

