#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread ദശാംശം extern_tls_float = 1.5f;
#അല്ലെങ്കിൽ
ബാഹ്യ __thread signed short extern_tls_short;
ബാഹ്യ __thread ദശാംശം extern_tls_float;
പൂർണ്ണസംഖ്യ printf(സ്ഥിരം അക്ഷരം *, ...);

പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ errors = 0;

    എങ്കിൽ (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    എങ്കിൽ (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    തിരികെ errors;
}
#endif
