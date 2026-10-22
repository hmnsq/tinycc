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

#جيڪڏهن_وصف_ٿيل __TINYC__
#وصف_ڪريو INT_MIN (-2147483647 - 1)
#وصف_ڪريو وڌ_کان_وڌ_عدد 2147483647
#وصف_ڪريو UINT_MAX 0xffffffff
#وصف_ڪريو LONG_MIN (-2147483647L - 1)
#وصف_ڪريو LONG_MAX 2147483647L
#وصف_ڪريو ULONG_MAX 0xffffffffUL
#وصف_ڪريو LLONG_MAX 9223372036854775807LL
#وصف_ڪريو LLONG_MIN (-9223372036854775807LL - 1)
#وصف_ڪريو ULLONG_MAX 0xffffffffffffffffULL
#وإلا
#ضمن <limits.h>
#جيڪڏهن_پورو

/* We rely on the little endianness and EABI calling convention for this to
   work */

تعريفنوع بنية double_unsigned_struct {
    بنانشان هيٺيون;
    بنانشان مٿاهون;
} double_unsigned_struct;

تعريفنوع بنية unsigned_int_struct {
    بنانشان هيٺيون;
    صحيح مٿاهون;
} unsigned_int_struct;

#وصف_ڪريو REGS_RETURN(name, type) \
    ساكن فراغ name ## _return(type ret) {}


/* Float helper functions */

#وصف_ڪريو FLOAT_EXP_بٽ 8
#وصف_ڪريو FLOAT_FRAC_بٽ 23

#وصف_ڪريو DOUBLE_EXP_بٽ 11
#وصف_ڪريو DOUBLE_FRAC_بٽ 52

#وصف_ڪريو ONE_EXP(type) ((1 << (type ## EXP_بٽ - 1)) - 1)

REGS_RETURN(unsigned_int_struct, unsigned_int_struct)
REGS_RETURN(double_unsigned_struct, double_unsigned_struct)

/* float -> integer: (sign) 1.fraction x 2^(exponent - exp_for_one) */


