#شامل <stdio.h>
#شامل "threads.h"

#اگر __SIZEOF_POINTER__ == 8
# define pFMT "0x%llx"
#ورنہ
# define pFMT "0x%x"
#اگر_ختم

#تعریف_کرو	CHECK(var,fmt,val)	لکھو(fmt "\n",var); اگر (var != val) errors = 1

قسمتعریف شمار { tls_a, tls_b, tls_c } tls_enum_type;
قسمتعریف ساخت { صحیح tls_d, tls_e, tls_f; } tls_struct_type;

قسمتعریف ساخت {
    صحیح *init;
    علامتی مختصر *element;
} tls_پتہ_type;

__thread حرف tls_char = 42;
__thread مختصر tls_short = 43;
__thread صحیح tls_init = 44;
__thread طویل طویل tls_long_long = 45;
__thread صحیح tls_zero;
__thread اعشاری tls_float = 46.0;
__thread دوہرا tls_double = 47.0;
__thread طویل دوہرا tls_long_double = 48.0;
__thread صحیح *tls_ptr = (صحیح *)49;
__thread tls_enum_type tls_enum = tls_b;
__thread tls_struct_type tls_struct = { 50, 51, 52 };
__thread علامتی حرف tls_signed_char = -5;
__thread غیرعلامتی حرف tls_unsigned_char = 250;
__thread علامتی مختصر tls_signed_short = -1234;
__thread غیرعلامتی مختصر tls_unsigned_short = 60000;
__thread علامتی مختصر tls_array[4] = { -1000, 2000, -3000, 4000 };

#اگر defined __riscv && __riscv_xlen == 64
قسمتعریف ساخت {
    حرف padding[4096];
    صحیح قدر;
} tls_large_type;

__thread tls_large_type tls_large = { { 0 }, 123456 };
#اگر_ختم

ساکن صحیح check_extra(صحیح بدلا)
{
    متلون صحیح اشاریہ = 2;

    اگر (بدلا)
        واپس tls_signed_char != -7 || tls_unsigned_char != 42
            || tls_signed_short != -2222 || tls_unsigned_short != 12345
            || tls_array[1] != 2222 || tls_array[اشاریہ] != -3333;

    اگر (tls_signed_char != -5 || tls_unsigned_char != 250
        || tls_signed_short != -1234 || tls_unsigned_short != 60000
        || tls_array[1] != 2000 || tls_array[اشاریہ] != -3000)
        واپس 1;

#اگر defined __riscv && __riscv_xlen == 64
    اگر (tls_large.قدر != 123456)
        واپس 1;
#اگر_ختم
    واپس 0;
}

ساکن صحیح check(خالی)
{
    صحیح errors = 0;

    CHECK(tls_char, "%d", 42);
    CHECK(tls_short, "%d", 43);
    CHECK(tls_init, "%d", 44);
    CHECK(tls_long_long, "%lld", 45);
    CHECK(tls_zero, "%d", 0);
    CHECK(tls_float, "%g", 46.0);
    CHECK(tls_double, "%g", 47.0);
    CHECK(tls_long_double, "%Lg", 48.0);
    CHECK(tls_ptr, pFMT, (صحیح *)49);
    CHECK(tls_enum, "%d", tls_b);
    CHECK(tls_struct.tls_d, "%d", 50);
    CHECK(tls_struct.tls_e, "%d", 51);
    CHECK(tls_struct.tls_f, "%d", 52);
    واپس errors;
}

ساکن خالی *thread_func(خالی *arg)
{
    tls_پتہ_type *main_پتے = arg;
    صحیح *init_پتہ = &tls_init;
    علامتی مختصر *element_پتہ = &tls_array[1];
    متلون صحیح اشاریہ = 2;
    طویل errors = check();

    اگر (init_پتہ == main_پتے->init
        || element_پتہ == main_پتے->element
        || *init_پتہ != 44 || *element_پتہ != 2000
        || tls_array[اشاریہ] != -3000 || check_extra(0))
        errors = 1;

    tls_char = 10;
    tls_short = 20;
    tls_init = 30;
    tls_long_long = 40;
    tls_zero = 50;
    tls_float = 60.0;
    tls_double = 70.0;
    tls_long_double = 80.0;
    tls_ptr = (صحیح *)90;
    tls_enum = tls_c;
    tls_struct.tls_d = 100;
    tls_struct.tls_e = 110;
    tls_struct.tls_f = 120;
    *element_پتہ = 2222;
    tls_array[اشاریہ] = -3333;
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
    CHECK(tls_ptr, pFMT, (صحیح *)90);
    CHECK(tls_struct.tls_d, "%d", 100);
    CHECK(tls_struct.tls_e, "%d", 110);
    CHECK(tls_struct.tls_f, "%d", 120);

    اگر (*init_پتہ != 30 || *element_پتہ != 2222
        || tls_array[اشاریہ] != -3333 || check_extra(1))
        errors = 1;

    واپس (خالی *)(سائز_t)errors;
}

صحیح مین()
{
    pthread_t t;
    خالی *ret;
    صحیح errors = check();
    tls_پتہ_type پتے = { &tls_init, &tls_array[1] };

    اگر (*پتے.init != 44 || *پتے.element != 2000
        || check_extra(0))
        errors = 1;

    pthread_create(&t, تہی, thread_func, &پتے);
    pthread_join(t, &ret);

    errors |= (ret ? 1 : 0) | check();
    اگر (*پتے.init != 44 || *پتے.element != 2000
        || check_extra(0))
        errors = 1;

    لکھو("errors: %d\n", errors);
    واپس errors;
}
