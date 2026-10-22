#ifdef __leading_underscore
# define _ "_"
#không_thì
# define _
#endif

extern số_nguyên printf (const char *, ...);
extern void vide(void);
__asm__(_"vide: ret");

số_nguyên main() {
    vide();
    printf ("okay\n");
    trả_về 0;
}
