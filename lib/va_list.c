/* va_list.c - tinycc support for va_list on X86_64 */

#اگر defined __x86_64__

/* Avoid include files, they may not be available when cross compiling */
بیرونی تهی abort(تهی);

/* This should be in sync with our include/stdarg.h */
شمارش __va_arg_type {
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

بیرونی تهی *memcpy(تهی *dest, ثابت تهی *src, unsigned long n);

تهی *__va_arg(__builtin_va_list ap,
               صحیح arg_type,
               صحیح size, صحیح align)
{
    size = (size + 7) & ~7;
    align = (align + 7) & ~7;
    انتخاب ((شمارش __va_arg_type)arg_type) {
    حالت __va_gen_reg:
        اگر (ap->gp_offset + size <= 48) {
            ap->gp_offset += size;
            بازگشت ap->reg_save_area + ap->gp_offset - size;
        }
        برو use_overflow_area;

    حالت __va_float_reg:
        اگر (ap->fp_offset < 128 + 48) {
            ap->fp_offset += 16;
            اگر (size == 8)
                بازگشت ap->reg_save_area + ap->fp_offset - 16;
            اگر (ap->fp_offset < 128 + 48) {
                memcpy(ap->reg_save_area + ap->fp_offset - 8,
                       ap->reg_save_area + ap->fp_offset, 8);
                ap->fp_offset += 16;
                بازگشت ap->reg_save_area + ap->fp_offset - 32;
            }
        }
        برو use_overflow_area;

    حالت __va_stack:
    use_overflow_area:
        ap->overflow_arg_area += size;
        ap->overflow_arg_area = (نویسه*)((long long)(ap->overflow_arg_area + align - 1) & -align);
        بازگشت ap->overflow_arg_area - size;

    پیشفرض: /* should never happen */
        abort();
        بازگشت 0;
    }
}
#endif
