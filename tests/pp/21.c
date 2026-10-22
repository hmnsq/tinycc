/* accept 'defined' as result of substitution */

----- 1 ------
#تعریف_کرو AAA 2
#تعریف_کرو BBB
#تعریف_کرو CCC (defined ( AAA ) && AAA > 1 && !defined BBB)
#اگر !CCC
OK
#ورنہ
NOT OK
#اگر_ختم

----- 2 ------
#تعریف_منسوخ BBB
#اگر CCC
OK
#ورنہ
NOT OK
#اگر_ختم

----- 3 ------
#تعریف_کرو DEFINED defined
#تعریف_کرو DDD (DEFINED ( AAA ) && AAA > 1 && !DEFINED BBB)
#اگر (DDD)
OK
#ورنہ
NOT OK
#اگر_ختم

----- 4 ------
#تعریف_منسوخ AAA
#اگر !(DDD)
OK
#ورنہ
NOT OK
#اگر_ختم

----- 5 ------
سطر __LINE__
#تعریف_کرو __LINE__ # ## #
سطر __LINE__

----- 10 ------
/* preprocessor numbers are (u)intmax_t */
#اگر -2147483648 < 0
1 true
#اگر_ختم
#اگر -0x80000000 < 0
2 true
#اگر_ختم
#اگر -9223372036854775808U > 0
3 true
#اگر_ختم
#اگر -0x8000000000000000 > 0 // unsigned by overflow
4 true
#اگر_ختم
#اگر 1 << 31 > 2 && 1 << 32 > 2 && 1 << 63 < 2 && 1U << 63 > 2
5 true
#اگر_ختم
#اگر (1<<29) * 11 >= 1<<32 && defined DDD << 63 < 0
6 true
#اگر_ختم
