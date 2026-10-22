/* accept 'defined' as result of substitution */

----- 1 ------
#تعریف_کن AAA 2
#تعریف_کن BBB
#تعریف_کن CCC (defined ( AAA ) && AAA > 1 && !defined BBB)
#إذا !CCC
OK
#وإلا
NOT OK
#پایان_اگر

----- 2 ------
#لغو_تعریف BBB
#إذا CCC
OK
#وإلا
NOT OK
#پایان_اگر

----- 3 ------
#تعریف_کن DEFINED defined
#تعریف_کن DDD (DEFINED ( AAA ) && AAA > 1 && !DEFINED BBB)
#إذا (DDD)
OK
#وإلا
NOT OK
#پایان_اگر

----- 4 ------
#لغو_تعریف AAA
#إذا !(DDD)
OK
#وإلا
NOT OK
#پایان_اگر

----- 5 ------
سطر __LINE__
#تعریف_کن __LINE__ # ## #
سطر __LINE__

----- 10 ------
/* preprocessor numbers are (u)intmax_t */
#إذا -2147483648 < 0
1 true
#پایان_اگر
#إذا -0x80000000 < 0
2 true
#پایان_اگر
#إذا -9223372036854775808U > 0
3 true
#پایان_اگر
#إذا -0x8000000000000000 > 0 // unsigned by overflow
4 true
#پایان_اگر
#إذا 1 << 31 > 2 && 1 << 32 > 2 && 1 << 63 < 2 && 1U << 63 > 2
5 true
#پایان_اگر
#إذا (1<<29) * 11 >= 1<<32 && defined DDD << 63 < 0
6 true
#پایان_اگر
