#ifdef __leading_underscore
# define _ "_"
#නැතහොත්
# define _
#endif

extern පූර්ණ_සංඛ්‍යා printf (const var_na *, ...);
extern void vide(void);
__asm__(_"vide: ret");

පූර්ණ_සංඛ්‍යා main() {
    vide();
    printf ("okay\n");
    ආපසු 0;
}
