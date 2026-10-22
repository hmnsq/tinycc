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

#यदि_परिभाषितम् __TINYC__
#परिभाषय INT_MIN (-2147483647 - 1)
#परिभाषय अधिकतम_पूर्णाङ्कः 2147483647
#परिभाषय UINT_MAX 0xffffffff
#परिभाषय LONG_MIN (-2147483647L - 1)
#परिभाषय LONG_MAX 2147483647L
#परिभाषय ULONG_MAX 0xffffffffUL
#परिभाषय LLONG_MAX 9223372036854775807LL
#परिभाषय LLONG_MIN (-9223372036854775807LL - 1)
#परिभाषय ULLONG_MAX 0xffffffffffffffffULL
#अन्यथा
#अन्तर्भाव <limits.h>
#यदि_अन्तः

/* We rely on the little endianness and EABI calling convention for this to
   work */

प्रकारनिर्देश संरचना double_unsigned_struct {
    अचिह्नित नीचः;
    अचिह्नित उच्चः;
} double_unsigned_struct;

प्रकारनिर्देश संरचना unsigned_int_struct {
    अचिह्नित नीचः;
    पूर्णाङ्क उच्चः;
} unsigned_int_struct;

#परिभाषय REGS_RETURN(name, type) \
    स्थिर शून्य name ## _return(type ret) {}


/* Float helper functions */

#परिभाषय FLOAT_EXP_द्वयङ्काः 8
#परिभाषय FLOAT_FRAC_द्वयङ्काः 23

#परिभाषय DOUBLE_EXP_द्वयङ्काः 11
#परिभाषय DOUBLE_FRAC_द्वयङ्काः 52

#परिभाषय ONE_EXP(type) ((1 << (type ## EXP_द्वयङ्काः - 1)) - 1)

REGS_RETURN(unsigned_int_struct, unsigned_int_struct)
REGS_RETURN(double_unsigned_struct, double_unsigned_struct)

/* float -> integer: (sign) 1.fraction x 2^(exponent - exp_for_one) */


