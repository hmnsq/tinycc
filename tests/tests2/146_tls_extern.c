#جيڪڏهن_وصف_ٿيل DEFS
__thread نشانوارو ننڍو extern_tls_short = 1234;
__thread عائم extern_tls_float = 1.5f;
#وإلا
خارجي __thread نشانوارو ننڍو extern_tls_short;
خارجي __thread عائم extern_tls_float;
صحيح لکو(ثابت حرف *, ...);

صحيح مکيه(فراغ)
{
    صحيح errors = 0;

    إذا (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    إذا (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    لکو("extern tls errors: %d\n", errors);
    أرجع errors;
}
#جيڪڏهن_پورو
