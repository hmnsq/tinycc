#ifdef __leading_underscore
# define _ "_"
#അല്ലെങ്കിൽ
# define _
#endif

ബാഹ്യ പൂർണ്ണസംഖ്യ printf (സ്ഥിരം അക്ഷരം *, ...);
ബാഹ്യ ശൂന്യം vide(ശൂന്യം);
__asm__(_"vide: ret");

പൂർണ്ണസംഖ്യ പ്രധാന() {
    vide();
    printf ("okay\n");
    തിരികെ 0;
}
