#समावेश <stdio.h>
#समावेश "threads.h"

#अगर __SIZEOF_POINTER__ == 8
# define pFMT "0x%llx"
#अन्यथा
# define pFMT "0x%x"
#पूर्ण_अगर

#घोषणा	CHECK(var,fmt,val)	म_लिखो(fmt "\n",var); अगर (var != val) errors = 1

प्रकार क्रमागत { tls_a, tls_b, tls_c } tls_enum_type;
प्रकार काष्ठा { पूर्णांक tls_d, tls_e, tls_f; } tls_struct_type;

प्रकार काष्ठा {
    पूर्णांक *init;
    चिन्हित लघु *element;
} tls_address_type;

__thread अक्षर tls_char = 42;
__thread लघु tls_short = 43;
__thread पूर्णांक tls_init = 44;
__thread दीर्घ दीर्घ tls_long_long = 45;
__thread पूर्णांक tls_zero;
__thread भग्न tls_float = 46.0;
__thread द्विगुन tls_double = 47.0;
__thread दीर्घ द्विगुन tls_long_double = 48.0;
__thread पूर्णांक *tls_ptr = (पूर्णांक *)49;
__thread tls_enum_type tls_enum = tls_b;
__thread tls_struct_type tls_struct = { 50, 51, 52 };
__thread चिन्हित अक्षर tls_signed_char = -5;
__thread अचिन्हित अक्षर tls_unsigned_char = 250;
__thread चिन्हित लघु tls_signed_short = -1234;
__thread अचिन्हित लघु tls_unsigned_short = 60000;
__thread चिन्हित लघु tls_array[4] = { -1000, 2000, -3000, 4000 };

#अगर defined __riscv && __riscv_xlen == 64
प्रकार काष्ठा {
    अक्षर padding[4096];
    पूर्णांक मूल्य;
} tls_large_type;

__thread tls_large_type tls_large = { { 0 }, 123456 };
#पूर्ण_अगर

अटल पूर्णांक check_extra(पूर्णांक changed)
{
    अस्थिर पूर्णांक सूचकांक = 2;

    अगर (changed)
        वापस tls_signed_char != -7 || tls_unsigned_char != 42
            || tls_signed_short != -2222 || tls_unsigned_short != 12345
            || tls_array[1] != 2222 || tls_array[सूचकांक] != -3333;

    अगर (tls_signed_char != -5 || tls_unsigned_char != 250
        || tls_signed_short != -1234 || tls_unsigned_short != 60000
        || tls_array[1] != 2000 || tls_array[सूचकांक] != -3000)
        वापस 1;

#अगर defined __riscv && __riscv_xlen == 64
    अगर (tls_large.मूल्य != 123456)
        वापस 1;
#पूर्ण_अगर
    वापस 0;
}

अटल पूर्णांक check(व्योम)
{
    पूर्णांक errors = 0;

    CHECK(tls_char, "%d", 42);
    CHECK(tls_short, "%d", 43);
    CHECK(tls_init, "%d", 44);
    CHECK(tls_long_long, "%lld", 45);
    CHECK(tls_zero, "%d", 0);
    CHECK(tls_float, "%g", 46.0);
    CHECK(tls_double, "%g", 47.0);
    CHECK(tls_long_double, "%Lg", 48.0);
    CHECK(tls_ptr, pFMT, (पूर्णांक *)49);
    CHECK(tls_enum, "%d", tls_b);
    CHECK(tls_struct.tls_d, "%d", 50);
    CHECK(tls_struct.tls_e, "%d", 51);
    CHECK(tls_struct.tls_f, "%d", 52);
    वापस errors;
}

अटल व्योम *thread_func(व्योम *arg)
{
    tls_address_type *main_addresses = arg;
    पूर्णांक *init_address = &tls_init;
    चिन्हित लघु *element_address = &tls_array[1];
    अस्थिर पूर्णांक सूचकांक = 2;
    दीर्घ errors = check();

    अगर (init_address == main_addresses->init
        || element_address == main_addresses->element
        || *init_address != 44 || *element_address != 2000
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
    tls_ptr = (पूर्णांक *)90;
    tls_enum = tls_c;
    tls_struct.tls_d = 100;
    tls_struct.tls_e = 110;
    tls_struct.tls_f = 120;
    *element_address = 2222;
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
    CHECK(tls_ptr, pFMT, (पूर्णांक *)90);
    CHECK(tls_struct.tls_d, "%d", 100);
    CHECK(tls_struct.tls_e, "%d", 110);
    CHECK(tls_struct.tls_f, "%d", 120);

    अगर (*init_address != 30 || *element_address != 2222
        || tls_array[सूचकांक] != -3333 || check_extra(1))
        errors = 1;

    वापस (व्योम *)(माप_प्रकार)errors;
}

पूर्णांक मुख्य()
{
    pthread_t t;
    व्योम *ret;
    पूर्णांक errors = check();
    tls_address_type addresses = { &tls_init, &tls_array[1] };

    अगर (*addresses.init != 44 || *addresses.element != 2000
        || check_extra(0))
        errors = 1;

    pthread_create(&t, शून्य, thread_func, &addresses);
    pthread_join(t, &ret);

    errors |= (ret ? 1 : 0) | check();
    अगर (*addresses.init != 44 || *addresses.element != 2000
        || check_extra(0))
        errors = 1;

    म_लिखो("errors: %d\n", errors);
    वापस errors;
}
