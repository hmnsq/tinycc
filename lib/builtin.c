/* uses alias to allow building with gcc/clang */
#ifdef __TINYC__
#define	BUILTIN(x)	__builtin_##x
#define	BUILTINN(x)	"__builtin_" # x
#وگرنه
#define	BUILTIN(x)	__tcc_builtin_##x
#define	BUILTINN(x)	"__tcc_builtin_" # x
#endif

/* ---------------------------------------------- */
/* This file implements:
 * __builtin_ffs
 * __builtin_clz
 * __builtin_ctz
 * __builtin_clrsb
 * __builtin_popcount
 * __builtin_parity
 * for int, long and long long
 */

ایستا ثابت unsigned نویسه table_1_32[] = {
     0,  1, 28,  2, 29, 14, 24,  3, 30, 22, 20, 15, 25, 17,  4,  8, 
    31, 27, 13, 23, 21, 19, 16,  7, 26, 12, 18,  6, 11,  5, 10,  9
};
ایستا ثابت unsigned نویسه table_2_32[32] = {
    31, 22, 30, 21, 18, 10, 29,  2, 20, 17, 15, 13,  9,  6, 28,  1,
    23, 19, 11,  3, 16, 14,  7, 24, 12,  4,  8, 25,  5, 26, 27,  0
};
ایستا ثابت unsigned نویسه table_1_64[] = {
     0,  1,  2, 53,  3,  7, 54, 27,  4, 38, 41,  8, 34, 55, 48, 28,
    62,  5, 39, 46, 44, 42, 22,  9, 24, 35, 59, 56, 49, 18, 29, 11,
    63, 52,  6, 26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58, 17, 10,
    51, 25, 36, 32, 60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12
};
ایستا ثابت unsigned نویسه table_2_64[] = {
    63, 16, 62,  7, 15, 36, 61,  3,  6, 14, 22, 26, 35, 47, 60,  2,
     9,  5, 28, 11, 13, 21, 42, 19, 25, 31, 34, 40, 46, 52, 59,  1,
    17,  8, 37,  4, 23, 27, 48, 10, 29, 12, 43, 20, 32, 41, 53, 18,
    38, 24, 49, 30, 44, 33, 54, 39, 50, 45, 55, 51, 56, 57, 58,  0
};

#define FFSI(x) \
    بازگشت table_1_32[((x & -x) * 0x077cb531u) >> 27] + (x != 0);
#define FFSL(x) \
    بازگشت table_1_64[((x & -x) * 0x022fdd63cc95386dull) >> 58] + (x != 0);
#define CTZI(x) \
    بازگشت table_1_32[((x & -x) * 0x077cb531u) >> 27];
#define CTZL(x) \
    بازگشت table_1_64[((x & -x) * 0x022fdd63cc95386dull) >> 58];
#define CLZI(x)   \
    x |= x >> 1;  \
    x |= x >> 2;  \
    x |= x >> 4;  \
    x |= x >> 8;  \
    x |= x >> 16; \
    بازگشت table_2_32[(x * 0x07c4acddu) >> 27];
#define CLZL(x)   \
    x |= x >> 1;  \
    x |= x >> 2;  \
    x |= x >> 4;  \
    x |= x >> 8;  \
    x |= x >> 16; \
    x |= x >> 32; \
    بازگشت table_2_64[x * 0x03f79d71b4cb0a89ull >> 58];
#define POPCOUNTI(x, m)                                                   \
    x = x - ((x >> 1) & 0x55555555);                                      \
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);                       \
    x = (x + (x >> 4)) & 0xf0f0f0f;                                       \
    بازگشت ((x * 0x01010101) >> 24) & m; 
#define POPCOUNTL(x, m)                                                   \
    x = x - ((x >> 1) & 0x5555555555555555ull);                           \
    x = (x & 0x3333333333333333ull) + ((x >> 2) & 0x3333333333333333ull); \
    x = (x + (x >> 4)) & 0xf0f0f0f0f0f0f0full;                            \
    بازگشت ((x * 0x0101010101010101ull) >> 56) & m;

/* Returns one plus the index of the least significant 1-bit of x,
   or if x is zero, returns zero. */
صحیح BUILTIN(ffs) (صحیح x) { FFSI(x) }
صحیح BUILTIN(ffsll) (long long x) { FFSL(x) }
#اگر __SIZEOF_LONG__ == 4
صحیح BUILTIN(ffsl) (long x) __attribute__((alias(BUILTINN(ffs))));
#وگرنه
صحیح BUILTIN(ffsl) (long x) __attribute__((alias(BUILTINN(ffsll))));
#endif

/* Returns the number of leading 0-bits in x, starting at the most significant
   bit position. If x is 0, the result is undefined.  */
صحیح BUILTIN(clz) (unsigned صحیح x) { CLZI(x) }
صحیح BUILTIN(clzll) (unsigned long long x) { CLZL(x) }
#اگر __SIZEOF_LONG__ == 4
صحیح BUILTIN(clzl) (unsigned long x) __attribute__((alias(BUILTINN(clz))));
#وگرنه
صحیح BUILTIN(clzl) (unsigned long x) __attribute__((alias(BUILTINN(clzll))));
#endif

