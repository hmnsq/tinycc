/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the TinyCC package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_UCHAR
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_UCHAR

/*
 * The following defines are only valid when C11 (-std=c11) is used.
 *
 * ... a wide character constant prefixed by the letter u or U has type char16_t
 * or char32_t, respectively, unsigned integer types defined in the <uchar.h>
 * header.
 */

#ਜੇ __STDC_VERSION__ >= 201112L
/**
 * __STDC_UTF_16__ The integer constant 1, intended to indicate that
 * values of type char16_t are UTF-16 encoded.
 */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __STDC_UTF_16__ 1
/**
 * __STDC_UTF_32__ The integer constant 1, intended to indicate that
 * values of type char32_t are UTF-32 encoded.
 */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __STDC_UTF_32__ 1

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ char16_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ char32_t;
#ਜੇ_ਅੰਤ /* __STDC_VERSION__ >= 201112L */
#ਜੇ_ਅੰਤ /* _INC_UCHAR */
