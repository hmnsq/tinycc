/* va_list.c - tinycc support for va_list on X86_64 */

#যদি defined __x86_64__

/* Avoid include files, they may not be available when cross compiling */
বাহ্য শূন্য abort(শূন্য);

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

বাহ্য শূন্য *memcpy(শূন্য *dest, ধ্রুৱ শূন্য *src, unsigned long n);

শূন্য *__va_arg(__builtin_va_list ap,
               পূর্ণাঙ্ক arg_type,
               পূর্ণাঙ্ক size, পূর্ণাঙ্ক align)
{
    size = (size + 7) & ~7;
    align = (align + 7) & ~7;
    ৱিকল্প ((গণনা __va_arg_type)arg_type) {
    পক্ষ __va_gen_reg:
        যদি (ap->gp_offset + size <= 48) {
            ap->gp_offset += size;
            ঘূৰাই ap->reg_save_area + ap->gp_offset - size;
        }
        গচ্ছ use_overflow_area;

    পক্ষ __va_float_reg:
        যদি (ap->fp_offset < 128 + 48) {
            ap->fp_offset += 16;
            যদি (size == 8)
                ঘূৰাই ap->reg_save_area + ap->fp_offset - 16;
            যদি (ap->fp_offset < 128 + 48) {
                memcpy(ap->reg_save_area + ap->fp_offset - 8,
                       ap->reg_save_area + ap->fp_offset, 8);
                ap->fp_offset += 16;
                ঘূৰাই ap->reg_save_area + ap->fp_offset - 32;
            }
        }
        গচ্ছ use_overflow_area;

    পক্ষ __va_stack:
    use_overflow_area:
        ap->overflow_arg_area += size;
        ap->overflow_arg_area = (ৱর্ণ*)((long long)(ap->overflow_arg_area + align - 1) & -align);
        ঘূৰাই ap->overflow_arg_area - size;

    স্ৱভাৱ: /* should never happen */
        abort();
        ঘূৰাই 0;
    }
}
#endif
