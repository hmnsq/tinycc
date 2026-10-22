/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the TinyCC package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#اگر_تعریف_نشده _INC_UCHAR
#تعریف_کن _INC_UCHAR

/*
 * The following defines are only valid when C11 (-std=c11) is used.
 *
 * ... a wide character constant prefixed by the letter u or U has type char16_t
 * or char32_t, respectively, unsigned integer types defined in the <uchar.h>
 * header.
 */

#إذا __STDC_VERSION__ >= 201112L
/**
 * __STDC_UTF_16__ The integer constant 1, intended to indicate that
 * values of type char16_t are UTF-16 encoded.
 */
#تعریف_کن __STDC_UTF_16__ 1
/**
 * __STDC_UTF_32__ The integer constant 1, intended to indicate that
 * values of type char32_t are UTF-32 encoded.
 */
#تعریف_کن __STDC_UTF_32__ 1

تعريفنوع بیعلامت کوتاه char16_t;
تعريفنوع بیعلامت صحيح char32_t;
#پایان_اگر /* __STDC_VERSION__ >= 201112L */
#پایان_اگر /* _INC_UCHAR */
