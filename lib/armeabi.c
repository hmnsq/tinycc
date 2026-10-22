/* TCC ARM runtime EABI
   Copyright (C) 2013 Thomas Preud'homme

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.*/

#ifdef __TINYC__
#define INT_MIN (-2147483647 - 1)
#define INT_MAX 2147483647
#define UINT_MAX 0xffffffff
#define LONG_MIN (-2147483647L - 1)
#define LONG_MAX 2147483647L
#define ULONG_MAX 0xffffffffUL
#define LLONG_MAX 9223372036854775807LL
#define LLONG_MIN (-9223372036854775807LL - 1)
#define ULLONG_MAX 0xffffffffffffffffULL
#ಅನ್ಯಥಾ
#ಅನ್ತರ್ಭಾವ <limits.h>
#endif

/* We rely on the little endianness and EABI calling convention for this to
   work */

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ double_unsigned_struct {
    unsigned ಕೆಳಗಿನ;
    unsigned ಮೇಲಿನ;
} double_unsigned_struct;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ unsigned_int_struct {
    unsigned ಕೆಳಗಿನ;
    ಪೂರ್ಣಾಙ್ಕ ಮೇಲಿನ;
} unsigned_int_struct;

#define REGS_RETURN(name, type) \
    ಸ್ಥಿರ ಶೂನ್ಯ name ## _return(type ret) {}


/* Float helper functions */

#define FLOAT_EXP_BITS 8
#define FLOAT_FRAC_BITS 23

#define DOUBLE_EXP_BITS 11
#define DOUBLE_FRAC_BITS 52

#define ONE_EXP(type) ((1 << (type ## _EXP_BITS - 1)) - 1)

REGS_RETURN(unsigned_int_struct, unsigned_int_struct)
REGS_RETURN(double_unsigned_struct, double_unsigned_struct)

/* float -> integer: (sign) 1.fraction x 2^(exponent - exp_for_one) */


