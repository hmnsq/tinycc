#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ DEFS
__thread ಚಿಹ್ನೆಯುಳ್ಳ ಗಿಡ್ಡ extern_tls_short = 1234;
__thread ದಶಮಾಂಶ extern_tls_float = 1.5f;
#ಇಲ್ಲದಿದ್ದರೆ
ಬಾಹ್ಯ __thread ಚಿಹ್ನೆಯುಳ್ಳ ಗಿಡ್ಡ extern_tls_short;
ಬಾಹ್ಯ __thread ದಶಮಾಂಶ extern_tls_float;
ಪೂರ್ಣಾಂಕ ಬರೆ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *, ...);

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ errors = 0;

    ಆದರೆ (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    ಆದರೆ (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    ಬರೆ("extern tls errors: %d\n", errors);
    ಹಿಂತಿರುಗಿ errors;
}
#ಆದರೆ_ಅಂತ್ಯ
