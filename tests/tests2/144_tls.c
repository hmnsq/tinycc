#ضمن <stdio.h>
#ضمن "threads.h"

#إذا __SIZEOF_POINTER__ == 8
# define pFMT "0x%llx"
#وإلا
# define pFMT "0x%x"
#جے_انت

#تعریف_کرو	CHECK(var,fmt,val)	لکھو(fmt "\n",var); إذا (var != val) errors = 1

تعريفنوع تعداد { tls_a, tls_b, tls_c } tls_enum_type;
تعريفنوع بنية { صحيح tls_d, tls_e, tls_f; } tls_struct_type;

تعريفنوع بنية {
    صحيح *init;
    نشانیوالا چھوٹا *element;
} tls_پتہ_type;

__thread حرف tls_char = 42;
__thread چھوٹا tls_short = 43;
__thread صحيح tls_init = 44;
__thread لما لما tls_long_long = 45;
__thread صحيح tls_zero;
__thread عائم tls_float = 46.0;
__thread مزدوج tls_double = 47.0;
__thread لما مزدوج tls_long_double = 48.0;
__thread صحيح *tls_ptr = (صحيح *)49;
__thread tls_enum_type tls_enum = tls_b;
__thread tls_struct_type tls_struct = { 50, 51, 52 };
__thread نشانیوالا حرف tls_signed_char = -5;
__thread بنانشانی حرف tls_unsigned_char = 250;
__thread نشانیوالا چھوٹا tls_signed_short = -1234;
__thread بنانشانی چھوٹا tls_unsigned_short = 60000;
__thread نشانیوالا چھوٹا tls_array[4] = { -1000, 2000, -3000, 4000 };

#إذا defined __riscv && __riscv_xlen == 64
تعريفنوع بنية {
    حرف padding[4096];
    صحيح قدر;
} tls_large_type;

__thread tls_large_type tls_large = { { 0 }, 123456 };
#جے_انت

ساكن صحيح check_extra(صحيح بدلیا)
{
    متطاير صحيح اشاریہ = 2;

    إذا (بدلیا)
        أرجع tls_signed_char != -7 || tls_unsigned_char != 42
            || tls_signed_short != -2222 || tls_unsigned_short != 12345
            || tls_array[1] != 2222 || tls_array[اشاریہ] != -3333;

    إذا (tls_signed_char != -5 || tls_unsigned_char != 250
        || tls_signed_short != -1234 || tls_unsigned_short != 60000
        || tls_array[1] != 2000 || tls_array[اشاریہ] != -3000)
        أرجع 1;

#إذا defined __riscv && __riscv_xlen == 64
    إذا (tls_large.قدر != 123456)
        أرجع 1;
#جے_انت
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
    tls_پتہ_type *main_پتے = arg;
    صحيح *init_پتہ = &tls_init;
    نشانیوالا چھوٹا *element_پتہ = &tls_array[1];
    متطاير صحيح اشاریہ = 2;
    لما errors = check();

    إذا (init_پتہ == main_پتے->init
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
    tls_ptr = (صحيح *)90;
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
    CHECK(tls_ptr, pFMT, (صحيح *)90);
    CHECK(tls_struct.tls_d, "%d", 100);
    CHECK(tls_struct.tls_e, "%d", 110);
    CHECK(tls_struct.tls_f, "%d", 120);

    إذا (*init_پتہ != 30 || *element_پتہ != 2222
        || tls_array[اشاریہ] != -3333 || check_extra(1))
        errors = 1;

    أرجع (فراغ *)(ناپ_t)errors;
}

صحيح مکھ()
{
    pthread_t t;
    فراغ *ret;
    صحيح errors = check();
    tls_پتہ_type پتے = { &tls_init, &tls_array[1] };

    إذا (*پتے.init != 44 || *پتے.element != 2000
        || check_extra(0))
        errors = 1;

    pthread_create(&t, عدم, thread_func, &پتے);
    pthread_join(t, &ret);

    errors |= (ret ? 1 : 0) | check();
    إذا (*پتے.init != 44 || *پتے.element != 2000
        || check_extra(0))
        errors = 1;

    لکھو("errors: %d\n", errors);
    أرجع errors;
}
