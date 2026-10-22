/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* 7.8 Format conversion of integer types <inttypes.h> */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INTTYPES_H_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INTTYPES_H_

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdint.h>
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __need_wchar_t
#ਅਨ੍ਤਰ੍ਭਾਵ <stddef.h>

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ	__cplusplus
ਬਾਹਰੀ	"C"	{
#ਜੇ_ਅੰਤ

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
	intmax_t quot;
	intmax_t rem;
	} imaxdiv_t;

#ਜੇ !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS)

/* 7.8.1 Macros for format specifiers
 * 
 * MS runtime does not yet understand C9x standard "ll"
 * length specifier. It appears to treat "ll" as "l".
 * The non-standard I64 length specifier causes warning in GCC,
 * but understood by MS runtime functions.
 */

/* fprintf macros for signed types */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRId8 "d"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRId16 "d"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRId32 "d"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRId64 "I64d"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIdLEAST8 "d"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIdLEAST16 "d"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIdLEAST32 "d"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIdLEAST64 "I64d"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIdFAST8 "d"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIdFAST16 "d"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIdFAST32 "d"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIdFAST64 "I64d"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIdMAX "I64d"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIi8 "i"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIi16 "i"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIi32 "i"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIi64 "I64i"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIiLEAST8 "i"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIiLEAST16 "i"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIiLEAST32 "i"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIiLEAST64 "I64i"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIiFAST8 "i"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIiFAST16 "i"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIiFAST32 "i"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIiFAST64 "I64i"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIiMAX "I64i"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIo8 "o"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIo16 "o"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIo32 "o"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIo64 "I64o"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIoLEAST8 "o"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIoLEAST16 "o"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIoLEAST32 "o"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIoLEAST64 "I64o"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIoFAST8 "o"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIoFAST16 "o"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIoFAST32 "o"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIoFAST64 "I64o"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIoMAX "I64o"

/* fprintf macros for unsigned types */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIu8 "u"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIu16 "u"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIu32 "u"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIu64 "I64u"


#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIuLEAST8 "u"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIuLEAST16 "u"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIuLEAST32 "u"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIuLEAST64 "I64u"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIuFAST8 "u"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIuFAST16 "u"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIuFAST32 "u"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIuFAST64 "I64u"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIuMAX "I64u"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIx8 "x"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIx16 "x"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIx32 "x"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIx64 "I64x"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIxLEAST8 "x"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIxLEAST16 "x"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIxLEAST32 "x"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIxLEAST64 "I64x"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIxFAST8 "x"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIxFAST16 "x"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIxFAST32 "x"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIxFAST64 "I64x"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIxMAX "I64x"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIX8 "X"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIX16 "X"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIX32 "X"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIX64 "I64X"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIXLEAST8 "X"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIXLEAST16 "X"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIXLEAST32 "X"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIXLEAST64 "I64X"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIXFAST8 "X"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIXFAST16 "X"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIXFAST32 "X"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIXFAST64 "I64X"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIXMAX "I64X"

/*
 *   fscanf macros for signed int types
 *   NOTE: if 32-bit int is used for int_fast8_t and int_fast16_t
 *   (see stdint.h, 7.18.1.3), FAST8 and FAST16 should have
 *   no length identifiers
 */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNd16 "hd"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNd32 "d"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNd64 "I64d"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNdLEAST16 "hd"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNdLEAST32 "d"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNdLEAST64 "I64d"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNdFAST16 "hd"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNdFAST32 "d"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNdFAST64 "I64d"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNdMAX "I64d"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNi16 "hi"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNi32 "i"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNi64 "I64i"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNiLEAST16 "hi"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNiLEAST32 "i"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNiLEAST64 "I64i"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNiFAST16 "hi"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNiFAST32 "i"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNiFAST64 "I64i"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNiMAX "I64i"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNo16 "ho"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNo32 "o"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNo64 "I64o"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNoLEAST16 "ho"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNoLEAST32 "o"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNoLEAST64 "I64o"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNoFAST16 "ho"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNoFAST32 "o"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNoFAST64 "I64o"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNoMAX "I64o"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNx16 "hx"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNx32 "x"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNx64 "I64x"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNxLEAST16 "hx"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNxLEAST32 "x"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNxLEAST64 "I64x"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNxFAST16 "hx"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNxFAST32 "x"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNxFAST64 "I64x"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNxMAX "I64x"

/* fscanf macros for unsigned int types */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNu16 "hu"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNu32 "u"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNu64 "I64u"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNuLEAST16 "hu"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNuLEAST32 "u"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNuLEAST64 "I64u"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNuFAST16 "hu"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNuFAST32 "u"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNuFAST64 "I64u"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNuMAX "I64u"

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIdPTR "I64d"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIiPTR "I64i"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIoPTR "I64o"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIuPTR "I64u"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIxPTR "I64x"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIXPTR "I64X"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNdPTR "I64d"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNiPTR "I64i"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNoPTR "I64o"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNxPTR "I64x"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNuPTR "I64u"
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIdPTR "d"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIiPTR "i"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIoPTR "o"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIuPTR "u"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIxPTR "x"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIXPTR "X"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNdPTR "d"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNiPTR "i"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNoPTR "o"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNxPTR "x"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNuPTR "u"
#ਜੇ_ਅੰਤ

#ਜੇ defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
/*
 * no length modifier for char types prior to C9x
 * MS runtime  scanf appears to treat "hh" as "h" 
 */

/* signed char */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNd8 "hhd"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNdLEAST8 "hhd"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNdFAST8 "hhd"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNi8 "hhi"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNiLEAST8 "hhi"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNiFAST8 "hhi"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNo8 "hho"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNoLEAST8 "hho"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNoFAST8 "hho"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNx8 "hhx"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNxLEAST8 "hhx"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNxFAST8 "hhx"

/* unsigned char */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNu8 "hhu"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNuLEAST8 "hhu"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNuFAST8 "hhu"
#ਜੇ_ਅੰਤ /* __STDC_VERSION__ >= 199901 */

#ਜੇ_ਅੰਤ	/* !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS) */

intmax_t __cdecl imaxabs (intmax_t j);
__CRT_INLINE intmax_t __cdecl imaxabs (intmax_t j)
	{ਵਾਪਸ	(j >= 0 ? j : -j);}
imaxdiv_t __cdecl imaxdiv (intmax_t numer, intmax_t denom);

/* 7.8.2 Conversion functions for greatest-width integer types */

intmax_t __cdecl strtoimax (ਅਚਲ ਅੱਖਰ* __restrict__ nptr,
                            ਅੱਖਰ** __restrict__ endptr, ਪੂਰਨ ਅਧਾਰ);
uintmax_t __cdecl strtoumax (ਅਚਲ ਅੱਖਰ* __restrict__ nptr,
			     ਅੱਖਰ** __restrict__ endptr, ਪੂਰਨ ਅਧਾਰ);

intmax_t __cdecl wcstoimax (ਅਚਲ wchar_t* __restrict__ nptr,
                            wchar_t** __restrict__ endptr, ਪੂਰਨ ਅਧਾਰ);
uintmax_t __cdecl wcstoumax (ਅਚਲ wchar_t* __restrict__ nptr,
			     wchar_t** __restrict__ endptr, ਪੂਰਨ ਅਧਾਰ);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ	__cplusplus
}
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ /* ndef _INTTYPES_H */
