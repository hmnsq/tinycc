/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* 7.8 Format conversion of integer types <inttypes.h> */

#अगर_अघोषित _INTTYPES_H_
#घोषणा _INTTYPES_H_

#समावेश <_mingw.h>
#समावेश <stdint.h>
#घोषणा __need_wchar_t
#समावेश <stddef.h>

#अगर_घोषित	__cplusplus
बाह्य	"C"	{
#पूर्ण_अगर

प्रकार काष्ठा {
	intmax_t quot;
	intmax_t rem;
	} imaxdiv_t;

#अगर !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS)

/* 7.8.1 Macros for format specifiers
 * 
 * MS runtime does not yet understand C9x standard "ll"
 * length specifier. It appears to treat "ll" as "l".
 * The non-standard I64 length specifier causes warning in GCC,
 * but understood by MS runtime functions.
 */

/* fprintf macros for signed types */
#घोषणा PRId8 "d"
#घोषणा PRId16 "d"
#घोषणा PRId32 "d"
#घोषणा PRId64 "I64d"

#घोषणा PRIdLEAST8 "d"
#घोषणा PRIdLEAST16 "d"
#घोषणा PRIdLEAST32 "d"
#घोषणा PRIdLEAST64 "I64d"

#घोषणा PRIdFAST8 "d"
#घोषणा PRIdFAST16 "d"
#घोषणा PRIdFAST32 "d"
#घोषणा PRIdFAST64 "I64d"

#घोषणा PRIdMAX "I64d"

#घोषणा PRIi8 "i"
#घोषणा PRIi16 "i"
#घोषणा PRIi32 "i"
#घोषणा PRIi64 "I64i"

#घोषणा PRIiLEAST8 "i"
#घोषणा PRIiLEAST16 "i"
#घोषणा PRIiLEAST32 "i"
#घोषणा PRIiLEAST64 "I64i"

#घोषणा PRIiFAST8 "i"
#घोषणा PRIiFAST16 "i"
#घोषणा PRIiFAST32 "i"
#घोषणा PRIiFAST64 "I64i"

#घोषणा PRIiMAX "I64i"

#घोषणा PRIo8 "o"
#घोषणा PRIo16 "o"
#घोषणा PRIo32 "o"
#घोषणा PRIo64 "I64o"

#घोषणा PRIoLEAST8 "o"
#घोषणा PRIoLEAST16 "o"
#घोषणा PRIoLEAST32 "o"
#घोषणा PRIoLEAST64 "I64o"

#घोषणा PRIoFAST8 "o"
#घोषणा PRIoFAST16 "o"
#घोषणा PRIoFAST32 "o"
#घोषणा PRIoFAST64 "I64o"

#घोषणा PRIoMAX "I64o"

/* fprintf macros for unsigned types */
#घोषणा PRIu8 "u"
#घोषणा PRIu16 "u"
#घोषणा PRIu32 "u"
#घोषणा PRIu64 "I64u"


#घोषणा PRIuLEAST8 "u"
#घोषणा PRIuLEAST16 "u"
#घोषणा PRIuLEAST32 "u"
#घोषणा PRIuLEAST64 "I64u"

#घोषणा PRIuFAST8 "u"
#घोषणा PRIuFAST16 "u"
#घोषणा PRIuFAST32 "u"
#घोषणा PRIuFAST64 "I64u"

#घोषणा PRIuMAX "I64u"

#घोषणा PRIx8 "x"
#घोषणा PRIx16 "x"
#घोषणा PRIx32 "x"
#घोषणा PRIx64 "I64x"

#घोषणा PRIxLEAST8 "x"
#घोषणा PRIxLEAST16 "x"
#घोषणा PRIxLEAST32 "x"
#घोषणा PRIxLEAST64 "I64x"

#घोषणा PRIxFAST8 "x"
#घोषणा PRIxFAST16 "x"
#घोषणा PRIxFAST32 "x"
#घोषणा PRIxFAST64 "I64x"

#घोषणा PRIxMAX "I64x"

#घोषणा PRIX8 "X"
#घोषणा PRIX16 "X"
#घोषणा PRIX32 "X"
#घोषणा PRIX64 "I64X"

#घोषणा PRIXLEAST8 "X"
#घोषणा PRIXLEAST16 "X"
#घोषणा PRIXLEAST32 "X"
#घोषणा PRIXLEAST64 "I64X"

#घोषणा PRIXFAST8 "X"
#घोषणा PRIXFAST16 "X"
#घोषणा PRIXFAST32 "X"
#घोषणा PRIXFAST64 "I64X"

#घोषणा PRIXMAX "I64X"

/*
 *   fscanf macros for signed int types
 *   NOTE: if 32-bit int is used for int_fast8_t and int_fast16_t
 *   (see stdint.h, 7.18.1.3), FAST8 and FAST16 should have
 *   no length identifiers
 */

#घोषणा SCNd16 "hd"
#घोषणा SCNd32 "d"
#घोषणा SCNd64 "I64d"

#घोषणा SCNdLEAST16 "hd"
#घोषणा SCNdLEAST32 "d"
#घोषणा SCNdLEAST64 "I64d"

#घोषणा SCNdFAST16 "hd"
#घोषणा SCNdFAST32 "d"
#घोषणा SCNdFAST64 "I64d"

#घोषणा SCNdMAX "I64d"

#घोषणा SCNi16 "hi"
#घोषणा SCNi32 "i"
#घोषणा SCNi64 "I64i"

#घोषणा SCNiLEAST16 "hi"
#घोषणा SCNiLEAST32 "i"
#घोषणा SCNiLEAST64 "I64i"

#घोषणा SCNiFAST16 "hi"
#घोषणा SCNiFAST32 "i"
#घोषणा SCNiFAST64 "I64i"

#घोषणा SCNiMAX "I64i"

#घोषणा SCNo16 "ho"
#घोषणा SCNo32 "o"
#घोषणा SCNo64 "I64o"

#घोषणा SCNoLEAST16 "ho"
#घोषणा SCNoLEAST32 "o"
#घोषणा SCNoLEAST64 "I64o"

#घोषणा SCNoFAST16 "ho"
#घोषणा SCNoFAST32 "o"
#घोषणा SCNoFAST64 "I64o"

#घोषणा SCNoMAX "I64o"

#घोषणा SCNx16 "hx"
#घोषणा SCNx32 "x"
#घोषणा SCNx64 "I64x"

#घोषणा SCNxLEAST16 "hx"
#घोषणा SCNxLEAST32 "x"
#घोषणा SCNxLEAST64 "I64x"

#घोषणा SCNxFAST16 "hx"
#घोषणा SCNxFAST32 "x"
#घोषणा SCNxFAST64 "I64x"

#घोषणा SCNxMAX "I64x"

/* fscanf macros for unsigned int types */

#घोषणा SCNu16 "hu"
#घोषणा SCNu32 "u"
#घोषणा SCNu64 "I64u"

#घोषणा SCNuLEAST16 "hu"
#घोषणा SCNuLEAST32 "u"
#घोषणा SCNuLEAST64 "I64u"

#घोषणा SCNuFAST16 "hu"
#घोषणा SCNuFAST32 "u"
#घोषणा SCNuFAST64 "I64u"

#घोषणा SCNuMAX "I64u"

#अगर_घोषित _WIN64
#घोषणा PRIdPTR "I64d"
#घोषणा PRIiPTR "I64i"
#घोषणा PRIoPTR "I64o"
#घोषणा PRIuPTR "I64u"
#घोषणा PRIxPTR "I64x"
#घोषणा PRIXPTR "I64X"
#घोषणा SCNdPTR "I64d"
#घोषणा SCNiPTR "I64i"
#घोषणा SCNoPTR "I64o"
#घोषणा SCNxPTR "I64x"
#घोषणा SCNuPTR "I64u"
#अन्यथा
#घोषणा PRIdPTR "d"
#घोषणा PRIiPTR "i"
#घोषणा PRIoPTR "o"
#घोषणा PRIuPTR "u"
#घोषणा PRIxPTR "x"
#घोषणा PRIXPTR "X"
#घोषणा SCNdPTR "d"
#घोषणा SCNiPTR "i"
#घोषणा SCNoPTR "o"
#घोषणा SCNxPTR "x"
#घोषणा SCNuPTR "u"
#पूर्ण_अगर

#अगर defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
/*
 * no length modifier for char types prior to C9x
 * MS runtime  scanf appears to treat "hh" as "h" 
 */

/* signed char */
#घोषणा SCNd8 "hhd"
#घोषणा SCNdLEAST8 "hhd"
#घोषणा SCNdFAST8 "hhd"

#घोषणा SCNi8 "hhi"
#घोषणा SCNiLEAST8 "hhi"
#घोषणा SCNiFAST8 "hhi"

#घोषणा SCNo8 "hho"
#घोषणा SCNoLEAST8 "hho"
#घोषणा SCNoFAST8 "hho"

#घोषणा SCNx8 "hhx"
#घोषणा SCNxLEAST8 "hhx"
#घोषणा SCNxFAST8 "hhx"

/* unsigned char */
#घोषणा SCNu8 "hhu"
#घोषणा SCNuLEAST8 "hhu"
#घोषणा SCNuFAST8 "hhu"
#पूर्ण_अगर /* __STDC_VERSION__ >= 199901 */

#पूर्ण_अगर	/* !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS) */

intmax_t __cdecl imaxabs (intmax_t j);
__CRT_INLINE intmax_t __cdecl imaxabs (intmax_t j)
	{वापस	(j >= 0 ? j : -j);}
imaxdiv_t __cdecl imaxdiv (intmax_t numer, intmax_t denom);

/* 7.8.2 Conversion functions for greatest-width integer types */

intmax_t __cdecl strtoimax (स्थिर अक्षर* __restrict__ nptr,
                            अक्षर** __restrict__ endptr, पूर्णांक base);
uintmax_t __cdecl strtoumax (स्थिर अक्षर* __restrict__ nptr,
			     अक्षर** __restrict__ endptr, पूर्णांक base);

intmax_t __cdecl wcstoimax (स्थिर ब_अक्षर_प्रकार* __restrict__ nptr,
                            ब_अक्षर_प्रकार** __restrict__ endptr, पूर्णांक base);
uintmax_t __cdecl wcstoumax (स्थिर ब_अक्षर_प्रकार* __restrict__ nptr,
			     ब_अक्षर_प्रकार** __restrict__ endptr, पूर्णांक base);

#अगर_घोषित	__cplusplus
}
#पूर्ण_अगर

#पूर्ण_अगर /* ndef _INTTYPES_H */