/* Returns the number of trailing 0-bits in x, starting at the least
   significant bit position. If x is 0, the result is undefined. */
صحیح BUILTIN(ctz) (unsigned صحیح x) { CTZI(x) }
صحیح BUILTIN(ctzll) (unsigned long long x) { CTZL(x) }
#اگر __SIZEOF_LONG__ == 4
صحیح BUILTIN(ctzl) (unsigned long x) __attribute__((alias(BUILTINN(ctz))));
#وگرنه
صحیح BUILTIN(ctzl) (unsigned long x) __attribute__((alias(BUILTINN(ctzll))));
#endif

/* Returns the number of leading redundant sign bits in x, i.e. the number
   of bits following the most significant bit that are identical to it.
   There are no special cases for 0 or other values. */
صحیح BUILTIN(clrsb) (صحیح x) { اگر (x < 0) x = ~x; x <<= 1; CLZI(x) }
صحیح BUILTIN(clrsbll) (long long x) { اگر (x < 0) x = ~x; x <<= 1; CLZL(x) }
#اگر __SIZEOF_LONG__ == 4
صحیح BUILTIN(clrsbl) (long x) __attribute__((alias(BUILTINN(clrsb))));
#وگرنه
صحیح BUILTIN(clrsbl) (long x) __attribute__((alias(BUILTINN(clrsbll))));
#endif

/* Returns the number of 1-bits in x.*/
صحیح BUILTIN(popcount) (unsigned صحیح x) { POPCOUNTI(x, 0x3f) }
صحیح BUILTIN(popcountll) (unsigned long long x) { POPCOUNTL(x, 0x7f) }
#اگر __SIZEOF_LONG__ == 4
صحیح BUILTIN(popcountl) (unsigned long x) __attribute__((alias(BUILTINN(popcount))));
#وگرنه
صحیح BUILTIN(popcountl ) (unsigned long x) __attribute__((alias(BUILTINN(popcountll))));
#endif

/* Returns the parity of x, i.e. the number of 1-bits in x modulo 2. */
صحیح BUILTIN(parity) (unsigned صحیح x) { POPCOUNTI(x, 0x01) }
صحیح BUILTIN(parityll) (unsigned long long x) { POPCOUNTL(x, 0x01) }
#اگر __SIZEOF_LONG__ == 4
صحیح BUILTIN(parityl) (unsigned long x) __attribute__((alias(BUILTINN(parity))));
#وگرنه
صحیح BUILTIN(parityl) (unsigned long x) __attribute__((alias(BUILTINN(parityll))));
#endif

#ifndef __TINYC__
#اگر defined(__GNUC__) && (__GNUC__ >= 6)
/* gcc overrides alias from __builtin_ffs... to ffs.. so use assembly code */
__asm__(".globl  __builtin_ffs");
__asm__(".set __builtin_ffs,__tcc_builtin_ffs");
__asm__(".globl  __builtin_ffsl");
__asm__(".set __builtin_ffsl,__tcc_builtin_ffsl");
__asm__(".globl  __builtin_ffsll");
__asm__(".set __builtin_ffsll,__tcc_builtin_ffsll");
#وگرنه
صحیح __builtin_ffs(صحیح x) __attribute__((alias("__tcc_builtin_ffs")));
صحیح __builtin_ffsl(long x) __attribute__((alias("__tcc_builtin_ffsl")));
صحیح __builtin_ffsll(long long x) __attribute__((alias("__tcc_builtin_ffsll")));
#endif
صحیح __builtin_clz(unsigned صحیح x) __attribute__((alias("__tcc_builtin_clz")));
صحیح __builtin_clzl(unsigned long x) __attribute__((alias("__tcc_builtin_clzl")));
صحیح __builtin_clzll(unsigned long long x) __attribute__((alias("__tcc_builtin_clzll")));
صحیح __builtin_ctz(unsigned صحیح x) __attribute__((alias("__tcc_builtin_ctz")));
صحیح __builtin_ctzl(unsigned long x) __attribute__((alias("__tcc_builtin_ctzl")));
صحیح __builtin_ctzll(unsigned long long x) __attribute__((alias("__tcc_builtin_ctzll")));
صحیح __builtin_clrsb(صحیح x) __attribute__((alias("__tcc_builtin_clrsb")));
صحیح __builtin_clrsbl(long x) __attribute__((alias("__tcc_builtin_clrsbl")));
صحیح __builtin_clrsbll(long long x) __attribute__((alias("__tcc_builtin_clrsbll")));
صحیح __builtin_popcount(unsigned صحیح x) __attribute__((alias("__tcc_builtin_popcount")));
صحیح __builtin_popcountl(unsigned long x) __attribute__((alias("__tcc_builtin_popcountl")));
صحیح __builtin_popcountll(unsigned long long x) __attribute__((alias("__tcc_builtin_popcountll")));
صحیح __builtin_parity(unsigned صحیح x) __attribute__((alias("__tcc_builtin_parity")));
صحیح __builtin_parityl(unsigned long x) __attribute__((alias("__tcc_builtin_parityl")));
صحیح __builtin_parityll(unsigned long long x) __attribute__((alias("__tcc_builtin_parityll")));
#endif
