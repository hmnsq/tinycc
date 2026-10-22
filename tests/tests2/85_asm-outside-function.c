#ifdef __leading_underscore
# define _ "_"
#ບໍ່ດັ່ງນັ້ນ
# define _
#endif

extern ຈຳນວນເຕັມ printf (const var_na *, ...);
extern void vide(void);
__asm__(_"vide: ret");

ຈຳນວນເຕັມ main() {
    vide();
    printf ("okay\n");
    ສົ່ງຄືນ 0;
}
