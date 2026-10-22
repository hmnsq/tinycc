#ifdef __leading_underscore
# define _ "_"
#иначе
# define _
#endif

extern целое printf (const char *, ...);
extern void vide(void);
__asm__(_"vide: ret");

целое основной() {
    vide();
    printf ("okay\n");
    вернуть 0;
}
