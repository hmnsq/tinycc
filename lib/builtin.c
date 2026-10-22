/* uses alias to allow building with gcc/clang */
#جيڪڏهن_وصف_ٿيل __TINYC__
#وصف_ڪريو	BUILTIN(x)	__builtin_##x
#وصف_ڪريو	BUILTINN(x)	"__builtin_" # x
#وإلا
#وصف_ڪريو	BUILTIN(x)	__tcc_builtin_##x
#وصف_ڪريو	BUILTINN(x)	"__tcc_builtin_" # x
#جيڪڏهن_پورو

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

ساكن ثابت بنانشان حرف جدول_1_32[] = {
     0,  1, 28,  2, 29, 14, 24,  3, 30, 22, 20, 15, 25, 17,  4,  8, 
    31, 27, 13, 23, 21, 19, 16,  7, 26, 12, 18,  6, 11,  5, 10,  9
};
ساكن ثابت بنانشان حرف جدول_2_32[32] = {
    31, 22, 30, 21, 18, 10, 29,  2, 20, 17, 15, 13,  9,  6, 28,  1,
    23, 19, 11,  3, 16, 14,  7, 24, 12,  4,  8, 25,  5, 26, 27,  0
};
ساكن ثابت بنانشان حرف جدول_1_64[] = {
     0,  1,  2, 53,  3,  7, 54, 27,  4, 38, 41,  8, 34, 55, 48, 28,
    62,  5, 39, 46, 44, 42, 22,  9, 24, 35, 59, 56, 49, 18, 29, 11,
    63, 52,  6, 26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58, 17, 10,
    51, 25, 36, 32, 60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12
};
ساكن ثابت بنانشان حرف جدول_2_64[] = {
    63, 16, 62,  7, 15, 36, 61,  3,  6, 14, 22, 26, 35, 47, 60,  2,
     9,  5, 28, 11, 13, 21, 42, 19, 25, 31, 34, 40, 46, 52, 59,  1,
    17,  8, 37,  4, 23, 27, 48, 10, 29, 12, 43, 20, 32, 41, 53, 18,
    38, 24, 49, 30, 44, 33, 54, 39, 50, 45, 55, 51, 56, 57, 58,  0
};

#وصف_ڪريو FFSI(x) \
    أرجع جدول_1_32[((x & -x) * 0x077cb531u) >> 27] + (x != 0);
#وصف_ڪريو FFSL(x) \
    أرجع جدول_1_64[((x & -x) * 0x022fdd63cc95386dull) >> 58] + (x != 0);
#وصف_ڪريو CTZI(x) \
    أرجع جدول_1_32[((x & -x) * 0x077cb531u) >> 27];
#وصف_ڪريو CTZL(x) \
    أرجع جدول_1_64[((x & -x) * 0x022fdd63cc95386dull) >> 58];
#وصف_ڪريو CLZI(x)   \
    x |= x >> 1;  \
    x |= x >> 2;  \
    x |= x >> 4;  \
    x |= x >> 8;  \
    x |= x >> 16; \
    أرجع جدول_2_32[(x * 0x07c4acddu) >> 27];
#وصف_ڪريو CLZL(x)   \
    x |= x >> 1;  \
    x |= x >> 2;  \
    x |= x >> 4;  \
    x |= x >> 8;  \
    x |= x >> 16; \
    x |= x >> 32; \
    أرجع جدول_2_64[x * 0x03f79d71b4cb0a89ull >> 58];
#وصف_ڪريو POPCOUNTI(x, m)                                                   \
    x = x - ((x >> 1) & 0x55555555);                                      \
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);                       \
    x = (x + (x >> 4)) & 0xf0f0f0f;                                       \
    أرجع ((x * 0x01010101) >> 24) & m; 
#وصف_ڪريو POPCOUNTL(x, m)                                                   \
    x = x - ((x >> 1) & 0x5555555555555555ull);                           \
    x = (x & 0x3333333333333333ull) + ((x >> 2) & 0x3333333333333333ull); \
    x = (x + (x >> 4)) & 0xf0f0f0f0f0f0f0full;                            \
    أرجع ((x * 0x0101010101010101ull) >> 56) & m;

/* Returns one plus the index of the least significant 1-bit of x,
   or if x is zero, returns zero. */
صحيح BUILTIN(ffs) (صحيح x) { FFSI(x) }
صحيح BUILTIN(ffsll) (ڊگهو ڊگهو x) { FFSL(x) }
#إذا __SIZEOF_LONG__ == 4
صحيح BUILTIN(ffsl) (ڊگهو x) __attribute__((alias(BUILTINN(ffs))));
#وإلا
صحيح BUILTIN(ffsl) (ڊگهو x) __attribute__((alias(BUILTINN(ffsll))));
#جيڪڏهن_پورو

/* Returns the number of leading 0-bits in x, starting at the most significant
   bit position. If x is 0, the result is undefined.  */
صحيح BUILTIN(clz) (بنانشان صحيح x) { CLZI(x) }
صحيح BUILTIN(clzll) (بنانشان ڊگهو ڊگهو x) { CLZL(x) }
#إذا __SIZEOF_LONG__ == 4
صحيح BUILTIN(clzl) (بنانشان ڊگهو x) __attribute__((alias(BUILTINN(clz))));
#وإلا
صحيح BUILTIN(clzl) (بنانشان ڊگهو x) __attribute__((alias(BUILTINN(clzll))));
#جيڪڏهن_پورو

