/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* 7.8 Format conversion of integer types <inttypes.h> */

#यदि_अपरिभाषितम् _INTTYPES_H_
#परिभाषय _INTTYPES_H_

#अन्तर्भाव <_mingw.h>
#अन्तर्भाव <stdint.h>
#परिभाषय __need_wchar_t
#अन्तर्भाव <stddef.h>

#यदि_परिभाषितम्	__cplusplus
बाह्य	"C"	{
#यदि_अन्तः

प्रकारनिर्देश संरचना {
	intmax_t quot;
	intmax_t rem;
	} imaxdiv_t;

#यदि !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS)

/* 7.8.1 Macros for format specifiers
 * 
 * MS runtime does not yet understand C9x standard "ll"
 * length specifier. It appears to treat "ll" as "l".
 * The non-standard I64 length specifier causes warning in GCC,
 * but understood by MS runtime functions.
 */

/* fprintf macros for signed types */
#परिभाषय PRId8 "d"
#परिभाषय PRId16 "d"
#परिभाषय PRId32 "d"
#परिभाषय PRId64 "I64d"

#परिभाषय PRIdLEAST8 "d"
#परिभाषय PRIdLEAST16 "d"
#परिभाषय PRIdLEAST32 "d"
#परिभाषय PRIdLEAST64 "I64d"

#परिभाषय PRIdFAST8 "d"
#परिभाषय PRIdFAST16 "d"
#परिभाषय PRIdFAST32 "d"
#परिभाषय PRIdFAST64 "I64d"

#परिभाषय PRIdMAX "I64d"

#परिभाषय PRIi8 "i"
#परिभाषय PRIi16 "i"
#परिभाषय PRIi32 "i"
#परिभाषय PRIi64 "I64i"

#परिभाषय PRIiLEAST8 "i"
#परिभाषय PRIiLEAST16 "i"
#परिभाषय PRIiLEAST32 "i"
#परिभाषय PRIiLEAST64 "I64i"

#परिभाषय PRIiFAST8 "i"
#परिभाषय PRIiFAST16 "i"
#परिभाषय PRIiFAST32 "i"
#परिभाषय PRIiFAST64 "I64i"

#परिभाषय PRIiMAX "I64i"

#परिभाषय PRIo8 "o"
#परिभाषय PRIo16 "o"
#परिभाषय PRIo32 "o"
#परिभाषय PRIo64 "I64o"

#परिभाषय PRIoLEAST8 "o"
#परिभाषय PRIoLEAST16 "o"
#परिभाषय PRIoLEAST32 "o"
#परिभाषय PRIoLEAST64 "I64o"

#परिभाषय PRIoFAST8 "o"
#परिभाषय PRIoFAST16 "o"
#परिभाषय PRIoFAST32 "o"
#परिभाषय PRIoFAST64 "I64o"

#परिभाषय PRIoMAX "I64o"

/* fprintf macros for unsigned types */
#परिभाषय PRIu8 "u"
#परिभाषय PRIu16 "u"
#परिभाषय PRIu32 "u"
#परिभाषय PRIu64 "I64u"


#परिभाषय PRIuLEAST8 "u"
#परिभाषय PRIuLEAST16 "u"
#परिभाषय PRIuLEAST32 "u"
#परिभाषय PRIuLEAST64 "I64u"

#परिभाषय PRIuFAST8 "u"
#परिभाषय PRIuFAST16 "u"
#परिभाषय PRIuFAST32 "u"
#परिभाषय PRIuFAST64 "I64u"

#परिभाषय PRIuMAX "I64u"

#परिभाषय PRIx8 "x"
#परिभाषय PRIx16 "x"
#परिभाषय PRIx32 "x"
#परिभाषय PRIx64 "I64x"

#परिभाषय PRIxLEAST8 "x"
#परिभाषय PRIxLEAST16 "x"
#परिभाषय PRIxLEAST32 "x"
#परिभाषय PRIxLEAST64 "I64x"

#परिभाषय PRIxFAST8 "x"
#परिभाषय PRIxFAST16 "x"
#परिभाषय PRIxFAST32 "x"
#परिभाषय PRIxFAST64 "I64x"

#परिभाषय PRIxMAX "I64x"

#परिभाषय PRIX8 "X"
#परिभाषय PRIX16 "X"
#परिभाषय PRIX32 "X"
#परिभाषय PRIX64 "I64X"

#परिभाषय PRIXLEAST8 "X"
#परिभाषय PRIXLEAST16 "X"
#परिभाषय PRIXLEAST32 "X"
#परिभाषय PRIXLEAST64 "I64X"

#परिभाषय PRIXFAST8 "X"
#परिभाषय PRIXFAST16 "X"
#परिभाषय PRIXFAST32 "X"
#परिभाषय PRIXFAST64 "I64X"

#परिभाषय PRIXMAX "I64X"

/*
 *   fscanf macros for signed int types
 *   NOTE: if 32-bit int is used for int_fast8_t and int_fast16_t
 *   (see stdint.h, 7.18.1.3), FAST8 and FAST16 should have
 *   no length identifiers
 */

#परिभाषय SCNd16 "hd"
#परिभाषय SCNd32 "d"
#परिभाषय SCNd64 "I64d"

#परिभाषय SCNdLEAST16 "hd"
#परिभाषय SCNdLEAST32 "d"
#परिभाषय SCNdLEAST64 "I64d"

#परिभाषय SCNdFAST16 "hd"
#परिभाषय SCNdFAST32 "d"
#परिभाषय SCNdFAST64 "I64d"

#परिभाषय SCNdMAX "I64d"

#परिभाषय SCNi16 "hi"
#परिभाषय SCNi32 "i"
#परिभाषय SCNi64 "I64i"

#परिभाषय SCNiLEAST16 "hi"
#परिभाषय SCNiLEAST32 "i"
#परिभाषय SCNiLEAST64 "I64i"

#परिभाषय SCNiFAST16 "hi"
#परिभाषय SCNiFAST32 "i"
#परिभाषय SCNiFAST64 "I64i"

#परिभाषय SCNiMAX "I64i"

#परिभाषय SCNo16 "ho"
#परिभाषय SCNo32 "o"
#परिभाषय SCNo64 "I64o"

#परिभाषय SCNoLEAST16 "ho"
#परिभाषय SCNoLEAST32 "o"
#परिभाषय SCNoLEAST64 "I64o"

#परिभाषय SCNoFAST16 "ho"
#परिभाषय SCNoFAST32 "o"
#परिभाषय SCNoFAST64 "I64o"

#परिभाषय SCNoMAX "I64o"

#परिभाषय SCNx16 "hx"
#परिभाषय SCNx32 "x"
#परिभाषय SCNx64 "I64x"

#परिभाषय SCNxLEAST16 "hx"
#परिभाषय SCNxLEAST32 "x"
#परिभाषय SCNxLEAST64 "I64x"

#परिभाषय SCNxFAST16 "hx"
#परिभाषय SCNxFAST32 "x"
#परिभाषय SCNxFAST64 "I64x"

#परिभाषय SCNxMAX "I64x"

/* fscanf macros for unsigned int types */

#परिभाषय SCNu16 "hu"
#परिभाषय SCNu32 "u"
#परिभाषय SCNu64 "I64u"

#परिभाषय SCNuLEAST16 "hu"
#परिभाषय SCNuLEAST32 "u"
#परिभाषय SCNuLEAST64 "I64u"

#परिभाषय SCNuFAST16 "hu"
#परिभाषय SCNuFAST32 "u"
#परिभाषय SCNuFAST64 "I64u"

#परिभाषय SCNuMAX "I64u"

#यदि_परिभाषितम् _WIN64
#परिभाषय PRIdPTR "I64d"
#परिभाषय PRIiPTR "I64i"
#परिभाषय PRIoPTR "I64o"
#परिभाषय PRIuPTR "I64u"
#परिभाषय PRIxPTR "I64x"
#परिभाषय PRIXPTR "I64X"
#परिभाषय SCNdPTR "I64d"
#परिभाषय SCNiPTR "I64i"
#परिभाषय SCNoPTR "I64o"
#परिभाषय SCNxPTR "I64x"
#परिभाषय SCNuPTR "I64u"
#अन्यथा
#परिभाषय PRIdPTR "d"
#परिभाषय PRIiPTR "i"
#परिभाषय PRIoPTR "o"
#परिभाषय PRIuPTR "u"
#परिभाषय PRIxPTR "x"
#परिभाषय PRIXPTR "X"
#परिभाषय SCNdPTR "d"
#परिभाषय SCNiPTR "i"
#परिभाषय SCNoPTR "o"
#परिभाषय SCNxPTR "x"
#परिभाषय SCNuPTR "u"
#यदि_अन्तः

#यदि defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
/*
 * no length modifier for char types prior to C9x
 * MS runtime  scanf appears to treat "hh" as "h" 
 */

/* signed char */
#परिभाषय SCNd8 "hhd"
#परिभाषय SCNdLEAST8 "hhd"
#परिभाषय SCNdFAST8 "hhd"

#परिभाषय SCNi8 "hhi"
#परिभाषय SCNiLEAST8 "hhi"
#परिभाषय SCNiFAST8 "hhi"

#परिभाषय SCNo8 "hho"
#परिभाषय SCNoLEAST8 "hho"
#परिभाषय SCNoFAST8 "hho"

#परिभाषय SCNx8 "hhx"
#परिभाषय SCNxLEAST8 "hhx"
#परिभाषय SCNxFAST8 "hhx"

/* unsigned char */
#परिभाषय SCNu8 "hhu"
#परिभाषय SCNuLEAST8 "hhu"
#परिभाषय SCNuFAST8 "hhu"
#यदि_अन्तः /* __STDC_VERSION__ >= 199901 */

#यदि_अन्तः	/* !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS) */

intmax_t __cdecl imaxabs (intmax_t j);
__CRT_INLINE intmax_t __cdecl imaxabs (intmax_t j)
	{प्रत्यागम	(j >= 0 ? j : -j);}
imaxdiv_t __cdecl imaxdiv (intmax_t numer, intmax_t denom);

/* 7.8.2 Conversion functions for greatest-width integer types */

intmax_t __cdecl strtoimax (ध्रुव वर्ण* __restrict__ nptr,
                            वर्ण** __restrict__ endptr, पूर्णाङ्क आधारः);
uintmax_t __cdecl strtoumax (ध्रुव वर्ण* __restrict__ nptr,
			     वर्ण** __restrict__ endptr, पूर्णाङ्क आधारः);

intmax_t __cdecl wcstoimax (ध्रुव wchar_t* __restrict__ nptr,
                            wchar_t** __restrict__ endptr, पूर्णाङ्क आधारः);
uintmax_t __cdecl wcstoumax (ध्रुव wchar_t* __restrict__ nptr,
			     wchar_t** __restrict__ endptr, पूर्णाङ्क आधारः);

#यदि_परिभाषितम्	__cplusplus
}
#यदि_अन्तः

#यदि_अन्तः /* ndef _INTTYPES_H */
