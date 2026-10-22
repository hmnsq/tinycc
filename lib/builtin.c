/* uses alias to allow building with gcc/clang */
#جے_تعریف_شدہ __TINYC__
#تعریف_کرو	BUILTIN(x)	__builtin_##x
#تعریف_کرو	BUILTINN(x)	"__builtin_" # x
#وإلا
#تعریف_کرو	BUILTIN(x)	__tcc_builtin_##x
#تعریف_کرو	BUILTINN(x)	"__tcc_builtin_" # x
#جے_انت

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

ساكن ثابت بنانشانی حرف جدول_1_32[] = {
     0,  1, 28,  2, 29, 14, 24,  3, 30, 22, 20, 15, 25, 17,  4,  8, 
    31, 27, 13, 23, 21, 19, 16,  7, 26, 12, 18,  6, 11,  5, 10,  9
};
ساكن ثابت بنانشانی حرف جدول_2_32[32] = {
    31, 22, 30, 21, 18, 10, 29,  2, 20, 17, 15, 13,  9,  6, 28,  1,
    23, 19, 11,  3, 16, 14,  7, 24, 12,  4,  8, 25,  5, 26, 27,  0
};
ساكن ثابت بنانشانی حرف جدول_1_64[] = {
     0,  1,  2, 53,  3,  7, 54, 27,  4, 38, 41,  8, 34, 55, 48, 28,
    62,  5, 39, 46, 44, 42, 22,  9, 24, 35, 59, 56, 49, 18, 29, 11,
    63, 52,  6, 26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58, 17, 10,
    51, 25, 36, 32, 60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12
};
ساكن ثابت بنانشانی حرف جدول_2_64[] = {
    63, 16, 62,  7, 15, 36, 61,  3,  6, 14, 22, 26, 35, 47, 60,  2,
     9,  5, 28, 11, 13, 21, 42, 19, 25, 31, 34, 40, 46, 52, 59,  1,
    17,  8, 37,  4, 23, 27, 48, 10, 29, 12, 43, 20, 32, 41, 53, 18,
    38, 24, 49, 30, 44, 33, 54, 39, 50, 45, 55, 51, 56, 57, 58,  0
};

#تعریف_کرو FFSI(x) \
    أرجع جدول_1_32[((x & -x) * 0x077cb531u) >> 27] + (x != 0);
#تعریف_کرو FFSL(x) \
    أرجع جدول_1_64[((x & -x) * 0x022fdd63cc95386dull) >> 58] + (x != 0);
#تعریف_کرو CTZI(x) \
    أرجع جدول_1_32[((x & -x) * 0x077cb531u) >> 27];
#تعریف_کرو CTZL(x) \
    أرجع جدول_1_64[((x & -x) * 0x022fdd63cc95386dull) >> 58];
#تعریف_کرو CLZI(x)   \
    x |= x >> 1;  \
    x |= x >> 2;  \
    x |= x >> 4;  \
    x |= x >> 8;  \
    x |= x >> 16; \
    أرجع جدول_2_32[(x * 0x07c4acddu) >> 27];
#تعریف_کرو CLZL(x)   \
    x |= x >> 1;  \
    x |= x >> 2;  \
    x |= x >> 4;  \
    x |= x >> 8;  \
    x |= x >> 16; \
    x |= x >> 32; \
    أرجع جدول_2_64[x * 0x03f79d71b4cb0a89ull >> 58];
#تعریف_کرو POPCOUNTI(x, m)                                                   \
    x = x - ((x >> 1) & 0x55555555);                                      \
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);                       \
    x = (x + (x >> 4)) & 0xf0f0f0f;                                       \
    أرجع ((x * 0x01010101) >> 24) & m; 
#تعریف_کرو POPCOUNTL(x, m)                                                   \
    x = x - ((x >> 1) & 0x5555555555555555ull);                           \
    x = (x & 0x3333333333333333ull) + ((x >> 2) & 0x3333333333333333ull); \
    x = (x + (x >> 4)) & 0xf0f0f0f0f0f0f0full;                            \
    أرجع ((x * 0x0101010101010101ull) >> 56) & m;

/* Returns one plus the index of the least significant 1-bit of x,
   or if x is zero, returns zero. */
صحيح BUILTIN(ffs) (صحيح x) { FFSI(x) }
صحيح BUILTIN(ffsll) (لما لما x) { FFSL(x) }
#إذا __SIZEOF_LONG__ == 4
صحيح BUILTIN(ffsl) (لما x) __attribute__((alias(BUILTINN(ffs))));
#وإلا
صحيح BUILTIN(ffsl) (لما x) __attribute__((alias(BUILTINN(ffsll))));
#جے_انت

/* Returns the number of leading 0-bits in x, starting at the most significant
   bit position. If x is 0, the result is undefined.  */
صحيح BUILTIN(clz) (بنانشانی صحيح x) { CLZI(x) }
صحيح BUILTIN(clzll) (بنانشانی لما لما x) { CLZL(x) }
#إذا __SIZEOF_LONG__ == 4
صحيح BUILTIN(clzl) (بنانشانی لما x) __attribute__((alias(BUILTINN(clz))));
#وإلا
صحيح BUILTIN(clzl) (بنانشانی لما x) __attribute__((alias(BUILTINN(clzll))));
#جے_انت

/* Returns the number of trailing 0-bits in x, starting at the least
   significant bit position. If x is 0, the result is undefined. */
