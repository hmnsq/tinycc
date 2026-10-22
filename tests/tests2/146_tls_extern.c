#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread ଦଶମିକ extern_tls_float = 1.5f;
#ଅନ୍ୟଥା
ବାହ୍ୟ __thread signed short extern_tls_short;
ବାହ୍ୟ __thread ଦଶମିକ extern_tls_float;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf(ଅଚଳ ଅକ୍ଷର *, ...);

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା errors = 0;

    ଯଦି (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    ଯଦି (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    ଫେରନ୍ତୁ errors;
}
#endif
