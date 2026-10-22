#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _FLOAT_H_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _FLOAT_H_

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLT_RADIX 2

/* IEEE float */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLT_MANT_DIG 24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLT_DIG 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLT_ROUNDS 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLT_EPSILON 1.19209290e-07F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLT_MIN_EXP (-125)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLT_MIN 1.17549435e-38F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLT_MIN_10_EXP (-37)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLT_MAX_EXP 128
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLT_MAX 3.40282347e+38F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLT_MAX_10_EXP 38

/* IEEE double */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DBL_MANT_DIG 53
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DBL_DIG 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DBL_EPSILON 2.2204460492503131e-16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DBL_MIN_EXP (-1021)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DBL_MIN 2.2250738585072014e-308
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DBL_MIN_10_EXP (-307)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DBL_MAX_EXP 1024
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DBL_MAX 1.7976931348623157e+308
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DBL_MAX_10_EXP 308

/* horrible intel long double */
#ਜੇ defined __i386__ || defined __x86_64__

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MANT_DIG 64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_DIG 18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_EPSILON 1.08420217248550443401e-19L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MIN_EXP (-16381)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MIN 3.36210314311209350626e-4932L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MIN_10_EXP (-4931)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MAX_EXP 16384
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MAX 1.18973149535723176502e+4932L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MAX_10_EXP 4932
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECIMAL_DIG 21

#ਜਾਂਜੇ defined __aarch64__ || defined __riscv
/*
 * Use values from:
 * gcc -dM -E -xc /dev/null | grep LDBL | sed -e "s/__//g"
 */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MANT_DIG 113
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_DIG 33
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_EPSILON 1.92592994438723585305597794258492732e-34L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MIN_EXP (-16381)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MIN 3.36210314311209350626267781732175260e-4932L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MIN_10_EXP (-4931)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MAX_EXP 16384
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MAX 1.18973149535723176508575932662800702e+4932L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MAX_10_EXP 4932
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECIMAL_DIG 36

#ਨਹੀਂਤਾਂ

/* same as IEEE double */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MANT_DIG 53
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_DIG 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_EPSILON 2.2204460492503131e-16L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MIN_EXP (-1021)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MIN 2.2250738585072014e-308L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MIN_10_EXP (-307)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MAX_EXP 1024
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MAX 1.7976931348623157e+308L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDBL_MAX_10_EXP 308
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECIMAL_DIG 17

#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ /* _FLOAT_H_ */
