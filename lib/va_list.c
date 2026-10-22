/* va_list.c - tinycc support for va_list on X86_64 */

#ଯଦି defined __x86_64__

/* Avoid include files, they may not be available when cross compiling */
ବାହ୍ୟ ଶୂନ୍ୟ abort(ଶୂନ୍ୟ);

/* This should be in sync with our include/stdarg.h */
ଗଣନା __va_arg_type {
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

ବାହ୍ୟ ଶୂନ୍ୟ *memcpy(ଶୂନ୍ୟ *dest, ଅଚଳ ଶୂନ୍ୟ *src, unsigned long n);

ଶୂନ୍ୟ *__va_arg(__builtin_va_list ap,
               ପୂର୍ଣ୍ଣସଂଖ୍ୟା arg_type,
               ପୂର୍ଣ୍ଣସଂଖ୍ୟା size, ପୂର୍ଣ୍ଣସଂଖ୍ୟା align)
{
    size = (size + 7) & ~7;
    align = (align + 7) & ~7;
    ବାଛ ((ଗଣନା __va_arg_type)arg_type) {
    ସ୍ଥିତି __va_gen_reg:
        ଯଦି (ap->gp_offset + size <= 48) {
            ap->gp_offset += size;
            ଫେରନ୍ତୁ ap->reg_save_area + ap->gp_offset - size;
        }
        ଯାଅ use_overflow_area;

    ସ୍ଥିତି __va_float_reg:
        ଯଦି (ap->fp_offset < 128 + 48) {
            ap->fp_offset += 16;
            ଯଦି (size == 8)
                ଫେରନ୍ତୁ ap->reg_save_area + ap->fp_offset - 16;
            ଯଦି (ap->fp_offset < 128 + 48) {
                memcpy(ap->reg_save_area + ap->fp_offset - 8,
                       ap->reg_save_area + ap->fp_offset, 8);
                ap->fp_offset += 16;
                ଫେରନ୍ତୁ ap->reg_save_area + ap->fp_offset - 32;
            }
        }
        ଯାଅ use_overflow_area;

    ସ୍ଥିତି __va_stack:
    use_overflow_area:
        ap->overflow_arg_area += size;
        ap->overflow_arg_area = (ଅକ୍ଷର*)((long long)(ap->overflow_arg_area + align - 1) & -align);
        ଫେରନ୍ତୁ ap->overflow_arg_area - size;

    ପୂର୍ବନିର୍ଦ୍ଧାରିତ: /* should never happen */
        abort();
        ଫେରନ୍ତୁ 0;
    }
}
#endif
