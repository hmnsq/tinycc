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
#ଅନ୍ୟଥା
#ଅନ୍ତର୍ଭାଵ <limits.h>
#endif

/* We rely on the little endianness and EABI calling convention for this to
   work */

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା double_unsigned_struct {
    unsigned ତଳ;
    unsigned ଉପର;
} double_unsigned_struct;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା unsigned_int_struct {
    unsigned ତଳ;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଉପର;
} unsigned_int_struct;

#define REGS_RETURN(name, type) \
    ସ୍ଥିର ଶୂନ୍ୟ name ## _return(type ret) {}


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
ଶୂନ୍ୟ __aeabi_ ## name(unsigned val)                                          \
{                                                                            \
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା exp, ଉପର_shift, sign;                                               \
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
    ଯଦି (with_sign) {                                                         \
        ଯଦି (exp > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            ଫେରନ୍ତୁ;                                                          \
    } ଅନ୍ୟଥା {                                                                 \
        ଯଦି ((sign && exp >= 0) || exp > 63) /* if val < 0 || val too big */  \
            ଫେରନ୍ତୁ;                                                          \
    }                                                                        \
                                                                             \
    val &= (1 << FLOAT_FRAC_BITS) - 1;                                       \
    ଯଦି (exp >= 32) {                                                         \
        ret.ଉପର = 1 << (exp - 32);                                          \
        ଯଦି (exp - 32 >= FLOAT_FRAC_BITS) {                                   \
            ret.ଉପର |= val << (exp - 32 - FLOAT_FRAC_BITS);                 \
            ret.ତଳ = 0;                                                     \
        } ଅନ୍ୟଥା {                                                             \
            ଉପର_shift = FLOAT_FRAC_BITS - (exp - 32);                       \
            ret.ଉପର |= val >> ଉପର_shift;                                   \
            ret.ତଳ = val << (32 - ଉପର_shift);                              \
        }                                                                    \
    } ଅନ୍ୟଥା {                                                                 \
        ret.ଉପର = 0;                                                        \
        ret.ତଳ = 1 << exp;                                                  \
        ଯଦି (exp > FLOAT_FRAC_BITS)                                           \
            ret.ତଳ |= val << (exp - FLOAT_FRAC_BITS);                       \
        ଅନ୍ୟଥା                                                                 \
            ret.ତଳ |= val >> (FLOAT_FRAC_BITS - exp);                       \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    ଯଦି (with_sign && sign) {                                                 \
        ret.ତଳ = ~ret.ତଳ;                                                  \
        ret.ଉପର = ~ret.ଉପର;                                                \
        ଯଦି (ret.ତଳ == UINT_MAX) {                                           \
            ret.ତଳ = 0;                                                     \
            ret.ଉପର++;                                                      \
        } ଅନ୍ୟଥା                                                               \
            ret.ତଳ++;                                                       \
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
ଶୂନ୍ୟ __aeabi_ ## name(double_unsigned_struct val)                            \
{                                                                            \
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା exp, ଉପର_shift, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    ଯଦି ((val.ଉପର & ~0x80000000) == 0 && val.ତଳ == 0) {                     \
        ret.ତଳ = ret.ଉପର = 0;                                              \
        ଯାଅ _ret_;                                                          \
    }                                                                        \
                                                                             \
    /* compute sign */                                                       \
    sign = val.ଉପର >> 31;                                                   \
                                                                             \
    /* compute real exponent */                                              \
    exp = (val.ଉପର >> (DOUBLE_FRAC_BITS - 32));                             \
    exp &= (1 << DOUBLE_EXP_BITS) - 1;                                       \
    exp -= ONE_EXP(DOUBLE);                                                  \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    ଯଦି (with_sign) {                                                         \
        ଯଦି (exp > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            ଫେରନ୍ତୁ;                                                          \
    } ଅନ୍ୟଥା {                                                                 \
        ଯଦି ((sign && exp >= 0) || exp > 63) /* if val < 0 || val too big */  \
            ଫେରନ୍ତୁ;                                                          \
    }                                                                        \
                                                                             \
    val.ଉପର &= (1 << (DOUBLE_FRAC_BITS - 32)) - 1;                          \
    ଯଦି (exp >= 32) {                                                         \
        ret.ଉପର = 1 << (exp - 32);                                          \
        ଯଦି (exp >= DOUBLE_FRAC_BITS) {                                       \
            ଉପର_shift = exp - DOUBLE_FRAC_BITS;                             \
            ret.ଉପର |= val.ଉପର << ଉପର_shift;                              \
            ret.ଉପର |= val.ତଳ >> (32 - ଉପର_shift);                        \
            ret.ତଳ = val.ତଳ << ଉପର_shift;                                 \
        } ଅନ୍ୟଥା {                                                             \
            ଉପର_shift = DOUBLE_FRAC_BITS - exp;                             \
            ret.ଉପର |= val.ଉପର >> ଉପର_shift;                              \
            ret.ତଳ = val.ଉପର << (32 - ଉପର_shift);                         \
            ret.ତଳ |= val.ତଳ >> ଉପର_shift;                                \
        }                                                                    \
    } ଅନ୍ୟଥା {                                                                 \
        ret.ଉପର = 0;                                                        \
        ret.ତଳ = 1 << exp;                                                  \
        ଯଦି (exp > DOUBLE_FRAC_BITS - 32) {                                   \
            ଉପର_shift = exp - (DOUBLE_FRAC_BITS - 32);                      \
            ret.ତଳ |= val.ଉପର << ଉପର_shift;                               \
            ret.ତଳ |= val.ତଳ >> (32 - ଉପର_shift);                         \
        } ଅନ୍ୟଥା                                                               \
            ret.ତଳ |= val.ଉପର >> (DOUBLE_FRAC_BITS - 32 - exp);            \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    ଯଦି (with_sign && sign) {                                                 \
        ret.ତଳ = ~ret.ତଳ;                                                  \
        ret.ଉପର = ~ret.ଉପର;                                                \
        ଯଦି (ret.ତଳ == UINT_MAX) {                                           \
            ret.ତଳ = 0;                                                     \
            ret.ଉପର++;                                                      \
        } ଅନ୍ୟଥା                                                               \
            ret.ତଳ++;                                                       \
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
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା s /* shift */, flb /* first lost bit */, sign = 0;              \
    unsigned p = 0 /* power */, ret;                                    \
    double_unsigned_struct val;                                         \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    ଯଦି (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.ତଳ = v;                                                        \
    val.ଉପର = v >> 32;                                                 \
    /* fill fraction bits */                                            \
    ପାଇଁ (s = 31, p = 1 << 31; p && !(val.ଉପର & p); s--, p >>= 1);      \
    ଯଦି (p) {                                                            \
        ret = val.ଉପର & (p - 1);                                       \
        ଯଦି (s < FLOAT_FRAC_BITS) {                                      \
            ret <<= FLOAT_FRAC_BITS - s;                                \
            ret |= val.ତଳ >> (32 - (FLOAT_FRAC_BITS - s));             \
            flb = (val.ତଳ >> (32 - (FLOAT_FRAC_BITS - s - 1))) & 1;    \
        } ଅନ୍ୟଥା {                                                        \
            flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;               \
            ret >>= s - FLOAT_FRAC_BITS;                                \
        }                                                               \
        s += 32;                                                        \
    } ଅନ୍ୟଥା {                                                            \
        ପାଇଁ (s = 31, p = 1 << 31; p && !(val.ତଳ & p); s--, p >>= 1);   \
        ଯଦି (p) {                                                        \
            ret = val.ତଳ & (p - 1);                                    \
            ଯଦି (s <= FLOAT_FRAC_BITS) {                                 \
                ret <<= FLOAT_FRAC_BITS - s;                            \
                flb = 0;                                                \
	    } ଅନ୍ୟଥା {                                                    \
                flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;           \
                ret >>= s - FLOAT_FRAC_BITS;                            \
	    }                                                           \
        } ଅନ୍ୟଥା                                                          \
            ଫେରନ୍ତୁ 0;                                                   \
    }                                                                   \
    ଯଦି (flb)                                                            \
        ret++;                                                          \
                                                                        \
    /* fill exponent bits */                                            \
    ret |= (s + ONE_EXP(FLOAT)) << FLOAT_FRAC_BITS;                     \
                                                                        \
    /* fill sign bit */                                                 \
    ret |= sign << 31;                                                  \
                                                                        \
    ଫେରନ୍ତୁ ret;                                                         \
}

/* unsigned long long to float conversion */
DEFINE__AEABI_XL2F(ul2f, 0)

/* long long to float conversion */
DEFINE__AEABI_XL2F(l2f, 1)

/* long long to double conversion */
#define __AEABI_XL2D(name, with_sign)                                   \
ଶୂନ୍ୟ __aeabi_ ## name(unsigned long long v)                             \
{                                                                       \
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା s /* shift */, ଉପର_shift, sign = 0;                            \
    unsigned tmp, p = 0;                                                \
    double_unsigned_struct val, ret;                                    \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    ଯଦି (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.ତଳ = v;                                                        \
    val.ଉପର = v >> 32;                                                 \
                                                                        \
    /* fill fraction bits */                                            \
    ପାଇଁ (s = 31, p = 1 << 31; p && !(val.ଉପର & p); s--, p >>= 1);      \
    ଯଦି (p) {                                                            \
        tmp = val.ଉପର & (p - 1);                                       \
        ଯଦି (s < DOUBLE_FRAC_BITS - 32) {                                \
            ଉପର_shift = DOUBLE_FRAC_BITS - 32 - s;                     \
            ret.ଉପର = tmp << ଉପର_shift;                               \
            ret.ଉପର |= val.ତଳ >> (32 - ଉପର_shift);                   \
            ret.ତଳ = val.ତଳ << ଉପର_shift;                            \
        } ଅନ୍ୟଥା {                                                        \
            ଉପର_shift = s - (DOUBLE_FRAC_BITS - 32);                   \
            ret.ଉପର = tmp >> ଉପର_shift;                               \
            ret.ତଳ = tmp << (32 - ଉପର_shift);                         \
            ret.ତଳ |= val.ତଳ >> ଉପର_shift;                           \
            ଯଦି ((val.ତଳ >> (ଉପର_shift - 1)) & 1) {                    \
                ଯଦି (ret.ତଳ == UINT_MAX) {                              \
                    ret.ଉପର++;                                         \
                    ret.ତଳ = 0;                                        \
		} ଅନ୍ୟଥା                                                  \
                    ret.ତଳ++;                                          \
            }                                                           \
        }                                                               \
        s += 32;                                                        \
    } ଅନ୍ୟଥା {                                                            \
        ପାଇଁ (s = 31, p = 1 << 31; p && !(val.ତଳ & p); s--, p >>= 1);   \
        ଯଦି (p) {                                                        \
            tmp = val.ତଳ & (p - 1);                                    \
            ଯଦି (s <= DOUBLE_FRAC_BITS - 32) {                           \
                ଉପର_shift = DOUBLE_FRAC_BITS - 32 - s;                 \
                ret.ଉପର = tmp << ଉପର_shift;                           \
                ret.ତଳ = 0;                                            \
	    } ଅନ୍ୟଥା {                                                    \
                ଉପର_shift = s - (DOUBLE_FRAC_BITS - 32);               \
                ret.ଉପର = tmp >> ଉପର_shift;                           \
                ret.ତଳ = tmp << (32 - ଉପର_shift);                     \
            }                                                           \
        } ଅନ୍ୟଥା {                                                        \
            ret.ଉପର = ret.ତଳ = 0;                                     \
            ଯାଅ _ret_;                                                 \
        }                                                               \
    }                                                                   \
                                                                        \
    /* fill exponent bits */                                            \
    ret.ଉପର |= (s + ONE_EXP(DOUBLE)) << (DOUBLE_FRAC_BITS - 32);       \
                                                                        \
    /* fill sign bit */                                                 \
    ret.ଉପର |= sign << 31;                                             \
                                                                        \
_ret_:                                                                  \
    double_unsigned_struct_return(ret);                                 \
}

/* unsigned long long to double conversion */
__AEABI_XL2D(ul2d, 0)

/* long long to double conversion */
__AEABI_XL2D(l2d, 1)

#ଯଦି 1
/* Long long helper functions */

/* TODO: add error in case of den == 0 (see §4.3.1 and §4.3.2) */

#define define_aeabi_xdivmod_signed_type(basetype, type) \
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା type {                                    \
    basetype quot;                                       \
    unsigned basetype rem;                               \
} type

#define define_aeabi_xdivmod_unsigned_type(basetype, type) \
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା type {                                      \
    basetype quot;                                         \
    basetype rem;                                          \
} type

#define AEABI_UXDIVMOD(name,type, rettype, typemacro)                     \
ସ୍ଥିର ଧାଡ଼ିଭିତରେ rettype aeabi_ ## name (type ଅଙ୍କ, type den)                 \
{                                                                         \
    rettype ret;                                                          \
    type quot = 0;                                                        \
                                                                          \
    /* Increase quotient while it is less than numerator */               \
    ଯେତେବେଳେ (ଅଙ୍କ >= den) {                                                  \
        type q = 1;                                                       \
                                                                          \
        /* Find closest power of two */                                   \
        ଯେତେବେଳେ ((q << 1) * den <= ଅଙ୍କ && q * den <= typemacro ## _MAX / 2) \
            q <<= 1;                                                      \
                                                                          \
        /* Compute difference between current quotient and numerator */   \
        ଅଙ୍କ -= q * den;                                                   \
        quot += q;                                                        \
    }                                                                     \
    ret.quot = quot;                                                      \
    ret.rem = ଅଙ୍କ;                                                        \
    ଫେରନ୍ତୁ ret;                                                           \
}

#define __AEABI_XDIVMOD(name, type, uiname, rettype, urettype, typemacro)     \
ଶୂନ୍ୟ __aeabi_ ## name(type numerator, type denominator)                       \
{                                                                             \
    unsigned type ଅଙ୍କ, den;                                                   \
    urettype uxdiv_ret;                                                       \
    rettype ret;                                                              \
                                                                              \
    ଯଦି (numerator >= 0)                                                       \
      ଅଙ୍କ = numerator;                                                        \
    ଅନ୍ୟଥା                                                                      \
      ଅଙ୍କ = 0 - numerator;                                                    \
    ଯଦି (denominator >= 0)                                                     \
      den = denominator;                                                      \
    ଅନ୍ୟଥା                                                                      \
      den = 0 - denominator;                                                  \
    uxdiv_ret = aeabi_ ## uiname(ଅଙ୍କ, den);                                   \
    /* signs differ */                                                        \
    ଯଦି ((numerator & typemacro ## _MIN) != (denominator & typemacro ## _MIN)) \
        ret.quot = 0 - uxdiv_ret.quot;                                        \
    ଅନ୍ୟଥା                                                                      \
        ret.quot = uxdiv_ret.quot;                                            \
    ଯଦି (numerator < 0)                                                        \
        ret.rem = 0 - uxdiv_ret.rem;                                          \
    ଅନ୍ୟଥା                                                                      \
        ret.rem = uxdiv_ret.rem;                                              \
                                                                              \
    rettype ## _return(ret);                                                  \
}

define_aeabi_xdivmod_signed_type(long long, lldiv_t);
define_aeabi_xdivmod_unsigned_type(unsigned long long, ulldiv_t);
define_aeabi_xdivmod_signed_type(ପୂର୍ଣ୍ଣସଂଖ୍ୟା, idiv_t);
define_aeabi_xdivmod_unsigned_type(unsigned, uidiv_t);

REGS_RETURN(lldiv_t, lldiv_t)
REGS_RETURN(ulldiv_t, ulldiv_t)
REGS_RETURN(idiv_t, idiv_t)
REGS_RETURN(uidiv_t, uidiv_t)

AEABI_UXDIVMOD(uldivmod, unsigned long long, ulldiv_t, ULLONG)

__AEABI_XDIVMOD(ldivmod, long long, uldivmod, lldiv_t, ulldiv_t, LLONG)

ଶୂନ୍ୟ __aeabi_uldivmod(unsigned long long ଅଙ୍କ, unsigned long long den)
{
    ulldiv_t_return(aeabi_uldivmod(ଅଙ୍କ, den));
}

ଶୂନ୍ୟ __aeabi_llsl(double_unsigned_struct val, ପୂର୍ଣ୍ଣସଂଖ୍ୟା shift)
{
    double_unsigned_struct ret;

    ଯଦି (shift >= 32) {
        val.ଉପର = val.ତଳ;
        val.ତଳ = 0;
        shift -= 32;
    }
    ଯଦି (shift > 0) {
        ret.ତଳ = val.ତଳ << shift;
        ret.ଉପର = (val.ଉପର << shift) | (val.ତଳ >> (32 - shift));
        double_unsigned_struct_return(ret);
	ଫେରନ୍ତୁ;
    }
    double_unsigned_struct_return(val);
}

#define aeabi_lsr(val, shift, fill, type)                          \
    type ## _struct ret;                                           \
                                                                   \
    ଯଦି (shift >= 32) {                                             \
        val.ତଳ = val.ଉପର;                                        \
        val.ଉପର = fill;                                           \
        shift -= 32;                                               \
    }                                                              \
    ଯଦି (shift > 0) {                                               \
        ret.ଉପର = val.ଉପର >> shift;                              \
        ret.ତଳ = (val.ଉପର << (32 - shift)) | (val.ତଳ >> shift); \
        type ## _struct_return(ret);                               \
	ଫେରନ୍ତୁ;                                                    \
    }                                                              \
    type ## _struct_return(val);

ଶୂନ୍ୟ __aeabi_llsr(double_unsigned_struct val, ପୂର୍ଣ୍ଣସଂଖ୍ୟା shift)
{
    aeabi_lsr(val, shift, 0, double_unsigned);
}

ଶୂନ୍ୟ __aeabi_lasr(unsigned_int_struct val, ପୂର୍ଣ୍ଣସଂଖ୍ୟା shift)
{
    aeabi_lsr(val, shift, val.ଉପର >> 31, unsigned_int);
}


/* Integer division functions */

#ଯଦି 0 /* very slow */
AEABI_UXDIVMOD(uidivmod, unsigned, uidiv_t, UINT)

ପୂର୍ଣ୍ଣସଂଖ୍ୟା __aeabi_idiv(ପୂର୍ଣ୍ଣସଂଖ୍ୟା numerator, ପୂର୍ଣ୍ଣସଂଖ୍ୟା denominator)
{
    unsigned ଅଙ୍କ, den;
    uidiv_t ret;

    ଯଦି (numerator >= 0)
        ଅଙ୍କ = numerator;
    ଅନ୍ୟଥା
        ଅଙ୍କ = 0 - numerator;
    ଯଦି (denominator >= 0)
        den = denominator;
    ଅନ୍ୟଥା
        den = 0 - denominator;
    ret = aeabi_uidivmod(ଅଙ୍କ, den);
    ଯଦି ((numerator & INT_MIN) != (denominator & INT_MIN)) /* signs differ */
        ret.quot *= -1;
    ଫେରନ୍ତୁ ret.quot;
}

unsigned __aeabi_uidiv(unsigned ଅଙ୍କ, unsigned den)
{
    ଫେରନ୍ତୁ aeabi_uidivmod(ଅଙ୍କ, den).quot;
}

__AEABI_XDIVMOD(idivmod, ପୂର୍ଣ୍ଣସଂଖ୍ୟା, uidivmod, idiv_t, uidiv_t, INT)

ଶୂନ୍ୟ __aeabi_uidivmod(unsigned ଅଙ୍କ, unsigned den)
{
    uidiv_t_return(aeabi_uidivmod(ଅଙ୍କ, den));
}
#ଅନ୍ୟଥା
# define UIDIVMOD_ASM 1
#endif

/* Some targets do not have all eabi calls (OpenBSD) */
ପ୍ରକାରବ୍ୟାଖ୍ୟା __SIZE_TYPE__ size_t;
ବାହ୍ୟ ଶୂନ୍ୟ *memcpy(ଶୂନ୍ୟ *dest, ଅଚଳ ଶୂନ୍ୟ *src, size_t n);
ବାହ୍ୟ ଶୂନ୍ୟ *memmove(ଶୂନ୍ୟ *dest, ଅଚଳ ଶୂନ୍ୟ *src, size_t n);
ବାହ୍ୟ ଶୂନ୍ୟ *memset(ଶୂନ୍ୟ *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, size_t n);

ଶୂନ୍ୟ *
__aeabi_memcpy (ଶୂନ୍ୟ *dest, ଅଚଳ ଶୂନ୍ୟ *src, size_t n)
{
    ଫେରନ୍ତୁ memcpy (dest, src, n);
}

ଶୂନ୍ୟ *
__aeabi_memmove (ଶୂନ୍ୟ *dest, ଅଚଳ ଶୂନ୍ୟ *src, size_t n)
{
    ଫେରନ୍ତୁ memmove (dest, src, n);
}

ଶୂନ୍ୟ *
__aeabi_memmove4 (ଶୂନ୍ୟ *dest, ଅଚଳ ଶୂନ୍ୟ *src, size_t n)
{
    ଫେରନ୍ତୁ memmove (dest, src, n);
}

ଶୂନ୍ୟ *
__aeabi_memmove8 (ଶୂନ୍ୟ *dest, ଅଚଳ ଶୂନ୍ୟ *src, size_t n)
{
    ଫେରନ୍ତୁ memmove (dest, src, n);
}

ଶୂନ୍ୟ *
__aeabi_memset (ଶୂନ୍ୟ *s, size_t n, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    ଫେରନ୍ତୁ memset (s, c, n);
}

/* ***************************************************************** */
#ଯଦି UIDIVMOD_ASM
#ଅନ୍ତର୍ଭାଵ <config.h>
__asm__(
   "\n  .global __aeabi_idiv, __aeabi_idivmod"
   "\n  .global __aeabi_uidiv, __aeabi_uidivmod"
#ଯଦି __ARM_FEATURE_IDIV
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
#ଅନ୍ୟଥା
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
