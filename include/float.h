#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _FLOAT_H_
#ವ್ಯಾಖ್ಯಾನಿಸು _FLOAT_H_

#ವ್ಯಾಖ್ಯಾನಿಸು FLT_RADIX 2

/* IEEE float */
#ವ್ಯಾಖ್ಯಾನಿಸು FLT_MANT_DIG 24
#ವ್ಯಾಖ್ಯಾನಿಸು FLT_DIG 6
#ವ್ಯಾಖ್ಯಾನಿಸು FLT_ROUNDS 1
#ವ್ಯಾಖ್ಯಾನಿಸು FLT_EPSILON 1.19209290e-07F
#ವ್ಯಾಖ್ಯಾನಿಸು FLT_MIN_EXP (-125)
#ವ್ಯಾಖ್ಯಾನಿಸು FLT_MIN 1.17549435e-38F
#ವ್ಯಾಖ್ಯಾನಿಸು FLT_MIN_10_EXP (-37)
#ವ್ಯಾಖ್ಯಾನಿಸು FLT_MAX_EXP 128
#ವ್ಯಾಖ್ಯಾನಿಸು FLT_MAX 3.40282347e+38F
#ವ್ಯಾಖ್ಯಾನಿಸು FLT_MAX_10_EXP 38

/* IEEE double */
#ವ್ಯಾಖ್ಯಾನಿಸು DBL_MANT_DIG 53
#ವ್ಯಾಖ್ಯಾನಿಸು DBL_DIG 15
#ವ್ಯಾಖ್ಯಾನಿಸು DBL_EPSILON 2.2204460492503131e-16
#ವ್ಯಾಖ್ಯಾನಿಸು DBL_MIN_EXP (-1021)
#ವ್ಯಾಖ್ಯಾನಿಸು DBL_MIN 2.2250738585072014e-308
#ವ್ಯಾಖ್ಯಾನಿಸು DBL_MIN_10_EXP (-307)
#ವ್ಯಾಖ್ಯಾನಿಸು DBL_MAX_EXP 1024
#ವ್ಯಾಖ್ಯಾನಿಸು DBL_MAX 1.7976931348623157e+308
#ವ್ಯಾಖ್ಯಾನಿಸು DBL_MAX_10_EXP 308

/* horrible intel long double */
#ಆದರೆ defined __i386__ || defined __x86_64__

#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MANT_DIG 64
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_DIG 18
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_EPSILON 1.08420217248550443401e-19L
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MIN_EXP (-16381)
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MIN 3.36210314311209350626e-4932L
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MIN_10_EXP (-4931)
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MAX_EXP 16384
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MAX 1.18973149535723176502e+4932L
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MAX_10_EXP 4932
#ವ್ಯಾಖ್ಯಾನಿಸು DECIMAL_DIG 21

#ಅಥವಾಆದರೆ defined __aarch64__ || defined __riscv
/*
 * Use values from:
 * gcc -dM -E -xc /dev/null | grep LDBL | sed -e "s/__//g"
 */
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MANT_DIG 113
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_DIG 33
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_EPSILON 1.92592994438723585305597794258492732e-34L
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MIN_EXP (-16381)
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MIN 3.36210314311209350626267781732175260e-4932L
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MIN_10_EXP (-4931)
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MAX_EXP 16384
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MAX 1.18973149535723176508575932662800702e+4932L
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MAX_10_EXP 4932
#ವ್ಯಾಖ್ಯಾನಿಸು DECIMAL_DIG 36

#ಇಲ್ಲದಿದ್ದರೆ

/* same as IEEE double */
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MANT_DIG 53
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_DIG 15
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_EPSILON 2.2204460492503131e-16L
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MIN_EXP (-1021)
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MIN 2.2250738585072014e-308L
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MIN_10_EXP (-307)
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MAX_EXP 1024
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MAX 1.7976931348623157e+308L
#ವ್ಯಾಖ್ಯಾನಿಸು LDBL_MAX_10_EXP 308
#ವ್ಯಾಖ್ಯಾನಿಸು DECIMAL_DIG 17

#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ_ಅಂತ್ಯ /* _FLOAT_H_ */
