#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread float extern_tls_float = 1.5f;
#ᬮᬶᬬ
extern __thread signed short extern_tls_short;
extern __thread float extern_tls_float;
puur_naa_nka printf(const var_na *, ...);

puur_naa_nka main(void)
{
    puur_naa_nka errors = 0;

    ᬬᬾᬦ᭄ (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    ᬬᬾᬦ᭄ (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    ᬯᬮᬶ errors;
}
#endif
