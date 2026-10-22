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

خارجي فراغ *حافظہ_نقل(فراغ *dest, ثابت فراغ *src, بنانشانی لما n);

فراغ *__va_arg(__builtin_va_list ap,
               صحيح arg_type,
               صحيح ناپ, صحيح align)
{
    ناپ = (ناپ + 7) & ~7;
    align = (align + 7) & ~7;
    بدل ((تعداد __va_arg_type)arg_type) {
    حالة __va_gen_reg:
        إذا (ap->gp_وتھ + ناپ <= 48) {
            ap->gp_وتھ += ناپ;
            أرجع ap->reg_save_area + ap->gp_وتھ - ناپ;
        }
        اذهب use_حد_توں_ودھ_area;

    حالة __va_float_reg:
        إذا (ap->fp_وتھ < 128 + 48) {
            ap->fp_وتھ += 16;
            إذا (ناپ == 8)
                أرجع ap->reg_save_area + ap->fp_وتھ - 16;
            إذا (ap->fp_وتھ < 128 + 48) {
                حافظہ_نقل(ap->reg_save_area + ap->fp_وتھ - 8,
                       ap->reg_save_area + ap->fp_وتھ, 8);
                ap->fp_وتھ += 16;
                أرجع ap->reg_save_area + ap->fp_وتھ - 32;
            }
        }
        اذهب use_حد_توں_ودھ_area;

    حالة __va_stack:
    use_حد_توں_ودھ_area:
        ap->حد_توں_ودھ_arg_area += ناپ;
        ap->حد_توں_ودھ_arg_area = (حرف*)((لما لما)(ap->حد_توں_ودھ_arg_area + align - 1) & -align);
        أرجع ap->حد_توں_ودھ_arg_area - ناپ;

    افتراضي: /* should never happen */
        abort();
        أرجع 0;
    }
}
#جے_انت
