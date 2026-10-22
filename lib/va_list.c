/* va_list.c - tinycc support for va_list on X86_64 */

#ಯದಿ defined __x86_64__

/* Avoid include files, they may not be available when cross compiling */
ಬಾಹ್ಯ ಶೂನ್ಯ abort(ಶೂನ್ಯ);

/* This should be in sync with our include/stdarg.h */
ಗಣನಾ __va_arg_type {
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

ಬಾಹ್ಯ ಶೂನ್ಯ *memcpy(ಶೂನ್ಯ *dest, ಧ್ರುವ ಶೂನ್ಯ *src, unsigned long n);

ಶೂನ್ಯ *__va_arg(__builtin_va_list ap,
               ಪೂರ್ಣಾಙ್ಕ arg_type,
               ಪೂರ್ಣಾಙ್ಕ size, ಪೂರ್ಣಾಙ್ಕ align)
{
    size = (size + 7) & ~7;
    align = (align + 7) & ~7;
    ವಿಕಲ್ಪ ((ಗಣನಾ __va_arg_type)arg_type) {
    ಪಕ್ಷ __va_gen_reg:
        ಯದಿ (ap->gp_offset + size <= 48) {
            ap->gp_offset += size;
            ಪ್ರತ್ಯಾಗಮ ap->reg_save_area + ap->gp_offset - size;
        }
        ಗಚ್ಛ use_overflow_area;

    ಪಕ್ಷ __va_float_reg:
        ಯದಿ (ap->fp_offset < 128 + 48) {
            ap->fp_offset += 16;
            ಯದಿ (size == 8)
                ಪ್ರತ್ಯಾಗಮ ap->reg_save_area + ap->fp_offset - 16;
            ಯದಿ (ap->fp_offset < 128 + 48) {
                memcpy(ap->reg_save_area + ap->fp_offset - 8,
                       ap->reg_save_area + ap->fp_offset, 8);
                ap->fp_offset += 16;
                ಪ್ರತ್ಯಾಗಮ ap->reg_save_area + ap->fp_offset - 32;
            }
        }
        ಗಚ್ಛ use_overflow_area;

    ಪಕ್ಷ __va_stack:
    use_overflow_area:
        ap->overflow_arg_area += size;
        ap->overflow_arg_area = (ವರ್ಣ*)((long long)(ap->overflow_arg_area + align - 1) & -align);
        ಪ್ರತ್ಯಾಗಮ ap->overflow_arg_area - size;

    ಸ್ವಭಾವ: /* should never happen */
        abort();
        ಪ್ರತ್ಯಾಗಮ 0;
    }
}
#endif
