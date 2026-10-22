/* uses alias to allow building with gcc/clang */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __TINYC__
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	BUILTIN(x)	__builtin_##x
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	BUILTINN(x)	"__builtin_" # x
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	BUILTIN(x)	__tcc_builtin_##x
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	BUILTINN(x)	"__tcc_builtin_" # x
#ਜੇ_ਅੰਤ

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

ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਸਾਰਣੀ_1_32[] = {
     0,  1, 28,  2, 29, 14, 24,  3, 30, 22, 20, 15, 25, 17,  4,  8, 
    31, 27, 13, 23, 21, 19, 16,  7, 26, 12, 18,  6, 11,  5, 10,  9
};
ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਸਾਰਣੀ_2_32[32] = {
    31, 22, 30, 21, 18, 10, 29,  2, 20, 17, 15, 13,  9,  6, 28,  1,
    23, 19, 11,  3, 16, 14,  7, 24, 12,  4,  8, 25,  5, 26, 27,  0
};
ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਸਾਰਣੀ_1_64[] = {
     0,  1,  2, 53,  3,  7, 54, 27,  4, 38, 41,  8, 34, 55, 48, 28,
    62,  5, 39, 46, 44, 42, 22,  9, 24, 35, 59, 56, 49, 18, 29, 11,
    63, 52,  6, 26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58, 17, 10,
    51, 25, 36, 32, 60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12
};
ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਸਾਰਣੀ_2_64[] = {
    63, 16, 62,  7, 15, 36, 61,  3,  6, 14, 22, 26, 35, 47, 60,  2,
     9,  5, 28, 11, 13, 21, 42, 19, 25, 31, 34, 40, 46, 52, 59,  1,
    17,  8, 37,  4, 23, 27, 48, 10, 29, 12, 43, 20, 32, 41, 53, 18,
    38, 24, 49, 30, 44, 33, 54, 39, 50, 45, 55, 51, 56, 57, 58,  0
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FFSI(x) \
    ਵਾਪਸ ਸਾਰਣੀ_1_32[((x & -x) * 0x077cb531u) >> 27] + (x != 0);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FFSL(x) \
    ਵਾਪਸ ਸਾਰਣੀ_1_64[((x & -x) * 0x022fdd63cc95386dull) >> 58] + (x != 0);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CTZI(x) \
    ਵਾਪਸ ਸਾਰਣੀ_1_32[((x & -x) * 0x077cb531u) >> 27];
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CTZL(x) \
    ਵਾਪਸ ਸਾਰਣੀ_1_64[((x & -x) * 0x022fdd63cc95386dull) >> 58];
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLZI(x)   \
    x |= x >> 1;  \
    x |= x >> 2;  \
    x |= x >> 4;  \
    x |= x >> 8;  \
    x |= x >> 16; \
    ਵਾਪਸ ਸਾਰਣੀ_2_32[(x * 0x07c4acddu) >> 27];
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLZL(x)   \
    x |= x >> 1;  \
    x |= x >> 2;  \
    x |= x >> 4;  \
    x |= x >> 8;  \
    x |= x >> 16; \
    x |= x >> 32; \
    ਵਾਪਸ ਸਾਰਣੀ_2_64[x * 0x03f79d71b4cb0a89ull >> 58];
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POPCOUNTI(x, m)                                                   \
    x = x - ((x >> 1) & 0x55555555);                                      \
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);                       \
    x = (x + (x >> 4)) & 0xf0f0f0f;                                       \
    ਵਾਪਸ ((x * 0x01010101) >> 24) & m; 
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POPCOUNTL(x, m)                                                   \
    x = x - ((x >> 1) & 0x5555555555555555ull);                           \
    x = (x & 0x3333333333333333ull) + ((x >> 2) & 0x3333333333333333ull); \
    x = (x + (x >> 4)) & 0xf0f0f0f0f0f0f0full;                            \
    ਵਾਪਸ ((x * 0x0101010101010101ull) >> 56) & m;

/* Returns one plus the index of the least significant 1-bit of x,
   or if x is zero, returns zero. */
ਪੂਰਨ BUILTIN(ffs) (ਪੂਰਨ x) { FFSI(x) }
ਪੂਰਨ BUILTIN(ffsll) (ਲੰਮਾ ਲੰਮਾ x) { FFSL(x) }
#ਜੇ __SIZEOF_LONG__ == 4
ਪੂਰਨ BUILTIN(ffsl) (ਲੰਮਾ x) __attribute__((alias(BUILTINN(ffs))));
#ਨਹੀਂਤਾਂ
ਪੂਰਨ BUILTIN(ffsl) (ਲੰਮਾ x) __attribute__((alias(BUILTINN(ffsll))));
#ਜੇ_ਅੰਤ

/* Returns the number of leading 0-bits in x, starting at the most significant
   bit position. If x is 0, the result is undefined.  */
ਪੂਰਨ BUILTIN(clz) (ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ x) { CLZI(x) }
ਪੂਰਨ BUILTIN(clzll) (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ x) { CLZL(x) }
#ਜੇ __SIZEOF_LONG__ == 4
ਪੂਰਨ BUILTIN(clzl) (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ x) __attribute__((alias(BUILTINN(clz))));
#ਨਹੀਂਤਾਂ
ਪੂਰਨ BUILTIN(clzl) (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ x) __attribute__((alias(BUILTINN(clzll))));
#ਜੇ_ਅੰਤ

/* Returns the number of trailing 0-bits in x, starting at the least
   significant bit position. If x is 0, the result is undefined. */
