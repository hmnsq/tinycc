#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread عائم extern_tls_float = 1.5f;
#وإلا
خارجي __thread signed short extern_tls_short;
خارجي __thread عائم extern_tls_float;
صحيح printf(ثابت حرف *, ...);

صحيح main(فراغ)
{
    صحيح errors = 0;

    𐡄𐡍 (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    𐡄𐡍 (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    أرجع errors;
}
#endif
