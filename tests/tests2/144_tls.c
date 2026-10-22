#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ "threads.h"

#ಆದರೆ __SIZEOF_POINTER__ == 8
# define pFMT "0x%llx"
#ಇಲ್ಲದಿದ್ದರೆ
# define pFMT "0x%x"
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು	CHECK(var,fmt,val)	ಬರೆ(fmt "\n",var); ಆದರೆ (var != val) errors = 1

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ { tls_a, tls_b, tls_c } tls_enum_type;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { ಪೂರ್ಣಾಂಕ tls_d, tls_e, tls_f; } tls_struct_type;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    ಪೂರ್ಣಾಂಕ *init;
    ಚಿಹ್ನೆಯುಳ್ಳ ಗಿಡ್ಡ *element;
} tls_ವಿಳಾಸ_type;

__thread ಅಕ್ಷರ tls_char = 42;
__thread ಗಿಡ್ಡ tls_short = 43;
__thread ಪೂರ್ಣಾಂಕ tls_init = 44;
__thread ದೀರ್ಘ ದೀರ್ಘ tls_long_long = 45;
__thread ಪೂರ್ಣಾಂಕ tls_zero;
__thread ದಶಮಾಂಶ tls_float = 46.0;
__thread ದ್ವಿಗುಣ tls_double = 47.0;
__thread ದೀರ್ಘ ದ್ವಿಗುಣ tls_long_double = 48.0;
__thread ಪೂರ್ಣಾಂಕ *tls_ptr = (ಪೂರ್ಣಾಂಕ *)49;
__thread tls_enum_type tls_enum = tls_b;
__thread tls_struct_type tls_struct = { 50, 51, 52 };
__thread ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ tls_signed_char = -5;
__thread ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ tls_unsigned_char = 250;
__thread ಚಿಹ್ನೆಯುಳ್ಳ ಗಿಡ್ಡ tls_signed_short = -1234;
__thread ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ tls_unsigned_short = 60000;
__thread ಚಿಹ್ನೆಯುಳ್ಳ ಗಿಡ್ಡ tls_array[4] = { -1000, 2000, -3000, 4000 };

#ಆದರೆ defined __riscv && __riscv_xlen == 64
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    ಅಕ್ಷರ padding[4096];
    ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ;
} tls_large_type;

__thread tls_large_type tls_large = { { 0 }, 123456 };
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ check_extra(ಪೂರ್ಣಾಂಕ ಬದಲಾಯಿತು)
{
    ಅಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ಸೂಚ್ಯಂಕ = 2;

    ಆದರೆ (ಬದಲಾಯಿತು)
        ಹಿಂತಿರುಗಿ tls_signed_char != -7 || tls_unsigned_char != 42
            || tls_signed_short != -2222 || tls_unsigned_short != 12345
            || tls_array[1] != 2222 || tls_array[ಸೂಚ್ಯಂಕ] != -3333;

    ಆದರೆ (tls_signed_char != -5 || tls_unsigned_char != 250
        || tls_signed_short != -1234 || tls_unsigned_short != 60000
        || tls_array[1] != 2000 || tls_array[ಸೂಚ್ಯಂಕ] != -3000)
        ಹಿಂತಿರುಗಿ 1;

#ಆದರೆ defined __riscv && __riscv_xlen == 64
    ಆದರೆ (tls_large.ಮೌಲ್ಯ != 123456)
        ಹಿಂತಿರುಗಿ 1;
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ 0;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ check(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ errors = 0;

    CHECK(tls_char, "%d", 42);
    CHECK(tls_short, "%d", 43);
    CHECK(tls_init, "%d", 44);
    CHECK(tls_long_long, "%lld", 45);
    CHECK(tls_zero, "%d", 0);
    CHECK(tls_float, "%g", 46.0);
    CHECK(tls_double, "%g", 47.0);
    CHECK(tls_long_double, "%Lg", 48.0);
    CHECK(tls_ptr, pFMT, (ಪೂರ್ಣಾಂಕ *)49);
    CHECK(tls_enum, "%d", tls_b);
    CHECK(tls_struct.tls_d, "%d", 50);
    CHECK(tls_struct.tls_e, "%d", 51);
    CHECK(tls_struct.tls_f, "%d", 52);
    ಹಿಂತಿರುಗಿ errors;
}

ಸ್ಥಿರ ಶೂನ್ಯ *thread_func(ಶೂನ್ಯ *arg)
{
    tls_ವಿಳಾಸ_type *main_ವಿಳಾಸಗಳು = arg;
    ಪೂರ್ಣಾಂಕ *init_ವಿಳಾಸ = &tls_init;
    ಚಿಹ್ನೆಯುಳ್ಳ ಗಿಡ್ಡ *element_ವಿಳಾಸ = &tls_array[1];
    ಅಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ಸೂಚ್ಯಂಕ = 2;
    ದೀರ್ಘ errors = check();

    ಆದರೆ (init_ವಿಳಾಸ == main_ವಿಳಾಸಗಳು->init
        || element_ವಿಳಾಸ == main_ವಿಳಾಸಗಳು->element
        || *init_ವಿಳಾಸ != 44 || *element_ವಿಳಾಸ != 2000
        || tls_array[ಸೂಚ್ಯಂಕ] != -3000 || check_extra(0))
        errors = 1;

    tls_char = 10;
    tls_short = 20;
    tls_init = 30;
    tls_long_long = 40;
    tls_zero = 50;
    tls_float = 60.0;
    tls_double = 70.0;
    tls_long_double = 80.0;
    tls_ptr = (ಪೂರ್ಣಾಂಕ *)90;
    tls_enum = tls_c;
    tls_struct.tls_d = 100;
    tls_struct.tls_e = 110;
    tls_struct.tls_f = 120;
    *element_ವಿಳಾಸ = 2222;
    tls_array[ಸೂಚ್ಯಂಕ] = -3333;
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
    CHECK(tls_ptr, pFMT, (ಪೂರ್ಣಾಂಕ *)90);
    CHECK(tls_struct.tls_d, "%d", 100);
    CHECK(tls_struct.tls_e, "%d", 110);
    CHECK(tls_struct.tls_f, "%d", 120);

    ಆದರೆ (*init_ವಿಳಾಸ != 30 || *element_ವಿಳಾಸ != 2222
        || tls_array[ಸೂಚ್ಯಂಕ] != -3333 || check_extra(1))
        errors = 1;

    ಹಿಂತಿರುಗಿ (ಶೂನ್ಯ *)(ಗಾತ್ರ_t)errors;
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    pthread_t t;
    ಶೂನ್ಯ *ret;
    ಪೂರ್ಣಾಂಕ errors = check();
    tls_ವಿಳಾಸ_type ವಿಳಾಸಗಳು = { &tls_init, &tls_array[1] };

    ಆದರೆ (*ವಿಳಾಸಗಳು.init != 44 || *ವಿಳಾಸಗಳು.element != 2000
        || check_extra(0))
        errors = 1;

    pthread_create(&t, ಖಾಲಿ, thread_func, &ವಿಳಾಸಗಳು);
    pthread_join(t, &ret);

    errors |= (ret ? 1 : 0) | check();
    ಆದರೆ (*ವಿಳಾಸಗಳು.init != 44 || *ವಿಳಾಸಗಳು.element != 2000
        || check_extra(0))
        errors = 1;

    ಬರೆ("errors: %d\n", errors);
    ಹಿಂತಿರುಗಿ errors;
}
