#यदि_अपरिभाषितम् _STDALIGN_H
#परिभाषय _STDALIGN_H

#यदि __STDC_VERSION__ < 201112L && (defined(__GNUC__) || defined(__TINYC__))
# define _Alignas(t) __attribute__((__aligned__(t)))
# define _Alignof(t) __alignof__(t)
#यदि_अन्तः

#परिभाषय alignas _Alignas
#परिभाषय alignof _Alignof

#परिभाषय __alignas_is_defined 1
#परिभाषय __alignof_is_defined 1

#यदि_अन्तः /* _STDALIGN_H */

