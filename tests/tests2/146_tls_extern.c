#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread float extern_tls_float = 1.5f;
#иначе
extern __thread signed short extern_tls_short;
extern __thread float extern_tls_float;
целое printf(const char *, ...);

целое основной(void)
{
    целое errors = 0;

    если (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    если (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    вернуть errors;
}
#endif
