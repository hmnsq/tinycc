/* uses alias to allow building with gcc/clang */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __TINYC__
#ವ್ಯಾಖ್ಯಾನಿಸು	BUILTIN(x)	__builtin_##x
#ವ್ಯಾಖ್ಯಾನಿಸು	BUILTINN(x)	"__builtin_" # x
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು	BUILTIN(x)	__tcc_builtin_##x
#ವ್ಯಾಖ್ಯಾನಿಸು	BUILTINN(x)	"__tcc_builtin_" # x
#ಆದರೆ_ಅಂತ್ಯ

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

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಕೋಷ್ಟಕ_1_32[] = {
     0,  1, 28,  2, 29, 14, 24,  3, 30, 22, 20, 15, 25, 17,  4,  8, 
    31, 27, 13, 23, 21, 19, 16,  7, 26, 12, 18,  6, 11,  5, 10,  9
};
ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಕೋಷ್ಟಕ_2_32[32] = {
    31, 22, 30, 21, 18, 10, 29,  2, 20, 17, 15, 13,  9,  6, 28,  1,
    23, 19, 11,  3, 16, 14,  7, 24, 12,  4,  8, 25,  5, 26, 27,  0
};
ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಕೋಷ್ಟಕ_1_64[] = {
     0,  1,  2, 53,  3,  7, 54, 27,  4, 38, 41,  8, 34, 55, 48, 28,
    62,  5, 39, 46, 44, 42, 22,  9, 24, 35, 59, 56, 49, 18, 29, 11,
    63, 52,  6, 26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58, 17, 10,
    51, 25, 36, 32, 60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12
};
ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಕೋಷ್ಟಕ_2_64[] = {
    63, 16, 62,  7, 15, 36, 61,  3,  6, 14, 22, 26, 35, 47, 60,  2,
     9,  5, 28, 11, 13, 21, 42, 19, 25, 31, 34, 40, 46, 52, 59,  1,
    17,  8, 37,  4, 23, 27, 48, 10, 29, 12, 43, 20, 32, 41, 53, 18,
    38, 24, 49, 30, 44, 33, 54, 39, 50, 45, 55, 51, 56, 57, 58,  0
};

#ವ್ಯಾಖ್ಯಾನಿಸು FFSI(x) \
    ಹಿಂತಿರುಗಿ ಕೋಷ್ಟಕ_1_32[((x & -x) * 0x077cb531u) >> 27] + (x != 0);
#ವ್ಯಾಖ್ಯಾನಿಸು FFSL(x) \
    ಹಿಂತಿರುಗಿ ಕೋಷ್ಟಕ_1_64[((x & -x) * 0x022fdd63cc95386dull) >> 58] + (x != 0);
#ವ್ಯಾಖ್ಯಾನಿಸು CTZI(x) \
    ಹಿಂತಿರುಗಿ ಕೋಷ್ಟಕ_1_32[((x & -x) * 0x077cb531u) >> 27];
#ವ್ಯಾಖ್ಯಾನಿಸು CTZL(x) \
    ಹಿಂತಿರುಗಿ ಕೋಷ್ಟಕ_1_64[((x & -x) * 0x022fdd63cc95386dull) >> 58];
#ವ್ಯಾಖ್ಯಾನಿಸು CLZI(x)   \
    x |= x >> 1;  \
    x |= x >> 2;  \
    x |= x >> 4;  \
    x |= x >> 8;  \
    x |= x >> 16; \
    ಹಿಂತಿರುಗಿ ಕೋಷ್ಟಕ_2_32[(x * 0x07c4acddu) >> 27];
#ವ್ಯಾಖ್ಯಾನಿಸು CLZL(x)   \
    x |= x >> 1;  \
    x |= x >> 2;  \
    x |= x >> 4;  \
    x |= x >> 8;  \
    x |= x >> 16; \
    x |= x >> 32; \
    ಹಿಂತಿರುಗಿ ಕೋಷ್ಟಕ_2_64[x * 0x03f79d71b4cb0a89ull >> 58];
#ವ್ಯಾಖ್ಯಾನಿಸು POPCOUNTI(x, m)                                                   \
    x = x - ((x >> 1) & 0x55555555);                                      \
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);                       \
    x = (x + (x >> 4)) & 0xf0f0f0f;                                       \
    ಹಿಂತಿರುಗಿ ((x * 0x01010101) >> 24) & m; 
