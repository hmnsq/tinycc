#ifdef __leading_underscore
# define _ "_"
#မဟုတ်ပါက
# define _
#endif

extern ကိန်းပြည့် printf (const var_na *, ...);
extern void vide(void);
__asm__(_"vide: ret");

ကိန်းပြည့် main() {
    vide();
    printf ("okay\n");
    ပြန်ပေး 0;
}
