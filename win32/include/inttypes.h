/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* 7.8 Format conversion of integer types <inttypes.h> */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INTTYPES_H_
#ವ್ಯಾಖ್ಯಾನಿಸು _INTTYPES_H_

#ಅನ್ತರ್ಭಾವ <_mingw.h>
#ಅನ್ತರ್ಭಾವ <stdint.h>
#ವ್ಯಾಖ್ಯಾನಿಸು __need_wchar_t
#ಅನ್ತರ್ಭಾವ <stddef.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ	__cplusplus
ಬಾಹ್ಯ	"C"	{
#ಆದರೆ_ಅಂತ್ಯ

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
	intmax_t quot;
	intmax_t rem;
	} imaxdiv_t;

#ಆದರೆ !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS)

/* 7.8.1 Macros for format specifiers
 * 
 * MS runtime does not yet understand C9x standard "ll"
 * length specifier. It appears to treat "ll" as "l".
 * The non-standard I64 length specifier causes warning in GCC,
 * but understood by MS runtime functions.
 */

/* fprintf macros for signed types */
#ವ್ಯಾಖ್ಯಾನಿಸು PRId8 "d"
#ವ್ಯಾಖ್ಯಾನಿಸು PRId16 "d"
#ವ್ಯಾಖ್ಯಾನಿಸು PRId32 "d"
#ವ್ಯಾಖ್ಯಾನಿಸು PRId64 "I64d"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIdLEAST8 "d"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIdLEAST16 "d"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIdLEAST32 "d"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIdLEAST64 "I64d"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIdFAST8 "d"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIdFAST16 "d"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIdFAST32 "d"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIdFAST64 "I64d"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIdMAX "I64d"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIi8 "i"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIi16 "i"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIi32 "i"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIi64 "I64i"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIiLEAST8 "i"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIiLEAST16 "i"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIiLEAST32 "i"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIiLEAST64 "I64i"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIiFAST8 "i"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIiFAST16 "i"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIiFAST32 "i"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIiFAST64 "I64i"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIiMAX "I64i"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIo8 "o"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIo16 "o"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIo32 "o"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIo64 "I64o"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIoLEAST8 "o"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIoLEAST16 "o"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIoLEAST32 "o"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIoLEAST64 "I64o"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIoFAST8 "o"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIoFAST16 "o"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIoFAST32 "o"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIoFAST64 "I64o"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIoMAX "I64o"

/* fprintf macros for unsigned types */
#ವ್ಯಾಖ್ಯಾನಿಸು PRIu8 "u"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIu16 "u"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIu32 "u"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIu64 "I64u"


#ವ್ಯಾಖ್ಯಾನಿಸು PRIuLEAST8 "u"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIuLEAST16 "u"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIuLEAST32 "u"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIuLEAST64 "I64u"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIuFAST8 "u"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIuFAST16 "u"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIuFAST32 "u"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIuFAST64 "I64u"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIuMAX "I64u"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIx8 "x"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIx16 "x"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIx32 "x"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIx64 "I64x"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIxLEAST8 "x"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIxLEAST16 "x"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIxLEAST32 "x"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIxLEAST64 "I64x"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIxFAST8 "x"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIxFAST16 "x"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIxFAST32 "x"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIxFAST64 "I64x"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIxMAX "I64x"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIX8 "X"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIX16 "X"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIX32 "X"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIX64 "I64X"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIXLEAST8 "X"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIXLEAST16 "X"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIXLEAST32 "X"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIXLEAST64 "I64X"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIXFAST8 "X"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIXFAST16 "X"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIXFAST32 "X"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIXFAST64 "I64X"

#ವ್ಯಾಖ್ಯಾನಿಸು PRIXMAX "I64X"

/*
 *   fscanf macros for signed int types
 *   NOTE: if 32-bit int is used for int_fast8_t and int_fast16_t
 *   (see stdint.h, 7.18.1.3), FAST8 and FAST16 should have
 *   no length identifiers
 */

