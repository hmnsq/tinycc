/* accept 'defined' as result of substitution */

----- 1 ------
#परिभाषय AAA 2
#परिभाषय BBB
#परिभाषय CCC (defined ( AAA ) && AAA > 1 && !defined BBB)
#यदि !CCC
OK
#अन्यथा
NOT OK
#यदि_अन्तः

----- 2 ------
#अपरिभाषय BBB
#यदि CCC
OK
#अन्यथा
NOT OK
#यदि_अन्तः

----- 3 ------
#परिभाषय DEFINED defined
#परिभाषय DDD (DEFINED ( AAA ) && AAA > 1 && !DEFINED BBB)
#यदि (DDD)
OK
#अन्यथा
NOT OK
#यदि_अन्तः

----- 4 ------
#अपरिभाषय AAA
#यदि !(DDD)
OK
#अन्यथा
NOT OK
#यदि_अन्तः

----- 5 ------
पङ्क्तिः __LINE__
#परिभाषय __LINE__ # ## #
पङ्क्तिः __LINE__

----- 10 ------
/* preprocessor numbers are (u)intmax_t */
#यदि -2147483648 < 0
1 true
#यदि_अन्तः
#यदि -0x80000000 < 0
2 true
#यदि_अन्तः
#यदि -9223372036854775808U > 0
3 true
#यदि_अन्तः
#यदि -0x8000000000000000 > 0 // unsigned by overflow
4 true
#यदि_अन्तः
#यदि 1 << 31 > 2 && 1 << 32 > 2 && 1 << 63 < 2 && 1U << 63 > 2
5 true
#यदि_अन्तः
#यदि (1<<29) * 11 >= 1<<32 && defined DDD << 63 < 0
6 true
#यदि_अन्तः
