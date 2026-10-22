#ifdef __leading_underscore
# define _ "_"
#아니면
# define _
#endif

extern 정수 printf (const char *, ...);
extern void vide(void);
__asm__(_"vide: ret");

정수 main() {
    vide();
    printf ("okay\n");
    반환 0;
}
