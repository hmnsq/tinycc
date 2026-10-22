#ifdef __leading_underscore
# define _ "_"
#অন্যথা
# define _
#endif

বাহ্যিক পূর্ণসংখ্যা printf (ধ্রুবক অক্ষর *, ...);
বাহ্যিক শূন্য vide(শূন্য);
__asm__(_"vide: ret");

পূর্ণসংখ্যা প্রধান() {
    vide();
    printf ("okay\n");
    ফেরত 0;
}
