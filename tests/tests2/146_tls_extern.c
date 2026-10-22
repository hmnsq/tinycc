#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread தசம extern_tls_float = 1.5f;
#இல்லையெனில்
வெளி __thread signed short extern_tls_short;
வெளி __thread தசம extern_tls_float;
முழு printf(மாறிலி எழுத்து *, ...);

முழு முதன்மை(வெறுமை)
{
    முழு errors = 0;

    எனில் (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    எனில் (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    திரும்பு errors;
}
#endif
