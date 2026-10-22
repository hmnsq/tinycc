/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* 7.8 Format conversion of integer types <inttypes.h> */

#جيڪڏهن_وصف_نه_ٿيل _INTTYPES_H_
#وصف_ڪريو _INTTYPES_H_

#ضمن <_mingw.h>
#ضمن <stdint.h>
#وصف_ڪريو __need_wchar_t
#ضمن <stddef.h>

#جيڪڏهن_وصف_ٿيل	__cplusplus
خارجي	"C"	{
#جيڪڏهن_پورو

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
#وصف_ڪريو PRId8 "d"
#وصف_ڪريو PRId16 "d"
#وصف_ڪريو PRId32 "d"
#وصف_ڪريو PRId64 "I64d"

#وصف_ڪريو PRIdLEAST8 "d"
#وصف_ڪريو PRIdLEAST16 "d"
#وصف_ڪريو PRIdLEAST32 "d"
#وصف_ڪريو PRIdLEAST64 "I64d"

#وصف_ڪريو PRIdFAST8 "d"
#وصف_ڪريو PRIdFAST16 "d"
#وصف_ڪريو PRIdFAST32 "d"
#وصف_ڪريو PRIdFAST64 "I64d"

#وصف_ڪريو PRIdMAX "I64d"

#وصف_ڪريو PRIi8 "i"
#وصف_ڪريو PRIi16 "i"
#وصف_ڪريو PRIi32 "i"
#وصف_ڪريو PRIi64 "I64i"

#وصف_ڪريو PRIiLEAST8 "i"
#وصف_ڪريو PRIiLEAST16 "i"
#وصف_ڪريو PRIiLEAST32 "i"
#وصف_ڪريو PRIiLEAST64 "I64i"

#وصف_ڪريو PRIiFAST8 "i"
#وصف_ڪريو PRIiFAST16 "i"
#وصف_ڪريو PRIiFAST32 "i"
#وصف_ڪريو PRIiFAST64 "I64i"

#وصف_ڪريو PRIiMAX "I64i"

#وصف_ڪريو PRIo8 "o"
#وصف_ڪريو PRIo16 "o"
#وصف_ڪريو PRIo32 "o"
#وصف_ڪريو PRIo64 "I64o"

#وصف_ڪريو PRIoLEAST8 "o"
#وصف_ڪريو PRIoLEAST16 "o"
#وصف_ڪريو PRIoLEAST32 "o"
#وصف_ڪريو PRIoLEAST64 "I64o"

#وصف_ڪريو PRIoFAST8 "o"
#وصف_ڪريو PRIoFAST16 "o"
#وصف_ڪريو PRIoFAST32 "o"
#وصف_ڪريو PRIoFAST64 "I64o"

#وصف_ڪريو PRIoMAX "I64o"

/* fprintf macros for unsigned types */
#وصف_ڪريو PRIu8 "u"
#وصف_ڪريو PRIu16 "u"
#وصف_ڪريو PRIu32 "u"
#وصف_ڪريو PRIu64 "I64u"


#وصف_ڪريو PRIuLEAST8 "u"
#وصف_ڪريو PRIuLEAST16 "u"
#وصف_ڪريو PRIuLEAST32 "u"
#وصف_ڪريو PRIuLEAST64 "I64u"

#وصف_ڪريو PRIuFAST8 "u"
#وصف_ڪريو PRIuFAST16 "u"
#وصف_ڪريو PRIuFAST32 "u"
#وصف_ڪريو PRIuFAST64 "I64u"

#وصف_ڪريو PRIuMAX "I64u"

#وصف_ڪريو PRIx8 "x"
#وصف_ڪريو PRIx16 "x"
#وصف_ڪريو PRIx32 "x"
#وصف_ڪريو PRIx64 "I64x"

#وصف_ڪريو PRIxLEAST8 "x"
#وصف_ڪريو PRIxLEAST16 "x"
#وصف_ڪريو PRIxLEAST32 "x"
#وصف_ڪريو PRIxLEAST64 "I64x"

#وصف_ڪريو PRIxFAST8 "x"
#وصف_ڪريو PRIxFAST16 "x"
#وصف_ڪريو PRIxFAST32 "x"
#وصف_ڪريو PRIxFAST64 "I64x"

#وصف_ڪريو PRIxMAX "I64x"

#وصف_ڪريو PRIX8 "X"
#وصف_ڪريو PRIX16 "X"
#وصف_ڪريو PRIX32 "X"
#وصف_ڪريو PRIX64 "I64X"

#وصف_ڪريو PRIXLEAST8 "X"
#وصف_ڪريو PRIXLEAST16 "X"
#وصف_ڪريو PRIXLEAST32 "X"
#وصف_ڪريو PRIXLEAST64 "I64X"

#وصف_ڪريو PRIXFAST8 "X"
#وصف_ڪريو PRIXFAST16 "X"
#وصف_ڪريو PRIXFAST32 "X"
#وصف_ڪريو PRIXFAST64 "I64X"

#وصف_ڪريو PRIXMAX "I64X"

/*
 *   fscanf macros for signed int types
 *   NOTE: if 32-bit int is used for int_fast8_t and int_fast16_t
 *   (see stdint.h, 7.18.1.3), FAST8 and FAST16 should have
 *   no length identifiers
 */

#وصف_ڪريو SCNd16 "hd"
#وصف_ڪريو SCNd32 "d"
#وصف_ڪريو SCNd64 "I64d"

#وصف_ڪريو SCNdLEAST16 "hd"
#وصف_ڪريو SCNdLEAST32 "d"
#وصف_ڪريو SCNdLEAST64 "I64d"

#وصف_ڪريو SCNdFAST16 "hd"
#وصف_ڪريو SCNdFAST32 "d"
#وصف_ڪريو SCNdFAST64 "I64d"

#وصف_ڪريو SCNdMAX "I64d"

#وصف_ڪريو SCNi16 "hi"
#وصف_ڪريو SCNi32 "i"
#وصف_ڪريو SCNi64 "I64i"

#وصف_ڪريو SCNiLEAST16 "hi"
#وصف_ڪريو SCNiLEAST32 "i"
#وصف_ڪريو SCNiLEAST64 "I64i"

#وصف_ڪريو SCNiFAST16 "hi"
#وصف_ڪريو SCNiFAST32 "i"
#وصف_ڪريو SCNiFAST64 "I64i"

#وصف_ڪريو SCNiMAX "I64i"

#وصف_ڪريو SCNo16 "ho"
#وصف_ڪريو SCNo32 "o"
#وصف_ڪريو SCNo64 "I64o"

#وصف_ڪريو SCNoLEAST16 "ho"
#وصف_ڪريو SCNoLEAST32 "o"
#وصف_ڪريو SCNoLEAST64 "I64o"

#وصف_ڪريو SCNoFAST16 "ho"
#وصف_ڪريو SCNoFAST32 "o"
#وصف_ڪريو SCNoFAST64 "I64o"

#وصف_ڪريو SCNoMAX "I64o"

#وصف_ڪريو SCNx16 "hx"
#وصف_ڪريو SCNx32 "x"
#وصف_ڪريو SCNx64 "I64x"

#وصف_ڪريو SCNxLEAST16 "hx"
#وصف_ڪريو SCNxLEAST32 "x"
#وصف_ڪريو SCNxLEAST64 "I64x"

#وصف_ڪريو SCNxFAST16 "hx"
#وصف_ڪريو SCNxFAST32 "x"
#وصف_ڪريو SCNxFAST64 "I64x"

#وصف_ڪريو SCNxMAX "I64x"

/* fscanf macros for unsigned int types */

#وصف_ڪريو SCNu16 "hu"
#وصف_ڪريو SCNu32 "u"
#وصف_ڪريو SCNu64 "I64u"

#وصف_ڪريو SCNuLEAST16 "hu"
#وصف_ڪريو SCNuLEAST32 "u"
#وصف_ڪريو SCNuLEAST64 "I64u"

#وصف_ڪريو SCNuFAST16 "hu"
#وصف_ڪريو SCNuFAST32 "u"
#وصف_ڪريو SCNuFAST64 "I64u"

#وصف_ڪريو SCNuMAX "I64u"

#جيڪڏهن_وصف_ٿيل _WIN64
#وصف_ڪريو PRIdPTR "I64d"
#وصف_ڪريو PRIiPTR "I64i"
#وصف_ڪريو PRIoPTR "I64o"
#وصف_ڪريو PRIuPTR "I64u"
#وصف_ڪريو PRIxPTR "I64x"
#وصف_ڪريو PRIXPTR "I64X"
#وصف_ڪريو SCNdPTR "I64d"
#وصف_ڪريو SCNiPTR "I64i"
#وصف_ڪريو SCNoPTR "I64o"
#وصف_ڪريو SCNxPTR "I64x"
#وصف_ڪريو SCNuPTR "I64u"
#وإلا
#وصف_ڪريو PRIdPTR "d"
#وصف_ڪريو PRIiPTR "i"
#وصف_ڪريو PRIoPTR "o"
#وصف_ڪريو PRIuPTR "u"
#وصف_ڪريو PRIxPTR "x"
#وصف_ڪريو PRIXPTR "X"
#وصف_ڪريو SCNdPTR "d"
#وصف_ڪريو SCNiPTR "i"
#وصف_ڪريو SCNoPTR "o"
#وصف_ڪريو SCNxPTR "x"
#وصف_ڪريو SCNuPTR "u"
#جيڪڏهن_پورو

#إذا defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
/*
 * no length modifier for char types prior to C9x
 * MS runtime  scanf appears to treat "hh" as "h" 
 */

/* signed char */
#وصف_ڪريو SCNd8 "hhd"
#وصف_ڪريو SCNdLEAST8 "hhd"
#وصف_ڪريو SCNdFAST8 "hhd"

#وصف_ڪريو SCNi8 "hhi"
#وصف_ڪريو SCNiLEAST8 "hhi"
#وصف_ڪريو SCNiFAST8 "hhi"

#وصف_ڪريو SCNo8 "hho"
#وصف_ڪريو SCNoLEAST8 "hho"
#وصف_ڪريو SCNoFAST8 "hho"

#وصف_ڪريو SCNx8 "hhx"
#وصف_ڪريو SCNxLEAST8 "hhx"
#وصف_ڪريو SCNxFAST8 "hhx"

/* unsigned char */
#وصف_ڪريو SCNu8 "hhu"
#وصف_ڪريو SCNuLEAST8 "hhu"
#وصف_ڪريو SCNuFAST8 "hhu"
#جيڪڏهن_پورو /* __STDC_VERSION__ >= 199901 */

#جيڪڏهن_پورو	/* !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS) */

intmax_t __cdecl imaxabs (intmax_t j);
__CRT_INLINE intmax_t __cdecl imaxabs (intmax_t j)
	{أرجع	(j >= 0 ? j : -j);}
imaxdiv_t __cdecl imaxdiv (intmax_t numer, intmax_t denom);

/* 7.8.2 Conversion functions for greatest-width integer types */

intmax_t __cdecl strtoimax (ثابت حرف* __restrict__ nptr,
                            حرف** __restrict__ endptr, صحيح بنياد);
uintmax_t __cdecl strtoumax (ثابت حرف* __restrict__ nptr,
			     حرف** __restrict__ endptr, صحيح بنياد);

intmax_t __cdecl wcstoimax (ثابت wchar_t* __restrict__ nptr,
                            wchar_t** __restrict__ endptr, صحيح بنياد);
uintmax_t __cdecl wcstoumax (ثابت wchar_t* __restrict__ nptr,
			     wchar_t** __restrict__ endptr, صحيح بنياد);

#جيڪڏهن_وصف_ٿيل	__cplusplus
}
#جيڪڏهن_پورو

#جيڪڏهن_پورو /* ndef _INTTYPES_H */
