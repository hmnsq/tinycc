/* accept 'defined' as result of substitution */

----- 1 ------
#تعریف_کړه AAA 2
#تعریف_کړه BBB
#تعریف_کړه CCC (defined ( AAA ) && AAA > 1 && !defined BBB)
#إذا !CCC
OK
#وإلا
NOT OK
#د_که_پای

----- 2 ------
#تعریف_لغوه BBB
#إذا CCC
OK
#وإلا
NOT OK
#د_که_پای

----- 3 ------
#تعریف_کړه DEFINED defined
#تعریف_کړه DDD (DEFINED ( AAA ) && AAA > 1 && !DEFINED BBB)
#إذا (DDD)
OK
#وإلا
NOT OK
#د_که_پای

----- 4 ------
#تعریف_لغوه AAA
#إذا !(DDD)
OK
#وإلا
NOT OK
#د_که_پای

----- 5 ------
کرښه __LINE__
#تعریف_کړه __LINE__ # ## #
کرښه __LINE__

----- 10 ------
/* preprocessor numbers are (u)intmax_t */
#إذا -2147483648 < 0
1 true
#د_که_پای
#إذا -0x80000000 < 0
2 true
#د_که_پای
#إذا -9223372036854775808U > 0
3 true
#د_که_پای
#إذا -0x8000000000000000 > 0 // unsigned by overflow
4 true
#د_که_پای
#إذا 1 << 31 > 2 && 1 << 32 > 2 && 1 << 63 < 2 && 1U << 63 > 2
5 true
#د_که_پای
#إذا (1<<29) * 11 >= 1<<32 && defined DDD << 63 < 0
6 true
#د_که_پای
