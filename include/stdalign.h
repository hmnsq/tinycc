#अगर_अघोषित _STDALIGN_H
#घोषणा _STDALIGN_H

#अगर __STDC_VERSION__ < 201112L && (defined(__GNUC__) || defined(__TINYC__))
# define _Alignas(t) __attribute__((__aligned__(t)))
# define _Alignof(t) __alignof__(t)
#पूर्ण_अगर

#घोषणा alignas _Alignas
#घोषणा alignof _Alignof

#घोषणा __alignas_is_defined 1
#घोषणा __alignof_is_defined 1

#पूर्ण_अगर /* _STDALIGN_H */

