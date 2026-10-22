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
#അല്ലെങ്കിൽ
#അന്തര്ഭാവ <limits.h>
#endif

/* We rely on the little endianness and EABI calling convention for this to
   work */

തരനിർവചനം ഘടന double_unsigned_struct {
    unsigned താഴെയുള്ള;
    unsigned മുകളിലെ;
} double_unsigned_struct;

തരനിർവചനം ഘടന unsigned_int_struct {
    unsigned താഴെയുള്ള;
    പൂർണ്ണസംഖ്യ മുകളിലെ;
} unsigned_int_struct;

#define REGS_RETURN(name, type) \
    സ്ഥിതം ശൂന്യം name ## _return(type ret) {}


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
ശൂന്യം __aeabi_ ## name(unsigned val)                                          \
{                                                                            \
    പൂർണ്ണസംഖ്യ exp, മുകളിലെ_shift, sign;                                               \
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
    എങ്കിൽ (with_sign) {                                                         \
        എങ്കിൽ (exp > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            തിരികെ;                                                          \
    } അല്ലെങ്കിൽ {                                                                 \
        എങ്കിൽ ((sign && exp >= 0) || exp > 63) /* if val < 0 || val too big */  \
            തിരികെ;                                                          \
    }                                                                        \
                                                                             \
    val &= (1 << FLOAT_FRAC_BITS) - 1;                                       \
    എങ്കിൽ (exp >= 32) {                                                         \
        ret.മുകളിലെ = 1 << (exp - 32);                                          \
        എങ്കിൽ (exp - 32 >= FLOAT_FRAC_BITS) {                                   \
            ret.മുകളിലെ |= val << (exp - 32 - FLOAT_FRAC_BITS);                 \
            ret.താഴെയുള്ള = 0;                                                     \
        } അല്ലെങ്കിൽ {                                                             \
            മുകളിലെ_shift = FLOAT_FRAC_BITS - (exp - 32);                       \
            ret.മുകളിലെ |= val >> മുകളിലെ_shift;                                   \
            ret.താഴെയുള്ള = val << (32 - മുകളിലെ_shift);                              \
        }                                                                    \
    } അല്ലെങ്കിൽ {                                                                 \
        ret.മുകളിലെ = 0;                                                        \
        ret.താഴെയുള്ള = 1 << exp;                                                  \
        എങ്കിൽ (exp > FLOAT_FRAC_BITS)                                           \
            ret.താഴെയുള്ള |= val << (exp - FLOAT_FRAC_BITS);                       \
        അല്ലെങ്കിൽ                                                                 \
            ret.താഴെയുള്ള |= val >> (FLOAT_FRAC_BITS - exp);                       \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    എങ്കിൽ (with_sign && sign) {                                                 \
        ret.താഴെയുള്ള = ~ret.താഴെയുള്ള;                                                  \
        ret.മുകളിലെ = ~ret.മുകളിലെ;                                                \
        എങ്കിൽ (ret.താഴെയുള്ള == UINT_MAX) {                                           \
            ret.താഴെയുള്ള = 0;                                                     \
            ret.മുകളിലെ++;                                                      \
        } അല്ലെങ്കിൽ                                                               \
            ret.താഴെയുള്ള++;                                                       \
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
ശൂന്യം __aeabi_ ## name(double_unsigned_struct val)                            \
{                                                                            \
    പൂർണ്ണസംഖ്യ exp, മുകളിലെ_shift, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    എങ്കിൽ ((val.മുകളിലെ & ~0x80000000) == 0 && val.താഴെയുള്ള == 0) {                     \
        ret.താഴെയുള്ള = ret.മുകളിലെ = 0;                                              \
        പോകുക _ret_;                                                          \
    }                                                                        \
                                                                             \
    /* compute sign */                                                       \
    sign = val.മുകളിലെ >> 31;                                                   \
                                                                             \
    /* compute real exponent */                                              \
    exp = (val.മുകളിലെ >> (DOUBLE_FRAC_BITS - 32));                             \
    exp &= (1 << DOUBLE_EXP_BITS) - 1;                                       \
    exp -= ONE_EXP(DOUBLE);                                                  \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    എങ്കിൽ (with_sign) {                                                         \
        എങ്കിൽ (exp > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            തിരികെ;                                                          \
    } അല്ലെങ്കിൽ {                                                                 \
        എങ്കിൽ ((sign && exp >= 0) || exp > 63) /* if val < 0 || val too big */  \
            തിരികെ;                                                          \
    }                                                                        \
                                                                             \
    val.മുകളിലെ &= (1 << (DOUBLE_FRAC_BITS - 32)) - 1;                          \
    എങ്കിൽ (exp >= 32) {                                                         \
        ret.മുകളിലെ = 1 << (exp - 32);                                          \
        എങ്കിൽ (exp >= DOUBLE_FRAC_BITS) {                                       \
            മുകളിലെ_shift = exp - DOUBLE_FRAC_BITS;                             \
            ret.മുകളിലെ |= val.മുകളിലെ << മുകളിലെ_shift;                              \
            ret.മുകളിലെ |= val.താഴെയുള്ള >> (32 - മുകളിലെ_shift);                        \
            ret.താഴെയുള്ള = val.താഴെയുള്ള << മുകളിലെ_shift;                                 \
        } അല്ലെങ്കിൽ {                                                             \
            മുകളിലെ_shift = DOUBLE_FRAC_BITS - exp;                             \
            ret.മുകളിലെ |= val.മുകളിലെ >> മുകളിലെ_shift;                              \
            ret.താഴെയുള്ള = val.മുകളിലെ << (32 - മുകളിലെ_shift);                         \
            ret.താഴെയുള്ള |= val.താഴെയുള്ള >> മുകളിലെ_shift;                                \
        }                                                                    \
    } അല്ലെങ്കിൽ {                                                                 \
        ret.മുകളിലെ = 0;                                                        \
        ret.താഴെയുള്ള = 1 << exp;                                                  \
        എങ്കിൽ (exp > DOUBLE_FRAC_BITS - 32) {                                   \
            മുകളിലെ_shift = exp - (DOUBLE_FRAC_BITS - 32);                      \
            ret.താഴെയുള്ള |= val.മുകളിലെ << മുകളിലെ_shift;                               \
            ret.താഴെയുള്ള |= val.താഴെയുള്ള >> (32 - മുകളിലെ_shift);                         \
        } അല്ലെങ്കിൽ                                                               \
            ret.താഴെയുള്ള |= val.മുകളിലെ >> (DOUBLE_FRAC_BITS - 32 - exp);            \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    എങ്കിൽ (with_sign && sign) {                                                 \
        ret.താഴെയുള്ള = ~ret.താഴെയുള്ള;                                                  \
        ret.മുകളിലെ = ~ret.മുകളിലെ;                                                \
        എങ്കിൽ (ret.താഴെയുള്ള == UINT_MAX) {                                           \
            ret.താഴെയുള്ള = 0;                                                     \
            ret.മുകളിലെ++;                                                      \
        } അല്ലെങ്കിൽ                                                               \
            ret.താഴെയുള്ള++;                                                       \
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
    പൂർണ്ണസംഖ്യ s /* shift */, flb /* first lost bit */, sign = 0;              \
    unsigned p = 0 /* power */, ret;                                    \
    double_unsigned_struct val;                                         \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    എങ്കിൽ (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.താഴെയുള്ള = v;                                                        \
    val.മുകളിലെ = v >> 32;                                                 \
    /* fill fraction bits */                                            \
    വേണ്ടി (s = 31, p = 1 << 31; p && !(val.മുകളിലെ & p); s--, p >>= 1);      \
    എങ്കിൽ (p) {                                                            \
        ret = val.മുകളിലെ & (p - 1);                                       \
        എങ്കിൽ (s < FLOAT_FRAC_BITS) {                                      \
            ret <<= FLOAT_FRAC_BITS - s;                                \
            ret |= val.താഴെയുള്ള >> (32 - (FLOAT_FRAC_BITS - s));             \
            flb = (val.താഴെയുള്ള >> (32 - (FLOAT_FRAC_BITS - s - 1))) & 1;    \
        } അല്ലെങ്കിൽ {                                                        \
            flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;               \
            ret >>= s - FLOAT_FRAC_BITS;                                \
        }                                                               \
        s += 32;                                                        \
    } അല്ലെങ്കിൽ {                                                            \
        വേണ്ടി (s = 31, p = 1 << 31; p && !(val.താഴെയുള്ള & p); s--, p >>= 1);   \
        എങ്കിൽ (p) {                                                        \
            ret = val.താഴെയുള്ള & (p - 1);                                    \
            എങ്കിൽ (s <= FLOAT_FRAC_BITS) {                                 \
                ret <<= FLOAT_FRAC_BITS - s;                            \
                flb = 0;                                                \
	    } അല്ലെങ്കിൽ {                                                    \
                flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;           \
                ret >>= s - FLOAT_FRAC_BITS;                            \
	    }                                                           \
        } അല്ലെങ്കിൽ                                                          \
            തിരികെ 0;                                                   \
    }                                                                   \
    എങ്കിൽ (flb)                                                            \
        ret++;                                                          \
                                                                        \
    /* fill exponent bits */                                            \
    ret |= (s + ONE_EXP(FLOAT)) << FLOAT_FRAC_BITS;                     \
                                                                        \
    /* fill sign bit */                                                 \
    ret |= sign << 31;                                                  \
                                                                        \
    തിരികെ ret;                                                         \
}

/* unsigned long long to float conversion */
DEFINE__AEABI_XL2F(ul2f, 0)

/* long long to float conversion */
DEFINE__AEABI_XL2F(l2f, 1)

/* long long to double conversion */
#define __AEABI_XL2D(name, with_sign)                                   \
ശൂന്യം __aeabi_ ## name(unsigned long long v)                             \
{                                                                       \
    പൂർണ്ണസംഖ്യ s /* shift */, മുകളിലെ_shift, sign = 0;                            \
    unsigned tmp, p = 0;                                                \
    double_unsigned_struct val, ret;                                    \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    എങ്കിൽ (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.താഴെയുള്ള = v;                                                        \
    val.മുകളിലെ = v >> 32;                                                 \
                                                                        \
    /* fill fraction bits */                                            \
    വേണ്ടി (s = 31, p = 1 << 31; p && !(val.മുകളിലെ & p); s--, p >>= 1);      \
    എങ്കിൽ (p) {                                                            \
        tmp = val.മുകളിലെ & (p - 1);                                       \
        എങ്കിൽ (s < DOUBLE_FRAC_BITS - 32) {                                \
            മുകളിലെ_shift = DOUBLE_FRAC_BITS - 32 - s;                     \
            ret.മുകളിലെ = tmp << മുകളിലെ_shift;                               \
            ret.മുകളിലെ |= val.താഴെയുള്ള >> (32 - മുകളിലെ_shift);                   \
            ret.താഴെയുള്ള = val.താഴെയുള്ള << മുകളിലെ_shift;                            \
        } അല്ലെങ്കിൽ {                                                        \
            മുകളിലെ_shift = s - (DOUBLE_FRAC_BITS - 32);                   \
            ret.മുകളിലെ = tmp >> മുകളിലെ_shift;                               \
            ret.താഴെയുള്ള = tmp << (32 - മുകളിലെ_shift);                         \
            ret.താഴെയുള്ള |= val.താഴെയുള്ള >> മുകളിലെ_shift;                           \
            എങ്കിൽ ((val.താഴെയുള്ള >> (മുകളിലെ_shift - 1)) & 1) {                    \
                എങ്കിൽ (ret.താഴെയുള്ള == UINT_MAX) {                              \
                    ret.മുകളിലെ++;                                         \
                    ret.താഴെയുള്ള = 0;                                        \
		} അല്ലെങ്കിൽ                                                  \
                    ret.താഴെയുള്ള++;                                          \
            }                                                           \
        }                                                               \
        s += 32;                                                        \
    } അല്ലെങ്കിൽ {                                                            \
        വേണ്ടി (s = 31, p = 1 << 31; p && !(val.താഴെയുള്ള & p); s--, p >>= 1);   \
        എങ്കിൽ (p) {                                                        \
            tmp = val.താഴെയുള്ള & (p - 1);                                    \
            എങ്കിൽ (s <= DOUBLE_FRAC_BITS - 32) {                           \
                മുകളിലെ_shift = DOUBLE_FRAC_BITS - 32 - s;                 \
                ret.മുകളിലെ = tmp << മുകളിലെ_shift;                           \
                ret.താഴെയുള്ള = 0;                                            \
	    } അല്ലെങ്കിൽ {                                                    \
                മുകളിലെ_shift = s - (DOUBLE_FRAC_BITS - 32);               \
                ret.മുകളിലെ = tmp >> മുകളിലെ_shift;                           \
                ret.താഴെയുള്ള = tmp << (32 - മുകളിലെ_shift);                     \
            }                                                           \
        } അല്ലെങ്കിൽ {                                                        \
            ret.മുകളിലെ = ret.താഴെയുള്ള = 0;                                     \
            പോകുക _ret_;                                                 \
        }                                                               \
    }                                                                   \
                                                                        \
    /* fill exponent bits */                                            \
    ret.മുകളിലെ |= (s + ONE_EXP(DOUBLE)) << (DOUBLE_FRAC_BITS - 32);       \
                                                                        \
    /* fill sign bit */                                                 \
    ret.മുകളിലെ |= sign << 31;                                             \
                                                                        \
_ret_:                                                                  \
    double_unsigned_struct_return(ret);                                 \
}

/* unsigned long long to double conversion */
__AEABI_XL2D(ul2d, 0)

/* long long to double conversion */
__AEABI_XL2D(l2d, 1)

#എങ്കിൽ 1
/* Long long helper functions */

/* TODO: add error in case of den == 0 (see §4.3.1 and §4.3.2) */

#define define_aeabi_xdivmod_signed_type(basetype, type) \
തരനിർവചനം ഘടന type {                                    \
    basetype quot;                                       \
    unsigned basetype rem;                               \
} type

#define define_aeabi_xdivmod_unsigned_type(basetype, type) \
തരനിർവചനം ഘടന type {                                      \
    basetype quot;                                         \
    basetype rem;                                          \
} type

#define AEABI_UXDIVMOD(name,type, rettype, typemacro)                     \
സ്ഥിതം വരിയിൽ rettype aeabi_ ## name (type അക്കം, type den)                 \
{                                                                         \
    rettype ret;                                                          \
    type quot = 0;                                                        \
                                                                          \
    /* Increase quotient while it is less than numerator */               \
    ആകുമ്പോൾ (അക്കം >= den) {                                                  \
        type q = 1;                                                       \
                                                                          \
        /* Find closest power of two */                                   \
        ആകുമ്പോൾ ((q << 1) * den <= അക്കം && q * den <= typemacro ## _MAX / 2) \
            q <<= 1;                                                      \
                                                                          \
        /* Compute difference between current quotient and numerator */   \
        അക്കം -= q * den;                                                   \
        quot += q;                                                        \
    }                                                                     \
    ret.quot = quot;                                                      \
    ret.rem = അക്കം;                                                        \
    തിരികെ ret;                                                           \
}

#define __AEABI_XDIVMOD(name, type, uiname, rettype, urettype, typemacro)     \
ശൂന്യം __aeabi_ ## name(type numerator, type denominator)                       \
{                                                                             \
    unsigned type അക്കം, den;                                                   \
    urettype uxdiv_ret;                                                       \
    rettype ret;                                                              \
                                                                              \
    എങ്കിൽ (numerator >= 0)                                                       \
      അക്കം = numerator;                                                        \
    അല്ലെങ്കിൽ                                                                      \
      അക്കം = 0 - numerator;                                                    \
    എങ്കിൽ (denominator >= 0)                                                     \
      den = denominator;                                                      \
    അല്ലെങ്കിൽ                                                                      \
      den = 0 - denominator;                                                  \
    uxdiv_ret = aeabi_ ## uiname(അക്കം, den);                                   \
    /* signs differ */                                                        \
    എങ്കിൽ ((numerator & typemacro ## _MIN) != (denominator & typemacro ## _MIN)) \
        ret.quot = 0 - uxdiv_ret.quot;                                        \
    അല്ലെങ്കിൽ                                                                      \
        ret.quot = uxdiv_ret.quot;                                            \
    എങ്കിൽ (numerator < 0)                                                        \
        ret.rem = 0 - uxdiv_ret.rem;                                          \
    അല്ലെങ്കിൽ                                                                      \
        ret.rem = uxdiv_ret.rem;                                              \
                                                                              \
    rettype ## _return(ret);                                                  \
}

define_aeabi_xdivmod_signed_type(long long, lldiv_t);
define_aeabi_xdivmod_unsigned_type(unsigned long long, ulldiv_t);
define_aeabi_xdivmod_signed_type(പൂർണ്ണസംഖ്യ, idiv_t);
define_aeabi_xdivmod_unsigned_type(unsigned, uidiv_t);

REGS_RETURN(lldiv_t, lldiv_t)
REGS_RETURN(ulldiv_t, ulldiv_t)
REGS_RETURN(idiv_t, idiv_t)
REGS_RETURN(uidiv_t, uidiv_t)

AEABI_UXDIVMOD(uldivmod, unsigned long long, ulldiv_t, ULLONG)

__AEABI_XDIVMOD(ldivmod, long long, uldivmod, lldiv_t, ulldiv_t, LLONG)

ശൂന്യം __aeabi_uldivmod(unsigned long long അക്കം, unsigned long long den)
{
    ulldiv_t_return(aeabi_uldivmod(അക്കം, den));
}

ശൂന്യം __aeabi_llsl(double_unsigned_struct val, പൂർണ്ണസംഖ്യ shift)
{
    double_unsigned_struct ret;

    എങ്കിൽ (shift >= 32) {
        val.മുകളിലെ = val.താഴെയുള്ള;
        val.താഴെയുള്ള = 0;
        shift -= 32;
    }
    എങ്കിൽ (shift > 0) {
        ret.താഴെയുള്ള = val.താഴെയുള്ള << shift;
        ret.മുകളിലെ = (val.മുകളിലെ << shift) | (val.താഴെയുള്ള >> (32 - shift));
        double_unsigned_struct_return(ret);
	തിരികെ;
    }
    double_unsigned_struct_return(val);
}

#define aeabi_lsr(val, shift, fill, type)                          \
    type ## _struct ret;                                           \
                                                                   \
    എങ്കിൽ (shift >= 32) {                                             \
        val.താഴെയുള്ള = val.മുകളിലെ;                                        \
        val.മുകളിലെ = fill;                                           \
        shift -= 32;                                               \
    }                                                              \
    എങ്കിൽ (shift > 0) {                                               \
        ret.മുകളിലെ = val.മുകളിലെ >> shift;                              \
        ret.താഴെയുള്ള = (val.മുകളിലെ << (32 - shift)) | (val.താഴെയുള്ള >> shift); \
        type ## _struct_return(ret);                               \
	തിരികെ;                                                    \
    }                                                              \
    type ## _struct_return(val);

ശൂന്യം __aeabi_llsr(double_unsigned_struct val, പൂർണ്ണസംഖ്യ shift)
{
    aeabi_lsr(val, shift, 0, double_unsigned);
}

ശൂന്യം __aeabi_lasr(unsigned_int_struct val, പൂർണ്ണസംഖ്യ shift)
{
    aeabi_lsr(val, shift, val.മുകളിലെ >> 31, unsigned_int);
}


/* Integer division functions */

#എങ്കിൽ 0 /* very slow */
AEABI_UXDIVMOD(uidivmod, unsigned, uidiv_t, UINT)

പൂർണ്ണസംഖ്യ __aeabi_idiv(പൂർണ്ണസംഖ്യ numerator, പൂർണ്ണസംഖ്യ denominator)
{
    unsigned അക്കം, den;
    uidiv_t ret;

    എങ്കിൽ (numerator >= 0)
        അക്കം = numerator;
    അല്ലെങ്കിൽ
        അക്കം = 0 - numerator;
    എങ്കിൽ (denominator >= 0)
        den = denominator;
    അല്ലെങ്കിൽ
        den = 0 - denominator;
    ret = aeabi_uidivmod(അക്കം, den);
    എങ്കിൽ ((numerator & INT_MIN) != (denominator & INT_MIN)) /* signs differ */
        ret.quot *= -1;
    തിരികെ ret.quot;
}

unsigned __aeabi_uidiv(unsigned അക്കം, unsigned den)
{
    തിരികെ aeabi_uidivmod(അക്കം, den).quot;
}

__AEABI_XDIVMOD(idivmod, പൂർണ്ണസംഖ്യ, uidivmod, idiv_t, uidiv_t, INT)

ശൂന്യം __aeabi_uidivmod(unsigned അക്കം, unsigned den)
{
    uidiv_t_return(aeabi_uidivmod(അക്കം, den));
}
#അല്ലെങ്കിൽ
# define UIDIVMOD_ASM 1
#endif

/* Some targets do not have all eabi calls (OpenBSD) */
തരനിർവചനം __SIZE_TYPE__ size_t;
ബാഹ്യ ശൂന്യം *memcpy(ശൂന്യം *dest, സ്ഥിരം ശൂന്യം *src, size_t n);
ബാഹ്യ ശൂന്യം *memmove(ശൂന്യം *dest, സ്ഥിരം ശൂന്യം *src, size_t n);
ബാഹ്യ ശൂന്യം *memset(ശൂന്യം *s, പൂർണ്ണസംഖ്യ c, size_t n);

ശൂന്യം *
__aeabi_memcpy (ശൂന്യം *dest, സ്ഥിരം ശൂന്യം *src, size_t n)
{
    തിരികെ memcpy (dest, src, n);
}

ശൂന്യം *
__aeabi_memmove (ശൂന്യം *dest, സ്ഥിരം ശൂന്യം *src, size_t n)
{
    തിരികെ memmove (dest, src, n);
}

ശൂന്യം *
__aeabi_memmove4 (ശൂന്യം *dest, സ്ഥിരം ശൂന്യം *src, size_t n)
{
    തിരികെ memmove (dest, src, n);
}

ശൂന്യം *
__aeabi_memmove8 (ശൂന്യം *dest, സ്ഥിരം ശൂന്യം *src, size_t n)
{
    തിരികെ memmove (dest, src, n);
}

ശൂന്യം *
__aeabi_memset (ശൂന്യം *s, size_t n, പൂർണ്ണസംഖ്യ c)
{
    തിരികെ memset (s, c, n);
}

/* ***************************************************************** */
#എങ്കിൽ UIDIVMOD_ASM
#അന്തര്ഭാവ <config.h>
__asm__(
   "\n  .global __aeabi_idiv, __aeabi_idivmod"
   "\n  .global __aeabi_uidiv, __aeabi_uidivmod"
#എങ്കിൽ __ARM_FEATURE_IDIV
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
#അല്ലെങ്കിൽ
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
