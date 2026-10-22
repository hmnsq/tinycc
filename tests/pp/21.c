/* accept 'defined' as result of substitution */

----- 1 ------
#define AAA 2
#define BBB
#define CCC (defined ( AAA ) && AAA > 1 && !defined BBB)
#जइ !CCC
OK
#अण्णहा
NOT OK
#endif

----- 2 ------
#undef BBB
#जइ CCC
OK
#अण्णहा
NOT OK
#endif

----- 3 ------
#define DEFINED defined
#define DDD (DEFINED ( AAA ) && AAA > 1 && !DEFINED BBB)
#जइ (DDD)
OK
#अण्णहा
NOT OK
#endif

----- 4 ------
#undef AAA
#जइ !(DDD)
OK
#अण्णहा
NOT OK
#endif

----- 5 ------
पङ्क्तिः __LINE__
#define __LINE__ # ## #
पङ्क्तिः __LINE__

----- 10 ------
/* preprocessor numbers are (u)intmax_t */
#जइ -2147483648 < 0
1 true
#endif
#जइ -0x80000000 < 0
2 true
#endif
#जइ -9223372036854775808U > 0
3 true
#endif
#जइ -0x8000000000000000 > 0 // unsigned by overflow
4 true
#endif
#जइ 1 << 31 > 2 && 1 << 32 > 2 && 1 << 63 < 2 && 1U << 63 > 2
5 true
#endif
#जइ (1<<29) * 11 >= 1<<32 && defined DDD << 63 < 0
6 true
#endif
