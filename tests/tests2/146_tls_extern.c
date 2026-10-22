#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread ভিন্ন extern_tls_float = 1.5f;
#অন্যথা
বাহ্য __thread signed short extern_tls_short;
বাহ্য __thread ভিন্ন extern_tls_float;
পূর্ণাঙ্ক printf(ধ্রুৱ ৱর্ণ *, ...);

পূর্ণাঙ্ক main(শূন্য)
{
    পূর্ণাঙ্ক errors = 0;

    যদি (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    যদি (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    ঘূৰাই errors;
}
#endif
