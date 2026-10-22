#ifdef __leading_underscore
# define _ "_"
#નહીંતર
# define _
#endif

બાહ્ય પૂર્ણાંક printf (અચલ અક્ષર *, ...);
બાહ્ય શૂન્ય vide(શૂન્ય);
__asm__(_"vide: ret");

પૂર્ણાંક મુખ્ય() {
    vide();
    printf ("okay\n");
    પાછા 0;
}
