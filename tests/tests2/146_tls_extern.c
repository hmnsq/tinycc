#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread দশমিক extern_tls_float = 1.5f;
#অন্যথা
বাহ্যিক __thread signed short extern_tls_short;
বাহ্যিক __thread দশমিক extern_tls_float;
পূর্ণসংখ্যা printf(ধ্রুবক অক্ষর *, ...);

পূর্ণসংখ্যা প্রধান(শূন্য)
{
    পূর্ণসংখ্যা errors = 0;

    যদি (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    যদি (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    ফেরত errors;
}
#endif
