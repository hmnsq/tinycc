#که_نه_تعریف_شوی _FLOAT_H_
#تعریف_کړه _FLOAT_H_

#تعریف_کړه FLT_RADIX 2

/* IEEE float */
#تعریف_کړه FLT_MANT_DIG 24
#تعریف_کړه FLT_DIG 6
#تعریف_کړه FLT_ROUNDS 1
#تعریف_کړه FLT_EPSILON 1.19209290e-07F
#تعریف_کړه FLT_MIN_EXP (-125)
#تعریف_کړه FLT_MIN 1.17549435e-38F
#تعریف_کړه FLT_MIN_10_EXP (-37)
#تعریف_کړه FLT_MAX_EXP 128
#تعریف_کړه FLT_MAX 3.40282347e+38F
#تعریف_کړه FLT_MAX_10_EXP 38

/* IEEE double */
#تعریف_کړه DBL_MANT_DIG 53
#تعریف_کړه DBL_DIG 15
#تعریف_کړه DBL_EPSILON 2.2204460492503131e-16
#تعریف_کړه DBL_MIN_EXP (-1021)
#تعریف_کړه DBL_MIN 2.2250738585072014e-308
#تعریف_کړه DBL_MIN_10_EXP (-307)
#تعریف_کړه DBL_MAX_EXP 1024
#تعریف_کړه DBL_MAX 1.7976931348623157e+308
#تعریف_کړه DBL_MAX_10_EXP 308

/* horrible intel long double */
#إذا defined __i386__ || defined __x86_64__

#تعریف_کړه LDBL_MANT_DIG 64
#تعریف_کړه LDBL_DIG 18
#تعریف_کړه LDBL_EPSILON 1.08420217248550443401e-19L
#تعریف_کړه LDBL_MIN_EXP (-16381)
#تعریف_کړه LDBL_MIN 3.36210314311209350626e-4932L
#تعریف_کړه LDBL_MIN_10_EXP (-4931)
#تعریف_کړه LDBL_MAX_EXP 16384
#تعریف_کړه LDBL_MAX 1.18973149535723176502e+4932L
#تعریف_کړه LDBL_MAX_10_EXP 4932
#تعریف_کړه DECIMAL_DIG 21

#وإلاإذا defined __aarch64__ || defined __riscv
/*
 * Use values from:
 * gcc -dM -E -xc /dev/null | grep LDBL | sed -e "s/__//g"
 */
#تعریف_کړه LDBL_MANT_DIG 113
#تعریف_کړه LDBL_DIG 33
#تعریف_کړه LDBL_EPSILON 1.92592994438723585305597794258492732e-34L
#تعریف_کړه LDBL_MIN_EXP (-16381)
#تعریف_کړه LDBL_MIN 3.36210314311209350626267781732175260e-4932L
#تعریف_کړه LDBL_MIN_10_EXP (-4931)
#تعریف_کړه LDBL_MAX_EXP 16384
#تعریف_کړه LDBL_MAX 1.18973149535723176508575932662800702e+4932L
#تعریف_کړه LDBL_MAX_10_EXP 4932
#تعریف_کړه DECIMAL_DIG 36

#وإلا

/* same as IEEE double */
#تعریف_کړه LDBL_MANT_DIG 53
#تعریف_کړه LDBL_DIG 15
#تعریف_کړه LDBL_EPSILON 2.2204460492503131e-16L
#تعریف_کړه LDBL_MIN_EXP (-1021)
#تعریف_کړه LDBL_MIN 2.2250738585072014e-308L
#تعریف_کړه LDBL_MIN_10_EXP (-307)
#تعریف_کړه LDBL_MAX_EXP 1024
#تعریف_کړه LDBL_MAX 1.7976931348623157e+308L
#تعریف_کړه LDBL_MAX_10_EXP 308
#تعریف_کړه DECIMAL_DIG 17

#د_که_پای

#د_که_پای /* _FLOAT_H_ */
