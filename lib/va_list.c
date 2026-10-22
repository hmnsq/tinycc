/* va_list.c - tinycc support for va_list on X86_64 */

#ਜੇ defined __x86_64__

/* Avoid include files, they may not be available when cross compiling */
ਬਾਹਰੀ ਖਾਲੀ abort(ਖਾਲੀ);

/* This should be in sync with our include/stdarg.h */
ਗਿਣਤੀ __va_arg_type {
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

ਬਾਹਰੀ ਖਾਲੀ *ਸਮ੍ਰਿਤੀ_ਨਕਲ(ਖਾਲੀ *dest, ਅਚਲ ਖਾਲੀ *src, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ n);

ਖਾਲੀ *__va_arg(__builtin_va_list ap,
               ਪੂਰਨ arg_type,
               ਪੂਰਨ ਮਾਪ, ਪੂਰਨ align)
{
    ਮਾਪ = (ਮਾਪ + 7) & ~7;
    align = (align + 7) & ~7;
    ਚੋਣ ((ਗਿਣਤੀ __va_arg_type)arg_type) {
    ਹਾਲਤ __va_gen_reg:
        ਜੇ (ap->gp_ਵਿੱਥ + ਮਾਪ <= 48) {
            ap->gp_ਵਿੱਥ += ਮਾਪ;
            ਵਾਪਸ ap->reg_save_area + ap->gp_ਵਿੱਥ - ਮਾਪ;
        }
        ਜਾਓ use_ਉਛਾਲ_area;

    ਹਾਲਤ __va_float_reg:
        ਜੇ (ap->fp_ਵਿੱਥ < 128 + 48) {
            ap->fp_ਵਿੱਥ += 16;
            ਜੇ (ਮਾਪ == 8)
                ਵਾਪਸ ap->reg_save_area + ap->fp_ਵਿੱਥ - 16;
            ਜੇ (ap->fp_ਵਿੱਥ < 128 + 48) {
                ਸਮ੍ਰਿਤੀ_ਨਕਲ(ap->reg_save_area + ap->fp_ਵਿੱਥ - 8,
                       ap->reg_save_area + ap->fp_ਵਿੱਥ, 8);
                ap->fp_ਵਿੱਥ += 16;
                ਵਾਪਸ ap->reg_save_area + ap->fp_ਵਿੱਥ - 32;
            }
        }
        ਜਾਓ use_ਉਛਾਲ_area;

    ਹਾਲਤ __va_stack:
    use_ਉਛਾਲ_area:
        ap->ਉਛਾਲ_arg_area += ਮਾਪ;
        ap->ਉਛਾਲ_arg_area = (ਅੱਖਰ*)((ਲੰਮਾ ਲੰਮਾ)(ap->ਉਛਾਲ_arg_area + align - 1) & -align);
        ਵਾਪਸ ap->ਉਛਾਲ_arg_area - ਮਾਪ;

    ਮੂਲ: /* should never happen */
        abort();
        ਵਾਪਸ 0;
    }
}
#ਜੇ_ਅੰਤ
