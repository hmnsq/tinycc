#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread भिन्न extern_tls_float = 1.5f;
#अन्यथा
बाह्य __thread signed short extern_tls_short;
बाह्य __thread भिन्न extern_tls_float;
पूर्णाङ्क printf(ध्रुव वर्ण *, ...);

पूर्णाङ्क main(शून्य)
{
    पूर्णाङ्क errors = 0;

    यदि (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    यदि (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    प्रत्यागम errors;
}
#endif
