#ifdef __leading_underscore
# define _ "_"
#ပေႃးဢမ်ႇ
# define _
#endif

extern puur_naa_nka printf (const var_na *, ...);
extern void vide(void);
__asm__(_"vide: ret");

puur_naa_nka main() {
    vide();
    printf ("okay\n");
    ပွၵ်ႈ 0;
}
