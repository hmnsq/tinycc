#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread float extern_tls_float = 1.5f;
#ບໍ່ດັ່ງນັ້ນ
extern __thread signed short extern_tls_short;
extern __thread float extern_tls_float;
ຈຳນວນເຕັມ printf(const var_na *, ...);

ຈຳນວນເຕັມ main(void)
{
    ຈຳນວນເຕັມ errors = 0;

    ຖ້າ (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    ຖ້າ (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    ສົ່ງຄືນ errors;
}
#endif
