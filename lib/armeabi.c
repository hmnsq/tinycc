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

#اگر_تعریف_شدہ __TINYC__
#تعریف_کرو INT_MIN (-2147483647 - 1)
#تعریف_کرو زیادہ_سے_زیادہ_عدد 2147483647
#تعریف_کرو UINT_MAX 0xffffffff
#تعریف_کرو LONG_MIN (-2147483647L - 1)
#تعریف_کرو LONG_MAX 2147483647L
#تعریف_کرو ULONG_MAX 0xffffffffUL
#تعریف_کرو LLONG_MAX 9223372036854775807LL
#تعریف_کرو LLONG_MIN (-9223372036854775807LL - 1)
#تعریف_کرو ULLONG_MAX 0xffffffffffffffffULL
#ورنہ
#شامل <limits.h>
#اگر_ختم

/* We rely on the little endianness and EABI calling convention for this to
   work */

قسمتعریف ساخت double_unsigned_struct {
    غیرعلامتی کم;
    غیرعلامتی بلند;
} double_unsigned_struct;

قسمتعریف ساخت unsigned_int_struct {
    غیرعلامتی کم;
    صحیح بلند;
} unsigned_int_struct;

#تعریف_کرو REGS_RETURN(name, type) \
    ساکن خالی name ## _return(type ret) {}


/* Float helper functions */

#تعریف_کرو FLOAT_EXP_بٹ 8
#تعریف_کرو FLOAT_FRAC_بٹ 23

#تعریف_کرو DOUBLE_EXP_بٹ 11
#تعریف_کرو DOUBLE_FRAC_بٹ 52

#تعریف_کرو ONE_EXP(type) ((1 << (type ## EXP_بٹ - 1)) - 1)

REGS_RETURN(unsigned_int_struct, unsigned_int_struct)
REGS_RETURN(double_unsigned_struct, double_unsigned_struct)

/* float -> integer: (sign) 1.fraction x 2^(exponent - exp_for_one) */


