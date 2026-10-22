#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread float extern_tls_float = 1.5f;
#không_thì
extern __thread signed short extern_tls_short;
extern __thread float extern_tls_float;
số_nguyên printf(const char *, ...);

số_nguyên main(void)
{
    số_nguyên errors = 0;

    nếu (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    nếu (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    trả_về errors;
}
#endif
