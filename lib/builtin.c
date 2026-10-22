/* uses alias to allow building with gcc/clang */
#ifdef __TINYC__
#define	BUILTIN(x)	__builtin_##x
#define	BUILTINN(x)	"__builtin_" # x
#否则
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

static const unsigned char table_1_32[] = {
     0,  1, 28,  2, 29, 14, 24,  3, 30, 22, 20, 15, 25, 17,  4,  8, 
    31, 27, 13, 23, 21, 19, 16,  7, 26, 12, 18,  6, 11,  5, 10,  9
};
static const unsigned char table_2_32[32] = {
    31, 22, 30, 21, 18, 10, 29,  2, 20, 17, 15, 13,  9,  6, 28,  1,
    23, 19, 11,  3, 16, 14,  7, 24, 12,  4,  8, 25,  5, 26, 27,  0
};
static const unsigned char table_1_64[] = {
     0,  1,  2, 53,  3,  7, 54, 27,  4, 38, 41,  8, 34, 55, 48, 28,
    62,  5, 39, 46, 44, 42, 22,  9, 24, 35, 59, 56, 49, 18, 29, 11,
    63, 52,  6, 26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58, 17, 10,
    51, 25, 36, 32, 60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12
};
static const unsigned char table_2_64[] = {
    63, 16, 62,  7, 15, 36, 61,  3,  6, 14, 22, 26, 35, 47, 60,  2,
     9,  5, 28, 11, 13, 21, 42, 19, 25, 31, 34, 40, 46, 52, 59,  1,
    17,  8, 37,  4, 23, 27, 48, 10, 29, 12, 43, 20, 32, 41, 53, 18,
    38, 24, 49, 30, 44, 33, 54, 39, 50, 45, 55, 51, 56, 57, 58,  0
};

#define FFSI(x) \
    戻る table_1_32[((x & -x) * 0x077cb531u) >> 27] + (x != 0);
#define FFSL(x) \
    戻る table_1_64[((x & -x) * 0x022fdd63cc95386dull) >> 58] + (x != 0);
#define CTZI(x) \
    戻る table_1_32[((x & -x) * 0x077cb531u) >> 27];
#define CTZL(x) \
    戻る table_1_64[((x & -x) * 0x022fdd63cc95386dull) >> 58];
#define CLZI(x)   \
    x |= x >> 1;  \
    x |= x >> 2;  \
    x |= x >> 4;  \
    x |= x >> 8;  \
    x |= x >> 16; \
    戻る table_2_32[(x * 0x07c4acddu) >> 27];
#define CLZL(x)   \
    x |= x >> 1;  \
    x |= x >> 2;  \
    x |= x >> 4;  \
    x |= x >> 8;  \
    x |= x >> 16; \
    x |= x >> 32; \
    戻る table_2_64[x * 0x03f79d71b4cb0a89ull >> 58];
#define POPCOUNTI(x, m)                                                   \
    x = x - ((x >> 1) & 0x55555555);                                      \
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);                       \
    x = (x + (x >> 4)) & 0xf0f0f0f;                                       \
    戻る ((x * 0x01010101) >> 24) & m; 
#define POPCOUNTL(x, m)                                                   \
    x = x - ((x >> 1) & 0x5555555555555555ull);                           \
    x = (x & 0x3333333333333333ull) + ((x >> 2) & 0x3333333333333333ull); \
    x = (x + (x >> 4)) & 0xf0f0f0f0f0f0f0full;                            \
    戻る ((x * 0x0101010101010101ull) >> 56) & m;

/* Returns one plus the index of the least significant 1-bit of x,
   or if x is zero, returns zero. */
整数 BUILTIN(ffs) (整数 x) { FFSI(x) }
整数 BUILTIN(ffsll) (long long x) { FFSL(x) }
#もし __SIZEOF_LONG__ == 4
整数 BUILTIN(ffsl) (long x) __attribute__((alias(BUILTINN(ffs))));
#否则
整数 BUILTIN(ffsl) (long x) __attribute__((alias(BUILTINN(ffsll))));
#endif

/* Returns the number of leading 0-bits in x, starting at the most significant
   bit position. If x is 0, the result is undefined.  */
整数 BUILTIN(clz) (unsigned 整数 x) { CLZI(x) }
整数 BUILTIN(clzll) (unsigned long long x) { CLZL(x) }
#もし __SIZEOF_LONG__ == 4
整数 BUILTIN(clzl) (unsigned long x) __attribute__((alias(BUILTINN(clz))));
#否则
整数 BUILTIN(clzl) (unsigned long x) __attribute__((alias(BUILTINN(clzll))));
#endif

/* Returns the number of trailing 0-bits in x, starting at the least
   significant bit position. If x is 0, the result is undefined. */
