/* uses alias to allow building with gcc/clang */
#यदि_परिभाषितम् __TINYC__
#परिभाषय	BUILTIN(x)	__builtin_##x
#परिभाषय	BUILTINN(x)	"__builtin_" # x
#अन्यथा
#परिभाषय	BUILTIN(x)	__tcc_builtin_##x
#परिभाषय	BUILTINN(x)	"__tcc_builtin_" # x
#यदि_अन्तः

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

स्थिर ध्रुव अचिह्नित वर्ण सारणी_1_32[] = {
     0,  1, 28,  2, 29, 14, 24,  3, 30, 22, 20, 15, 25, 17,  4,  8, 
    31, 27, 13, 23, 21, 19, 16,  7, 26, 12, 18,  6, 11,  5, 10,  9
};
स्थिर ध्रुव अचिह्नित वर्ण सारणी_2_32[32] = {
    31, 22, 30, 21, 18, 10, 29,  2, 20, 17, 15, 13,  9,  6, 28,  1,
    23, 19, 11,  3, 16, 14,  7, 24, 12,  4,  8, 25,  5, 26, 27,  0
};
स्थिर ध्रुव अचिह्नित वर्ण सारणी_1_64[] = {
     0,  1,  2, 53,  3,  7, 54, 27,  4, 38, 41,  8, 34, 55, 48, 28,
    62,  5, 39, 46, 44, 42, 22,  9, 24, 35, 59, 56, 49, 18, 29, 11,
    63, 52,  6, 26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58, 17, 10,
    51, 25, 36, 32, 60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12
};
स्थिर ध्रुव अचिह्नित वर्ण सारणी_2_64[] = {
    63, 16, 62,  7, 15, 36, 61,  3,  6, 14, 22, 26, 35, 47, 60,  2,
     9,  5, 28, 11, 13, 21, 42, 19, 25, 31, 34, 40, 46, 52, 59,  1,
    17,  8, 37,  4, 23, 27, 48, 10, 29, 12, 43, 20, 32, 41, 53, 18,
    38, 24, 49, 30, 44, 33, 54, 39, 50, 45, 55, 51, 56, 57, 58,  0
};

#परिभाषय FFSI(x) \
    प्रत्यागम सारणी_1_32[((x & -x) * 0x077cb531u) >> 27] + (x != 0);
#परिभाषय FFSL(x) \
    प्रत्यागम सारणी_1_64[((x & -x) * 0x022fdd63cc95386dull) >> 58] + (x != 0);
#परिभाषय CTZI(x) \
    प्रत्यागम सारणी_1_32[((x & -x) * 0x077cb531u) >> 27];
#परिभाषय CTZL(x) \
    प्रत्यागम सारणी_1_64[((x & -x) * 0x022fdd63cc95386dull) >> 58];
#परिभाषय CLZI(x)   \
    x |= x >> 1;  \
    x |= x >> 2;  \
    x |= x >> 4;  \
    x |= x >> 8;  \
    x |= x >> 16; \
    प्रत्यागम सारणी_2_32[(x * 0x07c4acddu) >> 27];
#परिभाषय CLZL(x)   \
    x |= x >> 1;  \
    x |= x >> 2;  \
    x |= x >> 4;  \
    x |= x >> 8;  \
    x |= x >> 16; \
    x |= x >> 32; \
    प्रत्यागम सारणी_2_64[x * 0x03f79d71b4cb0a89ull >> 58];
#परिभाषय POPCOUNTI(x, m)                                                   \
    x = x - ((x >> 1) & 0x55555555);                                      \
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);                       \
    x = (x + (x >> 4)) & 0xf0f0f0f;                                       \
    प्रत्यागम ((x * 0x01010101) >> 24) & m; 
#परिभाषय POPCOUNTL(x, m)                                                   \
    x = x - ((x >> 1) & 0x5555555555555555ull);                           \
    x = (x & 0x3333333333333333ull) + ((x >> 2) & 0x3333333333333333ull); \
    x = (x + (x >> 4)) & 0xf0f0f0f0f0f0f0full;                            \
    प्रत्यागम ((x * 0x0101010101010101ull) >> 56) & m;

