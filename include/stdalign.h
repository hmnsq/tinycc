#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _STDALIGN_H
#ವ್ಯಾಖ್ಯಾನಿಸು _STDALIGN_H

#ಆದರೆ __STDC_VERSION__ < 201112L && (defined(__GNUC__) || defined(__TINYC__))
# define _Alignas(t) __attribute__((__aligned__(t)))
# define _Alignof(t) __alignof__(t)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು alignas _Alignas
#ವ್ಯಾಖ್ಯಾನಿಸು alignof _Alignof

#ವ್ಯಾಖ್ಯಾನಿಸು __alignas_is_defined 1
#ವ್ಯಾಖ್ಯಾನಿಸು __alignof_is_defined 1

#ಆದರೆ_ಅಂತ್ಯ /* _STDALIGN_H */

