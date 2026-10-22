#ifdef __leading_underscore
# define _ "_"
#אחרת
# define _
#endif

خارجي صحيح printf (ثابت حرف *, ...);
خارجي فراغ vide(فراغ);
__asm__(_"vide: ret");

صحيح main() {
    vide();
    printf ("okay\n");
    החזר 0;
}
