#اگر_تعریف_شده DEFS
__thread علامتدار کوتاه extern_tls_short = 1234;
__thread عائم extern_tls_float = 1.5f;
#وإلا
خارجي __thread علامتدار کوتاه extern_tls_short;
خارجي __thread عائم extern_tls_float;
صحيح چاپ_کن(ثابت حرف *, ...);

صحيح اصلی(فراغ)
{
    صحيح errors = 0;

    إذا (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    إذا (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    چاپ_کن("extern tls errors: %d\n", errors);
    أرجع errors;
}
#پایان_اگر
