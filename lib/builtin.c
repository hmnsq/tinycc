/* uses alias to allow building with gcc/clang */
#నిర్వచితమైతే __TINYC__
#నిర్వచించు	BUILTIN(x)	__builtin_##x
#నిర్వచించు	BUILTINN(x)	"__builtin_" # x
#లేకపోతే
#నిర్వచించు	BUILTIN(x)	__tcc_builtin_##x
#నిర్వచించు	BUILTINN(x)	"__tcc_builtin_" # x
#అయితే_ముగింపు

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

స్థిర స్థిరరాశి గుర్తులేని అక్షరం పట్టిక_1_32[] = {
     0,  1, 28,  2, 29, 14, 24,  3, 30, 22, 20, 15, 25, 17,  4,  8, 
    31, 27, 13, 23, 21, 19, 16,  7, 26, 12, 18,  6, 11,  5, 10,  9
};
స్థిర స్థిరరాశి గుర్తులేని అక్షరం పట్టిక_2_32[32] = {
    31, 22, 30, 21, 18, 10, 29,  2, 20, 17, 15, 13,  9,  6, 28,  1,
    23, 19, 11,  3, 16, 14,  7, 24, 12,  4,  8, 25,  5, 26, 27,  0
};
స్థిర స్థిరరాశి గుర్తులేని అక్షరం పట్టిక_1_64[] = {
     0,  1,  2, 53,  3,  7, 54, 27,  4, 38, 41,  8, 34, 55, 48, 28,
    62,  5, 39, 46, 44, 42, 22,  9, 24, 35, 59, 56, 49, 18, 29, 11,
    63, 52,  6, 26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58, 17, 10,
    51, 25, 36, 32, 60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12
};
స్థిర స్థిరరాశి గుర్తులేని అక్షరం పట్టిక_2_64[] = {
    63, 16, 62,  7, 15, 36, 61,  3,  6, 14, 22, 26, 35, 47, 60,  2,
     9,  5, 28, 11, 13, 21, 42, 19, 25, 31, 34, 40, 46, 52, 59,  1,
    17,  8, 37,  4, 23, 27, 48, 10, 29, 12, 43, 20, 32, 41, 53, 18,
    38, 24, 49, 30, 44, 33, 54, 39, 50, 45, 55, 51, 56, 57, 58,  0
};

#నిర్వచించు FFSI(x) \
    తిరిగి పట్టిక_1_32[((x & -x) * 0x077cb531u) >> 27] + (x != 0);
#నిర్వచించు FFSL(x) \
    తిరిగి పట్టిక_1_64[((x & -x) * 0x022fdd63cc95386dull) >> 58] + (x != 0);
#నిర్వచించు CTZI(x) \
    తిరిగి పట్టిక_1_32[((x & -x) * 0x077cb531u) >> 27];
#నిర్వచించు CTZL(x) \
    తిరిగి పట్టిక_1_64[((x & -x) * 0x022fdd63cc95386dull) >> 58];
#నిర్వచించు CLZI(x)   \
    x |= x >> 1;  \
    x |= x >> 2;  \
    x |= x >> 4;  \
    x |= x >> 8;  \
    x |= x >> 16; \
    తిరిగి పట్టిక_2_32[(x * 0x07c4acddu) >> 27];
#నిర్వచించు CLZL(x)   \
    x |= x >> 1;  \
    x |= x >> 2;  \
    x |= x >> 4;  \
    x |= x >> 8;  \
    x |= x >> 16; \
    x |= x >> 32; \
    తిరిగి పట్టిక_2_64[x * 0x03f79d71b4cb0a89ull >> 58];
#నిర్వచించు POPCOUNTI(x, m)                                                   \
    x = x - ((x >> 1) & 0x55555555);                                      \
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);                       \
    x = (x + (x >> 4)) & 0xf0f0f0f;                                       \
    తిరిగి ((x * 0x01010101) >> 24) & m; 
#నిర్వచించు POPCOUNTL(x, m)                                                   \
    x = x - ((x >> 1) & 0x5555555555555555ull);                           \
    x = (x & 0x3333333333333333ull) + ((x >> 2) & 0x3333333333333333ull); \
    x = (x + (x >> 4)) & 0xf0f0f0f0f0f0f0full;                            \
    తిరిగి ((x * 0x0101010101010101ull) >> 56) & m;