#ವ್ಯಾಖ್ಯಾನಿಸು POPCOUNTL(x, m)                                                   \
    x = x - ((x >> 1) & 0x5555555555555555ull);                           \
    x = (x & 0x3333333333333333ull) + ((x >> 2) & 0x3333333333333333ull); \
    x = (x + (x >> 4)) & 0xf0f0f0f0f0f0f0full;                            \
    ಹಿಂತಿರುಗಿ ((x * 0x0101010101010101ull) >> 56) & m;

/* Returns one plus the index of the least significant 1-bit of x,
   or if x is zero, returns zero. */
ಪೂರ್ಣಾಂಕ BUILTIN(ffs) (ಪೂರ್ಣಾಂಕ x) { FFSI(x) }
ಪೂರ್ಣಾಂಕ BUILTIN(ffsll) (ದೀರ್ಘ ದೀರ್ಘ x) { FFSL(x) }
#ಆದರೆ __SIZEOF_LONG__ == 4
ಪೂರ್ಣಾಂಕ BUILTIN(ffsl) (ದೀರ್ಘ x) __attribute__((alias(BUILTINN(ffs))));
#ಇಲ್ಲದಿದ್ದರೆ
ಪೂರ್ಣಾಂಕ BUILTIN(ffsl) (ದೀರ್ಘ x) __attribute__((alias(BUILTINN(ffsll))));
#ಆದರೆ_ಅಂತ್ಯ

/* Returns the number of leading 0-bits in x, starting at the most significant
   bit position. If x is 0, the result is undefined.  */
ಪೂರ್ಣಾಂಕ BUILTIN(clz) (ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ x) { CLZI(x) }
ಪೂರ್ಣಾಂಕ BUILTIN(clzll) (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ x) { CLZL(x) }
#ಆದರೆ __SIZEOF_LONG__ == 4
ಪೂರ್ಣಾಂಕ BUILTIN(clzl) (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ x) __attribute__((alias(BUILTINN(clz))));
#ಇಲ್ಲದಿದ್ದರೆ
ಪೂರ್ಣಾಂಕ BUILTIN(clzl) (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ x) __attribute__((alias(BUILTINN(clzll))));
#ಆದರೆ_ಅಂತ್ಯ

/* Returns the number of trailing 0-bits in x, starting at the least
   significant bit position. If x is 0, the result is undefined. */
ಪೂರ್ಣಾಂಕ BUILTIN(ctz) (ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ x) { CTZI(x) }
ಪೂರ್ಣಾಂಕ BUILTIN(ctzll) (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ x) { CTZL(x) }
#ಆದರೆ __SIZEOF_LONG__ == 4
ಪೂರ್ಣಾಂಕ BUILTIN(ctzl) (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ x) __attribute__((alias(BUILTINN(ctz))));
#ಇಲ್ಲದಿದ್ದರೆ
ಪೂರ್ಣಾಂಕ BUILTIN(ctzl) (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ x) __attribute__((alias(BUILTINN(ctzll))));
#ಆದರೆ_ಅಂತ್ಯ

/* Returns the number of leading redundant sign bits in x, i.e. the number
   of bits following the most significant bit that are identical to it.
   There are no special cases for 0 or other values. */
ಪೂರ್ಣಾಂಕ BUILTIN(clrsb) (ಪೂರ್ಣಾಂಕ x) { ಆದರೆ (x < 0) x = ~x; x <<= 1; CLZI(x) }
ಪೂರ್ಣಾಂಕ BUILTIN(clrsbll) (ದೀರ್ಘ ದೀರ್ಘ x) { ಆದರೆ (x < 0) x = ~x; x <<= 1; CLZL(x) }
#ಆದರೆ __SIZEOF_LONG__ == 4
ಪೂರ್ಣಾಂಕ BUILTIN(clrsbl) (ದೀರ್ಘ x) __attribute__((alias(BUILTINN(clrsb))));
#ಇಲ್ಲದಿದ್ದರೆ
ಪೂರ್ಣಾಂಕ BUILTIN(clrsbl) (ದೀರ್ಘ x) __attribute__((alias(BUILTINN(clrsbll))));
#ಆದರೆ_ಅಂತ್ಯ

/* Returns the number of 1-bits in x.*/
ಪೂರ್ಣಾಂಕ BUILTIN(popcount) (ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ x) { POPCOUNTI(x, 0x3f) }
ಪೂರ್ಣಾಂಕ BUILTIN(popcountll) (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ x) { POPCOUNTL(x, 0x7f) }
#ಆದರೆ __SIZEOF_LONG__ == 4
ಪೂರ್ಣಾಂಕ BUILTIN(popcountl) (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ x) __attribute__((alias(BUILTINN(popcount))));
#ಇಲ್ಲದಿದ್ದರೆ
ಪೂರ್ಣಾಂಕ BUILTIN(popcountl ) (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ x) __attribute__((alias(BUILTINN(popcountll))));
#ಆದರೆ_ಅಂತ್ಯ

