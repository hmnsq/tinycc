/* va_list.c - tinycc support for va_list on X86_64 */

#אם defined __x86_64__

/* Avoid include files, they may not be available when cross compiling */
خارجي فراغ abort(فراغ);

/* This should be in sync with our include/stdarg.h */
تعداد __va_arg_type {
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

خارجي فراغ *memcpy(فراغ *dest, ثابت فراغ *src, unsigned long n);

فراغ *__va_arg(__builtin_va_list ap,
               صحيح arg_type,
               صحيح size, صحيح align)
{
    size = (size + 7) & ~7;
    align = (align + 7) & ~7;
    بدل ((تعداد __va_arg_type)arg_type) {
    حالة __va_gen_reg:
        אם (ap->gp_offset + size <= 48) {
            ap->gp_offset += size;
            החזר ap->reg_save_area + ap->gp_offset - size;
        }
        اذهب use_overflow_area;

    حالة __va_float_reg:
        אם (ap->fp_offset < 128 + 48) {
            ap->fp_offset += 16;
            אם (size == 8)
                החזר ap->reg_save_area + ap->fp_offset - 16;
            אם (ap->fp_offset < 128 + 48) {
                memcpy(ap->reg_save_area + ap->fp_offset - 8,
                       ap->reg_save_area + ap->fp_offset, 8);
                ap->fp_offset += 16;
                החזר ap->reg_save_area + ap->fp_offset - 32;
            }
        }
        اذهب use_overflow_area;

    حالة __va_stack:
    use_overflow_area:
        ap->overflow_arg_area += size;
        ap->overflow_arg_area = (حرف*)((long long)(ap->overflow_arg_area + align - 1) & -align);
        החזר ap->overflow_arg_area - size;

    افتراضي: /* should never happen */
        abort();
        החזר 0;
    }
}
#endif
