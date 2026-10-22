#include <stdio.h>
#include "threads.h"

#නම් __SIZEOF_POINTER__ == 8
# define pFMT "0x%llx"
#නැතහොත්
# define pFMT "0x%x"
#endif

#define	CHECK(var,fmt,val)	printf(fmt "\n",var); නම් (var != val) errors = 1

typedef ga_nanaa { tls_a, tls_b, tls_c } tls_enum_type;
typedef sa_nracanaa { පූර්ණ_සංඛ්‍යා tls_d, tls_e, tls_f; } tls_struct_type;

typedef sa_nracanaa {
    පූර්ණ_සංඛ්‍යා *init;
    signed short *element;
} tls_address_type;

__thread var_na tls_char = 42;
__thread short tls_short = 43;
__thread පූර්ණ_සංඛ්‍යා tls_init = 44;
__thread long long tls_long_long = 45;
__thread පූර්ණ_සංඛ්‍යා tls_zero;
__thread float tls_float = 46.0;
__thread dviguu_na tls_double = 47.0;
__thread long dviguu_na tls_long_double = 48.0;
__thread පූර්ණ_සංඛ්‍යා *tls_ptr = (පූර්ණ_සංඛ්‍යා *)49;
__thread tls_enum_type tls_enum = tls_b;
__thread tls_struct_type tls_struct = { 50, 51, 52 };
__thread signed var_na tls_signed_char = -5;
__thread unsigned var_na tls_unsigned_char = 250;
__thread signed short tls_signed_short = -1234;
__thread unsigned short tls_unsigned_short = 60000;
__thread signed short tls_array[4] = { -1000, 2000, -3000, 4000 };

#නම් defined __riscv && __riscv_xlen == 64
typedef sa_nracanaa {
    var_na padding[4096];
    පූර්ණ_සංඛ්‍යා value;
} tls_large_type;

__thread tls_large_type tls_large = { { 0 }, 123456 };
#endif

static පූර්ණ_සංඛ්‍යා check_extra(පූර්ණ_සංඛ්‍යා changed)
{
    ca_ncala පූර්ණ_සංඛ්‍යා index = 2;

    නම් (changed)
        ආපසු tls_signed_char != -7 || tls_unsigned_char != 42
            || tls_signed_short != -2222 || tls_unsigned_short != 12345
            || tls_array[1] != 2222 || tls_array[index] != -3333;

    නම් (tls_signed_char != -5 || tls_unsigned_char != 250
        || tls_signed_short != -1234 || tls_unsigned_short != 60000
        || tls_array[1] != 2000 || tls_array[index] != -3000)
        ආපසු 1;

#නම් defined __riscv && __riscv_xlen == 64
    නම් (tls_large.value != 123456)
        ආපසු 1;
#endif
    ආපසු 0;
}

static පූර්ණ_සංඛ්‍යා check(void)
{
    පූර්ණ_සංඛ්‍යා errors = 0;

    CHECK(tls_char, "%d", 42);
    CHECK(tls_short, "%d", 43);
    CHECK(tls_init, "%d", 44);
    CHECK(tls_long_long, "%lld", 45);
    CHECK(tls_zero, "%d", 0);
    CHECK(tls_float, "%g", 46.0);
    CHECK(tls_double, "%g", 47.0);
    CHECK(tls_long_double, "%Lg", 48.0);
    CHECK(tls_ptr, pFMT, (පූර්ණ_සංඛ්‍යා *)49);
    CHECK(tls_enum, "%d", tls_b);
    CHECK(tls_struct.tls_d, "%d", 50);
    CHECK(tls_struct.tls_e, "%d", 51);
    CHECK(tls_struct.tls_f, "%d", 52);
    ආපසු errors;
}

static void *thread_func(void *arg)
{
    tls_address_type *main_addresses = arg;
    පූර්ණ_සංඛ්‍යා *init_address = &tls_init;
    signed short *element_address = &tls_array[1];
    ca_ncala පූර්ණ_සංඛ්‍යා index = 2;
    long errors = check();

    නම් (init_address == main_addresses->init
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
    tls_ptr = (පූර්ණ_සංඛ්‍යා *)90;
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
    CHECK(tls_ptr, pFMT, (පූර්ණ_සංඛ්‍යා *)90);
    CHECK(tls_struct.tls_d, "%d", 100);
    CHECK(tls_struct.tls_e, "%d", 110);
    CHECK(tls_struct.tls_f, "%d", 120);

    නම් (*init_address != 30 || *element_address != 2222
        || tls_array[index] != -3333 || check_extra(1))
        errors = 1;

    ආපසු (void *)(size_t)errors;
}

පූර්ණ_සංඛ්‍යා main()
{
    pthread_t t;
    void *ret;
    පූර්ණ_සංඛ්‍යා errors = check();
    tls_address_type addresses = { &tls_init, &tls_array[1] };

    නම් (*addresses.init != 44 || *addresses.element != 2000
        || check_extra(0))
        errors = 1;

    pthread_create(&t, NULL, thread_func, &addresses);
    pthread_join(t, &ret);

    errors |= (ret ? 1 : 0) | check();
    නම් (*addresses.init != 44 || *addresses.element != 2000
        || check_extra(0))
        errors = 1;

    printf("errors: %d\n", errors);
    ආපසු errors;
}