/* Returns one plus the index of the least significant 1-bit of x,
   or if x is zero, returns zero. */
पूर्णाङ्क BUILTIN(ffs) (पूर्णाङ्क x) { FFSI(x) }
पूर्णाङ्क BUILTIN(ffsll) (दीर्घ दीर्घ x) { FFSL(x) }
#यदि __SIZEOF_LONG__ == 4
पूर्णाङ्क BUILTIN(ffsl) (दीर्घ x) __attribute__((alias(BUILTINN(ffs))));
#अन्यथा
पूर्णाङ्क BUILTIN(ffsl) (दीर्घ x) __attribute__((alias(BUILTINN(ffsll))));
#यदि_अन्तः

/* Returns the number of leading 0-bits in x, starting at the most significant
   bit position. If x is 0, the result is undefined.  */
पूर्णाङ्क BUILTIN(clz) (अचिह्नित पूर्णाङ्क x) { CLZI(x) }
पूर्णाङ्क BUILTIN(clzll) (अचिह्नित दीर्घ दीर्घ x) { CLZL(x) }
#यदि __SIZEOF_LONG__ == 4
पूर्णाङ्क BUILTIN(clzl) (अचिह्नित दीर्घ x) __attribute__((alias(BUILTINN(clz))));
#अन्यथा
पूर्णाङ्क BUILTIN(clzl) (अचिह्नित दीर्घ x) __attribute__((alias(BUILTINN(clzll))));
#यदि_अन्तः

/* Returns the number of trailing 0-bits in x, starting at the least
   significant bit position. If x is 0, the result is undefined. */
पूर्णाङ्क BUILTIN(ctz) (अचिह्नित पूर्णाङ्क x) { CTZI(x) }
पूर्णाङ्क BUILTIN(ctzll) (अचिह्नित दीर्घ दीर्घ x) { CTZL(x) }
#यदि __SIZEOF_LONG__ == 4
पूर्णाङ्क BUILTIN(ctzl) (अचिह्नित दीर्घ x) __attribute__((alias(BUILTINN(ctz))));
#अन्यथा
पूर्णाङ्क BUILTIN(ctzl) (अचिह्नित दीर्घ x) __attribute__((alias(BUILTINN(ctzll))));
#यदि_अन्तः

/* Returns the number of leading redundant sign bits in x, i.e. the number
   of bits following the most significant bit that are identical to it.
   There are no special cases for 0 or other values. */
पूर्णाङ्क BUILTIN(clrsb) (पूर्णाङ्क x) { यदि (x < 0) x = ~x; x <<= 1; CLZI(x) }
पूर्णाङ्क BUILTIN(clrsbll) (दीर्घ दीर्घ x) { यदि (x < 0) x = ~x; x <<= 1; CLZL(x) }
#यदि __SIZEOF_LONG__ == 4
पूर्णाङ्क BUILTIN(clrsbl) (दीर्घ x) __attribute__((alias(BUILTINN(clrsb))));
#अन्यथा
पूर्णाङ्क BUILTIN(clrsbl) (दीर्घ x) __attribute__((alias(BUILTINN(clrsbll))));
#यदि_अन्तः

/* Returns the number of 1-bits in x.*/
पूर्णाङ्क BUILTIN(popcount) (अचिह्नित पूर्णाङ्क x) { POPCOUNTI(x, 0x3f) }
पूर्णाङ्क BUILTIN(popcountll) (अचिह्नित दीर्घ दीर्घ x) { POPCOUNTL(x, 0x7f) }
#यदि __SIZEOF_LONG__ == 4
पूर्णाङ्क BUILTIN(popcountl) (अचिह्नित दीर्घ x) __attribute__((alias(BUILTINN(popcount))));
#अन्यथा
पूर्णाङ्क BUILTIN(popcountl ) (अचिह्नित दीर्घ x) __attribute__((alias(BUILTINN(popcountll))));
#यदि_अन्तः

