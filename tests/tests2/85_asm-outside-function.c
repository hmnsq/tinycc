#ifdef __leading_underscore
# define _ "_"
#否则
# define _
#endif

extern 整数 printf (const char *, ...);
extern void vide(void);
__asm__(_"vide: ret");

整数 メインページ() {
    vide();
    printf ("okay\n");
    戻る 0;
}