/* float to [unsigned] long long conversion */
#परिभाषय DEFINE__AEABI_F2XLZ(name, with_sign)                                 \
शून्य __aeabi_ ## name(अचिह्नित val)                                          \
{                                                                            \
    पूर्णाङ्क घातांकः, उच्चः_सरणम्, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    /* compute sign */                                                       \
    sign = val >> 31;                                                        \
                                                                             \
    /* compute real exponent */                                              \
    घातांकः = val >> FLOAT_FRAC_द्वयङ्काः;                                            \
    घातांकः &= (1 << FLOAT_EXP_द्वयङ्काः) - 1;                                        \
    घातांकः -= ONE_EXP(FLOAT);                                                   \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    यदि (with_sign) {                                                         \
        यदि (घातांकः > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            प्रत्यागम;                                                          \
    } अन्यथा {                                                                 \
        यदि ((sign && घातांकः >= 0) || घातांकः > 63) /* if val < 0 || val too big */  \
            प्रत्यागम;                                                          \
    }                                                                        \
                                                                             \
    val &= (1 << FLOAT_FRAC_द्वयङ्काः) - 1;                                       \
    यदि (घातांकः >= 32) {                                                         \
        ret.उच्चः = 1 << (घातांकः - 32);                                          \
        यदि (घातांकः - 32 >= FLOAT_FRAC_द्वयङ्काः) {                                   \
            ret.उच्चः |= val << (घातांकः - 32 - FLOAT_FRAC_द्वयङ्काः);                 \
            ret.नीचः = 0;                                                     \
        } अन्यथा {                                                             \
            उच्चः_सरणम् = FLOAT_FRAC_द्वयङ्काः - (घातांकः - 32);                       \
            ret.उच्चः |= val >> उच्चः_सरणम्;                                   \
            ret.नीचः = val << (32 - उच्चः_सरणम्);                              \
        }                                                                    \
    } अन्यथा {                                                                 \
        ret.उच्चः = 0;                                                        \
        ret.नीचः = 1 << घातांकः;                                                  \
        यदि (घातांकः > FLOAT_FRAC_द्वयङ्काः)                                           \
            ret.नीचः |= val << (घातांकः - FLOAT_FRAC_द्वयङ्काः);                       \
        अन्यथा                                                                 \
            ret.नीचः |= val >> (FLOAT_FRAC_द्वयङ्काः - घातांकः);                       \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    यदि (with_sign && sign) {                                                 \
        ret.नीचः = ~ret.नीचः;                                                  \
        ret.उच्चः = ~ret.उच्चः;                                                \
        यदि (ret.नीचः == UINT_MAX) {                                           \
            ret.नीचः = 0;                                                     \
            ret.उच्चः++;                                                      \
        } अन्यथा                                                               \
            ret.नीचः++;                                                       \
    }                                                                        \
                                                                             \
    double_unsigned_struct_return(ret);                                      \
}

/* float to unsigned long long conversion */
DEFINE__AEABI_F2XLZ(f2ulz, 0)

/* float to long long conversion */
DEFINE__AEABI_F2XLZ(f2lz, 1)

/* double to [unsigned] long long conversion */
#परिभाषय DEFINE__AEABI_D2XLZ(name, with_sign)                                 \
शून्य __aeabi_ ## name(double_unsigned_struct val)                            \
{                                                                            \
    पूर्णाङ्क घातांकः, उच्चः_सरणम्, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    यदि ((val.उच्चः & ~0x80000000) == 0 && val.नीचः == 0) {                     \
        ret.नीचः = ret.उच्चः = 0;                                              \
        गच्छ _ret_;                                                          \
    }                                                                        \
                                                                             \
    /* compute sign */                                                       \
    sign = val.उच्चः >> 31;                                                   \
                                                                             \
    /* compute real exponent */                                              \
    घातांकः = (val.उच्चः >> (DOUBLE_FRAC_द्वयङ्काः - 32));                             \
    घातांकः &= (1 << DOUBLE_EXP_द्वयङ्काः) - 1;                                       \
    घातांकः -= ONE_EXP(DOUBLE);                                                  \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    यदि (with_sign) {                                                         \
        यदि (घातांकः > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            प्रत्यागम;                                                          \
    } अन्यथा {                                                                 \
        यदि ((sign && घातांकः >= 0) || घातांकः > 63) /* if val < 0 || val too big */  \
            प्रत्यागम;                                                          \
    }                                                                        \
                                                                             \
    val.उच्चः &= (1 << (DOUBLE_FRAC_द्वयङ्काः - 32)) - 1;                          \
    यदि (घातांकः >= 32) {                                                         \
        ret.उच्चः = 1 << (घातांकः - 32);                                          \
        यदि (घातांकः >= DOUBLE_FRAC_द्वयङ्काः) {                                       \
            उच्चः_सरणम् = घातांकः - DOUBLE_FRAC_द्वयङ्काः;                             \
            ret.उच्चः |= val.उच्चः << उच्चः_सरणम्;                              \
            ret.उच्चः |= val.नीचः >> (32 - उच्चः_सरणम्);                        \
            ret.नीचः = val.नीचः << उच्चः_सरणम्;                                 \
        } अन्यथा {                                                             \
            उच्चः_सरणम् = DOUBLE_FRAC_द्वयङ्काः - घातांकः;                             \
            ret.उच्चः |= val.उच्चः >> उच्चः_सरणम्;                              \
            ret.नीचः = val.उच्चः << (32 - उच्चः_सरणम्);                         \
            ret.नीचः |= val.नीचः >> उच्चः_सरणम्;                                \
        }                                                                    \
    } अन्यथा {                                                                 \
        ret.उच्चः = 0;                                                        \
        ret.नीचः = 1 << घातांकः;                                                  \
        यदि (घातांकः > DOUBLE_FRAC_द्वयङ्काः - 32) {                                   \
            उच्चः_सरणम् = घातांकः - (DOUBLE_FRAC_द्वयङ्काः - 32);                      \
            ret.नीचः |= val.उच्चः << उच्चः_सरणम्;                               \
            ret.नीचः |= val.नीचः >> (32 - उच्चः_सरणम्);                         \
        } अन्यथा                                                               \
            ret.नीचः |= val.उच्चः >> (DOUBLE_FRAC_द्वयङ्काः - 32 - घातांकः);            \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    यदि (with_sign && sign) {                                                 \
        ret.नीचः = ~ret.नीचः;                                                  \
        ret.उच्चः = ~ret.उच्चः;                                                \
        यदि (ret.नीचः == UINT_MAX) {                                           \
            ret.नीचः = 0;                                                     \
            ret.उच्चः++;                                                      \
        } अन्यथा                                                               \
            ret.नीचः++;                                                       \
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
#परिभाषय DEFINE__AEABI_XL2F(name, with_sign)                             \
अचिह्नित __aeabi_ ## name(अचिह्नित दीर्घ दीर्घ v)                         \
{                                                                       \
    पूर्णाङ्क s /*सरणम्*/, flb /* first lost bit */, sign = 0;              \
    अचिह्नित p = 0 /* power */, ret;                                    \
    double_unsigned_struct val;                                         \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    यदि (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.नीचः = v;                                                        \
    val.उच्चः = v >> 32;                                                 \
    /* fill fraction bits */                                            \
    प्रति (s = 31, p = 1 << 31; p && !(val.उच्चः & p); s--, p >>= 1);      \
    यदि (p) {                                                            \
        ret = val.उच्चः & (p - 1);                                       \
        यदि (s < FLOAT_FRAC_द्वयङ्काः) {                                      \
            ret <<= FLOAT_FRAC_द्वयङ्काः - s;                                \
            ret |= val.नीचः >> (32 - (FLOAT_FRAC_द्वयङ्काः - s));             \
            flb = (val.नीचः >> (32 - (FLOAT_FRAC_द्वयङ्काः - s - 1))) & 1;    \
        } अन्यथा {                                                        \
            flb = (ret >> (s - FLOAT_FRAC_द्वयङ्काः - 1)) & 1;               \
            ret >>= s - FLOAT_FRAC_द्वयङ्काः;                                \
        }                                                               \
        s += 32;                                                        \
    } अन्यथा {                                                            \
        प्रति (s = 31, p = 1 << 31; p && !(val.नीचः & p); s--, p >>= 1);   \
        यदि (p) {                                                        \
            ret = val.नीचः & (p - 1);                                    \
            यदि (s <= FLOAT_FRAC_द्वयङ्काः) {                                 \
                ret <<= FLOAT_FRAC_द्वयङ्काः - s;                            \
                flb = 0;                                                \
	    } अन्यथा {                                                    \
                flb = (ret >> (s - FLOAT_FRAC_द्वयङ्काः - 1)) & 1;           \
                ret >>= s - FLOAT_FRAC_द्वयङ्काः;                            \
	    }                                                           \
        } अन्यथा                                                          \
            प्रत्यागम 0;                                                   \
    }                                                                   \
    यदि (flb)                                                            \
        ret++;                                                          \
                                                                        \
    /* fill exponent bits */                                            \
    ret |= (s + ONE_EXP(FLOAT)) << FLOAT_FRAC_द्वयङ्काः;                     \
                                                                        \
    /* fill sign bit */                                                 \
    ret |= sign << 31;                                                  \
                                                                        \
    प्रत्यागम ret;                                                         \
}

/* unsigned long long to float conversion */
DEFINE__AEABI_XL2F(ul2f, 0)

/* long long to float conversion */
DEFINE__AEABI_XL2F(l2f, 1)

/* long long to double conversion */
#परिभाषय __AEABI_XL2D(name, with_sign)                                   \
शून्य __aeabi_ ## name(अचिह्नित दीर्घ दीर्घ v)                             \
{                                                                       \
    पूर्णाङ्क s /*सरणम्*/, उच्चः_सरणम्, sign = 0;                            \
    अचिह्नित tmp, p = 0;                                                \
    double_unsigned_struct val, ret;                                    \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    यदि (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.नीचः = v;                                                        \
    val.उच्चः = v >> 32;                                                 \
                                                                        \
    /* fill fraction bits */                                            \
    प्रति (s = 31, p = 1 << 31; p && !(val.उच्चः & p); s--, p >>= 1);      \
    यदि (p) {                                                            \
        tmp = val.उच्चः & (p - 1);                                       \
        यदि (s < DOUBLE_FRAC_द्वयङ्काः - 32) {                                \
            उच्चः_सरणम् = DOUBLE_FRAC_द्वयङ्काः - 32 - s;                     \
            ret.उच्चः = tmp << उच्चः_सरणम्;                               \
            ret.उच्चः |= val.नीचः >> (32 - उच्चः_सरणम्);                   \
            ret.नीचः = val.नीचः << उच्चः_सरणम्;                            \
        } अन्यथा {                                                        \
            उच्चः_सरणम् = s - (DOUBLE_FRAC_द्वयङ्काः - 32);                   \
            ret.उच्चः = tmp >> उच्चः_सरणम्;                               \
            ret.नीचः = tmp << (32 - उच्चः_सरणम्);                         \
            ret.नीचः |= val.नीचः >> उच्चः_सरणम्;                           \
            यदि ((val.नीचः >> (उच्चः_सरणम् - 1)) & 1) {                    \
                यदि (ret.नीचः == UINT_MAX) {                              \
                    ret.उच्चः++;                                         \
                    ret.नीचः = 0;                                        \
		} अन्यथा                                                  \
                    ret.नीचः++;                                          \
            }                                                           \
        }                                                               \
        s += 32;                                                        \
    } अन्यथा {                                                            \
        प्रति (s = 31, p = 1 << 31; p && !(val.नीचः & p); s--, p >>= 1);   \
        यदि (p) {                                                        \
            tmp = val.नीचः & (p - 1);                                    \
            यदि (s <= DOUBLE_FRAC_द्वयङ्काः - 32) {                           \
                उच्चः_सरणम् = DOUBLE_FRAC_द्वयङ्काः - 32 - s;                 \
                ret.उच्चः = tmp << उच्चः_सरणम्;                           \
                ret.नीचः = 0;                                            \
	    } अन्यथा {                                                    \
                उच्चः_सरणम् = s - (DOUBLE_FRAC_द्वयङ्काः - 32);               \
                ret.उच्चः = tmp >> उच्चः_सरणम्;                           \
                ret.नीचः = tmp << (32 - उच्चः_सरणम्);                     \
            }                                                           \
        } अन्यथा {                                                        \
            ret.उच्चः = ret.नीचः = 0;                                     \
            गच्छ _ret_;                                                 \
        }                                                               \
    }                                                                   \
                                                                        \
    /* fill exponent bits */                                            \
    ret.उच्चः |= (s + ONE_EXP(DOUBLE)) << (DOUBLE_FRAC_द्वयङ्काः - 32);       \
                                                                        \
    /* fill sign bit */                                                 \
    ret.उच्चः |= sign << 31;                                             \
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

#परिभाषय define_aeabi_xdivmod_signed_type(basetype, type) \
प्रकारनिर्देश संरचना type {                                    \
    basetype quot;                                       \
    अचिह्नित basetype rem;                               \
} type

#परिभाषय define_aeabi_xdivmod_unsigned_type(basetype, type) \
प्रकारनिर्देश संरचना type {                                      \
    basetype quot;                                         \
    basetype rem;                                          \
} type

#परिभाषय AEABI_UXDIVMOD(name,type, rettype, typemacro)                     \
स्थिर अन्तःस्थ rettype aeabi_ ## name (type अङ्कः, type den)                 \
{                                                                         \
    rettype ret;                                                          \
    type quot = 0;                                                        \
                                                                          \
    /* Increase quotient while it is less than numerator */               \
    यावत् (अङ्कः >= den) {                                                  \
        type q = 1;                                                       \
                                                                          \
        /* Find closest power of two */                                   \
        यावत् ((q << 1) * den <= अङ्कः && q * den <= typemacro ## _MAX / 2) \
            q <<= 1;                                                      \
                                                                          \
        /* Compute difference between current quotient and numerator */   \
        अङ्कः -= q * den;                                                   \
        quot += q;                                                        \
    }                                                                     \
    ret.quot = quot;                                                      \
    ret.rem = अङ्कः;                                                        \
    प्रत्यागम ret;                                                           \
}

#परिभाषय __AEABI_XDIVMOD(name, type, uiname, rettype, urettype, typemacro)     \
शून्य __aeabi_ ## name(type numerator, type denominator)                       \
{                                                                             \
    अचिह्नित type अङ्कः, den;                                                   \
    urettype uxdiv_ret;                                                       \
    rettype ret;                                                              \
                                                                              \
    यदि (numerator >= 0)                                                       \
      अङ्कः = numerator;                                                        \
    अन्यथा                                                                      \
      अङ्कः = 0 - numerator;                                                    \
    यदि (denominator >= 0)                                                     \
      den = denominator;                                                      \
    अन्यथा                                                                      \
      den = 0 - denominator;                                                  \
    uxdiv_ret = aeabi_ ## uiname(अङ्कः, den);                                   \
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
define_aeabi_xdivmod_unsigned_type(अचिह्नित दीर्घ दीर्घ, ulldiv_t);
define_aeabi_xdivmod_signed_type(पूर्णाङ्क, idiv_t);
define_aeabi_xdivmod_unsigned_type(अचिह्नित, uidiv_t);

REGS_RETURN(lldiv_t, lldiv_t)
REGS_RETURN(ulldiv_t, ulldiv_t)
REGS_RETURN(idiv_t, idiv_t)
REGS_RETURN(uidiv_t, uidiv_t)

AEABI_UXDIVMOD(uldivmod, अचिह्नित दीर्घ दीर्घ, ulldiv_t, ULLONG)

__AEABI_XDIVMOD(ldivmod, दीर्घ दीर्घ, uldivmod, lldiv_t, ulldiv_t, LLONG)

शून्य __aeabi_uldivmod(अचिह्नित दीर्घ दीर्घ अङ्कः, अचिह्नित दीर्घ दीर्घ den)
{
    ulldiv_t_return(aeabi_uldivmod(अङ्कः, den));
}

शून्य __aeabi_llsl(double_unsigned_struct val, पूर्णाङ्क सरणम्)
{
    double_unsigned_struct ret;

    यदि (सरणम् >= 32) {
        val.उच्चः = val.नीचः;
        val.नीचः = 0;
        सरणम् -= 32;
    }
    यदि (सरणम् > 0) {
        ret.नीचः = val.नीचः << सरणम्;
        ret.उच्चः = (val.उच्चः << सरणम्) | (val.नीचः >> (32 - सरणम्));
        double_unsigned_struct_return(ret);
	प्रत्यागम;
    }
    double_unsigned_struct_return(val);
}

#परिभाषय aeabi_lsr(val, सरणम्, fill, type)                          \
    type ## _struct ret;                                           \
                                                                   \
    यदि (सरणम् >= 32) {                                             \
        val.नीचः = val.उच्चः;                                        \
        val.उच्चः = fill;                                           \
        सरणम् -= 32;                                               \
    }                                                              \
    यदि (सरणम् > 0) {                                               \
        ret.उच्चः = val.उच्चः >> सरणम्;                              \
        ret.नीचः = (val.उच्चः << (32 - सरणम्)) | (val.नीचः >> सरणम्); \
        type ## _struct_return(ret);                               \
	प्रत्यागम;                                                    \
    }                                                              \
    type ## _struct_return(val);

शून्य __aeabi_llsr(double_unsigned_struct val, पूर्णाङ्क सरणम्)
{
    aeabi_lsr(val, सरणम्, 0, double_unsigned);
}

शून्य __aeabi_lasr(unsigned_int_struct val, पूर्णाङ्क सरणम्)
{
    aeabi_lsr(val, सरणम्, val.उच्चः >> 31, unsigned_int);
}


/* Integer division functions */

#यदि 0 /* very slow */
AEABI_UXDIVMOD(uidivmod, अचिह्नित, uidiv_t, UINT)

पूर्णाङ्क __aeabi_idiv(पूर्णाङ्क numerator, पूर्णाङ्क denominator)
{
    अचिह्नित अङ्कः, den;
    uidiv_t ret;

    यदि (numerator >= 0)
        अङ्कः = numerator;
    अन्यथा
        अङ्कः = 0 - numerator;
    यदि (denominator >= 0)
        den = denominator;
    अन्यथा
        den = 0 - denominator;
    ret = aeabi_uidivmod(अङ्कः, den);
    यदि ((numerator & INT_MIN) != (denominator & INT_MIN)) /* signs differ */
        ret.quot *= -1;
    प्रत्यागम ret.quot;
}

अचिह्नित __aeabi_uidiv(अचिह्नित अङ्कः, अचिह्नित den)
{
    प्रत्यागम aeabi_uidivmod(अङ्कः, den).quot;
}

__AEABI_XDIVMOD(idivmod, पूर्णाङ्क, uidivmod, idiv_t, uidiv_t, INT)

शून्य __aeabi_uidivmod(अचिह्नित अङ्कः, अचिह्नित den)
{
    uidiv_t_return(aeabi_uidivmod(अङ्कः, den));
}
#अन्यथा
# define UIDIVMOD_ASM 1
#यदि_अन्तः

/* Some targets do not have all eabi calls (OpenBSD) */
प्रकारनिर्देश __SIZE_TYPE__ आकार_t;
बाह्य शून्य *स्मृतिं_प्रतिलिख(शून्य *dest, ध्रुव शून्य *src, आकार_t n);
बाह्य शून्य *memmove(शून्य *dest, ध्रुव शून्य *src, आकार_t n);
बाह्य शून्य *स्मृतिं_पूरय(शून्य *s, पूर्णाङ्क c, आकार_t n);

शून्य *
__aeabi_memcpy (शून्य *dest, ध्रुव शून्य *src, आकार_t n)
{
    प्रत्यागम स्मृतिं_प्रतिलिख (dest, src, n);
}

शून्य *
__aeabi_memmove (शून्य *dest, ध्रुव शून्य *src, आकार_t n)
{
    प्रत्यागम memmove (dest, src, n);
}

शून्य *
__aeabi_memmove4 (शून्य *dest, ध्रुव शून्य *src, आकार_t n)
{
    प्रत्यागम memmove (dest, src, n);
}

शून्य *
__aeabi_memmove8 (शून्य *dest, ध्रुव शून्य *src, आकार_t n)
{
    प्रत्यागम memmove (dest, src, n);
}

शून्य *
__aeabi_memset (शून्य *s, आकार_t n, पूर्णाङ्क c)
{
    प्रत्यागम स्मृतिं_पूरय (s, c, n);
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
#यदि_अन्तः
);
#यदि_अन्तः /* UIDIVMOD_ASM */
/* ***************************************************************** */
#यदि_अन्तः
