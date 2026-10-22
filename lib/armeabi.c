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

#నిర్వచితమైతే __TINYC__
#నిర్వచించు INT_MIN (-2147483647 - 1)
#నిర్వచించు గరిష్ఠ_పూర్ణాంకం 2147483647
#నిర్వచించు UINT_MAX 0xffffffff
#నిర్వచించు LONG_MIN (-2147483647L - 1)
#నిర్వచించు LONG_MAX 2147483647L
#నిర్వచించు ULONG_MAX 0xffffffffUL
#నిర్వచించు LLONG_MAX 9223372036854775807LL
#నిర్వచించు LLONG_MIN (-9223372036854775807LL - 1)
#నిర్వచించు ULLONG_MAX 0xffffffffffffffffULL
#లేకపోతే
#అన్తర్భావ <limits.h>
#అయితే_ముగింపు

/* We rely on the little endianness and EABI calling convention for this to
   work */

రకనిర్వచనం నిర్మాణం double_unsigned_struct {
    గుర్తులేని దిగువ;
    గుర్తులేని ఎగువ;
} double_unsigned_struct;

రకనిర్వచనం నిర్మాణం unsigned_int_struct {
    గుర్తులేని దిగువ;
    పూర్ణాంకం ఎగువ;
} unsigned_int_struct;

#నిర్వచించు REGS_RETURN(name, type) \
    స్థిర శూన్య name ## _return(type ret) {}


/* Float helper functions */

#నిర్వచించు FLOAT_EXP_బిట్లు 8
#నిర్వచించు FLOAT_FRAC_బిట్లు 23

#నిర్వచించు DOUBLE_EXP_బిట్లు 11
#నిర్వచించు DOUBLE_FRAC_బిట్లు 52

#నిర్వచించు ONE_EXP(type) ((1 << (type ## EXP_బిట్లు - 1)) - 1)

REGS_RETURN(unsigned_int_struct, unsigned_int_struct)
REGS_RETURN(double_unsigned_struct, double_unsigned_struct)

/* float -> integer: (sign) 1.fraction x 2^(exponent - exp_for_one) */


