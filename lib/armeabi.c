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
#define पूर्णांक_न्यून (-2147483647 - 1)
#define पूर्णांक_उच्च 2147483647
#define अच_पूर्णांक_उच्च 0xffffffff
#define दीर्घ_न्यून (-2147483647L - 1)
#define दीर्घ_उच्च 2147483647L
#define अच_दीर्घ_उच्च 0xffffffffUL
#define LLONG_MAX 9223372036854775807LL
#define LLONG_MIN (-9223372036854775807LL - 1)
#define ULLONG_MAX 0xffffffffffffffffULL
#अन्यथा
#अन्तर्भाव <limits.h>
#endif

/* We rely on the little endianness and EABI calling convention for this to
   work */

प्रकारनिर्देश संरचना double_unsigned_struct {
    अचिन्हित तल्लो;
    अचिन्हित माथिल्लो;
} double_unsigned_struct;

प्रकारनिर्देश संरचना unsigned_int_struct {
    अचिन्हित तल्लो;
    पूर्णाङ्क माथिल्लो;
} unsigned_int_struct;

#define REGS_RETURN(name, type) \
    स्थिर शून्य name ## _return(type ret) {}


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
शून्य __aeabi_ ## name(अचिन्हित val)                                          \
{                                                                            \
    पूर्णाङ्क exp, माथिल्लो_shift, sign;                                               \
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
    यदि (with_sign) {                                                         \
        यदि (exp > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            फर्काऊ;                                                          \
    } अन्यथा {                                                                 \
        यदि ((sign && exp >= 0) || exp > 63) /* if val < 0 || val too big */  \
            फर्काऊ;                                                          \
    }                                                                        \
                                                                             \
    val &= (1 << FLOAT_FRAC_BITS) - 1;                                       \
    यदि (exp >= 32) {                                                         \
        ret.माथिल्लो = 1 << (exp - 32);                                          \
        यदि (exp - 32 >= FLOAT_FRAC_BITS) {                                   \
            ret.माथिल्लो |= val << (exp - 32 - FLOAT_FRAC_BITS);                 \
            ret.तल्लो = 0;                                                     \
        } अन्यथा {                                                             \
            माथिल्लो_shift = FLOAT_FRAC_BITS - (exp - 32);                       \
            ret.माथिल्लो |= val >> माथिल्लो_shift;                                   \
            ret.तल्लो = val << (32 - माथिल्लो_shift);                              \
        }                                                                    \
    } अन्यथा {                                                                 \
        ret.माथिल्लो = 0;                                                        \
        ret.तल्लो = 1 << exp;                                                  \
        यदि (exp > FLOAT_FRAC_BITS)                                           \
            ret.तल्लो |= val << (exp - FLOAT_FRAC_BITS);                       \
        अन्यथा                                                                 \
            ret.तल्लो |= val >> (FLOAT_FRAC_BITS - exp);                       \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    यदि (with_sign && sign) {                                                 \
        ret.तल्लो = ~ret.तल्लो;                                                  \
        ret.माथिल्लो = ~ret.माथिल्लो;                                                \
        यदि (ret.तल्लो == अच_पूर्णांक_उच्च) {                                           \
            ret.तल्लो = 0;                                                     \
            ret.माथिल्लो++;                                                      \
        } अन्यथा                                                               \
            ret.तल्लो++;                                                       \
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
शून्य __aeabi_ ## name(double_unsigned_struct val)                            \
{                                                                            \
    पूर्णाङ्क exp, माथिल्लो_shift, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    यदि ((val.माथिल्लो & ~0x80000000) == 0 && val.तल्लो == 0) {                     \
        ret.तल्लो = ret.माथिल्लो = 0;                                              \
        गच्छ _ret_;                                                          \
    }                                                                        \
                                                                             \
    /* compute sign */                                                       \
    sign = val.माथिल्लो >> 31;                                                   \
                                                                             \
    /* compute real exponent */                                              \
    exp = (val.माथिल्लो >> (DOUBLE_FRAC_BITS - 32));                             \
    exp &= (1 << DOUBLE_EXP_BITS) - 1;                                       \
    exp -= ONE_EXP(DOUBLE);                                                  \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    यदि (with_sign) {                                                         \
        यदि (exp > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            फर्काऊ;                                                          \
    } अन्यथा {                                                                 \
        यदि ((sign && exp >= 0) || exp > 63) /* if val < 0 || val too big */  \
            फर्काऊ;                                                          \
    }                                                                        \
                                                                             \
    val.माथिल्लो &= (1 << (DOUBLE_FRAC_BITS - 32)) - 1;                          \
    यदि (exp >= 32) {                                                         \
        ret.माथिल्लो = 1 << (exp - 32);                                          \
        यदि (exp >= DOUBLE_FRAC_BITS) {                                       \
            माथिल्लो_shift = exp - DOUBLE_FRAC_BITS;                             \
            ret.माथिल्लो |= val.माथिल्लो << माथिल्लो_shift;                              \
            ret.माथिल्लो |= val.तल्लो >> (32 - माथिल्लो_shift);                        \
            ret.तल्लो = val.तल्लो << माथिल्लो_shift;                                 \
        } अन्यथा {                                                             \
            माथिल्लो_shift = DOUBLE_FRAC_BITS - exp;                             \
            ret.माथिल्लो |= val.माथिल्लो >> माथिल्लो_shift;                              \
            ret.तल्लो = val.माथिल्लो << (32 - माथिल्लो_shift);                         \
            ret.तल्लो |= val.तल्लो >> माथिल्लो_shift;                                \
        }                                                                    \
    } अन्यथा {                                                                 \
        ret.माथिल्लो = 0;                                                        \
        ret.तल्लो = 1 << exp;                                                  \
        यदि (exp > DOUBLE_FRAC_BITS - 32) {                                   \
            माथिल्लो_shift = exp - (DOUBLE_FRAC_BITS - 32);                      \
            ret.तल्लो |= val.माथिल्लो << माथिल्लो_shift;                               \
            ret.तल्लो |= val.तल्लो >> (32 - माथिल्लो_shift);                         \
        } अन्यथा                                                               \
            ret.तल्लो |= val.माथिल्लो >> (DOUBLE_FRAC_BITS - 32 - exp);            \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    यदि (with_sign && sign) {                                                 \
        ret.तल्लो = ~ret.तल्लो;                                                  \
        ret.माथिल्लो = ~ret.माथिल्लो;                                                \
        यदि (ret.तल्लो == अच_पूर्णांक_उच्च) {                                           \
            ret.तल्लो = 0;                                                     \
            ret.माथिल्लो++;                                                      \
        } अन्यथा                                                               \
            ret.तल्लो++;                                                       \
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
अचिन्हित __aeabi_ ## name(अचिन्हित दीर्घ दीर्घ v)                         \
{                                                                       \
    पूर्णाङ्क s /* shift */, flb /* first lost bit */, sign = 0;              \
    अचिन्हित p = 0 /* power */, ret;                                    \
    double_unsigned_struct val;                                         \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    यदि (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.तल्लो = v;                                                        \
    val.माथिल्लो = v >> 32;                                                 \
    /* fill fraction bits */                                            \
    लागि (s = 31, p = 1 << 31; p && !(val.माथिल्लो & p); s--, p >>= 1);      \
    यदि (p) {                                                            \
        ret = val.माथिल्लो & (p - 1);                                       \
        यदि (s < FLOAT_FRAC_BITS) {                                      \
            ret <<= FLOAT_FRAC_BITS - s;                                \
            ret |= val.तल्लो >> (32 - (FLOAT_FRAC_BITS - s));             \
            flb = (val.तल्लो >> (32 - (FLOAT_FRAC_BITS - s - 1))) & 1;    \
        } अन्यथा {                                                        \
            flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;               \
            ret >>= s - FLOAT_FRAC_BITS;                                \
        }                                                               \
        s += 32;                                                        \
    } अन्यथा {                                                            \
        लागि (s = 31, p = 1 << 31; p && !(val.तल्लो & p); s--, p >>= 1);   \
        यदि (p) {                                                        \
            ret = val.तल्लो & (p - 1);                                    \
            यदि (s <= FLOAT_FRAC_BITS) {                                 \
                ret <<= FLOAT_FRAC_BITS - s;                            \
                flb = 0;                                                \
	    } अन्यथा {                                                    \
                flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;           \
                ret >>= s - FLOAT_FRAC_BITS;                            \
	    }                                                           \
        } अन्यथा                                                          \
            फर्काऊ 0;                                                   \
    }                                                                   \
    यदि (flb)                                                            \
        ret++;                                                          \
                                                                        \
    /* fill exponent bits */                                            \
    ret |= (s + ONE_EXP(FLOAT)) << FLOAT_FRAC_BITS;                     \
                                                                        \
    /* fill sign bit */                                                 \
    ret |= sign << 31;                                                  \
                                                                        \
    फर्काऊ ret;                                                         \
}

/* unsigned long long to float conversion */
DEFINE__AEABI_XL2F(ul2f, 0)

/* long long to float conversion */
DEFINE__AEABI_XL2F(l2f, 1)

/* long long to double conversion */
#define __AEABI_XL2D(name, with_sign)                                   \
शून्य __aeabi_ ## name(अचिन्हित दीर्घ दीर्घ v)                             \
{                                                                       \
    पूर्णाङ्क s /* shift */, माथिल्लो_shift, sign = 0;                            \
    अचिन्हित tmp, p = 0;                                                \
    double_unsigned_struct val, ret;                                    \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    यदि (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.तल्लो = v;                                                        \
    val.माथिल्लो = v >> 32;                                                 \
                                                                        \
    /* fill fraction bits */                                            \
    लागि (s = 31, p = 1 << 31; p && !(val.माथिल्लो & p); s--, p >>= 1);      \
    यदि (p) {                                                            \
        tmp = val.माथिल्लो & (p - 1);                                       \
        यदि (s < DOUBLE_FRAC_BITS - 32) {                                \
            माथिल्लो_shift = DOUBLE_FRAC_BITS - 32 - s;                     \
            ret.माथिल्लो = tmp << माथिल्लो_shift;                               \
            ret.माथिल्लो |= val.तल्लो >> (32 - माथिल्लो_shift);                   \
            ret.तल्लो = val.तल्लो << माथिल्लो_shift;                            \
        } अन्यथा {                                                        \
            माथिल्लो_shift = s - (DOUBLE_FRAC_BITS - 32);                   \
            ret.माथिल्लो = tmp >> माथिल्लो_shift;                               \
            ret.तल्लो = tmp << (32 - माथिल्लो_shift);                         \
            ret.तल्लो |= val.तल्लो >> माथिल्लो_shift;                           \
            यदि ((val.तल्लो >> (माथिल्लो_shift - 1)) & 1) {                    \
                यदि (ret.तल्लो == अच_पूर्णांक_उच्च) {                              \
                    ret.माथिल्लो++;                                         \
                    ret.तल्लो = 0;                                        \
		} अन्यथा                                                  \
                    ret.तल्लो++;                                          \
            }                                                           \
        }                                                               \
        s += 32;                                                        \
    } अन्यथा {                                                            \
        लागि (s = 31, p = 1 << 31; p && !(val.तल्लो & p); s--, p >>= 1);   \
        यदि (p) {                                                        \
            tmp = val.तल्लो & (p - 1);                                    \
            यदि (s <= DOUBLE_FRAC_BITS - 32) {                           \
                माथिल्लो_shift = DOUBLE_FRAC_BITS - 32 - s;                 \
                ret.माथिल्लो = tmp << माथिल्लो_shift;                           \
                ret.तल्लो = 0;                                            \
	    } अन्यथा {                                                    \
                माथिल्लो_shift = s - (DOUBLE_FRAC_BITS - 32);               \
                ret.माथिल्लो = tmp >> माथिल्लो_shift;                           \
                ret.तल्लो = tmp << (32 - माथिल्लो_shift);                     \
            }                                                           \
        } अन्यथा {                                                        \
            ret.माथिल्लो = ret.तल्लो = 0;                                     \
            गच्छ _ret_;                                                 \
        }                                                               \
    }                                                                   \
                                                                        \
    /* fill exponent bits */                                            \
    ret.माथिल्लो |= (s + ONE_EXP(DOUBLE)) << (DOUBLE_FRAC_BITS - 32);       \
                                                                        \
    /* fill sign bit */                                                 \
    ret.माथिल्लो |= sign << 31;                                             \
                                                                        \
_ret_:                                                                  \
    double_unsigned_struct_return(ret);                                 \
}

/* unsigned long long to double conversion */
__AEABI_XL2D(ul2d, 0)

/* long long to double conversion */
__AEABI_XL2D(l2d, 1)

#यदि 1
/* Long long helper functions */

/* TODO: add error in case of den == 0 (see §4.3.1 and §4.3.2) */

#define define_aeabi_xdivmod_signed_type(basetype, type) \
प्रकारनिर्देश संरचना type {                                    \
    basetype quot;                                       \
    अचिन्हित basetype rem;                               \
} type

#define define_aeabi_xdivmod_unsigned_type(basetype, type) \
प्रकारनिर्देश संरचना type {                                      \
    basetype quot;                                         \
    basetype rem;                                          \
} type

#define AEABI_UXDIVMOD(name,type, rettype, typemacro)                     \
स्थिर अन्तःस्थ rettype aeabi_ ## name (type अङ्क, type den)                 \
{                                                                         \
    rettype ret;                                                          \
    type quot = 0;                                                        \
                                                                          \
    /* Increase quotient while it is less than numerator */               \
    जबसम्म (अङ्क >= den) {                                                  \
        type q = 1;                                                       \
                                                                          \
        /* Find closest power of two */                                   \
        जबसम्म ((q << 1) * den <= अङ्क && q * den <= typemacro ## _MAX / 2) \
            q <<= 1;                                                      \
                                                                          \
        /* Compute difference between current quotient and numerator */   \
        अङ्क -= q * den;                                                   \
        quot += q;                                                        \
    }                                                                     \
    ret.quot = quot;                                                      \
    ret.rem = अङ्क;                                                        \
    फर्काऊ ret;                                                           \
}

#define __AEABI_XDIVMOD(name, type, uiname, rettype, urettype, typemacro)     \
शून्य __aeabi_ ## name(type numerator, type denominator)                       \
{                                                                             \
    अचिन्हित type अङ्क, den;                                                   \
    urettype uxdiv_ret;                                                       \
    rettype ret;                                                              \
                                                                              \
    यदि (numerator >= 0)                                                       \
      अङ्क = numerator;                                                        \
    अन्यथा                                                                      \
      अङ्क = 0 - numerator;                                                    \
    यदि (denominator >= 0)                                                     \
      den = denominator;                                                      \
    अन्यथा                                                                      \
      den = 0 - denominator;                                                  \
    uxdiv_ret = aeabi_ ## uiname(अङ्क, den);                                   \
    /* signs differ */                                                        \
    यदि ((numerator & typemacro ## _MIN) != (denominator & typemacro ## _MIN)) \
        ret.quot = 0 - uxdiv_ret.quot;                                        \
    अन्यथा                                                                      \
        ret.quot = uxdiv_ret.quot;                                            \
    यदि (numerator < 0)                                                        \
        ret.rem = 0 - uxdiv_ret.rem;                                          \
    अन्यथा                                                                      \
        ret.rem = uxdiv_ret.rem;                                              \
                                                                              \
    rettype ## _return(ret);                                                  \
}

define_aeabi_xdivmod_signed_type(दीर्घ दीर्घ, lldiv_t);
define_aeabi_xdivmod_unsigned_type(अचिन्हित दीर्घ दीर्घ, ulldiv_t);
define_aeabi_xdivmod_signed_type(पूर्णाङ्क, idiv_t);
define_aeabi_xdivmod_unsigned_type(अचिन्हित, uidiv_t);

REGS_RETURN(lldiv_t, lldiv_t)
REGS_RETURN(ulldiv_t, ulldiv_t)
REGS_RETURN(idiv_t, idiv_t)
REGS_RETURN(uidiv_t, uidiv_t)

AEABI_UXDIVMOD(uldivmod, अचिन्हित दीर्घ दीर्घ, ulldiv_t, ULLONG)

__AEABI_XDIVMOD(ldivmod, दीर्घ दीर्घ, uldivmod, lldiv_t, ulldiv_t, LLONG)

शून्य __aeabi_uldivmod(अचिन्हित दीर्घ दीर्घ अङ्क, अचिन्हित दीर्घ दीर्घ den)
{
    ulldiv_t_return(aeabi_uldivmod(अङ्क, den));
}

शून्य __aeabi_llsl(double_unsigned_struct val, पूर्णाङ्क shift)
{
    double_unsigned_struct ret;

    यदि (shift >= 32) {
        val.माथिल्लो = val.तल्लो;
        val.तल्लो = 0;
        shift -= 32;
    }
    यदि (shift > 0) {
        ret.तल्लो = val.तल्लो << shift;
        ret.माथिल्लो = (val.माथिल्लो << shift) | (val.तल्लो >> (32 - shift));
        double_unsigned_struct_return(ret);
	फर्काऊ;
    }
    double_unsigned_struct_return(val);
}

#define aeabi_lsr(val, shift, fill, type)                          \
    type ## _struct ret;                                           \
                                                                   \
    यदि (shift >= 32) {                                             \
        val.तल्लो = val.माथिल्लो;                                        \
        val.माथिल्लो = fill;                                           \
        shift -= 32;                                               \
    }                                                              \
    यदि (shift > 0) {                                               \
        ret.माथिल्लो = val.माथिल्लो >> shift;                              \
        ret.तल्लो = (val.माथिल्लो << (32 - shift)) | (val.तल्लो >> shift); \
        type ## _struct_return(ret);                               \
	फर्काऊ;                                                    \
    }                                                              \
    type ## _struct_return(val);

शून्य __aeabi_llsr(double_unsigned_struct val, पूर्णाङ्क shift)
{
    aeabi_lsr(val, shift, 0, double_unsigned);
}

शून्य __aeabi_lasr(unsigned_int_struct val, पूर्णाङ्क shift)
{
    aeabi_lsr(val, shift, val.माथिल्लो >> 31, unsigned_int);
}


/* Integer division functions */

#यदि 0 /* very slow */
AEABI_UXDIVMOD(uidivmod, अचिन्हित, uidiv_t, UINT)

पूर्णाङ्क __aeabi_idiv(पूर्णाङ्क numerator, पूर्णाङ्क denominator)
{
    अचिन्हित अङ्क, den;
    uidiv_t ret;

    यदि (numerator >= 0)
        अङ्क = numerator;
    अन्यथा
        अङ्क = 0 - numerator;
    यदि (denominator >= 0)
        den = denominator;
    अन्यथा
        den = 0 - denominator;
    ret = aeabi_uidivmod(अङ्क, den);
    यदि ((numerator & पूर्णांक_न्यून) != (denominator & पूर्णांक_न्यून)) /* signs differ */
        ret.quot *= -1;
    फर्काऊ ret.quot;
}

अचिन्हित __aeabi_uidiv(अचिन्हित अङ्क, अचिन्हित den)
{
    फर्काऊ aeabi_uidivmod(अङ्क, den).quot;
}

__AEABI_XDIVMOD(idivmod, पूर्णाङ्क, uidivmod, idiv_t, uidiv_t, INT)

शून्य __aeabi_uidivmod(अचिन्हित अङ्क, अचिन्हित den)
{
    uidiv_t_return(aeabi_uidivmod(अङ्क, den));
}
#अन्यथा
# define UIDIVMOD_ASM 1
#endif

/* Some targets do not have all eabi calls (OpenBSD) */
प्रकारनिर्देश __SIZE_TYPE__ माप_प्रकार;
बाह्य शून्य *स_नकल(शून्य *dest, अचर शून्य *src, माप_प्रकार n);
बाह्य शून्य *स_हटाओ(शून्य *dest, अचर शून्य *src, माप_प्रकार n);
बाह्य शून्य *स_रखो(शून्य *s, पूर्णाङ्क c, माप_प्रकार n);

शून्य *
__aeabi_memcpy (शून्य *dest, अचर शून्य *src, माप_प्रकार n)
{
    फर्काऊ स_नकल (dest, src, n);
}

शून्य *
__aeabi_memmove (शून्य *dest, अचर शून्य *src, माप_प्रकार n)
{
    फर्काऊ स_हटाओ (dest, src, n);
}

शून्य *
__aeabi_memmove4 (शून्य *dest, अचर शून्य *src, माप_प्रकार n)
{
    फर्काऊ स_हटाओ (dest, src, n);
}

शून्य *
__aeabi_memmove8 (शून्य *dest, अचर शून्य *src, माप_प्रकार n)
{
    फर्काऊ स_हटाओ (dest, src, n);
}

शून्य *
__aeabi_memset (शून्य *s, माप_प्रकार n, पूर्णाङ्क c)
{
    फर्काऊ स_रखो (s, c, n);
}

/* ***************************************************************** */
#यदि UIDIVMOD_ASM
#अन्तर्भाव <config.h>
__asm__(
   "\n  .global __aeabi_idiv, __aeabi_idivmod"
   "\n  .global __aeabi_uidiv, __aeabi_uidivmod"
#यदि __ARM_FEATURE_IDIV
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
#अन्यथा
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