ਪੂਰਨ BUILTIN(ctz) (ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ x) { CTZI(x) }
ਪੂਰਨ BUILTIN(ctzll) (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ x) { CTZL(x) }
#ਜੇ __SIZEOF_LONG__ == 4
ਪੂਰਨ BUILTIN(ctzl) (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ x) __attribute__((alias(BUILTINN(ctz))));
#ਨਹੀਂਤਾਂ
ਪੂਰਨ BUILTIN(ctzl) (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ x) __attribute__((alias(BUILTINN(ctzll))));
#ਜੇ_ਅੰਤ

/* Returns the number of leading redundant sign bits in x, i.e. the number
   of bits following the most significant bit that are identical to it.
   There are no special cases for 0 or other values. */
ਪੂਰਨ BUILTIN(clrsb) (ਪੂਰਨ x) { ਜੇ (x < 0) x = ~x; x <<= 1; CLZI(x) }
ਪੂਰਨ BUILTIN(clrsbll) (ਲੰਮਾ ਲੰਮਾ x) { ਜੇ (x < 0) x = ~x; x <<= 1; CLZL(x) }
#ਜੇ __SIZEOF_LONG__ == 4
ਪੂਰਨ BUILTIN(clrsbl) (ਲੰਮਾ x) __attribute__((alias(BUILTINN(clrsb))));
#ਨਹੀਂਤਾਂ
ਪੂਰਨ BUILTIN(clrsbl) (ਲੰਮਾ x) __attribute__((alias(BUILTINN(clrsbll))));
#ਜੇ_ਅੰਤ

/* Returns the number of 1-bits in x.*/
ਪੂਰਨ BUILTIN(popcount) (ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ x) { POPCOUNTI(x, 0x3f) }
ਪੂਰਨ BUILTIN(popcountll) (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ x) { POPCOUNTL(x, 0x7f) }
#ਜੇ __SIZEOF_LONG__ == 4
ਪੂਰਨ BUILTIN(popcountl) (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ x) __attribute__((alias(BUILTINN(popcount))));
#ਨਹੀਂਤਾਂ
ਪੂਰਨ BUILTIN(popcountl ) (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ x) __attribute__((alias(BUILTINN(popcountll))));
#ਜੇ_ਅੰਤ

/* Returns the parity of x, i.e. the number of 1-bits in x modulo 2. */
ਪੂਰਨ BUILTIN(parity) (ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ x) { POPCOUNTI(x, 0x01) }
ਪੂਰਨ BUILTIN(parityll) (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ x) { POPCOUNTL(x, 0x01) }
#ਜੇ __SIZEOF_LONG__ == 4
ਪੂਰਨ BUILTIN(parityl) (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ x) __attribute__((alias(BUILTINN(parity))));
#ਨਹੀਂਤਾਂ
ਪੂਰਨ BUILTIN(parityl) (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ x) __attribute__((alias(BUILTINN(parityll))));
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __TINYC__
#ਜੇ defined(__GNUC__) && (__GNUC__ >= 6)
/* gcc overrides alias from __builtin_ffs... to ffs.. so use assembly code */
__asm__(".globl  __builtin_ffs");
__asm__(".set __builtin_ffs,__tcc_builtin_ffs");
__asm__(".globl  __builtin_ffsl");
__asm__(".set __builtin_ffsl,__tcc_builtin_ffsl");
__asm__(".globl  __builtin_ffsll");
__asm__(".set __builtin_ffsll,__tcc_builtin_ffsll");
#ਨਹੀਂਤਾਂ
ਪੂਰਨ __builtin_ffs(ਪੂਰਨ x) __attribute__((alias("__tcc_builtin_ffs")));
ਪੂਰਨ __builtin_ffsl(ਲੰਮਾ x) __attribute__((alias("__tcc_builtin_ffsl")));
ਪੂਰਨ __builtin_ffsll(ਲੰਮਾ ਲੰਮਾ x) __attribute__((alias("__tcc_builtin_ffsll")));
#ਜੇ_ਅੰਤ
ਪੂਰਨ __builtin_clz(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ x) __attribute__((alias("__tcc_builtin_clz")));
ਪੂਰਨ __builtin_clzl(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ x) __attribute__((alias("__tcc_builtin_clzl")));
ਪੂਰਨ __builtin_clzll(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ x) __attribute__((alias("__tcc_builtin_clzll")));
ਪੂਰਨ __builtin_ctz(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ x) __attribute__((alias("__tcc_builtin_ctz")));
ਪੂਰਨ __builtin_ctzl(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ x) __attribute__((alias("__tcc_builtin_ctzl")));
ਪੂਰਨ __builtin_ctzll(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ x) __attribute__((alias("__tcc_builtin_ctzll")));
ਪੂਰਨ __builtin_clrsb(ਪੂਰਨ x) __attribute__((alias("__tcc_builtin_clrsb")));
ਪੂਰਨ __builtin_clrsbl(ਲੰਮਾ x) __attribute__((alias("__tcc_builtin_clrsbl")));
ਪੂਰਨ __builtin_clrsbll(ਲੰਮਾ ਲੰਮਾ x) __attribute__((alias("__tcc_builtin_clrsbll")));
ਪੂਰਨ __builtin_popcount(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ x) __attribute__((alias("__tcc_builtin_popcount")));
ਪੂਰਨ __builtin_popcountl(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ x) __attribute__((alias("__tcc_builtin_popcountl")));
ਪੂਰਨ __builtin_popcountll(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ x) __attribute__((alias("__tcc_builtin_popcountll")));
ਪੂਰਨ __builtin_parity(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ x) __attribute__((alias("__tcc_builtin_parity")));
ਪੂਰਨ __builtin_parityl(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ x) __attribute__((alias("__tcc_builtin_parityl")));
ਪੂਰਨ __builtin_parityll(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ x) __attribute__((alias("__tcc_builtin_parityll")));
#ਜੇ_ਅੰਤ
