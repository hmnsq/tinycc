#यदि_अपरिभाषितम् _FLOAT_H_
#परिभाषय _FLOAT_H_

#परिभाषय FLT_RADIX 2

/* IEEE float */
#परिभाषय FLT_MANT_DIG 24
#परिभाषय FLT_DIG 6
#परिभाषय FLT_ROUNDS 1
#परिभाषय FLT_EPSILON 1.19209290e-07F
#परिभाषय FLT_MIN_EXP (-125)
#परिभाषय FLT_MIN 1.17549435e-38F
#परिभाषय FLT_MIN_10_EXP (-37)
#परिभाषय FLT_MAX_EXP 128
#परिभाषय FLT_MAX 3.40282347e+38F
#परिभाषय FLT_MAX_10_EXP 38

/* IEEE double */
#परिभाषय DBL_MANT_DIG 53
#परिभाषय DBL_DIG 15
#परिभाषय DBL_EPSILON 2.2204460492503131e-16
#परिभाषय DBL_MIN_EXP (-1021)
#परिभाषय DBL_MIN 2.2250738585072014e-308
#परिभाषय DBL_MIN_10_EXP (-307)
#परिभाषय DBL_MAX_EXP 1024
#परिभाषय DBL_MAX 1.7976931348623157e+308
#परिभाषय DBL_MAX_10_EXP 308

/* horrible intel long double */
#यदि defined __i386__ || defined __x86_64__

#परिभाषय LDBL_MANT_DIG 64
#परिभाषय LDBL_DIG 18
#परिभाषय LDBL_EPSILON 1.08420217248550443401e-19L
#परिभाषय LDBL_MIN_EXP (-16381)
#परिभाषय LDBL_MIN 3.36210314311209350626e-4932L
#परिभाषय LDBL_MIN_10_EXP (-4931)
#परिभाषय LDBL_MAX_EXP 16384
#परिभाषय LDBL_MAX 1.18973149535723176502e+4932L
#परिभाषय LDBL_MAX_10_EXP 4932
#परिभाषय DECIMAL_DIG 21

#नोचेद्यदि defined __aarch64__ || defined __riscv
/*
 * Use values from:
 * gcc -dM -E -xc /dev/null | grep LDBL | sed -e "s/__//g"
 */
#परिभाषय LDBL_MANT_DIG 113
#परिभाषय LDBL_DIG 33
#परिभाषय LDBL_EPSILON 1.92592994438723585305597794258492732e-34L
#परिभाषय LDBL_MIN_EXP (-16381)
#परिभाषय LDBL_MIN 3.36210314311209350626267781732175260e-4932L
#परिभाषय LDBL_MIN_10_EXP (-4931)
#परिभाषय LDBL_MAX_EXP 16384
#परिभाषय LDBL_MAX 1.18973149535723176508575932662800702e+4932L
#परिभाषय LDBL_MAX_10_EXP 4932
#परिभाषय DECIMAL_DIG 36

#अन्यथा

/* same as IEEE double */
#परिभाषय LDBL_MANT_DIG 53
#परिभाषय LDBL_DIG 15
#परिभाषय LDBL_EPSILON 2.2204460492503131e-16L
#परिभाषय LDBL_MIN_EXP (-1021)
#परिभाषय LDBL_MIN 2.2250738585072014e-308L
#परिभाषय LDBL_MIN_10_EXP (-307)
#परिभाषय LDBL_MAX_EXP 1024
#परिभाषय LDBL_MAX 1.7976931348623157e+308L
#परिभाषय LDBL_MAX_10_EXP 308
#परिभाषय DECIMAL_DIG 17

#यदि_अन्तः

#यदि_अन्तः /* _FLOAT_H_ */
