#अन्तर्भाव <stdio.h>
#अन्तर्भाव "threads.h"

#यदि __SIZEOF_POINTER__ == 8
# define pFMT "0x%llx"
#अन्यथा
# define pFMT "0x%x"
#यदि_अन्तः

#परिभाषय	CHECK(var,fmt,val)	प्रारूप_लिख(fmt "\n",var); यदि (var != val) errors = 1

प्रकारनिर्देश गणना { tls_a, tls_b, tls_c } tls_enum_type;
प्रकारनिर्देश संरचना { पूर्णाङ्क tls_d, tls_e, tls_f; } tls_struct_type;

प्रकारनिर्देश संरचना {
    पूर्णाङ्क *init;
    चिह्नित ह्रस्व *element;
} tls_स्थानाङ्कः_type;

__thread वर्ण tls_char = 42;
__thread ह्रस्व tls_short = 43;
__thread पूर्णाङ्क tls_init = 44;
__thread दीर्घ दीर्घ tls_long_long = 45;
__thread पूर्णाङ्क tls_zero;
__thread भिन्न tls_float = 46.0;
__thread द्विगुण tls_double = 47.0;
__thread दीर्घ द्विगुण tls_long_double = 48.0;
__thread पूर्णाङ्क *tls_ptr = (पूर्णाङ्क *)49;
__thread tls_enum_type tls_enum = tls_b;
__thread tls_struct_type tls_struct = { 50, 51, 52 };
__thread चिह्नित वर्ण tls_signed_char = -5;
__thread अचिह्नित वर्ण tls_unsigned_char = 250;
__thread चिह्नित ह्रस्व tls_signed_short = -1234;
__thread अचिह्नित ह्रस्व tls_unsigned_short = 60000;
__thread चिह्नित ह्रस्व tls_array[4] = { -1000, 2000, -3000, 4000 };

#यदि defined __riscv && __riscv_xlen == 64
प्रकारनिर्देश संरचना {
    वर्ण padding[4096];
    पूर्णाङ्क मानम्;
} tls_large_type;

__thread tls_large_type tls_large = { { 0 }, 123456 };
#यदि_अन्तः

स्थिर पूर्णाङ्क check_extra(पूर्णाङ्क परिवर्तितम्)
{
    चञ्चल पूर्णाङ्क सूचकांक = 2;

    यदि (परिवर्तितम्)
        प्रत्यागम tls_signed_char != -7 || tls_unsigned_char != 42
            || tls_signed_short != -2222 || tls_unsigned_short != 12345
            || tls_array[1] != 2222 || tls_array[सूचकांक] != -3333;

    यदि (tls_signed_char != -5 || tls_unsigned_char != 250
        || tls_signed_short != -1234 || tls_unsigned_short != 60000
        || tls_array[1] != 2000 || tls_array[सूचकांक] != -3000)
        प्रत्यागम 1;

#यदि defined __riscv && __riscv_xlen == 64
    यदि (tls_large.मानम् != 123456)
        प्रत्यागम 1;
#यदि_अन्तः
    प्रत्यागम 0;
}

स्थिर पूर्णाङ्क check(शून्य)
{
    पूर्णाङ्क errors = 0;

    CHECK(tls_char, "%d", 42);
    CHECK(tls_short, "%d", 43);
    CHECK(tls_init, "%d", 44);
    CHECK(tls_long_long, "%lld", 45);
    CHECK(tls_zero, "%d", 0);
    CHECK(tls_float, "%g", 46.0);
    CHECK(tls_double, "%g", 47.0);
    CHECK(tls_long_double, "%Lg", 48.0);
    CHECK(tls_ptr, pFMT, (पूर्णाङ्क *)49);
    CHECK(tls_enum, "%d", tls_b);
    CHECK(tls_struct.tls_d, "%d", 50);
    CHECK(tls_struct.tls_e, "%d", 51);
    CHECK(tls_struct.tls_f, "%d", 52);
    प्रत्यागम errors;
}

स्थिर शून्य *thread_func(शून्य *arg)
{
    tls_स्थानाङ्कः_type *main_स्थानाङ्काः = arg;
    पूर्णाङ्क *init_स्थानाङ्कः = &tls_init;
    चिह्नित ह्रस्व *element_स्थानाङ्कः = &tls_array[1];
    चञ्चल पूर्णाङ्क सूचकांक = 2;
    दीर्घ errors = check();

    यदि (init_स्थानाङ्कः == main_स्थानाङ्काः->init
        || element_स्थानाङ्कः == main_स्थानाङ्काः->element
        || *init_स्थानाङ्कः != 44 || *element_स्थानाङ्कः != 2000
        || tls_array[सूचकांक] != -3000 || check_extra(0))
        errors = 1;

    tls_char = 10;
    tls_short = 20;
    tls_init = 30;
    tls_long_long = 40;
    tls_zero = 50;
    tls_float = 60.0;
    tls_double = 70.0;
    tls_long_double = 80.0;
    tls_ptr = (पूर्णाङ्क *)90;
    tls_enum = tls_c;
    tls_struct.tls_d = 100;
    tls_struct.tls_e = 110;
    tls_struct.tls_f = 120;
    *element_स्थानाङ्कः = 2222;
    tls_array[सूचकांक] = -3333;
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
    CHECK(tls_ptr, pFMT, (पूर्णाङ्क *)90);
    CHECK(tls_struct.tls_d, "%d", 100);
    CHECK(tls_struct.tls_e, "%d", 110);
    CHECK(tls_struct.tls_f, "%d", 120);

    यदि (*init_स्थानाङ्कः != 30 || *element_स्थानाङ्कः != 2222
        || tls_array[सूचकांक] != -3333 || check_extra(1))
        errors = 1;

    प्रत्यागम (शून्य *)(आकार_t)errors;
}

पूर्णाङ्क मुख्यम्()
{
    pthread_t t;
    शून्य *ret;
    पूर्णाङ्क errors = check();
    tls_स्थानाङ्कः_type स्थानाङ्काः = { &tls_init, &tls_array[1] };

    यदि (*स्थानाङ्काः.init != 44 || *स्थानाङ्काः.element != 2000
        || check_extra(0))
        errors = 1;

    pthread_create(&t, रिक्त, thread_func, &स्थानाङ्काः);
    pthread_join(t, &ret);

    errors |= (ret ? 1 : 0) | check();
    यदि (*स्थानाङ्काः.init != 44 || *स्थानाङ्काः.element != 2000
        || check_extra(0))
        errors = 1;

    प्रारूप_लिख("errors: %d\n", errors);
    प्रत्यागम errors;
}
