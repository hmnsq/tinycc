/* va_list.c - tinycc support for va_list on X86_64 */

#जइ defined __x86_64__

/* Avoid include files, they may not be available when cross compiling */
बाह्य शून्य abort(शून्य);

/* This should be in sync with our include/stdarg.h */
गणना __va_arg_type {
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

बाह्य शून्य *memcpy(शून्य *dest, ध्रुव शून्य *src, unsigned long n);

शून्य *__va_arg(__builtin_va_list ap,
               पूर्णाङ्क arg_type,
               पूर्णाङ्क size, पूर्णाङ्क align)
{
    size = (size + 7) & ~7;
    align = (align + 7) & ~7;
    विकल्प ((गणना __va_arg_type)arg_type) {
    पक्ष __va_gen_reg:
        जइ (ap->gp_offset + size <= 48) {
            ap->gp_offset += size;
            प्रत्यागम ap->reg_save_area + ap->gp_offset - size;
        }
        गच्छ use_overflow_area;

    पक्ष __va_float_reg:
        जइ (ap->fp_offset < 128 + 48) {
            ap->fp_offset += 16;
            जइ (size == 8)
                प्रत्यागम ap->reg_save_area + ap->fp_offset - 16;
            जइ (ap->fp_offset < 128 + 48) {
                memcpy(ap->reg_save_area + ap->fp_offset - 8,
                       ap->reg_save_area + ap->fp_offset, 8);
                ap->fp_offset += 16;
                प्रत्यागम ap->reg_save_area + ap->fp_offset - 32;
            }
        }
        गच्छ use_overflow_area;

    पक्ष __va_stack:
    use_overflow_area:
        ap->overflow_arg_area += size;
        ap->overflow_arg_area = (वर्ण*)((long long)(ap->overflow_arg_area + align - 1) & -align);
        प्रत्यागम ap->overflow_arg_area - size;

    स्वभाव: /* should never happen */
        abort();
        प्रत्यागम 0;
    }
}
#endif
