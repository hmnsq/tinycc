/* va_list.c - tinycc support for va_list on X86_64 */

#যদি defined __x86_64__

/* Avoid include files, they may not be available when cross compiling */
বাহ্যিক শূন্য abort(শূন্য);

/* This should be in sync with our include/stdarg.h */
গণনা __va_arg_type {
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

বাহ্যিক শূন্য *memcpy(শূন্য *dest, ধ্রুবক শূন্য *src, unsigned long n);

শূন্য *__va_arg(__builtin_va_list ap,
               পূর্ণসংখ্যা arg_type,
               পূর্ণসংখ্যা আকার_2, পূর্ণসংখ্যা align)
{
    আকার_2 = (আকার_2 + 7) & ~7;
    align = (align + 7) & ~7;
    নির্বাচন ((গণনা __va_arg_type)arg_type) {
    ক্ষেত্র __va_gen_reg:
        যদি (ap->gp_offset + আকার_2 <= 48) {
            ap->gp_offset += আকার_2;
            ফেরত ap->reg_save_area + ap->gp_offset - আকার_2;
        }
        যাও use_overflow_area;

    ক্ষেত্র __va_float_reg:
        যদি (ap->fp_offset < 128 + 48) {
            ap->fp_offset += 16;
            যদি (আকার_2 == 8)
                ফেরত ap->reg_save_area + ap->fp_offset - 16;
            যদি (ap->fp_offset < 128 + 48) {
                memcpy(ap->reg_save_area + ap->fp_offset - 8,
                       ap->reg_save_area + ap->fp_offset, 8);
                ap->fp_offset += 16;
                ফেরত ap->reg_save_area + ap->fp_offset - 32;
            }
        }
        যাও use_overflow_area;

    ক্ষেত্র __va_stack:
    use_overflow_area:
        ap->overflow_arg_area += আকার_2;
        ap->overflow_arg_area = (অক্ষর*)((long long)(ap->overflow_arg_area + align - 1) & -align);
        ফেরত ap->overflow_arg_area - আকার_2;

    পূর্বনির্ধারিত: /* should never happen */
        abort();
        ফেরত 0;
    }
}
#endif
