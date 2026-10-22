/* uses alias to allow building with gcc/clang */
#अगर_घोषित __TINYC__
#घोषणा	BUILTIN(x)	__builtin_##x
#घोषणा	BUILTINN(x)	"__builtin_" # x
#अन्यथा
#घोषणा	BUILTIN(x)	__tcc_builtin_##x
#घोषणा	BUILTINN(x)	"__tcc_builtin_" # x
#पूर्ण_अगर

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

अटल स्थिर अचिन्हित अक्षर table_1_32[] = {
     0,  1, 28,  2, 29, 14, 24,  3, 30, 22, 20, 15, 25, 17,  4,  8, 
    31, 27, 13, 23, 21, 19, 16,  7, 26, 12, 18,  6, 11,  5, 10,  9
};
अटल स्थिर अचिन्हित अक्षर table_2_32[32] = {
    31, 22, 30, 21, 18, 10, 29,  2, 20, 17, 15, 13,  9,  6, 28,  1,
    23, 19, 11,  3, 16, 14,  7, 24, 12,  4,  8, 25,  5, 26, 27,  0
};
अटल स्थिर अचिन्हित अक्षर table_1_64[] = {
     0,  1,  2, 53,  3,  7, 54, 27,  4, 38, 41,  8, 34, 55, 48, 28,
    62,  5, 39, 46, 44, 42, 22,  9, 24, 35, 59, 56, 49, 18, 29, 11,
    63, 52,  6, 26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58, 17, 10,
    51, 25, 36, 32, 60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12
};
अटल स्थिर अचिन्हित अक्षर table_2_64[] = {
    63, 16, 62,  7, 15, 36, 61,  3,  6, 14, 22, 26, 35, 47, 60,  2,
     9,  5, 28, 11, 13, 21, 42, 19, 25, 31, 34, 40, 46, 52, 59,  1,
    17,  8, 37,  4, 23, 27, 48, 10, 29, 12, 43, 20, 32, 41, 53, 18,
    38, 24, 49, 30, 44, 33, 54, 39, 50, 45, 55, 51, 56, 57, 58,  0
};

#घोषणा FFSI(x) \
    वापस table_1_32[((x & -x) * 0x077cb531u) >> 27] + (x != 0);
#घोषणा FFSL(x) \
    वापस table_1_64[((x & -x) * 0x022fdd63cc95386dull) >> 58] + (x != 0);
#घोषणा CTZI(x) \
    वापस table_1_32[((x & -x) * 0x077cb531u) >> 27];
#घोषणा CTZL(x) \
    वापस table_1_64[((x & -x) * 0x022fdd63cc95386dull) >> 58];
#घोषणा CLZI(x)   \
    x |= x >> 1;  \
    x |= x >> 2;  \
    x |= x >> 4;  \
    x |= x >> 8;  \
    x |= x >> 16; \
    वापस table_2_32[(x * 0x07c4acddu) >> 27];
#घोषणा CLZL(x)   \
    x |= x >> 1;  \
    x |= x >> 2;  \
    x |= x >> 4;  \
    x |= x >> 8;  \
    x |= x >> 16; \
    x |= x >> 32; \
    वापस table_2_64[x * 0x03f79d71b4cb0a89ull >> 58];
#घोषणा POPCOUNTI(x, m)                                                   \
    x = x - ((x >> 1) & 0x55555555);                                      \
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);                       \
    x = (x + (x >> 4)) & 0xf0f0f0f;                                       \
    वापस ((x * 0x01010101) >> 24) & m; 
#घोषणा POPCOUNTL(x, m)                                                   \
    x = x - ((x >> 1) & 0x5555555555555555ull);                           \
    x = (x & 0x3333333333333333ull) + ((x >> 2) & 0x3333333333333333ull); \
    x = (x + (x >> 4)) & 0xf0f0f0f0f0f0f0full;                            \
    वापस ((x * 0x0101010101010101ull) >> 56) & m;

