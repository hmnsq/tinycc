/* va_list.c - tinycc support for va_list on X86_64 */

#ако defined __x86_64__

/* Avoid include files, they may not be available when cross compiling */
extern void abort(void);

/* This should be in sync with our include/stdarg.h */
enum __va_arg_type {
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
               цяло arg_type,
               цяло size, цяло align)
{
    size = (size + 7) & ~7;
    align = (align + 7) & ~7;
    switch ((enum __va_arg_type)arg_type) {
    case __va_gen_reg:
        ако (ap->gp_offset + size <= 48) {
            ap->gp_offset += size;
            върни ap->reg_save_area + ap->gp_offset - size;
        }
        goto use_overflow_area;

    case __va_float_reg:
        ако (ap->fp_offset < 128 + 48) {
            ap->fp_offset += 16;
            ако (size == 8)
                върни ap->reg_save_area + ap->fp_offset - 16;
            ако (ap->fp_offset < 128 + 48) {
                memcpy(ap->reg_save_area + ap->fp_offset - 8,
                       ap->reg_save_area + ap->fp_offset, 8);
                ap->fp_offset += 16;
                върни ap->reg_save_area + ap->fp_offset - 32;
            }
        }
        goto use_overflow_area;

    case __va_stack:
    use_overflow_area:
        ap->overflow_arg_area += size;
        ap->overflow_arg_area = (char*)((long long)(ap->overflow_arg_area + align - 1) & -align);
        върни ap->overflow_arg_area - size;

    default: /* should never happen */
        abort();
        върни 0;
    }
}
#endif