#ವ್ಯಾಖ್ಯಾನಿಸು SCNd16 "hd"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNd32 "d"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNd64 "I64d"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNdLEAST16 "hd"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNdLEAST32 "d"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNdLEAST64 "I64d"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNdFAST16 "hd"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNdFAST32 "d"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNdFAST64 "I64d"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNdMAX "I64d"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNi16 "hi"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNi32 "i"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNi64 "I64i"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNiLEAST16 "hi"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNiLEAST32 "i"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNiLEAST64 "I64i"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNiFAST16 "hi"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNiFAST32 "i"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNiFAST64 "I64i"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNiMAX "I64i"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNo16 "ho"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNo32 "o"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNo64 "I64o"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNoLEAST16 "ho"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNoLEAST32 "o"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNoLEAST64 "I64o"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNoFAST16 "ho"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNoFAST32 "o"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNoFAST64 "I64o"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNoMAX "I64o"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNx16 "hx"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNx32 "x"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNx64 "I64x"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNxLEAST16 "hx"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNxLEAST32 "x"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNxLEAST64 "I64x"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNxFAST16 "hx"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNxFAST32 "x"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNxFAST64 "I64x"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNxMAX "I64x"

/* fscanf macros for unsigned int types */

#ವ್ಯಾಖ್ಯಾನಿಸು SCNu16 "hu"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNu32 "u"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNu64 "I64u"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNuLEAST16 "hu"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNuLEAST32 "u"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNuLEAST64 "I64u"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNuFAST16 "hu"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNuFAST32 "u"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNuFAST64 "I64u"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNuMAX "I64u"

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನಿಸು PRIdPTR "I64d"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIiPTR "I64i"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIoPTR "I64o"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIuPTR "I64u"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIxPTR "I64x"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIXPTR "I64X"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNdPTR "I64d"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNiPTR "I64i"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNoPTR "I64o"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNxPTR "I64x"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNuPTR "I64u"
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು PRIdPTR "d"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIiPTR "i"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIoPTR "o"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIuPTR "u"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIxPTR "x"
#ವ್ಯಾಖ್ಯಾನಿಸು PRIXPTR "X"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNdPTR "d"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNiPTR "i"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNoPTR "o"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNxPTR "x"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNuPTR "u"
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
/*
 * no length modifier for char types prior to C9x
 * MS runtime  scanf appears to treat "hh" as "h" 
 */

/* signed char */
#ವ್ಯಾಖ್ಯಾನಿಸು SCNd8 "hhd"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNdLEAST8 "hhd"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNdFAST8 "hhd"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNi8 "hhi"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNiLEAST8 "hhi"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNiFAST8 "hhi"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNo8 "hho"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNoLEAST8 "hho"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNoFAST8 "hho"

#ವ್ಯಾಖ್ಯಾನಿಸು SCNx8 "hhx"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNxLEAST8 "hhx"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNxFAST8 "hhx"

/* unsigned char */
#ವ್ಯಾಖ್ಯಾನಿಸು SCNu8 "hhu"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNuLEAST8 "hhu"
#ವ್ಯಾಖ್ಯಾನಿಸು SCNuFAST8 "hhu"
#ಆದರೆ_ಅಂತ್ಯ /* __STDC_VERSION__ >= 199901 */

#ಆದರೆ_ಅಂತ್ಯ	/* !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS) */

intmax_t __cdecl imaxabs (intmax_t j);
__CRT_INLINE intmax_t __cdecl imaxabs (intmax_t j)
	{ಹಿಂತಿರುಗಿ	(j >= 0 ? j : -j);}
imaxdiv_t __cdecl imaxdiv (intmax_t numer, intmax_t denom);

/* 7.8.2 Conversion functions for greatest-width integer types */

intmax_t __cdecl strtoimax (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ* __restrict__ nptr,
                            ಅಕ್ಷರ** __restrict__ endptr, ಪೂರ್ಣಾಂಕ ತಳ);
uintmax_t __cdecl strtoumax (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ* __restrict__ nptr,
			     ಅಕ್ಷರ** __restrict__ endptr, ಪೂರ್ಣಾಂಕ ತಳ);

intmax_t __cdecl wcstoimax (ಸ್ಥಿರಾಂಕ wchar_t* __restrict__ nptr,
                            wchar_t** __restrict__ endptr, ಪೂರ್ಣಾಂಕ ತಳ);
uintmax_t __cdecl wcstoumax (ಸ್ಥಿರಾಂಕ wchar_t* __restrict__ nptr,
			     wchar_t** __restrict__ endptr, ಪೂರ್ಣಾಂಕ ತಳ);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ	__cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ_ಅಂತ್ಯ /* ndef _INTTYPES_H */
