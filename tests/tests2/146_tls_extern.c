#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread ಭಿನ್ನ extern_tls_float = 1.5f;
#ಅನ್ಯಥಾ
ಬಾಹ್ಯ __thread signed short extern_tls_short;
ಬಾಹ್ಯ __thread ಭಿನ್ನ extern_tls_float;
ಪೂರ್ಣಾಙ್ಕ printf(ಧ್ರುವ ವರ್ಣ *, ...);

ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ errors = 0;

    ಯದಿ (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    ಯದಿ (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    ಪ್ರತ್ಯಾಗಮ errors;
}
#endif
