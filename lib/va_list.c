/* va_list.c - tinycc support for va_list on X86_64 */

#यदि defined __x86_64__

/* Avoid include files, they may not be available when cross compiling */
बाह्य शून्य पात(शून्य);

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

बाह्य शून्य *स_नकल(शून्य *dest, अचर शून्य *src, अचिन्हित दीर्घ n);

शून्य *__va_arg(__builtin_va_list ap,
               पूर्णाङ्क arg_type,
               पूर्णाङ्क size, पूर्णाङ्क align)
{
    size = (size + 7) & ~7;
    align = (align + 7) & ~7;
    विकल्प ((गणना __va_arg_type)arg_type) {
    पक्ष __va_gen_reg:
        यदि (ap->gp_offset + size <= 48) {
            ap->gp_offset += size;
            फर्काऊ ap->reg_save_area + ap->gp_offset - size;
        }
        गच्छ use_overflow_area;

    पक्ष __va_float_reg:
        यदि (ap->fp_offset < 128 + 48) {
            ap->fp_offset += 16;
            यदि (size == 8)
                फर्काऊ ap->reg_save_area + ap->fp_offset - 16;
            यदि (ap->fp_offset < 128 + 48) {
                स_नकल(ap->reg_save_area + ap->fp_offset - 8,
                       ap->reg_save_area + ap->fp_offset, 8);
                ap->fp_offset += 16;
                फर्काऊ ap->reg_save_area + ap->fp_offset - 32;
            }
        }
        गच्छ use_overflow_area;

    पक्ष __va_stack:
    use_overflow_area:
        ap->overflow_arg_area += size;
        ap->overflow_arg_area = (वर्ण*)((दीर्घ दीर्घ)(ap->overflow_arg_area + align - 1) & -align);
        फर्काऊ ap->overflow_arg_area - size;

    स्वभाव: /* should never happen */
        पात();
        फर्काऊ 0;
    }
}
#endif
