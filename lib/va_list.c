/* va_list.c - tinycc support for va_list on X86_64 */

#अगर defined __x86_64__

/* Avoid include files, they may not be available when cross compiling */
बाह्य व्योम पात(व्योम);

/* This should be in sync with our include/stdarg.h */
क्रमागत __va_arg_type {
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

बाह्य व्योम *स_नकल(व्योम *dest, स्थिर व्योम *src, अचिन्हित दीर्घ n);

व्योम *__va_arg(__builtin_va_list ap,
               पूर्णांक arg_type,
               पूर्णांक आकार, पूर्णांक align)
{
    आकार = (आकार + 7) & ~7;
    align = (align + 7) & ~7;
    चयन ((क्रमागत __va_arg_type)arg_type) {
    हाल __va_gen_reg:
        अगर (ap->gp_offset + आकार <= 48) {
            ap->gp_offset += आकार;
            वापस ap->reg_save_area + ap->gp_offset - आकार;
        }
        जाओ use_overflow_area;

    हाल __va_float_reg:
        अगर (ap->fp_offset < 128 + 48) {
            ap->fp_offset += 16;
            अगर (आकार == 8)
                वापस ap->reg_save_area + ap->fp_offset - 16;
            अगर (ap->fp_offset < 128 + 48) {
                स_नकल(ap->reg_save_area + ap->fp_offset - 8,
                       ap->reg_save_area + ap->fp_offset, 8);
                ap->fp_offset += 16;
                वापस ap->reg_save_area + ap->fp_offset - 32;
            }
        }
        जाओ use_overflow_area;

    हाल __va_stack:
    use_overflow_area:
        ap->overflow_arg_area += आकार;
        ap->overflow_arg_area = (अक्षर*)((दीर्घ दीर्घ)(ap->overflow_arg_area + align - 1) & -align);
        वापस ap->overflow_arg_area - आकार;

    शेष: /* should never happen */
        पात();
        वापस 0;
    }
}
#पूर्ण_अगर