/* Returns one plus the index of the least significant 1-bit of x,
   or if x is zero, returns zero. */
पूर्णांक BUILTIN(ffs) (पूर्णांक x) { FFSI(x) }
पूर्णांक BUILTIN(ffsll) (दीर्घ दीर्घ x) { FFSL(x) }
#अगर __SIZEOF_LONG__ == 4
पूर्णांक BUILTIN(ffsl) (दीर्घ x) __attribute__((alias(BUILTINN(ffs))));
#अन्यथा
पूर्णांक BUILTIN(ffsl) (दीर्घ x) __attribute__((alias(BUILTINN(ffsll))));
#पूर्ण_अगर

/* Returns the number of leading 0-bits in x, starting at the most significant
   bit position. If x is 0, the result is undefined.  */
पूर्णांक BUILTIN(clz) (अचिन्हित पूर्णांक x) { CLZI(x) }
पूर्णांक BUILTIN(clzll) (अचिन्हित दीर्घ दीर्घ x) { CLZL(x) }
#अगर __SIZEOF_LONG__ == 4
पूर्णांक BUILTIN(clzl) (अचिन्हित दीर्घ x) __attribute__((alias(BUILTINN(clz))));
#अन्यथा
पूर्णांक BUILTIN(clzl) (अचिन्हित दीर्घ x) __attribute__((alias(BUILTINN(clzll))));
#पूर्ण_अगर

/* Returns the number of trailing 0-bits in x, starting at the least
   significant bit position. If x is 0, the result is undefined. */
पूर्णांक BUILTIN(ctz) (अचिन्हित पूर्णांक x) { CTZI(x) }
पूर्णांक BUILTIN(ctzll) (अचिन्हित दीर्घ दीर्घ x) { CTZL(x) }
#अगर __SIZEOF_LONG__ == 4
पूर्णांक BUILTIN(ctzl) (अचिन्हित दीर्घ x) __attribute__((alias(BUILTINN(ctz))));
#अन्यथा
पूर्णांक BUILTIN(ctzl) (अचिन्हित दीर्घ x) __attribute__((alias(BUILTINN(ctzll))));
#पूर्ण_अगर

/* Returns the number of leading redundant sign bits in x, i.e. the number
   of bits following the most significant bit that are identical to it.
   There are no special cases for 0 or other values. */
पूर्णांक BUILTIN(clrsb) (पूर्णांक x) { अगर (x < 0) x = ~x; x <<= 1; CLZI(x) }
पूर्णांक BUILTIN(clrsbll) (दीर्घ दीर्घ x) { अगर (x < 0) x = ~x; x <<= 1; CLZL(x) }
#अगर __SIZEOF_LONG__ == 4
पूर्णांक BUILTIN(clrsbl) (दीर्घ x) __attribute__((alias(BUILTINN(clrsb))));
#अन्यथा
पूर्णांक BUILTIN(clrsbl) (दीर्घ x) __attribute__((alias(BUILTINN(clrsbll))));
#पूर्ण_अगर

/* Returns the number of 1-bits in x.*/
पूर्णांक BUILTIN(popcount) (अचिन्हित पूर्णांक x) { POPCOUNTI(x, 0x3f) }
पूर्णांक BUILTIN(popcountll) (अचिन्हित दीर्घ दीर्घ x) { POPCOUNTL(x, 0x7f) }
#अगर __SIZEOF_LONG__ == 4
पूर्णांक BUILTIN(popcountl) (अचिन्हित दीर्घ x) __attribute__((alias(BUILTINN(popcount))));
#अन्यथा
पूर्णांक BUILTIN(popcountl ) (अचिन्हित दीर्घ x) __attribute__((alias(BUILTINN(popcountll))));
#पूर्ण_अगर