/* Returns one plus the index of the least significant 1-bit of x,
   or if x is zero, returns zero. */
పూర్ణాంకం BUILTIN(ffs) (పూర్ణాంకం x) { FFSI(x) }
పూర్ణాంకం BUILTIN(ffsll) (దీర్ఘ దీర్ఘ x) { FFSL(x) }
#ఒకవేళ __SIZEOF_LONG__ == 4
పూర్ణాంకం BUILTIN(ffsl) (దీర్ఘ x) __attribute__((alias(BUILTINN(ffs))));
#లేకపోతే
పూర్ణాంకం BUILTIN(ffsl) (దీర్ఘ x) __attribute__((alias(BUILTINN(ffsll))));
#అయితే_ముగింపు

/* Returns the number of leading 0-bits in x, starting at the most significant
   bit position. If x is 0, the result is undefined.  */
పూర్ణాంకం BUILTIN(clz) (గుర్తులేని పూర్ణాంకం x) { CLZI(x) }
పూర్ణాంకం BUILTIN(clzll) (గుర్తులేని దీర్ఘ దీర్ఘ x) { CLZL(x) }
#ఒకవేళ __SIZEOF_LONG__ == 4
పూర్ణాంకం BUILTIN(clzl) (గుర్తులేని దీర్ఘ x) __attribute__((alias(BUILTINN(clz))));
#లేకపోతే
పూర్ణాంకం BUILTIN(clzl) (గుర్తులేని దీర్ఘ x) __attribute__((alias(BUILTINN(clzll))));
#అయితే_ముగింపు

/* Returns the number of trailing 0-bits in x, starting at the least
   significant bit position. If x is 0, the result is undefined. */
పూర్ణాంకం BUILTIN(ctz) (గుర్తులేని పూర్ణాంకం x) { CTZI(x) }
పూర్ణాంకం BUILTIN(ctzll) (గుర్తులేని దీర్ఘ దీర్ఘ x) { CTZL(x) }
#ఒకవేళ __SIZEOF_LONG__ == 4
పూర్ణాంకం BUILTIN(ctzl) (గుర్తులేని దీర్ఘ x) __attribute__((alias(BUILTINN(ctz))));
#లేకపోతే
పూర్ణాంకం BUILTIN(ctzl) (గుర్తులేని దీర్ఘ x) __attribute__((alias(BUILTINN(ctzll))));
#అయితే_ముగింపు

/* Returns the number of leading redundant sign bits in x, i.e. the number
   of bits following the most significant bit that are identical to it.
   There are no special cases for 0 or other values. */
పూర్ణాంకం BUILTIN(clrsb) (పూర్ణాంకం x) { ఒకవేళ (x < 0) x = ~x; x <<= 1; CLZI(x) }
పూర్ణాంకం BUILTIN(clrsbll) (దీర్ఘ దీర్ఘ x) { ఒకవేళ (x < 0) x = ~x; x <<= 1; CLZL(x) }
#ఒకవేళ __SIZEOF_LONG__ == 4
పూర్ణాంకం BUILTIN(clrsbl) (దీర్ఘ x) __attribute__((alias(BUILTINN(clrsb))));
#లేకపోతే
పూర్ణాంకం BUILTIN(clrsbl) (దీర్ఘ x) __attribute__((alias(BUILTINN(clrsbll))));
#అయితే_ముగింపు

/* Returns the number of 1-bits in x.*/
పూర్ణాంకం BUILTIN(popcount) (గుర్తులేని పూర్ణాంకం x) { POPCOUNTI(x, 0x3f) }
పూర్ణాంకం BUILTIN(popcountll) (గుర్తులేని దీర్ఘ దీర్ఘ x) { POPCOUNTL(x, 0x7f) }
#ఒకవేళ __SIZEOF_LONG__ == 4
పూర్ణాంకం BUILTIN(popcountl) (గుర్తులేని దీర్ఘ x) __attribute__((alias(BUILTINN(popcount))));
#లేకపోతే
పూర్ణాంకం BUILTIN(popcountl ) (గుర్తులేని దీర్ఘ x) __attribute__((alias(BUILTINN(popcountll))));
#అయితే_ముగింపు

