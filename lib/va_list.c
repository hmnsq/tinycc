/* va_list.c - tinycc support for va_list on X86_64 */

#ಆದರೆ defined __x86_64__

/* Avoid include files, they may not be available when cross compiling */
ಬಾಹ್ಯ ಶೂನ್ಯ abort(ಶೂನ್ಯ);

/* This should be in sync with our include/stdarg.h */
ಎಣಿಕೆ __va_arg_type {
    __va_gen_reg, __va_float_reg, __va_stack
};

/* GCC compatible definition of va_list. */
/*predefined by TCC (tcc_predefs.h):
typedef struct {
    unsigned int gp_offset;
    unsigned int fp_offset;
    union {
        unsigned int overflow_offset;
        char *overflow_arg_area;
    };
    char *reg_save_area;
} __builtin_va_list[1];
*/

ಬಾಹ್ಯ ಶೂನ್ಯ *ಸ್ಮರಣೆ_ನಕಲು(ಶೂನ್ಯ *dest, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ n);

ಶೂನ್ಯ *__va_arg(__builtin_va_list ap,
               ಪೂರ್ಣಾಂಕ arg_type,
               ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, ಪೂರ್ಣಾಂಕ align)
{
    ಗಾತ್ರ_2 = (ಗಾತ್ರ_2 + 7) & ~7;
    align = (align + 7) & ~7;
    ಆಯ್ಕೆ ((ಎಣಿಕೆ __va_arg_type)arg_type) {
    ಸ್ಥಿತಿ __va_gen_reg:
        ಆದರೆ (ap->gp_ಸ್ಥಾನಾಂತರ + ಗಾತ್ರ_2 <= 48) {
            ap->gp_ಸ್ಥಾನಾಂತರ += ಗಾತ್ರ_2;
            ಹಿಂತಿರುಗಿ ap->reg_save_area + ap->gp_ಸ್ಥಾನಾಂತರ - ಗಾತ್ರ_2;
        }
        ಹೋಗು use_ಅತಿಪ್ರವಾಹ_area;

    ಸ್ಥಿತಿ __va_float_reg:
        ಆದರೆ (ap->fp_ಸ್ಥಾನಾಂತರ < 128 + 48) {
            ap->fp_ಸ್ಥಾನಾಂತರ += 16;
            ಆದರೆ (ಗಾತ್ರ_2 == 8)
                ಹಿಂತಿರುಗಿ ap->reg_save_area + ap->fp_ಸ್ಥಾನಾಂತರ - 16;
            ಆದರೆ (ap->fp_ಸ್ಥಾನಾಂತರ < 128 + 48) {
                ಸ್ಮರಣೆ_ನಕಲು(ap->reg_save_area + ap->fp_ಸ್ಥಾನಾಂತರ - 8,
                       ap->reg_save_area + ap->fp_ಸ್ಥಾನಾಂತರ, 8);
                ap->fp_ಸ್ಥಾನಾಂತರ += 16;
                ಹಿಂತಿರುಗಿ ap->reg_save_area + ap->fp_ಸ್ಥಾನಾಂತರ - 32;
            }
        }
        ಹೋಗು use_ಅತಿಪ್ರವಾಹ_area;

    ಸ್ಥಿತಿ __va_stack:
    use_ಅತಿಪ್ರವಾಹ_area:
        ap->ಅತಿಪ್ರವಾಹ_arg_area += ಗಾತ್ರ_2;
        ap->ಅತಿಪ್ರವಾಹ_arg_area = (ಅಕ್ಷರ*)((ದೀರ್ಘ ದೀರ್ಘ)(ap->ಅತಿಪ್ರವಾಹ_arg_area + align - 1) & -align);
        ಹಿಂತಿರುಗಿ ap->ಅತಿಪ್ರವಾಹ_arg_area - ಗಾತ್ರ_2;

    ಪೂರ್ವನಿಯೋಜಿತ: /* should never happen */
        abort();
        ಹಿಂತಿರುಗಿ 0;
    }
}
#ಆದರೆ_ಅಂತ್ಯ