/* float to [unsigned] long long conversion */
#تعریف_کرو DEFINE__AEABI_F2XLZ(name, with_sign)                                 \
خالی __aeabi_ ## name(غیرعلامتی val)                                          \
{                                                                            \
    صحیح قوت_نما, بلند_سرکاؤ, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    /* compute sign */                                                       \
    sign = val >> 31;                                                        \
                                                                             \
    /* compute real exponent */                                              \
    قوت_نما = val >> FLOAT_FRAC_بٹ;                                            \
    قوت_نما &= (1 << FLOAT_EXP_بٹ) - 1;                                        \
    قوت_نما -= ONE_EXP(FLOAT);                                                   \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    اگر (with_sign) {                                                         \
        اگر (قوت_نما > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            واپس;                                                          \
    } ورنہ {                                                                 \
        اگر ((sign && قوت_نما >= 0) || قوت_نما > 63) /* if val < 0 || val too big */  \
            واپس;                                                          \
    }                                                                        \
                                                                             \
    val &= (1 << FLOAT_FRAC_بٹ) - 1;                                       \
    اگر (قوت_نما >= 32) {                                                         \
        ret.بلند = 1 << (قوت_نما - 32);                                          \
        اگر (قوت_نما - 32 >= FLOAT_FRAC_بٹ) {                                   \
            ret.بلند |= val << (قوت_نما - 32 - FLOAT_FRAC_بٹ);                 \
            ret.کم = 0;                                                     \
        } ورنہ {                                                             \
            بلند_سرکاؤ = FLOAT_FRAC_بٹ - (قوت_نما - 32);                       \
            ret.بلند |= val >> بلند_سرکاؤ;                                   \
            ret.کم = val << (32 - بلند_سرکاؤ);                              \
        }                                                                    \
    } ورنہ {                                                                 \
        ret.بلند = 0;                                                        \
        ret.کم = 1 << قوت_نما;                                                  \
        اگر (قوت_نما > FLOAT_FRAC_بٹ)                                           \
            ret.کم |= val << (قوت_نما - FLOAT_FRAC_بٹ);                       \
        ورنہ                                                                 \
            ret.کم |= val >> (FLOAT_FRAC_بٹ - قوت_نما);                       \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    اگر (with_sign && sign) {                                                 \
        ret.کم = ~ret.کم;                                                  \
        ret.بلند = ~ret.بلند;                                                \
        اگر (ret.کم == UINT_MAX) {                                           \
            ret.کم = 0;                                                     \
            ret.بلند++;                                                      \
        } ورنہ                                                               \
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
#تعریف_کرو DEFINE__AEABI_D2XLZ(name, with_sign)                                 \
خالی __aeabi_ ## name(double_unsigned_struct val)                            \
{                                                                            \
    صحیح قوت_نما, بلند_سرکاؤ, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    اگر ((val.بلند & ~0x80000000) == 0 && val.کم == 0) {                     \
        ret.کم = ret.بلند = 0;                                              \
        جاؤ _ret_;                                                          \
    }                                                                        \
                                                                             \
    /* compute sign */                                                       \
    sign = val.بلند >> 31;                                                   \
                                                                             \
    /* compute real exponent */                                              \
    قوت_نما = (val.بلند >> (DOUBLE_FRAC_بٹ - 32));                             \
    قوت_نما &= (1 << DOUBLE_EXP_بٹ) - 1;                                       \
    قوت_نما -= ONE_EXP(DOUBLE);                                                  \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    اگر (with_sign) {                                                         \
        اگر (قوت_نما > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            واپس;                                                          \
    } ورنہ {                                                                 \
        اگر ((sign && قوت_نما >= 0) || قوت_نما > 63) /* if val < 0 || val too big */  \
            واپس;                                                          \
    }                                                                        \
                                                                             \
    val.بلند &= (1 << (DOUBLE_FRAC_بٹ - 32)) - 1;                          \
    اگر (قوت_نما >= 32) {                                                         \
        ret.بلند = 1 << (قوت_نما - 32);                                          \
        اگر (قوت_نما >= DOUBLE_FRAC_بٹ) {                                       \
            بلند_سرکاؤ = قوت_نما - DOUBLE_FRAC_بٹ;                             \
            ret.بلند |= val.بلند << بلند_سرکاؤ;                              \
            ret.بلند |= val.کم >> (32 - بلند_سرکاؤ);                        \
            ret.کم = val.کم << بلند_سرکاؤ;                                 \
        } ورنہ {                                                             \
            بلند_سرکاؤ = DOUBLE_FRAC_بٹ - قوت_نما;                             \
            ret.بلند |= val.بلند >> بلند_سرکاؤ;                              \
            ret.کم = val.بلند << (32 - بلند_سرکاؤ);                         \
            ret.کم |= val.کم >> بلند_سرکاؤ;                                \
        }                                                                    \
    } ورنہ {                                                                 \
        ret.بلند = 0;                                                        \
        ret.کم = 1 << قوت_نما;                                                  \
        اگر (قوت_نما > DOUBLE_FRAC_بٹ - 32) {                                   \
            بلند_سرکاؤ = قوت_نما - (DOUBLE_FRAC_بٹ - 32);                      \
            ret.کم |= val.بلند << بلند_سرکاؤ;                               \
            ret.کم |= val.کم >> (32 - بلند_سرکاؤ);                         \
        } ورنہ                                                               \
            ret.کم |= val.بلند >> (DOUBLE_FRAC_بٹ - 32 - قوت_نما);            \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    اگر (with_sign && sign) {                                                 \
        ret.کم = ~ret.کم;                                                  \
        ret.بلند = ~ret.بلند;                                                \
        اگر (ret.کم == UINT_MAX) {                                           \
            ret.کم = 0;                                                     \
            ret.بلند++;                                                      \
        } ورنہ                                                               \
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
#تعریف_کرو DEFINE__AEABI_XL2F(name, with_sign)                             \
غیرعلامتی __aeabi_ ## name(غیرعلامتی طویل طویل v)                         \
{                                                                       \
    صحیح s /*سرکاؤ*/, flb /* first lost bit */, sign = 0;              \
    غیرعلامتی p = 0 /* power */, ret;                                    \
    double_unsigned_struct val;                                         \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    اگر (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.کم = v;                                                        \
    val.بلند = v >> 32;                                                 \
    /* fill fraction bits */                                            \
    برائے (s = 31, p = 1 << 31; p && !(val.بلند & p); s--, p >>= 1);      \
    اگر (p) {                                                            \
        ret = val.بلند & (p - 1);                                       \
        اگر (s < FLOAT_FRAC_بٹ) {                                      \
            ret <<= FLOAT_FRAC_بٹ - s;                                \
            ret |= val.کم >> (32 - (FLOAT_FRAC_بٹ - s));             \
            flb = (val.کم >> (32 - (FLOAT_FRAC_بٹ - s - 1))) & 1;    \
        } ورنہ {                                                        \
            flb = (ret >> (s - FLOAT_FRAC_بٹ - 1)) & 1;               \
            ret >>= s - FLOAT_FRAC_بٹ;                                \
        }                                                               \
        s += 32;                                                        \
    } ورنہ {                                                            \
        برائے (s = 31, p = 1 << 31; p && !(val.کم & p); s--, p >>= 1);   \
        اگر (p) {                                                        \
            ret = val.کم & (p - 1);                                    \
            اگر (s <= FLOAT_FRAC_بٹ) {                                 \
                ret <<= FLOAT_FRAC_بٹ - s;                            \
                flb = 0;                                                \
	    } ورنہ {                                                    \
                flb = (ret >> (s - FLOAT_FRAC_بٹ - 1)) & 1;           \
                ret >>= s - FLOAT_FRAC_بٹ;                            \
	    }                                                           \
        } ورنہ                                                          \
            واپس 0;                                                   \
    }                                                                   \
    اگر (flb)                                                            \
        ret++;                                                          \
                                                                        \
    /* fill exponent bits */                                            \
    ret |= (s + ONE_EXP(FLOAT)) << FLOAT_FRAC_بٹ;                     \
                                                                        \
    /* fill sign bit */                                                 \
    ret |= sign << 31;                                                  \
                                                                        \
    واپس ret;                                                         \
}

/* unsigned long long to float conversion */
DEFINE__AEABI_XL2F(ul2f, 0)

/* long long to float conversion */
DEFINE__AEABI_XL2F(l2f, 1)

/* long long to double conversion */
#تعریف_کرو __AEABI_XL2D(name, with_sign)                                   \
خالی __aeabi_ ## name(غیرعلامتی طویل طویل v)                             \
{                                                                       \
    صحیح s /*سرکاؤ*/, بلند_سرکاؤ, sign = 0;                            \
    غیرعلامتی tmp, p = 0;                                                \
    double_unsigned_struct val, ret;                                    \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    اگر (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.کم = v;                                                        \
    val.بلند = v >> 32;                                                 \
                                                                        \
    /* fill fraction bits */                                            \
    برائے (s = 31, p = 1 << 31; p && !(val.بلند & p); s--, p >>= 1);      \
    اگر (p) {                                                            \
        tmp = val.بلند & (p - 1);                                       \
        اگر (s < DOUBLE_FRAC_بٹ - 32) {                                \
            بلند_سرکاؤ = DOUBLE_FRAC_بٹ - 32 - s;                     \
            ret.بلند = tmp << بلند_سرکاؤ;                               \
            ret.بلند |= val.کم >> (32 - بلند_سرکاؤ);                   \
            ret.کم = val.کم << بلند_سرکاؤ;                            \
        } ورنہ {                                                        \
            بلند_سرکاؤ = s - (DOUBLE_FRAC_بٹ - 32);                   \
            ret.بلند = tmp >> بلند_سرکاؤ;                               \
            ret.کم = tmp << (32 - بلند_سرکاؤ);                         \
            ret.کم |= val.کم >> بلند_سرکاؤ;                           \
            اگر ((val.کم >> (بلند_سرکاؤ - 1)) & 1) {                    \
                اگر (ret.کم == UINT_MAX) {                              \
                    ret.بلند++;                                         \
                    ret.کم = 0;                                        \
		} ورنہ                                                  \
                    ret.کم++;                                          \
            }                                                           \
        }                                                               \
        s += 32;                                                        \
    } ورنہ {                                                            \
        برائے (s = 31, p = 1 << 31; p && !(val.کم & p); s--, p >>= 1);   \
        اگر (p) {                                                        \
            tmp = val.کم & (p - 1);                                    \
            اگر (s <= DOUBLE_FRAC_بٹ - 32) {                           \
                بلند_سرکاؤ = DOUBLE_FRAC_بٹ - 32 - s;                 \
                ret.بلند = tmp << بلند_سرکاؤ;                           \
                ret.کم = 0;                                            \
	    } ورنہ {                                                    \
                بلند_سرکاؤ = s - (DOUBLE_FRAC_بٹ - 32);               \
                ret.بلند = tmp >> بلند_سرکاؤ;                           \
                ret.کم = tmp << (32 - بلند_سرکاؤ);                     \
            }                                                           \
        } ورنہ {                                                        \
            ret.بلند = ret.کم = 0;                                     \
            جاؤ _ret_;                                                 \
        }                                                               \
    }                                                                   \
                                                                        \
    /* fill exponent bits */                                            \
    ret.بلند |= (s + ONE_EXP(DOUBLE)) << (DOUBLE_FRAC_بٹ - 32);       \
                                                                        \
    /* fill sign bit */                                                 \
    ret.بلند |= sign << 31;                                             \
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

#تعریف_کرو define_aeabi_xdivmod_signed_type(basetype, type) \
قسمتعریف ساخت type {                                    \
    basetype quot;                                       \
    غیرعلامتی basetype rem;                               \
} type

#تعریف_کرو define_aeabi_xdivmod_unsigned_type(basetype, type) \
قسمتعریف ساخت type {                                      \
    basetype quot;                                         \
    basetype rem;                                          \
} type

#تعریف_کرو AEABI_UXDIVMOD(name,type, rettype, typemacro)                     \
ساکن اندرونی rettype aeabi_ ## name (type عدد, type den)                 \
{                                                                         \
    rettype ret;                                                          \
    type quot = 0;                                                        \
                                                                          \
    /* Increase quotient while it is less than numerator */               \
    جب (عدد >= den) {                                                  \
        type q = 1;                                                       \
                                                                          \
        /* Find closest power of two */                                   \
        جب ((q << 1) * den <= عدد && q * den <= typemacro ## _MAX / 2) \
            q <<= 1;                                                      \
                                                                          \
        /* Compute difference between current quotient and numerator */   \
        عدد -= q * den;                                                   \
        quot += q;                                                        \
    }                                                                     \
    ret.quot = quot;                                                      \
    ret.rem = عدد;                                                        \
    واپس ret;                                                           \
}

#تعریف_کرو __AEABI_XDIVMOD(name, type, uiname, rettype, urettype, typemacro)     \
خالی __aeabi_ ## name(type numerator, type denominator)                       \
{                                                                             \
    غیرعلامتی type عدد, den;                                                   \
    urettype uxdiv_ret;                                                       \
    rettype ret;                                                              \
                                                                              \
    اگر (numerator >= 0)                                                       \
      عدد = numerator;                                                        \
    ورنہ                                                                      \
      عدد = 0 - numerator;                                                    \
    اگر (denominator >= 0)                                                     \
      den = denominator;                                                      \
    ورنہ                                                                      \
      den = 0 - denominator;                                                  \
    uxdiv_ret = aeabi_ ## uiname(عدد, den);                                   \
    /* signs differ */                                                        \
    اگر ((numerator & typemacro ## _MIN) != (denominator & typemacro ## _MIN)) \
        ret.quot = 0 - uxdiv_ret.quot;                                        \
    ورنہ                                                                      \
        ret.quot = uxdiv_ret.quot;                                            \
    اگر (numerator < 0)                                                        \
        ret.rem = 0 - uxdiv_ret.rem;                                          \
    ورنہ                                                                      \
        ret.rem = uxdiv_ret.rem;                                              \
                                                                              \
    rettype ## _return(ret);                                                  \
}

define_aeabi_xdivmod_signed_type(طویل طویل, lldiv_t);
define_aeabi_xdivmod_unsigned_type(غیرعلامتی طویل طویل, ulldiv_t);
define_aeabi_xdivmod_signed_type(صحیح, idiv_t);
define_aeabi_xdivmod_unsigned_type(غیرعلامتی, uidiv_t);

REGS_RETURN(lldiv_t, lldiv_t)
REGS_RETURN(ulldiv_t, ulldiv_t)
REGS_RETURN(idiv_t, idiv_t)
REGS_RETURN(uidiv_t, uidiv_t)

AEABI_UXDIVMOD(uldivmod, غیرعلامتی طویل طویل, ulldiv_t, ULLONG)

__AEABI_XDIVMOD(ldivmod, طویل طویل, uldivmod, lldiv_t, ulldiv_t, LLONG)

خالی __aeabi_uldivmod(غیرعلامتی طویل طویل عدد, غیرعلامتی طویل طویل den)
{
    ulldiv_t_return(aeabi_uldivmod(عدد, den));
}

خالی __aeabi_llsl(double_unsigned_struct val, صحیح سرکاؤ)
{
    double_unsigned_struct ret;

    اگر (سرکاؤ >= 32) {
        val.بلند = val.کم;
        val.کم = 0;
        سرکاؤ -= 32;
    }
    اگر (سرکاؤ > 0) {
        ret.کم = val.کم << سرکاؤ;
        ret.بلند = (val.بلند << سرکاؤ) | (val.کم >> (32 - سرکاؤ));
        double_unsigned_struct_return(ret);
	واپس;
    }
    double_unsigned_struct_return(val);
}

#تعریف_کرو aeabi_lsr(val, سرکاؤ, fill, type)                          \
    type ## _struct ret;                                           \
                                                                   \
    اگر (سرکاؤ >= 32) {                                             \
        val.کم = val.بلند;                                        \
        val.بلند = fill;                                           \
        سرکاؤ -= 32;                                               \
    }                                                              \
    اگر (سرکاؤ > 0) {                                               \
        ret.بلند = val.بلند >> سرکاؤ;                              \
        ret.کم = (val.بلند << (32 - سرکاؤ)) | (val.کم >> سرکاؤ); \
        type ## _struct_return(ret);                               \
	واپس;                                                    \
    }                                                              \
    type ## _struct_return(val);

خالی __aeabi_llsr(double_unsigned_struct val, صحیح سرکاؤ)
{
    aeabi_lsr(val, سرکاؤ, 0, double_unsigned);
}

خالی __aeabi_lasr(unsigned_int_struct val, صحیح سرکاؤ)
{
    aeabi_lsr(val, سرکاؤ, val.بلند >> 31, unsigned_int);
}


/* Integer division functions */

#اگر 0 /* very slow */
AEABI_UXDIVMOD(uidivmod, غیرعلامتی, uidiv_t, UINT)

صحیح __aeabi_idiv(صحیح numerator, صحیح denominator)
{
    غیرعلامتی عدد, den;
    uidiv_t ret;

    اگر (numerator >= 0)
        عدد = numerator;
    ورنہ
        عدد = 0 - numerator;
    اگر (denominator >= 0)
        den = denominator;
    ورنہ
        den = 0 - denominator;
    ret = aeabi_uidivmod(عدد, den);
    اگر ((numerator & INT_MIN) != (denominator & INT_MIN)) /* signs differ */
        ret.quot *= -1;
    واپس ret.quot;
}

غیرعلامتی __aeabi_uidiv(غیرعلامتی عدد, غیرعلامتی den)
{
    واپس aeabi_uidivmod(عدد, den).quot;
}

__AEABI_XDIVMOD(idivmod, صحیح, uidivmod, idiv_t, uidiv_t, INT)

خالی __aeabi_uidivmod(غیرعلامتی عدد, غیرعلامتی den)
{
    uidiv_t_return(aeabi_uidivmod(عدد, den));
}
#ورنہ
# define UIDIVMOD_ASM 1
#اگر_ختم

/* Some targets do not have all eabi calls (OpenBSD) */
قسمتعریف __SIZE_TYPE__ سائز_t;
خارجی خالی *حافظہ_نقل(خالی *dest, ثابت خالی *src, سائز_t n);
خارجی خالی *memmove(خالی *dest, ثابت خالی *src, سائز_t n);
خارجی خالی *memset(خالی *s, صحیح c, سائز_t n);

خالی *
__aeabi_memcpy (خالی *dest, ثابت خالی *src, سائز_t n)
{
    واپس حافظہ_نقل (dest, src, n);
}

خالی *
__aeabi_memmove (خالی *dest, ثابت خالی *src, سائز_t n)
{
    واپس memmove (dest, src, n);
}

خالی *
__aeabi_memmove4 (خالی *dest, ثابت خالی *src, سائز_t n)
{
    واپس memmove (dest, src, n);
}

خالی *
__aeabi_memmove8 (خالی *dest, ثابت خالی *src, سائز_t n)
{
    واپس memmove (dest, src, n);
}

خالی *
__aeabi_memset (خالی *s, سائز_t n, صحیح c)
{
    واپس memset (s, c, n);
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
#ورنہ
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
   "\n  mov     r2, #1"	    //شمار
   "\n  mov     r3, #0"	    //نتیجہ
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
#اگر_ختم
);
#اگر_ختم /* UIDIVMOD_ASM */
/* ***************************************************************** */
#اگر_ختم
