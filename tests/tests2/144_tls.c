#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব "threads.h"

#যদি __SIZEOF_POINTER__ == 8
# define pFMT "0x%llx"
#অন্যথা
# define pFMT "0x%x"
#endif

#define	CHECK(var,fmt,val)	printf(fmt "\n",var); যদি (var != val) errors = 1

প্রকারলেখ গণনা { tls_a, tls_b, tls_c } tls_enum_type;
প্রকারলেখ কাঠামো { পূর্ণসংখ্যা tls_d, tls_e, tls_f; } tls_struct_type;

প্রকারলেখ কাঠামো {
    পূর্ণসংখ্যা *init;
    signed short *element;
} tls_address_type;

__thread অক্ষর tls_char = 42;
__thread short tls_short = 43;
__thread পূর্ণসংখ্যা tls_init = 44;
__thread long long tls_long_long = 45;
__thread পূর্ণসংখ্যা tls_zero;
__thread দশমিক tls_float = 46.0;
__thread দ্বিগুণ tls_double = 47.0;
__thread long দ্বিগুণ tls_long_double = 48.0;
__thread পূর্ণসংখ্যা *tls_ptr = (পূর্ণসংখ্যা *)49;
__thread tls_enum_type tls_enum = tls_b;
__thread tls_struct_type tls_struct = { 50, 51, 52 };
__thread signed অক্ষর tls_signed_char = -5;
__thread unsigned অক্ষর tls_unsigned_char = 250;
__thread signed short tls_signed_short = -1234;
__thread unsigned short tls_unsigned_short = 60000;
__thread signed short tls_array[4] = { -1000, 2000, -3000, 4000 };

#যদি defined __riscv && __riscv_xlen == 64
প্রকারলেখ কাঠামো {
    অক্ষর padding[4096];
    পূর্ণসংখ্যা মান;
} tls_large_type;

__thread tls_large_type tls_large = { { 0 }, 123456 };
#endif

স্থির পূর্ণসংখ্যা check_extra(পূর্ণসংখ্যা changed)
{
    অস্থির পূর্ণসংখ্যা সূচক = 2;

    যদি (changed)
        ফেরত tls_signed_char != -7 || tls_unsigned_char != 42
            || tls_signed_short != -2222 || tls_unsigned_short != 12345
            || tls_array[1] != 2222 || tls_array[সূচক] != -3333;

    যদি (tls_signed_char != -5 || tls_unsigned_char != 250
        || tls_signed_short != -1234 || tls_unsigned_short != 60000
        || tls_array[1] != 2000 || tls_array[সূচক] != -3000)
        ফেরত 1;

#যদি defined __riscv && __riscv_xlen == 64
    যদি (tls_large.মান != 123456)
        ফেরত 1;
#endif
    ফেরত 0;
}

স্থির পূর্ণসংখ্যা check(শূন্য)
{
    পূর্ণসংখ্যা errors = 0;

    CHECK(tls_char, "%d", 42);
    CHECK(tls_short, "%d", 43);
    CHECK(tls_init, "%d", 44);
    CHECK(tls_long_long, "%lld", 45);
    CHECK(tls_zero, "%d", 0);
    CHECK(tls_float, "%g", 46.0);
    CHECK(tls_double, "%g", 47.0);
    CHECK(tls_long_double, "%Lg", 48.0);
    CHECK(tls_ptr, pFMT, (পূর্ণসংখ্যা *)49);
    CHECK(tls_enum, "%d", tls_b);
    CHECK(tls_struct.tls_d, "%d", 50);
    CHECK(tls_struct.tls_e, "%d", 51);
    CHECK(tls_struct.tls_f, "%d", 52);
    ফেরত errors;
}

স্থির শূন্য *thread_func(শূন্য *arg)
{
    tls_address_type *main_addresses = arg;
    পূর্ণসংখ্যা *init_address = &tls_init;
    signed short *element_address = &tls_array[1];
    অস্থির পূর্ণসংখ্যা সূচক = 2;
    long errors = check();

    যদি (init_address == main_addresses->init
        || element_address == main_addresses->element
        || *init_address != 44 || *element_address != 2000
        || tls_array[সূচক] != -3000 || check_extra(0))
        errors = 1;

    tls_char = 10;
    tls_short = 20;
    tls_init = 30;
    tls_long_long = 40;
    tls_zero = 50;
    tls_float = 60.0;
    tls_double = 70.0;
    tls_long_double = 80.0;
    tls_ptr = (পূর্ণসংখ্যা *)90;
    tls_enum = tls_c;
    tls_struct.tls_d = 100;
    tls_struct.tls_e = 110;
    tls_struct.tls_f = 120;
    *element_address = 2222;
    tls_array[সূচক] = -3333;
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
    CHECK(tls_ptr, pFMT, (পূর্ণসংখ্যা *)90);
    CHECK(tls_struct.tls_d, "%d", 100);
    CHECK(tls_struct.tls_e, "%d", 110);
    CHECK(tls_struct.tls_f, "%d", 120);

    যদি (*init_address != 30 || *element_address != 2222
        || tls_array[সূচক] != -3333 || check_extra(1))
        errors = 1;

    ফেরত (শূন্য *)(আকার_t)errors;
}

পূর্ণসংখ্যা প্রধান()
{
    pthread_t t;
    শূন্য *ret;
    পূর্ণসংখ্যা errors = check();
    tls_address_type addresses = { &tls_init, &tls_array[1] };

    যদি (*addresses.init != 44 || *addresses.element != 2000
        || check_extra(0))
        errors = 1;

    pthread_create(&t, ফাঁকা, thread_func, &addresses);
    pthread_join(t, &ret);

    errors |= (ret ? 1 : 0) | check();
    যদি (*addresses.init != 44 || *addresses.element != 2000
        || check_extra(0))
        errors = 1;

    printf("errors: %d\n", errors);
    ফেরত errors;
}