صحيح BUILTIN(ctz) (بنانشانی صحيح x) { CTZI(x) }
صحيح BUILTIN(ctzll) (بنانشانی لما لما x) { CTZL(x) }
#إذا __SIZEOF_LONG__ == 4
صحيح BUILTIN(ctzl) (بنانشانی لما x) __attribute__((alias(BUILTINN(ctz))));
#وإلا
صحيح BUILTIN(ctzl) (بنانشانی لما x) __attribute__((alias(BUILTINN(ctzll))));
#جے_انت

/* Returns the number of leading redundant sign bits in x, i.e. the number
   of bits following the most significant bit that are identical to it.
   There are no special cases for 0 or other values. */
صحيح BUILTIN(clrsb) (صحيح x) { إذا (x < 0) x = ~x; x <<= 1; CLZI(x) }
صحيح BUILTIN(clrsbll) (لما لما x) { إذا (x < 0) x = ~x; x <<= 1; CLZL(x) }
#إذا __SIZEOF_LONG__ == 4
صحيح BUILTIN(clrsbl) (لما x) __attribute__((alias(BUILTINN(clrsb))));
#وإلا
صحيح BUILTIN(clrsbl) (لما x) __attribute__((alias(BUILTINN(clrsbll))));
#جے_انت

/* Returns the number of 1-bits in x.*/
صحيح BUILTIN(popcount) (بنانشانی صحيح x) { POPCOUNTI(x, 0x3f) }
صحيح BUILTIN(popcountll) (بنانشانی لما لما x) { POPCOUNTL(x, 0x7f) }
#إذا __SIZEOF_LONG__ == 4
صحيح BUILTIN(popcountl) (بنانشانی لما x) __attribute__((alias(BUILTINN(popcount))));
#وإلا
صحيح BUILTIN(popcountl ) (بنانشانی لما x) __attribute__((alias(BUILTINN(popcountll))));
#جے_انت

/* Returns the parity of x, i.e. the number of 1-bits in x modulo 2. */
صحيح BUILTIN(parity) (بنانشانی صحيح x) { POPCOUNTI(x, 0x01) }
صحيح BUILTIN(parityll) (بنانشانی لما لما x) { POPCOUNTL(x, 0x01) }
#إذا __SIZEOF_LONG__ == 4
صحيح BUILTIN(parityl) (بنانشانی لما x) __attribute__((alias(BUILTINN(parity))));
#وإلا
صحيح BUILTIN(parityl) (بنانشانی لما x) __attribute__((alias(BUILTINN(parityll))));
#جے_انت

#جے_بنا_تعریف __TINYC__
#إذا defined(__GNUC__) && (__GNUC__ >= 6)
/* gcc overrides alias from __builtin_ffs... to ffs.. so use assembly code */
__asm__(".globl  __builtin_ffs");
__asm__(".set __builtin_ffs,__tcc_builtin_ffs");
__asm__(".globl  __builtin_ffsl");
__asm__(".set __builtin_ffsl,__tcc_builtin_ffsl");
__asm__(".globl  __builtin_ffsll");
__asm__(".set __builtin_ffsll,__tcc_builtin_ffsll");
#وإلا
صحيح __builtin_ffs(صحيح x) __attribute__((alias("__tcc_builtin_ffs")));
صحيح __builtin_ffsl(لما x) __attribute__((alias("__tcc_builtin_ffsl")));
صحيح __builtin_ffsll(لما لما x) __attribute__((alias("__tcc_builtin_ffsll")));
#جے_انت
صحيح __builtin_clz(بنانشانی صحيح x) __attribute__((alias("__tcc_builtin_clz")));
صحيح __builtin_clzl(بنانشانی لما x) __attribute__((alias("__tcc_builtin_clzl")));
صحيح __builtin_clzll(بنانشانی لما لما x) __attribute__((alias("__tcc_builtin_clzll")));
صحيح __builtin_ctz(بنانشانی صحيح x) __attribute__((alias("__tcc_builtin_ctz")));
صحيح __builtin_ctzl(بنانشانی لما x) __attribute__((alias("__tcc_builtin_ctzl")));
صحيح __builtin_ctzll(بنانشانی لما لما x) __attribute__((alias("__tcc_builtin_ctzll")));
صحيح __builtin_clrsb(صحيح x) __attribute__((alias("__tcc_builtin_clrsb")));
صحيح __builtin_clrsbl(لما x) __attribute__((alias("__tcc_builtin_clrsbl")));
صحيح __builtin_clrsbll(لما لما x) __attribute__((alias("__tcc_builtin_clrsbll")));
صحيح __builtin_popcount(بنانشانی صحيح x) __attribute__((alias("__tcc_builtin_popcount")));
صحيح __builtin_popcountl(بنانشانی لما x) __attribute__((alias("__tcc_builtin_popcountl")));
صحيح __builtin_popcountll(بنانشانی لما لما x) __attribute__((alias("__tcc_builtin_popcountll")));
صحيح __builtin_parity(بنانشانی صحيح x) __attribute__((alias("__tcc_builtin_parity")));
صحيح __builtin_parityl(بنانشانی لما x) __attribute__((alias("__tcc_builtin_parityl")));
صحيح __builtin_parityll(بنانشانی لما لما x) __attribute__((alias("__tcc_builtin_parityll")));
#جے_انت
