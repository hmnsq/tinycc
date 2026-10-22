#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ "threads.h"

#ಯದಿ __SIZEOF_POINTER__ == 8
# define pFMT "0x%llx"
#ಅನ್ಯಥಾ
# define pFMT "0x%x"
#endif

#define	CHECK(var,fmt,val)	printf(fmt "\n",var); ಯದಿ (var != val) errors = 1

ಪ್ರಕಾರನಿರ್ದೇಶ ಗಣನಾ { tls_a, tls_b, tls_c } tls_enum_type;
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ tls_d, tls_e, tls_f; } tls_struct_type;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
    ಪೂರ್ಣಾಙ್ಕ *init;
    signed short *element;
} tls_address_type;

__thread ವರ್ಣ tls_char = 42;
__thread short tls_short = 43;
__thread ಪೂರ್ಣಾಙ್ಕ tls_init = 44;
__thread long long tls_long_long = 45;
__thread ಪೂರ್ಣಾಙ್ಕ tls_zero;
__thread ಭಿನ್ನ tls_float = 46.0;
__thread ದ್ವಿಗುಣ tls_double = 47.0;
__thread long ದ್ವಿಗುಣ tls_long_double = 48.0;
__thread ಪೂರ್ಣಾಙ್ಕ *tls_ptr = (ಪೂರ್ಣಾಙ್ಕ *)49;
__thread tls_enum_type tls_enum = tls_b;
__thread tls_struct_type tls_struct = { 50, 51, 52 };
__thread signed ವರ್ಣ tls_signed_char = -5;
__thread unsigned ವರ್ಣ tls_unsigned_char = 250;
__thread signed short tls_signed_short = -1234;
__thread unsigned short tls_unsigned_short = 60000;
__thread signed short tls_array[4] = { -1000, 2000, -3000, 4000 };

#ಯದಿ defined __riscv && __riscv_xlen == 64
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
    ವರ್ಣ padding[4096];
    ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ;
} tls_large_type;

__thread tls_large_type tls_large = { { 0 }, 123456 };
#endif

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ check_extra(ಪೂರ್ಣಾಙ್ಕ changed)
{
    ಚಞ್ಚಲ ಪೂರ್ಣಾಙ್ಕ index = 2;

    ಯದಿ (changed)
        ಪ್ರತ್ಯಾಗಮ tls_signed_char != -7 || tls_unsigned_char != 42
            || tls_signed_short != -2222 || tls_unsigned_short != 12345
            || tls_array[1] != 2222 || tls_array[index] != -3333;

    ಯದಿ (tls_signed_char != -5 || tls_unsigned_char != 250
        || tls_signed_short != -1234 || tls_unsigned_short != 60000
        || tls_array[1] != 2000 || tls_array[index] != -3000)
        ಪ್ರತ್ಯಾಗಮ 1;

#ಯದಿ defined __riscv && __riscv_xlen == 64
    ಯದಿ (tls_large.ಮೌಲ್ಯ != 123456)
        ಪ್ರತ್ಯಾಗಮ 1;
#endif
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ check(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ errors = 0;

    CHECK(tls_char, "%d", 42);
    CHECK(tls_short, "%d", 43);
    CHECK(tls_init, "%d", 44);
    CHECK(tls_long_long, "%lld", 45);
    CHECK(tls_zero, "%d", 0);
    CHECK(tls_float, "%g", 46.0);
    CHECK(tls_double, "%g", 47.0);
    CHECK(tls_long_double, "%Lg", 48.0);
    CHECK(tls_ptr, pFMT, (ಪೂರ್ಣಾಙ್ಕ *)49);
    CHECK(tls_enum, "%d", tls_b);
    CHECK(tls_struct.tls_d, "%d", 50);
    CHECK(tls_struct.tls_e, "%d", 51);
    CHECK(tls_struct.tls_f, "%d", 52);
    ಪ್ರತ್ಯಾಗಮ errors;
}

ಸ್ಥಿರ ಶೂನ್ಯ *thread_func(ಶೂನ್ಯ *arg)
{
    tls_address_type *main_addresses = arg;
    ಪೂರ್ಣಾಙ್ಕ *init_address = &tls_init;
    signed short *element_address = &tls_array[1];
    ಚಞ್ಚಲ ಪೂರ್ಣಾಙ್ಕ index = 2;
    long errors = check();

    ಯದಿ (init_address == main_addresses->init
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
    tls_ptr = (ಪೂರ್ಣಾಙ್ಕ *)90;
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
    CHECK(tls_ptr, pFMT, (ಪೂರ್ಣಾಙ್ಕ *)90);
    CHECK(tls_struct.tls_d, "%d", 100);
    CHECK(tls_struct.tls_e, "%d", 110);
    CHECK(tls_struct.tls_f, "%d", 120);

    ಯದಿ (*init_address != 30 || *element_address != 2222
        || tls_array[index] != -3333 || check_extra(1))
        errors = 1;

    ಪ್ರತ್ಯಾಗಮ (ಶೂನ್ಯ *)(size_t)errors;
}

ಪೂರ್ಣಾಙ್ಕ main()
{
    pthread_t t;
    ಶೂನ್ಯ *ret;
    ಪೂರ್ಣಾಙ್ಕ errors = check();
    tls_address_type addresses = { &tls_init, &tls_array[1] };

    ಯದಿ (*addresses.init != 44 || *addresses.element != 2000
        || check_extra(0))
        errors = 1;

    pthread_create(&t, ರಿಕ್ತ, thread_func, &addresses);
    pthread_join(t, &ret);

    errors |= (ret ? 1 : 0) | check();
    ಯದಿ (*addresses.init != 44 || *addresses.element != 2000
        || check_extra(0))
        errors = 1;

    printf("errors: %d\n", errors);
    ಪ್ರತ್ಯಾಗಮ errors;
}
