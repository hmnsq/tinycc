/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* 7.8 Format conversion of integer types <inttypes.h> */

#నిర్వచితం_కాకపోతే _INTTYPES_H_
#నిర్వచించు _INTTYPES_H_

#అన్తర్భావ <_mingw.h>
#అన్తర్భావ <stdint.h>
#నిర్వచించు __need_wchar_t
#అన్తర్భావ <stddef.h>

#నిర్వచితమైతే	__cplusplus
బాహ్య	"C"	{
#అయితే_ముగింపు

రకనిర్వచనం నిర్మాణం {
	intmax_t quot;
	intmax_t rem;
	} imaxdiv_t;

#ఒకవేళ !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS)

/* 7.8.1 Macros for format specifiers
 * 
 * MS runtime does not yet understand C9x standard "ll"
 * length specifier. It appears to treat "ll" as "l".
 * The non-standard I64 length specifier causes warning in GCC,
 * but understood by MS runtime functions.
 */

/* fprintf macros for signed types */
#నిర్వచించు PRId8 "d"
#నిర్వచించు PRId16 "d"
#నిర్వచించు PRId32 "d"
#నిర్వచించు PRId64 "I64d"

#నిర్వచించు PRIdLEAST8 "d"
#నిర్వచించు PRIdLEAST16 "d"
#నిర్వచించు PRIdLEAST32 "d"
#నిర్వచించు PRIdLEAST64 "I64d"

#నిర్వచించు PRIdFAST8 "d"
#నిర్వచించు PRIdFAST16 "d"
#నిర్వచించు PRIdFAST32 "d"
#నిర్వచించు PRIdFAST64 "I64d"

#నిర్వచించు PRIdMAX "I64d"

#నిర్వచించు PRIi8 "i"
#నిర్వచించు PRIi16 "i"
#నిర్వచించు PRIi32 "i"
#నిర్వచించు PRIi64 "I64i"

#నిర్వచించు PRIiLEAST8 "i"
#నిర్వచించు PRIiLEAST16 "i"
#నిర్వచించు PRIiLEAST32 "i"
#నిర్వచించు PRIiLEAST64 "I64i"

#నిర్వచించు PRIiFAST8 "i"
#నిర్వచించు PRIiFAST16 "i"
#నిర్వచించు PRIiFAST32 "i"
#నిర్వచించు PRIiFAST64 "I64i"

#నిర్వచించు PRIiMAX "I64i"

#నిర్వచించు PRIo8 "o"
#నిర్వచించు PRIo16 "o"
#నిర్వచించు PRIo32 "o"
#నిర్వచించు PRIo64 "I64o"

#నిర్వచించు PRIoLEAST8 "o"
#నిర్వచించు PRIoLEAST16 "o"
#నిర్వచించు PRIoLEAST32 "o"
#నిర్వచించు PRIoLEAST64 "I64o"

#నిర్వచించు PRIoFAST8 "o"
#నిర్వచించు PRIoFAST16 "o"
#నిర్వచించు PRIoFAST32 "o"
#నిర్వచించు PRIoFAST64 "I64o"

#నిర్వచించు PRIoMAX "I64o"

/* fprintf macros for unsigned types */
#నిర్వచించు PRIu8 "u"
#నిర్వచించు PRIu16 "u"
#నిర్వచించు PRIu32 "u"
#నిర్వచించు PRIu64 "I64u"


#నిర్వచించు PRIuLEAST8 "u"
#నిర్వచించు PRIuLEAST16 "u"
#నిర్వచించు PRIuLEAST32 "u"
#నిర్వచించు PRIuLEAST64 "I64u"

#నిర్వచించు PRIuFAST8 "u"
#నిర్వచించు PRIuFAST16 "u"
#నిర్వచించు PRIuFAST32 "u"
#నిర్వచించు PRIuFAST64 "I64u"

#నిర్వచించు PRIuMAX "I64u"

#నిర్వచించు PRIx8 "x"
#నిర్వచించు PRIx16 "x"
#నిర్వచించు PRIx32 "x"
#నిర్వచించు PRIx64 "I64x"

#నిర్వచించు PRIxLEAST8 "x"
#నిర్వచించు PRIxLEAST16 "x"
#నిర్వచించు PRIxLEAST32 "x"
#నిర్వచించు PRIxLEAST64 "I64x"

#నిర్వచించు PRIxFAST8 "x"
#నిర్వచించు PRIxFAST16 "x"
#నిర్వచించు PRIxFAST32 "x"
#నిర్వచించు PRIxFAST64 "I64x"

#నిర్వచించు PRIxMAX "I64x"

#నిర్వచించు PRIX8 "X"
#నిర్వచించు PRIX16 "X"
#నిర్వచించు PRIX32 "X"
#నిర్వచించు PRIX64 "I64X"

#నిర్వచించు PRIXLEAST8 "X"
#నిర్వచించు PRIXLEAST16 "X"
#నిర్వచించు PRIXLEAST32 "X"
#నిర్వచించు PRIXLEAST64 "I64X"

#నిర్వచించు PRIXFAST8 "X"
#నిర్వచించు PRIXFAST16 "X"
#నిర్వచించు PRIXFAST32 "X"
#నిర్వచించు PRIXFAST64 "I64X"

#నిర్వచించు PRIXMAX "I64X"

/*
 *   fscanf macros for signed int types
 *   NOTE: if 32-bit int is used for int_fast8_t and int_fast16_t
 *   (see stdint.h, 7.18.1.3), FAST8 and FAST16 should have
 *   no length identifiers
 */

#నిర్వచించు SCNd16 "hd"
#నిర్వచించు SCNd32 "d"
#నిర్వచించు SCNd64 "I64d"

#నిర్వచించు SCNdLEAST16 "hd"
#నిర్వచించు SCNdLEAST32 "d"
#నిర్వచించు SCNdLEAST64 "I64d"

#నిర్వచించు SCNdFAST16 "hd"
#నిర్వచించు SCNdFAST32 "d"
#నిర్వచించు SCNdFAST64 "I64d"

#నిర్వచించు SCNdMAX "I64d"

#నిర్వచించు SCNi16 "hi"
#నిర్వచించు SCNi32 "i"
#నిర్వచించు SCNi64 "I64i"

#నిర్వచించు SCNiLEAST16 "hi"
#నిర్వచించు SCNiLEAST32 "i"
#నిర్వచించు SCNiLEAST64 "I64i"

#నిర్వచించు SCNiFAST16 "hi"
#నిర్వచించు SCNiFAST32 "i"
#నిర్వచించు SCNiFAST64 "I64i"

#నిర్వచించు SCNiMAX "I64i"

#నిర్వచించు SCNo16 "ho"
#నిర్వచించు SCNo32 "o"
#నిర్వచించు SCNo64 "I64o"

#నిర్వచించు SCNoLEAST16 "ho"
#నిర్వచించు SCNoLEAST32 "o"
#నిర్వచించు SCNoLEAST64 "I64o"

#నిర్వచించు SCNoFAST16 "ho"
#నిర్వచించు SCNoFAST32 "o"
#నిర్వచించు SCNoFAST64 "I64o"

#నిర్వచించు SCNoMAX "I64o"

#నిర్వచించు SCNx16 "hx"
#నిర్వచించు SCNx32 "x"
#నిర్వచించు SCNx64 "I64x"

#నిర్వచించు SCNxLEAST16 "hx"
#నిర్వచించు SCNxLEAST32 "x"
#నిర్వచించు SCNxLEAST64 "I64x"

#నిర్వచించు SCNxFAST16 "hx"
#నిర్వచించు SCNxFAST32 "x"
#నిర్వచించు SCNxFAST64 "I64x"

#నిర్వచించు SCNxMAX "I64x"

/* fscanf macros for unsigned int types */

#నిర్వచించు SCNu16 "hu"
#నిర్వచించు SCNu32 "u"
#నిర్వచించు SCNu64 "I64u"

#నిర్వచించు SCNuLEAST16 "hu"
#నిర్వచించు SCNuLEAST32 "u"
#నిర్వచించు SCNuLEAST64 "I64u"

#నిర్వచించు SCNuFAST16 "hu"
#నిర్వచించు SCNuFAST32 "u"
#నిర్వచించు SCNuFAST64 "I64u"

#నిర్వచించు SCNuMAX "I64u"

#నిర్వచితమైతే _WIN64
#నిర్వచించు PRIdPTR "I64d"
#నిర్వచించు PRIiPTR "I64i"
#నిర్వచించు PRIoPTR "I64o"
#నిర్వచించు PRIuPTR "I64u"
#నిర్వచించు PRIxPTR "I64x"
#నిర్వచించు PRIXPTR "I64X"
#నిర్వచించు SCNdPTR "I64d"
#నిర్వచించు SCNiPTR "I64i"
#నిర్వచించు SCNoPTR "I64o"
#నిర్వచించు SCNxPTR "I64x"
#నిర్వచించు SCNuPTR "I64u"
#లేకపోతే
#నిర్వచించు PRIdPTR "d"
#నిర్వచించు PRIiPTR "i"
#నిర్వచించు PRIoPTR "o"
#నిర్వచించు PRIuPTR "u"
#నిర్వచించు PRIxPTR "x"
#నిర్వచించు PRIXPTR "X"
#నిర్వచించు SCNdPTR "d"
#నిర్వచించు SCNiPTR "i"
#నిర్వచించు SCNoPTR "o"
#నిర్వచించు SCNxPTR "x"
#నిర్వచించు SCNuPTR "u"
#అయితే_ముగింపు

#ఒకవేళ defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
/*
 * no length modifier for char types prior to C9x
 * MS runtime  scanf appears to treat "hh" as "h" 
 */

/* signed char */
#నిర్వచించు SCNd8 "hhd"
#నిర్వచించు SCNdLEAST8 "hhd"
#నిర్వచించు SCNdFAST8 "hhd"

#నిర్వచించు SCNi8 "hhi"
#నిర్వచించు SCNiLEAST8 "hhi"
#నిర్వచించు SCNiFAST8 "hhi"

#నిర్వచించు SCNo8 "hho"
#నిర్వచించు SCNoLEAST8 "hho"
#నిర్వచించు SCNoFAST8 "hho"

#నిర్వచించు SCNx8 "hhx"
#నిర్వచించు SCNxLEAST8 "hhx"
#నిర్వచించు SCNxFAST8 "hhx"

/* unsigned char */
#నిర్వచించు SCNu8 "hhu"
#నిర్వచించు SCNuLEAST8 "hhu"
#నిర్వచించు SCNuFAST8 "hhu"
#అయితే_ముగింపు /* __STDC_VERSION__ >= 199901 */

#అయితే_ముగింపు	/* !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS) */

intmax_t __cdecl imaxabs (intmax_t j);
__CRT_INLINE intmax_t __cdecl imaxabs (intmax_t j)
	{తిరిగి	(j >= 0 ? j : -j);}
imaxdiv_t __cdecl imaxdiv (intmax_t numer, intmax_t denom);

/* 7.8.2 Conversion functions for greatest-width integer types */

intmax_t __cdecl strtoimax (స్థిరరాశి అక్షరం* __restrict__ nptr,
                            అక్షరం** __restrict__ endptr, పూర్ణాంకం పునాది);
uintmax_t __cdecl strtoumax (స్థిరరాశి అక్షరం* __restrict__ nptr,
			     అక్షరం** __restrict__ endptr, పూర్ణాంకం పునాది);

intmax_t __cdecl wcstoimax (స్థిరరాశి wchar_t* __restrict__ nptr,
                            wchar_t** __restrict__ endptr, పూర్ణాంకం పునాది);
uintmax_t __cdecl wcstoumax (స్థిరరాశి wchar_t* __restrict__ nptr,
			     wchar_t** __restrict__ endptr, పూర్ణాంకం పునాది);

#నిర్వచితమైతే	__cplusplus
}
#అయితే_ముగింపు

#అయితే_ముగింపు /* ndef _INTTYPES_H */
