#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ "threads.h"

#ଯଦି __SIZEOF_POINTER__ == 8
# define pFMT "0x%llx"
#ଅନ୍ୟଥା
# define pFMT "0x%x"
#endif

#define	CHECK(var,fmt,val)	printf(fmt "\n",var); ଯଦି (var != val) errors = 1

ପ୍ରକାରବ୍ୟାଖ୍ୟା ଗଣନା { tls_a, tls_b, tls_c } tls_enum_type;
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { ପୂର୍ଣ୍ଣସଂଖ୍ୟା tls_d, tls_e, tls_f; } tls_struct_type;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *init;
    signed short *element;
} tls_address_type;

__thread ଅକ୍ଷର tls_char = 42;
__thread short tls_short = 43;
__thread ପୂର୍ଣ୍ଣସଂଖ୍ୟା tls_init = 44;
__thread long long tls_long_long = 45;
__thread ପୂର୍ଣ୍ଣସଂଖ୍ୟା tls_zero;
__thread ଦଶମିକ tls_float = 46.0;
__thread ଦ୍ୱିଗୁଣ tls_double = 47.0;
__thread long ଦ୍ୱିଗୁଣ tls_long_double = 48.0;
__thread ପୂର୍ଣ୍ଣସଂଖ୍ୟା *tls_ptr = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା *)49;
__thread tls_enum_type tls_enum = tls_b;
__thread tls_struct_type tls_struct = { 50, 51, 52 };
__thread signed ଅକ୍ଷର tls_signed_char = -5;
__thread unsigned ଅକ୍ଷର tls_unsigned_char = 250;
__thread signed short tls_signed_short = -1234;
__thread unsigned short tls_unsigned_short = 60000;
__thread signed short tls_array[4] = { -1000, 2000, -3000, 4000 };

#ଯଦି defined __riscv && __riscv_xlen == 64
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
    ଅକ୍ଷର padding[4096];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ;
} tls_large_type;

__thread tls_large_type tls_large = { { 0 }, 123456 };
#endif

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା check_extra(ପୂର୍ଣ୍ଣସଂଖ୍ୟା changed)
{
    ଅସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା index = 2;

    ଯଦି (changed)
        ଫେରନ୍ତୁ tls_signed_char != -7 || tls_unsigned_char != 42
            || tls_signed_short != -2222 || tls_unsigned_short != 12345
            || tls_array[1] != 2222 || tls_array[index] != -3333;

    ଯଦି (tls_signed_char != -5 || tls_unsigned_char != 250
        || tls_signed_short != -1234 || tls_unsigned_short != 60000
        || tls_array[1] != 2000 || tls_array[index] != -3000)
        ଫେରନ୍ତୁ 1;

#ଯଦି defined __riscv && __riscv_xlen == 64
    ଯଦି (tls_large.ମୂଲ୍ୟ != 123456)
        ଫେରନ୍ତୁ 1;
#endif
    ଫେରନ୍ତୁ 0;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା check(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା errors = 0;

    CHECK(tls_char, "%d", 42);
    CHECK(tls_short, "%d", 43);
    CHECK(tls_init, "%d", 44);
    CHECK(tls_long_long, "%lld", 45);
    CHECK(tls_zero, "%d", 0);
    CHECK(tls_float, "%g", 46.0);
    CHECK(tls_double, "%g", 47.0);
    CHECK(tls_long_double, "%Lg", 48.0);
    CHECK(tls_ptr, pFMT, (ପୂର୍ଣ୍ଣସଂଖ୍ୟା *)49);
    CHECK(tls_enum, "%d", tls_b);
    CHECK(tls_struct.tls_d, "%d", 50);
    CHECK(tls_struct.tls_e, "%d", 51);
    CHECK(tls_struct.tls_f, "%d", 52);
    ଫେରନ୍ତୁ errors;
}

ସ୍ଥିର ଶୂନ୍ୟ *thread_func(ଶୂନ୍ୟ *arg)
{
    tls_address_type *main_addresses = arg;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *init_address = &tls_init;
    signed short *element_address = &tls_array[1];
    ଅସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା index = 2;
    long errors = check();

    ଯଦି (init_address == main_addresses->init
        || element_address == main_addresses->element
        || *init_address != 44 || *element_address != 2000
        || tls_array[index] != -3000 || check_extra(0))
        errors = 1;

    tls_char = 10;
    tls_short = 20;
    tls_init = 30;
    tls_long_long = 40;
    tls_zero = 50;
    tls_float = 60.0;
    tls_double = 70.0;
    tls_long_double = 80.0;
    tls_ptr = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା *)90;
    tls_enum = tls_c;
    tls_struct.tls_d = 100;
    tls_struct.tls_e = 110;
    tls_struct.tls_f = 120;
    *element_address = 2222;
    tls_array[index] = -3333;
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
    CHECK(tls_ptr, pFMT, (ପୂର୍ଣ୍ଣସଂଖ୍ୟା *)90);
    CHECK(tls_struct.tls_d, "%d", 100);
    CHECK(tls_struct.tls_e, "%d", 110);
    CHECK(tls_struct.tls_f, "%d", 120);

    ଯଦି (*init_address != 30 || *element_address != 2222
        || tls_array[index] != -3333 || check_extra(1))
        errors = 1;

    ଫେରନ୍ତୁ (ଶୂନ୍ୟ *)(size_t)errors;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    pthread_t t;
    ଶୂନ୍ୟ *ret;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା errors = check();
    tls_address_type addresses = { &tls_init, &tls_array[1] };

    ଯଦି (*addresses.init != 44 || *addresses.element != 2000
        || check_extra(0))
        errors = 1;

    pthread_create(&t, ଖାଲି, thread_func, &addresses);
    pthread_join(t, &ret);

    errors |= (ret ? 1 : 0) | check();
    ଯଦି (*addresses.init != 44 || *addresses.element != 2000
        || check_extra(0))
        errors = 1;

    printf("errors: %d\n", errors);
    ଫେରନ୍ତୁ errors;
}
