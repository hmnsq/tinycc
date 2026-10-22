#अगर_घोषित DEFS
__thread चिन्हित लघु extern_tls_short = 1234;
__thread भग्न extern_tls_float = 1.5f;
#अन्यथा
बाह्य __thread चिन्हित लघु extern_tls_short;
बाह्य __thread भग्न extern_tls_float;
पूर्णांक म_लिखो(स्थिर अक्षर *, ...);

पूर्णांक मुख्य(व्योम)
{
    पूर्णांक errors = 0;

    अगर (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    अगर (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    म_लिखो("extern tls errors: %d\n", errors);
    वापस errors;
}
#पूर्ण_अगर
