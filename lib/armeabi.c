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
#وگرنه
#شامل <limits.h>
#endif

/* We rely on the little endianness and EABI calling convention for this to
   work */

تعریفنوع ساختار double_unsigned_struct {
    unsigned کم;
    unsigned بالا;
} double_unsigned_struct;

تعریفنوع ساختار unsigned_int_struct {
    unsigned کم;
    صحیح بالا;
} unsigned_int_struct;

#define REGS_RETURN(name, type) \
    ایستا تهی name ## _return(type ret) {}


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
تهی __aeabi_ ## name(unsigned val)                                          \
{                                                                            \
    صحیح exp, بالا_shift, sign;                                               \
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
    اگر (with_sign) {                                                         \
        اگر (exp > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            بازگشت;                                                          \
    } وگرنه {                                                                 \
        اگر ((sign && exp >= 0) || exp > 63) /* if val < 0 || val too big */  \
            بازگشت;                                                          \
    }                                                                        \
                                                                             \
    val &= (1 << FLOAT_FRAC_BITS) - 1;                                       \
    اگر (exp >= 32) {                                                         \
        ret.بالا = 1 << (exp - 32);                                          \
        اگر (exp - 32 >= FLOAT_FRAC_BITS) {                                   \
            ret.بالا |= val << (exp - 32 - FLOAT_FRAC_BITS);                 \
            ret.کم = 0;                                                     \
        } وگرنه {                                                             \
            بالا_shift = FLOAT_FRAC_BITS - (exp - 32);                       \
            ret.بالا |= val >> بالا_shift;                                   \
            ret.کم = val << (32 - بالا_shift);                              \
        }                                                                    \
    } وگرنه {                                                                 \
        ret.بالا = 0;                                                        \
        ret.کم = 1 << exp;                                                  \
        اگر (exp > FLOAT_FRAC_BITS)                                           \
            ret.کم |= val << (exp - FLOAT_FRAC_BITS);                       \
        وگرنه                                                                 \
            ret.کم |= val >> (FLOAT_FRAC_BITS - exp);                       \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    اگر (with_sign && sign) {                                                 \
        ret.کم = ~ret.کم;                                                  \
        ret.بالا = ~ret.بالا;                                                \
        اگر (ret.کم == UINT_MAX) {                                           \
            ret.کم = 0;                                                     \
            ret.بالا++;                                                      \
        } وگرنه                                                               \
            ret.کم++;                                                       \
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
تهی __aeabi_ ## name(double_unsigned_struct val)                            \
{                                                                            \
    صحیح exp, بالا_shift, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    اگر ((val.بالا & ~0x80000000) == 0 && val.کم == 0) {                     \
        ret.کم = ret.بالا = 0;                                              \
        برو _ret_;                                                          \
    }                                                                        \
                                                                             \
    /* compute sign */                                                       \
    sign = val.بالا >> 31;                                                   \
                                                                             \
    /* compute real exponent */                                              \
    exp = (val.بالا >> (DOUBLE_FRAC_BITS - 32));                             \
    exp &= (1 << DOUBLE_EXP_BITS) - 1;                                       \
    exp -= ONE_EXP(DOUBLE);                                                  \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    اگر (with_sign) {                                                         \
        اگر (exp > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            بازگشت;                                                          \
    } وگرنه {                                                                 \
        اگر ((sign && exp >= 0) || exp > 63) /* if val < 0 || val too big */  \
            بازگشت;                                                          \
    }                                                                        \
                                                                             \
    val.بالا &= (1 << (DOUBLE_FRAC_BITS - 32)) - 1;                          \
    اگر (exp >= 32) {                                                         \
        ret.بالا = 1 << (exp - 32);                                          \
        اگر (exp >= DOUBLE_FRAC_BITS) {                                       \
            بالا_shift = exp - DOUBLE_FRAC_BITS;                             \
            ret.بالا |= val.بالا << بالا_shift;                              \
            ret.بالا |= val.کم >> (32 - بالا_shift);                        \
            ret.کم = val.کم << بالا_shift;                                 \
        } وگرنه {                                                             \
            بالا_shift = DOUBLE_FRAC_BITS - exp;                             \
            ret.بالا |= val.بالا >> بالا_shift;                              \
            ret.کم = val.بالا << (32 - بالا_shift);                         \
            ret.کم |= val.کم >> بالا_shift;                                \
        }                                                                    \
    } وگرنه {                                                                 \
        ret.بالا = 0;                                                        \
        ret.کم = 1 << exp;                                                  \
        اگر (exp > DOUBLE_FRAC_BITS - 32) {                                   \
            بالا_shift = exp - (DOUBLE_FRAC_BITS - 32);                      \
            ret.کم |= val.بالا << بالا_shift;                               \
            ret.کم |= val.کم >> (32 - بالا_shift);                         \
        } وگرنه                                                               \
            ret.کم |= val.بالا >> (DOUBLE_FRAC_BITS - 32 - exp);            \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    اگر (with_sign && sign) {                                                 \
        ret.کم = ~ret.کم;                                                  \
        ret.بالا = ~ret.بالا;                                                \
        اگر (ret.کم == UINT_MAX) {                                           \
            ret.کم = 0;                                                     \
            ret.بالا++;                                                      \
        } وگرنه                                                               \
            ret.کم++;                                                       \
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
    صحیح s /* shift */, flb /* first lost bit */, sign = 0;              \
    unsigned p = 0 /* power */, ret;                                    \
    double_unsigned_struct val;                                         \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    اگر (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.کم = v;                                                        \
    val.بالا = v >> 32;                                                 \
    /* fill fraction bits */                                            \
    برای (s = 31, p = 1 << 31; p && !(val.بالا & p); s--, p >>= 1);      \
    اگر (p) {                                                            \
        ret = val.بالا & (p - 1);                                       \
        اگر (s < FLOAT_FRAC_BITS) {                                      \
            ret <<= FLOAT_FRAC_BITS - s;                                \
            ret |= val.کم >> (32 - (FLOAT_FRAC_BITS - s));             \
            flb = (val.کم >> (32 - (FLOAT_FRAC_BITS - s - 1))) & 1;    \
        } وگرنه {                                                        \
            flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;               \
            ret >>= s - FLOAT_FRAC_BITS;                                \
        }                                                               \
        s += 32;                                                        \
    } وگرنه {                                                            \
        برای (s = 31, p = 1 << 31; p && !(val.کم & p); s--, p >>= 1);   \
        اگر (p) {                                                        \
            ret = val.کم & (p - 1);                                    \
            اگر (s <= FLOAT_FRAC_BITS) {                                 \
                ret <<= FLOAT_FRAC_BITS - s;                            \
                flb = 0;                                                \
	    } وگرنه {                                                    \
                flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;           \
                ret >>= s - FLOAT_FRAC_BITS;                            \
	    }                                                           \
        } وگرنه                                                          \
            بازگشت 0;                                                   \
    }                                                                   \
    اگر (flb)                                                            \
        ret++;                                                          \
                                                                        \
    /* fill exponent bits */                                            \
    ret |= (s + ONE_EXP(FLOAT)) << FLOAT_FRAC_BITS;                     \
                                                                        \
    /* fill sign bit */                                                 \
    ret |= sign << 31;                                                  \
                                                                        \
    بازگشت ret;                                                         \
}

/* unsigned long long to float conversion */
DEFINE__AEABI_XL2F(ul2f, 0)

/* long long to float conversion */
DEFINE__AEABI_XL2F(l2f, 1)

/* long long to double conversion */
#define __AEABI_XL2D(name, with_sign)                                   \
تهی __aeabi_ ## name(unsigned long long v)                             \
{                                                                       \
    صحیح s /* shift */, بالا_shift, sign = 0;                            \
    unsigned tmp, p = 0;                                                \
    double_unsigned_struct val, ret;                                    \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    اگر (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.کم = v;                                                        \
    val.بالا = v >> 32;                                                 \
                                                                        \
    /* fill fraction bits */                                            \
    برای (s = 31, p = 1 << 31; p && !(val.بالا & p); s--, p >>= 1);      \
    اگر (p) {                                                            \
        tmp = val.بالا & (p - 1);                                       \
        اگر (s < DOUBLE_FRAC_BITS - 32) {                                \
            بالا_shift = DOUBLE_FRAC_BITS - 32 - s;                     \
            ret.بالا = tmp << بالا_shift;                               \
            ret.بالا |= val.کم >> (32 - بالا_shift);                   \
            ret.کم = val.کم << بالا_shift;                            \
        } وگرنه {                                                        \
            بالا_shift = s - (DOUBLE_FRAC_BITS - 32);                   \
            ret.بالا = tmp >> بالا_shift;                               \
            ret.کم = tmp << (32 - بالا_shift);                         \
            ret.کم |= val.کم >> بالا_shift;                           \
            اگر ((val.کم >> (بالا_shift - 1)) & 1) {                    \
                اگر (ret.کم == UINT_MAX) {                              \
                    ret.بالا++;                                         \
                    ret.کم = 0;                                        \
		} وگرنه                                                  \
                    ret.کم++;                                          \
            }                                                           \
        }                                                               \
        s += 32;                                                        \
    } وگرنه {                                                            \
        برای (s = 31, p = 1 << 31; p && !(val.کم & p); s--, p >>= 1);   \
        اگر (p) {                                                        \
            tmp = val.کم & (p - 1);                                    \
            اگر (s <= DOUBLE_FRAC_BITS - 32) {                           \
                بالا_shift = DOUBLE_FRAC_BITS - 32 - s;                 \
                ret.بالا = tmp << بالا_shift;                           \
                ret.کم = 0;                                            \
	    } وگرنه {                                                    \
                بالا_shift = s - (DOUBLE_FRAC_BITS - 32);               \
                ret.بالا = tmp >> بالا_shift;                           \
                ret.کم = tmp << (32 - بالا_shift);                     \
            }                                                           \
        } وگرنه {                                                        \
            ret.بالا = ret.کم = 0;                                     \
            برو _ret_;                                                 \
        }                                                               \
    }                                                                   \
                                                                        \
    /* fill exponent bits */                                            \
    ret.بالا |= (s + ONE_EXP(DOUBLE)) << (DOUBLE_FRAC_BITS - 32);       \
                                                                        \
    /* fill sign bit */                                                 \
    ret.بالا |= sign << 31;                                             \
                                                                        \
_ret_:                                                                  \
    double_unsigned_struct_return(ret);                                 \
}

/* unsigned long long to double conversion */
__AEABI_XL2D(ul2d, 0)

/* long long to double conversion */
__AEABI_XL2D(l2d, 1)

#اگر 1
/* Long long helper functions */

/* TODO: add error in case of den == 0 (see §4.3.1 and §4.3.2) */

#define define_aeabi_xdivmod_signed_type(basetype, type) \
تعریفنوع ساختار type {                                    \
    basetype quot;                                       \
    unsigned basetype rem;                               \
} type

#define define_aeabi_xdivmod_unsigned_type(basetype, type) \
تعریفنوع ساختار type {                                      \
    basetype quot;                                         \
    basetype rem;                                          \
} type

#define AEABI_UXDIVMOD(name,type, rettype, typemacro)                     \
ایستا درونخطی rettype aeabi_ ## name (type رقم, type den)                 \
{                                                                         \
    rettype ret;                                                          \
    type quot = 0;                                                        \
                                                                          \
    /* Increase quotient while it is less than numerator */               \
    وقتی (رقم >= den) {                                                  \
        type q = 1;                                                       \
                                                                          \
        /* Find closest power of two */                                   \
        وقتی ((q << 1) * den <= رقم && q * den <= typemacro ## _MAX / 2) \
            q <<= 1;                                                      \
                                                                          \
        /* Compute difference between current quotient and numerator */   \
        رقم -= q * den;                                                   \
        quot += q;                                                        \
    }                                                                     \
    ret.quot = quot;                                                      \
    ret.rem = رقم;                                                        \
    بازگشت ret;                                                           \
}

#define __AEABI_XDIVMOD(name, type, uiname, rettype, urettype, typemacro)     \
تهی __aeabi_ ## name(type numerator, type denominator)                       \
{                                                                             \
    unsigned type رقم, den;                                                   \
    urettype uxdiv_ret;                                                       \
    rettype ret;                                                              \
                                                                              \
    اگر (numerator >= 0)                                                       \
      رقم = numerator;                                                        \
    وگرنه                                                                      \
      رقم = 0 - numerator;                                                    \
    اگر (denominator >= 0)                                                     \
      den = denominator;                                                      \
    وگرنه                                                                      \
      den = 0 - denominator;                                                  \
    uxdiv_ret = aeabi_ ## uiname(رقم, den);                                   \
    /* signs differ */                                                        \
    اگر ((numerator & typemacro ## _MIN) != (denominator & typemacro ## _MIN)) \
        ret.quot = 0 - uxdiv_ret.quot;                                        \
    وگرنه                                                                      \
        ret.quot = uxdiv_ret.quot;                                            \
    اگر (numerator < 0)                                                        \
        ret.rem = 0 - uxdiv_ret.rem;                                          \
    وگرنه                                                                      \
        ret.rem = uxdiv_ret.rem;                                              \
                                                                              \
    rettype ## _return(ret);                                                  \
}

define_aeabi_xdivmod_signed_type(long long, lldiv_t);
define_aeabi_xdivmod_unsigned_type(unsigned long long, ulldiv_t);
define_aeabi_xdivmod_signed_type(صحیح, idiv_t);
define_aeabi_xdivmod_unsigned_type(unsigned, uidiv_t);

REGS_RETURN(lldiv_t, lldiv_t)
REGS_RETURN(ulldiv_t, ulldiv_t)
REGS_RETURN(idiv_t, idiv_t)
REGS_RETURN(uidiv_t, uidiv_t)

AEABI_UXDIVMOD(uldivmod, unsigned long long, ulldiv_t, ULLONG)

__AEABI_XDIVMOD(ldivmod, long long, uldivmod, lldiv_t, ulldiv_t, LLONG)

تهی __aeabi_uldivmod(unsigned long long رقم, unsigned long long den)
{
    ulldiv_t_return(aeabi_uldivmod(رقم, den));
}

تهی __aeabi_llsl(double_unsigned_struct val, صحیح shift)
{
    double_unsigned_struct ret;

    اگر (shift >= 32) {
        val.بالا = val.کم;
        val.کم = 0;
        shift -= 32;
    }
    اگر (shift > 0) {
        ret.کم = val.کم << shift;
        ret.بالا = (val.بالا << shift) | (val.کم >> (32 - shift));
        double_unsigned_struct_return(ret);
	بازگشت;
    }
    double_unsigned_struct_return(val);
}

#define aeabi_lsr(val, shift, fill, type)                          \
    type ## _struct ret;                                           \
                                                                   \
    اگر (shift >= 32) {                                             \
        val.کم = val.بالا;                                        \
        val.بالا = fill;                                           \
        shift -= 32;                                               \
    }                                                              \
    اگر (shift > 0) {                                               \
        ret.بالا = val.بالا >> shift;                              \
        ret.کم = (val.بالا << (32 - shift)) | (val.کم >> shift); \
        type ## _struct_return(ret);                               \
	بازگشت;                                                    \
    }                                                              \
    type ## _struct_return(val);

تهی __aeabi_llsr(double_unsigned_struct val, صحیح shift)
{
    aeabi_lsr(val, shift, 0, double_unsigned);
}

تهی __aeabi_lasr(unsigned_int_struct val, صحیح shift)
{
    aeabi_lsr(val, shift, val.بالا >> 31, unsigned_int);
}


/* Integer division functions */

#اگر 0 /* very slow */
AEABI_UXDIVMOD(uidivmod, unsigned, uidiv_t, UINT)

صحیح __aeabi_idiv(صحیح numerator, صحیح denominator)
{
    unsigned رقم, den;
    uidiv_t ret;

    اگر (numerator >= 0)
        رقم = numerator;
    وگرنه
        رقم = 0 - numerator;
    اگر (denominator >= 0)
        den = denominator;
    وگرنه
        den = 0 - denominator;
    ret = aeabi_uidivmod(رقم, den);
    اگر ((numerator & INT_MIN) != (denominator & INT_MIN)) /* signs differ */
        ret.quot *= -1;
    بازگشت ret.quot;
}

unsigned __aeabi_uidiv(unsigned رقم, unsigned den)
{
    بازگشت aeabi_uidivmod(رقم, den).quot;
}

__AEABI_XDIVMOD(idivmod, صحیح, uidivmod, idiv_t, uidiv_t, INT)

تهی __aeabi_uidivmod(unsigned رقم, unsigned den)
{
    uidiv_t_return(aeabi_uidivmod(رقم, den));
}
#وگرنه
# define UIDIVMOD_ASM 1
#endif

/* Some targets do not have all eabi calls (OpenBSD) */
تعریفنوع __SIZE_TYPE__ size_t;
بیرونی تهی *memcpy(تهی *dest, ثابت تهی *src, size_t n);
بیرونی تهی *memmove(تهی *dest, ثابت تهی *src, size_t n);
بیرونی تهی *memset(تهی *s, صحیح c, size_t n);

تهی *
__aeabi_memcpy (تهی *dest, ثابت تهی *src, size_t n)
{
    بازگشت memcpy (dest, src, n);
}

تهی *
__aeabi_memmove (تهی *dest, ثابت تهی *src, size_t n)
{
    بازگشت memmove (dest, src, n);
}

تهی *
__aeabi_memmove4 (تهی *dest, ثابت تهی *src, size_t n)
{
    بازگشت memmove (dest, src, n);
}

تهی *
__aeabi_memmove8 (تهی *dest, ثابت تهی *src, size_t n)
{
    بازگشت memmove (dest, src, n);
}

تهی *
__aeabi_memset (تهی *s, size_t n, صحیح c)
{
    بازگشت memset (s, c, n);
}

/* ***************************************************************** */
#اگر UIDIVMOD_ASM
#شامل <config.h>
__asm__(
   "\n  .global __aeabi_idiv, __aeabi_idivmod"
   "\n  .global __aeabi_uidiv, __aeabi_uidivmod"
#اگر __ARM_FEATURE_IDIV
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
#وگرنه
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
