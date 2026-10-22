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

#अगर_घोषित __TINYC__
#घोषणा पूर्णांक_न्यून (-2147483647 - 1)
#घोषणा पूर्णांक_उच्च 2147483647
#घोषणा अच_पूर्णांक_उच्च 0xffffffff
#घोषणा दीर्घ_न्यून (-2147483647L - 1)
#घोषणा दीर्घ_उच्च 2147483647L
#घोषणा अच_दीर्घ_उच्च 0xffffffffUL
#घोषणा LLONG_MAX 9223372036854775807LL
#घोषणा LLONG_MIN (-9223372036854775807LL - 1)
#घोषणा ULLONG_MAX 0xffffffffffffffffULL
#अन्यथा
#समावेश <limits.h>
#पूर्ण_अगर

/* We rely on the little endianness and EABI calling convention for this to
   work */

प्रकार काष्ठा double_unsigned_struct {
    अचिन्हित निचला;
    अचिन्हित ऊपरी;
} double_unsigned_struct;

प्रकार काष्ठा unsigned_int_struct {
    अचिन्हित निचला;
    पूर्णांक ऊपरी;
} unsigned_int_struct;

#घोषणा REGS_RETURN(name, type) \
    अटल व्योम name ## _return(type ret) {}


/* Float helper functions */

#घोषणा FLOAT_EXP_BITS 8
#घोषणा FLOAT_FRAC_BITS 23

#घोषणा DOUBLE_EXP_BITS 11
#घोषणा DOUBLE_FRAC_BITS 52

#घोषणा ONE_EXP(type) ((1 << (type ## _EXP_BITS - 1)) - 1)

REGS_RETURN(unsigned_int_struct, unsigned_int_struct)
REGS_RETURN(double_unsigned_struct, double_unsigned_struct)

/* float -> integer: (sign) 1.fraction x 2^(exponent - exp_for_one) */


