/* accept 'defined' as result of substitution */

----- 1 ------
#define AAA 2
#define BBB
#define CCC (defined ( AAA ) && AAA > 1 && !defined BBB)
#ᮚᮦᮔ᮪ !CCC
OK
#ᮜᮤᮚ
NOT OK
#endif

----- 2 ------
#undef BBB
#ᮚᮦᮔ᮪ CCC
OK
#ᮜᮤᮚ
NOT OK
#endif

----- 3 ------
#define DEFINED defined
#define DDD (DEFINED ( AAA ) && AAA > 1 && !DEFINED BBB)
#ᮚᮦᮔ᮪ (DDD)
OK
#ᮜᮤᮚ
NOT OK
#endif

----- 4 ------
#undef AAA
#ᮚᮦᮔ᮪ !(DDD)
OK
#ᮜᮤᮚ
NOT OK
#endif

----- 5 ------
line __LINE__
#define __LINE__ # ## #
line __LINE__

----- 10 ------
/* preprocessor numbers are (u)intmax_t */
#ᮚᮦᮔ᮪ -2147483648 < 0
1 true
#endif
#ᮚᮦᮔ᮪ -0x80000000 < 0
2 true
#endif
#ᮚᮦᮔ᮪ -9223372036854775808U > 0
3 true
#endif
#ᮚᮦᮔ᮪ -0x8000000000000000 > 0 // unsigned by overflow
4 true
#endif
#ᮚᮦᮔ᮪ 1 << 31 > 2 && 1 << 32 > 2 && 1 << 63 < 2 && 1U << 63 > 2
5 true
#endif
#ᮚᮦᮔ᮪ (1<<29) * 11 >= 1<<32 && defined DDD << 63 < 0
6 true
#endif
