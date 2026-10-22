#جيڪڏهن_وصف_نه_ٿيل _FLOAT_H_
#وصف_ڪريو _FLOAT_H_

#وصف_ڪريو FLT_RADIX 2

/* IEEE float */
#وصف_ڪريو FLT_MANT_DIG 24
#وصف_ڪريو FLT_DIG 6
#وصف_ڪريو FLT_ROUNDS 1
#وصف_ڪريو FLT_EPSILON 1.19209290e-07F
#وصف_ڪريو FLT_MIN_EXP (-125)
#وصف_ڪريو FLT_MIN 1.17549435e-38F
#وصف_ڪريو FLT_MIN_10_EXP (-37)
#وصف_ڪريو FLT_MAX_EXP 128
#وصف_ڪريو FLT_MAX 3.40282347e+38F
#وصف_ڪريو FLT_MAX_10_EXP 38

/* IEEE double */
#وصف_ڪريو DBL_MANT_DIG 53
#وصف_ڪريو DBL_DIG 15
#وصف_ڪريو DBL_EPSILON 2.2204460492503131e-16
#وصف_ڪريو DBL_MIN_EXP (-1021)
#وصف_ڪريو DBL_MIN 2.2250738585072014e-308
#وصف_ڪريو DBL_MIN_10_EXP (-307)
#وصف_ڪريو DBL_MAX_EXP 1024
#وصف_ڪريو DBL_MAX 1.7976931348623157e+308
#وصف_ڪريو DBL_MAX_10_EXP 308

/* horrible intel long double */
#إذا defined __i386__ || defined __x86_64__

#وصف_ڪريو LDBL_MANT_DIG 64
#وصف_ڪريو LDBL_DIG 18
#وصف_ڪريو LDBL_EPSILON 1.08420217248550443401e-19L
#وصف_ڪريو LDBL_MIN_EXP (-16381)
#وصف_ڪريو LDBL_MIN 3.36210314311209350626e-4932L
#وصف_ڪريو LDBL_MIN_10_EXP (-4931)
#وصف_ڪريو LDBL_MAX_EXP 16384
#وصف_ڪريو LDBL_MAX 1.18973149535723176502e+4932L
#وصف_ڪريو LDBL_MAX_10_EXP 4932
#وصف_ڪريو DECIMAL_DIG 21

#وإلاإذا defined __aarch64__ || defined __riscv
/*
 * Use values from:
 * gcc -dM -E -xc /dev/null | grep LDBL | sed -e "s/__//g"
 */
#وصف_ڪريو LDBL_MANT_DIG 113
#وصف_ڪريو LDBL_DIG 33
#وصف_ڪريو LDBL_EPSILON 1.92592994438723585305597794258492732e-34L
#وصف_ڪريو LDBL_MIN_EXP (-16381)
#وصف_ڪريو LDBL_MIN 3.36210314311209350626267781732175260e-4932L
#وصف_ڪريو LDBL_MIN_10_EXP (-4931)
#وصف_ڪريو LDBL_MAX_EXP 16384
#وصف_ڪريو LDBL_MAX 1.18973149535723176508575932662800702e+4932L
#وصف_ڪريو LDBL_MAX_10_EXP 4932
#وصف_ڪريو DECIMAL_DIG 36

#وإلا

/* same as IEEE double */
#وصف_ڪريو LDBL_MANT_DIG 53
#وصف_ڪريو LDBL_DIG 15
#وصف_ڪريو LDBL_EPSILON 2.2204460492503131e-16L
#وصف_ڪريو LDBL_MIN_EXP (-1021)
#وصف_ڪريو LDBL_MIN 2.2250738585072014e-308L
#وصف_ڪريو LDBL_MIN_10_EXP (-307)
#وصف_ڪريو LDBL_MAX_EXP 1024
#وصف_ڪريو LDBL_MAX 1.7976931348623157e+308L
#وصف_ڪريو LDBL_MAX_10_EXP 308
#وصف_ڪريو DECIMAL_DIG 17

#جيڪڏهن_پورو

#جيڪڏهن_پورو /* _FLOAT_H_ */
