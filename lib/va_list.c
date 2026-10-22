/* va_list.c - tinycc support for va_list on X86_64 */

#ပေႃး defined __x86_64__

/* Avoid include files, they may not be available when cross compiling */
extern void abort(void);

/* This should be in sync with our include/stdarg.h */
ga_nanaa __va_arg_type {
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

extern void *memcpy(void *dest, const void *src, unsigned long n);

void *__va_arg(__builtin_va_list ap,
               puur_naa_nka arg_type,
               puur_naa_nka size, puur_naa_nka align)
{
    size = (size + 7) & ~7;
    align = (align + 7) & ~7;
    switch ((ga_nanaa __va_arg_type)arg_type) {
    pak_sa __va_gen_reg:
        ပေႃး (ap->gp_offset + size <= 48) {
            ap->gp_offset += size;
            ပွၵ်ႈ ap->reg_save_area + ap->gp_offset - size;
        }
        goto use_overflow_area;

    pak_sa __va_float_reg:
        ပေႃး (ap->fp_offset < 128 + 48) {
            ap->fp_offset += 16;
            ပေႃး (size == 8)
                ပွၵ်ႈ ap->reg_save_area + ap->fp_offset - 16;
            ပေႃး (ap->fp_offset < 128 + 48) {
                memcpy(ap->reg_save_area + ap->fp_offset - 8,
                       ap->reg_save_area + ap->fp_offset, 8);
                ap->fp_offset += 16;
                ပွၵ်ႈ ap->reg_save_area + ap->fp_offset - 32;
            }
        }
        goto use_overflow_area;

    pak_sa __va_stack:
    use_overflow_area:
        ap->overflow_arg_area += size;
        ap->overflow_arg_area = (var_na*)((long long)(ap->overflow_arg_area + align - 1) & -align);
        ပွၵ်ႈ ap->overflow_arg_area - size;

    default: /* should never happen */
        abort();
        ပွၵ်ႈ 0;
    }
}
#endif