整数 BUILTIN(ctz) (unsigned 整数 x) { CTZI(x) }
整数 BUILTIN(ctzll) (unsigned long long x) { CTZL(x) }
#もし __SIZEOF_LONG__ == 4
整数 BUILTIN(ctzl) (unsigned long x) __attribute__((alias(BUILTINN(ctz))));
#否则
整数 BUILTIN(ctzl) (unsigned long x) __attribute__((alias(BUILTINN(ctzll))));
#endif

/* Returns the number of leading redundant sign bits in x, i.e. the number
   of bits following the most significant bit that are identical to it.
   There are no special cases for 0 or other values. */
整数 BUILTIN(clrsb) (整数 x) { もし (x < 0) x = ~x; x <<= 1; CLZI(x) }
整数 BUILTIN(clrsbll) (long long x) { もし (x < 0) x = ~x; x <<= 1; CLZL(x) }
#もし __SIZEOF_LONG__ == 4
整数 BUILTIN(clrsbl) (long x) __attribute__((alias(BUILTINN(clrsb))));
#否则
整数 BUILTIN(clrsbl) (long x) __attribute__((alias(BUILTINN(clrsbll))));
#endif

/* Returns the number of 1-bits in x.*/
整数 BUILTIN(popcount) (unsigned 整数 x) { POPCOUNTI(x, 0x3f) }
整数 BUILTIN(popcountll) (unsigned long long x) { POPCOUNTL(x, 0x7f) }
#もし __SIZEOF_LONG__ == 4
整数 BUILTIN(popcountl) (unsigned long x) __attribute__((alias(BUILTINN(popcount))));
#否则
整数 BUILTIN(popcountl ) (unsigned long x) __attribute__((alias(BUILTINN(popcountll))));
#endif

/* Returns the parity of x, i.e. the number of 1-bits in x modulo 2. */
整数 BUILTIN(parity) (unsigned 整数 x) { POPCOUNTI(x, 0x01) }
整数 BUILTIN(parityll) (unsigned long long x) { POPCOUNTL(x, 0x01) }
#もし __SIZEOF_LONG__ == 4
整数 BUILTIN(parityl) (unsigned long x) __attribute__((alias(BUILTINN(parity))));
#否则
整数 BUILTIN(parityl) (unsigned long x) __attribute__((alias(BUILTINN(parityll))));
#endif

#ifndef __TINYC__
#もし defined(__GNUC__) && (__GNUC__ >= 6)
/* gcc overrides alias from __builtin_ffs... to ffs.. so use assembly code */
__asm__(".globl  __builtin_ffs");
__asm__(".set __builtin_ffs,__tcc_builtin_ffs");
__asm__(".globl  __builtin_ffsl");
__asm__(".set __builtin_ffsl,__tcc_builtin_ffsl");
__asm__(".globl  __builtin_ffsll");
__asm__(".set __builtin_ffsll,__tcc_builtin_ffsll");
#否则
整数 __builtin_ffs(整数 x) __attribute__((alias("__tcc_builtin_ffs")));
整数 __builtin_ffsl(long x) __attribute__((alias("__tcc_builtin_ffsl")));
整数 __builtin_ffsll(long long x) __attribute__((alias("__tcc_builtin_ffsll")));
#endif
整数 __builtin_clz(unsigned 整数 x) __attribute__((alias("__tcc_builtin_clz")));
整数 __builtin_clzl(unsigned long x) __attribute__((alias("__tcc_builtin_clzl")));
整数 __builtin_clzll(unsigned long long x) __attribute__((alias("__tcc_builtin_clzll")));
整数 __builtin_ctz(unsigned 整数 x) __attribute__((alias("__tcc_builtin_ctz")));
整数 __builtin_ctzl(unsigned long x) __attribute__((alias("__tcc_builtin_ctzl")));
整数 __builtin_ctzll(unsigned long long x) __attribute__((alias("__tcc_builtin_ctzll")));
整数 __builtin_clrsb(整数 x) __attribute__((alias("__tcc_builtin_clrsb")));
整数 __builtin_clrsbl(long x) __attribute__((alias("__tcc_builtin_clrsbl")));
整数 __builtin_clrsbll(long long x) __attribute__((alias("__tcc_builtin_clrsbll")));
整数 __builtin_popcount(unsigned 整数 x) __attribute__((alias("__tcc_builtin_popcount")));
整数 __builtin_popcountl(unsigned long x) __attribute__((alias("__tcc_builtin_popcountl")));
整数 __builtin_popcountll(unsigned long long x) __attribute__((alias("__tcc_builtin_popcountll")));
整数 __builtin_parity(unsigned 整数 x) __attribute__((alias("__tcc_builtin_parity")));
整数 __builtin_parityl(unsigned long x) __attribute__((alias("__tcc_builtin_parityl")));
整数 __builtin_parityll(unsigned long long x) __attribute__((alias("__tcc_builtin_parityll")));
#endif
