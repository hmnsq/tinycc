#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ "threads.h"

#ਜੇ __SIZEOF_POINTER__ == 8
# define pFMT "0x%llx"
#ਨਹੀਂਤਾਂ
# define pFMT "0x%x"
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	CHECK(var,fmt,val)	ਲਿਖੋ(fmt "\n",var); ਜੇ (var != val) errors = 1

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ { tls_a, tls_b, tls_c } tls_enum_type;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { ਪੂਰਨ tls_d, tls_e, tls_f; } tls_struct_type;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    ਪੂਰਨ *init;
    ਨਿਸ਼ਾਨੀਵਾਲਾ ਛੋਟਾ *element;
} tls_ਪਤਾ_type;

__thread ਅੱਖਰ tls_char = 42;
__thread ਛੋਟਾ tls_short = 43;
__thread ਪੂਰਨ tls_init = 44;
__thread ਲੰਮਾ ਲੰਮਾ tls_long_long = 45;
__thread ਪੂਰਨ tls_zero;
__thread ਦਸ਼ਮਲਵ tls_float = 46.0;
__thread ਦੁੱਗਣਾ tls_double = 47.0;
__thread ਲੰਮਾ ਦੁੱਗਣਾ tls_long_double = 48.0;
__thread ਪੂਰਨ *tls_ptr = (ਪੂਰਨ *)49;
__thread tls_enum_type tls_enum = tls_b;
__thread tls_struct_type tls_struct = { 50, 51, 52 };
__thread ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ tls_signed_char = -5;
__thread ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ tls_unsigned_char = 250;
__thread ਨਿਸ਼ਾਨੀਵਾਲਾ ਛੋਟਾ tls_signed_short = -1234;
__thread ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ tls_unsigned_short = 60000;
__thread ਨਿਸ਼ਾਨੀਵਾਲਾ ਛੋਟਾ tls_array[4] = { -1000, 2000, -3000, 4000 };

#ਜੇ defined __riscv && __riscv_xlen == 64
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    ਅੱਖਰ padding[4096];
    ਪੂਰਨ ਮੁੱਲ;
} tls_large_type;

__thread tls_large_type tls_large = { { 0 }, 123456 };
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਪੂਰਨ check_extra(ਪੂਰਨ ਬਦਲਿਆ)
{
    ਅਸਥਿਰ ਪੂਰਨ ਸੂਚਕਾਂਕ = 2;

    ਜੇ (ਬਦਲਿਆ)
        ਵਾਪਸ tls_signed_char != -7 || tls_unsigned_char != 42
            || tls_signed_short != -2222 || tls_unsigned_short != 12345
            || tls_array[1] != 2222 || tls_array[ਸੂਚਕਾਂਕ] != -3333;

    ਜੇ (tls_signed_char != -5 || tls_unsigned_char != 250
        || tls_signed_short != -1234 || tls_unsigned_short != 60000
        || tls_array[1] != 2000 || tls_array[ਸੂਚਕਾਂਕ] != -3000)
        ਵਾਪਸ 1;

#ਜੇ defined __riscv && __riscv_xlen == 64
    ਜੇ (tls_large.ਮੁੱਲ != 123456)
        ਵਾਪਸ 1;
#ਜੇ_ਅੰਤ
    ਵਾਪਸ 0;
}

ਸਥਿਰ ਪੂਰਨ check(ਖਾਲੀ)
{
    ਪੂਰਨ errors = 0;

    CHECK(tls_char, "%d", 42);
    CHECK(tls_short, "%d", 43);
    CHECK(tls_init, "%d", 44);
    CHECK(tls_long_long, "%lld", 45);
    CHECK(tls_zero, "%d", 0);
    CHECK(tls_float, "%g", 46.0);
    CHECK(tls_double, "%g", 47.0);
    CHECK(tls_long_double, "%Lg", 48.0);
    CHECK(tls_ptr, pFMT, (ਪੂਰਨ *)49);
    CHECK(tls_enum, "%d", tls_b);
    CHECK(tls_struct.tls_d, "%d", 50);
    CHECK(tls_struct.tls_e, "%d", 51);
    CHECK(tls_struct.tls_f, "%d", 52);
    ਵਾਪਸ errors;
}

