#ifdef __leading_underscore
# define _ "_"
#وگرنه
# define _
#endif

بیرونی صحیح printf (ثابت نویسه *, ...);
بیرونی تهی vide(تهی);
__asm__(_"vide: ret");

صحیح اصلی() {
    vide();
    printf ("okay\n");
    بازگشت 0;
}
