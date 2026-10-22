/* accept 'defined' as result of substitution */

----- 1 ------
#घोषणा AAA 2
#घोषणा BBB
#घोषणा CCC (defined ( AAA ) && AAA > 1 && !defined BBB)
#अगर !CCC
OK
#अन्यथा
NOT OK
#पूर्ण_अगर

----- 2 ------
#अघोषित BBB
#अगर CCC
OK
#अन्यथा
NOT OK
#पूर्ण_अगर

----- 3 ------
#घोषणा DEFINED defined
#घोषणा DDD (DEFINED ( AAA ) && AAA > 1 && !DEFINED BBB)
#अगर (DDD)
OK
#अन्यथा
NOT OK
#पूर्ण_अगर

----- 4 ------
#अघोषित AAA
#अगर !(DDD)
OK
#अन्यथा
NOT OK
#पूर्ण_अगर

----- 5 ------
पंक्ति_2 __LINE__
#घोषणा __LINE__ # ## #
पंक्ति_2 __LINE__

----- 10 ------
/* preprocessor numbers are (u)intmax_t */
#अगर -2147483648 < 0
1 true
#पूर्ण_अगर
#अगर -0x80000000 < 0
2 true
#पूर्ण_अगर
#अगर -9223372036854775808U > 0
3 true
#पूर्ण_अगर
#अगर -0x8000000000000000 > 0 // unsigned by overflow
4 true
#पूर्ण_अगर
#अगर 1 << 31 > 2 && 1 << 32 > 2 && 1 << 63 < 2 && 1U << 63 > 2
5 true
#पूर्ण_अगर
#अगर (1<<29) * 11 >= 1<<32 && defined DDD << 63 < 0
6 true
#पूर्ण_अगर
