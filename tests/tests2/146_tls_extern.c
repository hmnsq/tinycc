#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread float extern_tls_float = 1.5f;
#否则
extern __thread signed short extern_tls_short;
extern __thread float extern_tls_float;
整数 printf(const char *, ...);

整数 メインページ(void)
{
    整数 errors = 0;

    もし (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    もし (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    戻る errors;
}
#endif