/* float to [unsigned] long long conversion */
#وصف_ڪريو DEFINE__AEABI_F2XLZ(name, with_sign)                                 \
فراغ __aeabi_ ## name(بنانشان val)                                          \
{                                                                            \
    صحيح قوت_نما, مٿاهون_سرڪايو, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    /* compute sign */                                                       \
    sign = val >> 31;                                                        \
                                                                             \
    /* compute real exponent */                                              \
    قوت_نما = val >> FLOAT_FRAC_بٽ;                                            \
    قوت_نما &= (1 << FLOAT_EXP_بٽ) - 1;                                        \
    قوت_نما -= ONE_EXP(FLOAT);                                                   \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    إذا (with_sign) {                                                         \
        إذا (قوت_نما > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            أرجع;                                                          \
    } وإلا {                                                                 \
        إذا ((sign && قوت_نما >= 0) || قوت_نما > 63) /* if val < 0 || val too big */  \
            أرجع;                                                          \
    }                                                                        \
                                                                             \
    val &= (1 << FLOAT_FRAC_بٽ) - 1;                                       \
    إذا (قوت_نما >= 32) {                                                         \
        ret.مٿاهون = 1 << (قوت_نما - 32);                                          \
        إذا (قوت_نما - 32 >= FLOAT_FRAC_بٽ) {                                   \
            ret.مٿاهون |= val << (قوت_نما - 32 - FLOAT_FRAC_بٽ);                 \
            ret.هيٺيون = 0;                                                     \
        } وإلا {                                                             \
            مٿاهون_سرڪايو = FLOAT_FRAC_بٽ - (قوت_نما - 32);                       \
            ret.مٿاهون |= val >> مٿاهون_سرڪايو;                                   \
            ret.هيٺيون = val << (32 - مٿاهون_سرڪايو);                              \
        }                                                                    \
    } وإلا {                                                                 \
        ret.مٿاهون = 0;                                                        \
        ret.هيٺيون = 1 << قوت_نما;                                                  \
        إذا (قوت_نما > FLOAT_FRAC_بٽ)                                           \
            ret.هيٺيون |= val << (قوت_نما - FLOAT_FRAC_بٽ);                       \
        وإلا                                                                 \
            ret.هيٺيون |= val >> (FLOAT_FRAC_بٽ - قوت_نما);                       \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    إذا (with_sign && sign) {                                                 \
        ret.هيٺيون = ~ret.هيٺيون;                                                  \
        ret.مٿاهون = ~ret.مٿاهون;                                                \
        إذا (ret.هيٺيون == UINT_MAX) {                                           \
            ret.هيٺيون = 0;                                                     \
            ret.مٿاهون++;                                                      \
        } وإلا                                                               \
            ret.هيٺيون++;                                                       \
    }                                                                        \
                                                                             \
    double_unsigned_struct_return(ret);                                      \
}

/* float to unsigned long long conversion */
DEFINE__AEABI_F2XLZ(f2ulz, 0)

/* float to long long conversion */
DEFINE__AEABI_F2XLZ(f2lz, 1)

/* double to [unsigned] long long conversion */
#وصف_ڪريو DEFINE__AEABI_D2XLZ(name, with_sign)                                 \
فراغ __aeabi_ ## name(double_unsigned_struct val)                            \
{                                                                            \
    صحيح قوت_نما, مٿاهون_سرڪايو, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    إذا ((val.مٿاهون & ~0x80000000) == 0 && val.هيٺيون == 0) {                     \
        ret.هيٺيون = ret.مٿاهون = 0;                                              \
        اذهب _ret_;                                                          \
    }                                                                        \
                                                                             \
    /* compute sign */                                                       \
    sign = val.مٿاهون >> 31;                                                   \
                                                                             \
    /* compute real exponent */                                              \
    قوت_نما = (val.مٿاهون >> (DOUBLE_FRAC_بٽ - 32));                             \
    قوت_نما &= (1 << DOUBLE_EXP_بٽ) - 1;                                       \
    قوت_نما -= ONE_EXP(DOUBLE);                                                  \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    إذا (with_sign) {                                                         \
        إذا (قوت_نما > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            أرجع;                                                          \
    } وإلا {                                                                 \
        إذا ((sign && قوت_نما >= 0) || قوت_نما > 63) /* if val < 0 || val too big */  \
            أرجع;                                                          \
    }                                                                        \
                                                                             \
    val.مٿاهون &= (1 << (DOUBLE_FRAC_بٽ - 32)) - 1;                          \
    إذا (قوت_نما >= 32) {                                                         \
        ret.مٿاهون = 1 << (قوت_نما - 32);                                          \
        إذا (قوت_نما >= DOUBLE_FRAC_بٽ) {                                       \
            مٿاهون_سرڪايو = قوت_نما - DOUBLE_FRAC_بٽ;                             \
            ret.مٿاهون |= val.مٿاهون << مٿاهون_سرڪايو;                              \
            ret.مٿاهون |= val.هيٺيون >> (32 - مٿاهون_سرڪايو);                        \
            ret.هيٺيون = val.هيٺيون << مٿاهون_سرڪايو;                                 \
        } وإلا {                                                             \
            مٿاهون_سرڪايو = DOUBLE_FRAC_بٽ - قوت_نما;                             \
            ret.مٿاهون |= val.مٿاهون >> مٿاهون_سرڪايو;                              \
            ret.هيٺيون = val.مٿاهون << (32 - مٿاهون_سرڪايو);                         \
            ret.هيٺيون |= val.هيٺيون >> مٿاهون_سرڪايو;                                \
        }                                                                    \
    } وإلا {                                                                 \
        ret.مٿاهون = 0;                                                        \
        ret.هيٺيون = 1 << قوت_نما;                                                  \
        إذا (قوت_نما > DOUBLE_FRAC_بٽ - 32) {                                   \
            مٿاهون_سرڪايو = قوت_نما - (DOUBLE_FRAC_بٽ - 32);                      \
            ret.هيٺيون |= val.مٿاهون << مٿاهون_سرڪايو;                               \
            ret.هيٺيون |= val.هيٺيون >> (32 - مٿاهون_سرڪايو);                         \
        } وإلا                                                               \
            ret.هيٺيون |= val.مٿاهون >> (DOUBLE_FRAC_بٽ - 32 - قوت_نما);            \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    إذا (with_sign && sign) {                                                 \
        ret.هيٺيون = ~ret.هيٺيون;                                                  \
        ret.مٿاهون = ~ret.مٿاهون;                                                \
        إذا (ret.هيٺيون == UINT_MAX) {                                           \
            ret.هيٺيون = 0;                                                     \
            ret.مٿاهون++;                                                      \
        } وإلا                                                               \
            ret.هيٺيون++;                                                       \
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
#وصف_ڪريو DEFINE__AEABI_XL2F(name, with_sign)                             \
بنانشان __aeabi_ ## name(بنانشان ڊگهو ڊگهو v)                         \
{                                                                       \
    صحيح s /*سرڪايو*/, flb /* first lost bit */, sign = 0;              \
    بنانشان p = 0 /* power */, ret;                                    \
    double_unsigned_struct val;                                         \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    إذا (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.هيٺيون = v;                                                        \
    val.مٿاهون = v >> 32;                                                 \
    /* fill fraction bits */                                            \
    لكل (s = 31, p = 1 << 31; p && !(val.مٿاهون & p); s--, p >>= 1);      \
    إذا (p) {                                                            \
        ret = val.مٿاهون & (p - 1);                                       \
        إذا (s < FLOAT_FRAC_بٽ) {                                      \
            ret <<= FLOAT_FRAC_بٽ - s;                                \
            ret |= val.هيٺيون >> (32 - (FLOAT_FRAC_بٽ - s));             \
            flb = (val.هيٺيون >> (32 - (FLOAT_FRAC_بٽ - s - 1))) & 1;    \
        } وإلا {                                                        \
            flb = (ret >> (s - FLOAT_FRAC_بٽ - 1)) & 1;               \
            ret >>= s - FLOAT_FRAC_بٽ;                                \
        }                                                               \
        s += 32;                                                        \
    } وإلا {                                                            \
        لكل (s = 31, p = 1 << 31; p && !(val.هيٺيون & p); s--, p >>= 1);   \
        إذا (p) {                                                        \
            ret = val.هيٺيون & (p - 1);                                    \
            إذا (s <= FLOAT_FRAC_بٽ) {                                 \
                ret <<= FLOAT_FRAC_بٽ - s;                            \
                flb = 0;                                                \
	    } وإلا {                                                    \
                flb = (ret >> (s - FLOAT_FRAC_بٽ - 1)) & 1;           \
                ret >>= s - FLOAT_FRAC_بٽ;                            \
	    }                                                           \
        } وإلا                                                          \
            أرجع 0;                                                   \
    }                                                                   \
    إذا (flb)                                                            \
        ret++;                                                          \
                                                                        \
    /* fill exponent bits */                                            \
    ret |= (s + ONE_EXP(FLOAT)) << FLOAT_FRAC_بٽ;                     \
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
#وصف_ڪريو __AEABI_XL2D(name, with_sign)                                   \
فراغ __aeabi_ ## name(بنانشان ڊگهو ڊگهو v)                             \
{                                                                       \
    صحيح s /*سرڪايو*/, مٿاهون_سرڪايو, sign = 0;                            \
    بنانشان tmp, p = 0;                                                \
    double_unsigned_struct val, ret;                                    \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    إذا (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.هيٺيون = v;                                                        \
    val.مٿاهون = v >> 32;                                                 \
                                                                        \
    /* fill fraction bits */                                            \
    لكل (s = 31, p = 1 << 31; p && !(val.مٿاهون & p); s--, p >>= 1);      \
    إذا (p) {                                                            \
        tmp = val.مٿاهون & (p - 1);                                       \
        إذا (s < DOUBLE_FRAC_بٽ - 32) {                                \
            مٿاهون_سرڪايو = DOUBLE_FRAC_بٽ - 32 - s;                     \
            ret.مٿاهون = tmp << مٿاهون_سرڪايو;                               \
            ret.مٿاهون |= val.هيٺيون >> (32 - مٿاهون_سرڪايو);                   \
            ret.هيٺيون = val.هيٺيون << مٿاهون_سرڪايو;                            \
        } وإلا {                                                        \
            مٿاهون_سرڪايو = s - (DOUBLE_FRAC_بٽ - 32);                   \
            ret.مٿاهون = tmp >> مٿاهون_سرڪايو;                               \
            ret.هيٺيون = tmp << (32 - مٿاهون_سرڪايو);                         \
            ret.هيٺيون |= val.هيٺيون >> مٿاهون_سرڪايو;                           \
            إذا ((val.هيٺيون >> (مٿاهون_سرڪايو - 1)) & 1) {                    \
                إذا (ret.هيٺيون == UINT_MAX) {                              \
                    ret.مٿاهون++;                                         \
                    ret.هيٺيون = 0;                                        \
		} وإلا                                                  \
                    ret.هيٺيون++;                                          \
            }                                                           \
        }                                                               \
        s += 32;                                                        \
    } وإلا {                                                            \
        لكل (s = 31, p = 1 << 31; p && !(val.هيٺيون & p); s--, p >>= 1);   \
        إذا (p) {                                                        \
            tmp = val.هيٺيون & (p - 1);                                    \
            إذا (s <= DOUBLE_FRAC_بٽ - 32) {                           \
                مٿاهون_سرڪايو = DOUBLE_FRAC_بٽ - 32 - s;                 \
                ret.مٿاهون = tmp << مٿاهون_سرڪايو;                           \
                ret.هيٺيون = 0;                                            \
	    } وإلا {                                                    \
                مٿاهون_سرڪايو = s - (DOUBLE_FRAC_بٽ - 32);               \
                ret.مٿاهون = tmp >> مٿاهون_سرڪايو;                           \
                ret.هيٺيون = tmp << (32 - مٿاهون_سرڪايو);                     \
            }                                                           \
        } وإلا {                                                        \
            ret.مٿاهون = ret.هيٺيون = 0;                                     \
            اذهب _ret_;                                                 \
        }                                                               \
    }                                                                   \
                                                                        \
    /* fill exponent bits */                                            \
    ret.مٿاهون |= (s + ONE_EXP(DOUBLE)) << (DOUBLE_FRAC_بٽ - 32);       \
                                                                        \
    /* fill sign bit */                                                 \
    ret.مٿاهون |= sign << 31;                                             \
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

#وصف_ڪريو define_aeabi_xdivmod_signed_type(basetype, type) \
تعريفنوع بنية type {                                    \
    basetype quot;                                       \
    بنانشان basetype rem;                               \
} type

#وصف_ڪريو define_aeabi_xdivmod_unsigned_type(basetype, type) \
تعريفنوع بنية type {                                      \
    basetype quot;                                         \
    basetype rem;                                          \
} type

#وصف_ڪريو AEABI_UXDIVMOD(name,type, rettype, typemacro)                     \
ساكن مضمن rettype aeabi_ ## name (type انگ, type den)                 \
{                                                                         \
    rettype ret;                                                          \
    type quot = 0;                                                        \
                                                                          \
    /* Increase quotient while it is less than numerator */               \
    طالما (انگ >= den) {                                                  \
        type q = 1;                                                       \
                                                                          \
        /* Find closest power of two */                                   \
        طالما ((q << 1) * den <= انگ && q * den <= typemacro ## _MAX / 2) \
            q <<= 1;                                                      \
                                                                          \
        /* Compute difference between current quotient and numerator */   \
        انگ -= q * den;                                                   \
        quot += q;                                                        \
    }                                                                     \
    ret.quot = quot;                                                      \
    ret.rem = انگ;                                                        \
    أرجع ret;                                                           \
}

#وصف_ڪريو __AEABI_XDIVMOD(name, type, uiname, rettype, urettype, typemacro)     \
فراغ __aeabi_ ## name(type numerator, type denominator)                       \
{                                                                             \
    بنانشان type انگ, den;                                                   \
    urettype uxdiv_ret;                                                       \
    rettype ret;                                                              \
                                                                              \
    إذا (numerator >= 0)                                                       \
      انگ = numerator;                                                        \
    وإلا                                                                      \
      انگ = 0 - numerator;                                                    \
    إذا (denominator >= 0)                                                     \
      den = denominator;                                                      \
    وإلا                                                                      \
      den = 0 - denominator;                                                  \
    uxdiv_ret = aeabi_ ## uiname(انگ, den);                                   \
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

define_aeabi_xdivmod_signed_type(ڊگهو ڊگهو, lldiv_t);
define_aeabi_xdivmod_unsigned_type(بنانشان ڊگهو ڊگهو, ulldiv_t);
define_aeabi_xdivmod_signed_type(صحيح, idiv_t);
define_aeabi_xdivmod_unsigned_type(بنانشان, uidiv_t);

REGS_RETURN(lldiv_t, lldiv_t)
REGS_RETURN(ulldiv_t, ulldiv_t)
REGS_RETURN(idiv_t, idiv_t)
REGS_RETURN(uidiv_t, uidiv_t)

AEABI_UXDIVMOD(uldivmod, بنانشان ڊگهو ڊگهو, ulldiv_t, ULLONG)

__AEABI_XDIVMOD(ldivmod, ڊگهو ڊگهو, uldivmod, lldiv_t, ulldiv_t, LLONG)

فراغ __aeabi_uldivmod(بنانشان ڊگهو ڊگهو انگ, بنانشان ڊگهو ڊگهو den)
{
    ulldiv_t_return(aeabi_uldivmod(انگ, den));
}

فراغ __aeabi_llsl(double_unsigned_struct val, صحيح سرڪايو)
{
    double_unsigned_struct ret;

    إذا (سرڪايو >= 32) {
        val.مٿاهون = val.هيٺيون;
        val.هيٺيون = 0;
        سرڪايو -= 32;
    }
    إذا (سرڪايو > 0) {
        ret.هيٺيون = val.هيٺيون << سرڪايو;
        ret.مٿاهون = (val.مٿاهون << سرڪايو) | (val.هيٺيون >> (32 - سرڪايو));
        double_unsigned_struct_return(ret);
	أرجع;
    }
    double_unsigned_struct_return(val);
}

#وصف_ڪريو aeabi_lsr(val, سرڪايو, fill, type)                          \
    type ## _struct ret;                                           \
                                                                   \
    إذا (سرڪايو >= 32) {                                             \
        val.هيٺيون = val.مٿاهون;                                        \
        val.مٿاهون = fill;                                           \
        سرڪايو -= 32;                                               \
    }                                                              \
    إذا (سرڪايو > 0) {                                               \
        ret.مٿاهون = val.مٿاهون >> سرڪايو;                              \
        ret.هيٺيون = (val.مٿاهون << (32 - سرڪايو)) | (val.هيٺيون >> سرڪايو); \
        type ## _struct_return(ret);                               \
	أرجع;                                                    \
    }                                                              \
    type ## _struct_return(val);

فراغ __aeabi_llsr(double_unsigned_struct val, صحيح سرڪايو)
{
    aeabi_lsr(val, سرڪايو, 0, double_unsigned);
}

فراغ __aeabi_lasr(unsigned_int_struct val, صحيح سرڪايو)
{
    aeabi_lsr(val, سرڪايو, val.مٿاهون >> 31, unsigned_int);
}


/* Integer division functions */

#إذا 0 /* very slow */
AEABI_UXDIVMOD(uidivmod, بنانشان, uidiv_t, UINT)

صحيح __aeabi_idiv(صحيح numerator, صحيح denominator)
{
    بنانشان انگ, den;
    uidiv_t ret;

    إذا (numerator >= 0)
        انگ = numerator;
    وإلا
        انگ = 0 - numerator;
    إذا (denominator >= 0)
        den = denominator;
    وإلا
        den = 0 - denominator;
    ret = aeabi_uidivmod(انگ, den);
    إذا ((numerator & INT_MIN) != (denominator & INT_MIN)) /* signs differ */
        ret.quot *= -1;
    أرجع ret.quot;
}

بنانشان __aeabi_uidiv(بنانشان انگ, بنانشان den)
{
    أرجع aeabi_uidivmod(انگ, den).quot;
}

__AEABI_XDIVMOD(idivmod, صحيح, uidivmod, idiv_t, uidiv_t, INT)

فراغ __aeabi_uidivmod(بنانشان انگ, بنانشان den)
{
    uidiv_t_return(aeabi_uidivmod(انگ, den));
}
#وإلا
# define UIDIVMOD_ASM 1
#جيڪڏهن_پورو

/* Some targets do not have all eabi calls (OpenBSD) */
تعريفنوع __SIZE_TYPE__ سائيز_t;
خارجي فراغ *يادگيري_نقل(فراغ *dest, ثابت فراغ *src, سائيز_t n);
خارجي فراغ *memmove(فراغ *dest, ثابت فراغ *src, سائيز_t n);
خارجي فراغ *memset(فراغ *s, صحيح c, سائيز_t n);

فراغ *
__aeabi_memcpy (فراغ *dest, ثابت فراغ *src, سائيز_t n)
{
    أرجع يادگيري_نقل (dest, src, n);
}

فراغ *
__aeabi_memmove (فراغ *dest, ثابت فراغ *src, سائيز_t n)
{
    أرجع memmove (dest, src, n);
}

فراغ *
__aeabi_memmove4 (فراغ *dest, ثابت فراغ *src, سائيز_t n)
{
    أرجع memmove (dest, src, n);
}

فراغ *
__aeabi_memmove8 (فراغ *dest, ثابت فراغ *src, سائيز_t n)
{
    أرجع memmove (dest, src, n);
}

فراغ *
__aeabi_memset (فراغ *s, سائيز_t n, صحيح c)
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
   "\n  mov     r3, #0"	    //نتيجو
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
#جيڪڏهن_پورو
);
#جيڪڏهن_پورو /* UIDIVMOD_ASM */
/* ***************************************************************** */
#جيڪڏهن_پورو