/* float to [unsigned] long long conversion */
#నిర్వచించు DEFINE__AEABI_F2XLZ(name, with_sign)                                 \
శూన్య __aeabi_ ## name(గుర్తులేని val)                                          \
{                                                                            \
    పూర్ణాంకం ఘాతాంకం, ఎగువ_జరుపు, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    /* compute sign */                                                       \
    sign = val >> 31;                                                        \
                                                                             \
    /* compute real exponent */                                              \
    ఘాతాంకం = val >> FLOAT_FRAC_బిట్లు;                                            \
    ఘాతాంకం &= (1 << FLOAT_EXP_బిట్లు) - 1;                                        \
    ఘాతాంకం -= ONE_EXP(FLOAT);                                                   \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    ఒకవేళ (with_sign) {                                                         \
        ఒకవేళ (ఘాతాంకం > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            తిరిగి;                                                          \
    } లేకపోతే {                                                                 \
        ఒకవేళ ((sign && ఘాతాంకం >= 0) || ఘాతాంకం > 63) /* if val < 0 || val too big */  \
            తిరిగి;                                                          \
    }                                                                        \
                                                                             \
    val &= (1 << FLOAT_FRAC_బిట్లు) - 1;                                       \
    ఒకవేళ (ఘాతాంకం >= 32) {                                                         \
        ret.ఎగువ = 1 << (ఘాతాంకం - 32);                                          \
        ఒకవేళ (ఘాతాంకం - 32 >= FLOAT_FRAC_బిట్లు) {                                   \
            ret.ఎగువ |= val << (ఘాతాంకం - 32 - FLOAT_FRAC_బిట్లు);                 \
            ret.దిగువ = 0;                                                     \
        } లేకపోతే {                                                             \
            ఎగువ_జరుపు = FLOAT_FRAC_బిట్లు - (ఘాతాంకం - 32);                       \
            ret.ఎగువ |= val >> ఎగువ_జరుపు;                                   \
            ret.దిగువ = val << (32 - ఎగువ_జరుపు);                              \
        }                                                                    \
    } లేకపోతే {                                                                 \
        ret.ఎగువ = 0;                                                        \
        ret.దిగువ = 1 << ఘాతాంకం;                                                  \
        ఒకవేళ (ఘాతాంకం > FLOAT_FRAC_బిట్లు)                                           \
            ret.దిగువ |= val << (ఘాతాంకం - FLOAT_FRAC_బిట్లు);                       \
        లేకపోతే                                                                 \
            ret.దిగువ |= val >> (FLOAT_FRAC_బిట్లు - ఘాతాంకం);                       \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    ఒకవేళ (with_sign && sign) {                                                 \
        ret.దిగువ = ~ret.దిగువ;                                                  \
        ret.ఎగువ = ~ret.ఎగువ;                                                \
        ఒకవేళ (ret.దిగువ == UINT_MAX) {                                           \
            ret.దిగువ = 0;                                                     \
            ret.ఎగువ++;                                                      \
        } లేకపోతే                                                               \
            ret.దిగువ++;                                                       \
    }                                                                        \
                                                                             \
    double_unsigned_struct_return(ret);                                      \
}

/* float to unsigned long long conversion */
DEFINE__AEABI_F2XLZ(f2ulz, 0)

/* float to long long conversion */
DEFINE__AEABI_F2XLZ(f2lz, 1)

/* double to [unsigned] long long conversion */
#నిర్వచించు DEFINE__AEABI_D2XLZ(name, with_sign)                                 \
శూన్య __aeabi_ ## name(double_unsigned_struct val)                            \
{                                                                            \
    పూర్ణాంకం ఘాతాంకం, ఎగువ_జరుపు, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    ఒకవేళ ((val.ఎగువ & ~0x80000000) == 0 && val.దిగువ == 0) {                     \
        ret.దిగువ = ret.ఎగువ = 0;                                              \
        వెళ్ళు _ret_;                                                          \
    }                                                                        \
                                                                             \
    /* compute sign */                                                       \
    sign = val.ఎగువ >> 31;                                                   \
                                                                             \
    /* compute real exponent */                                              \
    ఘాతాంకం = (val.ఎగువ >> (DOUBLE_FRAC_బిట్లు - 32));                             \
    ఘాతాంకం &= (1 << DOUBLE_EXP_బిట్లు) - 1;                                       \
    ఘాతాంకం -= ONE_EXP(DOUBLE);                                                  \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    ఒకవేళ (with_sign) {                                                         \
        ఒకవేళ (ఘాతాంకం > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            తిరిగి;                                                          \
    } లేకపోతే {                                                                 \
        ఒకవేళ ((sign && ఘాతాంకం >= 0) || ఘాతాంకం > 63) /* if val < 0 || val too big */  \
            తిరిగి;                                                          \
    }                                                                        \
                                                                             \
    val.ఎగువ &= (1 << (DOUBLE_FRAC_బిట్లు - 32)) - 1;                          \
    ఒకవేళ (ఘాతాంకం >= 32) {                                                         \
        ret.ఎగువ = 1 << (ఘాతాంకం - 32);                                          \
        ఒకవేళ (ఘాతాంకం >= DOUBLE_FRAC_బిట్లు) {                                       \
            ఎగువ_జరుపు = ఘాతాంకం - DOUBLE_FRAC_బిట్లు;                             \
            ret.ఎగువ |= val.ఎగువ << ఎగువ_జరుపు;                              \
            ret.ఎగువ |= val.దిగువ >> (32 - ఎగువ_జరుపు);                        \
            ret.దిగువ = val.దిగువ << ఎగువ_జరుపు;                                 \
        } లేకపోతే {                                                             \
            ఎగువ_జరుపు = DOUBLE_FRAC_బిట్లు - ఘాతాంకం;                             \
            ret.ఎగువ |= val.ఎగువ >> ఎగువ_జరుపు;                              \
            ret.దిగువ = val.ఎగువ << (32 - ఎగువ_జరుపు);                         \
            ret.దిగువ |= val.దిగువ >> ఎగువ_జరుపు;                                \
        }                                                                    \
    } లేకపోతే {                                                                 \
        ret.ఎగువ = 0;                                                        \
        ret.దిగువ = 1 << ఘాతాంకం;                                                  \
        ఒకవేళ (ఘాతాంకం > DOUBLE_FRAC_బిట్లు - 32) {                                   \
            ఎగువ_జరుపు = ఘాతాంకం - (DOUBLE_FRAC_బిట్లు - 32);                      \
            ret.దిగువ |= val.ఎగువ << ఎగువ_జరుపు;                               \
            ret.దిగువ |= val.దిగువ >> (32 - ఎగువ_జరుపు);                         \
        } లేకపోతే                                                               \
            ret.దిగువ |= val.ఎగువ >> (DOUBLE_FRAC_బిట్లు - 32 - ఘాతాంకం);            \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    ఒకవేళ (with_sign && sign) {                                                 \
        ret.దిగువ = ~ret.దిగువ;                                                  \
        ret.ఎగువ = ~ret.ఎగువ;                                                \
        ఒకవేళ (ret.దిగువ == UINT_MAX) {                                           \
            ret.దిగువ = 0;                                                     \
            ret.ఎగువ++;                                                      \
        } లేకపోతే                                                               \
            ret.దిగువ++;                                                       \
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
#నిర్వచించు DEFINE__AEABI_XL2F(name, with_sign)                             \
గుర్తులేని __aeabi_ ## name(గుర్తులేని దీర్ఘ దీర్ఘ v)                         \
{                                                                       \
    పూర్ణాంకం s /*జరుపు*/, flb /* first lost bit */, sign = 0;              \
    గుర్తులేని p = 0 /* power */, ret;                                    \
    double_unsigned_struct val;                                         \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    ఒకవేళ (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.దిగువ = v;                                                        \
    val.ఎగువ = v >> 32;                                                 \
    /* fill fraction bits */                                            \
    కొరకు (s = 31, p = 1 << 31; p && !(val.ఎగువ & p); s--, p >>= 1);      \
    ఒకవేళ (p) {                                                            \
        ret = val.ఎగువ & (p - 1);                                       \
        ఒకవేళ (s < FLOAT_FRAC_బిట్లు) {                                      \
            ret <<= FLOAT_FRAC_బిట్లు - s;                                \
            ret |= val.దిగువ >> (32 - (FLOAT_FRAC_బిట్లు - s));             \
            flb = (val.దిగువ >> (32 - (FLOAT_FRAC_బిట్లు - s - 1))) & 1;    \
        } లేకపోతే {                                                        \
            flb = (ret >> (s - FLOAT_FRAC_బిట్లు - 1)) & 1;               \
            ret >>= s - FLOAT_FRAC_బిట్లు;                                \
        }                                                               \
        s += 32;                                                        \
    } లేకపోతే {                                                            \
        కొరకు (s = 31, p = 1 << 31; p && !(val.దిగువ & p); s--, p >>= 1);   \
        ఒకవేళ (p) {                                                        \
            ret = val.దిగువ & (p - 1);                                    \
            ఒకవేళ (s <= FLOAT_FRAC_బిట్లు) {                                 \
                ret <<= FLOAT_FRAC_బిట్లు - s;                            \
                flb = 0;                                                \
	    } లేకపోతే {                                                    \
                flb = (ret >> (s - FLOAT_FRAC_బిట్లు - 1)) & 1;           \
                ret >>= s - FLOAT_FRAC_బిట్లు;                            \
	    }                                                           \
        } లేకపోతే                                                          \
            తిరిగి 0;                                                   \
    }                                                                   \
    ఒకవేళ (flb)                                                            \
        ret++;                                                          \
                                                                        \
    /* fill exponent bits */                                            \
    ret |= (s + ONE_EXP(FLOAT)) << FLOAT_FRAC_బిట్లు;                     \
                                                                        \
    /* fill sign bit */                                                 \
    ret |= sign << 31;                                                  \
                                                                        \
    తిరిగి ret;                                                         \
}

/* unsigned long long to float conversion */
DEFINE__AEABI_XL2F(ul2f, 0)

/* long long to float conversion */
DEFINE__AEABI_XL2F(l2f, 1)

/* long long to double conversion */
#నిర్వచించు __AEABI_XL2D(name, with_sign)                                   \
శూన్య __aeabi_ ## name(గుర్తులేని దీర్ఘ దీర్ఘ v)                             \
{                                                                       \
    పూర్ణాంకం s /*జరుపు*/, ఎగువ_జరుపు, sign = 0;                            \
    గుర్తులేని tmp, p = 0;                                                \
    double_unsigned_struct val, ret;                                    \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    ఒకవేళ (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.దిగువ = v;                                                        \
    val.ఎగువ = v >> 32;                                                 \
                                                                        \
    /* fill fraction bits */                                            \
    కొరకు (s = 31, p = 1 << 31; p && !(val.ఎగువ & p); s--, p >>= 1);      \
    ఒకవేళ (p) {                                                            \
        tmp = val.ఎగువ & (p - 1);                                       \
        ఒకవేళ (s < DOUBLE_FRAC_బిట్లు - 32) {                                \
            ఎగువ_జరుపు = DOUBLE_FRAC_బిట్లు - 32 - s;                     \
            ret.ఎగువ = tmp << ఎగువ_జరుపు;                               \
            ret.ఎగువ |= val.దిగువ >> (32 - ఎగువ_జరుపు);                   \
            ret.దిగువ = val.దిగువ << ఎగువ_జరుపు;                            \
        } లేకపోతే {                                                        \
            ఎగువ_జరుపు = s - (DOUBLE_FRAC_బిట్లు - 32);                   \
            ret.ఎగువ = tmp >> ఎగువ_జరుపు;                               \
            ret.దిగువ = tmp << (32 - ఎగువ_జరుపు);                         \
            ret.దిగువ |= val.దిగువ >> ఎగువ_జరుపు;                           \
            ఒకవేళ ((val.దిగువ >> (ఎగువ_జరుపు - 1)) & 1) {                    \
                ఒకవేళ (ret.దిగువ == UINT_MAX) {                              \
                    ret.ఎగువ++;                                         \
                    ret.దిగువ = 0;                                        \
		} లేకపోతే                                                  \
                    ret.దిగువ++;                                          \
            }                                                           \
        }                                                               \
        s += 32;                                                        \
    } లేకపోతే {                                                            \
        కొరకు (s = 31, p = 1 << 31; p && !(val.దిగువ & p); s--, p >>= 1);   \
        ఒకవేళ (p) {                                                        \
            tmp = val.దిగువ & (p - 1);                                    \
            ఒకవేళ (s <= DOUBLE_FRAC_బిట్లు - 32) {                           \
                ఎగువ_జరుపు = DOUBLE_FRAC_బిట్లు - 32 - s;                 \
                ret.ఎగువ = tmp << ఎగువ_జరుపు;                           \
                ret.దిగువ = 0;                                            \
	    } లేకపోతే {                                                    \
                ఎగువ_జరుపు = s - (DOUBLE_FRAC_బిట్లు - 32);               \
                ret.ఎగువ = tmp >> ఎగువ_జరుపు;                           \
                ret.దిగువ = tmp << (32 - ఎగువ_జరుపు);                     \
            }                                                           \
        } లేకపోతే {                                                        \
            ret.ఎగువ = ret.దిగువ = 0;                                     \
            వెళ్ళు _ret_;                                                 \
        }                                                               \
    }                                                                   \
                                                                        \
    /* fill exponent bits */                                            \
    ret.ఎగువ |= (s + ONE_EXP(DOUBLE)) << (DOUBLE_FRAC_బిట్లు - 32);       \
                                                                        \
    /* fill sign bit */                                                 \
    ret.ఎగువ |= sign << 31;                                             \
                                                                        \
_ret_:                                                                  \
    double_unsigned_struct_return(ret);                                 \
}

/* unsigned long long to double conversion */
__AEABI_XL2D(ul2d, 0)

/* long long to double conversion */
__AEABI_XL2D(l2d, 1)

#ఒకవేళ 1
/* Long long helper functions */

/* TODO: add error in case of den == 0 (see §4.3.1 and §4.3.2) */

#నిర్వచించు define_aeabi_xdivmod_signed_type(basetype, type) \
రకనిర్వచనం నిర్మాణం type {                                    \
    basetype quot;                                       \
    గుర్తులేని basetype rem;                               \
} type

#నిర్వచించు define_aeabi_xdivmod_unsigned_type(basetype, type) \
రకనిర్వచనం నిర్మాణం type {                                      \
    basetype quot;                                         \
    basetype rem;                                          \
} type

#నిర్వచించు AEABI_UXDIVMOD(name,type, rettype, typemacro)                     \
స్థిర అంతఃవరుస rettype aeabi_ ## name (type అంకె, type den)                 \
{                                                                         \
    rettype ret;                                                          \
    type quot = 0;                                                        \
                                                                          \
    /* Increase quotient while it is less than numerator */               \
    అయితే (అంకె >= den) {                                                  \
        type q = 1;                                                       \
                                                                          \
        /* Find closest power of two */                                   \
        అయితే ((q << 1) * den <= అంకె && q * den <= typemacro ## _MAX / 2) \
            q <<= 1;                                                      \
                                                                          \
        /* Compute difference between current quotient and numerator */   \
        అంకె -= q * den;                                                   \
        quot += q;                                                        \
    }                                                                     \
    ret.quot = quot;                                                      \
    ret.rem = అంకె;                                                        \
    తిరిగి ret;                                                           \
}

#నిర్వచించు __AEABI_XDIVMOD(name, type, uiname, rettype, urettype, typemacro)     \
శూన్య __aeabi_ ## name(type numerator, type denominator)                       \
{                                                                             \
    గుర్తులేని type అంకె, den;                                                   \
    urettype uxdiv_ret;                                                       \
    rettype ret;                                                              \
                                                                              \
    ఒకవేళ (numerator >= 0)                                                       \
      అంకె = numerator;                                                        \
    లేకపోతే                                                                      \
      అంకె = 0 - numerator;                                                    \
    ఒకవేళ (denominator >= 0)                                                     \
      den = denominator;                                                      \
    లేకపోతే                                                                      \
      den = 0 - denominator;                                                  \
    uxdiv_ret = aeabi_ ## uiname(అంకె, den);                                   \
    /* signs differ */                                                        \
    ఒకవేళ ((numerator & typemacro ## _MIN) != (denominator & typemacro ## _MIN)) \
        ret.quot = 0 - uxdiv_ret.quot;                                        \
    లేకపోతే                                                                      \
        ret.quot = uxdiv_ret.quot;                                            \
    ఒకవేళ (numerator < 0)                                                        \
        ret.rem = 0 - uxdiv_ret.rem;                                          \
    లేకపోతే                                                                      \
        ret.rem = uxdiv_ret.rem;                                              \
                                                                              \
    rettype ## _return(ret);                                                  \
}

define_aeabi_xdivmod_signed_type(దీర్ఘ దీర్ఘ, lldiv_t);
define_aeabi_xdivmod_unsigned_type(గుర్తులేని దీర్ఘ దీర్ఘ, ulldiv_t);
define_aeabi_xdivmod_signed_type(పూర్ణాంకం, idiv_t);
define_aeabi_xdivmod_unsigned_type(గుర్తులేని, uidiv_t);

REGS_RETURN(lldiv_t, lldiv_t)
REGS_RETURN(ulldiv_t, ulldiv_t)
REGS_RETURN(idiv_t, idiv_t)
REGS_RETURN(uidiv_t, uidiv_t)

AEABI_UXDIVMOD(uldivmod, గుర్తులేని దీర్ఘ దీర్ఘ, ulldiv_t, ULLONG)

__AEABI_XDIVMOD(ldivmod, దీర్ఘ దీర్ఘ, uldivmod, lldiv_t, ulldiv_t, LLONG)

శూన్య __aeabi_uldivmod(గుర్తులేని దీర్ఘ దీర్ఘ అంకె, గుర్తులేని దీర్ఘ దీర్ఘ den)
{
    ulldiv_t_return(aeabi_uldivmod(అంకె, den));
}

శూన్య __aeabi_llsl(double_unsigned_struct val, పూర్ణాంకం జరుపు)
{
    double_unsigned_struct ret;

    ఒకవేళ (జరుపు >= 32) {
        val.ఎగువ = val.దిగువ;
        val.దిగువ = 0;
        జరుపు -= 32;
    }
    ఒకవేళ (జరుపు > 0) {
        ret.దిగువ = val.దిగువ << జరుపు;
        ret.ఎగువ = (val.ఎగువ << జరుపు) | (val.దిగువ >> (32 - జరుపు));
        double_unsigned_struct_return(ret);
	తిరిగి;
    }
    double_unsigned_struct_return(val);
}

#నిర్వచించు aeabi_lsr(val, జరుపు, fill, type)                          \
    type ## _struct ret;                                           \
                                                                   \
    ఒకవేళ (జరుపు >= 32) {                                             \
        val.దిగువ = val.ఎగువ;                                        \
        val.ఎగువ = fill;                                           \
        జరుపు -= 32;                                               \
    }                                                              \
    ఒకవేళ (జరుపు > 0) {                                               \
        ret.ఎగువ = val.ఎగువ >> జరుపు;                              \
        ret.దిగువ = (val.ఎగువ << (32 - జరుపు)) | (val.దిగువ >> జరుపు); \
        type ## _struct_return(ret);                               \
	తిరిగి;                                                    \
    }                                                              \
    type ## _struct_return(val);

శూన్య __aeabi_llsr(double_unsigned_struct val, పూర్ణాంకం జరుపు)
{
    aeabi_lsr(val, జరుపు, 0, double_unsigned);
}

శూన్య __aeabi_lasr(unsigned_int_struct val, పూర్ణాంకం జరుపు)
{
    aeabi_lsr(val, జరుపు, val.ఎగువ >> 31, unsigned_int);
}


/* Integer division functions */

#ఒకవేళ 0 /* very slow */
AEABI_UXDIVMOD(uidivmod, గుర్తులేని, uidiv_t, UINT)

పూర్ణాంకం __aeabi_idiv(పూర్ణాంకం numerator, పూర్ణాంకం denominator)
{
    గుర్తులేని అంకె, den;
    uidiv_t ret;

    ఒకవేళ (numerator >= 0)
        అంకె = numerator;
    లేకపోతే
        అంకె = 0 - numerator;
    ఒకవేళ (denominator >= 0)
        den = denominator;
    లేకపోతే
        den = 0 - denominator;
    ret = aeabi_uidivmod(అంకె, den);
    ఒకవేళ ((numerator & INT_MIN) != (denominator & INT_MIN)) /* signs differ */
        ret.quot *= -1;
    తిరిగి ret.quot;
}

గుర్తులేని __aeabi_uidiv(గుర్తులేని అంకె, గుర్తులేని den)
{
    తిరిగి aeabi_uidivmod(అంకె, den).quot;
}

__AEABI_XDIVMOD(idivmod, పూర్ణాంకం, uidivmod, idiv_t, uidiv_t, INT)

శూన్య __aeabi_uidivmod(గుర్తులేని అంకె, గుర్తులేని den)
{
    uidiv_t_return(aeabi_uidivmod(అంకె, den));
}
#లేకపోతే
# define UIDIVMOD_ASM 1
#అయితే_ముగింపు

/* Some targets do not have all eabi calls (OpenBSD) */
రకనిర్వచనం __SIZE_TYPE__ కొలత_t;
బాహ్య శూన్య *జ్ఞాపకం_నకలు(శూన్య *dest, స్థిరరాశి శూన్య *src, కొలత_t n);
బాహ్య శూన్య *memmove(శూన్య *dest, స్థిరరాశి శూన్య *src, కొలత_t n);
బాహ్య శూన్య *memset(శూన్య *s, పూర్ణాంకం c, కొలత_t n);

శూన్య *
__aeabi_memcpy (శూన్య *dest, స్థిరరాశి శూన్య *src, కొలత_t n)
{
    తిరిగి జ్ఞాపకం_నకలు (dest, src, n);
}

శూన్య *
__aeabi_memmove (శూన్య *dest, స్థిరరాశి శూన్య *src, కొలత_t n)
{
    తిరిగి memmove (dest, src, n);
}

శూన్య *
__aeabi_memmove4 (శూన్య *dest, స్థిరరాశి శూన్య *src, కొలత_t n)
{
    తిరిగి memmove (dest, src, n);
}

శూన్య *
__aeabi_memmove8 (శూన్య *dest, స్థిరరాశి శూన్య *src, కొలత_t n)
{
    తిరిగి memmove (dest, src, n);
}

శూన్య *
__aeabi_memset (శూన్య *s, కొలత_t n, పూర్ణాంకం c)
{
    తిరిగి memset (s, c, n);
}

/* ***************************************************************** */
#ఒకవేళ UIDIVMOD_ASM
#అన్తర్భావ <config.h>
__asm__(
   "\n  .global __aeabi_idiv, __aeabi_idivmod"
   "\n  .global __aeabi_uidiv, __aeabi_uidivmod"
#ఒకవేళ __ARM_FEATURE_IDIV
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
#లేకపోతే
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
   "\n  mov     r3, #0"	    //ఫలితం
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
#అయితే_ముగింపు
);
#అయితే_ముగింపు /* UIDIVMOD_ASM */
/* ***************************************************************** */
#అయితే_ముగింపు
