#ifdef __leading_underscore
# define _ "_"
#បើមិនដូច្នេះ
# define _
#endif

extern ចំនួនគត់ printf (const var_na *, ...);
extern void vide(void);
__asm__(_"vide: ret");

ចំនួនគត់ main() {
    vide();
    printf ("okay\n");
    ត្រឡប់ 0;
}