/* Returns the parity of x, i.e. the number of 1-bits in x modulo 2. */
పూర్ణాంకం BUILTIN(parity) (గుర్తులేని పూర్ణాంకం x) { POPCOUNTI(x, 0x01) }
పూర్ణాంకం BUILTIN(parityll) (గుర్తులేని దీర్ఘ దీర్ఘ x) { POPCOUNTL(x, 0x01) }
#ఒకవేళ __SIZEOF_LONG__ == 4
పూర్ణాంకం BUILTIN(parityl) (గుర్తులేని దీర్ఘ x) __attribute__((alias(BUILTINN(parity))));
#లేకపోతే
పూర్ణాంకం BUILTIN(parityl) (గుర్తులేని దీర్ఘ x) __attribute__((alias(BUILTINN(parityll))));
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే __TINYC__
#ఒకవేళ defined(__GNUC__) && (__GNUC__ >= 6)
/* gcc overrides alias from __builtin_ffs... to ffs.. so use assembly code */
__asm__(".globl  __builtin_ffs");
__asm__(".set __builtin_ffs,__tcc_builtin_ffs");
__asm__(".globl  __builtin_ffsl");
__asm__(".set __builtin_ffsl,__tcc_builtin_ffsl");
__asm__(".globl  __builtin_ffsll");
__asm__(".set __builtin_ffsll,__tcc_builtin_ffsll");
#లేకపోతే
పూర్ణాంకం __builtin_ffs(పూర్ణాంకం x) __attribute__((alias("__tcc_builtin_ffs")));
పూర్ణాంకం __builtin_ffsl(దీర్ఘ x) __attribute__((alias("__tcc_builtin_ffsl")));
పూర్ణాంకం __builtin_ffsll(దీర్ఘ దీర్ఘ x) __attribute__((alias("__tcc_builtin_ffsll")));
#అయితే_ముగింపు
పూర్ణాంకం __builtin_clz(గుర్తులేని పూర్ణాంకం x) __attribute__((alias("__tcc_builtin_clz")));
పూర్ణాంకం __builtin_clzl(గుర్తులేని దీర్ఘ x) __attribute__((alias("__tcc_builtin_clzl")));
పూర్ణాంకం __builtin_clzll(గుర్తులేని దీర్ఘ దీర్ఘ x) __attribute__((alias("__tcc_builtin_clzll")));
పూర్ణాంకం __builtin_ctz(గుర్తులేని పూర్ణాంకం x) __attribute__((alias("__tcc_builtin_ctz")));
పూర్ణాంకం __builtin_ctzl(గుర్తులేని దీర్ఘ x) __attribute__((alias("__tcc_builtin_ctzl")));
పూర్ణాంకం __builtin_ctzll(గుర్తులేని దీర్ఘ దీర్ఘ x) __attribute__((alias("__tcc_builtin_ctzll")));
పూర్ణాంకం __builtin_clrsb(పూర్ణాంకం x) __attribute__((alias("__tcc_builtin_clrsb")));
పూర్ణాంకం __builtin_clrsbl(దీర్ఘ x) __attribute__((alias("__tcc_builtin_clrsbl")));
పూర్ణాంకం __builtin_clrsbll(దీర్ఘ దీర్ఘ x) __attribute__((alias("__tcc_builtin_clrsbll")));
పూర్ణాంకం __builtin_popcount(గుర్తులేని పూర్ణాంకం x) __attribute__((alias("__tcc_builtin_popcount")));
పూర్ణాంకం __builtin_popcountl(గుర్తులేని దీర్ఘ x) __attribute__((alias("__tcc_builtin_popcountl")));
పూర్ణాంకం __builtin_popcountll(గుర్తులేని దీర్ఘ దీర్ఘ x) __attribute__((alias("__tcc_builtin_popcountll")));
పూర్ణాంకం __builtin_parity(గుర్తులేని పూర్ణాంకం x) __attribute__((alias("__tcc_builtin_parity")));
పూర్ణాంకం __builtin_parityl(గుర్తులేని దీర్ఘ x) __attribute__((alias("__tcc_builtin_parityl")));
పూర్ణాంకం __builtin_parityll(గుర్తులేని దీర్ఘ దీర్ఘ x) __attribute__((alias("__tcc_builtin_parityll")));
#అయితే_ముగింపు
