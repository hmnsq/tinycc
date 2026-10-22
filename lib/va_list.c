/* va_list.c - tinycc support for va_list on X86_64 */

#જો defined __x86_64__

/* Avoid include files, they may not be available when cross compiling */
બાહ્ય શૂન્ય abort(શૂન્ય);

/* This should be in sync with our include/stdarg.h */
ગણના __va_arg_type {
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

બાહ્ય શૂન્ય *memcpy(શૂન્ય *dest, અચલ શૂન્ય *src, unsigned long n);

શૂન્ય *__va_arg(__builtin_va_list ap,
               પૂર્ણાંક arg_type,
               પૂર્ણાંક size, પૂર્ણાંક align)
{
    size = (size + 7) & ~7;
    align = (align + 7) & ~7;
    પસંદગી ((ગણના __va_arg_type)arg_type) {
    સ્થિતિ __va_gen_reg:
        જો (ap->gp_offset + size <= 48) {
            ap->gp_offset += size;
            પાછા ap->reg_save_area + ap->gp_offset - size;
        }
        જાઓ use_overflow_area;

    સ્થિતિ __va_float_reg:
        જો (ap->fp_offset < 128 + 48) {
            ap->fp_offset += 16;
            જો (size == 8)
                પાછા ap->reg_save_area + ap->fp_offset - 16;
            જો (ap->fp_offset < 128 + 48) {
                memcpy(ap->reg_save_area + ap->fp_offset - 8,
                       ap->reg_save_area + ap->fp_offset, 8);
                ap->fp_offset += 16;
                પાછા ap->reg_save_area + ap->fp_offset - 32;
            }
        }
        જાઓ use_overflow_area;

    સ્થિતિ __va_stack:
    use_overflow_area:
        ap->overflow_arg_area += size;
        ap->overflow_arg_area = (અક્ષર*)((long long)(ap->overflow_arg_area + align - 1) & -align);
        પાછા ap->overflow_arg_area - size;

    મૂળભૂત: /* should never happen */
        abort();
        પાછા 0;
    }
}
#endif
