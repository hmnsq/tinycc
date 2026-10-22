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

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __TINYC__
#ವ್ಯಾಖ್ಯಾನಿಸು INT_MIN (-2147483647 - 1)
#ವ್ಯಾಖ್ಯಾನಿಸು ಗರಿಷ್ಠ_ಪೂರ್ಣಾಂಕ 2147483647
#ವ್ಯಾಖ್ಯಾನಿಸು UINT_MAX 0xffffffff
#ವ್ಯಾಖ್ಯಾನಿಸು LONG_MIN (-2147483647L - 1)
#ವ್ಯಾಖ್ಯಾನಿಸು LONG_MAX 2147483647L
#ವ್ಯಾಖ್ಯಾನಿಸು ULONG_MAX 0xffffffffUL
#ವ್ಯಾಖ್ಯಾನಿಸು LLONG_MAX 9223372036854775807LL
#ವ್ಯಾಖ್ಯಾನಿಸು LLONG_MIN (-9223372036854775807LL - 1)
#ವ್ಯಾಖ್ಯಾನಿಸು ULLONG_MAX 0xffffffffffffffffULL
#ಇಲ್ಲದಿದ್ದರೆ
#ಅನ್ತರ್ಭಾವ <limits.h>
#ಆದರೆ_ಅಂತ್ಯ

/* We rely on the little endianness and EABI calling convention for this to
   work */

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ double_unsigned_struct {
    ಚಿಹ್ನೆರಹಿತ ಕೆಳಗಿನ;
    ಚಿಹ್ನೆರಹಿತ ಮೇಲಿನ;
} double_unsigned_struct;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ unsigned_int_struct {
    ಚಿಹ್ನೆರಹಿತ ಕೆಳಗಿನ;
    ಪೂರ್ಣಾಂಕ ಮೇಲಿನ;
} unsigned_int_struct;

#ವ್ಯಾಖ್ಯಾನಿಸು REGS_RETURN(name, type) \
    ಸ್ಥಿರ ಶೂನ್ಯ name ## _return(type ret) {}


/* Float helper functions */

#ವ್ಯಾಖ್ಯಾನಿಸು FLOAT_EXP_ಬಿಟ್ಟುಗಳು 8
#ವ್ಯಾಖ್ಯಾನಿಸು FLOAT_FRAC_ಬಿಟ್ಟುಗಳು 23

#ವ್ಯಾಖ್ಯಾನಿಸು DOUBLE_EXP_ಬಿಟ್ಟುಗಳು 11
#ವ್ಯಾಖ್ಯಾನಿಸು DOUBLE_FRAC_ಬಿಟ್ಟುಗಳು 52

#ವ್ಯಾಖ್ಯಾನಿಸು ONE_EXP(type) ((1 << (type ## EXP_ಬಿಟ್ಟುಗಳು - 1)) - 1)

REGS_RETURN(unsigned_int_struct, unsigned_int_struct)
REGS_RETURN(double_unsigned_struct, double_unsigned_struct)

/* float -> integer: (sign) 1.fraction x 2^(exponent - exp_for_one) */


