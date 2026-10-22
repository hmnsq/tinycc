#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread float extern_tls_float = 1.5f;
#បើមិនដូច្នេះ
extern __thread signed short extern_tls_short;
extern __thread float extern_tls_float;
ចំនួនគត់ printf(const var_na *, ...);

ចំនួនគត់ main(void)
{
    ចំនួនគត់ errors = 0;

    ប្រសិនបើ (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    ប្រសិនបើ (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    ត្រឡប់ errors;
}
#endif
