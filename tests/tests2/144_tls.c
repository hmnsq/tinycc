#ضمن <stdio.h>
#ضمن "threads.h"

#إذا __SIZEOF_POINTER__ == 8
# define pFMT "0x%llx"
#وإلا
# define pFMT "0x%x"
#جيڪڏهن_پورو

#وصف_ڪريو	CHECK(var,fmt,val)	لکو(fmt "\n",var); إذا (var != val) errors = 1

تعريفنوع تعداد { tls_a, tls_b, tls_c } tls_enum_type;
تعريفنوع بنية { صحيح tls_d, tls_e, tls_f; } tls_struct_type;

تعريفنوع بنية {
    صحيح *init;
    نشانوارو ننڍو *element;
} tls_پتو_type;

__thread حرف tls_char = 42;
__thread ننڍو tls_short = 43;
__thread صحيح tls_init = 44;
__thread ڊگهو ڊگهو tls_long_long = 45;
__thread صحيح tls_zero;
__thread عائم tls_float = 46.0;
__thread مزدوج tls_double = 47.0;
__thread ڊگهو مزدوج tls_long_double = 48.0;
__thread صحيح *tls_ptr = (صحيح *)49;
__thread tls_enum_type tls_enum = tls_b;
__thread tls_struct_type tls_struct = { 50, 51, 52 };
__thread نشانوارو حرف tls_signed_char = -5;
__thread بنانشان حرف tls_unsigned_char = 250;
__thread نشانوارو ننڍو tls_signed_short = -1234;
__thread بنانشان ننڍو tls_unsigned_short = 60000;
__thread نشانوارو ننڍو tls_array[4] = { -1000, 2000, -3000, 4000 };

#إذا defined __riscv && __riscv_xlen == 64
تعريفنوع بنية {
    حرف padding[4096];
    صحيح قدر;
} tls_large_type;

__thread tls_large_type tls_large = { { 0 }, 123456 };
#جيڪڏهن_پورو

ساكن صحيح check_extra(صحيح بدليو)
{
    متطاير صحيح اشاريو = 2;

    إذا (بدليو)
        أرجع tls_signed_char != -7 || tls_unsigned_char != 42
            || tls_signed_short != -2222 || tls_unsigned_short != 12345
            || tls_array[1] != 2222 || tls_array[اشاريو] != -3333;

    إذا (tls_signed_char != -5 || tls_unsigned_char != 250
        || tls_signed_short != -1234 || tls_unsigned_short != 60000
        || tls_array[1] != 2000 || tls_array[اشاريو] != -3000)
        أرجع 1;

#إذا defined __riscv && __riscv_xlen == 64
    إذا (tls_large.قدر != 123456)
        أرجع 1;
#جيڪڏهن_پورو
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
    tls_پتو_type *main_پتا = arg;
    صحيح *init_پتو = &tls_init;
    نشانوارو ننڍو *element_پتو = &tls_array[1];
    متطاير صحيح اشاريو = 2;
    ڊگهو errors = check();

    إذا (init_پتو == main_پتا->init
        || element_پتو == main_پتا->element
        || *init_پتو != 44 || *element_پتو != 2000
        || tls_array[اشاريو] != -3000 || check_extra(0))
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
    *element_پتو = 2222;
    tls_array[اشاريو] = -3333;
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

    إذا (*init_پتو != 30 || *element_پتو != 2222
        || tls_array[اشاريو] != -3333 || check_extra(1))
        errors = 1;

    أرجع (فراغ *)(سائيز_t)errors;
}

صحيح مکيه()
{
    pthread_t t;
    فراغ *ret;
    صحيح errors = check();
    tls_پتو_type پتا = { &tls_init, &tls_array[1] };

    إذا (*پتا.init != 44 || *پتا.element != 2000
        || check_extra(0))
        errors = 1;

    pthread_create(&t, عدم, thread_func, &پتا);
    pthread_join(t, &ret);

    errors |= (ret ? 1 : 0) | check();
    إذا (*پتا.init != 44 || *پتا.element != 2000
        || check_extra(0))
        errors = 1;

    لکو("errors: %d\n", errors);
    أرجع errors;
}