ਸਥਿਰ ਖਾਲੀ *thread_func(ਖਾਲੀ *arg)
{
    tls_ਪਤਾ_type *main_ਪਤੇ = arg;
    ਪੂਰਨ *init_ਪਤਾ = &tls_init;
    ਨਿਸ਼ਾਨੀਵਾਲਾ ਛੋਟਾ *element_ਪਤਾ = &tls_array[1];
    ਅਸਥਿਰ ਪੂਰਨ ਸੂਚਕਾਂਕ = 2;
    ਲੰਮਾ errors = check();

    ਜੇ (init_ਪਤਾ == main_ਪਤੇ->init
        || element_ਪਤਾ == main_ਪਤੇ->element
        || *init_ਪਤਾ != 44 || *element_ਪਤਾ != 2000
        || tls_array[ਸੂਚਕਾਂਕ] != -3000 || check_extra(0))
        errors = 1;

    tls_char = 10;
    tls_short = 20;
    tls_init = 30;
    tls_long_long = 40;
    tls_zero = 50;
    tls_float = 60.0;
    tls_double = 70.0;
    tls_long_double = 80.0;
    tls_ptr = (ਪੂਰਨ *)90;
    tls_enum = tls_c;
    tls_struct.tls_d = 100;
    tls_struct.tls_e = 110;
    tls_struct.tls_f = 120;
    *element_ਪਤਾ = 2222;
    tls_array[ਸੂਚਕਾਂਕ] = -3333;
    tls_signed_char = -7;
    tls_unsigned_char = 42;
    tls_signed_short = -2222;
    tls_unsigned_short = 12345;

    CHECK(tls_char, "%d", 10);
    CHECK(tls_short, "%d", 20);
    CHECK(tls_init, "%d", 30);
    CHECK(tls_long_long, "%lld", 40);
    CHECK(tls_zero, "%d", 50);
    CHECK(tls_float, "%g", 60.0);
    CHECK(tls_double, "%g", 70.0);
    CHECK(tls_long_double, "%Lg", 80.0);
    CHECK(tls_enum, "%d", tls_c);
    CHECK(tls_ptr, pFMT, (ਪੂਰਨ *)90);
    CHECK(tls_struct.tls_d, "%d", 100);
    CHECK(tls_struct.tls_e, "%d", 110);
    CHECK(tls_struct.tls_f, "%d", 120);

    ਜੇ (*init_ਪਤਾ != 30 || *element_ਪਤਾ != 2222
        || tls_array[ਸੂਚਕਾਂਕ] != -3333 || check_extra(1))
        errors = 1;

    ਵਾਪਸ (ਖਾਲੀ *)(ਮਾਪ_t)errors;
}

ਪੂਰਨ ਮੁੱਖ()
{
    pthread_t t;
    ਖਾਲੀ *ret;
    ਪੂਰਨ errors = check();
    tls_ਪਤਾ_type ਪਤੇ = { &tls_init, &tls_array[1] };

    ਜੇ (*ਪਤੇ.init != 44 || *ਪਤੇ.element != 2000
        || check_extra(0))
        errors = 1;

    pthread_create(&t, ਨਿਰਾ, thread_func, &ਪਤੇ);
    pthread_join(t, &ret);

    errors |= (ret ? 1 : 0) | check();
    ਜੇ (*ਪਤੇ.init != 44 || *ਪਤੇ.element != 2000
        || check_extra(0))
        errors = 1;

    ਲਿਖੋ("errors: %d\n", errors);
    ਵਾਪਸ errors;
}
