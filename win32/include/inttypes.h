/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* 7.8 Format conversion of integer types <inttypes.h> */

#جے_بنا_تعریف _INTTYPES_H_
#تعریف_کرو _INTTYPES_H_

#ضمن <_mingw.h>
#ضمن <stdint.h>
#تعریف_کرو __need_wchar_t
#ضمن <stddef.h>

#جے_تعریف_شدہ	__cplusplus
خارجي	"C"	{
#جے_انت

تعريفنوع بنية {
	intmax_t quot;
	intmax_t rem;
	} imaxdiv_t;

#إذا !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS)

/* 7.8.1 Macros for format specifiers
 * 
 * MS runtime does not yet understand C9x standard "ll"
 * length specifier. It appears to treat "ll" as "l".
 * The non-standard I64 length specifier causes warning in GCC,
 * but understood by MS runtime functions.
 */

/* fprintf macros for signed types */
#تعریف_کرو PRId8 "d"
#تعریف_کرو PRId16 "d"
#تعریف_کرو PRId32 "d"
#تعریف_کرو PRId64 "I64d"

#تعریف_کرو PRIdLEAST8 "d"
#تعریف_کرو PRIdLEAST16 "d"
#تعریف_کرو PRIdLEAST32 "d"
#تعریف_کرو PRIdLEAST64 "I64d"

#تعریف_کرو PRIdFAST8 "d"
#تعریف_کرو PRIdFAST16 "d"
#تعریف_کرو PRIdFAST32 "d"
#تعریف_کرو PRIdFAST64 "I64d"

#تعریف_کرو PRIdMAX "I64d"

#تعریف_کرو PRIi8 "i"
#تعریف_کرو PRIi16 "i"
#تعریف_کرو PRIi32 "i"
#تعریف_کرو PRIi64 "I64i"

#تعریف_کرو PRIiLEAST8 "i"
#تعریف_کرو PRIiLEAST16 "i"
#تعریف_کرو PRIiLEAST32 "i"
#تعریف_کرو PRIiLEAST64 "I64i"

#تعریف_کرو PRIiFAST8 "i"
#تعریف_کرو PRIiFAST16 "i"
#تعریف_کرو PRIiFAST32 "i"
#تعریف_کرو PRIiFAST64 "I64i"

#تعریف_کرو PRIiMAX "I64i"

#تعریف_کرو PRIo8 "o"
#تعریف_کرو PRIo16 "o"
#تعریف_کرو PRIo32 "o"
#تعریف_کرو PRIo64 "I64o"

#تعریف_کرو PRIoLEAST8 "o"
#تعریف_کرو PRIoLEAST16 "o"
#تعریف_کرو PRIoLEAST32 "o"
#تعریف_کرو PRIoLEAST64 "I64o"

#تعریف_کرو PRIoFAST8 "o"
#تعریف_کرو PRIoFAST16 "o"
#تعریف_کرو PRIoFAST32 "o"
#تعریف_کرو PRIoFAST64 "I64o"

#تعریف_کرو PRIoMAX "I64o"

/* fprintf macros for unsigned types */
#تعریف_کرو PRIu8 "u"
#تعریف_کرو PRIu16 "u"
#تعریف_کرو PRIu32 "u"
#تعریف_کرو PRIu64 "I64u"


#تعریف_کرو PRIuLEAST8 "u"
#تعریف_کرو PRIuLEAST16 "u"
#تعریف_کرو PRIuLEAST32 "u"
#تعریف_کرو PRIuLEAST64 "I64u"

#تعریف_کرو PRIuFAST8 "u"
#تعریف_کرو PRIuFAST16 "u"
#تعریف_کرو PRIuFAST32 "u"
#تعریف_کرو PRIuFAST64 "I64u"

#تعریف_کرو PRIuMAX "I64u"

#تعریف_کرو PRIx8 "x"
#تعریف_کرو PRIx16 "x"
#تعریف_کرو PRIx32 "x"
#تعریف_کرو PRIx64 "I64x"

#تعریف_کرو PRIxLEAST8 "x"
#تعریف_کرو PRIxLEAST16 "x"
#تعریف_کرو PRIxLEAST32 "x"
#تعریف_کرو PRIxLEAST64 "I64x"

#تعریف_کرو PRIxFAST8 "x"
#تعریف_کرو PRIxFAST16 "x"
#تعریف_کرو PRIxFAST32 "x"
#تعریف_کرو PRIxFAST64 "I64x"

#تعریف_کرو PRIxMAX "I64x"

#تعریف_کرو PRIX8 "X"
#تعریف_کرو PRIX16 "X"
#تعریف_کرو PRIX32 "X"
#تعریف_کرو PRIX64 "I64X"

#تعریف_کرو PRIXLEAST8 "X"
#تعریف_کرو PRIXLEAST16 "X"
#تعریف_کرو PRIXLEAST32 "X"
#تعریف_کرو PRIXLEAST64 "I64X"

#تعریف_کرو PRIXFAST8 "X"
#تعریف_کرو PRIXFAST16 "X"
#تعریف_کرو PRIXFAST32 "X"
#تعریف_کرو PRIXFAST64 "I64X"

#تعریف_کرو PRIXMAX "I64X"

/*
 *   fscanf macros for signed int types
 *   NOTE: if 32-bit int is used for int_fast8_t and int_fast16_t
 *   (see stdint.h, 7.18.1.3), FAST8 and FAST16 should have
 *   no length identifiers
 */

#تعریف_کرو SCNd16 "hd"
#تعریف_کرو SCNd32 "d"
#تعریف_کرو SCNd64 "I64d"

#تعریف_کرو SCNdLEAST16 "hd"
#تعریف_کرو SCNdLEAST32 "d"
#تعریف_کرو SCNdLEAST64 "I64d"

#تعریف_کرو SCNdFAST16 "hd"
#تعریف_کرو SCNdFAST32 "d"
#تعریف_کرو SCNdFAST64 "I64d"

#تعریف_کرو SCNdMAX "I64d"

#تعریف_کرو SCNi16 "hi"
#تعریف_کرو SCNi32 "i"
#تعریف_کرو SCNi64 "I64i"

#تعریف_کرو SCNiLEAST16 "hi"
#تعریف_کرو SCNiLEAST32 "i"
#تعریف_کرو SCNiLEAST64 "I64i"

#تعریف_کرو SCNiFAST16 "hi"
#تعریف_کرو SCNiFAST32 "i"
#تعریف_کرو SCNiFAST64 "I64i"

#تعریف_کرو SCNiMAX "I64i"

#تعریف_کرو SCNo16 "ho"
#تعریف_کرو SCNo32 "o"
#تعریف_کرو SCNo64 "I64o"

#تعریف_کرو SCNoLEAST16 "ho"
#تعریف_کرو SCNoLEAST32 "o"
#تعریف_کرو SCNoLEAST64 "I64o"

#تعریف_کرو SCNoFAST16 "ho"
#تعریف_کرو SCNoFAST32 "o"
#تعریف_کرو SCNoFAST64 "I64o"

#تعریف_کرو SCNoMAX "I64o"

#تعریف_کرو SCNx16 "hx"
#تعریف_کرو SCNx32 "x"
#تعریف_کرو SCNx64 "I64x"

#تعریف_کرو SCNxLEAST16 "hx"
#تعریف_کرو SCNxLEAST32 "x"
#تعریف_کرو SCNxLEAST64 "I64x"

#تعریف_کرو SCNxFAST16 "hx"
#تعریف_کرو SCNxFAST32 "x"
#تعریف_کرو SCNxFAST64 "I64x"

#تعریف_کرو SCNxMAX "I64x"

/* fscanf macros for unsigned int types */

#تعریف_کرو SCNu16 "hu"
#تعریف_کرو SCNu32 "u"
#تعریف_کرو SCNu64 "I64u"

#تعریف_کرو SCNuLEAST16 "hu"
#تعریف_کرو SCNuLEAST32 "u"
#تعریف_کرو SCNuLEAST64 "I64u"

#تعریف_کرو SCNuFAST16 "hu"
#تعریف_کرو SCNuFAST32 "u"
#تعریف_کرو SCNuFAST64 "I64u"

#تعریف_کرو SCNuMAX "I64u"

#جے_تعریف_شدہ _WIN64
#تعریف_کرو PRIdPTR "I64d"
#تعریف_کرو PRIiPTR "I64i"
#تعریف_کرو PRIoPTR "I64o"
#تعریف_کرو PRIuPTR "I64u"
#تعریف_کرو PRIxPTR "I64x"
#تعریف_کرو PRIXPTR "I64X"
#تعریف_کرو SCNdPTR "I64d"
#تعریف_کرو SCNiPTR "I64i"
#تعریف_کرو SCNoPTR "I64o"
#تعریف_کرو SCNxPTR "I64x"
#تعریف_کرو SCNuPTR "I64u"
#وإلا
#تعریف_کرو PRIdPTR "d"
#تعریف_کرو PRIiPTR "i"
#تعریف_کرو PRIoPTR "o"
#تعریف_کرو PRIuPTR "u"
#تعریف_کرو PRIxPTR "x"
#تعریف_کرو PRIXPTR "X"
#تعریف_کرو SCNdPTR "d"
#تعریف_کرو SCNiPTR "i"
#تعریف_کرو SCNoPTR "o"
#تعریف_کرو SCNxPTR "x"
#تعریف_کرو SCNuPTR "u"
#جے_انت

#إذا defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
/*
 * no length modifier for char types prior to C9x
 * MS runtime  scanf appears to treat "hh" as "h" 
 */

/* signed char */
#تعریف_کرو SCNd8 "hhd"
#تعریف_کرو SCNdLEAST8 "hhd"
#تعریف_کرو SCNdFAST8 "hhd"

#تعریف_کرو SCNi8 "hhi"
#تعریف_کرو SCNiLEAST8 "hhi"
#تعریف_کرو SCNiFAST8 "hhi"

#تعریف_کرو SCNo8 "hho"
#تعریف_کرو SCNoLEAST8 "hho"
#تعریف_کرو SCNoFAST8 "hho"

#تعریف_کرو SCNx8 "hhx"
#تعریف_کرو SCNxLEAST8 "hhx"
#تعریف_کرو SCNxFAST8 "hhx"

/* unsigned char */
#تعریف_کرو SCNu8 "hhu"
#تعریف_کرو SCNuLEAST8 "hhu"
#تعریف_کرو SCNuFAST8 "hhu"
#جے_انت /* __STDC_VERSION__ >= 199901 */

#جے_انت	/* !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS) */

intmax_t __cdecl imaxabs (intmax_t j);
__CRT_INLINE intmax_t __cdecl imaxabs (intmax_t j)
	{أرجع	(j >= 0 ? j : -j);}
imaxdiv_t __cdecl imaxdiv (intmax_t numer, intmax_t denom);

/* 7.8.2 Conversion functions for greatest-width integer types */

intmax_t __cdecl strtoimax (ثابت حرف* __restrict__ nptr,
                            حرف** __restrict__ endptr, صحيح ادھار);
uintmax_t __cdecl strtoumax (ثابت حرف* __restrict__ nptr,
			     حرف** __restrict__ endptr, صحيح ادھار);

intmax_t __cdecl wcstoimax (ثابت wchar_t* __restrict__ nptr,
                            wchar_t** __restrict__ endptr, صحيح ادھار);
uintmax_t __cdecl wcstoumax (ثابت wchar_t* __restrict__ nptr,
			     wchar_t** __restrict__ endptr, صحيح ادھار);

#جے_تعریف_شدہ	__cplusplus
}
#جے_انت

#جے_انت /* ndef _INTTYPES_H */