/* Returns the number of trailing 0-bits in x, starting at the least
   significant bit position. If x is 0, the result is undefined. */
صحيح BUILTIN(ctz) (بنانشان صحيح x) { CTZI(x) }
صحيح BUILTIN(ctzll) (بنانشان ڊگهو ڊگهو x) { CTZL(x) }
#إذا __SIZEOF_LONG__ == 4
صحيح BUILTIN(ctzl) (بنانشان ڊگهو x) __attribute__((alias(BUILTINN(ctz))));
#وإلا
صحيح BUILTIN(ctzl) (بنانشان ڊگهو x) __attribute__((alias(BUILTINN(ctzll))));
#جيڪڏهن_پورو

/* Returns the number of leading redundant sign bits in x, i.e. the number
   of bits following the most significant bit that are identical to it.
   There are no special cases for 0 or other values. */
صحيح BUILTIN(clrsb) (صحيح x) { إذا (x < 0) x = ~x; x <<= 1; CLZI(x) }
صحيح BUILTIN(clrsbll) (ڊگهو ڊگهو x) { إذا (x < 0) x = ~x; x <<= 1; CLZL(x) }
#إذا __SIZEOF_LONG__ == 4
صحيح BUILTIN(clrsbl) (ڊگهو x) __attribute__((alias(BUILTINN(clrsb))));
#وإلا
صحيح BUILTIN(clrsbl) (ڊگهو x) __attribute__((alias(BUILTINN(clrsbll))));
#جيڪڏهن_پورو

/* Returns the number of 1-bits in x.*/
صحيح BUILTIN(popcount) (بنانشان صحيح x) { POPCOUNTI(x, 0x3f) }
صحيح BUILTIN(popcountll) (بنانشان ڊگهو ڊگهو x) { POPCOUNTL(x, 0x7f) }
#إذا __SIZEOF_LONG__ == 4
صحيح BUILTIN(popcountl) (بنانشان ڊگهو x) __attribute__((alias(BUILTINN(popcount))));
#وإلا
صحيح BUILTIN(popcountl ) (بنانشان ڊگهو x) __attribute__((alias(BUILTINN(popcountll))));
#جيڪڏهن_پورو

/* Returns the parity of x, i.e. the number of 1-bits in x modulo 2. */
صحيح BUILTIN(parity) (بنانشان صحيح x) { POPCOUNTI(x, 0x01) }
صحيح BUILTIN(parityll) (بنانشان ڊگهو ڊگهو x) { POPCOUNTL(x, 0x01) }
#إذا __SIZEOF_LONG__ == 4
صحيح BUILTIN(parityl) (بنانشان ڊگهو x) __attribute__((alias(BUILTINN(parity))));
#وإلا
صحيح BUILTIN(parityl) (بنانشان ڊگهو x) __attribute__((alias(BUILTINN(parityll))));
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل __TINYC__
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
صحيح __builtin_ffsl(ڊگهو x) __attribute__((alias("__tcc_builtin_ffsl")));
صحيح __builtin_ffsll(ڊگهو ڊگهو x) __attribute__((alias("__tcc_builtin_ffsll")));
#جيڪڏهن_پورو
صحيح __builtin_clz(بنانشان صحيح x) __attribute__((alias("__tcc_builtin_clz")));
صحيح __builtin_clzl(بنانشان ڊگهو x) __attribute__((alias("__tcc_builtin_clzl")));
صحيح __builtin_clzll(بنانشان ڊگهو ڊگهو x) __attribute__((alias("__tcc_builtin_clzll")));
صحيح __builtin_ctz(بنانشان صحيح x) __attribute__((alias("__tcc_builtin_ctz")));
صحيح __builtin_ctzl(بنانشان ڊگهو x) __attribute__((alias("__tcc_builtin_ctzl")));
صحيح __builtin_ctzll(بنانشان ڊگهو ڊگهو x) __attribute__((alias("__tcc_builtin_ctzll")));
صحيح __builtin_clrsb(صحيح x) __attribute__((alias("__tcc_builtin_clrsb")));
صحيح __builtin_clrsbl(ڊگهو x) __attribute__((alias("__tcc_builtin_clrsbl")));
صحيح __builtin_clrsbll(ڊگهو ڊگهو x) __attribute__((alias("__tcc_builtin_clrsbll")));
صحيح __builtin_popcount(بنانشان صحيح x) __attribute__((alias("__tcc_builtin_popcount")));
صحيح __builtin_popcountl(بنانشان ڊگهو x) __attribute__((alias("__tcc_builtin_popcountl")));
صحيح __builtin_popcountll(بنانشان ڊگهو ڊگهو x) __attribute__((alias("__tcc_builtin_popcountll")));
صحيح __builtin_parity(بنانشان صحيح x) __attribute__((alias("__tcc_builtin_parity")));
صحيح __builtin_parityl(بنانشان ڊگهو x) __attribute__((alias("__tcc_builtin_parityl")));
صحيح __builtin_parityll(بنانشان ڊگهو ڊگهو x) __attribute__((alias("__tcc_builtin_parityll")));
#جيڪڏهن_پورو
