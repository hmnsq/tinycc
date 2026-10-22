#అన్తర్భావ <stdio.h>
#అన్తర్భావ "threads.h"

#ఒకవేళ __SIZEOF_POINTER__ == 8
# define pFMT "0x%llx"
#లేకపోతే
# define pFMT "0x%x"
#అయితే_ముగింపు

#నిర్వచించు	CHECK(var,fmt,val)	రాయి(fmt "\n",var); ఒకవేళ (var != val) errors = 1

రకనిర్వచనం గణన { tls_a, tls_b, tls_c } tls_enum_type;
రకనిర్వచనం నిర్మాణం { పూర్ణాంకం tls_d, tls_e, tls_f; } tls_struct_type;

రకనిర్వచనం నిర్మాణం {
    పూర్ణాంకం *init;
    గుర్తుగల పొట్టి *element;
} tls_చిరునామా_type;

__thread అక్షరం tls_char = 42;
__thread పొట్టి tls_short = 43;
__thread పూర్ణాంకం tls_init = 44;
__thread దీర్ఘ దీర్ఘ tls_long_long = 45;
__thread పూర్ణాంకం tls_zero;
__thread దశాంశం tls_float = 46.0;
__thread ద్విగుణ tls_double = 47.0;
__thread దీర్ఘ ద్విగుణ tls_long_double = 48.0;
__thread పూర్ణాంకం *tls_ptr = (పూర్ణాంకం *)49;
__thread tls_enum_type tls_enum = tls_b;
__thread tls_struct_type tls_struct = { 50, 51, 52 };
__thread గుర్తుగల అక్షరం tls_signed_char = -5;
__thread గుర్తులేని అక్షరం tls_unsigned_char = 250;
__thread గుర్తుగల పొట్టి tls_signed_short = -1234;
__thread గుర్తులేని పొట్టి tls_unsigned_short = 60000;
__thread గుర్తుగల పొట్టి tls_array[4] = { -1000, 2000, -3000, 4000 };

#ఒకవేళ defined __riscv && __riscv_xlen == 64
రకనిర్వచనం నిర్మాణం {
    అక్షరం padding[4096];
    పూర్ణాంకం విలువ;
} tls_large_type;

__thread tls_large_type tls_large = { { 0 }, 123456 };
#అయితే_ముగింపు

స్థిర పూర్ణాంకం check_extra(పూర్ణాంకం మారింది)
{
    అస్థిర పూర్ణాంకం సూచీ = 2;

    ఒకవేళ (మారింది)
        తిరిగి tls_signed_char != -7 || tls_unsigned_char != 42
            || tls_signed_short != -2222 || tls_unsigned_short != 12345
            || tls_array[1] != 2222 || tls_array[సూచీ] != -3333;

    ఒకవేళ (tls_signed_char != -5 || tls_unsigned_char != 250
        || tls_signed_short != -1234 || tls_unsigned_short != 60000
        || tls_array[1] != 2000 || tls_array[సూచీ] != -3000)
        తిరిగి 1;

#ఒకవేళ defined __riscv && __riscv_xlen == 64
    ఒకవేళ (tls_large.విలువ != 123456)
        తిరిగి 1;
#అయితే_ముగింపు
    తిరిగి 0;
}

స్థిర పూర్ణాంకం check(శూన్య)
{
    పూర్ణాంకం errors = 0;

    CHECK(tls_char, "%d", 42);
    CHECK(tls_short, "%d", 43);
    CHECK(tls_init, "%d", 44);
    CHECK(tls_long_long, "%lld", 45);
    CHECK(tls_zero, "%d", 0);
    CHECK(tls_float, "%g", 46.0);
    CHECK(tls_double, "%g", 47.0);
    CHECK(tls_long_double, "%Lg", 48.0);
    CHECK(tls_ptr, pFMT, (పూర్ణాంకం *)49);
    CHECK(tls_enum, "%d", tls_b);
    CHECK(tls_struct.tls_d, "%d", 50);
    CHECK(tls_struct.tls_e, "%d", 51);
    CHECK(tls_struct.tls_f, "%d", 52);
    తిరిగి errors;
}

స్థిర శూన్య *thread_func(శూన్య *arg)
{
    tls_చిరునామా_type *main_చిరునామాలు = arg;
    పూర్ణాంకం *init_చిరునామా = &tls_init;
    గుర్తుగల పొట్టి *element_చిరునామా = &tls_array[1];
    అస్థిర పూర్ణాంకం సూచీ = 2;
    దీర్ఘ errors = check();

    ఒకవేళ (init_చిరునామా == main_చిరునామాలు->init
        || element_చిరునామా == main_చిరునామాలు->element
        || *init_చిరునామా != 44 || *element_చిరునామా != 2000
        || tls_array[సూచీ] != -3000 || check_extra(0))
        errors = 1;

    tls_char = 10;
    tls_short = 20;
    tls_init = 30;
    tls_long_long = 40;
    tls_zero = 50;
    tls_float = 60.0;
    tls_double = 70.0;
    tls_long_double = 80.0;
    tls_ptr = (పూర్ణాంకం *)90;
    tls_enum = tls_c;
    tls_struct.tls_d = 100;
    tls_struct.tls_e = 110;
    tls_struct.tls_f = 120;
    *element_చిరునామా = 2222;
    tls_array[సూచీ] = -3333;
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
    CHECK(tls_ptr, pFMT, (పూర్ణాంకం *)90);
    CHECK(tls_struct.tls_d, "%d", 100);
    CHECK(tls_struct.tls_e, "%d", 110);
    CHECK(tls_struct.tls_f, "%d", 120);

    ఒకవేళ (*init_చిరునామా != 30 || *element_చిరునామా != 2222
        || tls_array[సూచీ] != -3333 || check_extra(1))
        errors = 1;

    తిరిగి (శూన్య *)(కొలత_t)errors;
}

పూర్ణాంకం ప్రధాన()
{
    pthread_t t;
    శూన్య *ret;
    పూర్ణాంకం errors = check();
    tls_చిరునామా_type చిరునామాలు = { &tls_init, &tls_array[1] };

    ఒకవేళ (*చిరునామాలు.init != 44 || *చిరునామాలు.element != 2000
        || check_extra(0))
        errors = 1;

    pthread_create(&t, ఖాళీ, thread_func, &చిరునామాలు);
    pthread_join(t, &ret);

    errors |= (ret ? 1 : 0) | check();
    ఒకవేళ (*చిరునామాలు.init != 44 || *చిరునామాలు.element != 2000
        || check_extra(0))
        errors = 1;

    రాయి("errors: %d\n", errors);
    తిరిగి errors;
}