/* Returns the parity of x, i.e. the number of 1-bits in x modulo 2. */
पूर्णांक BUILTIN(parity) (अचिन्हित पूर्णांक x) { POPCOUNTI(x, 0x01) }
पूर्णांक BUILTIN(parityll) (अचिन्हित दीर्घ दीर्घ x) { POPCOUNTL(x, 0x01) }
#अगर __SIZEOF_LONG__ == 4
पूर्णांक BUILTIN(parityl) (अचिन्हित दीर्घ x) __attribute__((alias(BUILTINN(parity))));
#अन्यथा
पूर्णांक BUILTIN(parityl) (अचिन्हित दीर्घ x) __attribute__((alias(BUILTINN(parityll))));
#पूर्ण_अगर

#अगर_अघोषित __TINYC__
#अगर defined(__GNUC__) && (__GNUC__ >= 6)
/* gcc overrides alias from __builtin_ffs... to ffs.. so use assembly code */
__asm__(".globl  __builtin_ffs");
__asm__(".set __builtin_ffs,__tcc_builtin_ffs");
__asm__(".globl  __builtin_ffsl");
__asm__(".set __builtin_ffsl,__tcc_builtin_ffsl");
__asm__(".globl  __builtin_ffsll");
__asm__(".set __builtin_ffsll,__tcc_builtin_ffsll");
#अन्यथा
पूर्णांक __builtin_ffs(पूर्णांक x) __attribute__((alias("__tcc_builtin_ffs")));
पूर्णांक __builtin_ffsl(दीर्घ x) __attribute__((alias("__tcc_builtin_ffsl")));
पूर्णांक __builtin_ffsll(दीर्घ दीर्घ x) __attribute__((alias("__tcc_builtin_ffsll")));
#पूर्ण_अगर
पूर्णांक __builtin_clz(अचिन्हित पूर्णांक x) __attribute__((alias("__tcc_builtin_clz")));
पूर्णांक __builtin_clzl(अचिन्हित दीर्घ x) __attribute__((alias("__tcc_builtin_clzl")));
पूर्णांक __builtin_clzll(अचिन्हित दीर्घ दीर्घ x) __attribute__((alias("__tcc_builtin_clzll")));
पूर्णांक __builtin_ctz(अचिन्हित पूर्णांक x) __attribute__((alias("__tcc_builtin_ctz")));
पूर्णांक __builtin_ctzl(अचिन्हित दीर्घ x) __attribute__((alias("__tcc_builtin_ctzl")));
पूर्णांक __builtin_ctzll(अचिन्हित दीर्घ दीर्घ x) __attribute__((alias("__tcc_builtin_ctzll")));
पूर्णांक __builtin_clrsb(पूर्णांक x) __attribute__((alias("__tcc_builtin_clrsb")));
पूर्णांक __builtin_clrsbl(दीर्घ x) __attribute__((alias("__tcc_builtin_clrsbl")));
पूर्णांक __builtin_clrsbll(दीर्घ दीर्घ x) __attribute__((alias("__tcc_builtin_clrsbll")));
पूर्णांक __builtin_popcount(अचिन्हित पूर्णांक x) __attribute__((alias("__tcc_builtin_popcount")));
पूर्णांक __builtin_popcountl(अचिन्हित दीर्घ x) __attribute__((alias("__tcc_builtin_popcountl")));
पूर्णांक __builtin_popcountll(अचिन्हित दीर्घ दीर्घ x) __attribute__((alias("__tcc_builtin_popcountll")));
पूर्णांक __builtin_parity(अचिन्हित पूर्णांक x) __attribute__((alias("__tcc_builtin_parity")));
पूर्णांक __builtin_parityl(अचिन्हित दीर्घ x) __attribute__((alias("__tcc_builtin_parityl")));
पूर्णांक __builtin_parityll(अचिन्हित दीर्घ दीर्घ x) __attribute__((alias("__tcc_builtin_parityll")));
#पूर्ण_अगर
