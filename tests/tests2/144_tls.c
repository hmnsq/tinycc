#ضمن <stdio.h>
#ضمن "threads.h"

#إذا __SIZEOF_POINTER__ == 8
# define pFMT "0x%llx"
#وإلا
# define pFMT "0x%x"
#د_که_پای

#تعریف_کړه	CHECK(var,fmt,val)	چاپ_کړه(fmt "\n",var); إذا (var != val) errors = 1

تعريفنوع تعداد { tls_a, tls_b, tls_c } tls_enum_type;
تعريفنوع بنية { صحيح tls_d, tls_e, tls_f; } tls_struct_type;

تعريفنوع بنية {
    صحيح *init;
    نښهدار لنډ *element;
} tls_پته_type;

__thread حرف tls_char = 42;
__thread لنډ tls_short = 43;
__thread صحيح tls_init = 44;
__thread اوږد اوږد tls_long_long = 45;
__thread صحيح tls_zero;
__thread عائم tls_float = 46.0;
__thread مزدوج tls_double = 47.0;
__thread اوږد مزدوج tls_long_double = 48.0;
__thread صحيح *tls_ptr = (صحيح *)49;
__thread tls_enum_type tls_enum = tls_b;
__thread tls_struct_type tls_struct = { 50, 51, 52 };
__thread نښهدار حرف tls_signed_char = -5;
__thread بینښه حرف tls_unsigned_char = 250;
__thread نښهدار لنډ tls_signed_short = -1234;
__thread بینښه لنډ tls_unsigned_short = 60000;
__thread نښهدار لنډ tls_array[4] = { -1000, 2000, -3000, 4000 };

#إذا defined __riscv && __riscv_xlen == 64
تعريفنوع بنية {
    حرف padding[4096];
    صحيح ارزښت;
} tls_large_type;

__thread tls_large_type tls_large = { { 0 }, 123456 };
#د_که_پای

ساكن صحيح check_extra(صحيح بدل_شوی)
{
    متطاير صحيح شاخص = 2;

    إذا (بدل_شوی)
        أرجع tls_signed_char != -7 || tls_unsigned_char != 42
            || tls_signed_short != -2222 || tls_unsigned_short != 12345
            || tls_array[1] != 2222 || tls_array[شاخص] != -3333;

    إذا (tls_signed_char != -5 || tls_unsigned_char != 250
        || tls_signed_short != -1234 || tls_unsigned_short != 60000
        || tls_array[1] != 2000 || tls_array[شاخص] != -3000)
        أرجع 1;

#إذا defined __riscv && __riscv_xlen == 64
    إذا (tls_large.ارزښت != 123456)
        أرجع 1;
#د_که_پای
    أرجع 0;
}

ساكن صحيح check(فراغ)
{
    صحيح errors = 0;

    CHECK(tls_char, "%d", 42);
    CHECK(tls_short, "%d", 43);
    CHECK(tls_init, "%d", 44);
    CHECK(tls_long_long, "%lld", 45);
    CHECK(tls_zero, "%d", 0);
    CHECK(tls_float, "%g", 46.0);
    CHECK(tls_double, "%g", 47.0);
    CHECK(tls_long_double, "%Lg", 48.0);
    CHECK(tls_ptr, pFMT, (صحيح *)49);
    CHECK(tls_enum, "%d", tls_b);
    CHECK(tls_struct.tls_d, "%d", 50);
    CHECK(tls_struct.tls_e, "%d", 51);
    CHECK(tls_struct.tls_f, "%d", 52);
    أرجع errors;
}

ساكن فراغ *thread_func(فراغ *arg)
{
    tls_پته_type *main_پتې = arg;
    صحيح *init_پته = &tls_init;
    نښهدار لنډ *element_پته = &tls_array[1];
    متطاير صحيح شاخص = 2;
    اوږد errors = check();

    إذا (init_پته == main_پتې->init
        || element_پته == main_پتې->element
        || *init_پته != 44 || *element_پته != 2000
        || tls_array[شاخص] != -3000 || check_extra(0))
        errors = 1;

    tls_char = 10;
    tls_short = 20;
    tls_init = 30;
    tls_long_long = 40;
    tls_zero = 50;
    tls_float = 60.0;
    tls_double = 70.0;
    tls_long_double = 80.0;
    tls_ptr = (صحيح *)90;
    tls_enum = tls_c;
    tls_struct.tls_d = 100;
    tls_struct.tls_e = 110;
    tls_struct.tls_f = 120;
    *element_پته = 2222;
    tls_array[شاخص] = -3333;
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
    CHECK(tls_ptr, pFMT, (صحيح *)90);
    CHECK(tls_struct.tls_d, "%d", 100);
    CHECK(tls_struct.tls_e, "%d", 110);
    CHECK(tls_struct.tls_f, "%d", 120);

    إذا (*init_پته != 30 || *element_پته != 2222
        || tls_array[شاخص] != -3333 || check_extra(1))
        errors = 1;

    أرجع (فراغ *)(اندازه_t)errors;
}

صحيح اصلي()
{
    pthread_t t;
    فراغ *ret;
    صحيح errors = check();
    tls_پته_type پتې = { &tls_init, &tls_array[1] };

    إذا (*پتې.init != 44 || *پتې.element != 2000
        || check_extra(0))
        errors = 1;

    pthread_create(&t, عدم, thread_func, &پتې);
    pthread_join(t, &ret);

    errors |= (ret ? 1 : 0) | check();
    إذا (*پتې.init != 44 || *پتې.element != 2000
        || check_extra(0))
        errors = 1;

    چاپ_کړه("errors: %d\n", errors);
    أرجع errors;
}
