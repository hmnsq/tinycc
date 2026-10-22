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
#નહીંતર
#અન્તર્ભાવ <limits.h>
#endif

/* We rely on the little endianness and EABI calling convention for this to
   work */

પ્રકારવ્યાખ્યા સંરચના double_unsigned_struct {
    unsigned નીચલું;
    unsigned ઉપલું;
} double_unsigned_struct;

પ્રકારવ્યાખ્યા સંરચના unsigned_int_struct {
    unsigned નીચલું;
    પૂર્ણાંક ઉપલું;
} unsigned_int_struct;

#define REGS_RETURN(name, type) \
    સ્થિર શૂન્ય name ## _return(type ret) {}


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
શૂન્ય __aeabi_ ## name(unsigned val)                                          \
{                                                                            \
    પૂર્ણાંક exp, ઉપલું_shift, sign;                                               \
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
    જો (with_sign) {                                                         \
        જો (exp > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            પાછા;                                                          \
    } નહીંતર {                                                                 \
        જો ((sign && exp >= 0) || exp > 63) /* if val < 0 || val too big */  \
            પાછા;                                                          \
    }                                                                        \
                                                                             \
    val &= (1 << FLOAT_FRAC_BITS) - 1;                                       \
    જો (exp >= 32) {                                                         \
        ret.ઉપલું = 1 << (exp - 32);                                          \
        જો (exp - 32 >= FLOAT_FRAC_BITS) {                                   \
            ret.ઉપલું |= val << (exp - 32 - FLOAT_FRAC_BITS);                 \
            ret.નીચલું = 0;                                                     \
        } નહીંતર {                                                             \
            ઉપલું_shift = FLOAT_FRAC_BITS - (exp - 32);                       \
            ret.ઉપલું |= val >> ઉપલું_shift;                                   \
            ret.નીચલું = val << (32 - ઉપલું_shift);                              \
        }                                                                    \
    } નહીંતર {                                                                 \
        ret.ઉપલું = 0;                                                        \
        ret.નીચલું = 1 << exp;                                                  \
        જો (exp > FLOAT_FRAC_BITS)                                           \
            ret.નીચલું |= val << (exp - FLOAT_FRAC_BITS);                       \
        નહીંતર                                                                 \
            ret.નીચલું |= val >> (FLOAT_FRAC_BITS - exp);                       \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    જો (with_sign && sign) {                                                 \
        ret.નીચલું = ~ret.નીચલું;                                                  \
        ret.ઉપલું = ~ret.ઉપલું;                                                \
        જો (ret.નીચલું == UINT_MAX) {                                           \
            ret.નીચલું = 0;                                                     \
            ret.ઉપલું++;                                                      \
        } નહીંતર                                                               \
            ret.નીચલું++;                                                       \
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
શૂન્ય __aeabi_ ## name(double_unsigned_struct val)                            \
{                                                                            \
    પૂર્ણાંક exp, ઉપલું_shift, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    જો ((val.ઉપલું & ~0x80000000) == 0 && val.નીચલું == 0) {                     \
        ret.નીચલું = ret.ઉપલું = 0;                                              \
        જાઓ _ret_;                                                          \
    }                                                                        \
                                                                             \
    /* compute sign */                                                       \
    sign = val.ઉપલું >> 31;                                                   \
                                                                             \
    /* compute real exponent */                                              \
    exp = (val.ઉપલું >> (DOUBLE_FRAC_BITS - 32));                             \
    exp &= (1 << DOUBLE_EXP_BITS) - 1;                                       \
    exp -= ONE_EXP(DOUBLE);                                                  \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    જો (with_sign) {                                                         \
        જો (exp > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            પાછા;                                                          \
    } નહીંતર {                                                                 \
        જો ((sign && exp >= 0) || exp > 63) /* if val < 0 || val too big */  \
            પાછા;                                                          \
    }                                                                        \
                                                                             \
    val.ઉપલું &= (1 << (DOUBLE_FRAC_BITS - 32)) - 1;                          \
    જો (exp >= 32) {                                                         \
        ret.ઉપલું = 1 << (exp - 32);                                          \
        જો (exp >= DOUBLE_FRAC_BITS) {                                       \
            ઉપલું_shift = exp - DOUBLE_FRAC_BITS;                             \
            ret.ઉપલું |= val.ઉપલું << ઉપલું_shift;                              \
            ret.ઉપલું |= val.નીચલું >> (32 - ઉપલું_shift);                        \
            ret.નીચલું = val.નીચલું << ઉપલું_shift;                                 \
        } નહીંતર {                                                             \
            ઉપલું_shift = DOUBLE_FRAC_BITS - exp;                             \
            ret.ઉપલું |= val.ઉપલું >> ઉપલું_shift;                              \
            ret.નીચલું = val.ઉપલું << (32 - ઉપલું_shift);                         \
            ret.નીચલું |= val.નીચલું >> ઉપલું_shift;                                \
        }                                                                    \
    } નહીંતર {                                                                 \
        ret.ઉપલું = 0;                                                        \
        ret.નીચલું = 1 << exp;                                                  \
        જો (exp > DOUBLE_FRAC_BITS - 32) {                                   \
            ઉપલું_shift = exp - (DOUBLE_FRAC_BITS - 32);                      \
            ret.નીચલું |= val.ઉપલું << ઉપલું_shift;                               \
            ret.નીચલું |= val.નીચલું >> (32 - ઉપલું_shift);                         \
        } નહીંતર                                                               \
            ret.નીચલું |= val.ઉપલું >> (DOUBLE_FRAC_BITS - 32 - exp);            \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    જો (with_sign && sign) {                                                 \
        ret.નીચલું = ~ret.નીચલું;                                                  \
        ret.ઉપલું = ~ret.ઉપલું;                                                \
        જો (ret.નીચલું == UINT_MAX) {                                           \
            ret.નીચલું = 0;                                                     \
            ret.ઉપલું++;                                                      \
        } નહીંતર                                                               \
            ret.નીચલું++;                                                       \
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
    પૂર્ણાંક s /* shift */, flb /* first lost bit */, sign = 0;              \
    unsigned p = 0 /* power */, ret;                                    \
    double_unsigned_struct val;                                         \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    જો (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.નીચલું = v;                                                        \
    val.ઉપલું = v >> 32;                                                 \
    /* fill fraction bits */                                            \
    માટે (s = 31, p = 1 << 31; p && !(val.ઉપલું & p); s--, p >>= 1);      \
    જો (p) {                                                            \
        ret = val.ઉપલું & (p - 1);                                       \
        જો (s < FLOAT_FRAC_BITS) {                                      \
            ret <<= FLOAT_FRAC_BITS - s;                                \
            ret |= val.નીચલું >> (32 - (FLOAT_FRAC_BITS - s));             \
            flb = (val.નીચલું >> (32 - (FLOAT_FRAC_BITS - s - 1))) & 1;    \
        } નહીંતર {                                                        \
            flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;               \
            ret >>= s - FLOAT_FRAC_BITS;                                \
        }                                                               \
        s += 32;                                                        \
    } નહીંતર {                                                            \
        માટે (s = 31, p = 1 << 31; p && !(val.નીચલું & p); s--, p >>= 1);   \
        જો (p) {                                                        \
            ret = val.નીચલું & (p - 1);                                    \
            જો (s <= FLOAT_FRAC_BITS) {                                 \
                ret <<= FLOAT_FRAC_BITS - s;                            \
                flb = 0;                                                \
	    } નહીંતર {                                                    \
                flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;           \
                ret >>= s - FLOAT_FRAC_BITS;                            \
	    }                                                           \
        } નહીંતર                                                          \
            પાછા 0;                                                   \
    }                                                                   \
    જો (flb)                                                            \
        ret++;                                                          \
                                                                        \
    /* fill exponent bits */                                            \
    ret |= (s + ONE_EXP(FLOAT)) << FLOAT_FRAC_BITS;                     \
                                                                        \
    /* fill sign bit */                                                 \
    ret |= sign << 31;                                                  \
                                                                        \
    પાછા ret;                                                         \
}

/* unsigned long long to float conversion */
DEFINE__AEABI_XL2F(ul2f, 0)

/* long long to float conversion */
DEFINE__AEABI_XL2F(l2f, 1)

/* long long to double conversion */
#define __AEABI_XL2D(name, with_sign)                                   \
શૂન્ય __aeabi_ ## name(unsigned long long v)                             \
{                                                                       \
    પૂર્ણાંક s /* shift */, ઉપલું_shift, sign = 0;                            \
    unsigned tmp, p = 0;                                                \
    double_unsigned_struct val, ret;                                    \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    જો (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.નીચલું = v;                                                        \
    val.ઉપલું = v >> 32;                                                 \
                                                                        \
    /* fill fraction bits */                                            \
    માટે (s = 31, p = 1 << 31; p && !(val.ઉપલું & p); s--, p >>= 1);      \
    જો (p) {                                                            \
        tmp = val.ઉપલું & (p - 1);                                       \
        જો (s < DOUBLE_FRAC_BITS - 32) {                                \
            ઉપલું_shift = DOUBLE_FRAC_BITS - 32 - s;                     \
            ret.ઉપલું = tmp << ઉપલું_shift;                               \
            ret.ઉપલું |= val.નીચલું >> (32 - ઉપલું_shift);                   \
            ret.નીચલું = val.નીચલું << ઉપલું_shift;                            \
        } નહીંતર {                                                        \
            ઉપલું_shift = s - (DOUBLE_FRAC_BITS - 32);                   \
            ret.ઉપલું = tmp >> ઉપલું_shift;                               \
            ret.નીચલું = tmp << (32 - ઉપલું_shift);                         \
            ret.નીચલું |= val.નીચલું >> ઉપલું_shift;                           \
            જો ((val.નીચલું >> (ઉપલું_shift - 1)) & 1) {                    \
                જો (ret.નીચલું == UINT_MAX) {                              \
                    ret.ઉપલું++;                                         \
                    ret.નીચલું = 0;                                        \
		} નહીંતર                                                  \
                    ret.નીચલું++;                                          \
            }                                                           \
        }                                                               \
        s += 32;                                                        \
    } નહીંતર {                                                            \
        માટે (s = 31, p = 1 << 31; p && !(val.નીચલું & p); s--, p >>= 1);   \
        જો (p) {                                                        \
            tmp = val.નીચલું & (p - 1);                                    \
            જો (s <= DOUBLE_FRAC_BITS - 32) {                           \
                ઉપલું_shift = DOUBLE_FRAC_BITS - 32 - s;                 \
                ret.ઉપલું = tmp << ઉપલું_shift;                           \
                ret.નીચલું = 0;                                            \
	    } નહીંતર {                                                    \
                ઉપલું_shift = s - (DOUBLE_FRAC_BITS - 32);               \
                ret.ઉપલું = tmp >> ઉપલું_shift;                           \
                ret.નીચલું = tmp << (32 - ઉપલું_shift);                     \
            }                                                           \
        } નહીંતર {                                                        \
            ret.ઉપલું = ret.નીચલું = 0;                                     \
            જાઓ _ret_;                                                 \
        }                                                               \
    }                                                                   \
                                                                        \
    /* fill exponent bits */                                            \
    ret.ઉપલું |= (s + ONE_EXP(DOUBLE)) << (DOUBLE_FRAC_BITS - 32);       \
                                                                        \
    /* fill sign bit */                                                 \
    ret.ઉપલું |= sign << 31;                                             \
                                                                        \
_ret_:                                                                  \
    double_unsigned_struct_return(ret);                                 \
}

/* unsigned long long to double conversion */
__AEABI_XL2D(ul2d, 0)

/* long long to double conversion */
__AEABI_XL2D(l2d, 1)

#જો 1
/* Long long helper functions */

/* TODO: add error in case of den == 0 (see §4.3.1 and §4.3.2) */

#define define_aeabi_xdivmod_signed_type(basetype, type) \
પ્રકારવ્યાખ્યા સંરચના type {                                    \
    basetype quot;                                       \
    unsigned basetype rem;                               \
} type

#define define_aeabi_xdivmod_unsigned_type(basetype, type) \
પ્રકારવ્યાખ્યા સંરચના type {                                      \
    basetype quot;                                         \
    basetype rem;                                          \
} type

#define AEABI_UXDIVMOD(name,type, rettype, typemacro)                     \
સ્થિર અંતઃરેખ rettype aeabi_ ## name (type અંક, type den)                 \
{                                                                         \
    rettype ret;                                                          \
    type quot = 0;                                                        \
                                                                          \
    /* Increase quotient while it is less than numerator */               \
    જ્યારે (અંક >= den) {                                                  \
        type q = 1;                                                       \
                                                                          \
        /* Find closest power of two */                                   \
        જ્યારે ((q << 1) * den <= અંક && q * den <= typemacro ## _MAX / 2) \
            q <<= 1;                                                      \
                                                                          \
        /* Compute difference between current quotient and numerator */   \
        અંક -= q * den;                                                   \
        quot += q;                                                        \
    }                                                                     \
    ret.quot = quot;                                                      \
    ret.rem = અંક;                                                        \
    પાછા ret;                                                           \
}

#define __AEABI_XDIVMOD(name, type, uiname, rettype, urettype, typemacro)     \
શૂન્ય __aeabi_ ## name(type numerator, type denominator)                       \
{                                                                             \
    unsigned type અંક, den;                                                   \
    urettype uxdiv_ret;                                                       \
    rettype ret;                                                              \
                                                                              \
    જો (numerator >= 0)                                                       \
      અંક = numerator;                                                        \
    નહીંતર                                                                      \
      અંક = 0 - numerator;                                                    \
    જો (denominator >= 0)                                                     \
      den = denominator;                                                      \
    નહીંતર                                                                      \
      den = 0 - denominator;                                                  \
    uxdiv_ret = aeabi_ ## uiname(અંક, den);                                   \
    /* signs differ */                                                        \
    જો ((numerator & typemacro ## _MIN) != (denominator & typemacro ## _MIN)) \
        ret.quot = 0 - uxdiv_ret.quot;                                        \
    નહીંતર                                                                      \
        ret.quot = uxdiv_ret.quot;                                            \
    જો (numerator < 0)                                                        \
        ret.rem = 0 - uxdiv_ret.rem;                                          \
    નહીંતર                                                                      \
        ret.rem = uxdiv_ret.rem;                                              \
                                                                              \
    rettype ## _return(ret);                                                  \
}

define_aeabi_xdivmod_signed_type(long long, lldiv_t);
define_aeabi_xdivmod_unsigned_type(unsigned long long, ulldiv_t);
define_aeabi_xdivmod_signed_type(પૂર્ણાંક, idiv_t);
define_aeabi_xdivmod_unsigned_type(unsigned, uidiv_t);

REGS_RETURN(lldiv_t, lldiv_t)
REGS_RETURN(ulldiv_t, ulldiv_t)
REGS_RETURN(idiv_t, idiv_t)
REGS_RETURN(uidiv_t, uidiv_t)

AEABI_UXDIVMOD(uldivmod, unsigned long long, ulldiv_t, ULLONG)

__AEABI_XDIVMOD(ldivmod, long long, uldivmod, lldiv_t, ulldiv_t, LLONG)

શૂન્ય __aeabi_uldivmod(unsigned long long અંક, unsigned long long den)
{
    ulldiv_t_return(aeabi_uldivmod(અંક, den));
}

શૂન્ય __aeabi_llsl(double_unsigned_struct val, પૂર્ણાંક shift)
{
    double_unsigned_struct ret;

    જો (shift >= 32) {
        val.ઉપલું = val.નીચલું;
        val.નીચલું = 0;
        shift -= 32;
    }
    જો (shift > 0) {
        ret.નીચલું = val.નીચલું << shift;
        ret.ઉપલું = (val.ઉપલું << shift) | (val.નીચલું >> (32 - shift));
        double_unsigned_struct_return(ret);
	પાછા;
    }
    double_unsigned_struct_return(val);
}

#define aeabi_lsr(val, shift, fill, type)                          \
    type ## _struct ret;                                           \
                                                                   \
    જો (shift >= 32) {                                             \
        val.નીચલું = val.ઉપલું;                                        \
        val.ઉપલું = fill;                                           \
        shift -= 32;                                               \
    }                                                              \
    જો (shift > 0) {                                               \
        ret.ઉપલું = val.ઉપલું >> shift;                              \
        ret.નીચલું = (val.ઉપલું << (32 - shift)) | (val.નીચલું >> shift); \
        type ## _struct_return(ret);                               \
	પાછા;                                                    \
    }                                                              \
    type ## _struct_return(val);

શૂન્ય __aeabi_llsr(double_unsigned_struct val, પૂર્ણાંક shift)
{
    aeabi_lsr(val, shift, 0, double_unsigned);
}

શૂન્ય __aeabi_lasr(unsigned_int_struct val, પૂર્ણાંક shift)
{
    aeabi_lsr(val, shift, val.ઉપલું >> 31, unsigned_int);
}


/* Integer division functions */

#જો 0 /* very slow */
AEABI_UXDIVMOD(uidivmod, unsigned, uidiv_t, UINT)

પૂર્ણાંક __aeabi_idiv(પૂર્ણાંક numerator, પૂર્ણાંક denominator)
{
    unsigned અંક, den;
    uidiv_t ret;

    જો (numerator >= 0)
        અંક = numerator;
    નહીંતર
        અંક = 0 - numerator;
    જો (denominator >= 0)
        den = denominator;
    નહીંતર
        den = 0 - denominator;
    ret = aeabi_uidivmod(અંક, den);
    જો ((numerator & INT_MIN) != (denominator & INT_MIN)) /* signs differ */
        ret.quot *= -1;
    પાછા ret.quot;
}

unsigned __aeabi_uidiv(unsigned અંક, unsigned den)
{
    પાછા aeabi_uidivmod(અંક, den).quot;
}

__AEABI_XDIVMOD(idivmod, પૂર્ણાંક, uidivmod, idiv_t, uidiv_t, INT)

શૂન્ય __aeabi_uidivmod(unsigned અંક, unsigned den)
{
    uidiv_t_return(aeabi_uidivmod(અંક, den));
}
#નહીંતર
# define UIDIVMOD_ASM 1
#endif

/* Some targets do not have all eabi calls (OpenBSD) */
પ્રકારવ્યાખ્યા __SIZE_TYPE__ size_t;
બાહ્ય શૂન્ય *memcpy(શૂન્ય *dest, અચલ શૂન્ય *src, size_t n);
બાહ્ય શૂન્ય *memmove(શૂન્ય *dest, અચલ શૂન્ય *src, size_t n);
બાહ્ય શૂન્ય *memset(શૂન્ય *s, પૂર્ણાંક c, size_t n);

શૂન્ય *
__aeabi_memcpy (શૂન્ય *dest, અચલ શૂન્ય *src, size_t n)
{
    પાછા memcpy (dest, src, n);
}

શૂન્ય *
__aeabi_memmove (શૂન્ય *dest, અચલ શૂન્ય *src, size_t n)
{
    પાછા memmove (dest, src, n);
}

શૂન્ય *
__aeabi_memmove4 (શૂન્ય *dest, અચલ શૂન્ય *src, size_t n)
{
    પાછા memmove (dest, src, n);
}

શૂન્ય *
__aeabi_memmove8 (શૂન્ય *dest, અચલ શૂન્ય *src, size_t n)
{
    પાછા memmove (dest, src, n);
}

શૂન્ય *
__aeabi_memset (શૂન્ય *s, size_t n, પૂર્ણાંક c)
{
    પાછા memset (s, c, n);
}

/* ***************************************************************** */
#જો UIDIVMOD_ASM
#અન્તર્ભાવ <config.h>
__asm__(
   "\n  .global __aeabi_idiv, __aeabi_idivmod"
   "\n  .global __aeabi_uidiv, __aeabi_uidivmod"
#જો __ARM_FEATURE_IDIV
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
#નહીંતર
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
