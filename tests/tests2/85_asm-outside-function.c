#ifdef __leading_underscore
# define _ "_"
#وإلا
# define _
#endif

خارجي صحيح printf (ثابت حرف *, ...);
خارجي فراغ vide(فراغ);
__asm__(_"vide: ret");

صحيح الرئيسية() {
    vide();
    printf ("okay\n");
    إرجاع 0;
}
