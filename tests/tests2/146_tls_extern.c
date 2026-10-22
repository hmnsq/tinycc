#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread float extern_tls_float = 1.5f;
#නැතහොත්
extern __thread signed short extern_tls_short;
extern __thread float extern_tls_float;
පූර්ණ_සංඛ්‍යා printf(const var_na *, ...);

පූර්ණ_සංඛ්‍යා main(void)
{
    පූර්ණ_සංඛ්‍යා errors = 0;

    නම් (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    නම් (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    ආපසු errors;
}
#endif
