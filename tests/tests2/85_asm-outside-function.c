#ifdef __leading_underscore
# define _ "_"
#இல்லையெனில்
# define _
#endif

வெளி முழு printf (மாறிலி எழுத்து *, ...);
வெளி வெறுமை vide(வெறுமை);
__asm__(_"vide: ret");

முழு முதன்மை() {
    vide();
    printf ("okay\n");
    திரும்பு 0;
}
