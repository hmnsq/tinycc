/* accept 'defined' as result of substitution */

----- 1 ------
#تعریف_کرو AAA 2
#تعریف_کرو BBB
#تعریف_کرو CCC (defined ( AAA ) && AAA > 1 && !defined BBB)
#إذا !CCC
OK
#وإلا
NOT OK
#جے_انت

----- 2 ------
#تعریف_رد BBB
#إذا CCC
OK
#وإلا
NOT OK
#جے_انت

----- 3 ------
#تعریف_کرو DEFINED defined
#تعریف_کرو DDD (DEFINED ( AAA ) && AAA > 1 && !DEFINED BBB)
#إذا (DDD)
OK
#وإلا
NOT OK
#جے_انت

----- 4 ------
#تعریف_رد AAA
#إذا !(DDD)
OK
#وإلا
NOT OK
#جے_انت

----- 5 ------
سطر __LINE__
#تعریف_کرو __LINE__ # ## #
سطر __LINE__

----- 10 ------
/* preprocessor numbers are (u)intmax_t */
#إذا -2147483648 < 0
1 true
#جے_انت
#إذا -0x80000000 < 0
2 true
#جے_انت
#إذا -9223372036854775808U > 0
3 true
#جے_انت
#إذا -0x8000000000000000 > 0 // unsigned by overflow
4 true
#جے_انت
#إذا 1 << 31 > 2 && 1 << 32 > 2 && 1 << 63 < 2 && 1U << 63 > 2
5 true
#جے_انت
#إذا (1<<29) * 11 >= 1<<32 && defined DDD << 63 < 0
6 true
#جے_انت