/* float to [unsigned] long long conversion */
#घोषणा DEFINE__AEABI_F2XLZ(name, with_sign)                                 \
व्योम __aeabi_ ## name(अचिन्हित val)                                          \
{                                                                            \
    पूर्णांक exp, ऊपरी_shift, sign;                                               \
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
    अगर (with_sign) {                                                         \
        अगर (exp > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            वापस;                                                          \
    } अन्यथा {                                                                 \
        अगर ((sign && exp >= 0) || exp > 63) /* if val < 0 || val too big */  \
            वापस;                                                          \
    }                                                                        \
                                                                             \
    val &= (1 << FLOAT_FRAC_BITS) - 1;                                       \
    अगर (exp >= 32) {                                                         \
        ret.ऊपरी = 1 << (exp - 32);                                          \
        अगर (exp - 32 >= FLOAT_FRAC_BITS) {                                   \
            ret.ऊपरी |= val << (exp - 32 - FLOAT_FRAC_BITS);                 \
            ret.निचला = 0;                                                     \
        } अन्यथा {                                                             \
            ऊपरी_shift = FLOAT_FRAC_BITS - (exp - 32);                       \
            ret.ऊपरी |= val >> ऊपरी_shift;                                   \
            ret.निचला = val << (32 - ऊपरी_shift);                              \
        }                                                                    \
    } अन्यथा {                                                                 \
        ret.ऊपरी = 0;                                                        \
        ret.निचला = 1 << exp;                                                  \
        अगर (exp > FLOAT_FRAC_BITS)                                           \
            ret.निचला |= val << (exp - FLOAT_FRAC_BITS);                       \
        अन्यथा                                                                 \
            ret.निचला |= val >> (FLOAT_FRAC_BITS - exp);                       \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    अगर (with_sign && sign) {                                                 \
        ret.निचला = ~ret.निचला;                                                  \
        ret.ऊपरी = ~ret.ऊपरी;                                                \
        अगर (ret.निचला == अच_पूर्णांक_उच्च) {                                           \
            ret.निचला = 0;                                                     \
            ret.ऊपरी++;                                                      \
        } अन्यथा                                                               \
            ret.निचला++;                                                       \
    }                                                                        \
                                                                             \
    double_unsigned_struct_return(ret);                                      \
}

/* float to unsigned long long conversion */
DEFINE__AEABI_F2XLZ(f2ulz, 0)

/* float to long long conversion */
DEFINE__AEABI_F2XLZ(f2lz, 1)

/* double to [unsigned] long long conversion */
#घोषणा DEFINE__AEABI_D2XLZ(name, with_sign)                                 \
व्योम __aeabi_ ## name(double_unsigned_struct val)                            \
{                                                                            \
    पूर्णांक exp, ऊपरी_shift, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    अगर ((val.ऊपरी & ~0x80000000) == 0 && val.निचला == 0) {                     \
        ret.निचला = ret.ऊपरी = 0;                                              \
        जाओ _ret_;                                                          \
    }                                                                        \
                                                                             \
    /* compute sign */                                                       \
    sign = val.ऊपरी >> 31;                                                   \
                                                                             \
    /* compute real exponent */                                              \
    exp = (val.ऊपरी >> (DOUBLE_FRAC_BITS - 32));                             \
    exp &= (1 << DOUBLE_EXP_BITS) - 1;                                       \
    exp -= ONE_EXP(DOUBLE);                                                  \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    अगर (with_sign) {                                                         \
        अगर (exp > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            वापस;                                                          \
    } अन्यथा {                                                                 \
        अगर ((sign && exp >= 0) || exp > 63) /* if val < 0 || val too big */  \
            वापस;                                                          \
    }                                                                        \
                                                                             \
    val.ऊपरी &= (1 << (DOUBLE_FRAC_BITS - 32)) - 1;                          \
    अगर (exp >= 32) {                                                         \
        ret.ऊपरी = 1 << (exp - 32);                                          \
        अगर (exp >= DOUBLE_FRAC_BITS) {                                       \
            ऊपरी_shift = exp - DOUBLE_FRAC_BITS;                             \
            ret.ऊपरी |= val.ऊपरी << ऊपरी_shift;                              \
            ret.ऊपरी |= val.निचला >> (32 - ऊपरी_shift);                        \
            ret.निचला = val.निचला << ऊपरी_shift;                                 \
        } अन्यथा {                                                             \
            ऊपरी_shift = DOUBLE_FRAC_BITS - exp;                             \
            ret.ऊपरी |= val.ऊपरी >> ऊपरी_shift;                              \
            ret.निचला = val.ऊपरी << (32 - ऊपरी_shift);                         \
            ret.निचला |= val.निचला >> ऊपरी_shift;                                \
        }                                                                    \
    } अन्यथा {                                                                 \
        ret.ऊपरी = 0;                                                        \
        ret.निचला = 1 << exp;                                                  \
        अगर (exp > DOUBLE_FRAC_BITS - 32) {                                   \
            ऊपरी_shift = exp - (DOUBLE_FRAC_BITS - 32);                      \
            ret.निचला |= val.ऊपरी << ऊपरी_shift;                               \
            ret.निचला |= val.निचला >> (32 - ऊपरी_shift);                         \
        } अन्यथा                                                               \
            ret.निचला |= val.ऊपरी >> (DOUBLE_FRAC_BITS - 32 - exp);            \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    अगर (with_sign && sign) {                                                 \
        ret.निचला = ~ret.निचला;                                                  \
        ret.ऊपरी = ~ret.ऊपरी;                                                \
        अगर (ret.निचला == अच_पूर्णांक_उच्च) {                                           \
            ret.निचला = 0;                                                     \
            ret.ऊपरी++;                                                      \
        } अन्यथा                                                               \
            ret.निचला++;                                                       \
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
#घोषणा DEFINE__AEABI_XL2F(name, with_sign)                             \
अचिन्हित __aeabi_ ## name(अचिन्हित दीर्घ दीर्घ v)                         \
{                                                                       \
    पूर्णांक s /* shift */, flb /* first lost bit */, sign = 0;              \
    अचिन्हित p = 0 /* power */, ret;                                    \
    double_unsigned_struct val;                                         \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    अगर (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.निचला = v;                                                        \
    val.ऊपरी = v >> 32;                                                 \
    /* fill fraction bits */                                            \
    क्रम (s = 31, p = 1 << 31; p && !(val.ऊपरी & p); s--, p >>= 1);      \
    अगर (p) {                                                            \
        ret = val.ऊपरी & (p - 1);                                       \
        अगर (s < FLOAT_FRAC_BITS) {                                      \
            ret <<= FLOAT_FRAC_BITS - s;                                \
            ret |= val.निचला >> (32 - (FLOAT_FRAC_BITS - s));             \
            flb = (val.निचला >> (32 - (FLOAT_FRAC_BITS - s - 1))) & 1;    \
        } अन्यथा {                                                        \
            flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;               \
            ret >>= s - FLOAT_FRAC_BITS;                                \
        }                                                               \
        s += 32;                                                        \
    } अन्यथा {                                                            \
        क्रम (s = 31, p = 1 << 31; p && !(val.निचला & p); s--, p >>= 1);   \
        अगर (p) {                                                        \
            ret = val.निचला & (p - 1);                                    \
            अगर (s <= FLOAT_FRAC_BITS) {                                 \
                ret <<= FLOAT_FRAC_BITS - s;                            \
                flb = 0;                                                \
	    } अन्यथा {                                                    \
                flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;           \
                ret >>= s - FLOAT_FRAC_BITS;                            \
	    }                                                           \
        } अन्यथा                                                          \
            वापस 0;                                                   \
    }                                                                   \
    अगर (flb)                                                            \
        ret++;                                                          \
                                                                        \
    /* fill exponent bits */                                            \
    ret |= (s + ONE_EXP(FLOAT)) << FLOAT_FRAC_BITS;                     \
                                                                        \
    /* fill sign bit */                                                 \
    ret |= sign << 31;                                                  \
                                                                        \
    वापस ret;                                                         \
}

/* unsigned long long to float conversion */
DEFINE__AEABI_XL2F(ul2f, 0)

/* long long to float conversion */
DEFINE__AEABI_XL2F(l2f, 1)

/* long long to double conversion */
#घोषणा __AEABI_XL2D(name, with_sign)                                   \
व्योम __aeabi_ ## name(अचिन्हित दीर्घ दीर्घ v)                             \
{                                                                       \
    पूर्णांक s /* shift */, ऊपरी_shift, sign = 0;                            \
    अचिन्हित tmp, p = 0;                                                \
    double_unsigned_struct val, ret;                                    \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    अगर (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.निचला = v;                                                        \
    val.ऊपरी = v >> 32;                                                 \
                                                                        \
    /* fill fraction bits */                                            \
    क्रम (s = 31, p = 1 << 31; p && !(val.ऊपरी & p); s--, p >>= 1);      \
    अगर (p) {                                                            \
        tmp = val.ऊपरी & (p - 1);                                       \
        अगर (s < DOUBLE_FRAC_BITS - 32) {                                \
            ऊपरी_shift = DOUBLE_FRAC_BITS - 32 - s;                     \
            ret.ऊपरी = tmp << ऊपरी_shift;                               \
            ret.ऊपरी |= val.निचला >> (32 - ऊपरी_shift);                   \
            ret.निचला = val.निचला << ऊपरी_shift;                            \
        } अन्यथा {                                                        \
            ऊपरी_shift = s - (DOUBLE_FRAC_BITS - 32);                   \
            ret.ऊपरी = tmp >> ऊपरी_shift;                               \
            ret.निचला = tmp << (32 - ऊपरी_shift);                         \
            ret.निचला |= val.निचला >> ऊपरी_shift;                           \
            अगर ((val.निचला >> (ऊपरी_shift - 1)) & 1) {                    \
                अगर (ret.निचला == अच_पूर्णांक_उच्च) {                              \
                    ret.ऊपरी++;                                         \
                    ret.निचला = 0;                                        \
		} अन्यथा                                                  \
                    ret.निचला++;                                          \
            }                                                           \
        }                                                               \
        s += 32;                                                        \
    } अन्यथा {                                                            \
        क्रम (s = 31, p = 1 << 31; p && !(val.निचला & p); s--, p >>= 1);   \
        अगर (p) {                                                        \
            tmp = val.निचला & (p - 1);                                    \
            अगर (s <= DOUBLE_FRAC_BITS - 32) {                           \
                ऊपरी_shift = DOUBLE_FRAC_BITS - 32 - s;                 \
                ret.ऊपरी = tmp << ऊपरी_shift;                           \
                ret.निचला = 0;                                            \
	    } अन्यथा {                                                    \
                ऊपरी_shift = s - (DOUBLE_FRAC_BITS - 32);               \
                ret.ऊपरी = tmp >> ऊपरी_shift;                           \
                ret.निचला = tmp << (32 - ऊपरी_shift);                     \
            }                                                           \
        } अन्यथा {                                                        \
            ret.ऊपरी = ret.निचला = 0;                                     \
            जाओ _ret_;                                                 \
        }                                                               \
    }                                                                   \
                                                                        \
    /* fill exponent bits */                                            \
    ret.ऊपरी |= (s + ONE_EXP(DOUBLE)) << (DOUBLE_FRAC_BITS - 32);       \
                                                                        \
    /* fill sign bit */                                                 \
    ret.ऊपरी |= sign << 31;                                             \
                                                                        \
_ret_:                                                                  \
    double_unsigned_struct_return(ret);                                 \
}

/* unsigned long long to double conversion */
__AEABI_XL2D(ul2d, 0)

/* long long to double conversion */
__AEABI_XL2D(l2d, 1)

#अगर 1
/* Long long helper functions */

/* TODO: add error in case of den == 0 (see §4.3.1 and §4.3.2) */

#घोषणा define_aeabi_xdivmod_signed_type(basetype, type) \
प्रकार काष्ठा type {                                    \
    basetype quot;                                       \
    अचिन्हित basetype rem;                               \
} type

#घोषणा define_aeabi_xdivmod_unsigned_type(basetype, type) \
प्रकार काष्ठा type {                                      \
    basetype quot;                                         \
    basetype rem;                                          \
} type

#घोषणा AEABI_UXDIVMOD(name,type, rettype, typemacro)                     \
अटल अंतरभूत rettype aeabi_ ## name (type अंक, type den)                 \
{                                                                         \
    rettype ret;                                                          \
    type quot = 0;                                                        \
                                                                          \
    /* Increase quotient while it is less than numerator */               \
    जबतक (अंक >= den) {                                                  \
        type q = 1;                                                       \
                                                                          \
        /* Find closest power of two */                                   \
        जबतक ((q << 1) * den <= अंक && q * den <= typemacro ## _MAX / 2) \
            q <<= 1;                                                      \
                                                                          \
        /* Compute difference between current quotient and numerator */   \
        अंक -= q * den;                                                   \
        quot += q;                                                        \
    }                                                                     \
    ret.quot = quot;                                                      \
    ret.rem = अंक;                                                        \
    वापस ret;                                                           \
}

#घोषणा __AEABI_XDIVMOD(name, type, uiname, rettype, urettype, typemacro)     \
व्योम __aeabi_ ## name(type numerator, type denominator)                       \
{                                                                             \
    अचिन्हित type अंक, den;                                                   \
    urettype uxdiv_ret;                                                       \
    rettype ret;                                                              \
                                                                              \
    अगर (numerator >= 0)                                                       \
      अंक = numerator;                                                        \
    अन्यथा                                                                      \
      अंक = 0 - numerator;                                                    \
    अगर (denominator >= 0)                                                     \
      den = denominator;                                                      \
    अन्यथा                                                                      \
      den = 0 - denominator;                                                  \
    uxdiv_ret = aeabi_ ## uiname(अंक, den);                                   \
    /* signs differ */                                                        \
    अगर ((numerator & typemacro ## _MIN) != (denominator & typemacro ## _MIN)) \
        ret.quot = 0 - uxdiv_ret.quot;                                        \
    अन्यथा                                                                      \
        ret.quot = uxdiv_ret.quot;                                            \
    अगर (numerator < 0)                                                        \
        ret.rem = 0 - uxdiv_ret.rem;                                          \
    अन्यथा                                                                      \
        ret.rem = uxdiv_ret.rem;                                              \
                                                                              \
    rettype ## _return(ret);                                                  \
}

define_aeabi_xdivmod_signed_type(दीर्घ दीर्घ, lldiv_t);
define_aeabi_xdivmod_unsigned_type(अचिन्हित दीर्घ दीर्घ, ulldiv_t);
define_aeabi_xdivmod_signed_type(पूर्णांक, idiv_t);
define_aeabi_xdivmod_unsigned_type(अचिन्हित, uidiv_t);

REGS_RETURN(lldiv_t, lldiv_t)
REGS_RETURN(ulldiv_t, ulldiv_t)
REGS_RETURN(idiv_t, idiv_t)
REGS_RETURN(uidiv_t, uidiv_t)

AEABI_UXDIVMOD(uldivmod, अचिन्हित दीर्घ दीर्घ, ulldiv_t, ULLONG)

__AEABI_XDIVMOD(ldivmod, दीर्घ दीर्घ, uldivmod, lldiv_t, ulldiv_t, LLONG)

व्योम __aeabi_uldivmod(अचिन्हित दीर्घ दीर्घ अंक, अचिन्हित दीर्घ दीर्घ den)
{
    ulldiv_t_return(aeabi_uldivmod(अंक, den));
}

व्योम __aeabi_llsl(double_unsigned_struct val, पूर्णांक shift)
{
    double_unsigned_struct ret;

    अगर (shift >= 32) {
        val.ऊपरी = val.निचला;
        val.निचला = 0;
        shift -= 32;
    }
    अगर (shift > 0) {
        ret.निचला = val.निचला << shift;
        ret.ऊपरी = (val.ऊपरी << shift) | (val.निचला >> (32 - shift));
        double_unsigned_struct_return(ret);
	वापस;
    }
    double_unsigned_struct_return(val);
}

#घोषणा aeabi_lsr(val, shift, fill, type)                          \
    type ## _struct ret;                                           \
                                                                   \
    अगर (shift >= 32) {                                             \
        val.निचला = val.ऊपरी;                                        \
        val.ऊपरी = fill;                                           \
        shift -= 32;                                               \
    }                                                              \
    अगर (shift > 0) {                                               \
        ret.ऊपरी = val.ऊपरी >> shift;                              \
        ret.निचला = (val.ऊपरी << (32 - shift)) | (val.निचला >> shift); \
        type ## _struct_return(ret);                               \
	वापस;                                                    \
    }                                                              \
    type ## _struct_return(val);

व्योम __aeabi_llsr(double_unsigned_struct val, पूर्णांक shift)
{
    aeabi_lsr(val, shift, 0, double_unsigned);
}

व्योम __aeabi_lasr(unsigned_int_struct val, पूर्णांक shift)
{
    aeabi_lsr(val, shift, val.ऊपरी >> 31, unsigned_int);
}


/* Integer division functions */

#अगर 0 /* very slow */
AEABI_UXDIVMOD(uidivmod, अचिन्हित, uidiv_t, UINT)

पूर्णांक __aeabi_idiv(पूर्णांक numerator, पूर्णांक denominator)
{
    अचिन्हित अंक, den;
    uidiv_t ret;

    अगर (numerator >= 0)
        अंक = numerator;
    अन्यथा
        अंक = 0 - numerator;
    अगर (denominator >= 0)
        den = denominator;
    अन्यथा
        den = 0 - denominator;
    ret = aeabi_uidivmod(अंक, den);
    अगर ((numerator & पूर्णांक_न्यून) != (denominator & पूर्णांक_न्यून)) /* signs differ */
        ret.quot *= -1;
    वापस ret.quot;
}

अचिन्हित __aeabi_uidiv(अचिन्हित अंक, अचिन्हित den)
{
    वापस aeabi_uidivmod(अंक, den).quot;
}

__AEABI_XDIVMOD(idivmod, पूर्णांक, uidivmod, idiv_t, uidiv_t, INT)

व्योम __aeabi_uidivmod(अचिन्हित अंक, अचिन्हित den)
{
    uidiv_t_return(aeabi_uidivmod(अंक, den));
}
#अन्यथा
# define UIDIVMOD_ASM 1
#पूर्ण_अगर

/* Some targets do not have all eabi calls (OpenBSD) */
प्रकार __SIZE_TYPE__ माप_प्रकार;
बाह्य व्योम *स_नकल(व्योम *dest, स्थिर व्योम *src, माप_प्रकार n);
बाह्य व्योम *स_हटाओ(व्योम *dest, स्थिर व्योम *src, माप_प्रकार n);
बाह्य व्योम *स_रखो(व्योम *s, पूर्णांक c, माप_प्रकार n);

व्योम *
__aeabi_memcpy (व्योम *dest, स्थिर व्योम *src, माप_प्रकार n)
{
    वापस स_नकल (dest, src, n);
}

व्योम *
__aeabi_memmove (व्योम *dest, स्थिर व्योम *src, माप_प्रकार n)
{
    वापस स_हटाओ (dest, src, n);
}

व्योम *
__aeabi_memmove4 (व्योम *dest, स्थिर व्योम *src, माप_प्रकार n)
{
    वापस स_हटाओ (dest, src, n);
}

व्योम *
__aeabi_memmove8 (व्योम *dest, स्थिर व्योम *src, माप_प्रकार n)
{
    वापस स_हटाओ (dest, src, n);
}

व्योम *
__aeabi_memset (व्योम *s, माप_प्रकार n, पूर्णांक c)
{
    वापस स_रखो (s, c, n);
}

/* ***************************************************************** */
#अगर UIDIVMOD_ASM
#समावेश <config.h>
__asm__(
   "\n  .global __aeabi_idiv, __aeabi_idivmod"
   "\n  .global __aeabi_uidiv, __aeabi_uidivmod"
#अगर __ARM_FEATURE_IDIV
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
   "\n  mov     r2, #1"	    //गणक
   "\n  mov     r3, #0"	    //परिणाम
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
#पूर्ण_अगर
);
#पूर्ण_अगर /* UIDIVMOD_ASM */
/* ***************************************************************** */
#पूर्ण_अगर