/* float to [unsigned] long long conversion */
#ವ್ಯಾಖ್ಯಾನಿಸು DEFINE__AEABI_F2XLZ(name, with_sign)                                 \
ಶೂನ್ಯ __aeabi_ ## name(ಚಿಹ್ನೆರಹಿತ val)                                          \
{                                                                            \
    ಪೂರ್ಣಾಂಕ ಘಾತಾಂಕ, ಮೇಲಿನ_ಸರಿಸು, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    /* compute sign */                                                       \
    sign = val >> 31;                                                        \
                                                                             \
    /* compute real exponent */                                              \
    ಘಾತಾಂಕ = val >> FLOAT_FRAC_ಬಿಟ್ಟುಗಳು;                                            \
    ಘಾತಾಂಕ &= (1 << FLOAT_EXP_ಬಿಟ್ಟುಗಳು) - 1;                                        \
    ಘಾತಾಂಕ -= ONE_EXP(FLOAT);                                                   \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    ಆದರೆ (with_sign) {                                                         \
        ಆದರೆ (ಘಾತಾಂಕ > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            ಹಿಂತಿರುಗಿ;                                                          \
    } ಇಲ್ಲದಿದ್ದರೆ {                                                                 \
        ಆದರೆ ((sign && ಘಾತಾಂಕ >= 0) || ಘಾತಾಂಕ > 63) /* if val < 0 || val too big */  \
            ಹಿಂತಿರುಗಿ;                                                          \
    }                                                                        \
                                                                             \
    val &= (1 << FLOAT_FRAC_ಬಿಟ್ಟುಗಳು) - 1;                                       \
    ಆದರೆ (ಘಾತಾಂಕ >= 32) {                                                         \
        ret.ಮೇಲಿನ = 1 << (ಘಾತಾಂಕ - 32);                                          \
        ಆದರೆ (ಘಾತಾಂಕ - 32 >= FLOAT_FRAC_ಬಿಟ್ಟುಗಳು) {                                   \
            ret.ಮೇಲಿನ |= val << (ಘಾತಾಂಕ - 32 - FLOAT_FRAC_ಬಿಟ್ಟುಗಳು);                 \
            ret.ಕೆಳಗಿನ = 0;                                                     \
        } ಇಲ್ಲದಿದ್ದರೆ {                                                             \
            ಮೇಲಿನ_ಸರಿಸು = FLOAT_FRAC_ಬಿಟ್ಟುಗಳು - (ಘಾತಾಂಕ - 32);                       \
            ret.ಮೇಲಿನ |= val >> ಮೇಲಿನ_ಸರಿಸು;                                   \
            ret.ಕೆಳಗಿನ = val << (32 - ಮೇಲಿನ_ಸರಿಸು);                              \
        }                                                                    \
    } ಇಲ್ಲದಿದ್ದರೆ {                                                                 \
        ret.ಮೇಲಿನ = 0;                                                        \
        ret.ಕೆಳಗಿನ = 1 << ಘಾತಾಂಕ;                                                  \
        ಆದರೆ (ಘಾತಾಂಕ > FLOAT_FRAC_ಬಿಟ್ಟುಗಳು)                                           \
            ret.ಕೆಳಗಿನ |= val << (ಘಾತಾಂಕ - FLOAT_FRAC_ಬಿಟ್ಟುಗಳು);                       \
        ಇಲ್ಲದಿದ್ದರೆ                                                                 \
            ret.ಕೆಳಗಿನ |= val >> (FLOAT_FRAC_ಬಿಟ್ಟುಗಳು - ಘಾತಾಂಕ);                       \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    ಆದರೆ (with_sign && sign) {                                                 \
        ret.ಕೆಳಗಿನ = ~ret.ಕೆಳಗಿನ;                                                  \
        ret.ಮೇಲಿನ = ~ret.ಮೇಲಿನ;                                                \
        ಆದರೆ (ret.ಕೆಳಗಿನ == UINT_MAX) {                                           \
            ret.ಕೆಳಗಿನ = 0;                                                     \
            ret.ಮೇಲಿನ++;                                                      \
        } ಇಲ್ಲದಿದ್ದರೆ                                                               \
            ret.ಕೆಳಗಿನ++;                                                       \
    }                                                                        \
                                                                             \
    double_unsigned_struct_return(ret);                                      \
}

/* float to unsigned long long conversion */
DEFINE__AEABI_F2XLZ(f2ulz, 0)

/* float to long long conversion */
DEFINE__AEABI_F2XLZ(f2lz, 1)

/* double to [unsigned] long long conversion */
#ವ್ಯಾಖ್ಯಾನಿಸು DEFINE__AEABI_D2XLZ(name, with_sign)                                 \
ಶೂನ್ಯ __aeabi_ ## name(double_unsigned_struct val)                            \
{                                                                            \
    ಪೂರ್ಣಾಂಕ ಘಾತಾಂಕ, ಮೇಲಿನ_ಸರಿಸು, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    ಆದರೆ ((val.ಮೇಲಿನ & ~0x80000000) == 0 && val.ಕೆಳಗಿನ == 0) {                     \
        ret.ಕೆಳಗಿನ = ret.ಮೇಲಿನ = 0;                                              \
        ಹೋಗು _ret_;                                                          \
    }                                                                        \
                                                                             \
    /* compute sign */                                                       \
    sign = val.ಮೇಲಿನ >> 31;                                                   \
                                                                             \
    /* compute real exponent */                                              \
    ಘಾತಾಂಕ = (val.ಮೇಲಿನ >> (DOUBLE_FRAC_ಬಿಟ್ಟುಗಳು - 32));                             \
    ಘಾತಾಂಕ &= (1 << DOUBLE_EXP_ಬಿಟ್ಟುಗಳು) - 1;                                       \
    ಘಾತಾಂಕ -= ONE_EXP(DOUBLE);                                                  \
                                                                             \
    /* undefined behavior if truncated value cannot be represented */        \
    ಆದರೆ (with_sign) {                                                         \
        ಆದರೆ (ಘಾತಾಂಕ > 62) /* |val| too big, double cannot represent LLONG_MAX */ \
            ಹಿಂತಿರುಗಿ;                                                          \
    } ಇಲ್ಲದಿದ್ದರೆ {                                                                 \
        ಆದರೆ ((sign && ಘಾತಾಂಕ >= 0) || ಘಾತಾಂಕ > 63) /* if val < 0 || val too big */  \
            ಹಿಂತಿರುಗಿ;                                                          \
    }                                                                        \
                                                                             \
    val.ಮೇಲಿನ &= (1 << (DOUBLE_FRAC_ಬಿಟ್ಟುಗಳು - 32)) - 1;                          \
    ಆದರೆ (ಘಾತಾಂಕ >= 32) {                                                         \
        ret.ಮೇಲಿನ = 1 << (ಘಾತಾಂಕ - 32);                                          \
        ಆದರೆ (ಘಾತಾಂಕ >= DOUBLE_FRAC_ಬಿಟ್ಟುಗಳು) {                                       \
            ಮೇಲಿನ_ಸರಿಸು = ಘಾತಾಂಕ - DOUBLE_FRAC_ಬಿಟ್ಟುಗಳು;                             \
            ret.ಮೇಲಿನ |= val.ಮೇಲಿನ << ಮೇಲಿನ_ಸರಿಸು;                              \
            ret.ಮೇಲಿನ |= val.ಕೆಳಗಿನ >> (32 - ಮೇಲಿನ_ಸರಿಸು);                        \
            ret.ಕೆಳಗಿನ = val.ಕೆಳಗಿನ << ಮೇಲಿನ_ಸರಿಸು;                                 \
        } ಇಲ್ಲದಿದ್ದರೆ {                                                             \
            ಮೇಲಿನ_ಸರಿಸು = DOUBLE_FRAC_ಬಿಟ್ಟುಗಳು - ಘಾತಾಂಕ;                             \
            ret.ಮೇಲಿನ |= val.ಮೇಲಿನ >> ಮೇಲಿನ_ಸರಿಸು;                              \
            ret.ಕೆಳಗಿನ = val.ಮೇಲಿನ << (32 - ಮೇಲಿನ_ಸರಿಸು);                         \
            ret.ಕೆಳಗಿನ |= val.ಕೆಳಗಿನ >> ಮೇಲಿನ_ಸರಿಸು;                                \
        }                                                                    \
    } ಇಲ್ಲದಿದ್ದರೆ {                                                                 \
        ret.ಮೇಲಿನ = 0;                                                        \
        ret.ಕೆಳಗಿನ = 1 << ಘಾತಾಂಕ;                                                  \
        ಆದರೆ (ಘಾತಾಂಕ > DOUBLE_FRAC_ಬಿಟ್ಟುಗಳು - 32) {                                   \
            ಮೇಲಿನ_ಸರಿಸು = ಘಾತಾಂಕ - (DOUBLE_FRAC_ಬಿಟ್ಟುಗಳು - 32);                      \
            ret.ಕೆಳಗಿನ |= val.ಮೇಲಿನ << ಮೇಲಿನ_ಸರಿಸು;                               \
            ret.ಕೆಳಗಿನ |= val.ಕೆಳಗಿನ >> (32 - ಮೇಲಿನ_ಸರಿಸು);                         \
        } ಇಲ್ಲದಿದ್ದರೆ                                                               \
            ret.ಕೆಳಗಿನ |= val.ಮೇಲಿನ >> (DOUBLE_FRAC_ಬಿಟ್ಟುಗಳು - 32 - ಘಾತಾಂಕ);            \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    ಆದರೆ (with_sign && sign) {                                                 \
        ret.ಕೆಳಗಿನ = ~ret.ಕೆಳಗಿನ;                                                  \
        ret.ಮೇಲಿನ = ~ret.ಮೇಲಿನ;                                                \
        ಆದರೆ (ret.ಕೆಳಗಿನ == UINT_MAX) {                                           \
            ret.ಕೆಳಗಿನ = 0;                                                     \
            ret.ಮೇಲಿನ++;                                                      \
        } ಇಲ್ಲದಿದ್ದರೆ                                                               \
            ret.ಕೆಳಗಿನ++;                                                       \
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
#ವ್ಯಾಖ್ಯಾನಿಸು DEFINE__AEABI_XL2F(name, with_sign)                             \
ಚಿಹ್ನೆರಹಿತ __aeabi_ ## name(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ v)                         \
{                                                                       \
    ಪೂರ್ಣಾಂಕ s /*ಸರಿಸು*/, flb /* first lost bit */, sign = 0;              \
    ಚಿಹ್ನೆರಹಿತ p = 0 /* power */, ret;                                    \
    double_unsigned_struct val;                                         \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    ಆದರೆ (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.ಕೆಳಗಿನ = v;                                                        \
    val.ಮೇಲಿನ = v >> 32;                                                 \
    /* fill fraction bits */                                            \
    ಗಾಗಿ (s = 31, p = 1 << 31; p && !(val.ಮೇಲಿನ & p); s--, p >>= 1);      \
    ಆದರೆ (p) {                                                            \
        ret = val.ಮೇಲಿನ & (p - 1);                                       \
        ಆದರೆ (s < FLOAT_FRAC_ಬಿಟ್ಟುಗಳು) {                                      \
            ret <<= FLOAT_FRAC_ಬಿಟ್ಟುಗಳು - s;                                \
            ret |= val.ಕೆಳಗಿನ >> (32 - (FLOAT_FRAC_ಬಿಟ್ಟುಗಳು - s));             \
            flb = (val.ಕೆಳಗಿನ >> (32 - (FLOAT_FRAC_ಬಿಟ್ಟುಗಳು - s - 1))) & 1;    \
        } ಇಲ್ಲದಿದ್ದರೆ {                                                        \
            flb = (ret >> (s - FLOAT_FRAC_ಬಿಟ್ಟುಗಳು - 1)) & 1;               \
            ret >>= s - FLOAT_FRAC_ಬಿಟ್ಟುಗಳು;                                \
        }                                                               \
        s += 32;                                                        \
    } ಇಲ್ಲದಿದ್ದರೆ {                                                            \
        ಗಾಗಿ (s = 31, p = 1 << 31; p && !(val.ಕೆಳಗಿನ & p); s--, p >>= 1);   \
        ಆದರೆ (p) {                                                        \
            ret = val.ಕೆಳಗಿನ & (p - 1);                                    \
            ಆದರೆ (s <= FLOAT_FRAC_ಬಿಟ್ಟುಗಳು) {                                 \
                ret <<= FLOAT_FRAC_ಬಿಟ್ಟುಗಳು - s;                            \
                flb = 0;                                                \
	    } ಇಲ್ಲದಿದ್ದರೆ {                                                    \
                flb = (ret >> (s - FLOAT_FRAC_ಬಿಟ್ಟುಗಳು - 1)) & 1;           \
                ret >>= s - FLOAT_FRAC_ಬಿಟ್ಟುಗಳು;                            \
	    }                                                           \
        } ಇಲ್ಲದಿದ್ದರೆ                                                          \
            ಹಿಂತಿರುಗಿ 0;                                                   \
    }                                                                   \
    ಆದರೆ (flb)                                                            \
        ret++;                                                          \
                                                                        \
    /* fill exponent bits */                                            \
    ret |= (s + ONE_EXP(FLOAT)) << FLOAT_FRAC_ಬಿಟ್ಟುಗಳು;                     \
                                                                        \
    /* fill sign bit */                                                 \
    ret |= sign << 31;                                                  \
                                                                        \
    ಹಿಂತಿರುಗಿ ret;                                                         \
}

/* unsigned long long to float conversion */
DEFINE__AEABI_XL2F(ul2f, 0)

/* long long to float conversion */
DEFINE__AEABI_XL2F(l2f, 1)

/* long long to double conversion */
#ವ್ಯಾಖ್ಯಾನಿಸು __AEABI_XL2D(name, with_sign)                                   \
ಶೂನ್ಯ __aeabi_ ## name(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ v)                             \
{                                                                       \
    ಪೂರ್ಣಾಂಕ s /*ಸರಿಸು*/, ಮೇಲಿನ_ಸರಿಸು, sign = 0;                            \
    ಚಿಹ್ನೆರಹಿತ tmp, p = 0;                                                \
    double_unsigned_struct val, ret;                                    \
                                                                        \
    /* fraction in negative float is encoded in 1's complement */       \
    ಆದರೆ (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.ಕೆಳಗಿನ = v;                                                        \
    val.ಮೇಲಿನ = v >> 32;                                                 \
                                                                        \
    /* fill fraction bits */                                            \
    ಗಾಗಿ (s = 31, p = 1 << 31; p && !(val.ಮೇಲಿನ & p); s--, p >>= 1);      \
    ಆದರೆ (p) {                                                            \
        tmp = val.ಮೇಲಿನ & (p - 1);                                       \
        ಆದರೆ (s < DOUBLE_FRAC_ಬಿಟ್ಟುಗಳು - 32) {                                \
            ಮೇಲಿನ_ಸರಿಸು = DOUBLE_FRAC_ಬಿಟ್ಟುಗಳು - 32 - s;                     \
            ret.ಮೇಲಿನ = tmp << ಮೇಲಿನ_ಸರಿಸು;                               \
            ret.ಮೇಲಿನ |= val.ಕೆಳಗಿನ >> (32 - ಮೇಲಿನ_ಸರಿಸು);                   \
            ret.ಕೆಳಗಿನ = val.ಕೆಳಗಿನ << ಮೇಲಿನ_ಸರಿಸು;                            \
        } ಇಲ್ಲದಿದ್ದರೆ {                                                        \
            ಮೇಲಿನ_ಸರಿಸು = s - (DOUBLE_FRAC_ಬಿಟ್ಟುಗಳು - 32);                   \
            ret.ಮೇಲಿನ = tmp >> ಮೇಲಿನ_ಸರಿಸು;                               \
            ret.ಕೆಳಗಿನ = tmp << (32 - ಮೇಲಿನ_ಸರಿಸು);                         \
            ret.ಕೆಳಗಿನ |= val.ಕೆಳಗಿನ >> ಮೇಲಿನ_ಸರಿಸು;                           \
            ಆದರೆ ((val.ಕೆಳಗಿನ >> (ಮೇಲಿನ_ಸರಿಸು - 1)) & 1) {                    \
                ಆದರೆ (ret.ಕೆಳಗಿನ == UINT_MAX) {                              \
                    ret.ಮೇಲಿನ++;                                         \
                    ret.ಕೆಳಗಿನ = 0;                                        \
		} ಇಲ್ಲದಿದ್ದರೆ                                                  \
                    ret.ಕೆಳಗಿನ++;                                          \
            }                                                           \
        }                                                               \
        s += 32;                                                        \
    } ಇಲ್ಲದಿದ್ದರೆ {                                                            \
        ಗಾಗಿ (s = 31, p = 1 << 31; p && !(val.ಕೆಳಗಿನ & p); s--, p >>= 1);   \
        ಆದರೆ (p) {                                                        \
            tmp = val.ಕೆಳಗಿನ & (p - 1);                                    \
            ಆದರೆ (s <= DOUBLE_FRAC_ಬಿಟ್ಟುಗಳು - 32) {                           \
                ಮೇಲಿನ_ಸರಿಸು = DOUBLE_FRAC_ಬಿಟ್ಟುಗಳು - 32 - s;                 \
                ret.ಮೇಲಿನ = tmp << ಮೇಲಿನ_ಸರಿಸು;                           \
                ret.ಕೆಳಗಿನ = 0;                                            \
	    } ಇಲ್ಲದಿದ್ದರೆ {                                                    \
                ಮೇಲಿನ_ಸರಿಸು = s - (DOUBLE_FRAC_ಬಿಟ್ಟುಗಳು - 32);               \
                ret.ಮೇಲಿನ = tmp >> ಮೇಲಿನ_ಸರಿಸು;                           \
                ret.ಕೆಳಗಿನ = tmp << (32 - ಮೇಲಿನ_ಸರಿಸು);                     \
            }                                                           \
        } ಇಲ್ಲದಿದ್ದರೆ {                                                        \
            ret.ಮೇಲಿನ = ret.ಕೆಳಗಿನ = 0;                                     \
            ಹೋಗು _ret_;                                                 \
        }                                                               \
    }                                                                   \
                                                                        \
    /* fill exponent bits */                                            \
    ret.ಮೇಲಿನ |= (s + ONE_EXP(DOUBLE)) << (DOUBLE_FRAC_ಬಿಟ್ಟುಗಳು - 32);       \
                                                                        \
    /* fill sign bit */                                                 \
    ret.ಮೇಲಿನ |= sign << 31;                                             \
                                                                        \
_ret_:                                                                  \
    double_unsigned_struct_return(ret);                                 \
}

/* unsigned long long to double conversion */
__AEABI_XL2D(ul2d, 0)

/* long long to double conversion */
__AEABI_XL2D(l2d, 1)

#ಆದರೆ 1
/* Long long helper functions */

/* TODO: add error in case of den == 0 (see §4.3.1 and §4.3.2) */

#ವ್ಯಾಖ್ಯಾನಿಸು define_aeabi_xdivmod_signed_type(basetype, type) \
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ type {                                    \
    basetype quot;                                       \
    ಚಿಹ್ನೆರಹಿತ basetype rem;                               \
} type

#ವ್ಯಾಖ್ಯಾನಿಸು define_aeabi_xdivmod_unsigned_type(basetype, type) \
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ type {                                      \
    basetype quot;                                         \
    basetype rem;                                          \
} type

#ವ್ಯಾಖ್ಯಾನಿಸು AEABI_UXDIVMOD(name,type, rettype, typemacro)                     \
ಸ್ಥಿರ ಸಾಲೊಳಗೆ rettype aeabi_ ## name (type ಅಂಕೆ, type den)                 \
{                                                                         \
    rettype ret;                                                          \
    type quot = 0;                                                        \
                                                                          \
    /* Increase quotient while it is less than numerator */               \
    ಆಗ (ಅಂಕೆ >= den) {                                                  \
        type q = 1;                                                       \
                                                                          \
        /* Find closest power of two */                                   \
        ಆಗ ((q << 1) * den <= ಅಂಕೆ && q * den <= typemacro ## _MAX / 2) \
            q <<= 1;                                                      \
                                                                          \
        /* Compute difference between current quotient and numerator */   \
        ಅಂಕೆ -= q * den;                                                   \
        quot += q;                                                        \
    }                                                                     \
    ret.quot = quot;                                                      \
    ret.rem = ಅಂಕೆ;                                                        \
    ಹಿಂತಿರುಗಿ ret;                                                           \
}

#ವ್ಯಾಖ್ಯಾನಿಸು __AEABI_XDIVMOD(name, type, uiname, rettype, urettype, typemacro)     \
ಶೂನ್ಯ __aeabi_ ## name(type numerator, type denominator)                       \
{                                                                             \
    ಚಿಹ್ನೆರಹಿತ type ಅಂಕೆ, den;                                                   \
    urettype uxdiv_ret;                                                       \
    rettype ret;                                                              \
                                                                              \
    ಆದರೆ (numerator >= 0)                                                       \
      ಅಂಕೆ = numerator;                                                        \
    ಇಲ್ಲದಿದ್ದರೆ                                                                      \
      ಅಂಕೆ = 0 - numerator;                                                    \
    ಆದರೆ (denominator >= 0)                                                     \
      den = denominator;                                                      \
    ಇಲ್ಲದಿದ್ದರೆ                                                                      \
      den = 0 - denominator;                                                  \
    uxdiv_ret = aeabi_ ## uiname(ಅಂಕೆ, den);                                   \
    /* signs differ */                                                        \
    ಆದರೆ ((numerator & typemacro ## _MIN) != (denominator & typemacro ## _MIN)) \
        ret.quot = 0 - uxdiv_ret.quot;                                        \
    ಇಲ್ಲದಿದ್ದರೆ                                                                      \
        ret.quot = uxdiv_ret.quot;                                            \
    ಆದರೆ (numerator < 0)                                                        \
        ret.rem = 0 - uxdiv_ret.rem;                                          \
    ಇಲ್ಲದಿದ್ದರೆ                                                                      \
        ret.rem = uxdiv_ret.rem;                                              \
                                                                              \
    rettype ## _return(ret);                                                  \
}

define_aeabi_xdivmod_signed_type(ದೀರ್ಘ ದೀರ್ಘ, lldiv_t);
define_aeabi_xdivmod_unsigned_type(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ, ulldiv_t);
define_aeabi_xdivmod_signed_type(ಪೂರ್ಣಾಂಕ, idiv_t);
define_aeabi_xdivmod_unsigned_type(ಚಿಹ್ನೆರಹಿತ, uidiv_t);

REGS_RETURN(lldiv_t, lldiv_t)
REGS_RETURN(ulldiv_t, ulldiv_t)
REGS_RETURN(idiv_t, idiv_t)
REGS_RETURN(uidiv_t, uidiv_t)

AEABI_UXDIVMOD(uldivmod, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ, ulldiv_t, ULLONG)

__AEABI_XDIVMOD(ldivmod, ದೀರ್ಘ ದೀರ್ಘ, uldivmod, lldiv_t, ulldiv_t, LLONG)

ಶೂನ್ಯ __aeabi_uldivmod(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ಅಂಕೆ, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ den)
{
    ulldiv_t_return(aeabi_uldivmod(ಅಂಕೆ, den));
}

ಶೂನ್ಯ __aeabi_llsl(double_unsigned_struct val, ಪೂರ್ಣಾಂಕ ಸರಿಸು)
{
    double_unsigned_struct ret;

    ಆದರೆ (ಸರಿಸು >= 32) {
        val.ಮೇಲಿನ = val.ಕೆಳಗಿನ;
        val.ಕೆಳಗಿನ = 0;
        ಸರಿಸು -= 32;
    }
    ಆದರೆ (ಸರಿಸು > 0) {
        ret.ಕೆಳಗಿನ = val.ಕೆಳಗಿನ << ಸರಿಸು;
        ret.ಮೇಲಿನ = (val.ಮೇಲಿನ << ಸರಿಸು) | (val.ಕೆಳಗಿನ >> (32 - ಸರಿಸು));
        double_unsigned_struct_return(ret);
	ಹಿಂತಿರುಗಿ;
    }
    double_unsigned_struct_return(val);
}

#ವ್ಯಾಖ್ಯಾನಿಸು aeabi_lsr(val, ಸರಿಸು, fill, type)                          \
    type ## _struct ret;                                           \
                                                                   \
    ಆದರೆ (ಸರಿಸು >= 32) {                                             \
        val.ಕೆಳಗಿನ = val.ಮೇಲಿನ;                                        \
        val.ಮೇಲಿನ = fill;                                           \
        ಸರಿಸು -= 32;                                               \
    }                                                              \
    ಆದರೆ (ಸರಿಸು > 0) {                                               \
        ret.ಮೇಲಿನ = val.ಮೇಲಿನ >> ಸರಿಸು;                              \
        ret.ಕೆಳಗಿನ = (val.ಮೇಲಿನ << (32 - ಸರಿಸು)) | (val.ಕೆಳಗಿನ >> ಸರಿಸು); \
        type ## _struct_return(ret);                               \
	ಹಿಂತಿರುಗಿ;                                                    \
    }                                                              \
    type ## _struct_return(val);

ಶೂನ್ಯ __aeabi_llsr(double_unsigned_struct val, ಪೂರ್ಣಾಂಕ ಸರಿಸು)
{
    aeabi_lsr(val, ಸರಿಸು, 0, double_unsigned);
}

ಶೂನ್ಯ __aeabi_lasr(unsigned_int_struct val, ಪೂರ್ಣಾಂಕ ಸರಿಸು)
{
    aeabi_lsr(val, ಸರಿಸು, val.ಮೇಲಿನ >> 31, unsigned_int);
}


/* Integer division functions */

#ಆದರೆ 0 /* very slow */
AEABI_UXDIVMOD(uidivmod, ಚಿಹ್ನೆರಹಿತ, uidiv_t, UINT)

ಪೂರ್ಣಾಂಕ __aeabi_idiv(ಪೂರ್ಣಾಂಕ numerator, ಪೂರ್ಣಾಂಕ denominator)
{
    ಚಿಹ್ನೆರಹಿತ ಅಂಕೆ, den;
    uidiv_t ret;

    ಆದರೆ (numerator >= 0)
        ಅಂಕೆ = numerator;
    ಇಲ್ಲದಿದ್ದರೆ
        ಅಂಕೆ = 0 - numerator;
    ಆದರೆ (denominator >= 0)
        den = denominator;
    ಇಲ್ಲದಿದ್ದರೆ
        den = 0 - denominator;
    ret = aeabi_uidivmod(ಅಂಕೆ, den);
    ಆದರೆ ((numerator & INT_MIN) != (denominator & INT_MIN)) /* signs differ */
        ret.quot *= -1;
    ಹಿಂತಿರುಗಿ ret.quot;
}

ಚಿಹ್ನೆರಹಿತ __aeabi_uidiv(ಚಿಹ್ನೆರಹಿತ ಅಂಕೆ, ಚಿಹ್ನೆರಹಿತ den)
{
    ಹಿಂತಿರುಗಿ aeabi_uidivmod(ಅಂಕೆ, den).quot;
}

__AEABI_XDIVMOD(idivmod, ಪೂರ್ಣಾಂಕ, uidivmod, idiv_t, uidiv_t, INT)

ಶೂನ್ಯ __aeabi_uidivmod(ಚಿಹ್ನೆರಹಿತ ಅಂಕೆ, ಚಿಹ್ನೆರಹಿತ den)
{
    uidiv_t_return(aeabi_uidivmod(ಅಂಕೆ, den));
}
#ಇಲ್ಲದಿದ್ದರೆ
# define UIDIVMOD_ASM 1
#ಆದರೆ_ಅಂತ್ಯ

/* Some targets do not have all eabi calls (OpenBSD) */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __SIZE_TYPE__ ಗಾತ್ರ_t;
ಬಾಹ್ಯ ಶೂನ್ಯ *ಸ್ಮರಣೆ_ನಕಲು(ಶೂನ್ಯ *dest, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t n);
ಬಾಹ್ಯ ಶೂನ್ಯ *memmove(ಶೂನ್ಯ *dest, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t n);
ಬಾಹ್ಯ ಶೂನ್ಯ *memset(ಶೂನ್ಯ *s, ಪೂರ್ಣಾಂಕ c, ಗಾತ್ರ_t n);

ಶೂನ್ಯ *
__aeabi_memcpy (ಶೂನ್ಯ *dest, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t n)
{
    ಹಿಂತಿರುಗಿ ಸ್ಮರಣೆ_ನಕಲು (dest, src, n);
}

ಶೂನ್ಯ *
__aeabi_memmove (ಶೂನ್ಯ *dest, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t n)
{
    ಹಿಂತಿರುಗಿ memmove (dest, src, n);
}

ಶೂನ್ಯ *
__aeabi_memmove4 (ಶೂನ್ಯ *dest, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t n)
{
    ಹಿಂತಿರುಗಿ memmove (dest, src, n);
}

ಶೂನ್ಯ *
__aeabi_memmove8 (ಶೂನ್ಯ *dest, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t n)
{
    ಹಿಂತಿರುಗಿ memmove (dest, src, n);
}

ಶೂನ್ಯ *
__aeabi_memset (ಶೂನ್ಯ *s, ಗಾತ್ರ_t n, ಪೂರ್ಣಾಂಕ c)
{
    ಹಿಂತಿರುಗಿ memset (s, c, n);
}

/* ***************************************************************** */
#ಆದರೆ UIDIVMOD_ASM
#ಅನ್ತರ್ಭಾವ <config.h>
__asm__(
   "\n  .global __aeabi_idiv, __aeabi_idivmod"
   "\n  .global __aeabi_uidiv, __aeabi_uidivmod"
#ಆದರೆ __ARM_FEATURE_IDIV
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
#ಇಲ್ಲದಿದ್ದರೆ
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
   "\n  mov     r3, #0"	    //ಫಲಿತಾಂಶ
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
#ಆದರೆ_ಅಂತ್ಯ
);
#ಆದರೆ_ಅಂತ್ಯ /* UIDIVMOD_ASM */
/* ***************************************************************** */
#ಆದರೆ_ಅಂತ್ಯ
