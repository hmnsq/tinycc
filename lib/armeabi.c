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
#অন্যথা
#অন্তর্ভাৱ <limits.h>
#endif

/* We rely on the little endianness and EABI calling convention for this to
   work */

প্রকারনির্দেশ সংরচনা double_unsigned_struct {
    unsigned নিচেৰ;
    unsigned উপৰেৰ;
} double_unsigned_struct;

প্রকারনির্দেশ সংরচনা unsigned_int_struct {
    unsigned নিচেৰ;
    পূর্ণাঙ্ক উপৰেৰ;
} unsigned_int_struct;

#define REGS_RETURN(name, type) \
    স্থির শূন্য name ## _return(type ret) {}


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
শূন্য __aeabi_ ## name(unsigned val)                                          \
{                                                                            \
    পূর্ণাঙ্ক exp, উপৰেৰ_shift, sign;                                               \
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
    যদি (with_sign) {                                                         \
        যদি (exp > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            ঘূৰাই;                                                          \
    } অন্যথা {                                                                 \
        যদি ((sign && exp >= 0) || exp > 63) /* if val < 0 || val too big */  \
            ঘূৰাই;                                                          \
    }                                                                        \
                                                                             \
    val &= (1 << FLOAT_FRAC_BITS) - 1;                                       \
    যদি (exp >= 32) {                                                         \
        ret.উপৰেৰ = 1 << (exp - 32);                                          \
        যদি (exp - 32 >= FLOAT_FRAC_BITS) {                                   \
            ret.উপৰেৰ |= val << (exp - 32 - FLOAT_FRAC_BITS);                 \
            ret.নিচেৰ = 0;                                                     \
        } অন্যথা {                                                             \
            উপৰেৰ_shift = FLOAT_FRAC_BITS - (exp - 32);                       \
            ret.উপৰেৰ |= val >> উপৰেৰ_shift;                                   \
            ret.নিচেৰ = val << (32 - উপৰেৰ_shift);                              \
        }                                                                    \
    } অন্যথা {                                                                 \
        ret.উপৰেৰ = 0;                                                        \
        ret.নিচেৰ = 1 << exp;                                                  \
        যদি (exp > FLOAT_FRAC_BITS)                                           \
            ret.নিচেৰ |= val << (exp - FLOAT_FRAC_BITS);                       \
        অন্যথা                                                                 \
            ret.নিচেৰ |= val >> (FLOAT_FRAC_BITS - exp);                       \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    যদি (with_sign && sign) {                                                 \
        ret.নিচেৰ = ~ret.নিচেৰ;                                                  \
        ret.উপৰেৰ = ~ret.উপৰেৰ;                                                \
        যদি (ret.নিচেৰ == UINT_MAX) {                                           \
            ret.নিচেৰ = 0;                                                     \
            ret.উপৰেৰ++;                                                      \
        } অন্যথা                                                               \
            ret.নিচেৰ++;                                                       \
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
শূন্য __aeabi_ ## name(double_unsigned_struct val)                            \
{                                                                            \
    পূর্ণাঙ্ক exp, উপৰেৰ_shift, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    যদি ((val.উপৰেৰ & ~0x80000000) == 0 && val.নিচেৰ == 0) {                     \
        ret.নিচেৰ = ret.উপৰেৰ = 0;                                              \
        গচ্ছ _ret_;                                                          \
    }                                                                        \
                                                                             \
    /* compute sign */                                                       \
    sign = val.উপৰেৰ >> 31;                                                   \
                                                                             \
    /* compute real exponent */                                              \
    exp = (val.উপৰেৰ >> (DOUBLE_FRAC_BITS - 32));                             \
    exp &= (1 << DOUBLE_EXP_BITS) - 1;                                       \
    exp -= ONE_EXP(DOUBLE);                                                  \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    যদি (with_sign) {                                                         \
        যদি (exp > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            ঘূৰাই;                                                          \
    } অন্যথা {                                                                 \
        যদি ((sign && exp >= 0) || exp > 63) /* if val < 0 || val too big */  \
            ঘূৰাই;                                                          \
    }                                                                        \
                                                                             \
    val.উপৰেৰ &= (1 << (DOUBLE_FRAC_BITS - 32)) - 1;                          \
    যদি (exp >= 32) {                                                         \
        ret.উপৰেৰ = 1 << (exp - 32);                                          \
        যদি (exp >= DOUBLE_FRAC_BITS) {                                       \
            উপৰেৰ_shift = exp - DOUBLE_FRAC_BITS;                             \
            ret.উপৰেৰ |= val.উপৰেৰ << উপৰেৰ_shift;                              \
            ret.উপৰেৰ |= val.নিচেৰ >> (32 - উপৰেৰ_shift);                        \
            ret.নিচেৰ = val.নিচেৰ << উপৰেৰ_shift;                                 \
        } অন্যথা {                                                             \
            উপৰেৰ_shift = DOUBLE_FRAC_BITS - exp;                             \
            ret.উপৰেৰ |= val.উপৰেৰ >> উপৰেৰ_shift;                              \
            ret.নিচেৰ = val.উপৰেৰ << (32 - উপৰেৰ_shift);                         \
            ret.নিচেৰ |= val.নিচেৰ >> উপৰেৰ_shift;                                \
        }                                                                    \
    } অন্যথা {                                                                 \
        ret.উপৰেৰ = 0;                                                        \
        ret.নিচেৰ = 1 << exp;                                                  \
        যদি (exp > DOUBLE_FRAC_BITS - 32) {                                   \
            উপৰেৰ_shift = exp - (DOUBLE_FRAC_BITS - 32);                      \
            ret.নিচেৰ |= val.উপৰেৰ << উপৰেৰ_shift;                               \
            ret.নিচেৰ |= val.নিচেৰ >> (32 - উপৰেৰ_shift);                         \
        } অন্যথা                                                               \
            ret.নিচেৰ |= val.উপৰেৰ >> (DOUBLE_FRAC_BITS - 32 - exp);            \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    যদি (with_sign && sign) {                                                 \
        ret.নিচেৰ = ~ret.নিচেৰ;                                                  \
        ret.উপৰেৰ = ~ret.উপৰেৰ;                                                \
        যদি (ret.নিচেৰ == UINT_MAX) {                                           \
            ret.নিচেৰ = 0;                                                     \
            ret.উপৰেৰ++;                                                      \
        } অন্যথা                                                               \
            ret.নিচেৰ++;                                                       \
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
    পূর্ণাঙ্ক s /* shift */, flb /* first lost bit */, sign = 0;              \
    unsigned p = 0 /* power */, ret;                                    \
    double_unsigned_struct val;                                         \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    যদি (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.নিচেৰ = v;                                                        \
    val.উপৰেৰ = v >> 32;                                                 \
    /* fill fraction bits */                                            \
    বাবে (s = 31, p = 1 << 31; p && !(val.উপৰেৰ & p); s--, p >>= 1);      \
    যদি (p) {                                                            \
        ret = val.উপৰেৰ & (p - 1);                                       \
        যদি (s < FLOAT_FRAC_BITS) {                                      \
            ret <<= FLOAT_FRAC_BITS - s;                                \
            ret |= val.নিচেৰ >> (32 - (FLOAT_FRAC_BITS - s));             \
            flb = (val.নিচেৰ >> (32 - (FLOAT_FRAC_BITS - s - 1))) & 1;    \
        } অন্যথা {                                                        \
            flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;               \
            ret >>= s - FLOAT_FRAC_BITS;                                \
        }                                                               \
        s += 32;                                                        \
    } অন্যথা {                                                            \
        বাবে (s = 31, p = 1 << 31; p && !(val.নিচেৰ & p); s--, p >>= 1);   \
        যদি (p) {                                                        \
            ret = val.নিচেৰ & (p - 1);                                    \
            যদি (s <= FLOAT_FRAC_BITS) {                                 \
                ret <<= FLOAT_FRAC_BITS - s;                            \
                flb = 0;                                                \
	    } অন্যথা {                                                    \
                flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;           \
                ret >>= s - FLOAT_FRAC_BITS;                            \
	    }                                                           \
        } অন্যথা                                                          \
            ঘূৰাই 0;                                                   \
    }                                                                   \
    যদি (flb)                                                            \
        ret++;                                                          \
                                                                        \
    /* fill exponent bits */                                            \
    ret |= (s + ONE_EXP(FLOAT)) << FLOAT_FRAC_BITS;                     \
                                                                        \
    /* fill sign bit */                                                 \
    ret |= sign << 31;                                                  \
                                                                        \
    ঘূৰাই ret;                                                         \
}

/* unsigned long long to float conversion */
DEFINE__AEABI_XL2F(ul2f, 0)

/* long long to float conversion */
DEFINE__AEABI_XL2F(l2f, 1)

/* long long to double conversion */
#define __AEABI_XL2D(name, with_sign)                                   \
শূন্য __aeabi_ ## name(unsigned long long v)                             \
{                                                                       \
    পূর্ণাঙ্ক s /* shift */, উপৰেৰ_shift, sign = 0;                            \
    unsigned tmp, p = 0;                                                \
    double_unsigned_struct val, ret;                                    \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    যদি (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.নিচেৰ = v;                                                        \
    val.উপৰেৰ = v >> 32;                                                 \
                                                                        \
    /* fill fraction bits */                                            \
    বাবে (s = 31, p = 1 << 31; p && !(val.উপৰেৰ & p); s--, p >>= 1);      \
    যদি (p) {                                                            \
        tmp = val.উপৰেৰ & (p - 1);                                       \
        যদি (s < DOUBLE_FRAC_BITS - 32) {                                \
            উপৰেৰ_shift = DOUBLE_FRAC_BITS - 32 - s;                     \
            ret.উপৰেৰ = tmp << উপৰেৰ_shift;                               \
            ret.উপৰেৰ |= val.নিচেৰ >> (32 - উপৰেৰ_shift);                   \
            ret.নিচেৰ = val.নিচেৰ << উপৰেৰ_shift;                            \
        } অন্যথা {                                                        \
            উপৰেৰ_shift = s - (DOUBLE_FRAC_BITS - 32);                   \
            ret.উপৰেৰ = tmp >> উপৰেৰ_shift;                               \
            ret.নিচেৰ = tmp << (32 - উপৰেৰ_shift);                         \
            ret.নিচেৰ |= val.নিচেৰ >> উপৰেৰ_shift;                           \
            যদি ((val.নিচেৰ >> (উপৰেৰ_shift - 1)) & 1) {                    \
                যদি (ret.নিচেৰ == UINT_MAX) {                              \
                    ret.উপৰেৰ++;                                         \
                    ret.নিচেৰ = 0;                                        \
		} অন্যথা                                                  \
                    ret.নিচেৰ++;                                          \
            }                                                           \
        }                                                               \
        s += 32;                                                        \
    } অন্যথা {                                                            \
        বাবে (s = 31, p = 1 << 31; p && !(val.নিচেৰ & p); s--, p >>= 1);   \
        যদি (p) {                                                        \
            tmp = val.নিচেৰ & (p - 1);                                    \
            যদি (s <= DOUBLE_FRAC_BITS - 32) {                           \
                উপৰেৰ_shift = DOUBLE_FRAC_BITS - 32 - s;                 \
                ret.উপৰেৰ = tmp << উপৰেৰ_shift;                           \
                ret.নিচেৰ = 0;                                            \
	    } অন্যথা {                                                    \
                উপৰেৰ_shift = s - (DOUBLE_FRAC_BITS - 32);               \
                ret.উপৰেৰ = tmp >> উপৰেৰ_shift;                           \
                ret.নিচেৰ = tmp << (32 - উপৰেৰ_shift);                     \
            }                                                           \
        } অন্যথা {                                                        \
            ret.উপৰেৰ = ret.নিচেৰ = 0;                                     \
            গচ্ছ _ret_;                                                 \
        }                                                               \
    }                                                                   \
                                                                        \
    /* fill exponent bits */                                            \
    ret.উপৰেৰ |= (s + ONE_EXP(DOUBLE)) << (DOUBLE_FRAC_BITS - 32);       \
                                                                        \
    /* fill sign bit */                                                 \
    ret.উপৰেৰ |= sign << 31;                                             \
                                                                        \
_ret_:                                                                  \
    double_unsigned_struct_return(ret);                                 \
}

/* unsigned long long to double conversion */
__AEABI_XL2D(ul2d, 0)

/* long long to double conversion */
__AEABI_XL2D(l2d, 1)

#যদি 1
/* Long long helper functions */

/* TODO: add error in case of den == 0 (see §4.3.1 and §4.3.2) */

#define define_aeabi_xdivmod_signed_type(basetype, type) \
প্রকারনির্দেশ সংরচনা type {                                    \
    basetype quot;                                       \
    unsigned basetype rem;                               \
} type

#define define_aeabi_xdivmod_unsigned_type(basetype, type) \
প্রকারনির্দেশ সংরচনা type {                                      \
    basetype quot;                                         \
    basetype rem;                                          \
} type

#define AEABI_UXDIVMOD(name,type, rettype, typemacro)                     \
স্থির অন্তঃস্থ rettype aeabi_ ## name (type অঙ্ক, type den)                 \
{                                                                         \
    rettype ret;                                                          \
    type quot = 0;                                                        \
                                                                          \
    /* Increase quotient while it is less than numerator */               \
    যেতিয়ালৈ (অঙ্ক >= den) {                                                  \
        type q = 1;                                                       \
                                                                          \
        /* Find closest power of two */                                   \
        যেতিয়ালৈ ((q << 1) * den <= অঙ্ক && q * den <= typemacro ## _MAX / 2) \
            q <<= 1;                                                      \
                                                                          \
        /* Compute difference between current quotient and numerator */   \
        অঙ্ক -= q * den;                                                   \
        quot += q;                                                        \
    }                                                                     \
    ret.quot = quot;                                                      \
    ret.rem = অঙ্ক;                                                        \
    ঘূৰাই ret;                                                           \
}

#define __AEABI_XDIVMOD(name, type, uiname, rettype, urettype, typemacro)     \
শূন্য __aeabi_ ## name(type numerator, type denominator)                       \
{                                                                             \
    unsigned type অঙ্ক, den;                                                   \
    urettype uxdiv_ret;                                                       \
    rettype ret;                                                              \
                                                                              \
    যদি (numerator >= 0)                                                       \
      অঙ্ক = numerator;                                                        \
    অন্যথা                                                                      \
      অঙ্ক = 0 - numerator;                                                    \
    যদি (denominator >= 0)                                                     \
      den = denominator;                                                      \
    অন্যথা                                                                      \
      den = 0 - denominator;                                                  \
    uxdiv_ret = aeabi_ ## uiname(অঙ্ক, den);                                   \
    /* signs differ */                                                        \
    যদি ((numerator & typemacro ## _MIN) != (denominator & typemacro ## _MIN)) \
        ret.quot = 0 - uxdiv_ret.quot;                                        \
    অন্যথা                                                                      \
        ret.quot = uxdiv_ret.quot;                                            \
    যদি (numerator < 0)                                                        \
        ret.rem = 0 - uxdiv_ret.rem;                                          \
    অন্যথা                                                                      \
        ret.rem = uxdiv_ret.rem;                                              \
                                                                              \
    rettype ## _return(ret);                                                  \
}

define_aeabi_xdivmod_signed_type(long long, lldiv_t);
define_aeabi_xdivmod_unsigned_type(unsigned long long, ulldiv_t);
define_aeabi_xdivmod_signed_type(পূর্ণাঙ্ক, idiv_t);
define_aeabi_xdivmod_unsigned_type(unsigned, uidiv_t);

REGS_RETURN(lldiv_t, lldiv_t)
REGS_RETURN(ulldiv_t, ulldiv_t)
REGS_RETURN(idiv_t, idiv_t)
REGS_RETURN(uidiv_t, uidiv_t)

AEABI_UXDIVMOD(uldivmod, unsigned long long, ulldiv_t, ULLONG)

__AEABI_XDIVMOD(ldivmod, long long, uldivmod, lldiv_t, ulldiv_t, LLONG)

শূন্য __aeabi_uldivmod(unsigned long long অঙ্ক, unsigned long long den)
{
    ulldiv_t_return(aeabi_uldivmod(অঙ্ক, den));
}

শূন্য __aeabi_llsl(double_unsigned_struct val, পূর্ণাঙ্ক shift)
{
    double_unsigned_struct ret;

    যদি (shift >= 32) {
        val.উপৰেৰ = val.নিচেৰ;
        val.নিচেৰ = 0;
        shift -= 32;
    }
    যদি (shift > 0) {
        ret.নিচেৰ = val.নিচেৰ << shift;
        ret.উপৰেৰ = (val.উপৰেৰ << shift) | (val.নিচেৰ >> (32 - shift));
        double_unsigned_struct_return(ret);
	ঘূৰাই;
    }
    double_unsigned_struct_return(val);
}

#define aeabi_lsr(val, shift, fill, type)                          \
    type ## _struct ret;                                           \
                                                                   \
    যদি (shift >= 32) {                                             \
        val.নিচেৰ = val.উপৰেৰ;                                        \
        val.উপৰেৰ = fill;                                           \
        shift -= 32;                                               \
    }                                                              \
    যদি (shift > 0) {                                               \
        ret.উপৰেৰ = val.উপৰেৰ >> shift;                              \
        ret.নিচেৰ = (val.উপৰেৰ << (32 - shift)) | (val.নিচেৰ >> shift); \
        type ## _struct_return(ret);                               \
	ঘূৰাই;                                                    \
    }                                                              \
    type ## _struct_return(val);

শূন্য __aeabi_llsr(double_unsigned_struct val, পূর্ণাঙ্ক shift)
{
    aeabi_lsr(val, shift, 0, double_unsigned);
}

শূন্য __aeabi_lasr(unsigned_int_struct val, পূর্ণাঙ্ক shift)
{
    aeabi_lsr(val, shift, val.উপৰেৰ >> 31, unsigned_int);
}


/* Integer division functions */

#যদি 0 /* very slow */
AEABI_UXDIVMOD(uidivmod, unsigned, uidiv_t, UINT)

পূর্ণাঙ্ক __aeabi_idiv(পূর্ণাঙ্ক numerator, পূর্ণাঙ্ক denominator)
{
    unsigned অঙ্ক, den;
    uidiv_t ret;

    যদি (numerator >= 0)
        অঙ্ক = numerator;
    অন্যথা
        অঙ্ক = 0 - numerator;
    যদি (denominator >= 0)
        den = denominator;
    অন্যথা
        den = 0 - denominator;
    ret = aeabi_uidivmod(অঙ্ক, den);
    যদি ((numerator & INT_MIN) != (denominator & INT_MIN)) /* signs differ */
        ret.quot *= -1;
    ঘূৰাই ret.quot;
}

unsigned __aeabi_uidiv(unsigned অঙ্ক, unsigned den)
{
    ঘূৰাই aeabi_uidivmod(অঙ্ক, den).quot;
}

__AEABI_XDIVMOD(idivmod, পূর্ণাঙ্ক, uidivmod, idiv_t, uidiv_t, INT)

শূন্য __aeabi_uidivmod(unsigned অঙ্ক, unsigned den)
{
    uidiv_t_return(aeabi_uidivmod(অঙ্ক, den));
}
#অন্যথা
# define UIDIVMOD_ASM 1
#endif

/* Some targets do not have all eabi calls (OpenBSD) */
প্রকারনির্দেশ __SIZE_TYPE__ size_t;
বাহ্য শূন্য *memcpy(শূন্য *dest, ধ্রুৱ শূন্য *src, size_t n);
বাহ্য শূন্য *memmove(শূন্য *dest, ধ্রুৱ শূন্য *src, size_t n);
বাহ্য শূন্য *memset(শূন্য *s, পূর্ণাঙ্ক c, size_t n);

শূন্য *
__aeabi_memcpy (শূন্য *dest, ধ্রুৱ শূন্য *src, size_t n)
{
    ঘূৰাই memcpy (dest, src, n);
}

শূন্য *
__aeabi_memmove (শূন্য *dest, ধ্রুৱ শূন্য *src, size_t n)
{
    ঘূৰাই memmove (dest, src, n);
}

শূন্য *
__aeabi_memmove4 (শূন্য *dest, ধ্রুৱ শূন্য *src, size_t n)
{
    ঘূৰাই memmove (dest, src, n);
}

শূন্য *
__aeabi_memmove8 (শূন্য *dest, ধ্রুৱ শূন্য *src, size_t n)
{
    ঘূৰাই memmove (dest, src, n);
}

শূন্য *
__aeabi_memset (শূন্য *s, size_t n, পূর্ণাঙ্ক c)
{
    ঘূৰাই memset (s, c, n);
}

/* ***************************************************************** */
#যদি UIDIVMOD_ASM
#অন্তর্ভাৱ <config.h>
__asm__(
   "\n  .global __aeabi_idiv, __aeabi_idivmod"
   "\n  .global __aeabi_uidiv, __aeabi_uidivmod"
#যদি __ARM_FEATURE_IDIV
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
#অন্যথা
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
