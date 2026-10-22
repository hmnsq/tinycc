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

خارجي فراغ *يادگيري_نقل(فراغ *dest, ثابت فراغ *src, بنانشان ڊگهو n);

فراغ *__va_arg(__builtin_va_list ap,
               صحيح arg_type,
               صحيح سائيز, صحيح align)
{
    سائيز = (سائيز + 7) & ~7;
    align = (align + 7) & ~7;
    بدل ((تعداد __va_arg_type)arg_type) {
    حالة __va_gen_reg:
        إذا (ap->gp_وٿي + سائيز <= 48) {
            ap->gp_وٿي += سائيز;
            أرجع ap->reg_save_area + ap->gp_وٿي - سائيز;
        }
        اذهب use_حد_کان_مٿي_area;

    حالة __va_float_reg:
        إذا (ap->fp_وٿي < 128 + 48) {
            ap->fp_وٿي += 16;
            إذا (سائيز == 8)
                أرجع ap->reg_save_area + ap->fp_وٿي - 16;
            إذا (ap->fp_وٿي < 128 + 48) {
                يادگيري_نقل(ap->reg_save_area + ap->fp_وٿي - 8,
                       ap->reg_save_area + ap->fp_وٿي, 8);
                ap->fp_وٿي += 16;
                أرجع ap->reg_save_area + ap->fp_وٿي - 32;
            }
        }
        اذهب use_حد_کان_مٿي_area;

    حالة __va_stack:
    use_حد_کان_مٿي_area:
        ap->حد_کان_مٿي_arg_area += سائيز;
        ap->حد_کان_مٿي_arg_area = (حرف*)((ڊگهو ڊگهو)(ap->حد_کان_مٿي_arg_area + align - 1) & -align);
        أرجع ap->حد_کان_مٿي_arg_area - سائيز;

    افتراضي: /* should never happen */
        abort();
        أرجع 0;
    }
}
#جيڪڏهن_پورو
