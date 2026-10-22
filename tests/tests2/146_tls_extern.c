#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread દશાંશ extern_tls_float = 1.5f;
#નહીંતર
બાહ્ય __thread signed short extern_tls_short;
બાહ્ય __thread દશાંશ extern_tls_float;
પૂર્ણાંક printf(અચલ અક્ષર *, ...);

પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    પૂર્ણાંક errors = 0;

    જો (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    જો (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    પાછા errors;
}
#endif