/* Returns the parity of x, i.e. the number of 1-bits in x modulo 2. */
ಪೂರ್ಣಾಂಕ BUILTIN(parity) (ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ x) { POPCOUNTI(x, 0x01) }
ಪೂರ್ಣಾಂಕ BUILTIN(parityll) (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ x) { POPCOUNTL(x, 0x01) }
#ಆದರೆ __SIZEOF_LONG__ == 4
ಪೂರ್ಣಾಂಕ BUILTIN(parityl) (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ x) __attribute__((alias(BUILTINN(parity))));
#ಇಲ್ಲದಿದ್ದರೆ
ಪೂರ್ಣಾಂಕ BUILTIN(parityl) (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ x) __attribute__((alias(BUILTINN(parityll))));
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __TINYC__
#ಆದರೆ defined(__GNUC__) && (__GNUC__ >= 6)
/* gcc overrides alias from __builtin_ffs... to ffs.. so use assembly code */
__asm__(".globl  __builtin_ffs");
__asm__(".set __builtin_ffs,__tcc_builtin_ffs");
__asm__(".globl  __builtin_ffsl");
__asm__(".set __builtin_ffsl,__tcc_builtin_ffsl");
__asm__(".globl  __builtin_ffsll");
__asm__(".set __builtin_ffsll,__tcc_builtin_ffsll");
#ಇಲ್ಲದಿದ್ದರೆ
ಪೂರ್ಣಾಂಕ __builtin_ffs(ಪೂರ್ಣಾಂಕ x) __attribute__((alias("__tcc_builtin_ffs")));
ಪೂರ್ಣಾಂಕ __builtin_ffsl(ದೀರ್ಘ x) __attribute__((alias("__tcc_builtin_ffsl")));
ಪೂರ್ಣಾಂಕ __builtin_ffsll(ದೀರ್ಘ ದೀರ್ಘ x) __attribute__((alias("__tcc_builtin_ffsll")));
#ಆದರೆ_ಅಂತ್ಯ
ಪೂರ್ಣಾಂಕ __builtin_clz(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ x) __attribute__((alias("__tcc_builtin_clz")));
ಪೂರ್ಣಾಂಕ __builtin_clzl(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ x) __attribute__((alias("__tcc_builtin_clzl")));
ಪೂರ್ಣಾಂಕ __builtin_clzll(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ x) __attribute__((alias("__tcc_builtin_clzll")));
ಪೂರ್ಣಾಂಕ __builtin_ctz(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ x) __attribute__((alias("__tcc_builtin_ctz")));
ಪೂರ್ಣಾಂಕ __builtin_ctzl(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ x) __attribute__((alias("__tcc_builtin_ctzl")));
ಪೂರ್ಣಾಂಕ __builtin_ctzll(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ x) __attribute__((alias("__tcc_builtin_ctzll")));
ಪೂರ್ಣಾಂಕ __builtin_clrsb(ಪೂರ್ಣಾಂಕ x) __attribute__((alias("__tcc_builtin_clrsb")));
ಪೂರ್ಣಾಂಕ __builtin_clrsbl(ದೀರ್ಘ x) __attribute__((alias("__tcc_builtin_clrsbl")));
ಪೂರ್ಣಾಂಕ __builtin_clrsbll(ದೀರ್ಘ ದೀರ್ಘ x) __attribute__((alias("__tcc_builtin_clrsbll")));
ಪೂರ್ಣಾಂಕ __builtin_popcount(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ x) __attribute__((alias("__tcc_builtin_popcount")));
ಪೂರ್ಣಾಂಕ __builtin_popcountl(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ x) __attribute__((alias("__tcc_builtin_popcountl")));
ಪೂರ್ಣಾಂಕ __builtin_popcountll(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ x) __attribute__((alias("__tcc_builtin_popcountll")));
ಪೂರ್ಣಾಂಕ __builtin_parity(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ x) __attribute__((alias("__tcc_builtin_parity")));
ಪೂರ್ಣಾಂಕ __builtin_parityl(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ x) __attribute__((alias("__tcc_builtin_parityl")));
ಪೂರ್ಣಾಂಕ __builtin_parityll(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ x) __attribute__((alias("__tcc_builtin_parityll")));
#ಆದರೆ_ಅಂತ್ಯ
