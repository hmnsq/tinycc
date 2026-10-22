#ifdef DEFS
__thread चिन्हित लघु extern_tls_short = 1234;
__thread दशांश extern_tls_float = 1.5f;
#अन्यथा
बाह्य __thread चिन्हित लघु extern_tls_short;
बाह्य __thread दशांश extern_tls_float;
पूर्णांक म_लिखो(स्थिरांक अक्षर *, ...);

पूर्णांक main(शून्य)
{
    पूर्णांक errors = 0;

    जर (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    जर (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    म_लिखो("extern tls errors: %d\n", errors);
    परत errors;
}
#endif