/* float to [unsigned] long long conversion */
#define DEFINE__AEABI_F2XLZ(name, with_sign)                                 \
ಶೂನ್ಯ __aeabi_ ## name(unsigned val)                                          \
{                                                                            \
    ಪೂರ್ಣಾಙ್ಕ exp, ಮೇಲಿನ_shift, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    /* compute sign */                                                       \
    sign = val >> 31;                                                        \
                                                                             \
    /* compute real exponent */                                              \
    exp = val >> FLOAT_FRAC_BITS;                                            \
    exp &= (1 << FLOAT_EXP_BITS) - 1;                                        \
    exp -= ONE_EXP(FLOAT);                                                   \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    ಯದಿ (with_sign) {                                                         \
        ಯದಿ (exp > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            ಪ್ರತ್ಯಾಗಮ;                                                          \
    } ಅನ್ಯಥಾ {                                                                 \
        ಯದಿ ((sign && exp >= 0) || exp > 63) /* if val < 0 || val too big */  \
            ಪ್ರತ್ಯಾಗಮ;                                                          \
    }                                                                        \
                                                                             \
    val &= (1 << FLOAT_FRAC_BITS) - 1;                                       \
    ಯದಿ (exp >= 32) {                                                         \
        ret.ಮೇಲಿನ = 1 << (exp - 32);                                          \
        ಯದಿ (exp - 32 >= FLOAT_FRAC_BITS) {                                   \
            ret.ಮೇಲಿನ |= val << (exp - 32 - FLOAT_FRAC_BITS);                 \
            ret.ಕೆಳಗಿನ = 0;                                                     \
        } ಅನ್ಯಥಾ {                                                             \
            ಮೇಲಿನ_shift = FLOAT_FRAC_BITS - (exp - 32);                       \
            ret.ಮೇಲಿನ |= val >> ಮೇಲಿನ_shift;                                   \
            ret.ಕೆಳಗಿನ = val << (32 - ಮೇಲಿನ_shift);                              \
        }                                                                    \
    } ಅನ್ಯಥಾ {                                                                 \
        ret.ಮೇಲಿನ = 0;                                                        \
        ret.ಕೆಳಗಿನ = 1 << exp;                                                  \
        ಯದಿ (exp > FLOAT_FRAC_BITS)                                           \
            ret.ಕೆಳಗಿನ |= val << (exp - FLOAT_FRAC_BITS);                       \
        ಅನ್ಯಥಾ                                                                 \
            ret.ಕೆಳಗಿನ |= val >> (FLOAT_FRAC_BITS - exp);                       \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    ಯದಿ (with_sign && sign) {                                                 \
        ret.ಕೆಳಗಿನ = ~ret.ಕೆಳಗಿನ;                                                  \
        ret.ಮೇಲಿನ = ~ret.ಮೇಲಿನ;                                                \
        ಯದಿ (ret.ಕೆಳಗಿನ == UINT_MAX) {                                           \
            ret.ಕೆಳಗಿನ = 0;                                                     \
            ret.ಮೇಲಿನ++;                                                      \
        } ಅನ್ಯಥಾ                                                               \
            ret.ಕೆಳಗಿನ++;                                                       \
    }                                                                        \
                                                                             \
    double_unsigned_struct_return(ret);                                      \
}

/* float to unsigned long long conversion */
DEFINE__AEABI_F2XLZ(f2ulz, 0)

/* float to long long conversion */
DEFINE__AEABI_F2XLZ(f2lz, 1)

/* double to [unsigned] long long conversion */
#define DEFINE__AEABI_D2XLZ(name, with_sign)                                 \
ಶೂನ್ಯ __aeabi_ ## name(double_unsigned_struct val)                            \
{                                                                            \
    ಪೂರ್ಣಾಙ್ಕ exp, ಮೇಲಿನ_shift, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    ಯದಿ ((val.ಮೇಲಿನ & ~0x80000000) == 0 && val.ಕೆಳಗಿನ == 0) {                     \
        ret.ಕೆಳಗಿನ = ret.ಮೇಲಿನ = 0;                                              \
        ಗಚ್ಛ _ret_;                                                          \
    }                                                                        \
                                                                             \
    /* compute sign */                                                       \
    sign = val.ಮೇಲಿನ >> 31;                                                   \
                                                                             \
    /* compute real exponent */                                              \
    exp = (val.ಮೇಲಿನ >> (DOUBLE_FRAC_BITS - 32));                             \
    exp &= (1 << DOUBLE_EXP_BITS) - 1;                                       \
    exp -= ONE_EXP(DOUBLE);                                                  \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    ಯದಿ (with_sign) {                                                         \
        ಯದಿ (exp > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            ಪ್ರತ್ಯಾಗಮ;                                                          \
    } ಅನ್ಯಥಾ {                                                                 \
        ಯದಿ ((sign && exp >= 0) || exp > 63) /* if val < 0 || val too big */  \
            ಪ್ರತ್ಯಾಗಮ;                                                          \
    }                                                                        \
                                                                             \
    val.ಮೇಲಿನ &= (1 << (DOUBLE_FRAC_BITS - 32)) - 1;                          \
    ಯದಿ (exp >= 32) {                                                         \
        ret.ಮೇಲಿನ = 1 << (exp - 32);                                          \
        ಯದಿ (exp >= DOUBLE_FRAC_BITS) {                                       \
            ಮೇಲಿನ_shift = exp - DOUBLE_FRAC_BITS;                             \
            ret.ಮೇಲಿನ |= val.ಮೇಲಿನ << ಮೇಲಿನ_shift;                              \
            ret.ಮೇಲಿನ |= val.ಕೆಳಗಿನ >> (32 - ಮೇಲಿನ_shift);                        \
            ret.ಕೆಳಗಿನ = val.ಕೆಳಗಿನ << ಮೇಲಿನ_shift;                                 \
        } ಅನ್ಯಥಾ {                                                             \
            ಮೇಲಿನ_shift = DOUBLE_FRAC_BITS - exp;                             \
            ret.ಮೇಲಿನ |= val.ಮೇಲಿನ >> ಮೇಲಿನ_shift;                              \
            ret.ಕೆಳಗಿನ = val.ಮೇಲಿನ << (32 - ಮೇಲಿನ_shift);                         \
            ret.ಕೆಳಗಿನ |= val.ಕೆಳಗಿನ >> ಮೇಲಿನ_shift;                                \
        }                                                                    \
    } ಅನ್ಯಥಾ {                                                                 \
        ret.ಮೇಲಿನ = 0;                                                        \
        ret.ಕೆಳಗಿನ = 1 << exp;                                                  \
        ಯದಿ (exp > DOUBLE_FRAC_BITS - 32) {                                   \
            ಮೇಲಿನ_shift = exp - (DOUBLE_FRAC_BITS - 32);                      \
            ret.ಕೆಳಗಿನ |= val.ಮೇಲಿನ << ಮೇಲಿನ_shift;                               \
            ret.ಕೆಳಗಿನ |= val.ಕೆಳಗಿನ >> (32 - ಮೇಲಿನ_shift);                         \
        } ಅನ್ಯಥಾ                                                               \
            ret.ಕೆಳಗಿನ |= val.ಮೇಲಿನ >> (DOUBLE_FRAC_BITS - 32 - exp);            \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    ಯದಿ (with_sign && sign) {                                                 \
        ret.ಕೆಳಗಿನ = ~ret.ಕೆಳಗಿನ;                                                  \
        ret.ಮೇಲಿನ = ~ret.ಮೇಲಿನ;                                                \
        ಯದಿ (ret.ಕೆಳಗಿನ == UINT_MAX) {                                           \
            ret.ಕೆಳಗಿನ = 0;                                                     \
            ret.ಮೇಲಿನ++;                                                      \
        } ಅನ್ಯಥಾ                                                               \
            ret.ಕೆಳಗಿನ++;                                                       \
    }                                                                        \
                                                                             \
_ret_:                                                                       \
    double_unsigned_struct_return(ret);                                      \
}

/* double to unsigned long long conversion */
DEFINE__AEABI_D2XLZ(d2ulz, 0)

/* double to long long conversion */
DEFINE__AEABI_D2XLZ(d2lz, 1)

/* long long to float conversion */
#define DEFINE__AEABI_XL2F(name, with_sign)                             \
unsigned __aeabi_ ## name(unsigned long long v)                         \
{                                                                       \
    ಪೂರ್ಣಾಙ್ಕ s /* shift */, flb /* first lost bit */, sign = 0;              \
    unsigned p = 0 /* power */, ret;                                    \
    double_unsigned_struct val;                                         \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    ಯದಿ (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.ಕೆಳಗಿನ = v;                                                        \
    val.ಮೇಲಿನ = v >> 32;                                                 \
    /* fill fraction bits */                                            \
    ಪ್ರತಿ (s = 31, p = 1 << 31; p && !(val.ಮೇಲಿನ & p); s--, p >>= 1);      \
    ಯದಿ (p) {                                                            \
        ret = val.ಮೇಲಿನ & (p - 1);                                       \
        ಯದಿ (s < FLOAT_FRAC_BITS) {                                      \
            ret <<= FLOAT_FRAC_BITS - s;                                \
            ret |= val.ಕೆಳಗಿನ >> (32 - (FLOAT_FRAC_BITS - s));             \
            flb = (val.ಕೆಳಗಿನ >> (32 - (FLOAT_FRAC_BITS - s - 1))) & 1;    \
        } ಅನ್ಯಥಾ {                                                        \
            flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;               \
            ret >>= s - FLOAT_FRAC_BITS;                                \
        }                                                               \
        s += 32;                                                        \
    } ಅನ್ಯಥಾ {                                                            \
        ಪ್ರತಿ (s = 31, p = 1 << 31; p && !(val.ಕೆಳಗಿನ & p); s--, p >>= 1);   \
        ಯದಿ (p) {                                                        \
            ret = val.ಕೆಳಗಿನ & (p - 1);                                    \
            ಯದಿ (s <= FLOAT_FRAC_BITS) {                                 \
                ret <<= FLOAT_FRAC_BITS - s;                            \
                flb = 0;                                                \
	    } ಅನ್ಯಥಾ {                                                    \
                flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;           \
                ret >>= s - FLOAT_FRAC_BITS;                            \
	    }                                                           \
        } ಅನ್ಯಥಾ                                                          \
            ಪ್ರತ್ಯಾಗಮ 0;                                                   \
    }                                                                   \
    ಯದಿ (flb)                                                            \
        ret++;                                                          \
                                                                        \
    /* fill exponent bits */                                            \
    ret |= (s + ONE_EXP(FLOAT)) << FLOAT_FRAC_BITS;                     \
                                                                        \
    /* fill sign bit */                                                 \
    ret |= sign << 31;                                                  \
                                                                        \
    ಪ್ರತ್ಯಾಗಮ ret;                                                         \
}

/* unsigned long long to float conversion */
DEFINE__AEABI_XL2F(ul2f, 0)

/* long long to float conversion */
DEFINE__AEABI_XL2F(l2f, 1)

/* long long to double conversion */
#define __AEABI_XL2D(name, with_sign)                                   \
ಶೂನ್ಯ __aeabi_ ## name(unsigned long long v)                             \
{                                                                       \
    ಪೂರ್ಣಾಙ್ಕ s /* shift */, ಮೇಲಿನ_shift, sign = 0;                            \
    unsigned tmp, p = 0;                                                \
    double_unsigned_struct val, ret;                                    \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    ಯದಿ (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.ಕೆಳಗಿನ = v;                                                        \
    val.ಮೇಲಿನ = v >> 32;                                                 \
                                                                        \
    /* fill fraction bits */                                            \
    ಪ್ರತಿ (s = 31, p = 1 << 31; p && !(val.ಮೇಲಿನ & p); s--, p >>= 1);      \
    ಯದಿ (p) {                                                            \
        tmp = val.ಮೇಲಿನ & (p - 1);                                       \
        ಯದಿ (s < DOUBLE_FRAC_BITS - 32) {                                \
            ಮೇಲಿನ_shift = DOUBLE_FRAC_BITS - 32 - s;                     \
            ret.ಮೇಲಿನ = tmp << ಮೇಲಿನ_shift;                               \
            ret.ಮೇಲಿನ |= val.ಕೆಳಗಿನ >> (32 - ಮೇಲಿನ_shift);                   \
            ret.ಕೆಳಗಿನ = val.ಕೆಳಗಿನ << ಮೇಲಿನ_shift;                            \
        } ಅನ್ಯಥಾ {                                                        \
            ಮೇಲಿನ_shift = s - (DOUBLE_FRAC_BITS - 32);                   \
            ret.ಮೇಲಿನ = tmp >> ಮೇಲಿನ_shift;                               \
            ret.ಕೆಳಗಿನ = tmp << (32 - ಮೇಲಿನ_shift);                         \
            ret.ಕೆಳಗಿನ |= val.ಕೆಳಗಿನ >> ಮೇಲಿನ_shift;                           \
            ಯದಿ ((val.ಕೆಳಗಿನ >> (ಮೇಲಿನ_shift - 1)) & 1) {                    \
                ಯದಿ (ret.ಕೆಳಗಿನ == UINT_MAX) {                              \
                    ret.ಮೇಲಿನ++;                                         \
                    ret.ಕೆಳಗಿನ = 0;                                        \
		} ಅನ್ಯಥಾ                                                  \
                    ret.ಕೆಳಗಿನ++;                                          \
            }                                                           \
        }                                                               \
        s += 32;                                                        \
    } ಅನ್ಯಥಾ {                                                            \
        ಪ್ರತಿ (s = 31, p = 1 << 31; p && !(val.ಕೆಳಗಿನ & p); s--, p >>= 1);   \
        ಯದಿ (p) {                                                        \
            tmp = val.ಕೆಳಗಿನ & (p - 1);                                    \
            ಯದಿ (s <= DOUBLE_FRAC_BITS - 32) {                           \
                ಮೇಲಿನ_shift = DOUBLE_FRAC_BITS - 32 - s;                 \
                ret.ಮೇಲಿನ = tmp << ಮೇಲಿನ_shift;                           \
                ret.ಕೆಳಗಿನ = 0;                                            \
	    } ಅನ್ಯಥಾ {                                                    \
                ಮೇಲಿನ_shift = s - (DOUBLE_FRAC_BITS - 32);               \
                ret.ಮೇಲಿನ = tmp >> ಮೇಲಿನ_shift;                           \
                ret.ಕೆಳಗಿನ = tmp << (32 - ಮೇಲಿನ_shift);                     \
            }                                                           \
        } ಅನ್ಯಥಾ {                                                        \
            ret.ಮೇಲಿನ = ret.ಕೆಳಗಿನ = 0;                                     \
            ಗಚ್ಛ _ret_;                                                 \
        }                                                               \
    }                                                                   \
                                                                        \
    /* fill exponent bits */                                            \
    ret.ಮೇಲಿನ |= (s + ONE_EXP(DOUBLE)) << (DOUBLE_FRAC_BITS - 32);       \
                                                                        \
    /* fill sign bit */                                                 \
    ret.ಮೇಲಿನ |= sign << 31;                                             \
                                                                        \
_ret_:                                                                  \
    double_unsigned_struct_return(ret);                                 \
}

/* unsigned long long to double conversion */
__AEABI_XL2D(ul2d, 0)

/* long long to double conversion */
__AEABI_XL2D(l2d, 1)

#ಯದಿ 1
/* Long long helper functions */

/* TODO: add error in case of den == 0 (see §4.3.1 and §4.3.2) */

#define define_aeabi_xdivmod_signed_type(basetype, type) \
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ type {                                    \
    basetype quot;                                       \
    unsigned basetype rem;                               \
} type

#define define_aeabi_xdivmod_unsigned_type(basetype, type) \
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ type {                                      \
    basetype quot;                                         \
    basetype rem;                                          \
} type

#define AEABI_UXDIVMOD(name,type, rettype, typemacro)                     \
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ rettype aeabi_ ## name (type ಅಂಕೆ, type den)                 \
{                                                                         \
    rettype ret;                                                          \
    type quot = 0;                                                        \
                                                                          \
    /* Increase quotient while it is less than numerator */               \
    ಯಾವತ್ (ಅಂಕೆ >= den) {                                                  \
        type q = 1;                                                       \
                                                                          \
        /* Find closest power of two */                                   \
        ಯಾವತ್ ((q << 1) * den <= ಅಂಕೆ && q * den <= typemacro ## _MAX / 2) \
            q <<= 1;                                                      \
                                                                          \
        /* Compute difference between current quotient and numerator */   \
        ಅಂಕೆ -= q * den;                                                   \
        quot += q;                                                        \
    }                                                                     \
    ret.quot = quot;                                                      \
    ret.rem = ಅಂಕೆ;                                                        \
    ಪ್ರತ್ಯಾಗಮ ret;                                                           \
}

#define __AEABI_XDIVMOD(name, type, uiname, rettype, urettype, typemacro)     \
ಶೂನ್ಯ __aeabi_ ## name(type numerator, type denominator)                       \
{                                                                             \
    unsigned type ಅಂಕೆ, den;                                                   \
    urettype uxdiv_ret;                                                       \
    rettype ret;                                                              \
                                                                              \
    ಯದಿ (numerator >= 0)                                                       \
      ಅಂಕೆ = numerator;                                                        \
    ಅನ್ಯಥಾ                                                                      \
      ಅಂಕೆ = 0 - numerator;                                                    \
    ಯದಿ (denominator >= 0)                                                     \
      den = denominator;                                                      \
    ಅನ್ಯಥಾ                                                                      \
      den = 0 - denominator;                                                  \
    uxdiv_ret = aeabi_ ## uiname(ಅಂಕೆ, den);                                   \
    /* signs differ */                                                        \
    ಯದಿ ((numerator & typemacro ## _MIN) != (denominator & typemacro ## _MIN)) \
        ret.quot = 0 - uxdiv_ret.quot;                                        \
    ಅನ್ಯಥಾ                                                                      \
        ret.quot = uxdiv_ret.quot;                                            \
    ಯದಿ (numerator < 0)                                                        \
        ret.rem = 0 - uxdiv_ret.rem;                                          \
    ಅನ್ಯಥಾ                                                                      \
        ret.rem = uxdiv_ret.rem;                                              \
                                                                              \
    rettype ## _return(ret);                                                  \
}

define_aeabi_xdivmod_signed_type(long long, lldiv_t);
define_aeabi_xdivmod_unsigned_type(unsigned long long, ulldiv_t);
define_aeabi_xdivmod_signed_type(ಪೂರ್ಣಾಙ್ಕ, idiv_t);
define_aeabi_xdivmod_unsigned_type(unsigned, uidiv_t);

REGS_RETURN(lldiv_t, lldiv_t)
REGS_RETURN(ulldiv_t, ulldiv_t)
REGS_RETURN(idiv_t, idiv_t)
REGS_RETURN(uidiv_t, uidiv_t)

AEABI_UXDIVMOD(uldivmod, unsigned long long, ulldiv_t, ULLONG)

__AEABI_XDIVMOD(ldivmod, long long, uldivmod, lldiv_t, ulldiv_t, LLONG)

ಶೂನ್ಯ __aeabi_uldivmod(unsigned long long ಅಂಕೆ, unsigned long long den)
{
    ulldiv_t_return(aeabi_uldivmod(ಅಂಕೆ, den));
}

ಶೂನ್ಯ __aeabi_llsl(double_unsigned_struct val, ಪೂರ್ಣಾಙ್ಕ shift)
{
    double_unsigned_struct ret;

    ಯದಿ (shift >= 32) {
        val.ಮೇಲಿನ = val.ಕೆಳಗಿನ;
        val.ಕೆಳಗಿನ = 0;
        shift -= 32;
    }
    ಯದಿ (shift > 0) {
        ret.ಕೆಳಗಿನ = val.ಕೆಳಗಿನ << shift;
        ret.ಮೇಲಿನ = (val.ಮೇಲಿನ << shift) | (val.ಕೆಳಗಿನ >> (32 - shift));
        double_unsigned_struct_return(ret);
	ಪ್ರತ್ಯಾಗಮ;
    }
    double_unsigned_struct_return(val);
}

#define aeabi_lsr(val, shift, fill, type)                          \
    type ## _struct ret;                                           \
                                                                   \
    ಯದಿ (shift >= 32) {                                             \
        val.ಕೆಳಗಿನ = val.ಮೇಲಿನ;                                        \
        val.ಮೇಲಿನ = fill;                                           \
        shift -= 32;                                               \
    }                                                              \
    ಯದಿ (shift > 0) {                                               \
        ret.ಮೇಲಿನ = val.ಮೇಲಿನ >> shift;                              \
        ret.ಕೆಳಗಿನ = (val.ಮೇಲಿನ << (32 - shift)) | (val.ಕೆಳಗಿನ >> shift); \
        type ## _struct_return(ret);                               \
	ಪ್ರತ್ಯಾಗಮ;                                                    \
    }                                                              \
    type ## _struct_return(val);

ಶೂನ್ಯ __aeabi_llsr(double_unsigned_struct val, ಪೂರ್ಣಾಙ್ಕ shift)
{
    aeabi_lsr(val, shift, 0, double_unsigned);
}

ಶೂನ್ಯ __aeabi_lasr(unsigned_int_struct val, ಪೂರ್ಣಾಙ್ಕ shift)
{
    aeabi_lsr(val, shift, val.ಮೇಲಿನ >> 31, unsigned_int);
}


/* Integer division functions */

#ಯದಿ 0 /* very slow */
AEABI_UXDIVMOD(uidivmod, unsigned, uidiv_t, UINT)

ಪೂರ್ಣಾಙ್ಕ __aeabi_idiv(ಪೂರ್ಣಾಙ್ಕ numerator, ಪೂರ್ಣಾಙ್ಕ denominator)
{
    unsigned ಅಂಕೆ, den;
    uidiv_t ret;

    ಯದಿ (numerator >= 0)
        ಅಂಕೆ = numerator;
    ಅನ್ಯಥಾ
        ಅಂಕೆ = 0 - numerator;
    ಯದಿ (denominator >= 0)
        den = denominator;
    ಅನ್ಯಥಾ
        den = 0 - denominator;
    ret = aeabi_uidivmod(ಅಂಕೆ, den);
    ಯದಿ ((numerator & INT_MIN) != (denominator & INT_MIN)) /* signs differ */
        ret.quot *= -1;
    ಪ್ರತ್ಯಾಗಮ ret.quot;
}

unsigned __aeabi_uidiv(unsigned ಅಂಕೆ, unsigned den)
{
    ಪ್ರತ್ಯಾಗಮ aeabi_uidivmod(ಅಂಕೆ, den).quot;
}

__AEABI_XDIVMOD(idivmod, ಪೂರ್ಣಾಙ್ಕ, uidivmod, idiv_t, uidiv_t, INT)

ಶೂನ್ಯ __aeabi_uidivmod(unsigned ಅಂಕೆ, unsigned den)
{
    uidiv_t_return(aeabi_uidivmod(ಅಂಕೆ, den));
}
#ಅನ್ಯಥಾ
# define UIDIVMOD_ASM 1
#endif

/* Some targets do not have all eabi calls (OpenBSD) */
ಪ್ರಕಾರನಿರ್ದೇಶ __SIZE_TYPE__ size_t;
ಬಾಹ್ಯ ಶೂನ್ಯ *memcpy(ಶೂನ್ಯ *dest, ಧ್ರುವ ಶೂನ್ಯ *src, size_t n);
ಬಾಹ್ಯ ಶೂನ್ಯ *memmove(ಶೂನ್ಯ *dest, ಧ್ರುವ ಶೂನ್ಯ *src, size_t n);
ಬಾಹ್ಯ ಶೂನ್ಯ *memset(ಶೂನ್ಯ *s, ಪೂರ್ಣಾಙ್ಕ c, size_t n);

ಶೂನ್ಯ *
__aeabi_memcpy (ಶೂನ್ಯ *dest, ಧ್ರುವ ಶೂನ್ಯ *src, size_t n)
{
    ಪ್ರತ್ಯಾಗಮ memcpy (dest, src, n);
}

ಶೂನ್ಯ *
__aeabi_memmove (ಶೂನ್ಯ *dest, ಧ್ರುವ ಶೂನ್ಯ *src, size_t n)
{
    ಪ್ರತ್ಯಾಗಮ memmove (dest, src, n);
}

ಶೂನ್ಯ *
__aeabi_memmove4 (ಶೂನ್ಯ *dest, ಧ್ರುವ ಶೂನ್ಯ *src, size_t n)
{
    ಪ್ರತ್ಯಾಗಮ memmove (dest, src, n);
}

ಶೂನ್ಯ *
__aeabi_memmove8 (ಶೂನ್ಯ *dest, ಧ್ರುವ ಶೂನ್ಯ *src, size_t n)
{
    ಪ್ರತ್ಯಾಗಮ memmove (dest, src, n);
}

ಶೂನ್ಯ *
__aeabi_memset (ಶೂನ್ಯ *s, size_t n, ಪೂರ್ಣಾಙ್ಕ c)
{
    ಪ್ರತ್ಯಾಗಮ memset (s, c, n);
}

/* ***************************************************************** */
#ಯದಿ UIDIVMOD_ASM
#ಅನ್ತರ್ಭಾವ <config.h>
__asm__(
   "\n  .global __aeabi_idiv, __aeabi_idivmod"
   "\n  .global __aeabi_uidiv, __aeabi_uidivmod"
#ಯದಿ __ARM_FEATURE_IDIV
   "\n__aeabi_idiv:"
   "\n__aeabi_idivmod:"
   "\n  mov     r2, r0"
   "\n  sdiv    r0, r0, r1"
   "\n  mls     r1, r1, r0, r2"
   "\n  bx      lr"

   "\n__aeabi_uidiv:"
   "\n__aeabi_uidivmod:"
   "\n  mov     r2, r0"
   "\n  udiv    r0, r0, r1"
   "\n  mls     r1, r1, r0, r2"
   "\n  bx      lr"
#ಅನ್ಯಥಾ
/* Runtime ABI for the ARM Cortex-M0
 * idivmod.S: signed 32 bit division (quotient and remainder)
 *
 * Copyright (c) 2012 Jörg Mische <bobbl@gmx.de>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 */
   "\n__aeabi_idiv:"
   "\n__aeabi_idivmod:"
   "\n  cmp     r0, #0"
   "\n  bge     .Lnumerator_pos"
   "\n  rsb     r0, r0, #0" // num = -num
   "\n  cmp     r1, #0"
   "\n  bge     .Lboth_neg"
   "\n  rsb     r1, r1, #0" // den = -den
   "\n  push    {lr}"
   "\n  bl      __aeabi_uidivmod"
   "\n  rsb     r1, r1, #0" // rem = -rem
   "\n  pop     {pc}"
   "\n.Lboth_neg:"
   "\n  push    {lr}"
   "\n  bl      __aeabi_uidivmod"
   "\n  rsb     r0, r0, #0" // quot = -quot
   "\n  rsb     r1, r1, #0" // rem = -rem
   "\n  pop     {pc}"
   "\n.Ldenom_neg:"
   "\n  rsb     r1, r1, #0" // den = -den
   "\n  push    {lr}"
   "\n  bl      __aeabi_uidivmod"
   "\n  rsb     r0, r0, #0" // quot = -quot
   "\n  pop     {pc}"
   "\n.Lnumerator_pos:"
   "\n  cmp     r1, #0"
   "\n  blt     .Ldenom_neg"

   // Divide r0 by r1 and return the quotient in r0 and the remainder in r1
   "\n__aeabi_uidiv:"
   "\n__aeabi_uidivmod:"
   // Shift left the denominator until it is greater than the numerator
   "\n  mov     r2, #1"	    // counter
   "\n  mov     r3, #0"	    // result
   "\n  cmp     r0, r1"
   "\n  bls     .Lsub_loop"
   "\n  adds    r1, #0"	    // dont shift if denominator would overflow
   "\n  bmi     .Lsub_loop"
   "\n  beq     .Luidiv0"
   "\n.Ldenom_shift_loop:"
   "\n  lsl     r2, #1"
   "\n  lsls    r1, #1"
   "\n  bmi     .Lsub_loop"
   "\n  cmp     r0, r1"
   "\n  bhi     .Ldenom_shift_loop"
   "\n.Lsub_loop:"
   "\n  cmp     r0, r1"     // if (num >= den)...
   "\n  subcs   r0, r1"     // numerator -= denom
   "\n  orrcs   r3, r2"     // result(r3) |= bitmask(r2)
   "\n  lsr     r1, #1"	    // denom(r1) >>= 1
   "\n  lsrs    r2, #1"	    // bitmask(r2) >>= 1
   "\n  bne     .Lsub_loop"
   "\n  mov     r1, r0"	    // remainder(r1) = numerator(r0)
   "\n  mov     r0, r3"	    // quotient(r0) = result(r3)
   "\n  bx      lr"
   "\n.Luidiv0:"            // XXX: division by zero
   "\n  mov     r0, #0"
   "\n  bx      lr"
#endif
);
#endif /* UIDIVMOD_ASM */
/* ***************************************************************** */
#endif
