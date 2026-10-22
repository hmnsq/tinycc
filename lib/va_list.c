/* va_list.c - tinycc support for va_list on X86_64 */

#எனில் defined __x86_64__

/* Avoid include files, they may not be available when cross compiling */
வெளி வெறுமை abort(வெறுமை);

/* This should be in sync with our include/stdarg.h */
எண்ணிக்கை __va_arg_type {
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

வெளி வெறுமை *memcpy(வெறுமை *dest, மாறிலி வெறுமை *src, unsigned long n);

வெறுமை *__va_arg(__builtin_va_list ap,
               முழு arg_type,
               முழு size, முழு align)
{
    size = (size + 7) & ~7;
    align = (align + 7) & ~7;
    தேர்வு ((எண்ணிக்கை __va_arg_type)arg_type) {
    நிலை __va_gen_reg:
        எனில் (ap->gp_offset + size <= 48) {
            ap->gp_offset += size;
            திரும்பு ap->reg_save_area + ap->gp_offset - size;
        }
        செல் use_overflow_area;

    நிலை __va_float_reg:
        எனில் (ap->fp_offset < 128 + 48) {
            ap->fp_offset += 16;
            எனில் (size == 8)
                திரும்பு ap->reg_save_area + ap->fp_offset - 16;
            எனில் (ap->fp_offset < 128 + 48) {
                memcpy(ap->reg_save_area + ap->fp_offset - 8,
                       ap->reg_save_area + ap->fp_offset, 8);
                ap->fp_offset += 16;
                திரும்பு ap->reg_save_area + ap->fp_offset - 32;
            }
        }
        செல் use_overflow_area;

    நிலை __va_stack:
    use_overflow_area:
        ap->overflow_arg_area += size;
        ap->overflow_arg_area = (எழுத்து*)((long long)(ap->overflow_arg_area + align - 1) & -align);
        திரும்பு ap->overflow_arg_area - size;

    இயல்பு: /* should never happen */
        abort();
        திரும்பு 0;
    }
}
#endif
