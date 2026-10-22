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
#وإلا
#ضمن <limits.h>
#endif

/* We rely on the little endianness and EABI calling convention for this to
   work */

تعريفنوع بنية double_unsigned_struct {
    unsigned أدنى;
    unsigned عالي;
} double_unsigned_struct;

تعريفنوع بنية unsigned_int_struct {
    unsigned أدنى;
    صحيح عالي;
} unsigned_int_struct;

#define REGS_RETURN(name, type) \
    ساكن فراغ name ## _return(type ret) {}


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
فراغ __aeabi_ ## name(unsigned val)                                          \
{                                                                            \
    صحيح exp, عالي_shift, sign;                                               \
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
    إذا (with_sign) {                                                         \
        إذا (exp > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            أرجع;                                                          \
    } وإلا {                                                                 \
        إذا ((sign && exp >= 0) || exp > 63) /* if val < 0 || val too big */  \
            أرجع;                                                          \
    }                                                                        \
                                                                             \
    val &= (1 << FLOAT_FRAC_BITS) - 1;                                       \
    إذا (exp >= 32) {                                                         \
        ret.عالي = 1 << (exp - 32);                                          \
        إذا (exp - 32 >= FLOAT_FRAC_BITS) {                                   \
            ret.عالي |= val << (exp - 32 - FLOAT_FRAC_BITS);                 \
            ret.أدنى = 0;                                                     \
        } وإلا {                                                             \
            عالي_shift = FLOAT_FRAC_BITS - (exp - 32);                       \
            ret.عالي |= val >> عالي_shift;                                   \
            ret.أدنى = val << (32 - عالي_shift);                              \
        }                                                                    \
    } وإلا {                                                                 \
        ret.عالي = 0;                                                        \
        ret.أدنى = 1 << exp;                                                  \
        إذا (exp > FLOAT_FRAC_BITS)                                           \
            ret.أدنى |= val << (exp - FLOAT_FRAC_BITS);                       \
        وإلا                                                                 \
            ret.أدنى |= val >> (FLOAT_FRAC_BITS - exp);                       \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    إذا (with_sign && sign) {                                                 \
        ret.أدنى = ~ret.أدنى;                                                  \
        ret.عالي = ~ret.عالي;                                                \
        إذا (ret.أدنى == UINT_MAX) {                                           \
            ret.أدنى = 0;                                                     \
            ret.عالي++;                                                      \
        } وإلا                                                               \
            ret.أدنى++;                                                       \
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
فراغ __aeabi_ ## name(double_unsigned_struct val)                            \
{                                                                            \
    صحيح exp, عالي_shift, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    إذا ((val.عالي & ~0x80000000) == 0 && val.أدنى == 0) {                     \
        ret.أدنى = ret.عالي = 0;                                              \
        اذهب _ret_;                                                          \
    }                                                                        \
                                                                             \
    /* compute sign */                                                       \
    sign = val.عالي >> 31;                                                   \
                                                                             \
    /* compute real exponent */                                              \
    exp = (val.عالي >> (DOUBLE_FRAC_BITS - 32));                             \
    exp &= (1 << DOUBLE_EXP_BITS) - 1;                                       \
    exp -= ONE_EXP(DOUBLE);                                                  \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    إذا (with_sign) {                                                         \
        إذا (exp > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            أرجع;                                                          \
    } وإلا {                                                                 \
        إذا ((sign && exp >= 0) || exp > 63) /* if val < 0 || val too big */  \
            أرجع;                                                          \
    }                                                                        \
                                                                             \
    val.عالي &= (1 << (DOUBLE_FRAC_BITS - 32)) - 1;                          \
    إذا (exp >= 32) {                                                         \
        ret.عالي = 1 << (exp - 32);                                          \
        إذا (exp >= DOUBLE_FRAC_BITS) {                                       \
            عالي_shift = exp - DOUBLE_FRAC_BITS;                             \
            ret.عالي |= val.عالي << عالي_shift;                              \
            ret.عالي |= val.أدنى >> (32 - عالي_shift);                        \
            ret.أدنى = val.أدنى << عالي_shift;                                 \
        } وإلا {                                                             \
            عالي_shift = DOUBLE_FRAC_BITS - exp;                             \
            ret.عالي |= val.عالي >> عالي_shift;                              \
            ret.أدنى = val.عالي << (32 - عالي_shift);                         \
            ret.أدنى |= val.أدنى >> عالي_shift;                                \
        }                                                                    \
    } وإلا {                                                                 \
        ret.عالي = 0;                                                        \
        ret.أدنى = 1 << exp;                                                  \
        إذا (exp > DOUBLE_FRAC_BITS - 32) {                                   \
            عالي_shift = exp - (DOUBLE_FRAC_BITS - 32);                      \
            ret.أدنى |= val.عالي << عالي_shift;                               \
            ret.أدنى |= val.أدنى >> (32 - عالي_shift);                         \
        } وإلا                                                               \
            ret.أدنى |= val.عالي >> (DOUBLE_FRAC_BITS - 32 - exp);            \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    إذا (with_sign && sign) {                                                 \
        ret.أدنى = ~ret.أدنى;                                                  \
        ret.عالي = ~ret.عالي;                                                \
        إذا (ret.أدنى == UINT_MAX) {                                           \
            ret.أدنى = 0;                                                     \
            ret.عالي++;                                                      \
        } وإلا                                                               \
            ret.أدنى++;                                                       \
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
    صحيح s /* shift */, flb /* first lost bit */, sign = 0;              \
    unsigned p = 0 /* power */, ret;                                    \
    double_unsigned_struct val;                                         \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    إذا (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.أدنى = v;                                                        \
    val.عالي = v >> 32;                                                 \
    /* fill fraction bits */                                            \
    لكل (s = 31, p = 1 << 31; p && !(val.عالي & p); s--, p >>= 1);      \
    إذا (p) {                                                            \
        ret = val.عالي & (p - 1);                                       \
        إذا (s < FLOAT_FRAC_BITS) {                                      \
            ret <<= FLOAT_FRAC_BITS - s;                                \
            ret |= val.أدنى >> (32 - (FLOAT_FRAC_BITS - s));             \
            flb = (val.أدنى >> (32 - (FLOAT_FRAC_BITS - s - 1))) & 1;    \
        } وإلا {                                                        \
            flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;               \
            ret >>= s - FLOAT_FRAC_BITS;                                \
        }                                                               \
        s += 32;                                                        \
    } وإلا {                                                            \
        لكل (s = 31, p = 1 << 31; p && !(val.أدنى & p); s--, p >>= 1);   \
        إذا (p) {                                                        \
            ret = val.أدنى & (p - 1);                                    \
            إذا (s <= FLOAT_FRAC_BITS) {                                 \
                ret <<= FLOAT_FRAC_BITS - s;                            \
                flb = 0;                                                \
	    } وإلا {                                                    \
                flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;           \
                ret >>= s - FLOAT_FRAC_BITS;                            \
	    }                                                           \
        } وإلا                                                          \
            أرجع 0;                                                   \
    }                                                                   \
    إذا (flb)                                                            \
        ret++;                                                          \
                                                                        \
    /* fill exponent bits */                                            \
    ret |= (s + ONE_EXP(FLOAT)) << FLOAT_FRAC_BITS;                     \
                                                                        \
    /* fill sign bit */                                                 \
    ret |= sign << 31;                                                  \
                                                                        \
    أرجع ret;                                                         \
}

/* unsigned long long to float conversion */
DEFINE__AEABI_XL2F(ul2f, 0)

/* long long to float conversion */
DEFINE__AEABI_XL2F(l2f, 1)

/* long long to double conversion */
#define __AEABI_XL2D(name, with_sign)                                   \
فراغ __aeabi_ ## name(unsigned long long v)                             \
{                                                                       \
    صحيح s /* shift */, عالي_shift, sign = 0;                            \
    unsigned tmp, p = 0;                                                \
    double_unsigned_struct val, ret;                                    \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    إذا (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.أدنى = v;                                                        \
    val.عالي = v >> 32;                                                 \
                                                                        \
    /* fill fraction bits */                                            \
    لكل (s = 31, p = 1 << 31; p && !(val.عالي & p); s--, p >>= 1);      \
    إذا (p) {                                                            \
        tmp = val.عالي & (p - 1);                                       \
        إذا (s < DOUBLE_FRAC_BITS - 32) {                                \
            عالي_shift = DOUBLE_FRAC_BITS - 32 - s;                     \
            ret.عالي = tmp << عالي_shift;                               \
            ret.عالي |= val.أدنى >> (32 - عالي_shift);                   \
            ret.أدنى = val.أدنى << عالي_shift;                            \
        } وإلا {                                                        \
            عالي_shift = s - (DOUBLE_FRAC_BITS - 32);                   \
            ret.عالي = tmp >> عالي_shift;                               \
            ret.أدنى = tmp << (32 - عالي_shift);                         \
            ret.أدنى |= val.أدنى >> عالي_shift;                           \
            إذا ((val.أدنى >> (عالي_shift - 1)) & 1) {                    \
                إذا (ret.أدنى == UINT_MAX) {                              \
                    ret.عالي++;                                         \
                    ret.أدنى = 0;                                        \
		} وإلا                                                  \
                    ret.أدنى++;                                          \
            }                                                           \
        }                                                               \
        s += 32;                                                        \
    } وإلا {                                                            \
        لكل (s = 31, p = 1 << 31; p && !(val.أدنى & p); s--, p >>= 1);   \
        إذا (p) {                                                        \
            tmp = val.أدنى & (p - 1);                                    \
            إذا (s <= DOUBLE_FRAC_BITS - 32) {                           \
                عالي_shift = DOUBLE_FRAC_BITS - 32 - s;                 \
                ret.عالي = tmp << عالي_shift;                           \
                ret.أدنى = 0;                                            \
	    } وإلا {                                                    \
                عالي_shift = s - (DOUBLE_FRAC_BITS - 32);               \
                ret.عالي = tmp >> عالي_shift;                           \
                ret.أدنى = tmp << (32 - عالي_shift);                     \
            }                                                           \
        } وإلا {                                                        \
            ret.عالي = ret.أدنى = 0;                                     \
            اذهب _ret_;                                                 \
        }                                                               \
    }                                                                   \
                                                                        \
    /* fill exponent bits */                                            \
    ret.عالي |= (s + ONE_EXP(DOUBLE)) << (DOUBLE_FRAC_BITS - 32);       \
                                                                        \
    /* fill sign bit */                                                 \
    ret.عالي |= sign << 31;                                             \
                                                                        \
_ret_:                                                                  \
    double_unsigned_struct_return(ret);                                 \
}

/* unsigned long long to double conversion */
__AEABI_XL2D(ul2d, 0)

/* long long to double conversion */
__AEABI_XL2D(l2d, 1)

#إذا 1
/* Long long helper functions */

/* TODO: add error in case of den == 0 (see §4.3.1 and §4.3.2) */

#define define_aeabi_xdivmod_signed_type(basetype, type) \
تعريفنوع بنية type {                                    \
    basetype quot;                                       \
    unsigned basetype rem;                               \
} type

#define define_aeabi_xdivmod_unsigned_type(basetype, type) \
تعريفنوع بنية type {                                      \
    basetype quot;                                         \
    basetype rem;                                          \
} type

#define AEABI_UXDIVMOD(name,type, rettype, typemacro)                     \
ساكن مضمن rettype aeabi_ ## name (type رقم, type den)                 \
{                                                                         \
    rettype ret;                                                          \
    type quot = 0;                                                        \
                                                                          \
    /* Increase quotient while it is less than numerator */               \
    طالما (رقم >= den) {                                                  \
        type q = 1;                                                       \
                                                                          \
        /* Find closest power of two */                                   \
        طالما ((q << 1) * den <= رقم && q * den <= typemacro ## _MAX / 2) \
            q <<= 1;                                                      \
                                                                          \
        /* Compute difference between current quotient and numerator */   \
        رقم -= q * den;                                                   \
        quot += q;                                                        \
    }                                                                     \
    ret.quot = quot;                                                      \
    ret.rem = رقم;                                                        \
    أرجع ret;                                                           \
}

#define __AEABI_XDIVMOD(name, type, uiname, rettype, urettype, typemacro)     \
فراغ __aeabi_ ## name(type numerator, type denominator)                       \
{                                                                             \
    unsigned type رقم, den;                                                   \
    urettype uxdiv_ret;                                                       \
    rettype ret;                                                              \
                                                                              \
    إذا (numerator >= 0)                                                       \
      رقم = numerator;                                                        \
    وإلا                                                                      \
      رقم = 0 - numerator;                                                    \
    إذا (denominator >= 0)                                                     \
      den = denominator;                                                      \
    وإلا                                                                      \
      den = 0 - denominator;                                                  \
    uxdiv_ret = aeabi_ ## uiname(رقم, den);                                   \
    /* signs differ */                                                        \
    إذا ((numerator & typemacro ## _MIN) != (denominator & typemacro ## _MIN)) \
        ret.quot = 0 - uxdiv_ret.quot;                                        \
    وإلا                                                                      \
        ret.quot = uxdiv_ret.quot;                                            \
    إذا (numerator < 0)                                                        \
        ret.rem = 0 - uxdiv_ret.rem;                                          \
    وإلا                                                                      \
        ret.rem = uxdiv_ret.rem;                                              \
                                                                              \
    rettype ## _return(ret);                                                  \
}

define_aeabi_xdivmod_signed_type(long long, lldiv_t);
define_aeabi_xdivmod_unsigned_type(unsigned long long, ulldiv_t);
define_aeabi_xdivmod_signed_type(صحيح, idiv_t);
define_aeabi_xdivmod_unsigned_type(unsigned, uidiv_t);

REGS_RETURN(lldiv_t, lldiv_t)
REGS_RETURN(ulldiv_t, ulldiv_t)
REGS_RETURN(idiv_t, idiv_t)
REGS_RETURN(uidiv_t, uidiv_t)

AEABI_UXDIVMOD(uldivmod, unsigned long long, ulldiv_t, ULLONG)

__AEABI_XDIVMOD(ldivmod, long long, uldivmod, lldiv_t, ulldiv_t, LLONG)

فراغ __aeabi_uldivmod(unsigned long long رقم, unsigned long long den)
{
    ulldiv_t_return(aeabi_uldivmod(رقم, den));
}

فراغ __aeabi_llsl(double_unsigned_struct val, صحيح shift)
{
    double_unsigned_struct ret;

    إذا (shift >= 32) {
        val.عالي = val.أدنى;
        val.أدنى = 0;
        shift -= 32;
    }
    إذا (shift > 0) {
        ret.أدنى = val.أدنى << shift;
        ret.عالي = (val.عالي << shift) | (val.أدنى >> (32 - shift));
        double_unsigned_struct_return(ret);
	أرجع;
    }
    double_unsigned_struct_return(val);
}

#define aeabi_lsr(val, shift, fill, type)                          \
    type ## _struct ret;                                           \
                                                                   \
    إذا (shift >= 32) {                                             \
        val.أدنى = val.عالي;                                        \
        val.عالي = fill;                                           \
        shift -= 32;                                               \
    }                                                              \
    إذا (shift > 0) {                                               \
        ret.عالي = val.عالي >> shift;                              \
        ret.أدنى = (val.عالي << (32 - shift)) | (val.أدنى >> shift); \
        type ## _struct_return(ret);                               \
	أرجع;                                                    \
    }                                                              \
    type ## _struct_return(val);

فراغ __aeabi_llsr(double_unsigned_struct val, صحيح shift)
{
    aeabi_lsr(val, shift, 0, double_unsigned);
}

فراغ __aeabi_lasr(unsigned_int_struct val, صحيح shift)
{
    aeabi_lsr(val, shift, val.عالي >> 31, unsigned_int);
}


/* Integer division functions */

#إذا 0 /* very slow */
AEABI_UXDIVMOD(uidivmod, unsigned, uidiv_t, UINT)

صحيح __aeabi_idiv(صحيح numerator, صحيح denominator)
{
    unsigned رقم, den;
    uidiv_t ret;

    إذا (numerator >= 0)
        رقم = numerator;
    وإلا
        رقم = 0 - numerator;
    إذا (denominator >= 0)
        den = denominator;
    وإلا
        den = 0 - denominator;
    ret = aeabi_uidivmod(رقم, den);
    إذا ((numerator & INT_MIN) != (denominator & INT_MIN)) /* signs differ */
        ret.quot *= -1;
    أرجع ret.quot;
}

unsigned __aeabi_uidiv(unsigned رقم, unsigned den)
{
    أرجع aeabi_uidivmod(رقم, den).quot;
}

__AEABI_XDIVMOD(idivmod, صحيح, uidivmod, idiv_t, uidiv_t, INT)

فراغ __aeabi_uidivmod(unsigned رقم, unsigned den)
{
    uidiv_t_return(aeabi_uidivmod(رقم, den));
}
#وإلا
# define UIDIVMOD_ASM 1
#endif

/* Some targets do not have all eabi calls (OpenBSD) */
تعريفنوع __SIZE_TYPE__ size_t;
خارجي فراغ *memcpy(فراغ *dest, ثابت فراغ *src, size_t n);
خارجي فراغ *memmove(فراغ *dest, ثابت فراغ *src, size_t n);
خارجي فراغ *memset(فراغ *s, صحيح c, size_t n);

فراغ *
__aeabi_memcpy (فراغ *dest, ثابت فراغ *src, size_t n)
{
    أرجع memcpy (dest, src, n);
}

فراغ *
__aeabi_memmove (فراغ *dest, ثابت فراغ *src, size_t n)
{
    أرجع memmove (dest, src, n);
}

فراغ *
__aeabi_memmove4 (فراغ *dest, ثابت فراغ *src, size_t n)
{
    أرجع memmove (dest, src, n);
}

فراغ *
__aeabi_memmove8 (فراغ *dest, ثابت فراغ *src, size_t n)
{
    أرجع memmove (dest, src, n);
}

فراغ *
__aeabi_memset (فراغ *s, size_t n, صحيح c)
{
    أرجع memset (s, c, n);
}

/* ***************************************************************** */
#إذا UIDIVMOD_ASM
#ضمن <config.h>
__asm__(
   "\n  .global __aeabi_idiv, __aeabi_idivmod"
   "\n  .global __aeabi_uidiv, __aeabi_uidivmod"
#إذا __ARM_FEATURE_IDIV
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
#وإلا
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
