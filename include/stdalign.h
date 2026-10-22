#నిర్వచితం_కాకపోతే _STDALIGN_H
#నిర్వచించు _STDALIGN_H

#ఒకవేళ __STDC_VERSION__ < 201112L && (defined(__GNUC__) || defined(__TINYC__))
# define _Alignas(t) __attribute__((__aligned__(t)))
# define _Alignof(t) __alignof__(t)
#అయితే_ముగింపు

#నిర్వచించు alignas _Alignas
#నిర్వచించు alignof _Alignof

#నిర్వచించు __alignas_is_defined 1
#నిర్వచించు __alignof_is_defined 1

#అయితే_ముగింపు /* _STDALIGN_H */

