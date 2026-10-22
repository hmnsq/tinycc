#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread float extern_tls_float = 1.5f;
#มิฉะนั้น
extern __thread signed short extern_tls_short;
extern __thread float extern_tls_float;
จำนวนเต็ม printf(const var_na *, ...);

จำนวนเต็ม หลัก(void)
{
    จำนวนเต็ม errors = 0;

    ถ้า (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    ถ้า (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    คืน errors;
}
#endif
