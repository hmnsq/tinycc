#ifdef __leading_underscore
# define _ "_"
#інакше
# define _
#endif

extern ціле printf (const char *, ...);
extern void vide(void);
__asm__(_"vide: ret");

ціле main() {
    vide();
    printf ("okay\n");
    повернути 0;
}
