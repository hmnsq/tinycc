#ifdef __leading_underscore
# define _ "_"
#ଅନ୍ୟଥା
# define _
#endif

ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf (ଅଚଳ ଅକ୍ଷର *, ...);
ବାହ୍ୟ ଶୂନ୍ୟ vide(ଶୂନ୍ୟ);
__asm__(_"vide: ret");

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ() {
    vide();
    printf ("okay\n");
    ଫେରନ୍ତୁ 0;
}
