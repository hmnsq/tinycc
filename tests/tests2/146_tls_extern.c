#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ DEFS
__thread ਨਿਸ਼ਾਨੀਵਾਲਾ ਛੋਟਾ extern_tls_short = 1234;
__thread ਦਸ਼ਮਲਵ extern_tls_float = 1.5f;
#ਨਹੀਂਤਾਂ
ਬਾਹਰੀ __thread ਨਿਸ਼ਾਨੀਵਾਲਾ ਛੋਟਾ extern_tls_short;
ਬਾਹਰੀ __thread ਦਸ਼ਮਲਵ extern_tls_float;
ਪੂਰਨ ਲਿਖੋ(ਅਚਲ ਅੱਖਰ *, ...);

ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
    ਪੂਰਨ errors = 0;

    ਜੇ (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    ਜੇ (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    ਲਿਖੋ("extern tls errors: %d\n", errors);
    ਵਾਪਸ errors;
}
#ਜੇ_ਅੰਤ
