/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* 7.8 Format conversion of integer types <inttypes.h> */

#اگر_تعریف_نشده _INTTYPES_H_
#تعریف_کن _INTTYPES_H_

#ضمن <_mingw.h>
#ضمن <stdint.h>
#تعریف_کن __need_wchar_t
#ضمن <stddef.h>

#اگر_تعریف_شده	__cplusplus
خارجي	"C"	{
#پایان_اگر

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
#تعریف_کن PRId8 "d"
#تعریف_کن PRId16 "d"
#تعریف_کن PRId32 "d"
#تعریف_کن PRId64 "I64d"

#تعریف_کن PRIdLEAST8 "d"
#تعریف_کن PRIdLEAST16 "d"
#تعریف_کن PRIdLEAST32 "d"
#تعریف_کن PRIdLEAST64 "I64d"

#تعریف_کن PRIdFAST8 "d"
#تعریف_کن PRIdFAST16 "d"
#تعریف_کن PRIdFAST32 "d"
#تعریف_کن PRIdFAST64 "I64d"

#تعریف_کن PRIdMAX "I64d"

#تعریف_کن PRIi8 "i"
#تعریف_کن PRIi16 "i"
#تعریف_کن PRIi32 "i"
#تعریف_کن PRIi64 "I64i"

#تعریف_کن PRIiLEAST8 "i"
#تعریف_کن PRIiLEAST16 "i"
#تعریف_کن PRIiLEAST32 "i"
#تعریف_کن PRIiLEAST64 "I64i"

#تعریف_کن PRIiFAST8 "i"
#تعریف_کن PRIiFAST16 "i"
#تعریف_کن PRIiFAST32 "i"
#تعریف_کن PRIiFAST64 "I64i"

#تعریف_کن PRIiMAX "I64i"

#تعریف_کن PRIo8 "o"
#تعریف_کن PRIo16 "o"
#تعریف_کن PRIo32 "o"
#تعریف_کن PRIo64 "I64o"

#تعریف_کن PRIoLEAST8 "o"
#تعریف_کن PRIoLEAST16 "o"
#تعریف_کن PRIoLEAST32 "o"
#تعریف_کن PRIoLEAST64 "I64o"

#تعریف_کن PRIoFAST8 "o"
#تعریف_کن PRIoFAST16 "o"
#تعریف_کن PRIoFAST32 "o"
#تعریف_کن PRIoFAST64 "I64o"

#تعریف_کن PRIoMAX "I64o"

/* fprintf macros for unsigned types */
#تعریف_کن PRIu8 "u"
#تعریف_کن PRIu16 "u"
#تعریف_کن PRIu32 "u"
#تعریف_کن PRIu64 "I64u"


#تعریف_کن PRIuLEAST8 "u"
#تعریف_کن PRIuLEAST16 "u"
#تعریف_کن PRIuLEAST32 "u"
#تعریف_کن PRIuLEAST64 "I64u"

#تعریف_کن PRIuFAST8 "u"
#تعریف_کن PRIuFAST16 "u"
#تعریف_کن PRIuFAST32 "u"
#تعریف_کن PRIuFAST64 "I64u"

#تعریف_کن PRIuMAX "I64u"

#تعریف_کن PRIx8 "x"
#تعریف_کن PRIx16 "x"
#تعریف_کن PRIx32 "x"
#تعریف_کن PRIx64 "I64x"

#تعریف_کن PRIxLEAST8 "x"
#تعریف_کن PRIxLEAST16 "x"
#تعریف_کن PRIxLEAST32 "x"
#تعریف_کن PRIxLEAST64 "I64x"

#تعریف_کن PRIxFAST8 "x"
#تعریف_کن PRIxFAST16 "x"
#تعریف_کن PRIxFAST32 "x"
#تعریف_کن PRIxFAST64 "I64x"

#تعریف_کن PRIxMAX "I64x"

#تعریف_کن PRIX8 "X"
#تعریف_کن PRIX16 "X"
#تعریف_کن PRIX32 "X"
#تعریف_کن PRIX64 "I64X"

#تعریف_کن PRIXLEAST8 "X"
#تعریف_کن PRIXLEAST16 "X"
#تعریف_کن PRIXLEAST32 "X"
#تعریف_کن PRIXLEAST64 "I64X"

#تعریف_کن PRIXFAST8 "X"
#تعریف_کن PRIXFAST16 "X"
#تعریف_کن PRIXFAST32 "X"
#تعریف_کن PRIXFAST64 "I64X"

#تعریف_کن PRIXMAX "I64X"

/*
 *   fscanf macros for signed int types
 *   NOTE: if 32-bit int is used for int_fast8_t and int_fast16_t
 *   (see stdint.h, 7.18.1.3), FAST8 and FAST16 should have
 *   no length identifiers
 */

#تعریف_کن SCNd16 "hd"
#تعریف_کن SCNd32 "d"
#تعریف_کن SCNd64 "I64d"

#تعریف_کن SCNdLEAST16 "hd"
#تعریف_کن SCNdLEAST32 "d"
#تعریف_کن SCNdLEAST64 "I64d"

#تعریف_کن SCNdFAST16 "hd"
#تعریف_کن SCNdFAST32 "d"
#تعریف_کن SCNdFAST64 "I64d"

#تعریف_کن SCNdMAX "I64d"

#تعریف_کن SCNi16 "hi"
#تعریف_کن SCNi32 "i"
#تعریف_کن SCNi64 "I64i"

#تعریف_کن SCNiLEAST16 "hi"
#تعریف_کن SCNiLEAST32 "i"
#تعریف_کن SCNiLEAST64 "I64i"

#تعریف_کن SCNiFAST16 "hi"
#تعریف_کن SCNiFAST32 "i"
#تعریف_کن SCNiFAST64 "I64i"

#تعریف_کن SCNiMAX "I64i"

#تعریف_کن SCNo16 "ho"
#تعریف_کن SCNo32 "o"
#تعریف_کن SCNo64 "I64o"

#تعریف_کن SCNoLEAST16 "ho"
#تعریف_کن SCNoLEAST32 "o"
#تعریف_کن SCNoLEAST64 "I64o"

#تعریف_کن SCNoFAST16 "ho"
#تعریف_کن SCNoFAST32 "o"
#تعریف_کن SCNoFAST64 "I64o"

#تعریف_کن SCNoMAX "I64o"

#تعریف_کن SCNx16 "hx"
#تعریف_کن SCNx32 "x"
#تعریف_کن SCNx64 "I64x"

#تعریف_کن SCNxLEAST16 "hx"
#تعریف_کن SCNxLEAST32 "x"
#تعریف_کن SCNxLEAST64 "I64x"

#تعریف_کن SCNxFAST16 "hx"
#تعریف_کن SCNxFAST32 "x"
#تعریف_کن SCNxFAST64 "I64x"

#تعریف_کن SCNxMAX "I64x"

/* fscanf macros for unsigned int types */

#تعریف_کن SCNu16 "hu"
#تعریف_کن SCNu32 "u"
#تعریف_کن SCNu64 "I64u"

#تعریف_کن SCNuLEAST16 "hu"
#تعریف_کن SCNuLEAST32 "u"
#تعریف_کن SCNuLEAST64 "I64u"

#تعریف_کن SCNuFAST16 "hu"
#تعریف_کن SCNuFAST32 "u"
#تعریف_کن SCNuFAST64 "I64u"

#تعریف_کن SCNuMAX "I64u"

#اگر_تعریف_شده _WIN64
#تعریف_کن PRIdPTR "I64d"
#تعریف_کن PRIiPTR "I64i"
#تعریف_کن PRIoPTR "I64o"
#تعریف_کن PRIuPTR "I64u"
#تعریف_کن PRIxPTR "I64x"
#تعریف_کن PRIXPTR "I64X"
#تعریف_کن SCNdPTR "I64d"
#تعریف_کن SCNiPTR "I64i"
#تعریف_کن SCNoPTR "I64o"
#تعریف_کن SCNxPTR "I64x"
#تعریف_کن SCNuPTR "I64u"
#وإلا
#تعریف_کن PRIdPTR "d"
#تعریف_کن PRIiPTR "i"
#تعریف_کن PRIoPTR "o"
#تعریف_کن PRIuPTR "u"
#تعریف_کن PRIxPTR "x"
#تعریف_کن PRIXPTR "X"
#تعریف_کن SCNdPTR "d"
#تعریف_کن SCNiPTR "i"
#تعریف_کن SCNoPTR "o"
#تعریف_کن SCNxPTR "x"
#تعریف_کن SCNuPTR "u"
#پایان_اگر

#إذا defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
/*
 * no length modifier for char types prior to C9x
 * MS runtime  scanf appears to treat "hh" as "h" 
 */

/* signed char */
#تعریف_کن SCNd8 "hhd"
#تعریف_کن SCNdLEAST8 "hhd"
#تعریف_کن SCNdFAST8 "hhd"

#تعریف_کن SCNi8 "hhi"
#تعریف_کن SCNiLEAST8 "hhi"
#تعریف_کن SCNiFAST8 "hhi"

#تعریف_کن SCNo8 "hho"
#تعریف_کن SCNoLEAST8 "hho"
#تعریف_کن SCNoFAST8 "hho"

#تعریف_کن SCNx8 "hhx"
#تعریف_کن SCNxLEAST8 "hhx"
#تعریف_کن SCNxFAST8 "hhx"

/* unsigned char */
#تعریف_کن SCNu8 "hhu"
#تعریف_کن SCNuLEAST8 "hhu"
#تعریف_کن SCNuFAST8 "hhu"
#پایان_اگر /* __STDC_VERSION__ >= 199901 */

#پایان_اگر	/* !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS) */

intmax_t __cdecl imaxabs (intmax_t j);
__CRT_INLINE intmax_t __cdecl imaxabs (intmax_t j)
	{أرجع	(j >= 0 ? j : -j);}
imaxdiv_t __cdecl imaxdiv (intmax_t numer, intmax_t denom);

/* 7.8.2 Conversion functions for greatest-width integer types */

intmax_t __cdecl strtoimax (ثابت حرف* __restrict__ nptr,
                            حرف** __restrict__ endptr, صحيح پایه);
uintmax_t __cdecl strtoumax (ثابت حرف* __restrict__ nptr,
			     حرف** __restrict__ endptr, صحيح پایه);

intmax_t __cdecl wcstoimax (ثابت wchar_t* __restrict__ nptr,
                            wchar_t** __restrict__ endptr, صحيح پایه);
uintmax_t __cdecl wcstoumax (ثابت wchar_t* __restrict__ nptr,
			     wchar_t** __restrict__ endptr, صحيح پایه);

#اگر_تعریف_شده	__cplusplus
}
#پایان_اگر

#پایان_اگر /* ndef _INTTYPES_H */
