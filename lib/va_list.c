/* va_list.c - tinycc support for va_list on X86_64 */

#ఒకవేళ defined __x86_64__

/* Avoid include files, they may not be available when cross compiling */
బాహ్య శూన్య abort(శూన్య);

/* This should be in sync with our include/stdarg.h */
గణన __va_arg_type {
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

బాహ్య శూన్య *జ్ఞాపకం_నకలు(శూన్య *dest, స్థిరరాశి శూన్య *src, గుర్తులేని దీర్ఘ n);

శూన్య *__va_arg(__builtin_va_list ap,
               పూర్ణాంకం arg_type,
               పూర్ణాంకం కొలత, పూర్ణాంకం align)
{
    కొలత = (కొలత + 7) & ~7;
    align = (align + 7) & ~7;
    ఎంపిక ((గణన __va_arg_type)arg_type) {
    స్థితి __va_gen_reg:
        ఒకవేళ (ap->gp_స్థానభ్రంశం + కొలత <= 48) {
            ap->gp_స్థానభ్రంశం += కొలత;
            తిరిగి ap->reg_save_area + ap->gp_స్థానభ్రంశం - కొలత;
        }
        వెళ్ళు use_అధికప్రవాహం_area;

    స్థితి __va_float_reg:
        ఒకవేళ (ap->fp_స్థానభ్రంశం < 128 + 48) {
            ap->fp_స్థానభ్రంశం += 16;
            ఒకవేళ (కొలత == 8)
                తిరిగి ap->reg_save_area + ap->fp_స్థానభ్రంశం - 16;
            ఒకవేళ (ap->fp_స్థానభ్రంశం < 128 + 48) {
                జ్ఞాపకం_నకలు(ap->reg_save_area + ap->fp_స్థానభ్రంశం - 8,
                       ap->reg_save_area + ap->fp_స్థానభ్రంశం, 8);
                ap->fp_స్థానభ్రంశం += 16;
                తిరిగి ap->reg_save_area + ap->fp_స్థానభ్రంశం - 32;
            }
        }
        వెళ్ళు use_అధికప్రవాహం_area;

    స్థితి __va_stack:
    use_అధికప్రవాహం_area:
        ap->అధికప్రవాహం_arg_area += కొలత;
        ap->అధికప్రవాహం_arg_area = (అక్షరం*)((దీర్ఘ దీర్ఘ)(ap->అధికప్రవాహం_arg_area + align - 1) & -align);
        తిరిగి ap->అధికప్రవాహం_arg_area - కొలత;

    అప్రమేయ: /* should never happen */
        abort();
        తిరిగి 0;
    }
}
#అయితే_ముగింపు
