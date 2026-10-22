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

خارجي فراغ *کپی_حافظه(فراغ *dest, ثابت فراغ *src, بیعلامت دراز n);

فراغ *__va_arg(__builtin_va_list ap,
               صحيح arg_type,
               صحيح اندازه, صحيح align)
{
    اندازه = (اندازه + 7) & ~7;
    align = (align + 7) & ~7;
    بدل ((تعداد __va_arg_type)arg_type) {
    حالة __va_gen_reg:
        إذا (ap->gp_جابه_جایی + اندازه <= 48) {
            ap->gp_جابه_جایی += اندازه;
            أرجع ap->reg_save_area + ap->gp_جابه_جایی - اندازه;
        }
        اذهب use_سرریز_area;

    حالة __va_float_reg:
        إذا (ap->fp_جابه_جایی < 128 + 48) {
            ap->fp_جابه_جایی += 16;
            إذا (اندازه == 8)
                أرجع ap->reg_save_area + ap->fp_جابه_جایی - 16;
            إذا (ap->fp_جابه_جایی < 128 + 48) {
                کپی_حافظه(ap->reg_save_area + ap->fp_جابه_جایی - 8,
                       ap->reg_save_area + ap->fp_جابه_جایی, 8);
                ap->fp_جابه_جایی += 16;
                أرجع ap->reg_save_area + ap->fp_جابه_جایی - 32;
            }
        }
        اذهب use_سرریز_area;

    حالة __va_stack:
    use_سرریز_area:
        ap->سرریز_arg_area += اندازه;
        ap->سرریز_arg_area = (حرف*)((دراز دراز)(ap->سرریز_arg_area + align - 1) & -align);
        أرجع ap->سرریز_arg_area - اندازه;

    افتراضي: /* should never happen */
        abort();
        أرجع 0;
    }
}
#پایان_اگر
