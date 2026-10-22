/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* 7.8 Format conversion of integer types <inttypes.h> */

#که_نه_تعریف_شوی _INTTYPES_H_
#تعریف_کړه _INTTYPES_H_

#ضمن <_mingw.h>
#ضمن <stdint.h>
#تعریف_کړه __need_wchar_t
#ضمن <stddef.h>

#که_تعریف_شوی	__cplusplus
خارجي	"C"	{
#د_که_پای

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
#تعریف_کړه PRId8 "d"
#تعریف_کړه PRId16 "d"
#تعریف_کړه PRId32 "d"
#تعریف_کړه PRId64 "I64d"

#تعریف_کړه PRIdLEAST8 "d"
#تعریف_کړه PRIdLEAST16 "d"
#تعریف_کړه PRIdLEAST32 "d"
#تعریف_کړه PRIdLEAST64 "I64d"

#تعریف_کړه PRIdFAST8 "d"
#تعریف_کړه PRIdFAST16 "d"
#تعریف_کړه PRIdFAST32 "d"
#تعریف_کړه PRIdFAST64 "I64d"

#تعریف_کړه PRIdMAX "I64d"

#تعریف_کړه PRIi8 "i"
#تعریف_کړه PRIi16 "i"
#تعریف_کړه PRIi32 "i"
#تعریف_کړه PRIi64 "I64i"

#تعریف_کړه PRIiLEAST8 "i"
#تعریف_کړه PRIiLEAST16 "i"
#تعریف_کړه PRIiLEAST32 "i"
#تعریف_کړه PRIiLEAST64 "I64i"

#تعریف_کړه PRIiFAST8 "i"
#تعریف_کړه PRIiFAST16 "i"
#تعریف_کړه PRIiFAST32 "i"
#تعریف_کړه PRIiFAST64 "I64i"

#تعریف_کړه PRIiMAX "I64i"

#تعریف_کړه PRIo8 "o"
#تعریف_کړه PRIo16 "o"
#تعریف_کړه PRIo32 "o"
#تعریف_کړه PRIo64 "I64o"

#تعریف_کړه PRIoLEAST8 "o"
#تعریف_کړه PRIoLEAST16 "o"
#تعریف_کړه PRIoLEAST32 "o"
#تعریف_کړه PRIoLEAST64 "I64o"

#تعریف_کړه PRIoFAST8 "o"
#تعریف_کړه PRIoFAST16 "o"
#تعریف_کړه PRIoFAST32 "o"
#تعریف_کړه PRIoFAST64 "I64o"

#تعریف_کړه PRIoMAX "I64o"

/* fprintf macros for unsigned types */
#تعریف_کړه PRIu8 "u"
#تعریف_کړه PRIu16 "u"
#تعریف_کړه PRIu32 "u"
#تعریف_کړه PRIu64 "I64u"


#تعریف_کړه PRIuLEAST8 "u"
#تعریف_کړه PRIuLEAST16 "u"
#تعریف_کړه PRIuLEAST32 "u"
#تعریف_کړه PRIuLEAST64 "I64u"

#تعریف_کړه PRIuFAST8 "u"
#تعریف_کړه PRIuFAST16 "u"
#تعریف_کړه PRIuFAST32 "u"
#تعریف_کړه PRIuFAST64 "I64u"

#تعریف_کړه PRIuMAX "I64u"

#تعریف_کړه PRIx8 "x"
#تعریف_کړه PRIx16 "x"
#تعریف_کړه PRIx32 "x"
#تعریف_کړه PRIx64 "I64x"

#تعریف_کړه PRIxLEAST8 "x"
#تعریف_کړه PRIxLEAST16 "x"
#تعریف_کړه PRIxLEAST32 "x"
#تعریف_کړه PRIxLEAST64 "I64x"

#تعریف_کړه PRIxFAST8 "x"
#تعریف_کړه PRIxFAST16 "x"
#تعریف_کړه PRIxFAST32 "x"
#تعریف_کړه PRIxFAST64 "I64x"

#تعریف_کړه PRIxMAX "I64x"

#تعریف_کړه PRIX8 "X"
#تعریف_کړه PRIX16 "X"
#تعریف_کړه PRIX32 "X"
#تعریف_کړه PRIX64 "I64X"

#تعریف_کړه PRIXLEAST8 "X"
#تعریف_کړه PRIXLEAST16 "X"
#تعریف_کړه PRIXLEAST32 "X"
#تعریف_کړه PRIXLEAST64 "I64X"

#تعریف_کړه PRIXFAST8 "X"
#تعریف_کړه PRIXFAST16 "X"
#تعریف_کړه PRIXFAST32 "X"
#تعریف_کړه PRIXFAST64 "I64X"

#تعریف_کړه PRIXMAX "I64X"

/*
 *   fscanf macros for signed int types
 *   NOTE: if 32-bit int is used for int_fast8_t and int_fast16_t
 *   (see stdint.h, 7.18.1.3), FAST8 and FAST16 should have
 *   no length identifiers
 */

#تعریف_کړه SCNd16 "hd"
#تعریف_کړه SCNd32 "d"
#تعریف_کړه SCNd64 "I64d"

#تعریف_کړه SCNdLEAST16 "hd"
#تعریف_کړه SCNdLEAST32 "d"
#تعریف_کړه SCNdLEAST64 "I64d"

#تعریف_کړه SCNdFAST16 "hd"
#تعریف_کړه SCNdFAST32 "d"
#تعریف_کړه SCNdFAST64 "I64d"

#تعریف_کړه SCNdMAX "I64d"

#تعریف_کړه SCNi16 "hi"
#تعریف_کړه SCNi32 "i"
#تعریف_کړه SCNi64 "I64i"

#تعریف_کړه SCNiLEAST16 "hi"
#تعریف_کړه SCNiLEAST32 "i"
#تعریف_کړه SCNiLEAST64 "I64i"

#تعریف_کړه SCNiFAST16 "hi"
#تعریف_کړه SCNiFAST32 "i"
#تعریف_کړه SCNiFAST64 "I64i"

#تعریف_کړه SCNiMAX "I64i"

#تعریف_کړه SCNo16 "ho"
#تعریف_کړه SCNo32 "o"
#تعریف_کړه SCNo64 "I64o"

#تعریف_کړه SCNoLEAST16 "ho"
#تعریف_کړه SCNoLEAST32 "o"
#تعریف_کړه SCNoLEAST64 "I64o"

#تعریف_کړه SCNoFAST16 "ho"
#تعریف_کړه SCNoFAST32 "o"
#تعریف_کړه SCNoFAST64 "I64o"

#تعریف_کړه SCNoMAX "I64o"

#تعریف_کړه SCNx16 "hx"
#تعریف_کړه SCNx32 "x"
#تعریف_کړه SCNx64 "I64x"

#تعریف_کړه SCNxLEAST16 "hx"
#تعریف_کړه SCNxLEAST32 "x"
#تعریف_کړه SCNxLEAST64 "I64x"

#تعریف_کړه SCNxFAST16 "hx"
#تعریف_کړه SCNxFAST32 "x"
#تعریف_کړه SCNxFAST64 "I64x"

#تعریف_کړه SCNxMAX "I64x"

/* fscanf macros for unsigned int types */

#تعریف_کړه SCNu16 "hu"
#تعریف_کړه SCNu32 "u"
#تعریف_کړه SCNu64 "I64u"

#تعریف_کړه SCNuLEAST16 "hu"
#تعریف_کړه SCNuLEAST32 "u"
#تعریف_کړه SCNuLEAST64 "I64u"

#تعریف_کړه SCNuFAST16 "hu"
#تعریف_کړه SCNuFAST32 "u"
#تعریف_کړه SCNuFAST64 "I64u"

#تعریف_کړه SCNuMAX "I64u"

#که_تعریف_شوی _WIN64
#تعریف_کړه PRIdPTR "I64d"
#تعریف_کړه PRIiPTR "I64i"
#تعریف_کړه PRIoPTR "I64o"
#تعریف_کړه PRIuPTR "I64u"
#تعریف_کړه PRIxPTR "I64x"
#تعریف_کړه PRIXPTR "I64X"
#تعریف_کړه SCNdPTR "I64d"
#تعریف_کړه SCNiPTR "I64i"
#تعریف_کړه SCNoPTR "I64o"
#تعریف_کړه SCNxPTR "I64x"
#تعریف_کړه SCNuPTR "I64u"
#وإلا
#تعریف_کړه PRIdPTR "d"
#تعریف_کړه PRIiPTR "i"
#تعریف_کړه PRIoPTR "o"
#تعریف_کړه PRIuPTR "u"
#تعریف_کړه PRIxPTR "x"
#تعریف_کړه PRIXPTR "X"
#تعریف_کړه SCNdPTR "d"
#تعریف_کړه SCNiPTR "i"
#تعریف_کړه SCNoPTR "o"
#تعریف_کړه SCNxPTR "x"
#تعریف_کړه SCNuPTR "u"
#د_که_پای

#إذا defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
/*
 * no length modifier for char types prior to C9x
 * MS runtime  scanf appears to treat "hh" as "h" 
 */

/* signed char */
#تعریف_کړه SCNd8 "hhd"
#تعریف_کړه SCNdLEAST8 "hhd"
#تعریف_کړه SCNdFAST8 "hhd"

#تعریف_کړه SCNi8 "hhi"
#تعریف_کړه SCNiLEAST8 "hhi"
#تعریف_کړه SCNiFAST8 "hhi"

#تعریف_کړه SCNo8 "hho"
#تعریف_کړه SCNoLEAST8 "hho"
#تعریف_کړه SCNoFAST8 "hho"

#تعریف_کړه SCNx8 "hhx"
#تعریف_کړه SCNxLEAST8 "hhx"
#تعریف_کړه SCNxFAST8 "hhx"

/* unsigned char */
#تعریف_کړه SCNu8 "hhu"
#تعریف_کړه SCNuLEAST8 "hhu"
#تعریف_کړه SCNuFAST8 "hhu"
#د_که_پای /* __STDC_VERSION__ >= 199901 */

#د_که_پای	/* !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS) */

intmax_t __cdecl imaxabs (intmax_t j);
__CRT_INLINE intmax_t __cdecl imaxabs (intmax_t j)
	{أرجع	(j >= 0 ? j : -j);}
imaxdiv_t __cdecl imaxdiv (intmax_t numer, intmax_t denom);

/* 7.8.2 Conversion functions for greatest-width integer types */

intmax_t __cdecl strtoimax (ثابت حرف* __restrict__ nptr,
                            حرف** __restrict__ endptr, صحيح بنسټ);
uintmax_t __cdecl strtoumax (ثابت حرف* __restrict__ nptr,
			     حرف** __restrict__ endptr, صحيح بنسټ);

intmax_t __cdecl wcstoimax (ثابت wchar_t* __restrict__ nptr,
                            wchar_t** __restrict__ endptr, صحيح بنسټ);
uintmax_t __cdecl wcstoumax (ثابت wchar_t* __restrict__ nptr,
			     wchar_t** __restrict__ endptr, صحيح بنسټ);

#که_تعریف_شوی	__cplusplus
}
#د_که_پای

#د_که_پای /* ndef _INTTYPES_H */
