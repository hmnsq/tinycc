/* va_list.c - tinycc support for va_list on X86_64 */

#اگر defined __x86_64__

/* Avoid include files, they may not be available when cross compiling */
خارجی خالی abort(خالی);

/* This should be in sync with our include/stdarg.h */
شمار __va_arg_type {
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

خارجی خالی *حافظہ_نقل(خالی *dest, ثابت خالی *src, غیرعلامتی طویل n);

خالی *__va_arg(__builtin_va_list ap,
               صحیح arg_type,
               صحیح سائز, صحیح align)
{
    سائز = (سائز + 7) & ~7;
    align = (align + 7) & ~7;
    انتخاب ((شمار __va_arg_type)arg_type) {
    حالت __va_gen_reg:
        اگر (ap->gp_انحراف + سائز <= 48) {
            ap->gp_انحراف += سائز;
            واپس ap->reg_save_area + ap->gp_انحراف - سائز;
        }
        جاؤ use_حد_سے_تجاوز_area;

    حالت __va_float_reg:
        اگر (ap->fp_انحراف < 128 + 48) {
            ap->fp_انحراف += 16;
            اگر (سائز == 8)
                واپس ap->reg_save_area + ap->fp_انحراف - 16;
            اگر (ap->fp_انحراف < 128 + 48) {
                حافظہ_نقل(ap->reg_save_area + ap->fp_انحراف - 8,
                       ap->reg_save_area + ap->fp_انحراف, 8);
                ap->fp_انحراف += 16;
                واپس ap->reg_save_area + ap->fp_انحراف - 32;
            }
        }
        جاؤ use_حد_سے_تجاوز_area;

    حالت __va_stack:
    use_حد_سے_تجاوز_area:
        ap->حد_سے_تجاوز_arg_area += سائز;
        ap->حد_سے_تجاوز_arg_area = (حرف*)((طویل طویل)(ap->حد_سے_تجاوز_arg_area + align - 1) & -align);
        واپس ap->حد_سے_تجاوز_arg_area - سائز;

    طےشدہ: /* should never happen */
        abort();
        واپس 0;
    }
}
#اگر_ختم
