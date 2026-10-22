#ifdef __leading_underscore
# define _ "_"
#иначе
# define _
#endif

extern цяло printf (const char *, ...);
extern void vide(void);
__asm__(_"vide: ret");

цяло main() {
    vide();
    printf ("okay\n");
    върни 0;
}
