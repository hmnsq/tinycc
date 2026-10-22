#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread float extern_tls_float = 1.5f;
#інакше
extern __thread signed short extern_tls_short;
extern __thread float extern_tls_float;
ціле printf(const char *, ...);

ціле main(void)
{
    ціле errors = 0;

    якщо (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    якщо (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    повернути errors;
}
#endif
