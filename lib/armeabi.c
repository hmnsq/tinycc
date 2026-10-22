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

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __TINYC__
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT_MIN (-2147483647 - 1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵੱਧ_ਤੋਂ_ਵੱਧ_ਅੰਕ 2147483647
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINT_MAX 0xffffffff
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LONG_MIN (-2147483647L - 1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LONG_MAX 2147483647L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ULONG_MAX 0xffffffffUL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LLONG_MAX 9223372036854775807LL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LLONG_MIN (-9223372036854775807LL - 1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ULLONG_MAX 0xffffffffffffffffULL
#ਨਹੀਂਤਾਂ
#ਅਨ੍ਤਰ੍ਭਾਵ <limits.h>
#ਜੇ_ਅੰਤ

/* We rely on the little endianness and EABI calling convention for this to
   work */

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ double_unsigned_struct {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਨੀਵਾਂ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਉੱਚਾ;
} double_unsigned_struct;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ unsigned_int_struct {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਨੀਵਾਂ;
    ਪੂਰਨ ਉੱਚਾ;
} unsigned_int_struct;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REGS_RETURN(name, type) \
    ਸਥਿਰ ਖਾਲੀ name ## _return(type ret) {}


/* Float helper functions */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLOAT_EXP_ਬਿੱਟ 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLOAT_FRAC_ਬਿੱਟ 23

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOUBLE_EXP_ਬਿੱਟ 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOUBLE_FRAC_ਬਿੱਟ 52

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ONE_EXP(type) ((1 << (type ## EXP_ਬਿੱਟ - 1)) - 1)

REGS_RETURN(unsigned_int_struct, unsigned_int_struct)
REGS_RETURN(double_unsigned_struct, double_unsigned_struct)

/* float -> integer: (sign) 1.fraction x 2^(exponent - exp_for_one) */


/* float to [unsigned] long long conversion */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEFINE__AEABI_F2XLZ(name, with_sign)                                 \
ਖਾਲੀ __aeabi_ ## name(ਬਿਨਾਨਿਸ਼ਾਨੀ val)                                          \
{                                                                            \
    ਪੂਰਨ ਘਾਤਾਂਕ, ਉੱਚਾ_ਖਿਸਕਾਓ, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    /* compute sign */                                                       \
    sign = val >> 31;                                                        \
                                                                             \
    /* compute real exponent */                                              \
    ਘਾਤਾਂਕ = val >> FLOAT_FRAC_ਬਿੱਟ;                                            \
    ਘਾਤਾਂਕ &= (1 << FLOAT_EXP_ਬਿੱਟ) - 1;                                        \
    ਘਾਤਾਂਕ -= ONE_EXP(FLOAT);                                                   \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    ਜੇ (with_sign) {                                                         \
        ਜੇ (ਘਾਤਾਂਕ > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            ਵਾਪਸ;                                                          \
    } ਨਹੀਂਤਾਂ {                                                                 \
        ਜੇ ((sign && ਘਾਤਾਂਕ >= 0) || ਘਾਤਾਂਕ > 63) /* if val < 0 || val too big */  \
            ਵਾਪਸ;                                                          \
    }                                                                        \
                                                                             \
    val &= (1 << FLOAT_FRAC_ਬਿੱਟ) - 1;                                       \
    ਜੇ (ਘਾਤਾਂਕ >= 32) {                                                         \
        ret.ਉੱਚਾ = 1 << (ਘਾਤਾਂਕ - 32);                                          \
        ਜੇ (ਘਾਤਾਂਕ - 32 >= FLOAT_FRAC_ਬਿੱਟ) {                                   \
            ret.ਉੱਚਾ |= val << (ਘਾਤਾਂਕ - 32 - FLOAT_FRAC_ਬਿੱਟ);                 \
            ret.ਨੀਵਾਂ = 0;                                                     \
        } ਨਹੀਂਤਾਂ {                                                             \
            ਉੱਚਾ_ਖਿਸਕਾਓ = FLOAT_FRAC_ਬਿੱਟ - (ਘਾਤਾਂਕ - 32);                       \
            ret.ਉੱਚਾ |= val >> ਉੱਚਾ_ਖਿਸਕਾਓ;                                   \
            ret.ਨੀਵਾਂ = val << (32 - ਉੱਚਾ_ਖਿਸਕਾਓ);                              \
        }                                                                    \
    } ਨਹੀਂਤਾਂ {                                                                 \
        ret.ਉੱਚਾ = 0;                                                        \
        ret.ਨੀਵਾਂ = 1 << ਘਾਤਾਂਕ;                                                  \
        ਜੇ (ਘਾਤਾਂਕ > FLOAT_FRAC_ਬਿੱਟ)                                           \
            ret.ਨੀਵਾਂ |= val << (ਘਾਤਾਂਕ - FLOAT_FRAC_ਬਿੱਟ);                       \
        ਨਹੀਂਤਾਂ                                                                 \
            ret.ਨੀਵਾਂ |= val >> (FLOAT_FRAC_ਬਿੱਟ - ਘਾਤਾਂਕ);                       \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    ਜੇ (with_sign && sign) {                                                 \
        ret.ਨੀਵਾਂ = ~ret.ਨੀਵਾਂ;                                                  \
        ret.ਉੱਚਾ = ~ret.ਉੱਚਾ;                                                \
        ਜੇ (ret.ਨੀਵਾਂ == UINT_MAX) {                                           \
            ret.ਨੀਵਾਂ = 0;                                                     \
            ret.ਉੱਚਾ++;                                                      \
        } ਨਹੀਂਤਾਂ                                                               \
            ret.ਨੀਵਾਂ++;                                                       \
    }                                                                        \
                                                                             \
    double_unsigned_struct_return(ret);                                      \
}

/* float to unsigned long long conversion */
DEFINE__AEABI_F2XLZ(f2ulz, 0)

/* float to long long conversion */
DEFINE__AEABI_F2XLZ(f2lz, 1)

/* double to [unsigned] long long conversion */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEFINE__AEABI_D2XLZ(name, with_sign)                                 \
ਖਾਲੀ __aeabi_ ## name(double_unsigned_struct val)                            \
{                                                                            \
    ਪੂਰਨ ਘਾਤਾਂਕ, ਉੱਚਾ_ਖਿਸਕਾਓ, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    ਜੇ ((val.ਉੱਚਾ & ~0x80000000) == 0 && val.ਨੀਵਾਂ == 0) {                     \
        ret.ਨੀਵਾਂ = ret.ਉੱਚਾ = 0;                                              \
        ਜਾਓ _ret_;                                                          \
    }                                                                        \
                                                                             \
    /* compute sign */                                                       \
    sign = val.ਉੱਚਾ >> 31;                                                   \
                                                                             \
    /* compute real exponent */                                              \
    ਘਾਤਾਂਕ = (val.ਉੱਚਾ >> (DOUBLE_FRAC_ਬਿੱਟ - 32));                             \
    ਘਾਤਾਂਕ &= (1 << DOUBLE_EXP_ਬਿੱਟ) - 1;                                       \
    ਘਾਤਾਂਕ -= ONE_EXP(DOUBLE);                                                  \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    ਜੇ (with_sign) {                                                         \
        ਜੇ (ਘਾਤਾਂਕ > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            ਵਾਪਸ;                                                          \
    } ਨਹੀਂਤਾਂ {                                                                 \
        ਜੇ ((sign && ਘਾਤਾਂਕ >= 0) || ਘਾਤਾਂਕ > 63) /* if val < 0 || val too big */  \
            ਵਾਪਸ;                                                          \
    }                                                                        \
                                                                             \
    val.ਉੱਚਾ &= (1 << (DOUBLE_FRAC_ਬਿੱਟ - 32)) - 1;                          \
    ਜੇ (ਘਾਤਾਂਕ >= 32) {                                                         \
        ret.ਉੱਚਾ = 1 << (ਘਾਤਾਂਕ - 32);                                          \
        ਜੇ (ਘਾਤਾਂਕ >= DOUBLE_FRAC_ਬਿੱਟ) {                                       \
            ਉੱਚਾ_ਖਿਸਕਾਓ = ਘਾਤਾਂਕ - DOUBLE_FRAC_ਬਿੱਟ;                             \
            ret.ਉੱਚਾ |= val.ਉੱਚਾ << ਉੱਚਾ_ਖਿਸਕਾਓ;                              \
            ret.ਉੱਚਾ |= val.ਨੀਵਾਂ >> (32 - ਉੱਚਾ_ਖਿਸਕਾਓ);                        \
            ret.ਨੀਵਾਂ = val.ਨੀਵਾਂ << ਉੱਚਾ_ਖਿਸਕਾਓ;                                 \
        } ਨਹੀਂਤਾਂ {                                                             \
            ਉੱਚਾ_ਖਿਸਕਾਓ = DOUBLE_FRAC_ਬਿੱਟ - ਘਾਤਾਂਕ;                             \
            ret.ਉੱਚਾ |= val.ਉੱਚਾ >> ਉੱਚਾ_ਖਿਸਕਾਓ;                              \
            ret.ਨੀਵਾਂ = val.ਉੱਚਾ << (32 - ਉੱਚਾ_ਖਿਸਕਾਓ);                         \
            ret.ਨੀਵਾਂ |= val.ਨੀਵਾਂ >> ਉੱਚਾ_ਖਿਸਕਾਓ;                                \
        }                                                                    \
    } ਨਹੀਂਤਾਂ {                                                                 \
        ret.ਉੱਚਾ = 0;                                                        \
        ret.ਨੀਵਾਂ = 1 << ਘਾਤਾਂਕ;                                                  \
        ਜੇ (ਘਾਤਾਂਕ > DOUBLE_FRAC_ਬਿੱਟ - 32) {                                   \
            ਉੱਚਾ_ਖਿਸਕਾਓ = ਘਾਤਾਂਕ - (DOUBLE_FRAC_ਬਿੱਟ - 32);                      \
            ret.ਨੀਵਾਂ |= val.ਉੱਚਾ << ਉੱਚਾ_ਖਿਸਕਾਓ;                               \
            ret.ਨੀਵਾਂ |= val.ਨੀਵਾਂ >> (32 - ਉੱਚਾ_ਖਿਸਕਾਓ);                         \
        } ਨਹੀਂਤਾਂ                                                               \
            ret.ਨੀਵਾਂ |= val.ਉੱਚਾ >> (DOUBLE_FRAC_ਬਿੱਟ - 32 - ਘਾਤਾਂਕ);            \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    ਜੇ (with_sign && sign) {                                                 \
        ret.ਨੀਵਾਂ = ~ret.ਨੀਵਾਂ;                                                  \
        ret.ਉੱਚਾ = ~ret.ਉੱਚਾ;                                                \
        ਜੇ (ret.ਨੀਵਾਂ == UINT_MAX) {                                           \
            ret.ਨੀਵਾਂ = 0;                                                     \
            ret.ਉੱਚਾ++;                                                      \
        } ਨਹੀਂਤਾਂ                                                               \
            ret.ਨੀਵਾਂ++;                                                       \
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
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEFINE__AEABI_XL2F(name, with_sign)                             \
ਬਿਨਾਨਿਸ਼ਾਨੀ __aeabi_ ## name(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ v)                         \
{                                                                       \
    ਪੂਰਨ s /*ਖਿਸਕਾਓ*/, flb /* first lost bit */, sign = 0;              \
    ਬਿਨਾਨਿਸ਼ਾਨੀ p = 0 /* power */, ret;                                    \
    double_unsigned_struct val;                                         \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    ਜੇ (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.ਨੀਵਾਂ = v;                                                        \
    val.ਉੱਚਾ = v >> 32;                                                 \
    /* fill fraction bits */                                            \
    ਲਈ (s = 31, p = 1 << 31; p && !(val.ਉੱਚਾ & p); s--, p >>= 1);      \
    ਜੇ (p) {                                                            \
        ret = val.ਉੱਚਾ & (p - 1);                                       \
        ਜੇ (s < FLOAT_FRAC_ਬਿੱਟ) {                                      \
            ret <<= FLOAT_FRAC_ਬਿੱਟ - s;                                \
            ret |= val.ਨੀਵਾਂ >> (32 - (FLOAT_FRAC_ਬਿੱਟ - s));             \
            flb = (val.ਨੀਵਾਂ >> (32 - (FLOAT_FRAC_ਬਿੱਟ - s - 1))) & 1;    \
        } ਨਹੀਂਤਾਂ {                                                        \
            flb = (ret >> (s - FLOAT_FRAC_ਬਿੱਟ - 1)) & 1;               \
            ret >>= s - FLOAT_FRAC_ਬਿੱਟ;                                \
        }                                                               \
        s += 32;                                                        \
    } ਨਹੀਂਤਾਂ {                                                            \
        ਲਈ (s = 31, p = 1 << 31; p && !(val.ਨੀਵਾਂ & p); s--, p >>= 1);   \
        ਜੇ (p) {                                                        \
            ret = val.ਨੀਵਾਂ & (p - 1);                                    \
            ਜੇ (s <= FLOAT_FRAC_ਬਿੱਟ) {                                 \
                ret <<= FLOAT_FRAC_ਬਿੱਟ - s;                            \
                flb = 0;                                                \
	    } ਨਹੀਂਤਾਂ {                                                    \
                flb = (ret >> (s - FLOAT_FRAC_ਬਿੱਟ - 1)) & 1;           \
                ret >>= s - FLOAT_FRAC_ਬਿੱਟ;                            \
	    }                                                           \
        } ਨਹੀਂਤਾਂ                                                          \
            ਵਾਪਸ 0;                                                   \
    }                                                                   \
    ਜੇ (flb)                                                            \
        ret++;                                                          \
                                                                        \
    /* fill exponent bits */                                            \
    ret |= (s + ONE_EXP(FLOAT)) << FLOAT_FRAC_ਬਿੱਟ;                     \
                                                                        \
    /* fill sign bit */                                                 \
    ret |= sign << 31;                                                  \
                                                                        \
    ਵਾਪਸ ret;                                                         \
}

/* unsigned long long to float conversion */
DEFINE__AEABI_XL2F(ul2f, 0)

/* long long to float conversion */
DEFINE__AEABI_XL2F(l2f, 1)

/* long long to double conversion */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __AEABI_XL2D(name, with_sign)                                   \
ਖਾਲੀ __aeabi_ ## name(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ v)                             \
{                                                                       \
    ਪੂਰਨ s /*ਖਿਸਕਾਓ*/, ਉੱਚਾ_ਖਿਸਕਾਓ, sign = 0;                            \
    ਬਿਨਾਨਿਸ਼ਾਨੀ tmp, p = 0;                                                \
    double_unsigned_struct val, ret;                                    \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    ਜੇ (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.ਨੀਵਾਂ = v;                                                        \
    val.ਉੱਚਾ = v >> 32;                                                 \
                                                                        \
    /* fill fraction bits */                                            \
    ਲਈ (s = 31, p = 1 << 31; p && !(val.ਉੱਚਾ & p); s--, p >>= 1);      \
    ਜੇ (p) {                                                            \
        tmp = val.ਉੱਚਾ & (p - 1);                                       \
        ਜੇ (s < DOUBLE_FRAC_ਬਿੱਟ - 32) {                                \
            ਉੱਚਾ_ਖਿਸਕਾਓ = DOUBLE_FRAC_ਬਿੱਟ - 32 - s;                     \
            ret.ਉੱਚਾ = tmp << ਉੱਚਾ_ਖਿਸਕਾਓ;                               \
            ret.ਉੱਚਾ |= val.ਨੀਵਾਂ >> (32 - ਉੱਚਾ_ਖਿਸਕਾਓ);                   \
            ret.ਨੀਵਾਂ = val.ਨੀਵਾਂ << ਉੱਚਾ_ਖਿਸਕਾਓ;                            \
        } ਨਹੀਂਤਾਂ {                                                        \
            ਉੱਚਾ_ਖਿਸਕਾਓ = s - (DOUBLE_FRAC_ਬਿੱਟ - 32);                   \
            ret.ਉੱਚਾ = tmp >> ਉੱਚਾ_ਖਿਸਕਾਓ;                               \
            ret.ਨੀਵਾਂ = tmp << (32 - ਉੱਚਾ_ਖਿਸਕਾਓ);                         \
            ret.ਨੀਵਾਂ |= val.ਨੀਵਾਂ >> ਉੱਚਾ_ਖਿਸਕਾਓ;                           \
            ਜੇ ((val.ਨੀਵਾਂ >> (ਉੱਚਾ_ਖਿਸਕਾਓ - 1)) & 1) {                    \
                ਜੇ (ret.ਨੀਵਾਂ == UINT_MAX) {                              \
                    ret.ਉੱਚਾ++;                                         \
                    ret.ਨੀਵਾਂ = 0;                                        \
		} ਨਹੀਂਤਾਂ                                                  \
                    ret.ਨੀਵਾਂ++;                                          \
            }                                                           \
        }                                                               \
        s += 32;                                                        \
    } ਨਹੀਂਤਾਂ {                                                            \
        ਲਈ (s = 31, p = 1 << 31; p && !(val.ਨੀਵਾਂ & p); s--, p >>= 1);   \
        ਜੇ (p) {                                                        \
            tmp = val.ਨੀਵਾਂ & (p - 1);                                    \
            ਜੇ (s <= DOUBLE_FRAC_ਬਿੱਟ - 32) {                           \
                ਉੱਚਾ_ਖਿਸਕਾਓ = DOUBLE_FRAC_ਬਿੱਟ - 32 - s;                 \
                ret.ਉੱਚਾ = tmp << ਉੱਚਾ_ਖਿਸਕਾਓ;                           \
                ret.ਨੀਵਾਂ = 0;                                            \
	    } ਨਹੀਂਤਾਂ {                                                    \
                ਉੱਚਾ_ਖਿਸਕਾਓ = s - (DOUBLE_FRAC_ਬਿੱਟ - 32);               \
                ret.ਉੱਚਾ = tmp >> ਉੱਚਾ_ਖਿਸਕਾਓ;                           \
                ret.ਨੀਵਾਂ = tmp << (32 - ਉੱਚਾ_ਖਿਸਕਾਓ);                     \
            }                                                           \
        } ਨਹੀਂਤਾਂ {                                                        \
            ret.ਉੱਚਾ = ret.ਨੀਵਾਂ = 0;                                     \
            ਜਾਓ _ret_;                                                 \
        }                                                               \
    }                                                                   \
                                                                        \
    /* fill exponent bits */                                            \
    ret.ਉੱਚਾ |= (s + ONE_EXP(DOUBLE)) << (DOUBLE_FRAC_ਬਿੱਟ - 32);       \
                                                                        \
    /* fill sign bit */                                                 \
    ret.ਉੱਚਾ |= sign << 31;                                             \
                                                                        \
_ret_:                                                                  \
    double_unsigned_struct_return(ret);                                 \
}

/* unsigned long long to double conversion */
__AEABI_XL2D(ul2d, 0)

/* long long to double conversion */
__AEABI_XL2D(l2d, 1)

#ਜੇ 1
/* Long long helper functions */

/* TODO: add error in case of den == 0 (see §4.3.1 and §4.3.2) */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ define_aeabi_xdivmod_signed_type(basetype, type) \
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ type {                                    \
    basetype quot;                                       \
    ਬਿਨਾਨਿਸ਼ਾਨੀ basetype rem;                               \
} type

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ define_aeabi_xdivmod_unsigned_type(basetype, type) \
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ type {                                      \
    basetype quot;                                         \
    basetype rem;                                          \
} type

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AEABI_UXDIVMOD(name,type, rettype, typemacro)                     \
ਸਥਿਰ ਸਤਰਅੰਦਰ rettype aeabi_ ## name (type ਅੰਕ, type den)                 \
{                                                                         \
    rettype ret;                                                          \
    type quot = 0;                                                        \
                                                                          \
    /* Increase quotient while it is less than numerator */               \
    ਜਦੋਂ (ਅੰਕ >= den) {                                                  \
        type q = 1;                                                       \
                                                                          \
        /* Find closest power of two */                                   \
        ਜਦੋਂ ((q << 1) * den <= ਅੰਕ && q * den <= typemacro ## _MAX / 2) \
            q <<= 1;                                                      \
                                                                          \
        /* Compute difference between current quotient and numerator */   \
        ਅੰਕ -= q * den;                                                   \
        quot += q;                                                        \
    }                                                                     \
    ret.quot = quot;                                                      \
    ret.rem = ਅੰਕ;                                                        \
    ਵਾਪਸ ret;                                                           \
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __AEABI_XDIVMOD(name, type, uiname, rettype, urettype, typemacro)     \
ਖਾਲੀ __aeabi_ ## name(type numerator, type denominator)                       \
{                                                                             \
    ਬਿਨਾਨਿਸ਼ਾਨੀ type ਅੰਕ, den;                                                   \
    urettype uxdiv_ret;                                                       \
    rettype ret;                                                              \
                                                                              \
    ਜੇ (numerator >= 0)                                                       \
      ਅੰਕ = numerator;                                                        \
    ਨਹੀਂਤਾਂ                                                                      \
      ਅੰਕ = 0 - numerator;                                                    \
    ਜੇ (denominator >= 0)                                                     \
      den = denominator;                                                      \
    ਨਹੀਂਤਾਂ                                                                      \
      den = 0 - denominator;                                                  \
    uxdiv_ret = aeabi_ ## uiname(ਅੰਕ, den);                                   \
    /* signs differ */                                                        \
    ਜੇ ((numerator & typemacro ## _MIN) != (denominator & typemacro ## _MIN)) \
        ret.quot = 0 - uxdiv_ret.quot;                                        \
    ਨਹੀਂਤਾਂ                                                                      \
        ret.quot = uxdiv_ret.quot;                                            \
    ਜੇ (numerator < 0)                                                        \
        ret.rem = 0 - uxdiv_ret.rem;                                          \
    ਨਹੀਂਤਾਂ                                                                      \
        ret.rem = uxdiv_ret.rem;                                              \
                                                                              \
    rettype ## _return(ret);                                                  \
}

define_aeabi_xdivmod_signed_type(ਲੰਮਾ ਲੰਮਾ, lldiv_t);
define_aeabi_xdivmod_unsigned_type(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ, ulldiv_t);
define_aeabi_xdivmod_signed_type(ਪੂਰਨ, idiv_t);
define_aeabi_xdivmod_unsigned_type(ਬਿਨਾਨਿਸ਼ਾਨੀ, uidiv_t);

REGS_RETURN(lldiv_t, lldiv_t)
REGS_RETURN(ulldiv_t, ulldiv_t)
REGS_RETURN(idiv_t, idiv_t)
REGS_RETURN(uidiv_t, uidiv_t)

AEABI_UXDIVMOD(uldivmod, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ, ulldiv_t, ULLONG)

__AEABI_XDIVMOD(ldivmod, ਲੰਮਾ ਲੰਮਾ, uldivmod, lldiv_t, ulldiv_t, LLONG)

ਖਾਲੀ __aeabi_uldivmod(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ਅੰਕ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ den)
{
    ulldiv_t_return(aeabi_uldivmod(ਅੰਕ, den));
}

ਖਾਲੀ __aeabi_llsl(double_unsigned_struct val, ਪੂਰਨ ਖਿਸਕਾਓ)
{
    double_unsigned_struct ret;

    ਜੇ (ਖਿਸਕਾਓ >= 32) {
        val.ਉੱਚਾ = val.ਨੀਵਾਂ;
        val.ਨੀਵਾਂ = 0;
        ਖਿਸਕਾਓ -= 32;
    }
    ਜੇ (ਖਿਸਕਾਓ > 0) {
        ret.ਨੀਵਾਂ = val.ਨੀਵਾਂ << ਖਿਸਕਾਓ;
        ret.ਉੱਚਾ = (val.ਉੱਚਾ << ਖਿਸਕਾਓ) | (val.ਨੀਵਾਂ >> (32 - ਖਿਸਕਾਓ));
        double_unsigned_struct_return(ret);
	ਵਾਪਸ;
    }
    double_unsigned_struct_return(val);
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ aeabi_lsr(val, ਖਿਸਕਾਓ, fill, type)                          \
    type ## _struct ret;                                           \
                                                                   \
    ਜੇ (ਖਿਸਕਾਓ >= 32) {                                             \
        val.ਨੀਵਾਂ = val.ਉੱਚਾ;                                        \
        val.ਉੱਚਾ = fill;                                           \
        ਖਿਸਕਾਓ -= 32;                                               \
    }                                                              \
    ਜੇ (ਖਿਸਕਾਓ > 0) {                                               \
        ret.ਉੱਚਾ = val.ਉੱਚਾ >> ਖਿਸਕਾਓ;                              \
        ret.ਨੀਵਾਂ = (val.ਉੱਚਾ << (32 - ਖਿਸਕਾਓ)) | (val.ਨੀਵਾਂ >> ਖਿਸਕਾਓ); \
        type ## _struct_return(ret);                               \
	ਵਾਪਸ;                                                    \
    }                                                              \
    type ## _struct_return(val);

ਖਾਲੀ __aeabi_llsr(double_unsigned_struct val, ਪੂਰਨ ਖਿਸਕਾਓ)
{
    aeabi_lsr(val, ਖਿਸਕਾਓ, 0, double_unsigned);
}

ਖਾਲੀ __aeabi_lasr(unsigned_int_struct val, ਪੂਰਨ ਖਿਸਕਾਓ)
{
    aeabi_lsr(val, ਖਿਸਕਾਓ, val.ਉੱਚਾ >> 31, unsigned_int);
}


/* Integer division functions */

#ਜੇ 0 /* very slow */
AEABI_UXDIVMOD(uidivmod, ਬਿਨਾਨਿਸ਼ਾਨੀ, uidiv_t, UINT)

ਪੂਰਨ __aeabi_idiv(ਪੂਰਨ numerator, ਪੂਰਨ denominator)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੰਕ, den;
    uidiv_t ret;

    ਜੇ (numerator >= 0)
        ਅੰਕ = numerator;
    ਨਹੀਂਤਾਂ
        ਅੰਕ = 0 - numerator;
    ਜੇ (denominator >= 0)
        den = denominator;
    ਨਹੀਂਤਾਂ
        den = 0 - denominator;
    ret = aeabi_uidivmod(ਅੰਕ, den);
    ਜੇ ((numerator & INT_MIN) != (denominator & INT_MIN)) /* signs differ */
        ret.quot *= -1;
    ਵਾਪਸ ret.quot;
}

ਬਿਨਾਨਿਸ਼ਾਨੀ __aeabi_uidiv(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੰਕ, ਬਿਨਾਨਿਸ਼ਾਨੀ den)
{
    ਵਾਪਸ aeabi_uidivmod(ਅੰਕ, den).quot;
}

__AEABI_XDIVMOD(idivmod, ਪੂਰਨ, uidivmod, idiv_t, uidiv_t, INT)

ਖਾਲੀ __aeabi_uidivmod(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੰਕ, ਬਿਨਾਨਿਸ਼ਾਨੀ den)
{
    uidiv_t_return(aeabi_uidivmod(ਅੰਕ, den));
}
#ਨਹੀਂਤਾਂ
# define UIDIVMOD_ASM 1
#ਜੇ_ਅੰਤ

/* Some targets do not have all eabi calls (OpenBSD) */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ __SIZE_TYPE__ ਮਾਪ_t;
ਬਾਹਰੀ ਖਾਲੀ *ਸਮ੍ਰਿਤੀ_ਨਕਲ(ਖਾਲੀ *dest, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t n);
ਬਾਹਰੀ ਖਾਲੀ *memmove(ਖਾਲੀ *dest, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t n);
ਬਾਹਰੀ ਖਾਲੀ *memset(ਖਾਲੀ *s, ਪੂਰਨ c, ਮਾਪ_t n);

ਖਾਲੀ *
__aeabi_memcpy (ਖਾਲੀ *dest, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t n)
{
    ਵਾਪਸ ਸਮ੍ਰਿਤੀ_ਨਕਲ (dest, src, n);
}

ਖਾਲੀ *
__aeabi_memmove (ਖਾਲੀ *dest, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t n)
{
    ਵਾਪਸ memmove (dest, src, n);
}

ਖਾਲੀ *
__aeabi_memmove4 (ਖਾਲੀ *dest, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t n)
{
    ਵਾਪਸ memmove (dest, src, n);
}

ਖਾਲੀ *
__aeabi_memmove8 (ਖਾਲੀ *dest, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t n)
{
    ਵਾਪਸ memmove (dest, src, n);
}

ਖਾਲੀ *
__aeabi_memset (ਖਾਲੀ *s, ਮਾਪ_t n, ਪੂਰਨ c)
{
    ਵਾਪਸ memset (s, c, n);
}

/* ***************************************************************** */
#ਜੇ UIDIVMOD_ASM
#ਅਨ੍ਤਰ੍ਭਾਵ <config.h>
__asm__(
   "\n  .global __aeabi_idiv, __aeabi_idivmod"
   "\n  .global __aeabi_uidiv, __aeabi_uidivmod"
#ਜੇ __ARM_FEATURE_IDIV
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
#ਨਹੀਂਤਾਂ
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
   "\n  mov     r3, #0"	    //ਨਤੀਜਾ
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
#ਜੇ_ਅੰਤ
);
#ਜੇ_ਅੰਤ /* UIDIVMOD_ASM */
/* ***************************************************************** */
#ਜੇ_ਅੰਤ
