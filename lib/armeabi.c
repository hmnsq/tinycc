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

#اگر_تعریف_شده __TINYC__
#تعریف_کن INT_MIN (-2147483647 - 1)
#تعریف_کن بیشترین_صحیح 2147483647
#تعریف_کن UINT_MAX 0xffffffff
#تعریف_کن LONG_MIN (-2147483647L - 1)
#تعریف_کن LONG_MAX 2147483647L
#تعریف_کن ULONG_MAX 0xffffffffUL
#تعریف_کن LLONG_MAX 9223372036854775807LL
#تعریف_کن LLONG_MIN (-9223372036854775807LL - 1)
#تعریف_کن ULLONG_MAX 0xffffffffffffffffULL
#وإلا
#ضمن <limits.h>
#پایان_اگر

/* We rely on the little endianness and EABI calling convention for this to
   work */

تعريفنوع بنية double_unsigned_struct {
    بیعلامت کم;
    بیعلامت بالا;
} double_unsigned_struct;

تعريفنوع بنية unsigned_int_struct {
    بیعلامت کم;
    صحيح بالا;
} unsigned_int_struct;

#تعریف_کن REGS_RETURN(name, type) \
    ساكن فراغ name ## _return(type ret) {}


/* Float helper functions */

#تعریف_کن FLOAT_EXP_بیتها 8
#تعریف_کن FLOAT_FRAC_بیتها 23

#تعریف_کن DOUBLE_EXP_بیتها 11
#تعریف_کن DOUBLE_FRAC_بیتها 52

#تعریف_کن ONE_EXP(type) ((1 << (type ## EXP_بیتها - 1)) - 1)

REGS_RETURN(unsigned_int_struct, unsigned_int_struct)
REGS_RETURN(double_unsigned_struct, double_unsigned_struct)

/* float -> integer: (sign) 1.fraction x 2^(exponent - exp_for_one) */


