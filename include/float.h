#నిర్వచితం_కాకపోతే _FLOAT_H_
#నిర్వచించు _FLOAT_H_

#నిర్వచించు FLT_RADIX 2

/* IEEE float */
#నిర్వచించు FLT_MANT_DIG 24
#నిర్వచించు FLT_DIG 6
#నిర్వచించు FLT_ROUNDS 1
#నిర్వచించు FLT_EPSILON 1.19209290e-07F
#నిర్వచించు FLT_MIN_EXP (-125)
#నిర్వచించు FLT_MIN 1.17549435e-38F
#నిర్వచించు FLT_MIN_10_EXP (-37)
#నిర్వచించు FLT_MAX_EXP 128
#నిర్వచించు FLT_MAX 3.40282347e+38F
#నిర్వచించు FLT_MAX_10_EXP 38

/* IEEE double */
#నిర్వచించు DBL_MANT_DIG 53
#నిర్వచించు DBL_DIG 15
#నిర్వచించు DBL_EPSILON 2.2204460492503131e-16
#నిర్వచించు DBL_MIN_EXP (-1021)
#నిర్వచించు DBL_MIN 2.2250738585072014e-308
#నిర్వచించు DBL_MIN_10_EXP (-307)
#నిర్వచించు DBL_MAX_EXP 1024
#నిర్వచించు DBL_MAX 1.7976931348623157e+308
#నిర్వచించు DBL_MAX_10_EXP 308

/* horrible intel long double */
#ఒకవేళ defined __i386__ || defined __x86_64__

#నిర్వచించు LDBL_MANT_DIG 64
#నిర్వచించు LDBL_DIG 18
#నిర్వచించు LDBL_EPSILON 1.08420217248550443401e-19L
#నిర్వచించు LDBL_MIN_EXP (-16381)
#నిర్వచించు LDBL_MIN 3.36210314311209350626e-4932L
#నిర్వచించు LDBL_MIN_10_EXP (-4931)
#నిర్వచించు LDBL_MAX_EXP 16384
#నిర్వచించు LDBL_MAX 1.18973149535723176502e+4932L
#నిర్వచించు LDBL_MAX_10_EXP 4932
#నిర్వచించు DECIMAL_DIG 21

#లేదావేళ defined __aarch64__ || defined __riscv
/*
 * Use values from:
 * gcc -dM -E -xc /dev/null | grep LDBL | sed -e "s/__//g"
 */
#నిర్వచించు LDBL_MANT_DIG 113
#నిర్వచించు LDBL_DIG 33
#నిర్వచించు LDBL_EPSILON 1.92592994438723585305597794258492732e-34L
#నిర్వచించు LDBL_MIN_EXP (-16381)
#నిర్వచించు LDBL_MIN 3.36210314311209350626267781732175260e-4932L
#నిర్వచించు LDBL_MIN_10_EXP (-4931)
#నిర్వచించు LDBL_MAX_EXP 16384
#నిర్వచించు LDBL_MAX 1.18973149535723176508575932662800702e+4932L
#నిర్వచించు LDBL_MAX_10_EXP 4932
#నిర్వచించు DECIMAL_DIG 36

#లేకపోతే

/* same as IEEE double */
#నిర్వచించు LDBL_MANT_DIG 53
#నిర్వచించు LDBL_DIG 15
#నిర్వచించు LDBL_EPSILON 2.2204460492503131e-16L
#నిర్వచించు LDBL_MIN_EXP (-1021)
#నిర్వచించు LDBL_MIN 2.2250738585072014e-308L
#నిర్వచించు LDBL_MIN_10_EXP (-307)
#నిర్వచించు LDBL_MAX_EXP 1024
#నిర్వచించు LDBL_MAX 1.7976931348623157e+308L
#నిర్వచించు LDBL_MAX_10_EXP 308
#నిర్వచించు DECIMAL_DIG 17

#అయితే_ముగింపు

#అయితే_ముగింపు /* _FLOAT_H_ */
