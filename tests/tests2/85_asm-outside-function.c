#ifdef __leading_underscore
# define _ "_"
#དེ་མིན
# define _
#endif

extern ཧྲིལ printf (const var_na *, ...);
extern void vide(void);
__asm__(_"vide: ret");

ཧྲིལ main() {
    vide();
    printf ("okay\n");
    ལོག 0;
}