/* float to [unsigned] long long conversion */
#تعریف_کن DEFINE__AEABI_F2XLZ(name, with_sign)                                 \
فراغ __aeabi_ ## name(بیعلامت val)                                          \
{                                                                            \
    صحيح نمایی_تابع, بالا_لغزش, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    /* compute sign */                                                       \
    sign = val >> 31;                                                        \
                                                                             \
    /* compute real exponent */                                              \
    نمایی_تابع = val >> FLOAT_FRAC_بیتها;                                            \
    نمایی_تابع &= (1 << FLOAT_EXP_بیتها) - 1;                                        \
    نمایی_تابع -= ONE_EXP(FLOAT);                                                   \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    إذا (with_sign) {                                                         \
        إذا (نمایی_تابع > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            أرجع;                                                          \
    } وإلا {                                                                 \
        إذا ((sign && نمایی_تابع >= 0) || نمایی_تابع > 63) /* if val < 0 || val too big */  \
            أرجع;                                                          \
    }                                                                        \
                                                                             \
    val &= (1 << FLOAT_FRAC_بیتها) - 1;                                       \
    إذا (نمایی_تابع >= 32) {                                                         \
        ret.بالا = 1 << (نمایی_تابع - 32);                                          \
        إذا (نمایی_تابع - 32 >= FLOAT_FRAC_بیتها) {                                   \
            ret.بالا |= val << (نمایی_تابع - 32 - FLOAT_FRAC_بیتها);                 \
            ret.کم = 0;                                                     \
        } وإلا {                                                             \
            بالا_لغزش = FLOAT_FRAC_بیتها - (نمایی_تابع - 32);                       \
            ret.بالا |= val >> بالا_لغزش;                                   \
            ret.کم = val << (32 - بالا_لغزش);                              \
        }                                                                    \
    } وإلا {                                                                 \
        ret.بالا = 0;                                                        \
        ret.کم = 1 << نمایی_تابع;                                                  \
        إذا (نمایی_تابع > FLOAT_FRAC_بیتها)                                           \
            ret.کم |= val << (نمایی_تابع - FLOAT_FRAC_بیتها);                       \
        وإلا                                                                 \
            ret.کم |= val >> (FLOAT_FRAC_بیتها - نمایی_تابع);                       \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    إذا (with_sign && sign) {                                                 \
        ret.کم = ~ret.کم;                                                  \
        ret.بالا = ~ret.بالا;                                                \
        إذا (ret.کم == UINT_MAX) {                                           \
            ret.کم = 0;                                                     \
            ret.بالا++;                                                      \
        } وإلا                                                               \
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
#تعریف_کن DEFINE__AEABI_D2XLZ(name, with_sign)                                 \
فراغ __aeabi_ ## name(double_unsigned_struct val)                            \
{                                                                            \
    صحيح نمایی_تابع, بالا_لغزش, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    إذا ((val.بالا & ~0x80000000) == 0 && val.کم == 0) {                     \
        ret.کم = ret.بالا = 0;                                              \
        اذهب _ret_;                                                          \
    }                                                                        \
                                                                             \
    /* compute sign */                                                       \
    sign = val.بالا >> 31;                                                   \
                                                                             \
    /* compute real exponent */                                              \
    نمایی_تابع = (val.بالا >> (DOUBLE_FRAC_بیتها - 32));                             \
    نمایی_تابع &= (1 << DOUBLE_EXP_بیتها) - 1;                                       \
    نمایی_تابع -= ONE_EXP(DOUBLE);                                                  \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    إذا (with_sign) {                                                         \
        إذا (نمایی_تابع > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            أرجع;                                                          \
    } وإلا {                                                                 \
        إذا ((sign && نمایی_تابع >= 0) || نمایی_تابع > 63) /* if val < 0 || val too big */  \
            أرجع;                                                          \
    }                                                                        \
                                                                             \
    val.بالا &= (1 << (DOUBLE_FRAC_بیتها - 32)) - 1;                          \
    إذا (نمایی_تابع >= 32) {                                                         \
        ret.بالا = 1 << (نمایی_تابع - 32);                                          \
        إذا (نمایی_تابع >= DOUBLE_FRAC_بیتها) {                                       \
            بالا_لغزش = نمایی_تابع - DOUBLE_FRAC_بیتها;                             \
            ret.بالا |= val.بالا << بالا_لغزش;                              \
            ret.بالا |= val.کم >> (32 - بالا_لغزش);                        \
            ret.کم = val.کم << بالا_لغزش;                                 \
        } وإلا {                                                             \
            بالا_لغزش = DOUBLE_FRAC_بیتها - نمایی_تابع;                             \
            ret.بالا |= val.بالا >> بالا_لغزش;                              \
            ret.کم = val.بالا << (32 - بالا_لغزش);                         \
            ret.کم |= val.کم >> بالا_لغزش;                                \
        }                                                                    \
    } وإلا {                                                                 \
        ret.بالا = 0;                                                        \
        ret.کم = 1 << نمایی_تابع;                                                  \
        إذا (نمایی_تابع > DOUBLE_FRAC_بیتها - 32) {                                   \
            بالا_لغزش = نمایی_تابع - (DOUBLE_FRAC_بیتها - 32);                      \
            ret.کم |= val.بالا << بالا_لغزش;                               \
            ret.کم |= val.کم >> (32 - بالا_لغزش);                         \
        } وإلا                                                               \
            ret.کم |= val.بالا >> (DOUBLE_FRAC_بیتها - 32 - نمایی_تابع);            \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    إذا (with_sign && sign) {                                                 \
        ret.کم = ~ret.کم;                                                  \
        ret.بالا = ~ret.بالا;                                                \
        إذا (ret.کم == UINT_MAX) {                                           \
            ret.کم = 0;                                                     \
            ret.بالا++;                                                      \
        } وإلا                                                               \
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
#تعریف_کن DEFINE__AEABI_XL2F(name, with_sign)                             \
بیعلامت __aeabi_ ## name(بیعلامت دراز دراز v)                         \
{                                                                       \
    صحيح s /*لغزش*/, flb /* first lost bit */, sign = 0;              \
    بیعلامت p = 0 /* power */, ret;                                    \
    double_unsigned_struct val;                                         \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    إذا (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.کم = v;                                                        \
    val.بالا = v >> 32;                                                 \
    /* fill fraction bits */                                            \
    لكل (s = 31, p = 1 << 31; p && !(val.بالا & p); s--, p >>= 1);      \
    إذا (p) {                                                            \
        ret = val.بالا & (p - 1);                                       \
        إذا (s < FLOAT_FRAC_بیتها) {                                      \
            ret <<= FLOAT_FRAC_بیتها - s;                                \
            ret |= val.کم >> (32 - (FLOAT_FRAC_بیتها - s));             \
            flb = (val.کم >> (32 - (FLOAT_FRAC_بیتها - s - 1))) & 1;    \
        } وإلا {                                                        \
            flb = (ret >> (s - FLOAT_FRAC_بیتها - 1)) & 1;               \
            ret >>= s - FLOAT_FRAC_بیتها;                                \
        }                                                               \
        s += 32;                                                        \
    } وإلا {                                                            \
        لكل (s = 31, p = 1 << 31; p && !(val.کم & p); s--, p >>= 1);   \
        إذا (p) {                                                        \
            ret = val.کم & (p - 1);                                    \
            إذا (s <= FLOAT_FRAC_بیتها) {                                 \
                ret <<= FLOAT_FRAC_بیتها - s;                            \
                flb = 0;                                                \
	    } وإلا {                                                    \
                flb = (ret >> (s - FLOAT_FRAC_بیتها - 1)) & 1;           \
                ret >>= s - FLOAT_FRAC_بیتها;                            \
	    }                                                           \
        } وإلا                                                          \
            أرجع 0;                                                   \
    }                                                                   \
    إذا (flb)                                                            \
        ret++;                                                          \
                                                                        \
    /* fill exponent bits */                                            \
    ret |= (s + ONE_EXP(FLOAT)) << FLOAT_FRAC_بیتها;                     \
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
#تعریف_کن __AEABI_XL2D(name, with_sign)                                   \
فراغ __aeabi_ ## name(بیعلامت دراز دراز v)                             \
{                                                                       \
    صحيح s /*لغزش*/, بالا_لغزش, sign = 0;                            \
    بیعلامت tmp, p = 0;                                                \
    double_unsigned_struct val, ret;                                    \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    إذا (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.کم = v;                                                        \
    val.بالا = v >> 32;                                                 \
                                                                        \
    /* fill fraction bits */                                            \
    لكل (s = 31, p = 1 << 31; p && !(val.بالا & p); s--, p >>= 1);      \
    إذا (p) {                                                            \
        tmp = val.بالا & (p - 1);                                       \
        إذا (s < DOUBLE_FRAC_بیتها - 32) {                                \
            بالا_لغزش = DOUBLE_FRAC_بیتها - 32 - s;                     \
            ret.بالا = tmp << بالا_لغزش;                               \
            ret.بالا |= val.کم >> (32 - بالا_لغزش);                   \
            ret.کم = val.کم << بالا_لغزش;                            \
        } وإلا {                                                        \
            بالا_لغزش = s - (DOUBLE_FRAC_بیتها - 32);                   \
            ret.بالا = tmp >> بالا_لغزش;                               \
            ret.کم = tmp << (32 - بالا_لغزش);                         \
            ret.کم |= val.کم >> بالا_لغزش;                           \
            إذا ((val.کم >> (بالا_لغزش - 1)) & 1) {                    \
                إذا (ret.کم == UINT_MAX) {                              \
                    ret.بالا++;                                         \
                    ret.کم = 0;                                        \
		} وإلا                                                  \
                    ret.کم++;                                          \
            }                                                           \
        }                                                               \
        s += 32;                                                        \
    } وإلا {                                                            \
        لكل (s = 31, p = 1 << 31; p && !(val.کم & p); s--, p >>= 1);   \
        إذا (p) {                                                        \
            tmp = val.کم & (p - 1);                                    \
            إذا (s <= DOUBLE_FRAC_بیتها - 32) {                           \
                بالا_لغزش = DOUBLE_FRAC_بیتها - 32 - s;                 \
                ret.بالا = tmp << بالا_لغزش;                           \
                ret.کم = 0;                                            \
	    } وإلا {                                                    \
                بالا_لغزش = s - (DOUBLE_FRAC_بیتها - 32);               \
                ret.بالا = tmp >> بالا_لغزش;                           \
                ret.کم = tmp << (32 - بالا_لغزش);                     \
            }                                                           \
        } وإلا {                                                        \
            ret.بالا = ret.کم = 0;                                     \
            اذهب _ret_;                                                 \
        }                                                               \
    }                                                                   \
                                                                        \
    /* fill exponent bits */                                            \
    ret.بالا |= (s + ONE_EXP(DOUBLE)) << (DOUBLE_FRAC_بیتها - 32);       \
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

#إذا 1
/* Long long helper functions */

/* TODO: add error in case of den == 0 (see §4.3.1 and §4.3.2) */

#تعریف_کن define_aeabi_xdivmod_signed_type(basetype, type) \
تعريفنوع بنية type {                                    \
    basetype quot;                                       \
    بیعلامت basetype rem;                               \
} type

#تعریف_کن define_aeabi_xdivmod_unsigned_type(basetype, type) \
تعريفنوع بنية type {                                      \
    basetype quot;                                         \
    basetype rem;                                          \
} type

#تعریف_کن AEABI_UXDIVMOD(name,type, rettype, typemacro)                     \
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

#تعریف_کن __AEABI_XDIVMOD(name, type, uiname, rettype, urettype, typemacro)     \
فراغ __aeabi_ ## name(type numerator, type denominator)                       \
{                                                                             \
    بیعلامت type رقم, den;                                                   \
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

define_aeabi_xdivmod_signed_type(دراز دراز, lldiv_t);
define_aeabi_xdivmod_unsigned_type(بیعلامت دراز دراز, ulldiv_t);
define_aeabi_xdivmod_signed_type(صحيح, idiv_t);
define_aeabi_xdivmod_unsigned_type(بیعلامت, uidiv_t);

REGS_RETURN(lldiv_t, lldiv_t)
REGS_RETURN(ulldiv_t, ulldiv_t)
REGS_RETURN(idiv_t, idiv_t)
REGS_RETURN(uidiv_t, uidiv_t)

AEABI_UXDIVMOD(uldivmod, بیعلامت دراز دراز, ulldiv_t, ULLONG)

__AEABI_XDIVMOD(ldivmod, دراز دراز, uldivmod, lldiv_t, ulldiv_t, LLONG)

فراغ __aeabi_uldivmod(بیعلامت دراز دراز رقم, بیعلامت دراز دراز den)
{
    ulldiv_t_return(aeabi_uldivmod(رقم, den));
}

فراغ __aeabi_llsl(double_unsigned_struct val, صحيح لغزش)
{
    double_unsigned_struct ret;

    إذا (لغزش >= 32) {
        val.بالا = val.کم;
        val.کم = 0;
        لغزش -= 32;
    }
    إذا (لغزش > 0) {
        ret.کم = val.کم << لغزش;
        ret.بالا = (val.بالا << لغزش) | (val.کم >> (32 - لغزش));
        double_unsigned_struct_return(ret);
	أرجع;
    }
    double_unsigned_struct_return(val);
}

#تعریف_کن aeabi_lsr(val, لغزش, fill, type)                          \
    type ## _struct ret;                                           \
                                                                   \
    إذا (لغزش >= 32) {                                             \
        val.کم = val.بالا;                                        \
        val.بالا = fill;                                           \
        لغزش -= 32;                                               \
    }                                                              \
    إذا (لغزش > 0) {                                               \
        ret.بالا = val.بالا >> لغزش;                              \
        ret.کم = (val.بالا << (32 - لغزش)) | (val.کم >> لغزش); \
        type ## _struct_return(ret);                               \
	أرجع;                                                    \
    }                                                              \
    type ## _struct_return(val);

فراغ __aeabi_llsr(double_unsigned_struct val, صحيح لغزش)
{
    aeabi_lsr(val, لغزش, 0, double_unsigned);
}

فراغ __aeabi_lasr(unsigned_int_struct val, صحيح لغزش)
{
    aeabi_lsr(val, لغزش, val.بالا >> 31, unsigned_int);
}


/* Integer division functions */

#إذا 0 /* very slow */
AEABI_UXDIVMOD(uidivmod, بیعلامت, uidiv_t, UINT)

صحيح __aeabi_idiv(صحيح numerator, صحيح denominator)
{
    بیعلامت رقم, den;
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

بیعلامت __aeabi_uidiv(بیعلامت رقم, بیعلامت den)
{
    أرجع aeabi_uidivmod(رقم, den).quot;
}

__AEABI_XDIVMOD(idivmod, صحيح, uidivmod, idiv_t, uidiv_t, INT)

فراغ __aeabi_uidivmod(بیعلامت رقم, بیعلامت den)
{
    uidiv_t_return(aeabi_uidivmod(رقم, den));
}
#وإلا
# define UIDIVMOD_ASM 1
#پایان_اگر

/* Some targets do not have all eabi calls (OpenBSD) */
تعريفنوع __SIZE_TYPE__ اندازه_t;
خارجي فراغ *کپی_حافظه(فراغ *dest, ثابت فراغ *src, اندازه_t n);
خارجي فراغ *memmove(فراغ *dest, ثابت فراغ *src, اندازه_t n);
خارجي فراغ *memset(فراغ *s, صحيح c, اندازه_t n);

فراغ *
__aeabi_memcpy (فراغ *dest, ثابت فراغ *src, اندازه_t n)
{
    أرجع کپی_حافظه (dest, src, n);
}

فراغ *
__aeabi_memmove (فراغ *dest, ثابت فراغ *src, اندازه_t n)
{
    أرجع memmove (dest, src, n);
}

فراغ *
__aeabi_memmove4 (فراغ *dest, ثابت فراغ *src, اندازه_t n)
{
    أرجع memmove (dest, src, n);
}

فراغ *
__aeabi_memmove8 (فراغ *dest, ثابت فراغ *src, اندازه_t n)
{
    أرجع memmove (dest, src, n);
}

فراغ *
__aeabi_memset (فراغ *s, اندازه_t n, صحيح c)
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
   "\n  mov     r3, #0"	    //نتیجه
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
#پایان_اگر
);
#پایان_اگر /* UIDIVMOD_ASM */
/* ***************************************************************** */
#پایان_اگر
