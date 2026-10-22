#جے_تعریف_شدہ DEFS
__thread نشانیوالا چھوٹا extern_tls_short = 1234;
__thread عائم extern_tls_float = 1.5f;
#وإلا
خارجي __thread نشانیوالا چھوٹا extern_tls_short;
خارجي __thread عائم extern_tls_float;
صحيح لکھو(ثابت حرف *, ...);

صحيح مکھ(فراغ)
{
    صحيح errors = 0;

    إذا (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    إذا (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    لکھو("extern tls errors: %d\n", errors);
    أرجع errors;
}
#جے_انت
