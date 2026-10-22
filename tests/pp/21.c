/* accept 'defined' as result of substitution */

----- 1 ------
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AAA 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BBB
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CCC (defined ( AAA ) && AAA > 1 && !defined BBB)
#ਜੇ !CCC
OK
#ਨਹੀਂਤਾਂ
NOT OK
#ਜੇ_ਅੰਤ

----- 2 ------
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ BBB
#ਜੇ CCC
OK
#ਨਹੀਂਤਾਂ
NOT OK
#ਜੇ_ਅੰਤ

----- 3 ------
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEFINED defined
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DDD (DEFINED ( AAA ) && AAA > 1 && !DEFINED BBB)
#ਜੇ (DDD)
OK
#ਨਹੀਂਤਾਂ
NOT OK
#ਜੇ_ਅੰਤ

----- 4 ------
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ AAA
#ਜੇ !(DDD)
OK
#ਨਹੀਂਤਾਂ
NOT OK
#ਜੇ_ਅੰਤ

----- 5 ------
ਸਤਰ __LINE__
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __LINE__ # ## #
ਸਤਰ __LINE__

----- 10 ------
/* preprocessor numbers are (u)intmax_t */
#ਜੇ -2147483648 < 0
1 true
#ਜੇ_ਅੰਤ
#ਜੇ -0x80000000 < 0
2 true
#ਜੇ_ਅੰਤ
#ਜੇ -9223372036854775808U > 0
3 true
#ਜੇ_ਅੰਤ
#ਜੇ -0x8000000000000000 > 0 // unsigned by overflow
4 true
#ਜੇ_ਅੰਤ
#ਜੇ 1 << 31 > 2 && 1 << 32 > 2 && 1 << 63 < 2 && 1U << 63 > 2
5 true
#ਜੇ_ਅੰਤ
#ਜੇ (1<<29) * 11 >= 1<<32 && defined DDD << 63 < 0
6 true
#ਜੇ_ਅੰਤ
