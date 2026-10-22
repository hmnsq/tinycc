/* accept 'defined' as result of substitution */

----- 1 ------
#وصف_ڪريو AAA 2
#وصف_ڪريو BBB
#وصف_ڪريو CCC (defined ( AAA ) && AAA > 1 && !defined BBB)
#إذا !CCC
OK
#وإلا
NOT OK
#جيڪڏهن_پورو

----- 2 ------
#وصف_رد BBB
#إذا CCC
OK
#وإلا
NOT OK
#جيڪڏهن_پورو

----- 3 ------
#وصف_ڪريو DEFINED defined
#وصف_ڪريو DDD (DEFINED ( AAA ) && AAA > 1 && !DEFINED BBB)
#إذا (DDD)
OK
#وإلا
NOT OK
#جيڪڏهن_پورو

----- 4 ------
#وصف_رد AAA
#إذا !(DDD)
OK
#وإلا
NOT OK
#جيڪڏهن_پورو

----- 5 ------
سٽ __LINE__
#وصف_ڪريو __LINE__ # ## #
سٽ __LINE__

----- 10 ------
/* preprocessor numbers are (u)intmax_t */
#إذا -2147483648 < 0
1 true
#جيڪڏهن_پورو
#إذا -0x80000000 < 0
2 true
#جيڪڏهن_پورو
#إذا -9223372036854775808U > 0
3 true
#جيڪڏهن_پورو
#إذا -0x8000000000000000 > 0 // unsigned by overflow
4 true
#جيڪڏهن_پورو
#إذا 1 << 31 > 2 && 1 << 32 > 2 && 1 << 63 < 2 && 1U << 63 > 2
5 true
#جيڪڏهن_پورو
#إذا (1<<29) * 11 >= 1<<32 && defined DDD << 63 < 0
6 true
#جيڪڏهن_پورو