/* Returns the parity of x, i.e. the number of 1-bits in x modulo 2. */
पूर्णाङ्क BUILTIN(parity) (अचिह्नित पूर्णाङ्क x) { POPCOUNTI(x, 0x01) }
पूर्णाङ्क BUILTIN(parityll) (अचिह्नित दीर्घ दीर्घ x) { POPCOUNTL(x, 0x01) }
#यदि __SIZEOF_LONG__ == 4
पूर्णाङ्क BUILTIN(parityl) (अचिह्नित दीर्घ x) __attribute__((alias(BUILTINN(parity))));
#अन्यथा
पूर्णाङ्क BUILTIN(parityl) (अचिह्नित दीर्घ x) __attribute__((alias(BUILTINN(parityll))));
#यदि_अन्तः

#यदि_अपरिभाषितम् __TINYC__
#यदि defined(__GNUC__) && (__GNUC__ >= 6)
/* gcc overrides alias from __builtin_ffs... to ffs.. so use assembly code */
__asm__(".globl  __builtin_ffs");
__asm__(".set __builtin_ffs,__tcc_builtin_ffs");
__asm__(".globl  __builtin_ffsl");
__asm__(".set __builtin_ffsl,__tcc_builtin_ffsl");
__asm__(".globl  __builtin_ffsll");
__asm__(".set __builtin_ffsll,__tcc_builtin_ffsll");
#अन्यथा
पूर्णाङ्क __builtin_ffs(पूर्णाङ्क x) __attribute__((alias("__tcc_builtin_ffs")));
पूर्णाङ्क __builtin_ffsl(दीर्घ x) __attribute__((alias("__tcc_builtin_ffsl")));
पूर्णाङ्क __builtin_ffsll(दीर्घ दीर्घ x) __attribute__((alias("__tcc_builtin_ffsll")));
#यदि_अन्तः
पूर्णाङ्क __builtin_clz(अचिह्नित पूर्णाङ्क x) __attribute__((alias("__tcc_builtin_clz")));
पूर्णाङ्क __builtin_clzl(अचिह्नित दीर्घ x) __attribute__((alias("__tcc_builtin_clzl")));
पूर्णाङ्क __builtin_clzll(अचिह्नित दीर्घ दीर्घ x) __attribute__((alias("__tcc_builtin_clzll")));
पूर्णाङ्क __builtin_ctz(अचिह्नित पूर्णाङ्क x) __attribute__((alias("__tcc_builtin_ctz")));
पूर्णाङ्क __builtin_ctzl(अचिह्नित दीर्घ x) __attribute__((alias("__tcc_builtin_ctzl")));
पूर्णाङ्क __builtin_ctzll(अचिह्नित दीर्घ दीर्घ x) __attribute__((alias("__tcc_builtin_ctzll")));
पूर्णाङ्क __builtin_clrsb(पूर्णाङ्क x) __attribute__((alias("__tcc_builtin_clrsb")));
पूर्णाङ्क __builtin_clrsbl(दीर्घ x) __attribute__((alias("__tcc_builtin_clrsbl")));
पूर्णाङ्क __builtin_clrsbll(दीर्घ दीर्घ x) __attribute__((alias("__tcc_builtin_clrsbll")));
पूर्णाङ्क __builtin_popcount(अचिह्नित पूर्णाङ्क x) __attribute__((alias("__tcc_builtin_popcount")));
पूर्णाङ्क __builtin_popcountl(अचिह्नित दीर्घ x) __attribute__((alias("__tcc_builtin_popcountl")));
पूर्णाङ्क __builtin_popcountll(अचिह्नित दीर्घ दीर्घ x) __attribute__((alias("__tcc_builtin_popcountll")));
पूर्णाङ्क __builtin_parity(अचिह्नित पूर्णाङ्क x) __attribute__((alias("__tcc_builtin_parity")));
पूर्णाङ्क __builtin_parityl(अचिह्नित दीर्घ x) __attribute__((alias("__tcc_builtin_parityl")));
पूर्णाङ्क __builtin_parityll(अचिह्नित दीर्घ दीर्घ x) __attribute__((alias("__tcc_builtin_parityll")));
#यदि_अन्तः
