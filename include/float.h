#ifndef _FLOAT_H_
#define _FLOAT_H_

#define भग्न_आधार 2

/* IEEE float */
#define भग्न_पूर्ण 24
#define भग्न_भग्न 6
#define FLT_ROUNDS 1
#define भग्न_अंतर 1.19209290e-07F
#define FLT_MIN_EXP (-125)
#define भग्न_न्यून 1.17549435e-38F
#define FLT_MIN_10_EXP (-37)
#define FLT_MAX_EXP 128
#define भग्न_उच्च 3.40282347e+38F
#define FLT_MAX_10_EXP 38

/* IEEE double */
#define द्विग_पूर्ण 53
#define द्विग_भग्न 15
#define द्विग_अंतर 2.2204460492503131e-16
#define DBL_MIN_EXP (-1021)
#define द्विग_न्यून 2.2250738585072014e-308
#define DBL_MIN_10_EXP (-307)
#define DBL_MAX_EXP 1024
#define द्विग_उच्च 1.7976931348623157e+308
#define DBL_MAX_10_EXP 308

/* horrible intel long double */
#यदि defined __i386__ || defined __x86_64__

#define द_द्वि_पूर्ण 64
#define द_द्वि_भग्न 18
#define द_द्वि_अंतर 1.08420217248550443401e-19L
#define LDBL_MIN_EXP (-16381)
#define द_द्वि_न्यून 3.36210314311209350626e-4932L
#define LDBL_MIN_10_EXP (-4931)
#define LDBL_MAX_EXP 16384
#define द_द्वि_उच्च 1.18973149535723176502e+4932L
#define LDBL_MAX_10_EXP 4932
#define DECIMAL_DIG 21

#अथवायदि defined __aarch64__ || defined __riscv
/*
 * Use values from:
 * gcc -dM -E -xc /dev/null | grep LDBL | sed -e "s/__//g"
 */
#define द_द्वि_पूर्ण 113
#define द_द्वि_भग्न 33
#define द_द्वि_अंतर 1.92592994438723585305597794258492732e-34L
#define LDBL_MIN_EXP (-16381)
#define द_द्वि_न्यून 3.36210314311209350626267781732175260e-4932L
#define LDBL_MIN_10_EXP (-4931)
#define LDBL_MAX_EXP 16384
#define द_द्वि_उच्च 1.18973149535723176508575932662800702e+4932L
#define LDBL_MAX_10_EXP 4932
#define DECIMAL_DIG 36

#अन्यथा

/* same as IEEE double */
#define द_द्वि_पूर्ण 53
#define द_द्वि_भग्न 15
#define द_द्वि_अंतर 2.2204460492503131e-16L
#define LDBL_MIN_EXP (-1021)
#define द_द्वि_न्यून 2.2250738585072014e-308L
#define LDBL_MIN_10_EXP (-307)
#define LDBL_MAX_EXP 1024
#define द_द्वि_उच्च 1.7976931348623157e+308L
#define LDBL_MAX_10_EXP 308
#define DECIMAL_DIG 17

#endif

#endif /* _FLOAT_H_ */
