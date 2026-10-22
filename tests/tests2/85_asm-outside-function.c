#ifdef __leading_underscore
# define _ "_"
#มิฉะนั้น
# define _
#endif

extern จำนวนเต็ม printf (const var_na *, ...);
extern void vide(void);
__asm__(_"vide: ret");

จำนวนเต็ม หลัก() {
    vide();
    printf ("okay\n");
    คืน 0;
}
