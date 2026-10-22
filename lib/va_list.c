/* va_list.c - tinycc support for va_list on X86_64 */

#यदि defined __x86_64__

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

बाह्य शून्य *स्मृतिं_प्रतिलिख(शून्य *dest, ध्रुव शून्य *src, अचिह्नित दीर्घ n);

शून्य *__va_arg(__builtin_va_list ap,
               पूर्णाङ्क arg_type,
               पूर्णाङ्क आकार, पूर्णाङ्क align)
{
    आकार = (आकार + 7) & ~7;
    align = (align + 7) & ~7;
    विकल्प ((गणना __va_arg_type)arg_type) {
    पक्ष __va_gen_reg:
        यदि (ap->gp_विस्थापनम् + आकार <= 48) {
            ap->gp_विस्थापनम् += आकार;
            प्रत्यागम ap->reg_save_area + ap->gp_विस्थापनम् - आकार;
        }
        गच्छ use_अतिप्रवाहः_area;

    पक्ष __va_float_reg:
        यदि (ap->fp_विस्थापनम् < 128 + 48) {
            ap->fp_विस्थापनम् += 16;
            यदि (आकार == 8)
                प्रत्यागम ap->reg_save_area + ap->fp_विस्थापनम् - 16;
            यदि (ap->fp_विस्थापनम् < 128 + 48) {
                स्मृतिं_प्रतिलिख(ap->reg_save_area + ap->fp_विस्थापनम् - 8,
                       ap->reg_save_area + ap->fp_विस्थापनम्, 8);
                ap->fp_विस्थापनम् += 16;
                प्रत्यागम ap->reg_save_area + ap->fp_विस्थापनम् - 32;
            }
        }
        गच्छ use_अतिप्रवाहः_area;

    पक्ष __va_stack:
    use_अतिप्रवाहः_area:
        ap->अतिप्रवाहः_arg_area += आकार;
        ap->अतिप्रवाहः_arg_area = (वर्ण*)((दीर्घ दीर्घ)(ap->अतिप्रवाहः_arg_area + align - 1) & -align);
        प्रत्यागम ap->अतिप्रवाहः_arg_area - आकार;

    स्वभाव: /* should never happen */
        abort();
        प्रत्यागम 0;
    }
}
#यदि_अन्तः
