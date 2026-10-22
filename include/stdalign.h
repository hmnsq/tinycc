#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _STDALIGN_H
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _STDALIGN_H

#ਜੇ __STDC_VERSION__ < 201112L && (defined(__GNUC__) || defined(__TINYC__))
# define _Alignas(t) __attribute__((__aligned__(t)))
# define _Alignof(t) __alignof__(t)
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ alignas _Alignas
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ alignof _Alignof

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __alignas_is_defined 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __alignof_is_defined 1

#ਜੇ_ਅੰਤ /* _STDALIGN_H */

