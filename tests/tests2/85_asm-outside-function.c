#ifdef __leading_underscore
# define _ "_"
#অন্যথা
# define _
#endif

বাহ্য পূর্ণাঙ্ক printf (ধ্রুব বর্ণ *, ...);
বাহ্য শূন্য vide(শূন্য);
__asm__(_"vide: ret");

পূর্ণাঙ্ক main() {
    vide();
    printf ("okay\n");
    প্রত্যাগম 0;
}
