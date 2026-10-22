/* va_list.c - tinycc support for va_list on X86_64 */

#إذا defined __x86_64__

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

خارجي فراغ *حافظه_نقل(فراغ *dest, ثابت فراغ *src, بینښه اوږد n);

فراغ *__va_arg(__builtin_va_list ap,
               صحيح arg_type,
               صحيح اندازه, صحيح align)
{
    اندازه = (اندازه + 7) & ~7;
    align = (align + 7) & ~7;
    بدل ((تعداد __va_arg_type)arg_type) {
    حالة __va_gen_reg:
        إذا (ap->gp_دننه_واټن + اندازه <= 48) {
            ap->gp_دننه_واټن += اندازه;
            أرجع ap->reg_save_area + ap->gp_دننه_واټن - اندازه;
        }
        اذهب use_ډکېدنه_area;

    حالة __va_float_reg:
        إذا (ap->fp_دننه_واټن < 128 + 48) {
            ap->fp_دننه_واټن += 16;
            إذا (اندازه == 8)
                أرجع ap->reg_save_area + ap->fp_دننه_واټن - 16;
            إذا (ap->fp_دننه_واټن < 128 + 48) {
                حافظه_نقل(ap->reg_save_area + ap->fp_دننه_واټن - 8,
                       ap->reg_save_area + ap->fp_دننه_واټن, 8);
                ap->fp_دننه_واټن += 16;
                أرجع ap->reg_save_area + ap->fp_دننه_واټن - 32;
            }
        }
        اذهب use_ډکېدنه_area;

    حالة __va_stack:
    use_ډکېدنه_area:
        ap->ډکېدنه_arg_area += اندازه;
        ap->ډکېدنه_arg_area = (حرف*)((اوږد اوږد)(ap->ډکېدنه_arg_area + align - 1) & -align);
        أرجع ap->ډکېدنه_arg_area - اندازه;

    افتراضي: /* should never happen */
        abort();
        أرجع 0;
    }
}
#د_که_پای
