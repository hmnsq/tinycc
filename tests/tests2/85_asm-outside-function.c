#ifdef __leading_underscore
# define _ "_"
#инако
# define _
#endif

extern цео printf (const char *, ...);
extern void vide(void);
__asm__(_"vide: ret");

цео main() {
    vide();
    printf ("okay\n");
    врати 0;
}
